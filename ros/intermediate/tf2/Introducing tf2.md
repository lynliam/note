# Introducing **tf2**

## tf2 tools

```tf2-tools``` can look at what tf2 is doing behind the scenes----Who broadcast the frames and who receive the frame.

```shell
ros2 run tf2_tools view_frames
```

```tf2_echo```reports the transform between any two frames broadcasted over ROS.

## ```rviz and tf2```

`rviz` is a visualization tool that is useful for examining tf2 frames. Let’s look at our turtle frames using rviz. Let’s start rviz with the `turtle_rviz.rviz` configuration file using the `-d` option: