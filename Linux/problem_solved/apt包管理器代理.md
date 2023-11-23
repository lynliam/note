# Ubuntu apt 包管理器代理设置

有时候会遇到服务器不在透明代理环境下，而我们与需要安装的软件下载源连接性不稳定，这个时候我们可能就需要临时为 apt 包管理器启用一下代理。

apt 代理设置主要可以分为以下三种方式：

## 1.环境变量法：

```shell
export http_proxy=http://127.0.0.1:7890
apt-get update
```

> 这种方式会设置的代理只在当前会话用户与 shell 中存在（也就是说应该直接 root 用户执行，不能使用 sudo 否则环境变量会失效）

## 2.临时命令：

```shell
sudo apt-get -o Acquire::http::proxy="http://127.0.0.1:7890/" update
```



## 3.修改apt包管理器配置文件：

修改 `/etc/apt/apt.conf`，增加如下配置：

```shell
Acquire::http::proxy "http://127.0.0.1:7890/";
Acquire::ftp::proxy "ftp://127.0.0.1:7890/";
Acquire::https::proxy "https://127.0.0.1:7890/";
```

> 这种方式会将代理设置持久化配置，但是不够灵活，如果代理出现问题需要再次修改配置文件进行调整。