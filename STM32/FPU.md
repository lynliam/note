# STM32启用FPU浮点运算

1.  GCC 编译生成浮点指令： `-mfloat-abi=hard `` -mfpu=fpv5-d16`

```c
  /* FPU settings ------------------------------------------------------------*/
  #if (__FPU_PRESENT == 1) && (__FPU_USED == 1)
    SCB->CPACR |= ((3UL << 10*2)|(3UL << 11*2));  /* set CP10 and CP11 Full Access */
  #endif
```

2. 故设置  `(__FPU_PRESENT == 1)   (__FPU_USED == 1)`