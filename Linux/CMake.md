# CMAKE
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

  * 非目标文件的程序安装

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

  

​		
