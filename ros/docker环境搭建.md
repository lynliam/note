# Docker版ROS2_humble



## 直接版本：

```shell
#拉取镜像
docker pull osrf/ros:humble-desktop

#开启可视化界面
xhost(参数)
//+：关闭访问控制，允许任何主机访问本地的X服务器；
//-：打开访问控制，仅允许授权清单中的主机访问本地的X服务器。

#启动镜像
sudo docker run -it -v /mnt/d/docker/humble_container_data_1:/data --group-add video --volume=/tmp/.X11-unix:/tmp/.X11-unix  --env="DISPLAY=$DISPLAY" --env="QT_X11_NO_MITSHM=1" --name=humble_ros_2 osrf/ros:humble-desktop  /bin/bash

#ROS2——bashrc
echo 'source /opt/ros/humble/setup.bash'>> ~/.bashrc
```

## dockerfile版

```shell
FROM osrf/ros:humble-desktop
RUN rm /etc/apt/sources.list
ADD sources.list /etc/apt/
RUN apt clean && apt update &&apt upgrade -y && apt-get install -y python3-pip openssh-server gdb gdbserver

# nvidia-container-runtime
ENV NVIDIA_VISIBLE_DEVICES \
${NVIDIA_VISIBLE_DEVICES:-all}

ENV NVIDIA_DRIVER_CAPABILITIES \
${NVIDIA_DRIVER_CAPABILITIES:+$NVIDIA_DRIVER_CAPABILITIES,}graphics

RUN apt-get update && \
apt-get install -y \
build-essential \
libgl1-mesa-dev \
libglew-dev \
libsdl2-dev \
libsdl2-image-dev \
libglm-dev \
libfreetype6-dev \
libglfw3-dev \
libglfw3 \
libglu1-mesa-dev \
freeglut3-dev \
vim \
minicom

RUN sudo pip install rosdepc 
RUN sudo rosdepc init && rosdepc update
USER root

RUN echo "source /opt/ros/humble/setup.bash" >> /root/.bashrc

RUN mkdir -p /root/2ROS2workspace
WORKDIR /root/2ROS2workspace
ENV LC_ALL C.UTF-8
```





