# `exec` 函数族

## 函数原型

```c
#include <unistd.h>
extern char **environ;
 
int execl(const char *path, const char *arg, ...);//常用
int execlp(const char *file, const char *arg, ...);//常用
int execle(const char *path, const char *arg,..., char * const envp[]);
int execv(const char *path, char *const argv[]);//常用
int execvp(const char *file, char *const argv[]);//常用
int execvpe(const char *file, char *const argv[],char *const envp[]);
```

## 返回值

exec函数族的函数执行成功后不会返回，调用失败时，**会设置errno并返回-1**，然后从原程序的调用点接着往下执行。

## 特点

当进程调用exec函数时，该进程被完全替换为新程序。因为调用exec函数并不创建新进程，所以前后进程的ID并没有改变。

### 参数说明

- `path`	可执行文件的路径名字
- `arg`	可执行程序所带的参数，第一个参数为可执行文件名字，没有带路径且arg必须以NULL结束
- `file`	如果参数file中包含/，则就将其视为路径名，否则就按 PATH环境变量，在它所指定的各目录中搜寻可执行文件



| **l** | **使用参数列表**                                             |
| ----- | ------------------------------------------------------------ |
| **p** | **使用文件名，并从PATH环境进行寻找可执行文件**               |
| **v** | **先构造一个指向各参数的指针数组，然后将该数组的地址作为这些函数的参数** |
| **e** | **多了envp[]数组，使用新的环境变量代替调用进程的环境变量**   |