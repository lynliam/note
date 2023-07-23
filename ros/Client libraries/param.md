# 参数

```cpp
//param
//构造函数中
this->declare_parameter<std::uint32_t>("",);
this->declare_parameter("name",value)
//获取并设置参数
this->get_parameter(" ",);
//设置参数位置
```

```shell
ros2 param list
ros2 param describe /node 参数名
ros2 param get /node 参数名
```

## Add ParameterDescriptor

Descriptors allow you to specify a text description of the parameter and its constraints, like making it read-only, specifying a range, etc.

```c++
// ...

class MinimalParam : public rclcpp::Node
{
public:
  MinimalParam()
  : Node("minimal_param_node")
  {
    //create description
    auto param_desc = rcl_interfaces::msg::ParameterDescriptor{};
    param_desc.description = "This parameter is mine!";
	//add parameter-description
    this->declare_parameter("my_parameter", "world", param_desc);

    timer_ = this->create_wall_timer(
      1000ms, std::bind(&MinimalParam::timer_callback, this));
  }
```



## Change via the ocnsole

```c++
ros2 param set /minimal_param_node my_parameter earth
```



## Change via a launch file

```c++
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package="cpp_parameters",
            executable="minimal_param_node",
            name="custom_minimal_param_node",
            output="screen",
            emulate_tty=True,
            parameters=[
                {"my_parameter": "earth"}
            ]
        )
    ])
```

