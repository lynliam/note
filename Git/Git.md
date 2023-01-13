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

#### 关于Support for password authentication was removed on August 13, 2021报错的解决方案

要去GitHub上把密码换成token

```shell
git remote set-url origin https://<your_token>@github.com/<USERNAME>/<REPO>.git

#  mytoken：
#  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
```

对远程仓库和本地仓库进行合并

```shell
git pull origin master --allow-unrelated-histories
```

