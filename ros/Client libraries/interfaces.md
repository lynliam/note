# implementing custom interfaces

### DEFINATION:

接口是一种规范，通过定义相同类型的数据接口使得不同的语言差异被抹平。

即是在c++下编译的文件和python下编译的文件都可以互相进行信息传递。

通过ROS2的IDl模块将接口文件转换成头文件

#### TYPE:

* topic(```xxx.msg```)

```
int64 num
```

* services(```xxx.srv```)

```
int64 a
int64 b
---
int64 sum
```

* action(```xxx.action```)

```
int32 order
---
int32[] sequence
---
int32[] partial_sequence
```



### create custom msg and srv interfaces:

* ### Create a package:

```shell
cd ~/ros_ws/src
ros2 pkg create --build-type ament_cmake xx_interfaces
mkdir xx_interfaces/msg
```



* ### create a msg file:

### 名字中不能出现下划线！！！！！！！！！！！！！！！

```shell
cd ./msg
#注意:msg文件开头首字母一定要大写
#名字中不能出现下划线！！！！！！！！！！！！！！！
touch Xxx.msg
code xxx.msg

#添加内容
```

* #### Build  a msg file

```xml
#in package.xml
#add
<buildtool_depend>rosidl_default_generators</buildtool_depend>

<exec_depend>rosidl_default_runtime</exec_depend>

<member_of_group>rosidl_interface_packages</member_of_group>
```

```cmake
#in CMakeLists.txt
#add
find_package(rosidl_default_generators REQUIRED)
set(msg_files
  "msg/AddressBook.msg"
)
rosidl_generate_interfaces(${PROJECT_NAME}
  ${msg_files}
)
ament_export_dependencies(rosidl_default_runtime)
```

```cmake
#添加对sensor_msgs的
find_package(sensor_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)
#添加消息文件和依赖
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/Novel.msg"
   DEPENDENCIES sensor_msgs
 )
```





* 