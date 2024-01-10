# 利用创建编译container

## Dockerfile

```dockerfile
FROM ubuntu:22.04
MAINTAINER liam>quan.2003@outlook.com>

RUN rm /etc/apt/sources.list
ADD sources.list /etc/apt/
RUN apt update
RUN apt install -y ca-certificates sudo
RUN apt clean && apt update &&apt upgrade -y \
        && apt-get install -y python3-pip \
                build-essential \
                gcc \
                g++ \
                openssh-server \
                iproute2
                
RUN apt install -y clang-format \
        clang-tidy \
        clang-tools \
        clang \
        clangd \
        libc++-dev \
        libc++1 \
        libc++abi-dev \
        libc++abi1 \
        libclang-dev \
        libclang1 \
        liblldb-dev \
        libllvm-ocaml-dev \
        libomp-dev \
        libomp5 \
        lld \
        lldb \
        llvm-dev \
        llvm-runtime \
        llvm \
        python3-clang \
        && apt-get clean

ARG UID=1000
ARG BUILDER_PASSWORD=builder
ARG ROOT_PASSWORD=root
# Set root password
RUN echo "root:${ROOT_PASSWORD}" | chpasswd
RUN useradd -m -u ${UID} -s /bin/bash -G sudo builder
RUN echo "builder:${BUILDER_PASSWORD}" | chpasswd
USER builder

EXPOSE 22
```

```shell
sudo docker build --build-arg UID=$(id -u) -t compiler:cmp-2.0 .


sudo docker run -p 9822:22 -it -v ./data:/data --privileged --group-add video --volume=/tmp/.X11-unix:/tmp/.X11-unix  --env="DISPLAY=$DISPLAY" --env="QT_X11_NO_MITSHM=1" --name builder compiler:cmp-2.0  /bin/bash 
```



