# Note



## 哈工程

### 底盘

1.    使用微动开关  来找舵轮初始位置
2.   定位：码盘   
3.   因为VESC有电流限制，故采用分段加速，采用MATLAB拟合

Matlab拟合：

S型加速路径：

1. 时间和速度的匹配

2. 路程和速度的匹配，`matlab` 找最合适的解

### 发射机构：

加速行程越长，越稳定



## 大连工业

![image-20231028215232585](note of 电控分享.assets/image-20231028215232585.png)



can  最多接6个电机，多了会丢数据



atan函数避免为 0   （）反三角）

![image-20231028215654973](note of 电控分享.assets/image-20231028215654973.png)

![image-20231028215705432](note of 电控分享.assets/image-20231028215705432.png)

解决翘头





![image-20231028220107228](note of 电控分享.assets/image-20231028220107228.png)

只获取一次坐标，防止摇摆。



vesc   烧？？？？？？？？？



![image-20231028220755596](note of 电控分享.assets/image-20231028220755596.png)



位置控制    电流有限幅



![image-20231028221148238](note of 电控分享.assets/image-20231028221148238.png)

 给一个小电流，当碰到flag  将当前角度置零

限制电流恒定力矩



![image-20231028221257011](note of 电控分享.assets/image-20231028221257011.png)

一到指定速度就加限幅，小于就取消限幅



![image-20231028221443691](note of 电控分享.assets/image-20231028221443691.png)



![image-20231028221600171](note of 电控分享.assets/image-20231028221600171.png)





ROS control   



![image-20231028221741444](note of 电控分享.assets/image-20231028221741444.png)

![image-20231028221757826](note of 电控分享.assets/image-20231028221757826.png)



![image-20231028221825216](note of 电控分享.assets/image-20231028221825216.png)



![image-20231028222256913](note of 电控分享.assets/image-20231028222256913.png)

![image-20231028222322827](note of 电控分享.assets/image-20231028222322827.png)

![image-20231028222357748](note of 电控分享.assets/image-20231028222357748.png)



**硬件映射**？？？？



**组局域网**？？？



**目标插补曲线**

<img src="note of 电控分享.assets/image-20231028223818877.png" alt="image-20231028223818877" style="zoom:50%;" />



![image-20231028223835560](note of 电控分享.assets/image-20231028223835560.png)

==实体按键还是最好==



![image-20231028224936477](note of 电控分享.assets/image-20231028224936477.png)



贵的陀螺仪

5m 偏移 3cm??



网络调试  udp调试

Jscope

![image-20231028225220107](note of 电控分享.assets/image-20231028225220107.png)

微分跟踪器



### 网口很快  





##  四川大学![image-20231028234205567](note of 电控分享.assets/image-20231028234205567.png)



![image-20231028234356083](note of 电控分享.assets/image-20231028234356083.png)

遥控器使用：

NRF



![image-20231028234958106](note of 电控分享.assets/image-20231028234958106.png)



DT35   激光测距慢？？？





