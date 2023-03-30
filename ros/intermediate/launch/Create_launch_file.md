# Create a launch file

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



### ros2 launch:

```python
cd launch
ros2 launch turtlesim_mimic_launch.py

#When it was provided by packages:
ros2 launch <package_name> <launch_file_name>
```

