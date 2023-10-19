# Git

------



* ### 简介

  * 版本控制：开发过程中用于管理我们对文件，目录或工程登内容的修改历史，方便查看更改激励，备份恢复以前版本软件
    * 管理多人协同开发
    * Git以快照流的方式进行版本控制

  * 常见的版本控制：
    * Git
    * SVN
    * CVS
    * VSS
    * TFS

  * 版本控制分类
    * 本地版本控制
    * 集中版本控制（SVN）
      * 所有的版本数据都保存在服务器上，协同开发者从服务器上同步更新
      * 所有版本数据存在服务器上
    * **分布式版本控制**
      * 所有版本信息仓库全部同步到本地的每个用户。可以离线在本地提交，只需在联网是PUSH到服务器上。    
    * **git和svn的区别**
      * git可以直接看到更新了哪些代码和文件

  * 三种状态：
    * committed（已提交）
    * modified（已修改）
    * staged（已暂存）

  * 三种区域
    * 工作目录
    * 暂存区域
    * Git仓库

  * 工作流程

    ![image](/media/lynliam/data/markdown/Git/images/v2-bdbe1c116582f534fe567089f87be824_1440w.webp)

    

------



* ### 配置








------

* ### 使用

  ```shell
  git init #初始化
  git remote add origin https://github.com/lynliam/xxx.git
  git add .   #添加本地所有代码
  git commit -m "提交备注"
  git push origin 【分支名称】  #提交到远程仓库
  ```

  

------

* ### 问题

### 关于Support for password authentication was removed on August 13, 2021报错的解决方案

要去GitHub上把密码换成token

***token会过期***

```shell
git remote set-url origin https://<your_token>@github.com/<USERNAME>/<REPO>.git
https://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@github.com/lynliam/note.git
#  mytoken：
#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
https://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@github.com/lynliam/note.git

#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
```

### 对远程仓库和本地仓库进行合并



~sds

```shell
#慎用！！！！！！！！
git pull origin master --allow-unrelated-histories
```

### git回退到上一个commit

```shell
#查看commit id
git log

#回退
#回退到某个版本，只回退了commit的信息，如果还要提交，直接commit即可（修改的内容变成未add的状态），索引（暂存区）和工作目录的内容是不变的，在三个命令中对现有版本库状态改动最小。
git reset --soft <commit id>

#彻底回退到某个版本，本地的源码也会变为上一个版本的内容，所有修改的内容都会丢失， (修改的代码 不会变成未add的状态)。索引（暂存区）内容和工作目录内容都会变给定提交时的状态。
git reset --hard <commit id>
```



### git push 报错：

```shell
git push错误：RPC 失败。HTTP 408 curl 18 Transferred a partial file
send-pack: unexpected disconnect while reading sideband packet
```

解决方法：

```shell
#原因分析：http缓存不够
git config --global http.postBuffer 524288000
```



### git 将master合并到main分支

解决方案

    找到项目文件夹，右键选择git bash，在命令行输入以下代码：
    
    git checkout main #将git切换到main分支
    git merge master #将master分支的内容迁移到main

如果合并成功可直接跳到4，如果遇到了“fatal: refusing to merge unrelated histories”看2。

    “fatal: refusing to merge unrelated histories”解决方法

可能是因为两个分支的仓库不一样？我不确定是否为这个原因，但解决方案如下：在上面的语句后面加上 --allow-unrelated-histories，即

git merge master --allow-unrelated-histories

如果合并成功可直接跳到4，如果遇到了“Please enter a commit message to explain why this merge is neccesary”看3。

    “Please enter a commit message to explain why this merge is neccesary”解决方法

这个意思是让你写一下为什么你非得合并，没有什么用。

    不想写的话：键盘上敲“:wq”然后回车。
    
    想写的话：键盘上敲“i”进入插入模式-写完后键盘上敲“ESC”退出插入模式-键盘上敲“:wq”然后回车。
    
    回到git bash的界面后在命令行输入以下代码：
    
     git push origin main #把合并结果push到github
     git branch -d master #删除master分支



### git 强制推送覆盖远程仓库

> 报错：
>
> ```shell
>  git push origin main
> To https://github.com/lynliam/note.git
>  ! [rejected]        main -> main (fetch first)
> 错误：无法推送一些引用到 'https://github.com/lynliam/note.git'
> 提示：更新被拒绝，因为远程仓库包含您本地尚不存在的提交。这通常是因为另外
> 提示：一个仓库已向该引用进行了推送。再次推送前，您可能需要先整合远程变更
> 提示：（如 'git pull ...'）。
> 提示：详见 'git push --help' 中的 'Note about fast-forwards' 小节。
> ```

```shell
git push origin main -f
```



### git  push到另一个仓库

```shell
git remote                      											     #查看当前远程仓库
git remote add newOrigin main                                                        #设置一个仓库名称newOrigin   和分支  main
git remote set_url newOrigin https://<your_token>@github.com/<USERNAME>/<REPO>.git   #设置url地址
git pull newOrigin main --allow-unrelated-histories                                  #与远程仓库合并
git push newOrigin main                                                              #push 到远程仓库
```



