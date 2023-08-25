# ROS_Node

* ROS_Graph
  * a network of ROS 2 elements processing data together at one time.

* Node :responsible for a singer module purpose



* TASk

  * ```ros2 run```   :launch an executable from a package

    ```shell
    ros2 run <package_name> <executable_name>
    ```

  * ```ros2 node list```:     name of all running nodes

    ```
    ros2 node list
    ```

  * Remapping:    reassign default node properties (node name , topic names, servie names,  etc.)

    ```shell
    #e.g.
    ros2 run turtlesim turtlesim_node  --ros-args --remap __node:=my_turtle
    ```

  * ros2 node info :   return subscribers, publishers, services, and actions

    ```shell
    ros2 node info <node_name>
    ```

    ```shell
    /turtlesim
      Subscribers:
        /parameter_events: rcl_interfaces/msg/ParameterEvent
        /turtle1/cmd_vel: geometry_msgs/msg/Twist
      Publishers:
        /parameter_events: rcl_interfaces/msg/ParameterEvent
        /rosout: rcl_interfaces/msg/Log
        /turtle1/color_sensor: turtlesim/msg/Color
        /turtle1/pose: turtlesim/msg/Pose
      Service Servers:
        /clear: std_srvs/srv/Empty
        /kill: turtlesim/srv/Kill
        /reset: std_srvs/srv/Empty
        /spawn: turtlesim/srv/Spawn
        /turtle1/set_pen: turtlesim/srv/SetPen
        /turtle1/teleport_absolute: turtlesim/srv/TeleportAbsolute
        /turtle1/teleport_relative: turtlesim/srv/TeleportRelative
        /turtlesim/describe_parameters: rcl_interfaces/srv/DescribeParameters
        /turtlesim/get_parameter_types: rcl_interfaces/srv/GetParameterTypes
        /turtlesim/get_parameters: rcl_interfaces/srv/GetParameters
        /turtlesim/list_parameters: rcl_interfaces/srv/ListParameters
        /turtlesim/set_parameters: rcl_interfaces/srv/SetParameters
        /turtlesim/set_parameters_atomically: rcl_interfaces/srv/SetParametersAtomically
      Service Clients:
    
      Action Servers:
        /turtle1/rotate_absolute: turtlesim/action/RotateAbsolute
      Action Clients:
    
    
    ```

    

























