 

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



## Chapter Three

### 书写规则

规则包含两个部分，一个是**依赖关系**，一个是**生成目标的方法**。

### 3.1     规则举例

```makefile
foo.o: foo.c def.h
	cc -c -g foo.c
```

### 3.2      规则的语法

```makefile
targets: prerequisities
	command
	...
	
# or
targets: prerequisities : command
	command
	...
```

* targets   可以是多个文件，或通配符。
* command 是命令行，如果其不与“target:prerequisites”在一行，那么，**必须以 Tab 键开头**，如果 和 prerequisites 在一行，那么可以用分号做为分隔。（见上）
* 反斜杠可以换行。



### 3.3    在规则中使用通配符

三个通配符：  *  ？ ~

举例：

在变量中的通配符

```makefile
obj = *.o
obj := $(wildcard *.c)                        #列出一确定文件夹中所有的.c文件
$(patsubst %.c,%.o,$(wildcard *.c))			  #列出上面命令中所有对应的.o文件
```

```makefile
objects := $(patsubst %.c,%.o,$(wildcard *.c))
foo : $(objects)
	cc -o foo $(objects)
```



### 3.4     文件搜寻

指定目录搜索，当`make`在当前目录下面找不到，则会去指定目录找，**`VPATH`** 为完成此功能的变量.

```makefile
VPATH = src:../headers
```



**`vapth`** 变量更加灵活：

```makefile
vpath <pattern> <directories>         #为符合模式 <pattern> 的文件指定搜索目录 <directories>

vpath <pattern>                       #清除符合模式 <pattern> 的文件的搜索目录。

vpath                                 #清除所有已被设置好了的文件搜索目录。

#<pattern> 中需要包含 % 字符，% 意思是匹配零或若干字符
```

举例：

```makefile
vpath %.h ../headers
```



### 3.5     伪目标

使用  `.PHONY`   来显式指明该目标为伪目标，这样就可以防止与文件名重名带来的不良后果。

```makefile
.PHONY : clean
clean :
	rm *.o temp
```



情况（有依赖的伪目标，并作为默认目标）:

```makefile
all : prog1 prog2 prog3
.PHONY : all

prog1 : prog1.o utils.o
	cc -o prog1 prog1.o utils.o
prog2 : prog2.o
	cc -o prog2 prog2.o
prog3 : prog3.o sort.o utils.o
	cc -o prog3 prog3.o sort.o utils.o
```

这样就可以 一口气生成若干个可执行文件。

> 原理：
>
> 我们知道，Makefile 中的第一个目标会被作为其默认目标。我们声明了一个“all”的伪目标，其依赖 于其它三个目标。
>
> 由于默认目标的特性是，总是被执行的，但由于“all”又是一个伪目标，伪目标只是一 个标签不会生成文件，所以不会有“all”文件产生。于是，其它三个目标的规则总是会被决议。也就达到 了我们一口气生成多个目标的目的。
>
> `.PHONY : all `声明了“all”这个目标为“伪目标”。（注：这里的显 式“`.PHONY : all`”不写的话一般情况也可以正确的执行，这样 make 可通过隐式规则推导出，“all”是 一个伪目标，执行 make 不会生成“all”文件，而执行后面的多个目标。建议：显式写出是一个好习惯。



情况（作为依赖的伪目标）：

```makefile
.PHONY : cleanall cleanobj cleandiff
cleanall : cleanobj cleandiff
	rm program
cleanobj :
	rm *.o
cleandiff :
	rm *.diff
```



### 3.6     多目标

目标可以不止一个。(自动化变量  $@ ,后文会学 )

```makefile
bigoutput littleoutput : text.g
	generate text.g -$(subst output,,$@) > $@
```

等价：

```makefile
bigout : text.g
	generate text.g -big > bigoutput
littleoutput : text.g
	generate text.g -little > littleoutput
```



### 3.7       静态模式

静态模式可以更加容易地定义多目标规则。

```makefile
<targets ...> : <target-pattern> : <prereq-patterns ...>
	<commands>
	...
```

**`<target-pattern>` ** 表示从  **`<targets ...>`**   中选出具有这样的 pattern 的组成一个集合。

直接看例子：

```makefile
objects:foo.c bar.o

all: $(objects)

$(objects): %.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@
```

**`%.o `**   表示     **`$(objects)`**   要所有以 .o 结尾的目标

**`%.c`**   表示      依赖模式 **`%.c`** 则取模式 **`%.o`** 的  **`%.`** ，也就是 foo bar ，并为其加下 .c 的后缀，于是，我们的依赖目标就是 foo.c bar.c

等价于

```makefile
oo.o : foo.c
$(CC) -c $(CFLAGS) foo.c -o foo.o
bar.o : bar.c
$(CC) -c $(CFLAGS) bar.c -o bar.o
```



```makefile
files = foo.elc bar.o lose.o
$(filter %.o,$(files)): %.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@
$(filter %.elc,$(files)): %.elc: %.el
	emacs -f batch-byte-compile $<
```

**$(filter %.o,$(files)) **表示调用 `Makefile` 的 filter 函数，过滤“$files”集，只要其中模式为“%.o”的 内容。



### 3.8        自动生成依赖

使用 `-M`  指令自动生成依赖关系；使用 `-MM`  指令自动生成依赖并防止将一些标准库文件也包含进来。

GNU组织建议议把编译器为每一个源文件的自动生成的依赖关系放到一个 文件中，为每一个 name.c 的文件都生成一个 name.d 的 Makefile 文件，.d 文件中就存放对应 .c 文件 的依赖关系。

举例：

```makefile
%.d: %.c
	@set -e; rm -f $@; \
	$(CC) -M $(CPPFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$
```

这句命令可以 将 变量 source中的字符串 **.c** 都替换成 **.d**

```makefile
include $(sources:.c=.d)
```



## Chapter Four

### 书写命令

每个命令的开头都必须以  Tab  键开头，除非命令紧跟在规则后面的分号后的。

### 4.1      显示命令

```makefile
@echo   xxxxx
```

输出：

```makefile
xxx
```

如果没加 @  那么，make将会输出命令那一串字符：

```makefile
echo xxx
xxx
```



```makefile
make -n 
# or
make --just-print

#上面的命令只会显示命令，而不会执行命令。

make -s 
#  or
make --silent 
#  or
make --quiet

#上面的命令全面禁止命令显示
```





### 4.2      命令执行

make   会一条一条执行后面的命令，而如果你想要将结果应用于下一条命令，应该用分号：

```makefile
exec:
	cd /home/lyn; pwd
```



### 4.3      命令出错

为了忽略命令报错，可以在命令行之间 Tab之后加上 ` - `

```makefile
clean:
	-rm -f *.o
```

