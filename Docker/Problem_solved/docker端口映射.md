# docker的端口映射

> Docker除了通过网络访问外，还提供了其他两个非常方便的功能来满足服务访问的基本需求：
>
> 一是允许映射容器内应用的服务端口到本地宿主机端口；
>
> 二是使用互联机制来实现多个容器间通过容器名来快速访问

端口映射可使用-p、-P来实现 

> -p指定要映射的端口，一个指定端口上只可以绑定一个容器
>
> -P将容器内部开放的网络端口随机映射到宿主机的一个端口上



 端口映射支持的格式：
```shell
ip:hostport:containerport #指定ip、指定宿主机port、指定容器port
ip::containerport #指定ip、未指定宿主机port（随机）、指定容器port
hostport:containerport #未指定ip、指定宿主机port、指定容器port
```

端口的映射有以下五种方法：

### 1 将容器暴露的所有端口，都随机映射到宿主机上。
```shell
#（不推荐使用）

docker run -P -it ubuntu /bin/bash 
```

### 2 将容器指定端口随机映射到宿主机一个端口上。

```shell
docker run -P 80 -it ubuntu /bin/bash
```

以上指令会将容器的80端口随机映射到宿主机的一个端口上。

### 3 将容器指定端口指定映射到宿主机的一个端口上。
例如：

```shell
docker run -p 8000:80 -it ubuntu /bin/bash
```

以上指令会将容器的80端口映射到宿主机的8000端口上。

### 4 将容器ip和端口，随机映射到宿主机上

```shell
docker run -P 192.168.0.100::80 -it ubuntu /bin/bash
```

以上指令会将容器的ip192.168.0.100和80端口，随机映射到宿主机的一个端口上。

### 将容器ip和端口，指定映射到宿主机上

```shell
docker run -p 192.168.0.100:8000:80 -it ubuntu /bin/bash
```

上指令会将容器的ip192.168.0.100和80端口，映射到宿主机的8000端口

查看映射端口配置
```shell
docker port container_ID #容器ID
#结果输出
80/tcp -> 0.0.0.0:800
```

