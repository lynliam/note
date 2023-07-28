# 安装

##  一、Windows版本安装



## 二、Ubuntu版本安装

### 一、环境包安装

```bash
#第一二三行必选
$ sudo apt-get install build-essential                     # 这是为了安装编译所需的库
$ sudo apt-get install cmake pkg-config git                # 这是为了安装一些必要的工具
$ sudo apt-get install  libgtk2.0-dev  libavcodec-dev libavformat-dev libswscale-dev 
$ sudo apt-get install python-dev python-numpy libtbb2 libtbb-dev libjpeg-dev libpng-dev libtiff-dev libjasper-dev libdc1394-22-dev

```

> 关于libjasper-dev包，不用安装

### 二、下载编译安装

```shell
cd ~/opencv-4.7.0
mkdir build
cd ./build
```

```shell
cmake -D CMAKE_INSTALL_PREFIX=/usr/local -D CMAKE_BUILD_TYPE=Release -D OPENCV_GENERATE_PKGCONFIG=ON -D   -D OPENCV_ENABLE_NONFREE=True ..
```

```c
/*
注解：

1. CMAKE_INSTALL_PREFIX 是opencv的安装地址 默认安装在 usr/local
2. CMAKE_BUILD_TYPE 是opencv安装的版本，Release和Debug两种可选，默认安装Release
3. OPENCV_ENABLE_NONFREE 是否使用部分被申请了专利的算方法 这里选True的话就可以使用了
4. OPENCV_GENERATE_PKGCONFIG 强烈建议开启这个 设置为ON OPENCV_GENERATE_PKGCONFIG 因为opencv4默认不生成.pc文件，所以加上这句用于生成opencv4.pc文件，支持pkg-config功能。opencv4版本及以上 这里用ON
*/
```

> 注：如果出现`Built target libprotobuf`的错误，将 `-D ENABLE_CXX11=1` 命令补充在cmake 指令后再来一次

```shell
sudo make -j12
sudo make install
```

### 三、环境配置

#### 1.修改etc/bash.bashrc

我们之前安装的时候 `OPENCV_GENERATE_PKGCONFIG=ON` 所以在/usr/lib/pkgconfig下生成了opencv4.pc文件，里面记录了OpenCV头文件、库文件的路經。需要进行如下配置：

```shell
#搜索opencv.pc文件目录
find / -iname opencv4.pc

#法一（未成功）：
sudo gedit /etc/bash.bashrc

#文件末尾添加以下内容 并保存
PKG_CONFIG_PATH=$PKG_CONFIG_PATH:/usr/lib/pkgconfig
export PKG_CONFIG_PATH
 
#更新
source /etc/bash.bashrc

#法二（成功）：
sudo vim /etc/profile.d/pkgconfig.sh

#文件末尾添加以下内容 并保存
export PKG_CONFIG_PATH=/usr/local/lib/pkgconfig:$PKG_CONFIG_PATH

#保存并退出后激活：
source /etc/profile

```

#### 2.修改动态库

```shell
#打开下列文件
sudo gedit /etc/ld.so.conf.d/opencv.conf 
 
# 添加lib路經 在 末尾 保存退出
/usr/lib
 
# 更新
sudo ldconfig
```

#### 3.更新

```shell
sudo updatedb
```



### 四、测试

```shell
#终端输入以下两命令，显示正常则安装成功
pkg-config --modversion opencv4 #查看版本号
pkg-config --libs opencv4 #查看libs库
```

```shell
cd ~/opencv-4.7.0/samples/cpp/example_cmake
mkdir build
cd ./build
cmake ..
make
./opencv_example ## 生成一个可执行文件 拖入终端执行 也可
```

### 五、Vscode配置

```json
{
    "tasks": [
        {
            "type": "cppbuild",
            "label": "C/C++: g++ opencv生成活动文件",
            "command": "/usr/bin/g++",
            "args": [
                "-fdiagnostics-color=always",
                "-std=c++11",
                "-static-libgcc",
                "-Wall",
                "-g",
                "${file}",
                "-o",
                "${fileDirname}/${fileBasenameNoExtension}",
                "`pkg-config --cflags --libs opencv4`"
            ],
            "options": {
                "cwd": "${workspaceFolder}"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": "build",
            "detail": "调试器生成的任务。"
        }
    ],
    "version": "2.0.0"
}
```

```json
{
    "configurations": [
        {
            "name": "Linux",
            "includePath": [
                "${workspaceFolder}/**",
                "/usr/include/opencv4"
            ],
            "defines": [],
            "compilerPath": "/usr/bin/gcc",
            "cStandard": "c17",
            "cppStandard": "gnu++17",
            "intelliSenseMode": "linux-gcc-x64"
        }
    ],
    "version": 4
}
```

```json
{
    // Use IntelliSense to learn about possible attributes.
    // Hover to view descriptions of existing attributes.
    // For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
    "version": "0.2.0",
    "configurations": [
        {
            "name": "g++ - 生成和调试活动文件",
            "preLaunchTask": "C/C++: g++ opencv生成活动文件", 
            "type": "cppdbg",
            "request": "launch",
            "program": "${fileDirname}/${fileBasenameNoExtension}",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}", 
            "environment": [],
            "externalConsole": true,
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "为 gdb 启用整齐打印",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
        }
    ]
}
```

```json
{
    "files.associations": {
        "cstdlib": "cpp",
        "ostream": "cpp"
    }
}
```



###  六、Bug解决

1. ```Gtk-Message: 14:00:08.135: Failed to load module "canberra-gtk-module"```

解决办法：

```shell
sudo apt install libcanberra-gtk-module
```



2. ```opencv 420.ddl 缺失```

解决办法：

在项目设置的调试中添加环境变量：

```PATH=D:\Program Files\opencv\source\opencv\build\x64\vc15\bin $(LocalDebuggerEnvironment)```



3. ```sudo updatedb sudo updatedb``` 的时候，显示“```sudo updatedb```找不到命令”

解决方法：

执行 `apt-get install mlocate`
 安装完成 `sudo updatedb`
