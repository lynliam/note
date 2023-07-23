# 如何用IAR for msp430烧写代码到msp430F5529

新建工作区：

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200413175530979.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L1NFTEZUSFJPTkU=,size_16,color_FFFFFF,t_70)

新建工程，点击Projec菜单下的Create New Project，

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200413175544569.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L1NFTEZUSFJPTkU=,size_16,color_FFFFFF,t_70)

在弹出的对话框中Tool chain选择msp430（一般为默认），选择C文件夹的main，点击ok。

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200413175609324.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L1NFTEZUSFJPTkU=,size_16,color_FFFFFF,t_70)

### ==保存工作区，File->Save Project,==  不保存无法烧录，烧录时候找不到.eww格式文件！！！！！

![在这里插入图片描述](https://img-blog.csdnimg.cn/2020041318003282.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L1NFTEZUSFJPTkU=,size_16,color_FFFFFF,t_70)

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200413180124189.png)

导入库函数版emptyproject 文件：

文件在同目录下面的

```shell
00_emptyProject.eww
```

> # How to include driverlib into your existing IAR project
>
> To add driver library to an existing project, right click project click on Add Group - "**driverlib**"
>
> 文件在同目录下的zip文件
>
> Now click Add files and browse through driverlib folder and add all source files of the family the device belongs to.
>
> ![image-20230712225551432](IAR烧写程序.assets/image-20230712225551432.png)
>
> ![image-20230712225637773](IAR烧写程序.assets/image-20230712225637773.png)
>
> ![image-20230712225651520](IAR烧写程序.assets/image-20230712225651520.png)
>
> 
>
> # How to create a new IAR project that uses Driverlib
>
> ![image-20230712225448512](IAR烧写程序.assets/image-20230712225448512.png)
>
> ![image-20230712225503183](IAR烧写程序.assets/image-20230712225503183.png)
>
> ![image-20230712225519270](IAR烧写程序.assets/image-20230712225519270.png)



options配置
3.1鼠标右键点击新建project，点击Options

![在这里插入图片描述](https://img-blog.csdnimg.cn/2020041318103912.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L1NFTEZUSFJPTkU=,size_16,color_FFFFFF,t_70)

选择General Options中的Target的Device，选择对应芯片型号

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200413181530186.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L1NFTEZUSFJPTkU=,size_16,color_FFFFFF,t_70)

3.3在Debugger的Setup的Driver选择FET Debugger。

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200413181635712.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L1NFTEZUSFJPTkU=,size_16,color_FFFFFF,t_70)

FET Debugger的Setup的Connection选择Texas Instrument USB-IF，点OK。

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200413181758414.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L1NFTEZUSFJPTkU=,size_16,color_FFFFFF,t_70)

点击右上角的Make编辑，没有错误和警告。

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200413182507363.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L1NFTEZUSFJPTkU=,size_16,color_FFFFFF,t_70)

用USB连接电脑和板子，点击右上角的绿色按钮Download and Debug。

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200413182644805.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L1NFTEZUSFJPTkU=,size_16,color_FFFFFF,t_70)

仿真界面如图，点击右上角的Go，程序就能运行了。

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200413183306337.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L1NFTEZUSFJPTkU=,size_16,color_FFFFFF,t_70)