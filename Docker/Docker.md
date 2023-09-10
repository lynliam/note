# Docker

## CTL

### 镜像基本命令：

#### docer images

```bash
docker images [options] [respository[:TAG]]
-a         #显示全部
-q         #只显示 <the-container-id>


lynliam@lynliam-Legion-Y7000P-IAH7:~$ docker images
REPOSITORY      TAG       IMAGE  <the-container-id>       CREATED       SIZE
bestwu/wechat   latest    e0d1be7e13bf   2 years ago   865MB
```

#### docker search

```shell

docker search [OPTIONS] TERM

Search the Docker Hub for images

Options:
  -f, --filter filter   Filter output based on conditions prov <the-container-id>ed
      --format string   Pretty-print search using a Go template
      --limit int       Max number of search results (default 25)
      --no-trunc        Don't truncate output

# example:
# --filter=STARS=5000
```

#### docker pull： 采用分层下载方式（模块化，联合文件系统）

```shell
docker pull [OPTIONS] NAME[:TAG|@DIGEST]
Options:
  -a, --all-tags                Download all tagged images in the repository
      --disable-content-trust   Skip image verification (default true)
      --platform string         Set platform if server is multi-platform
                                capable
  -q, --quiet                   Suppress verbose output

#不写tags 就默认下载最新
```

#### docker rmi

```shell
docker rmi [OPTIONS] IMAGE [IMAGE...]

Remove one or more images

Options:
  -f, --force      Force removal of the image
      --no-prune   Do not delete untagged parents
# example:
# docker rmi -f $(docker images -aq)
```

------



### 容器命令：

#### 新建容器并启动：

```shell
 docker run [option] images

--name="Name"
-d              #后台端口运行
-it             #交互模式运行
-p              #指定容器端口
-P              #随机指定端口
      --publish-all                    Publish all exposed ports to
                                       random ports
      --pull string                    Pull image before running
                                       ("always"|"missing"|"never")
                                       (default "missing")
      --read-only                      Mount the container's root
                                       filesystem as read only
      --restart string                 Restart policy to apply when a
                                       container exits (default "no")
      --rm                             Automatically remove the container
                                       when it exits
      --runtime string                 Runtime to use for this container
      --security-opt list              Security Options
      --shm-size bytes                 Size of /dev/shm
      --sig-proxy                      Proxy received signals to the
                                       process (default true)
      --stop-signal string             Signal to stop a container
                                       (default "SIGTERM")
      --stop-timeout int               Timeout (in seconds) to stop a
                                       container
      --storage-opt list               Storage driver options for the
                                       container
      --sysctl map                     Sysctl options (default map[])
      --tmpfs list                     Mount a tmpfs directory
```

#### 列出所有运行的容器：

```shell
docker ps 命令
      #列出正在运行的容器
-a    #列出正在运行的容器和历史运行过的容器
-q    #只显示编号
-n=?  #显示最近创建的容器
```

#### 退出容器：

```shell
exit            #直接退出并关闭
Ctrl + p + q    #直接退出后台运行
```

#### 删除容器：

```shell
docker rm  <the-container-id>                      #删除指定容器，要删运行中的容器使用-f
docker rm -f $(docker ps -aq)
```

#### 启动和停止容器:

```shell
docker start  <the-container-id>
docker restart  <the-container-id>
docker stop  <the-container-id>
docker kill  <the-container-id>
```



```
docker run -d -it --name mcl --network host -v ${PWD}/qq/plugins:/app/plugins -v ${PWD}/qq/config:/app/config -v   ${PWD}/qq/data:/app/data -v ${PWD}/qq/bots:/app/bots --restart unless-stopped kagurazakanyaa/mcl:latest
```

### 常用其他命令：

#### 后台启动容器

```shell
docker run -d [images]

#当docker发现没有前台应用就会自动停止
```

#### 日志

