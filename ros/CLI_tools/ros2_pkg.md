## ROS2 pkg

* 与功能包相关的指令ros2 pkg

```shell
create       Create a new ROS2 package
executables  Output a list of package specific executables
list         Output a list of available packages
prefix       Output the prefix path of a package
xml          Output the XML of the package manifest or a specific tag

```



* 创建

  ```shell
  ros2 pkg create <package-name>  --build-type  {cmake,ament_cmake,ament_python}  --dependencies <依赖名字>
  ```

* s列出可执行文件

  ```
  ros2 pkg executables
  ```

* 列出所有包

  ```shell
  ros2 pkg list
  ```

  

