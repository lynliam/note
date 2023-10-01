# C语言   `assert()`

`assert` 头文件`assert.h`

```c
#ifdef NDEBUG
#define assert(x)	((void)0)
#else /* debugging enabled */

_CRTIMP void __cdecl __MINGW_NOTHROW _assert (const char*, const char*, int) __MINGW_ATTRIB_NORETURN;

#define assert(e)       ((e) ? (void)0 : _assert(#e, __FILE__, __LINE__))

#endif	/* NDEBUG */

```

assert()宏接受一个整形表达式参数。如果表达式的值为假，assert()宏就会调用_assert函数在标准错误流中打印一条错误信息，并调用abort()（abort()函数的原型在stdlib.h头文件中）函数终止程序。

当我们认为已经排除了程序的bug时，就可以把宏定义#define NDEBUG写在包含assert.h位置前面。

> 小知识：
>
> * __cdecl是C Declaration的缩写（declaration，声明），表示C语言默认的函数调用方法：所有参数从右到左依次入栈。
> * ___CRTIMP是C run time implement的简写，C运行库的实现的意思。作为用户代码，不应该使用这个东西。提示是使用dll的动态 C 运行时库还是静态连接的 C 运行库的一个宏。
>
> ```c
> __#ifndef _CRTIMP
> #ifdef _DLL
> #define _CRTIMP __declspec(dllimport)
> #else /* ndef _DLL */
> #define _CRTIMP
> #endif /* _DLL */
> #endif /* _CRTIMP */
> ```
>
> * `__MINGW_NOTHROW`与`__MINGW_ATTRIB_NORETURN` 是异常处理相关标识
>
> 这几个标识符在C语言标准库文件中都有用得到，但是我们不需要关心，在我们用户的角度来看，以上函数原型我们看成：void _assert(const char*, const char*, int)；即可。