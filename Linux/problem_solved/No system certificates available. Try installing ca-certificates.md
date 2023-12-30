# No system certificates available. Try installing ca-certificates

### 先把 源的`https`改成`http` 

### 源配置#

```shell
deb https://mirrors.aliyun.com/debian/ bullseye main non-free contrib
deb-src https://mirrors.aliyun.com/debian/ bullseye main non-free contrib
deb https://mirrors.aliyun.com/debian-security/ bullseye-security main
deb-src https://mirrors.aliyun.com/debian-security/ bullseye-security main
deb https://mirrors.aliyun.com/debian/ bullseye-updates main non-free contrib
deb-src https://mirrors.aliyun.com/debian/ bullseye-updates main non-free contrib
deb https://mirrors.aliyun.com/debian/ bullseye-backports main non-free contrib
deb-src https://mirrors.aliyun.com/debian/ bullseye-backports main non-free contrib
```

我们可以看到使用的是https协议

### 问题描述#

然而修改好配置时，进行sudo apt-get update报错：

```shell
Reading package lists... Done
W: https://mirrors.aliyun.com/debian/dists/bullseye/InRelease: No system certificates available. Try installing ca-certificates.
W: https://mirrors.aliyun.com/debian/dists/bullseye-updates/InRelease: No system certificates available. Try installing ca-certificates.
W: Failed to fetch https://mirrors.aliyun.com/debian/dists/bullseye/InRelease  Certificate verification failed: The certificate is NOT trusted. The certificate issuer is unknown.  Could not handshake: Error in the certificate verification. 
W: Failed to fetch https://mirrors.aliyun.com/debian/dists/bullseye-updates/InRelease  Certificate verification failed: The certificate is NOT trusted. The certificate issuer is unknown.  Could not handshake: Error in the certificate verification. 
W: Some index files failed to download. They have been ignored, or old ones used instead.
```

出现安全证书不信任的问题

### 解决办法#

有三种解决办法，使用其一即可。

* 把https协议换成http协议
* 先安装certificate库（安装命令为sudo apt install ca-certificates），再修改成阿里云的源地址。有一种不配源怎么安装，不安装怎么配源的死锁感😂