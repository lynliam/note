# mount ntfs 分区只读 --Falling back to read-only mount because the NTFS partition is in an unsafe state

## 问题：

再一次强制关机中，重启后出现此问题

运行```tail -f /var/log/syslog```,时出现：

```
The disk contains an unclean file system (0, 0).
Metadata kept in Windows cache, refused to mount.
Falling back to read-only mount because the NTFS partition is in an
unsafe state. Please resume and shutdown Windows fully (no hibernation
or fast restarting.)
```



## 解决方法：

### 1. 安装```ntfs-3g```

```shell
sudo apt install ntfs-3g
```

### 2. 修复

```shell
sudo ntfsfixf /dev/nvme1px
```



