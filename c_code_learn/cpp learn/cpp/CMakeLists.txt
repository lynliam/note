cmake_minimum_required (VERSION 3.24.2)#规定cmake的最低版本要求
project(Cmake_test)#项目的名称，不一定和你的文件夹名称一样
set(CMAKE_CXX_COMPILER "g++")#设置c++编译器
 
include_directories(${PROJECT_SOURCE_DIR}/include)#添加头文件的搜索路径
aux_source_directory(./src SrcFiles)#将源文件列表写在变量SrcFiles中
aux_source_directory(./src/test SrcFiles)#工程项目较大，要创建多个模块
set(EXECUTABLE_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/build)#设置可执行文件输出路径
add_executable(main ${SrcFiles})#设置可执行文件的名称，make之后bin目录下出现main.exe
