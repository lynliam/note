# Linux折腾史

### 安装

1. 关闭security boot
2. 调整usb启动顺序
3. windows11下按着shift+重启键可以进疑难解答—＞uefi管理（进BIOS）
4. 重启进安装界面
5. 选Ubuntu
6. 过程点（something else），并拒绝联网


***
### 分区

1. /根目录
2.  swap  交换分区，和运行内存相关
3.  /var  系统运行时要改变的数据
4.  /home  用户目录文件
5.  /usr  软件存在处
6.  /opt
7.  /scr
8.  /efi  双硬盘请放于主windows硬盘（创建efi分区512Mb）记得选择引导分区
9. over

***

### 换源

更换源
1. 备份原来的源
  ```sudo cp -v /etc/apt/sources.list /etc/apt/sources.list.backup```
2. 终端执行chmod命令更改文件权限使软件源文件可编辑：
  ```sudo chmod 777 /etc/apt/sources.list```
3. 编辑     ```sudo gedit /etc/apt/sources.list```

如果你已添加 PPA 仓库，请查看 `/etc/apt/sources.list.d/` 目录并删除相应的条目

#### 阿里源

​    deb http://mirrors.aliyun.com/ubuntu/ bionic main restricted universe multiverse
​    deb http://mirrors.aliyun.com/ubuntu/ bionic-security main restricted universe multiverse
​    deb http://mirrors.aliyun.com/ubuntu/ bionic-updates main restricted universe multiverse
​    deb http://mirrors.aliyun.com/ubuntu/ bionic-proposed main restricted universe multiverse
​    deb http://mirrors.aliyun.com/ubuntu/ bionic-backports main restricted universe multiverse
​    deb-src http://mirrors.aliyun.com/ubuntu/ bionic main restricted universe multiverse
​    deb-src http://mirrors.aliyun.com/ubuntu/ bionic-security main restricted universe multiverse
​    deb-src http://mirrors.aliyun.com/ubuntu/ bionic-updates main restricted universe multiverse
​    deb-src http://mirrors.aliyun.com/ubuntu/ bionic-proposed main restricted universe multiverse
​    deb-src http://mirrors.aliyun.com/ubuntu/ bionic-backports main restricted universe multiverse

#### 清华源
    deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic main restricted universe multiverse
    deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic main restricted universe multiverse
    deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-updates main restricted universe multiverse
    deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-updates main restricted universe multiverse
    deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-backports main restricted universe multiverse
    deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-backports main restricted universe multiverse
    deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-security main restricted universe multiverse
    deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-security main restricted universe multiverse
    deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-proposed main restricted universe multiverse
    deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-proposed main restricted universe multiverse
#### 中科大源

​    deb https://mirrors.ustc.edu.cn/ubuntu/ bionic main restricted universe multiverse
​    deb-src https://mirrors.ustc.edu.cn/ubuntu/ bionic main restricted universe multiverse
​    deb https://mirrors.ustc.edu.cn/ubuntu/ bionic-updates main restricted universe multiverse
​    deb-src https://mirrors.ustc.edu.cn/ubuntu/ bionic-updates main restricted universe multiverse
​    deb https://mirrors.ustc.edu.cn/ubuntu/ bionic-backports main restricted universe multiverse
​    deb-src https://mirrors.ustc.edu.cn/ubuntu/ bionic-backports main restricted universe multiverse
​    deb https://mirrors.ustc.edu.cn/ubuntu/ bionic-security main restricted universe multiverse
​    deb-src https://mirrors.ustc.edu.cn/ubuntu/ bionic-security main restricted universe multiverse
​    deb https://mirrors.ustc.edu.cn/ubuntu/ bionic-proposed main restricted universe multiverse
​    deb-src https://mirrors.ustc.edu.cn/ubuntu/ bionic-proposed main restricted universe multiverse

4. 更新源sudo apt-get update
***

### 时间问题：

Windows 与 Linux 缺省看待系统硬件时间的方式是不一样的：

Linux 时钟分为系统时钟(System Clock)和硬件(RTC)时钟。Linux把硬件时间当作 UTC,系统时间是UTC时间经过换算得来的。比如说北京时间是GMT+8,则系统中显示时间是硬件时间+8。
Windows把系统硬件(RTC)时间当作本地时间(local time)，即系统时间跟BIOS中显示的时间(RTC)是一样的。

    sudo apt-get install ntpdate					//在Ubuntu下更新本地时间
    sudo ntpdate time.windows.com
    sudo hwclock --localtime --systohc			//将本地时间更新到硬件上
***
### 禁用nouveau驱动

* 创建配置文件：
```sudo gedit /etc/modprobe.d/blacklist_nouveau.conf```

* 文件中添加：
    ```blacklist nouveau```
  ```  options nouveau modeset=0```

* 重启，然后输入以下命令验证是否生效：
    ```lsmod | grep nouveau```

* 可能出现的问题：提示无法保存创建的blacklist_nouveau.conf文件
方法：提升用户权限，执行：
```cd /etc/modprobe.d/```
```sudo chmod 777```

* 不要遗漏sudo chmod 777 . 后面的“.”，表示当前路径，然后就可以保存创建的blacklist_nouveau.conf文件了。
***
### 卸载Ubuntu

1. 把开机启动项设为默认Windows启动

2. 删除Ubuntu系统分区

3. 进入windows系统，win+R--输入Diskpart

* ```list disk```

* ```select disk 0```

* ``list partition``

* ``select partition 6``（先删除Ubuntu启动项EFI所在分区）

* ``delete partition override``

同样的方法，删掉/ /swap /home分区等。

#### 4. 用EasyUEFI----管理EFI启动项---删除ubuntu启动项

#### 5. 清除windows系统EFI中的ubuntu启动项

* 输入【Win】+【R】，输入【diskpart】打开diskpart；

* 输入【list disk】，显示磁盘列表

* 输入【select disk 0】，选择磁盘0，即win10系统所在磁盘；

* 输入【list partition】，查看磁盘0的分区列表；

* 输入【select partition 1】，选择标注启动的分区；

***

### 装好NVIDIA显卡驱动后，切换核显

```shell
#切换intel
sudo prime-select intel
#切换nvidia
sudo prime-select nvidia
#显示当前显卡
prime-select query
```

------

### 安装cpufrequtils

```shell
sudo apt-get install cpufrequtils 
cpufreq-set -g powersave
cpufreq-set -g performance
cpufreq-info
```





