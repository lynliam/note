# RVIZ2可视化模型



URDF可视化的步骤如下：

1. 建立机器人描述功能包
2. 建立`urdf`文件夹编写urdf文件
3. 建立`launch`文件夹，编写launch文件
4. 修改`setup.py`配置，编译测试



## 1. 建立功能包

```shell
ros2 pkg create fishbot_description --build-type ament_python
```



## 2. URDF

```shell
cd fishbot_description && mkdir urdf
touch fishbot_base.urdf

#├── fishbot_description
#│   ├── __init__.py
#├── package.xml
#├── setup.cfg
#├── setup.py
#└── urdf
#    └── fishbot_base.urdf
```

`urdf`文件

```xml
<?xml version="1.0"?>
<robot name="fishbot">
    
  <!-- base link -->
  <link name="base_link">
      <visual>
      <origin xyz="0 0 0.0" rpy="0 0 0"/>
      <geometry>
        <cylinder length="0.12" radius="0.10"/>
      </geometry>
    </visual>
  </link>
    
  <!-- laser link -->
  <link name="laser_link">
      <visual>
      <origin xyz="0 0 0" rpy="0 0 0"/>
      <geometry>
        <cylinder length="0.02" radius="0.02"/>
      </geometry>
      <material name="black">
          <color rgba="0.0 0.0 0.0 0.8" /> 
      </material>
    </visual>
  </link>
    
  <!-- laser joint -->
    <joint name="laser_joint" type="fixed">
        <parent link="base_link" />
        <child link="laser_link" />
        <origin xyz="0 0 0.075" />
    </joint>

</robot>
```



## 3. 建立launch

```shell
mkdir launch
touch display_rviz2.launch.py
```

目录：

```shell
├── fishbot_description
│   ├── __init__.py
├── launch
│   └── display_rviz2.launch.py
├── package.xml
├── setup.cfg
├── setup.py
└── urdf
    └── fishbot_base.urdf
```

```python
import os
from launch import LaunchDescription
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():
    package_name 
```





