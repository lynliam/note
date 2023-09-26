# typedef 详解

## 函数指针复习：

```c
//函数指针定义
int (*pf)(int, double);

//操作
pf=&fun;
(*pf)(5,8.9);
//or
pf=fun
```



## 理解：

```c
int* (*a[5])(int, char*);      //＃1
void (*b[10]) (void (*)()); //＃2
double(*)() (*pa)[9];         //＃3 
```

一一解释上面代码 的含义

* `(*a[5])`  代表一个含有五个指针元素的数组； (int, cahr*)  表示指针指向的是一个函数   ； `int*` 表示函数的返回值是 `int*`
* `(*b[10]) `   代表一个含有十个指针元素的数组；`(void (*)())` 表示指针指向的是一个函数，参数为一个函数指针  ；  `void`  表示函数的返回值是 `void`
* `(*pa)[9] `   代表一个指针，指针指向一个数组，数组有九个元素 ； `double(*)()`  表示数组的类型是一个函数指针。



## 实践：

```c
typedef int* (*PF)(int, char*);//PF是一个类型别名【注2】。 
PF a[5];//跟int* (*a[5])(int, char*);的效果一样！
```

注2：很多初学者只知道typedef char* pchar；但是对于typedef的其它用法不太了解。Stephen Blaha对typedef用法做过一个总结：“建立一个类型别名的方法很简单，在传统的变量声明表达式里用类型名替代变量名，然后把关键字 typedef加在该语句的开头”。

＃2：`void (*b[10])(void (*)());`

```c
typedef void (*pfv)(); 
typedef void (*pf_taking_pfv)(pfv);
pf_taking_pfv b[10]; //跟void (*b[10]) (void (*)());的效果一样！ 
```



＃3.` double(*)()(*pa)[9];`

```c
typedef double(*PF)();
typedef PF (*PA)[9]; 
PA pa; //跟doube(*)()(*pa)[9];的效果一样！ 
```