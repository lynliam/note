```c++
#include<queue>

#include"rclcpp/rclcpp.hpp"
#include"std_msgs/msg/string.hpp"
#include"std_msgs/msg/u_int32.hpp"
#include"novel_interfaces/msg/novel_sell.hpp"
#include"novel_interfaces/srv/sell_novel.hpp"


class WangTwo :public rclcpp::Node
{
    public:
    WangTwo(std::string name):Node(name)
    {
        RCLCPP_INFO(this->get_logger(),"My name is %s",name.c_str());
        sub_novel = this->create_subscription<novel_interfaces::msg::NovelSell>("novel1",10,std::bind(&WangTwo::topic_callback,this,std::placeholders::_1));
        pub_money_ = this->create_publisher<novel_interfaces::msg::NovelSell>("money",10);
        callback_group_ser_ = this->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
        ser_ = this->create_service<novel_interfaces::srv::SellNovel>("sell_novel",std::bind(&WangTwo::sell_book_callback,this,std::placeholders::_1,std::placeholders::_2),rmw_qos_profile_services_default,callback_group_ser_);
    }
    private:
    std::queue<std::string> novels_queue;
    rclcpp::Subscription<novel_interfaces::msg::NovelSell>::SharedPtr sub_novel; 
    rclcpp::Publisher<novel_interfaces::msg::NovelSell>::SharedPtr pub_money_;
    rclcpp::CallbackGroup::SharedPtr callback_group_ser_;
    rclcpp::Service<novel_interfaces::srv::SellNovel>::SharedPtr ser_;
    void topic_callback(const novel_interfaces::msg::NovelSell::SharedPtr msg)
    {
        //RCLCPP_INFO(this->get_logger(),"money:%d",msg->money);
        auto money=novel_interfaces::msg::NovelSell();
        money.money= 10;

        // 发送人民币给李四
        pub_money_->publish(money);

        RCLCPP_INFO(this->get_logger(), "王二：我收到了：'%s' ，并给了李四：%d 元的稿费", msg->novel.c_str(),money.money);

        //将小说放入novels_queue中
        novels_queue.push(msg->novel);
        RCLCPP_INFO(this->get_logger(),"have already received %s!",msg->novel.c_str());   
    
    }
    void sell_book_callback(const novel_interfaces::srv::SellNovel::Request::SharedPtr request,
    const novel_interfaces::srv::SellNovel::Response::SharedPtr response)
    {
        RCLCPP_INFO(this->get_logger(),"received %d money",request->money);
        unsigned int novelsNum = request->money*1;  //应给小说数量，一块钱一章
        if(novels_queue.size()<novelsNum)
        {
            RCLCPP_INFO(this->get_logger(), "当前章节存量为%d：不能满足需求,开始等待",novels_queue.size());

            // 设置rate周期为1s，代表1s检查一次
            rclcpp::Rate loop_rate(1);

            //当书库里小说数量小于请求数量时一直循环
            while (novels_queue.size()<novelsNum)
            {
                //判断系统是否还在运行
                if(!rclcpp::ok())
                {
                    RCLCPP_ERROR(this->get_logger(), "程序被终止了");
                    return ;
                }
                //打印一下当前的章节数量和缺少的数量
                RCLCPP_INFO(this->get_logger(), "等待中，目前已有%d章，还差%d章",novels_queue.size(),novelsNum-novels_queue.size());

                //rate.sleep()让整个循环1s运行一次
                loop_rate.sleep();
            }
        }
        // 章节数量满足需求了
        RCLCPP_INFO(this->get_logger(), "当前章节存量为%d：已经满足需求",novels_queue.size());

        //一本本把书取出来，放进请求响应对象response中
        for(unsigned int i =0 ;i<novelsNum;i++)
        {
            response->novels.push_back(novels_queue.front());
            novels_queue.pop();
        }
    }
};

int main(int argc, char **argv)
{
    rclcpp::init(argc,argv);
    auto node = std::make_shared<WangTwo>("wang2");
    rclcpp::executors::MultiThreadedExecutor exect;
    exect.add_node(node);
    exect.spin();
    rclcpp::shutdown();

    return 0;
}
```

