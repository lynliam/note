# Git Error :Your local changes to the following files would be overwritten by merge

一、错误原因

团队其他成员修改了某文件并已提交入库，在pull之前修改了本地该文件，等修改完代码再pull时，这时会报错如下错误：error: Your local changes to the following files would be overwritten by merge

二、解决方案
根据是否要保存本地修改，有以下三种解决方案

```shell
2.1 本地代码commit后再pull
//先把当前修改的工作区内容提交了
git add .
git commit
//拉取最新代码，这里就相当于两个已提交分支的合并了，有冲突解决冲突，没冲突就pull成功
git pull
//解决完冲突后，继续完成自己的本地代码
//完成以后，add/commit/push三连到远程库
git add
git commit
git push



***这样就实现了开发过程中，将远程最新改动合到了我本地，然后我基于最新代码接着开发
***该方法的缺点是会多出一条额外提交记录（pull之前的这次提交）

      
      2.2  保留修改

执行以下三条命令
git stash #封存修改
git pull origin master 
git stash pop #把修改还原
注：
git stash：备份当前工作区内容，从最近的一次提交中读取相关内容，让工作区保证和上次提交的内容一致。同时，将当前工作区内容保存到Git栈中
git pull：拉取服务器上当前分支代码
git stash pop：从Git栈中读取最近一次保存的内容，恢复工作区相关内容。同时，用户可能进行多次stash操作，需要保证后stash的最先被取到，所以用栈（先进后出）来管理；pop取栈顶的内容并恢复

git stash list：显示Git栈内的所有备份，可以利用这个列表来决定从那个地方恢复。
git stash clear：清空Git栈

      2.3 废弃修改
核心思想就是版本回退，具体命令如下
git reset --hard 
git pull origin master
```