```shell
 docker logs [OPTIONS] CONTAINER

Fetch the logs of a container

Options:
      --details        Show extra details prov <the-container-id>ed to logs
  -f, --follow         Follow log output
      --since string   Show logs since timestamp (e.g.
                       2013-01-02T13:23:37Z) or relative (e.g. 42m for 42
                       minutes)
  -n, --tail string    Number of lines to show from the end of the logs
                       (default "all")
  -t, --timestamps     Show timestamps
      --until string   Show logs before a timestamp (e.g.
                       2013-01-02T13:23:37Z) or relative (e.g. 42m for 42
                       minutes)
                       
# docker logs -tf --tail 10 ded5fds98e6
```

#### 查看容器中进程信息：

```shell
docker top CONTAINER [ps OPTIONS]

#Display the running processes of a container

```

#### 查看容器信息：

```shell
docker inspect  <the-container-id>
#查看容器信息
```

#### 进入当前正在运行的容器：

  ```shell
  #以交互模式进入容器
  docker exec -it 5ac05bf74fdb /bin/bash
  #以交互模式进入
  docker attach  <the-container-id> /bin/bash
  正在执行当前的代码
  
  #docker exec      开启一个新终端，可以在里面操作
  # docker attach   进入正在执行的终端，不会启动新的进程
  ```

![点击查看图片来源](/media/lynliam/data/markdown/Docker/Docker.assets/2363254-20211002145236621-74451512.png)

![点击查看图片来源](/media/lynliam/data/markdown/Docker/Docker.assets/1512400-20200709142410215-1511709418.png)

## 容器数据卷：

==实现数据持久化==，将容器内的目录挂载到本地上实现数据共享。

```shell
docker run -it -v 容器内目录:本地目录
```

### 具名挂载&&匿名挂载：

```shell
#匿名挂载
docker run -d -P --name nginx01 -v /etc/nginx nginx
#具名挂载
docker run -d -P -v name01:/etc/nginx nginx 
```



## DockerFile

```shell
docker history <docker-id>
```





## concept

### Dockerfile

 A Dockerfile is simply a text-based file with no file extension. A  Dockerfile contains a ***script of instructions*** that Docker uses to create a container image.

### Container volumes

[Volumes](https://docs.docker.com/storage/volumes/) provide the ability to **connect** specific filesystem paths of  the **container** back to the **host machine**. If a directory in the container is mounted, changes in that directory are also seen on the host machine.

```shell
# create a volume 
$ docker volume create todo-db
# Stop and remove the todo app container
$ docker rm -f <id>
# using --mount option
$ docker run -dp 3000:3000 --mount type=volume, src=todo-db,target=/etc/todos getting-started

#dive into the volume 
docker volume inspect todo-db
[
    {
        "CreatedAt": "2019-09-26T02:18:36Z",
        "Driver": "local",
        "Labels": {},
        "Mountpoint": "/var/lib/docker/volumes/todo-db/_data",
        "Name": "todo-db",
        "Options": {},
        "Scope": "local"
    }
]
```

### bind mounts:

The difference between volume and bind mounts is that  the container sees the **changes** you make to the code **immediately**, as soon as you save a file. 

<img src="/home/lynliam/.config/Typora/typora-user-images/image-20230307214756966.png" alt="image-20230307214756966" style="zoom:50%;" />

If you’re following these steps on Windows, make sure to use PowerShell and not command prompt (`cmd`).

1. Open a terminal and make sure your current working directory is in the `app` directory of the getting started repository.
2. Run the following command to start `bash` in an `ubuntu` container with a bind mount.

```shell
 docker run -it --mount type=bind,src="$(pwd)",target=/src ubuntu bash
```

The `--mount` option tells Docker to create a bind mount, where `src` is the current working directory on your host machine (`getting-started/app`), and `target` is where that directory should appear inside the container (`/src`).



## Tips:

1. Update the application  :   you aren’t able to start the new container while your old container is still running.
2. Share the application :   

```shell
# first step:
docker push docker/getting-started
 The push refers to repository [docker.io/docker/getting-started]
 An image does not exist locally with the tag: docker/getting-started
# To fix this, you need to “tag” your existing image you’ve built to give it another name.
# YOUR-USER-NAME is your Docker ID
docker tag getting-started YOUR-USER-NAME/getting-started
```

3. Persist the DB(DataBase):

The container’s filesystem: the data is being **wiped clean** every single time we launch the container.

