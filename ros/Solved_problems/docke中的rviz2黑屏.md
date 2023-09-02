# rviz2 



### 系统中应开启

```shell
xhost +
```

```shell
add-apt-repository ppa:kisak/kisak-mesa && apt install -y mesa-utils && glxgears
```

其中 glxgears 是测试3d功能的，不安装也行

如果提示add-apt-repository commond not found

    sudo apt install --reinstall software-properties-common

### PPA换源：

# ==一定要确保自己的代理打开了！！！！！==

### clash请选择servicemode 点击==install==

### 然后打开 ==Tun mode==

    gedit sources.list.d/kisak-ubuntu-kisak-mesa-jammy.list
    
    deb https://launchpad.proxy.ustclug.org/kisak/kisak-mesa/ubuntu/ jammy main
    # deb-src https://ppa.launchpadcontent.net/kisak/kisak-mesa/ubuntu/ jammy main
    
    apt update -y && apt upgrade