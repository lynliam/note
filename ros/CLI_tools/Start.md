# START



* determine a unique inter for your group of ROS 2 agents

  ```shell
  export ROS_DOMAIN_ID=<your_domain_id>
  #TO maintain this setting :
  echo "export ROS_DOMAIN_ID=<your_domain_id>" >> ~/.bashrc
  ```

  

* determine ***ROS_LOCALHOST_ONLY***   variable

  ```shell
  #Using this you can limit it to localhost
  
  export ROS_LOCALHOST_ONLY=1
  #TO maintain :
  echo "export ROS_LOCALHOST_ONLY=1" >> ~/.bashrc
  ```

  

* using turtlesim

  ```shell
  ros2 run turtlesim turtlesim_node
  #to control turtle using arrow key
  ros2 run turtlesim turtle_teleop_key
  
  #list commend
  ros2 node list
  ros2 topic list
  ros2 service list
  ros2 action list
  ```


* ```shell
  #install colcon
  sudo apt install python3-colcon-common-extensions
  ```

* 