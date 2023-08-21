# 例子

```cpp
//首先先引入头文件
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/u_int32.hpp"

//定义一个继承自rclcpp::Node的类
class write_li : public rclcpp::Node
{
    public:
    write_li(std::string name_node): Node(name_node)     //构造函数，将name传递给Node类初始化
    {
        RCLCPP_INFO(this->get_logger(),"Wtring node start by %s!",name_node.c_str());   //打印日志信息
        writing_pub=this->create_publisher<std_msgs::msg::String>("command",10);        //发送话题“command”
        timer_ = this->create_wall_timer(std::chrono::milliseconds(1500),std::bind(&write_li::timer_callback,this));  //时间
        //std::bind()函数实现函数回调功能
        money_sub = this->create_subscription<std_msgs::msg::UInt32>("money",10,std::bind(&write_li::money_top_callback,this,std::placeholders::_1));       //订阅话题并交给回调函数处理
    }
    private:
    //声明对应的类模板共享指针
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr writing_pub;
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Subscription<std_msgs::msg::UInt32>::SharedPtr money_sub;

    void money_top_callback(const std_msgs::msg::UInt32::SharedPtr msg)
    {
        RCLCPP_INFO(this->get_logger(),"已收到%d",msg->data);
    }
    void timer_callback()
    {
        std_msgs::msg::String message;
        static std_msgs::msg::UInt32 chapter_nums;
        chapter_nums.data=0;
        message.data ="发布章节：";
        chapter_nums.data++;
        RCLCPP_INFO(this->get_logger(),"%s,已发送 %d",message.data.c_str(),chapter_nums.data);
        writing_pub->publish(message);      //调用类成员函数publish()
    }

};

int main(int argc,char **argv)
{
    rclcpp::init(argc,argv);                             //初始化 
    auto node = std::make_shared<write_li>("li4");       //创建一个节点
    rclcpp::spin(node);                                  //开转
    rclcpp::shutdown();                                  //检测关机
    return 0;
}
```

