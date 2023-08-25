# CMAKE

## Introduction

* example
	```cmake
	PROJECT(HELLO)                      
	#指定工程名称，并可以指定语言， 隐式定义了两个CMAKE变量：＜projectname>_BINARY_DIR ＜projectname>_SOURCE_DIR
	SET(SRC_LIST main.c)                //显式定义变量
	MESSAGE(STATUS "sss" ${HELLO_BINARY_DIR})   
	MESSAGE(STATUS "sss" ${HELLO_SOURCE_DIR})
	ADD_EXECUTABLE(hello ${SRC_LIST})    //生成一个文件名为hello的可执行文件
	```
	
* 清理工具
  * make clean    即可对构建结果进行清理
  
* 构建方式
  * 内部构建
    * 内部构建，也就是在CMakeLists.txt同一级目录进行编译。
  * 外部构建
    * 外部构建，与CMakeLists.txt不同级进行构建。

```cmake
ADD_SUBDIRECTORY(src bin)
ADD_SUBDIRECTORY(source_dir [binary_dir] [EXCLUDE_FRoM_ALL])
#该指令用于向当前工程中添加存放源文件的子目录，并指定中间二进制和目标二进制存放位置
#EXCLUDE_FROM_ALL命令含义为将这个目录从构建中排除
SUBDIRS(dir1,dir2...)
#上面的指令可以一次添加多个子目录，并且即使外部编译，子目录系统仍然会被保留
```

* 换个地方保存二进制

  ```cmake
  SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
  SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
  #在哪里写入这两条指令？原则：在哪里ADD_EXECUTABLE或ADD_LIBRARY,如果需要改变目标存放路径就在哪里加入上述定义
  ```

  

* 安装

  * 目标文件安装

  ```cmake
  INSTALL(TARGETS targets...
  [[ARCHIVE|LIBRARY|RUNTIME]
  [DESTINATION <dir>]
  [PERMISSIONS permissions...]
  [CONFIGURATIONS
  [Debug|Release|...]]
  [COMPONENT <component>]
  [OPTIONAL]
  ] [...])
  ```

  * 普通文件安装

  ```cmake
  INSTALL(FILES files... DESTINATION <dir>
  [PERMISSIONS permissions...]
  [CONFIGURATIONS [Debug|Release|...]]
  [COMPONENT <component>]
  [RENAME <name>] [OPTIONAL])
  ```

  * 非目标文件的可执行程序安装（脚本）

  ```cmake
  INSTALL(PROGRAMS files... DESTINATION <dir>
  [PERMISSIONS permissions...]
  [CONFIGURATIONS [Debug|Release|...]]
  [COMPONENT <component>]
  [RENAME <name>] [OPTIONAL])
  ```

  * 目录的安装

  ```cmake
  INSTALL(DIRECTORY dirs... DESTINATION <dir>
  [FILE_PERMISSIONS permissions...]
  [DIRECTORY_PERMISSIONS permissions...]
  [USE_SOURCE_PERMISSIONS]
  [CONFIGURATIONS [Debug|Release|...]]
  [COMPONENT <component>]
  [[PATTERN <pattern> | REGEX <regex>]
  [EXCLUDE] [PERMISSIONS permissions...]] [...])
  ```

  > DIRECTORY后面连接的是所在Source目录的相对路径，但务必注意：
  > abc和abc/有很大的区别。
  > 如果目录名不以/结尾，那么这个目录将被安装为目标路径下的abc，如果目录名以/结尾，
  > 代表将这个目录中的内容安装到目标路径，但不包括这个目录本身。

  

  ## 库
  
  ```cmake
  ADD_LIBRARY(libname [SHARED|STATIC|MODULE]
  [EXCLUDE_FROM_ALL]
  source1 source2 ... sourceN)
  
  #EXCLUDE_FROM_ALL参数的意思是这个库不会被默认构建，除非有其他的组件依赖或者手工构建。
  ```
  
  类型有三种:
  SHARED，动态库
  STATIC，静态库
  MODULE，在使用dyld的系统有效，如果不支持dyld，则被当作SHARED对待。
  
  * 设置属性
  
  ```cmake
  SET_TARGET_PROPERTIES，其基本语法是：
  SET_TARGET_PROPERTIES(target1 target2 ...
  PROPERTIES prop1 value1
  prop2 value2 ...)
  
  与他对应的指令是：
  GET_TARGET_PROPERTY(VAR target property)
  具体用法如下例，我们向lib/CMakeListst.txt中添加：
  GET_TARGET_PROPERTY(OUTPUT_VALUE hello_static OUTPUT_NAME)
  MESSAGE(STATUS “This is the hello_static
  OUTPUT_NAME:”${OUTPUT_VALUE})
  ```
  
  ```cmake
  #设置输出库的名字为 ： “hello”
  SET_TARGET_PROPERTIES(hello_static PROPERTIES OUTPUT_NAME "hello")
  ```
  
  ```cmake
  #设置阻止构建target时，清除其他使用相同名字的应用。
  SET_TARGET_PROPERTIES(hello PROPERTIES CLEAN_DIRECT_OUTPUT 1)
  SET_TARGET_PROPERTIES(hello_static PROPERTIES CLEAN_DIRECT_OUTPUT 1）
  ```
  
  五，动态库版本：
  
  ```cmake
  #VERSION 代指动态库版本，SOVERSION 代指api版本
  SET_TARGET_PROPERTIES(hello PROPERTIES VERSION 1.2 SOVERSION 1
  ```
  
  
  
  
  
  
  
  ### 六，安装共享库和头文件
  
  以上面的例子，我们需要将libhello.a, libhello.so.x以及hello.h安装到系统目
  录，才能真正让其他人开发使用，在本例中我们将hello的共享库安装到<prefix>/lib
  目录，将hello.h安装到<prefix>/include/hello目录。
  利用上一节了解到的INSTALL指令，我们向lib/CMakeLists.txt中添加如下指令：
  
  ```cmake
  INSTALL(TARGETS hello hello_static
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib)
  INSTALL(FILES hello.h DESTINATION include/hello)
  ```
  
  注意，静态库要使用ARCHIVE关键字
  通过:
  cmake -DCMAKE_INSTALL_PREFIX=/usr ..
  make
  make install
  我们就可以将头文件和共享库安装到系统目录/usr/local/lib和/usr/include/hello中了。
  
  > There are two ways to use this variable:
  >
  > passing it as a command line argument just like Job mentioned:
  >
  > ```cmake
  > cmake -DCMAKE_INSTALL_PREFIX=< install_path > ..
  > ```
  >
  > assigning value to it in CMakeLists.txt:
  >
  > ```cmake
  > SET(CMAKE_INSTALL_PREFIX < install_path >)
  > ```
  >
  > But do remember to place it ==BEFORE PROJECT==(< project_name>) command, otherwise it will ==not work==!
  
  
  
  ![image-20230328200834237](/media/lynliam/data/markdown/Linux/CMake.assets/image-20230328200834237.png)
  
  * 引入头文件搜索路径:
  
  ```cmake
  INCLUDE_DIRECTORIES([AFTER|BEFORE] [SYSTEM] dir1 dir2 ...)
  ```
  
  这条指令可以用来向工程添加多个特定的头文件搜索路径，路径之间用空格分割，如果路径
  中包含了空格，可以使用双引号将它括起来，默认的行为是追加到当前的头文件搜索路径的
  后面，你可以通过两种方式来进行控制搜索路径添加的方式：
  １，CMAKE_INCLUDE_DIRECTORIES_BEFORE，通过SET这个cmake变量为on，可以
  将添加的头文件搜索路径放在已有路径的前面。
  ２，通过AFTER或者BEFORE参数，也可以控制是追加还是置前
  
  
  
  * 为target添加共享库
  
  ```cmake
  #这个指令非常简单，添加非标准的共享库搜索路径，比如，在工程内部同时存在共享库和可
  #执行二进制，在编译时就需要指定一下这些共享库的路径
  LINK_DIRECTORIES(directory1 directory2 ...)
  
  #TARGET_LINK_LIBRARIES的全部语法是:
  #这个指令可以用来为target添加需要链接的共享库，本例中是一个可执行文件，但是同样
  #可以用于为自己编写的共享库添加共享库链接。
  TARGET_LINK_LIBRARIES(target library1
  <debug | optimized> library2
  ...)
  ```
  
  七，特殊的环境变量 ```CMAKE_INCLUDE_PATH``` 和 ```CMAKE_LIBRARY_PATH```

