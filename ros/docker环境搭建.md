<<<<<<< Updated upstream
# Docker版ROS2_humble



## 直接版本：

```shell
#拉取镜像
docker pull osrf/ros:humble-desktop

#开启可视化界面
xhost(参数)
//+：关闭访问控制，允许任何主机访问本地的X服务器；
//-：打开访问控制，仅允许授权清单中的主机访问本地的X服务器。

#容器换源
vim /etc/apt/sources.list

#粘贴源--------------------------------------------------------------------------------------------------------------
# 默认注释了源码镜像以提高 apt update 速度，如有需要可自行取消注释
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ jammy main restricted universe multiverse
deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ jammy main restricted universe multiverse
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ jammy-updates main restricted universe multiverse
deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ jammy-updates main restricted universe multiverse
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ jammy-backports main restricted universe multiverse
deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ jammy-backports main restricted universe multiverse

deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ jammy-security main restricted universe multiverse
deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ jammy-security main restricted universe multiverse

# deb http://security.ubuntu.com/ubuntu/ jammy-security main restricted universe multiverse
# deb-src http://security.ubuntu.com/ubuntu/ jammy-security main restricted universe multiverse

# 预发布软件源，不建议启用
# deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ jammy-proposed main restricted universe multiverse
# deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ jammy-proposed main restricted universe multiverse
#---------------------------------------------------------------------------------------------------------------------

#启动镜像
sudo docker run -it -v ~/d/docker/humble_container_data_1:/data -v /dev:/dev --privileged --group-add video --volume=/tmp/.X11-unix:/tmp/.X11-unix  --env="DISPLAY=$DISPLAY" --env="QT_X11_NO_MITSHM=1" --name=humble_ros_2 osrf/ros:humble-desktop  /bin/bash 

#ROS2——bashrc
echo 'source /opt/ros/humble/setup.bash'>> ~/.bashrc
sudo apt install gazebo
apt-get install -y python3-pip openssh-server gdb gdbserver
apt-get update && \
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
vim 
pip install rosdepc
rosdepc init && rosdepc update

#测试gazebo ，rviz2如果黑屏，请参考本目录下面的Solved_problems 里面的  rviz2黑屏
```

## dockerfile版（我没有测试，问wxz）

```shell
FROM osrf/ros:humble-desktop
RUN rm /etc/apt/sources.list
ADD sources.list /etc/apt/
RUN apt clean && apt update &&apt upgrade -y && apt-get install -y python3-pip openssh-server gdb gdbserver
    #安装rosdepc<https://zhuanlan.zhihu.com/p/398754989>
RUN sudo pip install rosdepc 

RUN sudo rosdepc init && rosdepc update

USER root

RUN echo "source /opt/ros/humble/setup.bash" >> /root/.bashrc

# 创建项目源码目录，这个目录将成为 Container 里面构建和执行的工作区
RUN mkdir -p /root/2ROS2workspace
WORKDIR /root/2ROS2workspace
ENV LC_ALL C.UTF-8
```





