# ffmpeg推流并分发视频流

安装摄像头工具：

```shell
sudo apt-get update
sudo apt-get install v4l-utils
```

## 1.0  `v4l2` 使用

```shell
v4l2-ctl --list-devices                    #列出所有摄像头设备
v4l2-ctl -L -d /dev/video1                 #命令来列出摄像头设备的详细信息
v4l2-ctl --list-formats-ext -d /dev/video1 #查看摄像头支持的像素格式和分辨率
```







## 2.0 FFmpeg

### 2.1 `CMakeLists.txt`

参考：

```cmake
cmake_minimum_required(VERSION 3.27)
project(VideoTest)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(cmake_minimum_required 11)

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O0 -Wall -g")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wl,-z,stack-size=1024000000")
#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
#set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -g")


set(CMAKE_CXX_COMPILER "g++")

set(INCLUDE_DIR "inc")
set(SRC_DIR "src/*.cpp")
set(FFMPEG_LIBS_DIR /usr/lib/x86_64-linux-gnu)
set(FFMPEG_HEADERS_DIR /usr/include/x86_64-linux-gnu)

# for opencv
find_package(OpenCV 4.9.0 REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(ffmpeg REQUIRED IMPORTED_TARGET libavcodec libavformat libavutil)
message("OpenCV version: ${OpenCV_VERSION}")

include_directories(${OpenCV_INCLUDE_DIRS} ${INCLUDE_DIR} ${FFMPEG_HEADERS_DIR})
file(GLOB_RECURSE SRC_FILES ${SRC_DIR})
link_directories(${OpenCV_LIB_DIR} ${FFMPEG_LIBS_DIR})

add_executable(${PROJECT_NAME} main.cpp ${SRC_FILES})
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS} PkgConfig::ffmpeg)

```

> - 有些CMake作为项目构建工具时，有一些库并没有提供cmake文件，往往提供的是`pkg-config`的`.pc`文件，虽然可以在`cmake`中用`include_directories`和`link_directories`来手动指定查找目录，但是这样写并不能保证跨平台，甚至同一个库在不同Linux发行版中的位置也不一样，这个时候最好的解决方法就是能够在 cmake 中（优雅地）使用pkg-config提供的信息。
>   拿FFmpeg举例，这是一个纯C库，并且没有提供cmake配置文件，接下来我们要在 cmake 项目中使用 ffmpeg；
>
> ```
> pkg-config --list-all | grep libav
> libavformat                 libavformat - FFmpeg container format library
> libavcodec                  libavcodec - FFmpeg codec library
> libavfilter                 libavfilter - FFmpeg audio/video filtering library
> libavdevice                 libavdevice - FFmpeg device handling library
> libavresample               libavresample - Libav audio resampling library
> libavutil                   libavutil - FFmpeg utility library
> ```
>
> ```cmake
> find_package(PkgConfig REQUIRED)
> 
> pkg_check_modules(ffmpeg REQUIRED IMPORTED_TARGET libavcodec libavformat libavutil)
> 
> target_link_libraries(${PROJECT_NAME} PRIVATE PkgConfig::ffmpeg)
> ```
>
> 