# Integrating launch files into ROS 2 packages

## 1. Create a package

```shell
mkdir -p launch_ws/src
cd launch_ws/src
ros2 pkg create cpp_launch_example --build-type ament_cmake
```



## 2. Create structure

```shell
#CMakeLists.txt

# Install launch files.
install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}/
)
```



## 3. launch file

> Inside your `launch` directory, create a new launch file called `_launch.py`.

```shell
import launch
import launch_ros.actions

def generate_launch_description():
    return launch.LaunchDescription([
        launch_ros.actions.Node(
            package='demo_nodes_cpp',
            executable='talker',
            name='talker'),
  ])
```



## 4.launch

```shell
colcon build 

ros2 launch cpp_launch_example my_script_launch.py
```

