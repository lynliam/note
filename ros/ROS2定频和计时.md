# 玩转ROS2-一文学会ROS2的定频和计时功能(Rate和Timer）

​                 转自http://imyhq.com/ops/20863.html

**目录**

[写在前面](http://imyhq.com/ops/20863.html#写在前面)

[一、C++（使用rclcpp）](http://imyhq.com/ops/20863.html#一、C%2B%2B（使用rclcpp）)

[1. 计时与时间戳](http://imyhq.com/ops/20863.html#1. 计时与时间戳)

[1.1 C++原生](http://imyhq.com/ops/20863.html#1.1 C%2B%2B原生)

[1.2 ROS2的三种时钟和两种时间戳](http://imyhq.com/ops/20863.html#1.2 ROS2的三种时钟和两种时间戳)

[1.3 ROS2自带的时间获取方式](http://imyhq.com/ops/20863.html#1.3 ROS2自带的时间获取方式)

[2. 使用timer](http://imyhq.com/ops/20863.html#2. 使用timer)

[3. 使用rate——WallRate和Rate选哪个？](http://imyhq.com/ops/20863.html#3. 使用rate)

[4. 使用thread](http://imyhq.com/ops/20863.html#4. 使用thread)

[二、python（使用rclpy）](http://imyhq.com/ops/20863.html#二、python（使用rclpy）)

[1. python的time模块](http://imyhq.com/ops/20863.html#1. 计时与时间戳)

[2. 使用timer](http://imyhq.com/ops/20863.html#2. 使用timer)

[3. 使用rate](http://imyhq.com/ops/20863.html#3. 使用rate)

[4. 使用thread](http://imyhq.com/ops/20863.html#4. 使用thread)

[后面的话](http://imyhq.com/ops/20863.html#后面的话)

------



# 写在前面

我们不是来蹭“时间管理大师”热度的，而是实实在在讨论ROS2获取时间戳的技术。

既然要讨论“时间管理”，一向想好学的我们，肯定得去网上查查大家和专家是怎么理解，怎么定义的。反正，不管生活、工作还是学习，都用得上。

> 时间管理是指通过事先规划和运用一定的技巧、方法与工具实现对时间的灵活以及有效运用，从而实现个人或组织的既定目标的过程。

说得有点复杂，我们通俗地讲，时间管理是基本技能，干啥都需要。

对于ROS2环境里的软件编程而言，**时间管理无外乎两类，定频与计时**。

**定频，**以固定周期持续运转；**计时，**更加灵活，与回调函数配合使用。

（扩展知识：回调函数与spin_once或spin配合使用，参见下文）

# 一、C++（使用rclcpp）

## 1. 计时与时间戳

### 1.1 C++原生

C++ 标准库中有三种时钟，且都在chrono包中。他们分别是`system_clock、steady_clock和high_resolution_clock`。

三者用法相似，我们已system_clock为例说明，其他两种在system_clock对应位置替换即可。

```cpp
#include <chrono>
#include <iostream>
#include <time>

std::chrono::steady_clock::time_point start= std::chrono::system_clock::now();
// do something...
std::chrono::steady_clock::time_point end = std::chrono::system_clock::now();
std::chrono::duration<double> diff = end - start;
std::cout << "Time span(s)： " << diff.count() << " s\n";
std::cout << "Time span(ns): " 
          << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
          << "us.\n";
```

再来说说三者的区别。

`system_clock`是系统时钟。可修改的，也可同步网络时间。可以认为有很大的相对性和主观性。`steady_clock`是单调时钟。其时间点单向递增，类似秒表，通常精度能达到纳秒级别，适合计时。

**对于high_resotion_clock，简单的说，不推荐使用，因为不适合移植和稳定编译。**

> `high_resolution_clock`在不同标准库之间有不同的实现。通常它只是system_clock和steay_clock的别名，取决于库或配置。例如对于`gcc`的`libstdc++` 它是`system_clock` ，对于`MSVC，`它是 `steady_clock` ，而对于`clang`的`libc++`，它取决于配置。所以推荐直接使用对应的时钟，而不是`high_resolution_clock`。
>
> 
>
> **简单地说，不推荐使用high_resotion_clock。**



### 1.2 ROS2的三种时钟和两种时间戳

与C++类似，`ROS2`中定义了三种时钟。

默认是使用`RCL_SYSTEM_TIME，即系统时间，对应``C++的``system_clock`。

```cpp
typedef enum rcl_clock_type_t
{
  /// Clock uninitialized
  RCL_CLOCK_UNINITIALIZED = 0,
  /// Use ROS time
  RCL_ROS_TIME,
  /// Use system time
  RCL_SYSTEM_TIME,
  /// Use a steady clock time
  RCL_STEADY_TIME
} rcl_clock_type_t;
```

`ROS2`中存在两种时间戳，一种是实际的物理系统时间，另一种是仿真时间，对应着在线与仿真。两种时间通过参数可以`use_sim_time`设置，可以写在`launch`文件，或执行ros2 launch时手动添加。

仿真时间通常是`Gazebo`发出的`/clock`话题。当需要在仿真环境中测试程序时，要将`use_sim_time`置为`True`，否则会报错，表示时间不匹配。`tf`关系不能正常找到。

###   1.3 ROS2自带的时间获取方式

在说ROS2之前，先用一句话总结：ROS1直接用Time类型。

```cpp
ros::Time now = ros::Time::now();
```

然而，ROS2有了变化，使用builtin_interfaces/msg/Time类型。

总的来说，ROS2有三种形式可以获得当前时间。

```cpp
#include <rclcpp/rclcpp.hpp>

# 为方便说明获取时间的方法，先创建一个node
auto node = rclpy.node.Node("exampleNode");

# 第一种方法不受use_sim_time的影响，总是输出物理系统的真实时间。
auto t1 = rclcpp::Clock().now();

# 后面两种方法，要区分物理系统时间和仿真时间。
auto t2 = node->get_clock()->now();
auto t3 = node->now();
```

**我们稍微归纳总结以下：**

**1）关闭仿真模式时，ROS2的三个方法**`rclcpp::Clock().now()`，`this->get_clock()->now()`和`this->now()`获取的时间与C++里的`std::chrono::system_clock::now()`是一致的，都是系统时间。

**2）打开仿真模式后，**`rclcpp::Clock().now()`**依然等于**`std::chrono::system_clock::now()`，无法获取仿真时间。

**3）**`this->get_clock()->now()`和`this->now()`是等效的，可以返回真实时间，也可返回仿真时间。

**更进一步，我们提炼一个更简单更适用的结论：**

> **ROS2代码中要获取时间戳时，直接使用`this->``get_clock()->now()或``this->now()`接口，这样可以保证在标志位`use_sim_time`变化时，代码各处使用的时间戳是一致的。**

这里值得多说几句的是，**ROS2的三个方法**`rclcpp::Clock().now()`，`this->get_clock()->now()`和`this->now()`获取的时间戳均包含`seconds()`和`nanoseconds()`两个等价方法，两者仅单位不同，前者是秒，后者是纳秒。

```cpp
rclcpp::Node::SharedPtr node_handle = nullptr;
node_handle = rclcpp::Node::make_shared("newNode");

//获取时间戳
builtin_interfaces::msg::Time now = node->get_clock()->now();
//分别获取秒和纳秒
double time_s = node->get_clock()->now().seconds();
double time_ns = node_handle->get_clock()->now().nanoseconds();
```

同理，`ROS2`中的时间类型`builtin_interfaces::msg::Time`是需要把秒和纳秒组合起来才能表示当前时间的。

```cpp
// 如果获取的是msg时间戳，恢复成完整表达如下
auto now_sec = msg->header.stamp.sec + msg->header.stamp.nanosec * 1e-9;
```

如果要计算程序运行时间，依然与C++类似，选用`RCL_STEADY_TIME`时钟比较准确的。

```cpp
rclcpp::Clock steady_clock_{RCL_STEADY_TIME};

auto start_time = steady_clock_.now();
//do something ...
auto cycle_duration = steady_clock_.now() - start_time;

RCLCPP_INFO(get_logger(), "Cost %.4f s", cycle_duration.seconds());
```



## 2. 使用timer

用法很直观，回调函数可以直接按常规方法定义，也可以用lambda表示达。

```cpp
#include "rclcpp/rclcpp.hpp"
#include <iostream>
#include <time.h>
#include <chrono>

// using namespace std;
using namespace std::chrono_literals;

// 第一个回调函数
auto timer1_callback =
            []() -> void
            {
                RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "-------timer callback!-----------");
                // do something else;
            };

// 第二个回调函数
void timer2_callback()
{
	// 获取时间
	time_t tt;
	time( &tt );

    // 调整时区
	tt = tt + 8*3600;  
	tm* t= gmtime( &tt );

	// 打印到终端上
	std::cout<<"current time   - "<<t->tm_hour<<":"<<t->tm_min<<":"<<t->tm_sec<<std::endl;
}

int main(int argc, char** argv){
    rclcpp::init(argc, argv);

    rclcpp::Node::SharedPtr node_handle = nullptr;
    node_handle = rclcpp::Node::make_shared("newNode");

    //创建两个定时器，并定义回调函数
    rclcpp::TimerBase::SharedPtr timer1,timer2;
    timer1 = node_handle->create_wall_timer(500ms, timer1_callback);
    timer2 = node_handle->create_wall_timer(1s, timer2_callback);

    rclcpp::spin(node_handle);
	rclcpp::shutdown();

    return 0;
}
```

上面程序主要看这一段

```cpp
    //创建两个定时器，并定义回调函数
    rclcpp::TimerBase::SharedPtr timer1,timer2;
    timer1 = node_handle->create_wall_timer(500ms, timer1_callback);
    timer2 = node_handle->create_wall_timer(1s, timer2_callback);
```

另外，提醒以下，为了用好create_wall_timer，记得声明。

```cpp
using namespace std::chrono_literals;
```

## 3. 使用rate——WallRate和Rate选哪个？

没错，有两个让人困惑的rate。那就在源码里看看定义吧。

```cpp
// Rate，使用系统时钟
using rclcpp::rate::Rate = typedef GenericRate<std::chrono::system_clock>
// WallRate，使用稳定时钟
using rclcpp::rate::WallRate = typedef GenericRate<std::chrono::steady_clock> 
```

嗯，也就这点区别，很容易理解。Rate与system_clock对应，WallRate则与steady_clock对应。

使用起来有类似单片机或嵌入式系统的中断的味道。

以WallRate为例，我们看看示例用法。

```cpp
#include "rclcpp/rclcpp.hpp"
#include <time.h>

using namespace std;

int main(int argc, char** argv){
    rclcpp::init(argc, argv);

    rclcpp::Node::SharedPtr node_handle = nullptr;
    node_handle = rclcpp::Node::make_shared("newNode");

	// 定频10Hz
    rclcpp::WallRate loop_rate(10.0);
    while (rclcpp::ok())
    {
        RCLCPP_INFO(rclcpp::get_logger("newNode"), "-------timer callback!-----------");
        /* 可以再干点别的事 */
        loop_rate.sleep();
    }

    return 0;
}
```

关于rate使用的注意事项，放到python版本一起讲。

## 4. 使用thread

使用thread

```cpp
#include "rclcpp/rclcpp.hpp"
#include <thread>

class CustomizedNode: public rclcpp::Node
{
public:
    CustomizedNode(): Node("rate_node"), loop_rate_(1.0)
    {
        RCLCPP_INFO(this->get_logger(), "--CustomizedNode Inititalization!--");
        std::thread task01(std::bind(&CustomizedNode::_function_A, this));
        task01.join();

    }
    void _function_A()
    {
        while (rclcpp::ok())
        {
            RCLCPP_INFO(this->get_logger(), "-------Rate callback!-----------");
            /* 可以再干点别的事 */
            loop_rate_.sleep();
        }
    }
private:
    rclcpp::WallRate loop_rate_;
};

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<CustomizedNode>());
    rclcpp::shutdown();
    return 0;
}
```



# 二、python（使用rclpy）

## 1. python的time模块

在 Python 中，通常有三种方式来表示时间：时间戳、格式化的时间字符串、元组struct_time。

先说后面两种在ROS2中不常用的方式。

一个是格式化的时间字符串，通用用于打印，常用于人机交互和显示；另外一个是元组（struct_time)，以元组形式（或理解成结构体形式）来表达时间，可以单独获得 9 个元素，比如年月日、时分秒、一周的第几日、一年的第几天以及是否夏令时。

再说说我们在ROS2中常用于时间记录的时间戳。
 时间戳，即timestamp。通常来说，时间戳表示的是从1970年1月1日00:00:00开始按秒计算的偏移量。常用命令为time.time() ，返回的是float类型。

```python
import time

# 返回时间戳，一个浮点数
time.time()

# 返回时间元组
# time.struct_time(tm_year=2022, tm_mon=12, tm_mday=4, tm_hour=12, tm_min=34, tm_sec=56, tm_wday=6, tm_yday=338, tm_isdst=0)
time.localtime()

# 返回时间字符串,比如：'Sun Dec  4 12:34:56 2022'
time.asctime()
```

另外，介绍两个有用的时间格式转换方法，用于打印时间信息。

```python
# 时间戳转成字符串形式，默认转化为time.asctime()的形式。
# 如果参数未给或者为 None 的时候，将会默认time.time()为参数。
time.ctime()

# time.strftime(format,[t])
# 把时间元组（struct_time）转化为格式化的时间字符串。
# 如果参数t未指定，将传入time.localtime()。
time.strftime("%Y年-%m月-%d日 %H:%M:%S", time.localtime()))
```

## 2. 使用timer

我个人认为，只要你理解了timer，那用起来真的是简单粗暴。

```python
import time
import rclpy
from rclpy.node import Node
import threading

# 定时器设定的周期，单位s
TIMER_INTERVAL = 1
# 功能函数执行的时间（用time.sleep仿真）
SLEEP_INTERVAL = 0.1


class CustomizedNode(Node):
    def __init__(self, name):
        super().__init__(name)

        # 创建计时器，并绑定回调函数
        self._timer = self.create_timer(TIMER_INTERVAL, self._function_A) 

    # 需要定时执行的函数
    def _function_A(self):
        self.get_logger().info(f"[_function_A]: Lalala, I'm a callback now!, sleep for {SLEEP_INTERVAL}s")
        time.sleep(SLEEP_INTERVAL) #休眠，仿真出函数执行的耗时

def main():
    rclpy.init()
    node = CustomizedNode("RobotNode")
    rclpy.spin(node)
    rclpy.shutdown()    


if __name__=="__main__":
    main()
```

## 3. 使用rate

被誉为定频神器的rate，其实有很大的局限性。rate设置的频率必须得到保证，如果循环执行的任务用时超出rate频率，那么rate.sleep()是没有作用的。

我们先来看看下面的例子。

```python
import time
import rclpy
from rclpy.node import Node

# 设置循环调用的频率
RATE_INTERVAL = 5
# 功能函数执行的时间（用time.sleep替代）
SLEEP_TIME = 0.1

# 循环的功能函数
def main_work(node, count):
    node.get_logger().info(f"sleep for {SLEEP_TIME}s - {count} times")
    time.sleep(SLEEP_TIME) #休眠，仿真出函数执行的耗时

if __name__=="__main__":
    rclpy.init()

    node = Node("exampleNode")
    rate = node.create_rate(RATE_INTERVAL) 
    start = time.time()
    for i in range(RATE_INTERVAL):

        # 循环执行的功能
        main_work(node, i)

        rclpy.spin_once(node)
        rate.sleep() #调用一次rate.sleep()
    end = time.time()
    print(f'循环{RATE_INTERVAL}次，耗时：{end-start}')

    rclpy.shutdown()
```

 在下面的例子里，rate频率RATE_INTERVAL取5，对应的执行周期是0.2，那么循环的功能主体的时间应小于0.2，此时，rate.sleep()是能实现定频的。

 ![img](http://qny.xmhxz.net/xzblog/2023/04/08/168092280678f5ace1db6a4b3db4be7442d52c520a.png?imageView2/1/q/50)

但是，如果此后将SLEEP_TIME改成1，你会发现，rate.sleep()不按照设定工作了。

![img](http://qny.xmhxz.net/xzblog/2023/04/08/16809228070a4159e435c844d0b639cae875572998.png?imageView2/1/q/50)

## 4. 使用thread

对于定制节点，为了能一直循环使用rate，我们单独开一个线程。

方法也很简单，示例代码如下：

```python
import rclpy
from rclpy.node import Node
import threading


class CustomizedNode(Node):
    def __init__(self, name):
        super().__init__(name)

        # 创建Rate，数量随意，可1或多
        self._rate = self.create_rate(1) 

        # 创建线程，数量随意，可1或多
        self._thread_1 = threading.Thread(target=self._function_A)
        self._thread_1.start()
        self._thread_2 = threading.Thread(target=self._function_B)
        self._thread_2.start()

    # 需要在线程里调用的函数
    def _function_A(self):
        while rclpy.ok():
            print("[_function_A]: Yes, commander!")
            self._rate.sleep()

    # 需要在线程里调用的函数
    def _function_B(self):
        while rclpy.ok():
            print("[_function_B]: Show me the money!")
            self._rate.sleep()

if __name__=="__main__":
    rclpy.init()
    node = CustomizedNode("RobotNode")
    rclpy.spin(node)
    rclpy.shutdown()
```