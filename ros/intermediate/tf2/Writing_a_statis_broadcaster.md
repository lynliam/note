# writing a static broadcaster(c++)

Publishing **static transforms** is useful to define the relationship between a robot base and its sensors or non-moving parts.



### Create packages:

```shell
ros2 pkg create --build-type ament_cmake --dependencies geometry_msgs rclcpp tf2 tf2_ros turtlesim --<packagse_name>
```

