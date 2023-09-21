# IAR下载配置

1. IAR简单介绍
IAR 一般是指一款嵌入式软件的集成开发环境，类似于 MDK-Keil 这款软件。IAR 的官网：

> https://www.iar.com/
>

IAR 对于不同的内核处理器，是对应不同的 IAR 软件的，IAR 到目前为止支持大部分的MCU，比如8051系列、ARM架构系列、MSP430系列、AVR系列等等这些常用的芯片架构。

对于 ARM 架构的芯片，有对应的 IAR Embedded Workbench for ARM 软件平台，因为我主要是使用 ARM 架构芯片，下面安装、注册和使用都是基于这个版本进行介绍的。

2. IAR9.30版本安装和注册
到目前为止，IAR for ARM 已经更新到了9.30以上的版本，我们到IAR官网下载最新版本即可，如下网址：

> [https://www.iar.com/products/architectures/arm/iar-embedded-workbench-for-arm/]

或者使用我下面百度网盘提供的链接进行下载，都是一样的软件，里面还包含的 IAR9.30 以上版本的注册工具。

安装过程其实很简单，就是保持默认选项一路next下去即可，这里不多介绍了，或者参考下面这篇文章进行安装（参考这篇文章进行注册9.30以上版本是不成功的，还需要其他的几个步骤）。

> https://strongerhuang.blog.csdn.net/article/details/52562533
>

注册过程详细介绍：

IAR 是专用的收费软件，这里介绍的注册方法仅供学习使用，请勿用于商业用途。

1、打开 IAR EW for ARM 软件，进入 License Manager 管理菜单。

安装完成之后，桌面是没有IAR软件的快捷方式的，可以到开始菜单中找到 IAR EW for ARM 软件，然后打开（注意：要以管理员方式打开）。第一次打开可能会自动弹出 License 注册界面，我们先不管他，点击取消，然后关闭即可。


![在这里插入图片描述](https://img-blog.csdnimg.cn/4950960d682c4cbda6c30500a274e953.png)

![在这里插入图片描述](https://img-blog.csdnimg.cn/b4376e663f4d440692f30bf6b82798ba.png)

![[外链图片转存失败,源站可能有防盗链机制,建议将图片保存下来直接上传(img-wjU2DXDn-1664116233810)(../picture/image-20220925140402837.png)]](https://img-blog.csdnimg.cn/182ae570d444440da450e83745ba7281.png)

![[外链图片转存失败,源站可能有防盗链机制,建议将图片保存下来直接上传(img-GKKz9b6c-1664116233810)(../picture/image-20220925140728749.png)]](https://img-blog.csdnimg.cn/74e969a44ed34612b2cec2adc9548f6e.png)

![[外链图片转存失败,源站可能有防盗链机制,建议将图片保存下来直接上传(img-qJEav5iU-1664116233810)(../picture/image-20220925140929460.png)]](https://img-blog.csdnimg.cn/5bf8ef5dca1940e9a12542c0b9b62d4f.png)

![[外链图片转存失败,源站可能有防盗链机制,建议将图片保存下来直接上传(img-GqKsJJtc-1664116233811)(../picture/image-20220925141017832.png)]](https://img-blog.csdnimg.cn/47263493e7b840b19060b19a1fb0b295.png)

![[外链图片转存失败,源站可能有防盗链机制,建议将图片保存下来直接上传(img-T2YRvCLP-1664116233812)(../picture/image-20220925141350640.png)]](https://img-blog.csdnimg.cn/fe97e23b213640a79d200f11be208574.png)

![[外链图片转存失败,源站可能有防盗链机制,建议将图片保存下来直接上传(img-NZD9dTvE-1664116233812)(../picture/image-20220925141639476.png)]](https://img-blog.csdnimg.cn/ac3e6d3aece547a1b65c95b02555214e.png)

![[外链图片转存失败,源站可能有防盗链机制,建议将图片保存下来直接上传(img-FKvtAvk5-1664116233812)(../picture/image-20220925142318857.png)]](https://img-blog.csdnimg.cn/65ac707fca0643f182434f73aefae915.png)

![[外链图片转存失败,源站可能有防盗链机制,建议将图片保存下来直接上传(img-dXkNyXj6-1664116233813)(../picture/image-20220925142536639.png)]](https://img-blog.csdnimg.cn/595097cc6fe44698bd679d6f5a185ed0.png)

点击下一步之后，就是会出现 Done 完成的界面了，我们直接点击 Done 即可完成注册。

提示： **the generation feature is not of version 18** 这个信息，说明还没有注册成功。这时我们还需要运行一个小工具，如下：

![[外链图片转存失败,源站可能有防盗链机制,建议将图片保存下来直接上传(img-nXwVIDVn-1664116233813)(../picture/image-20220925143055602.png)]](https://img-blog.csdnimg.cn/bf9fbf09566240f4b5aa1f8c5306baa4.png)

把IAR软件先关闭了，然后把上面的这个工具软件复制到IAR的下面三个安装目录：

```shell
run licpatcher64.exe from directories:
C:\Program Files\IAR Systems\Embedded Workbench 9.0\430\bin\
C:\Program Files\IAR Systems\Embedded Workbench 9.0\common\bin\
```

在这三个目录中，都运行一遍 licpatcher64a.exe 这个工具软件。

12、再次打开IAR for ARM 软件，确认是否注册成功。

进入到 License Manager 管理界面，如果注册状态是下面这样，说明注册成功了。

![[外链图片转存失败,源站可能有防盗链机制,建议将图片保存下来直接上传(img-U66IuXrb-1664116233814)(../picture/image-20220925143625915.png)]](https://img-blog.csdnimg.cn/5a9255b1ac094c568084137acebd24d9.png)