# apt只安装升级特定包

## 一、查看升级软件list

```shell
apt list --upgratable
```

## 二、升级

```shell
sudo apt install --only-upgrade <package name> <package name> ...
```

