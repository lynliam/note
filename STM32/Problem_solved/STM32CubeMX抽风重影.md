总的问题是微星小飞机的[OSD](https://so.csdn.net/so/search?q=OSD&spm=1001.2101.3001.7020)造成的，就是这个家伙：

![img](STM32CubeMX抽风重影.assets/b0563c1ec5634f48ae0fc46d85aa9f39.png)

然后可以在里面添加特定应用的设置，添加运行STM CubeMX的Java程序：

![img](STM32CubeMX抽风重影.assets/0810396c0cfc418db18d54bda0815d9e.png)

一般都在安装路径的这个地方：

..\STMicroelectronics\[STM32Cube](https://so.csdn.net/so/search?q=STM32Cube&spm=1001.2101.3001.7020)\STM32CubeMX\jre\bin

![img](STM32CubeMX抽风重影.assets/c518485197fb4de69fc6a6ba4aae9cb3.png)

之后把这个关了。

![img](STM32CubeMX抽风重影.assets/9d188f37bcde45658b6a5261babf4888.png)

**它就不会再抽风了**（好诶！！！）