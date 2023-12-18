# 临界段保护

## Cortex-M 内核快速关闭中断

### `CPS`指令（Arm汇编指令）

```assembly
CPSID I ;PRIMASK=1;       关中断
CPSIE I ;PRIMASK=0;       开中断
CPSID F ;FAULTMASK=1；    关异常
CPSIE F ;FAULTMASK=0；    开异常
```

操作寄存器实现

| 寄存器      | 功能描述                                                  |
| ----------- | --------------------------------------------------------- |
| `PRIMASK`   | 置为1的时候，关闭所有可屏蔽中断，只留下NMI和FAULT可以响应 |
| `FAULTMASK` | 置为1的时候，只有NMI可以响应                              |
| `BASEPRI`   | 定义被屏蔽的优先级的阈值，优先级大于设定值的中断都被关闭  |



```c
#define portDISABLE_INTERRUPTS()				vPortRaiseBASEPRI()
//不带返回值的关中断函数不能嵌套，不能在中断中实现
portFORCE_INLINE static void vPortRaiseBASEPRI( void )
{
uint32_t ulNewBASEPRI;

	__asm volatile
	(
		"	mov %0, %1												\n"	\
		"	msr basepri, %0											\n" \
		"	isb														\n" \
		"	dsb														\n" \
		:"=r" (ulNewBASEPRI) : "i" ( configMAX_SYSCALL_INTERRUPT_PRIORITY )
	);
}
```



```c
#define portSET_INTERRUPT_MASK_FROM_ISR()		ulPortRaiseBASEPRI()
//带返回值的关中断函数能嵌套，能在中断中实现
portFORCE_INLINE static uint32_t ulPortRaiseBASEPRI( void )
{
uint32_t ulOriginalBASEPRI, ulNewBASEPRI;

	__asm volatile
	(
		"	mrs %0, basepri											\n" \
		"	mov %1, %2												\n"	\
		"	msr basepri, %1											\n" \
		"	isb														\n" \
		"	dsb														\n" \
		:"=r" (ulOriginalBASEPRI), "=r" (ulNewBASEPRI) : "i" ( configMAX_SYSCALL_INTERRUPT_PRIORITY )
	);

	/* This return will not be reached but is necessary to prevent compiler
	warnings. */
	return ulOriginalBASEPRI;
}
```



```c
#define portCLEAR_INTERRUPT_MASK_FROM_ISR(x)	vPortSetBASEPRI(x)
#define portENABLE_INTERRUPTS()					vPortSetBASEPRI(0)
portFORCE_INLINE static void vPortSetBASEPRI( uint32_t ulNewMaskValue )
{
	__asm volatile
	(
		"	msr basepri, %0	" :: "r" ( ulNewMaskValue )
	);
}
```



## 进入/退出临界段的宏

```c
#define portENTER_CRITICAL()					vPortEnterCritical()
#define portEXIT_CRITICAL()						vPortExitCritical()
```

```c
#define taskENTER_CRITICAL()		portENTER_CRITICAL()
```



```c

void vPortEnterCritical( void )
{
	portDISABLE_INTERRUPTS();
	uxCriticalNesting++;

	/* This is not the interrupt safe version of the enter critical function so
	assert() if it is being called from an interrupt context.  Only API
	functions that end in "FromISR" can be used in an interrupt.  Only assert if
	the critical nesting count is 1 to protect against recursive calls if the
	assert function also uses a critical section. */
	if( uxCriticalNesting == 1 )
	{
		configASSERT( ( portNVIC_INT_CTRL_REG & portVECTACTIVE_MASK ) == 0 );
	}
}
/*-----------------------------------------------------------*/

void vPortExitCritical( void )
{
	configASSERT( uxCriticalNesting );
	uxCriticalNesting--;
	if( uxCriticalNesting == 0 )
	{
		portENABLE_INTERRUPTS();
	}
}
```

