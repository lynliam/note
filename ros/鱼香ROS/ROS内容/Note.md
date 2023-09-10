# Note

1. ### 使用```std::to_string()``` 将其他类型转换成```string```

2. ### 正常的```std::string```无法在```RCLCPP_INFO```中打印 需使用```c_str()``` 

3. ### ```village_interface::srv::SellNovel::Request::SharedPtr```和``` std::shared_ptr<village_interface::srv::Borrowmoney::Request>```

> 从另一个节点中获得的消息（提供的消息接口）都是指针类型```SharedPtr``` (除了client的接收回调函数，参数是```rclcpp::Client<village_interface::srv::Borrowmoney>::SharedFuture```)

4. ### 多线程

```cpp
//实现多线程
callback_group_service_ = this->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);

```

