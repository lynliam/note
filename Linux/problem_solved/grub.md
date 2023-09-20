# GRUB



1. ## 修改启动顺序

```shell
#终端中输入 
sudo gedit /etc/default/grub  

#设置
default-set=2 #(从0开始数起，如果希望第三项，选2)

#执行一下
sudo update-grub
#来重新生成GRUB启动配置项。
```



2. ## 修改主题

```shell
#文件在当前目录下面
#解压后
sudo ./install.sh
```



