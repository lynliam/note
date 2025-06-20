# C语言调用CPP函数

由于Cpp 函数重载机制的存在，cpp代码编译后，函数名会被改变，这在c语言中并不会，因此c语言文件直接调用cpp函数会出现 未定义函数 的报错，我们需要定义一个cpp函数接口，将其以c语言的方式暴露出来：

使用 `extern` 关键字 **告诉编译器以 C 语言的方式处理函数或变量的链接（linkage）**，这将禁止 函数名改编

定义：`c_api.h`

```c
#pragma once
#ifdef __cplusplus
extern "C"
{
#endif
#include "stm32f4xx.h"

void * Servo_Init(UART_HandleTypeDef huart);

void Servo_Write_PosEx(void * feetservo, int16_t Position, uint16_t Speed, uint8_t ACC);

uint8_t Servo_search_state(void * feetservo);

int Servo_Read_Pos(void * feetservo);
#ifdef __cplusplus
}

#endif
```

`c_api.cpp`

```cpp
#include "Servo_uart_c_api.h"
#include "Servo_uart.hpp"

#ifdef __cplusplus
extern "C"
{
#endif

void * Servo_Init(UART_HandleTypeDef huart)
{
    ServoMotor *servo = new ServoMotor(huart);   // ServoMotor 为类
    return (void *)servo;                        // 使用void 指针，因为c语言中并没有类指针
}

void Servo_Write_PosEx(void * feetservo, int16_t Position, uint16_t Speed, uint8_t ACC)
{
    ((ServoMotor*)feetservo)->WritePosEx(Position, Speed, ACC);  //使用函数指针来调用成员函数，包装了成员函数
    														     //因为c中并不支持 隐式 this 指针
}

uint8_t Servo_search_state(void * feetservo)
{
    return ((ServoMotor*)feetservo)->search_state();
}

int Servo_Read_Pos(void * feetservo)
{
    return ((ServoMotor*)feetservo)->get_current_pos();
}


#ifdef __cplusplus
}
#endif
```

