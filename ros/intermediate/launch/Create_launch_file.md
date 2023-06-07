# Create a launch file

### Backgroud:

1. help the user describe the **configuration** of the programs
2. reuse components throughout the system by giving different configuration
3. monitoring the **state** of the processes
4. reacting the changes

### example:

```python
from launch import LaunchDescription
from launch_ros.actions import Node

# The goal of the system is to launch two turtlesim windows, and have one turtle mimic the movements of the other.
#launch three node
def generate_launch_description():
    return LaunchDescription([
        Node(
            package='turtlesim',
            #With unique namespaces, messages meant for different turtles can be distinguished.
            namespace='turtlesim1',
            executable='turtlesim_node',
            name='sim'
        ),
        Node(
            package='turtlesim',
            namespace='turtlesim2',
            executable='turtlesim_node',
            name='sim'
        ),
        Node(
            package='turtlesim',
            executable='mimic',
            name='mimic',
            remappings=[
                ('/input/pose', '/turtlesim1/turtle1/pose'),
                ('/output/cmd_vel', '/turtlesim2/turtle1/cmd_vel'),
            ]
        )
    ])
```

* 命名空间不同可以避免node和topic name冲突

### ros2 launch:

```python
cd launch
ros2 launch turtlesim_mimic_launch.py

#When it was provided by packages:
ros2 launch <package_name> <launch_file_name>
```

> For packages with launch files, it is a good idea to add an `exec_depend` **dependency** on the `ros2launch` package in your package’s `package.xml`:
>
> ```
> <exec_depend>ros2launch</exec_depend>
> ```
>
> This helps make sure that the `ros2 launch` command is available after building your package. It also ensures that all [launch file formats](http://docs.ros.org/en/humble/How-To-Guides/Launch-file-different-formats.html) are recognized.
