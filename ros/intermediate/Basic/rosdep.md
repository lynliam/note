# Rosdep

* ```rosdep```is ROS's dependency management utility that can work with ROS packages and external libraries.



## package.xml files:

```package.xml``` file contains a set of dependencies.

The dependencies in this file are generally referred to as “rosdep keys”

* ```<test_depend>```         		      For dependencies only used in testing the code
* ```<build_depend>```           	      For dependencies only used in building the code
* ```<build_export_depend>```       needed by headers the code exports
* ```<exec_depend>```                      only used when running the code 
* ```<depend>```                               For mixed purposes,which covers build, export, and execution time dependencies.



## How rosdep work:

```rosdep``` will check for :

* package.xml files in its path
* specific package
* find the rosdep keys

一，是什么

* rosdep用来检查包的丢失依赖项，并完成下载和安装。

```shell
sudo rosdep init
rosdep update

# --from-paths src specifies the path to check for package.xml 
# -y means default yes
# ignore installing dependencies
rosdep install --from-paths src -y --ignore-src
```





* Rosdepc

```
wget http://fishros.com/install -O fishros && . fishros
sudo pip3 install rosdepc
```













