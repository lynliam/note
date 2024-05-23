# I2C

***
#### I2C的读法

* 在“Inter-Integrated Circuit” 中，“Inter-” 表示“在……之间，相互”的意思；“Integrated Circuit” 简称“IC”，表示“集成电路”的意思。 “Inter-Integrated Circuit”，直接翻译过来就是内部集成电路（DeepL翻译为互联电路，微软翻译为内部集成电路，百度翻译为内置集成电路）。德力威尔王术平认为，应该把“Inter-Integrated Circuit”翻译为集成电路互连或者芯片互连，更符合国人习惯，更为贴切。

* 在中国正式的书面场合，全称写作Inter-Integrated Circuit，简写Inter-IC或者I2C（数字“2”书写为上标，，英文读作“I squared C”，中文读作“I平方C”）。

*  在非正式场合或者数字“2”无法书写为上标时，有人就书写为“IIC”或者“I2C”，把“IIC”读作“I-I-C”，把“I2C”读作“I-two-C”或“I二C”。这些书写方式或叫法，其实没有对错，只是不同习惯而已，就像普通话和地方话一样。但是，我们在严谨的正式场合，还是要统一标准，规范书写为“I2C”（数字“2”书写为上标），规范读作“I平方C”。

* 在本文中，德力威尔王术平对相关术语的中文解释做出如下约定：

* I2C：读作“I平方C”（尽量不读作“I方C”，避免和I3C混淆）。

I2C：集成电路互连。

I2C Bus：I2C总线或集成电路互连总线。

I2C Specification：I2C规范或集成电路互连规范。

I2C Communication Interface：I2C通信接口或集成电路互连通信接口。


I2C Communication Protocol：I2C通信协议或集成电路互连通信协议。

I2C：在无法书写上标数字“2”时，可书写为“IIC”或“I2C”。

***
#### 概览

1. 半双工通信协议
2. **SCL总线**（串行时钟总线） && **SDA总线**（双向串行数据线）
3. 一个主机，多个从机（主机控制传输请求）
4. 每个设备均有一个地址。
5. 具有三种传输速率

![frm](E:\markdown\STM32\image\3.png)

#### I2C协议

* 起始信号(S)
* 从机接收到地址后会返回：
  * 应答信号
  * 非应答信号
* 主机每次发送一个数据包都要等待从机的应答信号
* 结束信号（P）

起始信号和停止信号是一种电平跳变时序信号，而不是一个电平信号。

* 应答信号（ACK）：第 9 个脉冲带来之前将 SDA 设置低电平，并且在时钟线为高电平期间保持 SDA 为低电平。

* 非应答信号（NACK）：第 9 个脉冲带来之前将 SDA 设置高电平，并且在时钟线为高电平期间保持 SDA 为高电平

#### 数据的传输

* 在使用 I2C 进行数据传输时，需要知道从机的地址，从机地址一般有 7 位和 10 位
* 读数据方向时，主机会释放对 SDA 信号线的控制，由从机控制 SDA 信号线，主机接收信号，写
数据方向时，SDA 由主机控制，从机接收信号。
* 传输时主机产生时钟，在第 9 个时钟时，数据发送端会释放 SDA 的控制权，由数据接收端控制
SDA，若 SDA 为高电平，表示非应答信号 (NACK)，低电平表示应答信号 (ACK)。

#### STM32 的 I2C 特性及架构

* “软件模拟协议”方式：直接控制 GPIO 引脚电平产生通讯时序时，需要由 CPU 控制每个时刻的引脚状态

* “硬件协议”方式：STM32 的 I2C 片上外设专门负责实现 I2C 通讯协议

1. 时钟控制逻辑

SCL 线的时钟信号，由 I2C 接口根据时钟控制寄存器 (CCR) 控制，控制的参数主要为时钟频率。

标准模式：
Thigh=CCR*TPCKL1 Tlow = CCR*TPCLK1

快速模式中 Tlow/Thigh=2 时：
Thigh = CCR*TPCKL1 Tlow = 2*CCR*TPCKL1

#### 数据控制逻辑

#### I2C 初始化结构体详解
```c
typedef struct {
uint32_t ClockSpeed; /*!< 设置 SCL 时钟频率，此值要低于 40 0000*/
uint32_t DutyCycle; /* 指定时钟占空比，可选 low/high = 2:1 及 16:9 模式 */
uint32_t OwnAddress1; /* 指定自身的 I2C 设备地址 1，可以是 7-bit 或者 10-
,→bit*/
uint32_t AddressingMode; /* 指定地址的长度模式，可以是 7bit 模式或者 10bit 模
式 */
uint32_t DualAddressMode; /* 设置双地址模式 */
uint32_t OwnAddress2; /* 指定自身的 I2C 设备地址 2，只能是 7-bit */
uint32_t GeneralCallMode; /* 指定广播呼叫模式 */
uint32_t NoStretchMode; /* 指定禁止时钟延长模式 */
} I2C_InitTypeDef;
```
