# ROS坐标系统，常见的坐标系和其含义 			

​		[ 			![weijiz](ROS坐标系.assets/7-profileimg.png) 			 		](http://community.bwbot.org/user/weijiz) 

​		 		**[weijiz](http://community.bwbot.org/user/weijiz)** 	 		 		 		 		 			 			 		 	 	 	  	 		 		 		[2017年9月27日 16:59](http://community.bwbot.org/post/317) 	 

### 常见的坐标系

在使用ROS进行定位导航等操作时，我们经常会遇到各种坐标系。每种坐标系都有明确的含义。理论上坐标系的名称可以是随意的，但是为了方便不同的软件间共享坐标信息，ROS定义了几个常见的坐标系。

1.`base_link`
 `base_link`坐标系和机器人的底盘直接连接。其具体位置和方向都是任意的。对于不同的机器人平台，底盘上会有不同的参考点。不过ROS也给了推荐的坐标系取法。

x 轴指向机器人前方
 y 轴指向机器人左方
 z 轴指向机器人上方

2.`odom`
 `odom`是一个固定在环境中的坐标系也就是world-fixed。它的原点和方向不会随着机器人运动而改变。但是odom的位置可以随着机器人的运动漂移。漂移导致`odom`不是一个很有用的长期的全局坐标。然而机器人的`odom`坐标必须保证是连续变化的。也就是在`odom`坐标系下机器人的位置必须是连续变化的，不能有突变和跳跃。
 在一般使用中`odom`坐标系是通过里程计信息计算出来的。比如轮子的编码器或者视觉里程计算法或者陀螺仪和加速度计。`odom`是一个短期的局域的精确坐标系。但是却是一个比较差的长期大范围坐标。

3.`map`
 `map`和`odom`一样是一个固定在环境中的世界坐标系。`map`的z轴是向上的。机器人在`map`坐标系下的坐标不应该随着时间漂移。但是`map`坐标系下的坐标并不需要保证连续性。也就是说在map坐标系下机器人的坐标可以在任何时间发生跳跃变化。
 一般来说`map`坐标系的坐标是通过传感器的信息不断的计算更新而来。比如激光雷达，视觉定位等等。因此能够有效的减少累积误差，但是也导致每次坐标更新可能会产生跳跃。
 `map`坐标系是一个很有用的长期全局坐标系。但是由于坐标会跳跃改变，这是一个比较差的局部坐标系（不适合用于避障和局部操作）。

### 坐标系的约定

在非结构化的环境中（比如开放环境），如果我们要定义一个全球坐标系

1. 默认的方向要采用 x轴向东，y轴向北，z轴向上
2. 如果没有特殊说明的话z轴为零的地方应该在WGS84椭球上(WGS84椭球是一个全球定位坐标。大致上也就是z代表水平面高度)
    如果在开发中这个约定不能完全保证，也要求尽量满足。比如对于没有GPS，指南针等传感器的机器人，仍然可以保证坐标系z轴向上的约定。如果有指南针传感器，这样就能保证x和y轴的初始化方向。

在结构化的环境中（比如室内），在定义坐标系时和环境保持对应更有用。比如对于有平面图的建筑，坐标系可以和平面图对应。类似的对于室内环境地图可以和建筑物的层相对应。对于有多层结构的建筑物，对每一层单独有一个坐标系也是合理的。

4.`earth`
 这个坐标系是为了多个机器人相互交互而设计的。当有多个机器人的时候，每个机器人都有自己的`map`坐标系，他们之间的`map`坐标系并不相同。如果想要在不同的机器人间共享数据，则需要这个坐标系来进行转化。
 如果`map`坐标系是一个全局坐标系，那么`map`到`earth`坐标系的变化可以是一个静态变换。如果不是的话，就要每次计算`map`坐标系的原点和方向。
 在刚启动的时候`map`坐标系的全局位置可能是不知道的。这时候可以先不发布到`earth`的变换，直到有了比较精确的全局位置。

坐标系之间的关系
 坐标系之间的关系可以用树图的方式表示。每一个坐标系只能有一个父坐标系和任意多个子坐标系。

`earth -> map -> odom -> base_link`
 按照之前的说明，`odom`和`map`都应该连接到`base_link`坐标系。但是这样是不允许的，因为每一个坐标系只能有一个父坐标系。

额外的中间坐标系
 这个图只表示了最少的坐标系。在保证基本的结构不变的情况下可以在其中加入中间的坐标系以提供额外的功能。

多机器人坐标系的例子

```
earth --> map_1 --> odom_1 --> base_link1`
 `earth --> map_2 --> odom_2 --> base_link2 
```

### 坐标系变换的计算

`odom`到`base_link`的变换由里程计数据源中的一个发布

`map`到`base_link`通过定位组件计算得出。但是定位组件并不发布从`map`到`base_link`的变换。它首先获取`odom`到`base_link`的变换然后利用定位信息计算出`map`到`odom`的变换。

`earth`到`map`的变换是根据`map`坐标系选取所发布的一个静态变换。如果没有设置，那么就会使用机器人的初始位置作为坐标原点。

### Map之间的切换

如果机器人的运动范围很大，那么极有可能是要切换地图的。在室内环境下，在不同的建筑物中，和不同的楼层地图都会不同。
 在不同的地图间切换的时候，定位组件要恰当的把`odom`的`parent`替换成新的地图。主要是`map`到`base_link`之间的变换要选取恰当的地图，然后在转换成`map`到`odom`之间的变换。

odom坐标系的连续性
 在切换地图的时候，odom坐标系不应该受到影响。odom坐标系要保证连续性。可能影响连续性的情况包括进出电梯，机器人自身没有运动，但是周围环境发生很大的变化。还有可能由于运动距离太远，造成数据溢出。这些都要特殊进行处理。





---

REP: 105 Title: Coordinate Frames for Mobile Platforms Author: Wim Meeussen Status: Active Type: Informational Content-Type: text/x-rst Created: 27-Oct-2010 Post-History: 27-Oct-2010



## 

## Abstract

This REP specifies naming conventions and semantic meaning for coordinate frames of mobile platforms used with ROS.



## 

## Motivation

Developers of drivers, models, and libraries need a share convention for coordinate frames in order to better integrate and re-use software components. Shared conventions for coordinate frames provides a specification for developers creating drivers and models for mobile bases. Similarly, developers creating libraries and applications can more easily use their software with a variety of mobile bases that are compatible with this specification. For example, this REP specifies the frames necessary for writing a new localization component. It also specifies frames that can be used to refer to the mobile base of a robot.



## 

## Specification



### 

### Coordinate Frames



#### 

#### base_link

The coordinate frame called `base_link` is rigidly attached to the mobile robot base. The `base_link` can be attached to the base in any arbitrary position or orientation; for every hardware platform there will be a different place on the base that provides an obvious point of reference. Note that REP 103 [[1\]](https://github.com/ros-infrastructure/rep/blob/master/rep-0105.rst#id8) specifies a preferred orientation for frames.



#### 

#### odom

The coordinate frame called `odom` is a world-fixed frame. The pose of a mobile platform in the `odom` frame can drift over time, without any bounds. This drift makes the `odom` frame useless as a long-term global reference. However, the pose of a robot in the `odom` frame is guaranteed to be continuous, meaning that the pose of a mobile platform in the `odom` frame always evolves in a smooth way, without discrete jumps.

In a typical setup the `odom` frame is computed based on an odometry source, such as wheel odometry, visual odometry or an inertial measurement unit.

The `odom` frame is useful as an accurate, short-term local reference, but drift makes it a poor frame for long-term reference.



#### 

#### map

The coordinate frame called `map` is a world fixed frame, with its Z-axis pointing upwards. The pose of a mobile platform, relative to the `map` frame, should not significantly drift over time. The `map` frame is not continuous, meaning the pose of a mobile platform in the `map` frame can change in discrete jumps at any time.

In a typical setup, a localization component constantly re-computes the robot pose in the `map` frame based on sensor observations, therefore eliminating drift, but causing discrete jumps when new sensor information arrives.

The `map` frame is useful as a long-term global reference, but discrete jumps in position estimators make it a poor reference frame for local sensing and acting.

**Map Conventions**

Map coordinate frames can either be referenced globally or to an application specific position. A example of an application specific positioning might be Mean Sea Level [[3\]](https://github.com/ros-infrastructure/rep/blob/master/rep-0105.rst#msl) according to EGM1996 [[4\]](https://github.com/ros-infrastructure/rep/blob/master/rep-0105.rst#egm96) such that the z position in the map frame is equivalent to meters above sea level. Whatever the choice is the most important part is that the choice of  reference position is clearly documented for users to avoid confusion.

- When defining coordinate frames with respect to a global reference like the earth:

  The default should be to align the x-axis east, y-axis north, and the z-axis up at the origin of the coordinate frame. If there is no other reference the default position of the z-axis should be zero at the height of the WGS84 ellipsoid.

In the case that there are application specific  requirements for which the above cannot be satistfied as many as  possible should still be met.

An example of an application which cannot meet the above  requirements is a robot starting up without an external reference device such as a GPS, compass, nor altimeter. But if the robot still has an accelerometer it can intialize the map at  its current location with the z axis upward.

If the robot has a compass heading as startup it can then also initialize x east, y north.

And if the robot has an altimeter estimate at startup it can initialize the height at MSL.

The conventions above are strongly recommended for unstructured environments.

**Map Conventions in Structured Environments**

In structured environments aligning the map with the  environment may be more useful. An example structured environment such as an office building interior,  which is commonly rectilinear and have limited global localization  methods, aligning the map with building is recommended especially if the building layout is known apriori. Similarly in an indoor environment it is recommended to align the map at floor level. In the case that you are operating on multiple floors it may make sense  to have multiple coordinate frames, one for each floor.

If there is ambiguity fall back to the conventions for  unstructured environments above. Or if there is limited prior knowledge of the environment the  unstructured conventions can still be used in structured environments.



#### 

#### earth

The coordinate frame called `earth` is the origin of ECEF. [[2\]](https://github.com/ros-infrastructure/rep/blob/master/rep-0105.rst#id9)

This frame is designed to allow the interaction of multiple robots in different map frames. If the application only needs one map the `earth` coordinate frame is not expected to be present. In the case of running with multiple maps simultaneously the `map` and `odom` and `base_link` frames will need to be customized for each robot. If running multiple robots and bridging data between them, the transform frame_ids can remain standard on each robot if the other robots'  frame_ids are rewritten.

If the `map` frame is globally referenced the publisher from `earth` to `map` can be a static transform publisher. Otherwise the `earth` to `map` transform will  usually need to be computed by taking the estimate of the current global position and subtracting the current estimated pose in the map to get  the estimated pose of the origin of the map.

In case the `map` frame's absolute positon is  unknown at the time of startup, it can remain detached until such time  that the global position estimation can be adaquately evaluated. This will operate in the same way that a robot can operate in the `odom` frame before localization in the `map` frame is initialized.

![Earth Centered Earth Fixed diagram](ROS坐标系.assets/ECEF_ENU_Longitude_Latitude_relationships.svg+xml)A visualization of Earth Centered Earth Fixed with a tangential `map` frame.



### 

### Relationship between Frames

We have chosen a tree representation to attach all coordinate frames in a robot system to each other. Therefore each coordinate frame has one parent coordinate frame, and any number of child coordinate frames. The frames described in this REP are attached as follows:

%% Example diagram graph LR    O(odom) --> B(base_link)    M(map) --> O    E(earth) --> M

The `map` frame is the parent of `odom`, and `odom` is the parent of `base_link`.  Although intuition would say that both `map` and `odom` should be attached to `base_link`, this is not allowed because each frame can only have one parent.

**Extra Intermediate Frames**

This graph shows the minimal representation of this graph. The basic topology should stay the same, however it is fine to insert  additional links in the graph which may provide additional  functionality.

**Pressure Altitude**

An example of a potential additional coordinate frame is one to represent pressure altitude for flying vehicles. Pressure altitude is an approximation of altitude based on a shared estimate of the atmospheric barometric pressure. [[5\]](https://github.com/ros-infrastructure/rep/blob/master/rep-0105.rst#pressure-altitude) In flying applications pressure altitude can be measured precisely using just a barometric altimeter. It may drift in time like odometry but will only drift vertically. To be useful a `pressure_altitude` frame could be inserted between the inertially consistent `odom` frame and the `map` frame. There would need to be an additional estimator to estimate the offset of the `pressure_altitude` from the `map` but this extra coordinate frame can support extra functionality and does not break the abstraction outlined above.



### 

### Example of multi-robot tf graph using ECEF

%% Example diagram graph TB    odom_1(odom_1) --> base_link1(base_link1)    map_1(map_1) --> odom_1    earth(earth) --> map_1    odom_2(odom_2) --> base_link2(base_link2)    map_2(map_2) --> odom_2    earth --> map_2

This is an example of a tf tree with two robots using different maps for localization and having a common frame `earth`.

The diagram above uses different frame ids for clarity. However for maximum reusability it is recommended to use the canonical  frame ids on each robot and use a script to forward information off of  the robot. When the information is forwarded the frame ids should be remapped to  disambiguate which robot they are coming from and referencing.



### 

### Frame Authorities

The transform from `odom` to `base_link` is computed and broadcast by one of the odometry sources.

The transform from `map` to `base_link` is computed by a localization component. However, the localization component does not broadcast the transform from `map` to `base_link`. Instead, it first receives the transform from `odom` to `base_link`, and uses this information to broadcast the transform from `map` to `odom`.

The transform from `earth` to `map`  is statically published and configured by the choice of map frame. If not specifically configured a fallback position is to use the initial position of the vehicle as the origin of the map frame. If the map is not georeferenced so as to support a simple static  transform the localization module can follow the same procedure as for  publishing the estimated offset from the `map` to the `odom` frame to publish the transform from `earth` to `map` frame.



### 

### Transitions Between Maps

When a robot travels a long distance it is expected that  it will need to transition between maps. In an outdoor context map coordinate frame is a euclidian approximation  of a vicinity however the euclidian approximation breaks down at longer  distances due to the curvature of the earth. In an indoor context this can be transitioning between two buildings  where each has a prior map in which you are navigating or the robot is  on a new floor of a building.

It is the responsibility of the localization frame authority to reparent the `odom` frame appropriately when moving between maps. The common implementation of computing the `map` to `odom` frame as the results of subtracting the `odom` to `base_link` from the localization fix `map` to `base_link` will take care of this implicitly when the choice of which `map` frame changes.

**odom Frame Consistency**

When transitioning between maps the odometric frame should not be affected. Data retention policies for data collected in the odom frame should be  tuned such that old or distant data is discarded before the integrated  position error accumulates enough to make the data invalid. Depending on the quality of the robot's odometry these policies may be  vastly different. A wheeled vehicle with multiple redundant high  resolution encoders will have a much lower rate of drift and will be  able to keep data for a much longer time or distance than a skid steer  robot which only has open loop feedback on turning.

There are other contexts which will also affect  appropriate retention policy, such as the robot being moved by external  motivators, or assumptions of a static environment. An example is a robot in an elevator, where the environment outside has  changed between entering and exiting it. Most of these problems come from the assumption of a static environment  where observations are in the same inertial frame as the robot. In these cases semantic information about the environment and its  objects is required to manage persistent data correctly. Regardless, the inertial odom frame should always remain continuous.

If the vehicle travels a long enough distance that the distance from the `odom` frame's origin to the vehicle approaches the maximum floating point  precision, degraded performance may be observed for float-based data  persisted in the `odom` frame. This is especially true of 32-bit floating point data used in things like pointclouds. If distances on this order are encountered a systematic reset of the `odom` frame origin may be required. If centimeter level accuracy is required the maximum distance to the `odom` frame is approximately 83km. [[6\]](https://github.com/ros-infrastructure/rep/blob/master/rep-0105.rst#floating-point) There is not a standard solution to this, systems with this issue will  need to work around it. Potential solutions include additional coordinate frames in which to  persist obstacle data or to store obstacle data, or using higher  precision.



### 

### Exceptions

The scope of potential robotics software is too broad to require all ROS software to follow the guidelines of this REP.  However, choosing different conventions should be well justified and well documented.



## 

## Compliance

This REP depends on and is compliant with REP 103 [[1\]](https://github.com/ros-infrastructure/rep/blob/master/rep-0105.rst#id8).



## 

## References

| [1]  | *([1](https://github.com/ros-infrastructure/rep/blob/master/rep-0105.rst#id1), [2](https://github.com/ros-infrastructure/rep/blob/master/rep-0105.rst#id7))* REP 103, Standard Units of Measure and Coordinate Conventions (http://www.ros.org/reps/rep-0103.html) |
| ---- | ------------------------------------------------------------ |
|      |                                                              |

| [[2\]](https://github.com/ros-infrastructure/rep/blob/master/rep-0105.rst#id4) | Earth Centered, Earth Fixed Wikipedia article (https://en.wikipedia.org/wiki/ECEF) |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
|                                                              |                                                              |

| [[3\]](https://github.com/ros-infrastructure/rep/blob/master/rep-0105.rst#id2) | Mean Sea Level (https://en.wikipedia.org/wiki/Sea_level) |
| ------------------------------------------------------------ | -------------------------------------------------------- |
|                                                              |                                                          |

| [[4\]](https://github.com/ros-infrastructure/rep/blob/master/rep-0105.rst#id3) | EGM1996 (http://earth-info.nga.mil/GandG/wgs84/gravitymod/egm96/egm96.html) |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
|                                                              |                                                              |

| [[5\]](https://github.com/ros-infrastructure/rep/blob/master/rep-0105.rst#id5) | Pressure Altitude (https://en.wikipedia.org/wiki/Pressure_altitude) |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
|                                                              |                                                              |

| [[6\]](https://github.com/ros-infrastructure/rep/blob/master/rep-0105.rst#id6) | Floating Point Precision (https://en.wikipedia.org/wiki/Single-precision_floating-point_format) |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
|                                                              |                                                              |