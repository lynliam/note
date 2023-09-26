# Create a workspace 

* #### Source ROS 2 environment

  * ```shell
    source /opt/ros/humble/setup.bash
    ```

    

* #### Create a new directory

  * ```shell
    mkdir -p ~/ros2_ws/src
    cd ~/ros2_ws/src
    ```

    

* #### Resolve dependencies

  * check if the dependencies are fully installed 

    ```shell
    # cd if you're still in the ``src`` directory with the ``ros_tutorials`` clone
    cd ..
    rosdep install -i --from-path src --rosdistro humble -y
    ```

    

* #### Build the workspace with colcon

  * now we can build it 

    ```shell
    colcon build
    ```

  * Other useful arguments for `colcon build`:

    - `--packages-up-to` builds the package you want, plus all its dependencies, but not the whole workspace (saves time)
    - `--symlink-install` saves you from having to rebuild every time you tweak python scripts
    - `--event-handlers console_direct+` shows console output while building (can otherwise be found in the `log` directory)

* #### Source the overlay

  * # remember !!!

  * ***open a new terminal to source the overlay***

  * `setup` sources the overlay as well as the underlay it was created in, allowing you to utilize both workspaces.

  ```shell
  source /opt/ros/humble/setup.bash
  
  cd ~/ros2_ws
  
  . install/local_setup.bash
  
  #source your main ROS 2 environment as the “underlay”, so you can build the overlay “on top of” it
  
  ros2 run turtlesim turtlesim_node
  ```

* 