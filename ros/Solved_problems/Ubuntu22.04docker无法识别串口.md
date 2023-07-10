能够找到USB设备，但是没有被映射为/dev/ttyUSB0的问题

我首先查看了是否存在ch340的驱动

lsmod | grep ch34

```shell
#返回
ch341                  24576  0
usbserial              57344  1 ch341
```

说明我的虚拟机是存在串口驱动的，但是没有找到设备，那通过这篇博客，我发现了是端口被占用了

    Ubuntu22.04没有ttyUSB（无法访问 ‘/dev/ttyUSB‘: 没有那个文件或目录）问题解决

文中所说的方法如下：

```shell
sudo dmesg | grep brltty
```

若出现[ 7033.078452] usb 1-13: usbfs: interface 0 claimed by ch341 while 'brltty' sets config #1 则说明驱动被占用

使用sudo apt remove brltty后，重新插拔设备即可

问题探究到底，这个brltty卸载后会不会对以后使用有影响呢？用chatgpt搜索这个软件后，给出的解释如下：

> 在Ubuntu中，Brltty 是一个用于盲人和视力受损人士的文本转换工具。它提供了一个用于显示在Braille终端上的用户界面，这些终端通常由触觉读取器件（如盲文显示器）或语音合成器（如屏幕阅读器）使用。
> Brltty 可以将文本数据转换成 Braille 码，通过串口或并口将其发送到 Braille 终端。它支持多种不同类型的 Braille 终端，包括常见的 VarioUltra、BrailleNote 和 Focus 14/40。
> 除了将文本数据转换为 Braille 码之外，Brltty 还提供了一些其他的辅助功能，如语音反馈、支持多国语言、自动检测插入/拔出设备等。

因此对于非盲人和视力受损人士用处不大，因此卸载后无影响

注意：由于串口是具有权限的，为了确保在后续运行python代码的时候具有程序启动串口的权限，我们这里把端口的权限进行更改

```shell
sudo chmod 777 /dev/ttyUSB0 
```



## 如果docker没权限记得加参数 --privileged