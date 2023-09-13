# Launching node

* #### Running a Launch File

  * ```shell
    #run normally
    ros2 launch <package_name> <launch_file_name>
    #run the file directly by specifying the path to the launch file
    ros2 launch <path_to_launch_file>
    
    ros2 launch turtlesim multisim.launch.py
    
    #the content of launch file
    
    #******************************************************************
    # turtlesim/launch/multisim.launch.py
    
    from launch import LaunchDescription
    import launch_ros.actions
    
    def generate_launch_description():
        return LaunchDescription([
            launch_ros.actions.Node(
                namespace= "turtlesim1", package='turtlesim', executable='turtlesim_node', output='screen'),
            launch_ros.actions.Node(
                namespace= "turtlesim2", package='turtlesim', executable='turtlesim_node', output='screen'),
        ])
    ```

* #### Setting arguments

  * use `key:=value` syntax

  * ```shell
    #example
    ros2 launch <package_name> <launch_file_name> background_r:=255
    #OR
    ros2 launch <path_to_launch_file> background_r:=255
    ```

  * 

* #### Controlling the turtles

  * #### Using Python, XML, and YAML for ROS 2 Launch Files[](http://docs.ros.org/en/humble/How-To-Guides/Launch-file-different-formats.html#using-python-xml-and-yaml-for-ros-2-launch-files)

    * ## [Launch file examples](http://docs.ros.org/en/humble/How-To-Guides/Launch-file-different-formats.html#id1)

      * Each launch file performs the followiing actions:
        * Setup command line arguments with defaults
        * Include another launch file
        * Include another launch file in another namespace
        * Start a node and setting its namespace
        * Start a node, setting its namespace, and setting parameters in that node (using the args)
        * Create a node to remap messages from one topic to another

* #### Control the Turtlesim Nodes

  * 