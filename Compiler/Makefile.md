 

# Makefile



学习自书[《跟着我学makefile》](https://github.com/seisman/how-to-write-makefile)

参考：

https://github.com/loverszhaokai/GNUMakeManual_CN/blob/master/GNU_Make_Manual_CN.pdf

[Makefile模板](https://github.com/TheNetAdmin/Makefile-Templates/blob/master/Readme-cn.md)

## Chapter One

## 前置知识：

# ![image-20230916233448971](Makefile.assets/image-20230916233448971.png) 

## Chapter Two

`make` 命令执行的时候，需要一个`makefile`文件去告诉 make 怎么去编译和链接程序。

### 2.1    `makefile`规则

```makefile
target ...   : prerequsities ...
	recipe
	...
```

> **`target`**:
>
> ​	目标文件 or 可执行文件 or label
>
> **`prerequisities`**：
>
> ​	生成 `target`  所需要的依赖文件
>
> **` recipe` **：
>
> ​	该 ` target` 要执行的命令

### 2.2    ` make`   逻辑

1. make 会在当前目录下找名字叫“Makefile”或“makefile”的文件。 
2.  如果找到，它会找文件中的第一个目标文件（target），在上面的例子中，他会找到“edit”这个文 件，并把这个文件作为最终的目标文件。 
3.  如果 edit 文件不存在，或是 edit 所依赖的后面的 .o 文件的文件修改时间要比 edit 这个文件新， 那么，他就会执行后面所定义的命令来生成 edit 这个文件。 
4.  如果 edit 所依赖的 .o 文件也不存在，那么 make 会在当前文件中找目标为 .o 文件的依赖性，如 果找到则再根据那一个规则生成 .o 文件。（这有点像一个堆栈的过程） 
5.  当然，你的 C 文件和头文件是存在的啦，于是 make 会生成 .o 文件，然后再用 .o 文件生成 make 的终极任务，也就是可执行文件 edit 了。



### 2.3     `makefile` 中使用变量

``` makefile
#定义变量
OBJ = main.o cmd.o \
	insert.o
	
#使用变量
edit:$(OBJ)
	cc -o edit $(OBJ)
```



### 2.4     让 `make`自动推导

`make` 可以自动推导文件和文件依赖关系后面的命令。 解释：`  make` 会找寻与生成目标（.o） 文件名相同的` .c`文件。

故：

之前的版本：

``` makefile
objects = main.o kbd.o command.o display.o \
	insert.o search.o files.o utils.o

edit : $(objects)
	cc -o edit $(objects)
main.o : main.c defs.h
	cc -c main.c
kbd.o : kbd.c defs.h command.h
	cc -c kbd.c
command.o : command.c defs.h command.h
	cc -c command.c
display.o : display.c defs.h buffer.h
	cc -c display.c
insert.o : insert.c defs.h buffer.h
	cc -c insert.c
search.o : search.c defs.h buffer.h
	cc -c search.c
files.o : files.c defs.h buffer.h command.h
	cc -c files.c
utils.o : utils.c defs.h
	cc -c utils.c
clean :
	rm edit $(objects)

```



``` makefile
objects = main.o kbd.o command.o display.o \
	insert.o search.o files.o utils.o

edit : $(objects)
	cc -o edit $(objects)

main.o : defs.h
kbd.o : defs.h command.h
command.o : defs.h command.h
display.o : defs.h buffer.h
insert.o : defs.h buffer.h
search.o : defs.h buffer.h
files.o : defs.h buffer.h command.h
utils.o : defs.h

.PHONY : clean
clean :
	rm edit $(objects)
```

（最后三行 表示clean是一个 ***伪目标***）

### 2.5    `makefile` 另一种风格

``` makefile
objects = main.o kbd.o command.o display.o \
	insert.o search.o files.o utils.o

edit : $(objects)
	cc -o edit $(objects)

$(objects) : defs.h
kbd.o command.o files.o : command.h
display.o insert.o search.o files.o : buffer.h

.PHONY : clean
clean :
	rm edit $(objects)

```



### 2.6        清空目录规则

``` makefile
.PHONY : clean
clean :
	-rm edit $(objects)
```

在 rm 前面的 减号 意思是 ***如果某些文件出现问题，但不要管，继续做后面的事情***



### 2.7        Makefile 里有什么

`Makefile` 里主要包含了五个东西：显式规则、隐式规则、变量定义、指令和注释。



### 2.8       Makefile文件名

文件名 最好为  `Makefile`



### 2.10         包含其他`Makefile`  

```makefile
include <filename>
```

include ... 可以是当前操作系统 Shell 的文件模式（可以包含路径和通配符）。

```makefile
include foo.make *.mk $(bar)
#等价于
include foo.make a.mk b.mk c.mk bish bash
```

 make寻找  文件 的顺序：

1. 当前目录下
2. `-I  or  --include-dir`  参数指定的目录
3. `<prefix>/include    /usr/gnu/inlcude    /usr/local/include    /usr/include` 

环境变量 .INCLUDE_DIRS 包含当前 make 会寻找的目录列表。

***你应当避免使用命令行参数 -I 来寻 找以上这些默认目录，否则会使得 make “忘掉”所有已经设定的包含目录，包括默认目录。*** 

​	如果有文件没有找到的话，make 会生成一条警告信息，但不会马上出现致命错误。它会继续载入其 它的文件，一旦完成 makefile 的读取，make 会再重试这些没有找到，或是不能读取的文件，如果还是不 行，make 才会出现一条致命信息。

​	如果你想让 make 不理那些无法读取的文件，而继续执行，你可以在 include 前加一个减号“-”。如： 

```makefile
-include <filename>
```

 其表示，无论 include 过程中出现什么错误，都不要报错继续执行。如果要和其它版本 make 兼容， 可以使用 `sinclude` 代替 `-include` 。



### 2.11       环境变量  `MAKEFILES` 

***不建议使用这个环境变量***

这个环境变量中引入的Makefile目标不会起作用。



### 2.12       `make`  的工作方式

GNU 的 make 工作时的执行步骤如下：（想来其它的 make 也是类似） 



----------------------------------

1. 读入所有的 Makefile。 
2.  读入被 include 的其它 Makefile。 
3.  初始化文件中的变量。 
4.  推导隐式规则，并分析所有规则。 
5.  为所有的目标文件创建依赖关系链。 

--------------------

6. 根据依赖关系，决定哪些目标要重新生成。  
7. 执行生成命令。

第一阶段（1-5），如果定义的变量被使用了，但是 make  不会马上展开