这两个是**环境变量**而不是 cmake 变量。 使用方法是要在 bash 中用 export 或者在 csh 中使用 set 命令设置或者 CMAKE_INCLUDE_PATH=/home/include cmake ..等方式。



## 常用变量：

```cmake
#这三个变量指代的内容是一致的，如果是 in source 编译，指得就是工程顶层目录，如果是 out-of-source 编译，指的是工程编译发生的目录。
CMAKE_BINARY_DIR
PROJECT_BINARY_DIR
<projectname>_BINARY_DIR

#这三个变量指代的内容是一致的，不论采用何种编译方式，都是工程顶层目录。也就是在 in source 编译时，他跟 CMAKE_BINARY_DIR 等变量一致
CMAKE_SOURCE_DIR
PROJECT_SOURCE_DIR
<projectname>_SOURCE_DIR

#指的是当前处理的 CMakeLists.txt 所在的路径，比如上面我们提到的 src 子目录
CMAKE_CURRENT_SOURCE_DIR

#如果是 in-source 编译，它跟 CMAKE_CURRENT_SOURCE_DIR 一致，如果是 out-of-source 编译，他指的是 target 编译目录。
#使用我们上面提到的 ADD_SUBDIRECTORY(src bin)可以更改这个变量的值。
#使用 SET(EXECUTABLE_OUTPUT_PATH <新路径>)并不会对这个变量造成影响，它仅仅修改了最终目标文件存放的路径。
CMAKE_CURRENNT_BINARY_DIR

#返回通过 PROJECT 指令定义的项目名称
PROJECT_NAME

#重新定义最终的存放目录
EXECUTABLE_OUTPUT_PATH
LIBRARY_OUTPUT_PATH

#这个变量用来定义自己的 cmake 模块所在的路径。如果你的工程比较复杂，有可能会自己编写一些 cmake 模块，这些 cmake 模块是随你的工程发布的，为了让 cmake 在处理CMakeLists.txt 时找到这些模块，你需要通过 SET 指令，将自己的 cmake 模块路径设置一下。
#比如SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
#这时候你就可以通过 INCLUDE 指令来调用自己的模块了
CMAKE_MODULE_PATH

#分别用来重新定义最终结果的存放目录，前面我们已经提到了这两个变量。
EXECUTABLE_OUTPUT_PATH 和 LIBRARY_OUTPUT_PATH
```

















