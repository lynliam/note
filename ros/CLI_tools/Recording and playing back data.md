# Recording 

* ```ros2 bag record```

  * ```shell
    #To record the data published to a topic
    # the rosbag file will save in the directory where you run it.
    ros2 bag record <topic_name>
    ```

  * ```shell 
    ros2 bag record -o subset /turtle1/cmd_vel /turtle1/pose
    #-o  to choose a unique name for your bag file
    #simply list each topic separated by a space.
    ```

    

* ```ros2 bag info```

  * ```shell
    #To see details of your recording 
    ros2 bag info <bag_file_name>
    ```

* ```shell
  ros2 bag play <bag_name>
  ```