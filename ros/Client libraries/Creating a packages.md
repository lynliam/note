# Creating a package

* Brief introduction:
  * considered a container for ROS 2 code
  * build system : ament
  * build tool :  CMake and Python





* create a package:

  ```shell
  #the following command will create a package
  ros2 pkg create --build-type ament_cmake <package_name>
  ```

  * Putting packages in a workspace:  easy to run colcon build

* Build

  ```shell
  #it will build all the packages in the workspace
  colcon build
  #or only build the selected packages
  colcon build --packages-select my_package
  source XXXX
  . install/local_setup.bash
  ```

  

* customize package.xml