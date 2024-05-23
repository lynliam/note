# Clang++ 无法找到 ioscream



使用命令：clang++ -c demo1.cpp -v

```shell
Ubuntu clang version 14.0.0-1ubuntu1.1
Target: x86_64-pc-linux-gnu
Thread model: posix
InstalledDir: /usr/bin
Found candidate GCC installation: /usr/bin/../lib/gcc/x86_64-linux-gnu/11
Found candidate GCC installation: /usr/bin/../lib/gcc/x86_64-linux-gnu/12
Selected GCC installation: /usr/bin/../lib/gcc/x86_64-linux-gnu/12
Candidate multilib: .;@m64
Selected multilib: .;@m64
 (in-process)
 "/usr/lib/llvm-14/bin/clang" -cc1 -triple x86_64-pc-linux-gnu -emit-obj -mrelax-all --mrelax-relocations -disable-free
-clear-ast-before-backend -disable-llvm-verifier -discard-value-names -main-file-name demo1.cpp -mrelocation-model pic -
pic-level 2 -pic-is-pie -mframe-pointer=all -fmath-errno -ffp-contract=on -fno-rounding-math -mconstructor-aliases -funw
ind-tables=2 -target-cpu x86-64 -tune-cpu generic -mllvm -treat-scalable-fixed-error-as-warning -debugger-tuning=gdb -v
-fcoverage-compilation-dir=/home/lyn/Code_Workspace/cmake-demo/demo1 -resource-dir /usr/lib/llvm-14/lib/clang/14.0.0 -in
ternal-isystem /usr/bin/../lib/gcc/x86_64-linux-gnu/12/../../../../include/c++ -internal-isystem /usr/bin/../lib/gcc/x86
_64-linux-gnu/12/../../../../include/c++/x86_64-linux-gnu -internal-isystem /usr/bin/../lib/gcc/x86_64-linux-gnu/12/../.
./../../include/c++/backward -internal-isystem /usr/lib/llvm-14/lib/clang/14.0.0/include -internal-isystem /usr/local/in
clude -internal-isystem /usr/bin/../lib/gcc/x86_64-linux-gnu/12/../../../../x86_64-linux-gnu/include -internal-externc-i
system /usr/include/x86_64-linux-gnu -internal-externc-isystem /include -internal-externc-isystem /usr/include -fdepreca
ted-macro -fdebug-compilation-dir=/home/lyn/Code_Workspace/cmake-demo/demo1 -ferror-limit 19 -fgnuc-version=4.2.1 -fcxx-
exceptions -fexceptions -fcolor-diagnostics -faddrsig -D__GCC_HAVE_DWARF2_CFI_ASM=1 -o demo1.o -x c++ demo1.cpp
clang -cc1 version 14.0.0 based upon LLVM 14.0.0 default target x86_64-pc-linux-gnu
ignoring nonexistent directory "/usr/bin/../lib/gcc/x86_64-linux-gnu/12/../../../../include/c++/x86_64-linux-gnu"
ignoring nonexistent directory "/usr/bin/../lib/gcc/x86_64-linux-gnu/12/../../../../include/c++/backward"
ignoring nonexistent directory "/usr/bin/../lib/gcc/x86_64-linux-gnu/12/../../../../x86_64-linux-gnu/include"
ignoring nonexistent directory "/include"
#include "..." search starts here:
#include <...> search starts here:
 /usr/bin/../lib/gcc/x86_64-linux-gnu/12/../../../../include/c++
 /usr/lib/llvm-14/lib/clang/14.0.0/include
 /usr/local/include
 /usr/include/x86_64-linux-gnu
 /usr/include
End of search list.
demo1.cpp:1:10: fatal error: 'iostream' file not found
#include <iostream>
         ^~~~~~~~~~
1 error generated.
```

原因是搜索目录不包含：

```c
/usr/include/c++/11
```

### 方案一

将下面c++版本数字改为你自己的版本数字(可通过`ls /usr/include/c++/`查看)

```bash
clang++ -I /usr/include/c++/11 -I /usr/include/x86_64-linux-gnu/c++/11 -c 1.cpp
```

或者在你的项目目录下新建`compile_flags.txt`文件，文件内容:

```text
-I
/usr/include/c++/11
-I
/usr/include/x86_64-linux-gnu/c++/11
```

这种方法虽然能够让编辑器不显示错误，但是自动补全补全不了头文件

### 方案二

注意看刚才的错误输出:

```text
...
Selected GCC installation: /usr/bin/../lib/gcc/x86_64-linux-gnu/12
...
```

说明`clang++` 使用gcc-12的安装目录, clang出错的原因貌似是该目录下没有包含`libstdc++.a` ，我们可以通过安装`libstdc++-12-dev`来解决问题(改成你对应的版本), 完美解决问题。

```bash
sudo apt install libstdc++-12-dev
```

### 方案三



问题：

> 为什么 clang++ 编译的时候： Found candidate GCC installation: /usr/bin/../lib/gcc/x86_64-linux-gnu/11 Found candidate GCC installation: /usr/bin/../lib/gcc/x86_64-linux-gnu/12 Selected GCC installation: /usr/bin/../lib/gcc/x86_64-linux-gnu/12   这个在干嘛

答案：

> 在使用`clang++`编译时，它可能会搜索系统中已安装的GCC（GNU Compiler Collection）版本，这是因为`clang`作为另一种C++编译器可以与GCC兼容。上述消息表明`clang++`找到了多个候选的GCC安装版本，并选择了其中一个来进行编译。
>
> 这个消息告诉你以下信息：
>
> 1. `clang++`在搜索系统中可用的GCC版本时，找到了两个候选安装位置，分别是 `/usr/bin/../lib/gcc/x86_64-linux-gnu/11` 和 `/usr/bin/../lib/gcc/x86_64-linux-gnu/12`。这些是不同的GCC版本。
> 2. 最后，`clang++`选择了 `/usr/bin/../lib/gcc/x86_64-linux-gnu/12` 作为编译所使用的GCC版本。
>
> 这是因为`clang`可以使用GCC的标准库和头文件，以确保代码在不同编译器之间的兼容性。当你使用`clang++`编译时，它会查找系统上的可用GCC版本，以便使用GCC的一些功能和库。
>
> 在此过程中，`clang++`将尝试找到与其自身兼容的GCC版本，并将其用于编译过程。在你的情况下，它选择了版本12作为兼容的GCC版本，以便与`clang`一起使用。这确保了编译器之间的协同工作，从而使你能够使用`clang++`编译代码，同时也可以利用GCC的功能。

