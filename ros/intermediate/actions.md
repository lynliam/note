# Wring an action server and client

##  1.1. Introduction

* asynchronous communication
* client sends goal and server sends goal feedback and results to client.



## 2.1. Interfaces 

### ```action```file ：

```action
# Request
---
# Result
---
# Feedback
```

* When the goal is completed,  server will send result to client.

### ```CMakeLists: ```

```cmake
find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "action/Fibonacci.action"
)
```

### ```package.xml```:

```xml
<buildtool_depend>rosidl_default_generators</buildtool_depend>

<depend>action_msgs</depend>
<!--the action_msgs depend include additonal metadata-->
<member_of_group>rosidl_interface_packages</member_of_group>
```

By convention, action types will be prefixed by their package name and the word `action`. So when we want to refer to our new action, it will have the full name `action_tutorials_interfaces/action/Fibonacci`.
