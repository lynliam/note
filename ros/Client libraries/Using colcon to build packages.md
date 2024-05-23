# Using `colcon` to build packages

* #### brief introduction

  * colon is an iteration on the ROS build tools `catkin_make`, `catkin_make_isolated`, `catkin_tools` and `ament_tools`
  
  * A ROS workspace is a directory with a particular structure.
  
    * ```shell
      #contains
      src
      build
      install
      log
      ```
  
      

* create a workspace 

* Add some sources

* Source an underlay

  * it is important to source the environment for an existing ROS 2 installation and provide necessary build dependencies

  * by sourcing the setup script provided by a binary installation or a source installation, ie.      and  call this environment an **underlay**.
  * our workspace call: overlay

* Build the workspace

  * ```shell
    colcon build --symlink-install
    # --symlink-install
    #This allows the installed files to be changed by changing the files in the source space 
    ```

  * ```shell
    colcon test
    ```

* source the environment

  * Before you can use any of the installed executables or libraries, you will need to add them to your path and library paths.

  * . install/setup.bash
