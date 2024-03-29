# 终于 微信 for linux

## For UOS or 麒麟

直接装



## For Ubuntu 

## 1.0   安装 Flatpak

https://flatpak.org/setup/Ubuntu

```shell
sudo apt install flatpak

sudo apt install gnome-software-plugin-flatpak

flatpak remote-add --if-not-exists flathub https://dl.flathub.org/repo/flathub.flatpakrepo
```



## 2.0   下载微信包

[github **[wechat-universal-flatpak]**](https://github.com/web1n/wechat-universal-flatpak)

从 Release 下载安装包，使用以下命令安装即可。

```shell
flatpak install com.tencent.WeChat.flatpak
```