```shell
❯ docker inspect 66ed6a552749
[
    {
        "Id": "66ed6a552749c15374c03fb6f456cd0fa6d071764f50536407d7c369d6728029",
        "Created": "2023-06-04T06:06:42.64959093Z",
        "Path": "/ros_entrypoint.sh",
        "Args": [
            "/bin/bash"
        ],
        "State": {
            "Status": "running",
            "Running": true,
            "Paused": false,
            "Restarting": false,
            "OOMKilled": false,
            "Dead": false,
            "Pid": 14791,
            "ExitCode": 0,
            "Error": "",
            "StartedAt": "2023-06-30T12:39:03.981650548Z",
            "FinishedAt": "2023-06-29T14:22:09.466736316Z"
        },
        "Image": "sha256:2d0812be07a4791aa8f05a07ccb36f47bb1f3d092f117d98c641a1af33bc7e3c",
        "ResolvConfPath": "/var/lib/docker/containers/66ed6a552749c15374c03fb6f456cd0fa6d071764f50536407d7c369d6728029/resolv.conf",
        "HostnamePath": "/var/lib/docker/containers/66ed6a552749c15374c03fb6f456cd0fa6d071764f50536407d7c369d6728029/hostname",
        "HostsPath": "/var/lib/docker/containers/66ed6a552749c15374c03fb6f456cd0fa6d071764f50536407d7c369d6728029/hosts",
        "LogPath": "/var/lib/docker/containers/66ed6a552749c15374c03fb6f456cd0fa6d071764f50536407d7c369d6728029/66ed6a552749c15374c03fb6f456cd0fa6d071764f50536407d7c369d6728029-json.log",
        "Name": "/humble_ros_2",
        "RestartCount": 0,
        "Driver": "overlay2",
        "Platform": "linux",
        "MountLabel": "",
        "ProcessLabel": "",
        "AppArmorProfile": "unconfined",
        "ExecIDs": [
            "76977dbb06657a41541a6108f5d1018c973e2175be1d6ab94b6baf39c5b15193",
            "985ec89898398910932c56d58abe7955fb753bab164bb9f4d0dfdba325ec53d9",
            "a03b3807bc8acbedf5ae5eb78cec3b081c4a57b0208cdd8349313720dcdc7ea3",
            "fec220895d8b4604d8dd951973cd9c759c26cdd49befbdc551cc16b2273e1b1c",
            "67af3ed1b11e4a96d85ac395505d06d6c7c2a1f7f4a39059e7ea719cf758f819",
            "cd80e3560720c14bd964dd8a4ec5bd0f8fd1c38ce52b344bfa9161ad87de9a3f",
            "4b872619f812197fa37de402d6dd29a807ed013cc63002fc705f1bb0bc896c4e",
            "59ba222d2b8d3da2060ab51391840685a66d54478b20a52ae0088fbc273602aa",
            "b764bc261e75f29bc17220ae9c31657d01ca0735d7b9433b372a8b23f1fa2aa4",
            "f9a7237b971f8c17278f9991fe355d525d90ecbb306825285ecacccbfb3943e4"
        ],
        "HostConfig": {
            "Binds": [
                "/mnt/d/docker/humble_container_data_1:/data",
                "/dev:/dev",
                "/tmp/.X11-unix:/tmp/.X11-unix"
            ],
            "ContainerIDFile": "",
            "LogConfig": {
                "Type": "json-file",
                "Config": {}
            },
            "NetworkMode": "default",
            "PortBindings": {},
            "RestartPolicy": {
                "Name": "no",
                "MaximumRetryCount": 0
            },
            "AutoRemove": false,
            "VolumeDriver": "",
            "VolumesFrom": null,
            "ConsoleSize": [
                30,
                120
            ],
            "CapAdd": null,
            "CapDrop": null,
            "CgroupnsMode": "private",
            "Dns": [],
            "DnsOptions": [],
            "DnsSearch": [],
            "ExtraHosts": null,
            "GroupAdd": [
                "video"
            ],
            "IpcMode": "private",
            "Cgroup": "",
            "Links": null,
            "OomScoreAdj": 0,
            "PidMode": "",
            "Privileged": true,
            "PublishAllPorts": false,
            "ReadonlyRootfs": false,
            "SecurityOpt": [
                "label=disable"
            ],
            "UTSMode": "",
            "UsernsMode": "",
            "ShmSize": 67108864,
            "Runtime": "runc",
            "Isolation": "",
            "CpuShares": 0,
            "Memory": 0,
            "NanoCpus": 0,
            "CgroupParent": "",
            "BlkioWeight": 0,
            "BlkioWeightDevice": [],
            "BlkioDeviceReadBps": [],
            "BlkioDeviceWriteBps": [],
            "BlkioDeviceReadIOps": [],
            "BlkioDeviceWriteIOps": [],
            "CpuPeriod": 0,
            "CpuQuota": 0,
            "CpuRealtimePeriod": 0,
            "CpuRealtimeRuntime": 0,
            "CpusetCpus": "",
            "CpusetMems": "",
            "Devices": [],
            "DeviceCgroupRules": null,
            "DeviceRequests": null,
            "MemoryReservation": 0,
            "MemorySwap": 0,
            "MemorySwappiness": null,
            "OomKillDisable": null,
            "PidsLimit": null,
            "Ulimits": null,
            "CpuCount": 0,
            "CpuPercent": 0,
            "IOMaximumIOps": 0,
            "IOMaximumBandwidth": 0,
            "MaskedPaths": null,
            "ReadonlyPaths": null
        },
        "GraphDriver": {
            "Data": {
                "LowerDir": "/var/lib/docker/overlay2/5fdff61eea46d4c8a5b82ae673bc696810f9370ca1f82ab56610615e68ac09aa-init/diff:/var/lib/docker/overlay2/b7a1645dfd849e1a0820b72bcdbd370e8078f5c8e576cff4701206e0ef9f2b5f/diff:/var/lib/docker/overlay2/c21dd11069b4b18fe52f8ea5cac766c11f2b5056eb6bbc4db03b206a75bcaffc/diff:/var/lib/docker/overlay2/643ac9040d4f59749128864d3e38e47772030575ca32cd82fcf99a803eff4c0b/diff:/var/lib/docker/overlay2/74e228c730628a4cb54b8f82e16e2fcb21f4e46a0b6e6780e74e42c26f311dba/diff:/var/lib/docker/overlay2/f254fc253036002ed61f450dba6203e17e805a77bee8926a6a26d3f6feb753fc/diff:/var/lib/docker/overlay2/da10a1e8244836b2aa1c502f15ca6775a2877e58580da654672f83b2f73ccbc0/diff:/var/lib/docker/overlay2/4180034cacfa42b69568e884ecb8c95285c969479bef775c27183f3849e3ae8d/diff:/var/lib/docker/overlay2/9ab2b0a97ab583a800af3552e8a775128fca30a96699ec9b81db668e013cab84/diff:/var/lib/docker/overlay2/0e66ced67f7df99f8f52edbd7daa9b83c2ed0e134f674c752ab99f48349a68c2/diff:/var/lib/docker/overlay2/fba0816b63287bb6dfc338633b4e67062207eb66aa60a11ee4c9489d1fc860fe/diff:/var/lib/docker/overlay2/ad529b1a032d38df57f4ea7e6ee5f709fa02e99ec3c05c3fc35665bd60390eed/diff:/var/lib/docker/overlay2/485ccf30a2c6ffbfbd1de8501e031424adf4e3a58f89fc2092aa41e54e60751b/diff",
                "MergedDir": "/var/lib/docker/overlay2/5fdff61eea46d4c8a5b82ae673bc696810f9370ca1f82ab56610615e68ac09aa/merged",
                "UpperDir": "/var/lib/docker/overlay2/5fdff61eea46d4c8a5b82ae673bc696810f9370ca1f82ab56610615e68ac09aa/diff",
                "WorkDir": "/var/lib/docker/overlay2/5fdff61eea46d4c8a5b82ae673bc696810f9370ca1f82ab56610615e68ac09aa/work"
            },
            "Name": "overlay2"
        },
        "Mounts": [
            {
                "Type": "bind",
                "Source": "/mnt/d/docker/humble_container_data_1",
                "Destination": "/data",
                "Mode": "",
                "RW": true,
                "Propagation": "rprivate"
            },
            {
                "Type": "bind",
                "Source": "/dev",
                "Destination": "/dev",
                "Mode": "",
                "RW": true,
                "Propagation": "rprivate"
            },
            {
                "Type": "bind",
                "Source": "/tmp/.X11-unix",
                "Destination": "/tmp/.X11-unix",
                "Mode": "",
                "RW": true,
                "Propagation": "rprivate"
            }
        ],
        "Config": {
            "Hostname": "66ed6a552749",
            "Domainname": "",
            "User": "",
            "AttachStdin": true,
            "AttachStdout": true,
            "AttachStderr": true,
            "Tty": true,
            "OpenStdin": true,
            "StdinOnce": true,
            "Env": [
                "DISPLAY=:1",
                "QT_X11_NO_MITSHM=1",
                "PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin",
                "LANG=C.UTF-8",
                "LC_ALL=C.UTF-8",
                "ROS_DISTRO=humble"
            ],
            "Cmd": [
                "/bin/bash"
            ],
            "Image": "osrf/ros:humble-desktop",
            "Volumes": null,
            "WorkingDir": "",
            "Entrypoint": [
                "/ros_entrypoint.sh"
            ],
            "OnBuild": null,
            "Labels": {
                "org.opencontainers.image.ref.name": "ubuntu",
                "org.opencontainers.image.version": "22.04"
            }
        },
        "NetworkSettings": {
            "Bridge": "",
            "SandboxID": "bc5e38dd552a47766215c8930157405fe861ba82c2ade93bfa4e25e6877cff17",
            "HairpinMode": false,
            "LinkLocalIPv6Address": "",
            "LinkLocalIPv6PrefixLen": 0,
            "Ports": {},
            "SandboxKey": "/var/run/docker/netns/bc5e38dd552a",
            "SecondaryIPAddresses": null,
            "SecondaryIPv6Addresses": null,
            "EndpointID": "a35e5608ae261c6b96c99decbc4fd3074cb3ae234e03daac4717bd7a75ee5071",
            "Gateway": "172.17.0.1",
            "GlobalIPv6Address": "",
            "GlobalIPv6PrefixLen": 0,
            "IPAddress": "172.17.0.2",
            "IPPrefixLen": 16,
            "IPv6Gateway": "",
            "MacAddress": "02:42:ac:11:00:02",
            "Networks": {
                "bridge": {
                    "IPAMConfig": null,
                    "Links": null,
                    "Aliases": null,
                    "NetworkID": "2a7f670329b8836c32af8c9d3fb26c81f613e9722c5c5d2eefd659d16beb8899",
                    "EndpointID": "a35e5608ae261c6b96c99decbc4fd3074cb3ae234e03daac4717bd7a75ee5071",
                    "Gateway": "172.17.0.1",
                    "IPAddress": "172.17.0.2",
                    "IPPrefixLen": 16,
                    "IPv6Gateway": "",
                    "GlobalIPv6Address": "",
                    "GlobalIPv6PrefixLen": 0,
                    "MacAddress": "02:42:ac:11:00:02",
                    "DriverOpts": null
                }
            }
        }
    }
]
```

