# ROS2——教你写新版Launch文件

## 为什么需要launch

如需启动一个节点，只需要执行

```
ros2 run package-name execute-name
```

但如果需要启动多个节点，一个一个启动需要开很多终端输入很多条命令，所以可以使用launch文件批量启动。

## 如何编写launch文件

在ROS1中launch文件是一种格式以`.launch`结尾的xml文档；而在ROS2中推荐使用Python方式编写launch文件，此时的launch文件是一种格式以`.launch.py`结尾的Python脚本。

### 启动节点

对于一个基础的启动节点的launch文件，需要引用以下库，然后创建一个名为做`generate_launch_description`的函数：

```
from launch import LaunchDescription
from launch_ros.actions import Node
def generate_launch_description():
    ......
```

**下文中未注明的均在`generate_launch_description()`函数中进行操作。**

创建`LaunchDescription`的对象`ld`（名字任意）

```
ld = LaunchDescription()
```

然后创建一个`Actions.Node`对

```
example-node = Node(
    package='package-name', #节点所在的功能包
    namespace='package-namespace', #命名空间。如果存在同名节点，这一选项会有用
    executable='execute-name/script-name.py', #表示要运行的可执行文件名或脚本名字.py
    parameters=[{'parameter-name': parameter-value}], #参数
    arguments=['-xxx', xxx,  '-xxx', xxx ], #启动参数
    output='screen', #用于将话题信息打印到屏幕
    name='node-name' #表示启动后的节点名，可以没有
    remappings=[ #重映射
        ('/xxx/xxx-new', '/xxx/xxx-old'),
	]
)
example-node2 = Node(
	......
)
```

将上面所有的Node对象加入`ld`，然后返回

```
ld.add_action(example-node)
ld.add_action(example-node2)
return launch_description
```

### 调用shell命令

需要添加头文件

```
from launch.actions import ExecuteProcess
```

使用`ExecuteProcess`调用shell命令

```
example_cmd = ExecuteProcess(
    cmd=['some-cmd', 'some-cmd'], #命令，用逗号隔开
    additional_env={'EXAMPLE_PATH': path}, #可以添加临时的环境变量
    output='screen'
)

ld.add_action(example_cmd)
```

### 获取路径

使用`FindPackageShare`获取package路径

```
from launch_ros.substitutions import FindPackageShare
......
package-name = ‘example-package’
package-path = FindPackageShare(package = package-name).find(package-name) 
```

或者使用`get_package_share_directory`

```
from ament_index_python.packages import get_package_share_directory
......
package-name = ‘example-package’
package-path = get_package_share_directory(package-name),
```

### 连接路径

#### 使用join

```
import os
...
#文件
file-name = 'example-file.xxx'
#字符串前加`f`表示可以在字符串里面使用用花括号括起来的变量和表达式，如定义好的`file-name`
file-path = os.path.join(package-path, f'example-folder/{file-name}')
#或者使用逗号隔开
file-path = os.path.join(package-path, 'example-folder', file-name)

#路径
dir-path = os.path.join(package-path, 'example-folder/')
```

#### 使用替换

```
from launch.substitutions import PathJoinSubstitution
...
PathJoinSubstitution([
    FindPackageShare('example-package'),
    'example-folder',
    'example-file.xxx'
])
```

### 改变参数

一般需要用到以下两个模块

```
from launch.substitutions import LaunchConfiguration
from launch.actions import DeclareLaunchArgument
```

`LaunchConfiguration`用于在变量中存储启动参数的值并将它们传递给所需的操作，允许我们在launch文件的任何部分获取启动参数的值。

```
example-cfg = LaunchConfiguration('arg-name', default='true')
```

`DeclareLaunchArgument`用于定义可以从上述启动文件或控制台传递的启动参数

```
example-arg = DeclareLaunchArgument(
    'arg-name',
    default_value='xxx',
    description='some description'
)

ld.add_action(example-arg)
```

### 启动另一个launch文件

假设已经存在很多的单独的launch文件用于启动不同的功能，如果需要同时启动这些launch文件，可以使用`IncludeLaunchDescription`在launch文件中嵌套启动launch文件，这样可以提高复用率。

需要以下两个头文件

```
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
```

使用`IncludeLaunchDescription`嵌套launch文件，其中同样可以使用上文所述的传递参数

```
another-launch = IncludeLaunchDescription(
    PythonLaunchDescriptionSource(
    	os.path.join(launch_file_dir, 'launch-file-name.launch.py')
    ),
    launch_arguments={'arg-name': example-arg}.items()
)

ld.add_action(another-launch)
```

### 在另一个launch文件中使用参数

这是一个困扰了我两天的，比较麻烦的简单问题。我们来看一个实例：这个launch文件有一个字符串格式的路径作为参数，其中的`robot_state_publisher`需要传入`robot_description`作为参数，而这个参数需要使用`open()`，也就是需要那个路径参数。我们自然而然会想到使用`LaunchConfiguration`，但是当你试图获取`urdf_path_cfg`的时候会发现这根本不是一个字符串。具体解决方案如下：

```python
import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node

from launch.actions import OpaqueFunction

def launch_setup(context, *args, **kwargs):
    use_sim_time_cfg = LaunchConfiguration('use_sim_time')
    urdf_path_cfg = LaunchConfiguration('urdf_path')
    urdf_path = urdf_path_cfg.perform(context)

    print('\033[92m' + "robot_state_publisher: Use urdf dir: " + urdf_path + '\033[0m')

    with open(urdf_path, 'r') as infp:
        robot_desc = infp.read()

    robot_state_publisher_node = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        name='robot_state_publisher',
        output='screen',
        parameters=[{
            'use_sim_time': use_sim_time_cfg,
            'robot_description': robot_desc
        }]
    )

    return [
        robot_state_publisher_node,
    ]

def generate_launch_description():

    ld = LaunchDescription()

    use_sim_time_arg = DeclareLaunchArgument(
        'use_sim_time',
        default_value='true',
        description='Use simulation (Gazebo) clock if true'
    )

    urdf_path_arg = DeclareLaunchArgument(
        'urdf_path',
        default_value='robot.urdf',
        description='urdf_path'
    )

    ld.add_action(urdf_path_arg)
    ld.add_action(use_sim_time_arg)
    ld.add_action(OpaqueFunction(function=launch_setup))

    return ld
```

这种写法我个人认为极其不优雅，但是确实能解决实际问题。

强烈建议ROS加入获取参数内容的方法！！！！！