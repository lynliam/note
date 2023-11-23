# Topic

* Background

  * exchange messages like a bus between  different nodes

  * each node can have many **Publishers** and **Subscriber**

    

* rqt_graph  (showing the nodes and topic)

* ros2 topic list

  ```
  ros2 topic list
  ros2 topic list -t 
  # -t this would return the topic type
  ```

* ros2 topic echo (**To see the data being published on a topic**) 

  ```shell
  ros2 topic echo <topic_name>
  #if you want to see the rqt_graph  :  close the "Debug" in "Hide"
  ```

  

* ros2 topic info

  ```shell
  ros2 topic info /turtle1/cmd_vel
  #it will return 
  #Type,  Publishers count,   Subscription count
  ```

  

* ros2 interface show

  ```shell
  #this will show you what structure of data the message epects.
  #e.g.
  ros2 interface show geometry_msgs/msg/Twist
  ```

  

* ros2 topic pub

  ```shell
  #Using this you will pass the data to the topic
  #the args nedds to be input in YAML syntax
  ros2 topic pub (paras) <topic_name> <msg_type> '<args>'
  paras:  --once    just execute once
          --rate 1  publish the cmd in a steady stream at 1Hz
  ```

  

* ros2 topic hz

  ```shell
  ros2 topic hz /turtle1/pose
  #it will return data on the rate at which /turtlesim node is publishing data to the pose topic
  ```

  