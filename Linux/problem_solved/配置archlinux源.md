# archlinux源





## 1. 备份 pacman 配置文件

```shell
sudo cp /etc/pacman.conf /etc/pacman.conf_backup
```

## 2. 编辑 pacman.conf 文件

使用任意文本编辑器（如 vim、nano、emacs 等），编辑 `/etc/pacman.conf` 文件（需要 root 权限）。

将以下内容复制到 `/etc/pacman.conf` 文件的**末尾**

```shell
Server = https://mirrors.hit.edu.cn/archlinux/$repo/os/$arch
Server = https://mirrors.tuna.tsinghua.edu.cn/archlinux/$repo/os/$arch
Server = https://mirrors.ustc.edu.cn/archlinux/$repo/os/$arch
```



```shell
#ArchLinuxCN 镜像
[archlinuxcn]
Server = https://mirrors.tuna.tsinghua.edu.cn/archlinuxcn/$arch
Server = https://mirrors.hit.edu.cn/archlinuxcn/$arch
Server = https://mirrors.ustc.edu.cn/archlinuxcn/$arch

#导入 archlinuxcn 钥匙环
sudo pacman -Sy archlinuxcn-keyring

#随后将自动进行 GPG 签名
```



## 2. 更新 pacman 本地软件包数据库

```shell
# 强制从镜像源同步软件包数据库
sudo pacman -Syy
```

或者

```shell
# 强制从镜像源同步软件包数据库并且更新系统
sudo pacman -Syyu
```

建议同时启用 `archlinuxcn` 源