=======
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
sudo docker run -it -v ~/d/docker/humble_container_data_1:/data -v /dev:/dev --privileged --group-add video --volume=/tmp/.X11-unix:/tmp/.X11-unix  --env="DISPLAY=$DISPLAY" --env="QT_X11_NO_MITSHM=1" --name=humble_ros_2 osrf/ros:humble-desktop  /bin/bash 

#ROS2——bashrc
echo 'source /opt/ros/humble/setup.bash'>> ~/.bashrc
sudo apt install rviz2
sudo apt install gazebo
apt-get install -y python3-pip openssh-server gdb gdbserver
apt-get update && \
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
vim 
pip install rosdepc
rosdepc init && rosdepc update
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





```shell
❯ docker inspect 66ed6a552749
[
    {
        "Id": "66ed6a552749c15374c03fb6f456cd0fa6d071764f50536407d7c369d6728029",
        "Created": "2023-06-04T06:06:42.64959093Z",
        "Path": "/ros_entrypoint.sh",
        "Args": [
            "/bin/bash"
        ],
        "State": {
            "Status": "running",
            "Running": true,
            "Paused": false,
            "Restarting": false,
            "OOMKilled": false,
            "Dead": false,
            "Pid": 14791,
            "ExitCode": 0,
            "Error": "",
            "StartedAt": "2023-06-30T12:39:03.981650548Z",
            "FinishedAt": "2023-06-29T14:22:09.466736316Z"
        },
        "Image": "sha256:2d0812be07a4791aa8f05a07ccb36f47bb1f3d092f117d98c641a1af33bc7e3c",
        "ResolvConfPath": "/var/lib/docker/containers/66ed6a552749c15374c03fb6f456cd0fa6d071764f50536407d7c369d6728029/resolv.conf",
        "HostnamePath": "/var/lib/docker/containers/66ed6a552749c15374c03fb6f456cd0fa6d071764f50536407d7c369d6728029/hostname",
        "HostsPath": "/var/lib/docker/containers/66ed6a552749c15374c03fb6f456cd0fa6d071764f50536407d7c369d6728029/hosts",
        "LogPath": "/var/lib/docker/containers/66ed6a552749c15374c03fb6f456cd0fa6d071764f50536407d7c369d6728029/66ed6a552749c15374c03fb6f456cd0fa6d071764f50536407d7c369d6728029-json.log",
        "Name": "/humble_ros_2",
        "RestartCount": 0,
        "Driver": "overlay2",
        "Platform": "linux",
        "MountLabel": "",
        "ProcessLabel": "",
        "AppArmorProfile": "unconfined",
        "ExecIDs": [
            "76977dbb06657a41541a6108f5d1018c973e2175be1d6ab94b6baf39c5b15193",
            "985ec89898398910932c56d58abe7955fb753bab164bb9f4d0dfdba325ec53d9",
            "a03b3807bc8acbedf5ae5eb78cec3b081c4a57b0208cdd8349313720dcdc7ea3",
            "fec220895d8b4604d8dd951973cd9c759c26cdd49befbdc551cc16b2273e1b1c",
            "67af3ed1b11e4a96d85ac395505d06d6c7c2a1f7f4a39059e7ea719cf758f819",
            "cd80e3560720c14bd964dd8a4ec5bd0f8fd1c38ce52b344bfa9161ad87de9a3f",
            "4b872619f812197fa37de402d6dd29a807ed013cc63002fc705f1bb0bc896c4e",
            "59ba222d2b8d3da2060ab51391840685a66d54478b20a52ae0088fbc273602aa",
            "b764bc261e75f29bc17220ae9c31657d01ca0735d7b9433b372a8b23f1fa2aa4",
            "f9a7237b971f8c17278f9991fe355d525d90ecbb306825285ecacccbfb3943e4"
        ],
        "HostConfig": {
            "Binds": [
                "/mnt/d/docker/humble_container_data_1:/data",
                "/dev:/dev",
                "/tmp/.X11-unix:/tmp/.X11-unix"
            ],
            "ContainerIDFile": "",
            "LogConfig": {
                "Type": "json-file",
                "Config": {}
            },
            "NetworkMode": "default",
            "PortBindings": {},
            "RestartPolicy": {
                "Name": "no",
                "MaximumRetryCount": 0
            },
            "AutoRemove": false,
            "VolumeDriver": "",
            "VolumesFrom": null,
            "ConsoleSize": [
                30,
                120
            ],
            "CapAdd": null,
            "CapDrop": null,
            "CgroupnsMode": "private",
            "Dns": [],
            "DnsOptions": [],
            "DnsSearch": [],
            "ExtraHosts": null,
            "GroupAdd": [
                "video"
            ],
            "IpcMode": "private",
            "Cgroup": "",
            "Links": null,
            "OomScoreAdj": 0,
            "PidMode": "",
            "Privileged": true,
            "PublishAllPorts": false,
            "ReadonlyRootfs": false,
            "SecurityOpt": [
                "label=disable"
            ],
            "UTSMode": "",
            "UsernsMode": "",
            "ShmSize": 67108864,
            "Runtime": "runc",
            "Isolation": "",
            "CpuShares": 0,
            "Memory": 0,
            "NanoCpus": 0,
            "CgroupParent": "",
            "BlkioWeight": 0,
            "BlkioWeightDevice": [],
            "BlkioDeviceReadBps": [],
            "BlkioDeviceWriteBps": [],
            "BlkioDeviceReadIOps": [],
            "BlkioDeviceWriteIOps": [],
            "CpuPeriod": 0,
            "CpuQuota": 0,
            "CpuRealtimePeriod": 0,
            "CpuRealtimeRuntime": 0,
            "CpusetCpus": "",
            "CpusetMems": "",
            "Devices": [],
            "DeviceCgroupRules": null,
            "DeviceRequests": null,
            "MemoryReservation": 0,
            "MemorySwap": 0,
            "MemorySwappiness": null,
            "OomKillDisable": null,
            "PidsLimit": null,
            "Ulimits": null,
            "CpuCount": 0,
            "CpuPercent": 0,
            "IOMaximumIOps": 0,
            "IOMaximumBandwidth": 0,
            "MaskedPaths": null,
            "ReadonlyPaths": null
        },
        "GraphDriver": {
            "Data": {
                "LowerDir": "/var/lib/docker/overlay2/5fdff61eea46d4c8a5b82ae673bc696810f9370ca1f82ab56610615e68ac09aa-init/diff:/var/lib/docker/overlay2/b7a1645dfd849e1a0820b72bcdbd370e8078f5c8e576cff4701206e0ef9f2b5f/diff:/var/lib/docker/overlay2/c21dd11069b4b18fe52f8ea5cac766c11f2b5056eb6bbc4db03b206a75bcaffc/diff:/var/lib/docker/overlay2/643ac9040d4f59749128864d3e38e47772030575ca32cd82fcf99a803eff4c0b/diff:/var/lib/docker/overlay2/74e228c730628a4cb54b8f82e16e2fcb21f4e46a0b6e6780e74e42c26f311dba/diff:/var/lib/docker/overlay2/f254fc253036002ed61f450dba6203e17e805a77bee8926a6a26d3f6feb753fc/diff:/var/lib/docker/overlay2/da10a1e8244836b2aa1c502f15ca6775a2877e58580da654672f83b2f73ccbc0/diff:/var/lib/docker/overlay2/4180034cacfa42b69568e884ecb8c95285c969479bef775c27183f3849e3ae8d/diff:/var/lib/docker/overlay2/9ab2b0a97ab583a800af3552e8a775128fca30a96699ec9b81db668e013cab84/diff:/var/lib/docker/overlay2/0e66ced67f7df99f8f52edbd7daa9b83c2ed0e134f674c752ab99f48349a68c2/diff:/var/lib/docker/overlay2/fba0816b63287bb6dfc338633b4e67062207eb66aa60a11ee4c9489d1fc860fe/diff:/var/lib/docker/overlay2/ad529b1a032d38df57f4ea7e6ee5f709fa02e99ec3c05c3fc35665bd60390eed/diff:/var/lib/docker/overlay2/485ccf30a2c6ffbfbd1de8501e031424adf4e3a58f89fc2092aa41e54e60751b/diff",
                "MergedDir": "/var/lib/docker/overlay2/5fdff61eea46d4c8a5b82ae673bc696810f9370ca1f82ab56610615e68ac09aa/merged",
                "UpperDir": "/var/lib/docker/overlay2/5fdff61eea46d4c8a5b82ae673bc696810f9370ca1f82ab56610615e68ac09aa/diff",
                "WorkDir": "/var/lib/docker/overlay2/5fdff61eea46d4c8a5b82ae673bc696810f9370ca1f82ab56610615e68ac09aa/work"
            },
            "Name": "overlay2"
        },
        "Mounts": [
            {
                "Type": "bind",
                "Source": "/mnt/d/docker/humble_container_data_1",
                "Destination": "/data",
                "Mode": "",
                "RW": true,
                "Propagation": "rprivate"
            },
            {
                "Type": "bind",
                "Source": "/dev",
                "Destination": "/dev",
                "Mode": "",
                "RW": true,
                "Propagation": "rprivate"
            },
            {
                "Type": "bind",
                "Source": "/tmp/.X11-unix",
                "Destination": "/tmp/.X11-unix",
                "Mode": "",
                "RW": true,
                "Propagation": "rprivate"
            }
        ],
        "Config": {
            "Hostname": "66ed6a552749",
            "Domainname": "",
            "User": "",
            "AttachStdin": true,
            "AttachStdout": true,
            "AttachStderr": true,
            "Tty": true,
            "OpenStdin": true,
            "StdinOnce": true,
            "Env": [
                "DISPLAY=:1",
                "QT_X11_NO_MITSHM=1",
                "PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin",
                "LANG=C.UTF-8",
                "LC_ALL=C.UTF-8",
                "ROS_DISTRO=humble"
            ],
            "Cmd": [
                "/bin/bash"
            ],
            "Image": "osrf/ros:humble-desktop",
            "Volumes": null,
            "WorkingDir": "",
            "Entrypoint": [
                "/ros_entrypoint.sh"
            ],
            "OnBuild": null,
            "Labels": {
                "org.opencontainers.image.ref.name": "ubuntu",
                "org.opencontainers.image.version": "22.04"
            }
        },
        "NetworkSettings": {
            "Bridge": "",
            "SandboxID": "bc5e38dd552a47766215c8930157405fe861ba82c2ade93bfa4e25e6877cff17",
            "HairpinMode": false,
            "LinkLocalIPv6Address": "",
            "LinkLocalIPv6PrefixLen": 0,
            "Ports": {},
            "SandboxKey": "/var/run/docker/netns/bc5e38dd552a",
            "SecondaryIPAddresses": null,
            "SecondaryIPv6Addresses": null,
            "EndpointID": "a35e5608ae261c6b96c99decbc4fd3074cb3ae234e03daac4717bd7a75ee5071",
            "Gateway": "172.17.0.1",
            "GlobalIPv6Address": "",
            "GlobalIPv6PrefixLen": 0,
            "IPAddress": "172.17.0.2",
            "IPPrefixLen": 16,
            "IPv6Gateway": "",
            "MacAddress": "02:42:ac:11:00:02",
            "Networks": {
                "bridge": {
                    "IPAMConfig": null,
                    "Links": null,
                    "Aliases": null,
                    "NetworkID": "2a7f670329b8836c32af8c9d3fb26c81f613e9722c5c5d2eefd659d16beb8899",
                    "EndpointID": "a35e5608ae261c6b96c99decbc4fd3074cb3ae234e03daac4717bd7a75ee5071",
                    "Gateway": "172.17.0.1",
                    "IPAddress": "172.17.0.2",
                    "IPPrefixLen": 16,
                    "IPv6Gateway": "",
                    "GlobalIPv6Address": "",
                    "GlobalIPv6PrefixLen": 0,
                    "MacAddress": "02:42:ac:11:00:02",
                    "DriverOpts": null
                }
            }
        }
    }
]
```

>>>>>>> Stashed changes
