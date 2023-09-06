# Docker

## 安装

[Docker 官网](https://docs.docker.com/desktop/install/mac-install/)

Apple silicon 最好安装 Rosetta 2.

```sh
$ softwareupdate --install-rosetta
```



**或者使用 Homebrew 安装**

```sh
$ brew cask install docker
```



## 配置

### 设置 Docker 默认镜像为阿里云仓库

打开 [阿里云镜像官网](https://cr.console.aliyun.com/cn-hangzhou/instances/mirrors) 扫码登录，复制加速器地址

打开 **DockerDesktop**，点击右上角设置小齿轮，并点击Docker Engine，将**registry-mirrors**下的网址替换成加速器地址，最后点击Apply&restart

```json
{
  "builder": {
    "gc": {
      "defaultKeepStorage": "20GB",
      "enabled": true
    }
  },
  "experimental": false,
  "features": {
    "buildkit": true
  },
  "registry-mirrors": [
     "https://....mirror.aliyuncs.com"
  ]
}
```



## 常用命令

查看已安装的镜像

```sh
open /Applications/Docker.app # mac启动docker服务

docker images # 查看镜像

docker rmi 镜像id # 删除镜像

docker ps # 显示所有运行中的容器

docker ps -a # 显示所有容器

docker rm 容器 ID # 或名称 删除容器

docker start 容器 ID 或名称 # 启动指定容器

docker stop 容器 ID 或名称 # 停止指定容器

docker restart 容器 ID 或名称 # 重启指定容器

docker run -it 容器 ID bash  # 运行容器并进入容器内

exit # 退出
```





## docker镜像管理

1. 获取镜像（默认的 docker 仓库是 [dockerhub](https://hub.docker.com/)）

   ```sh
   # 查看本地镜像
   $ docker images
   $ docker image ls
   
   # 搜索镜像
   $ docker search 镜像名:tag		# tag就是具体的标签版本
   $ docker search centos
   
   # 下载镜像
   $ docker pull centos		# 默认是 centos:latest
   $ docker pull centos:7.8.2009 # https://hub.docker.com/_/centos 在这里找标签信息
   
   # docker 资源目录
   $ docker info |grep Root
   $ ls /var/lib/docker/image/overlay2/imagedb/content/sha256/-l
   
   # 使用镜像生成容器
   # -it 开启一个交互式终端  --rm 容器退出时删除该容器
   $ docker run -it --rm centos:centos7 bash
   
   # 退出
   $ exit
   ```
   
2. 查看镜像

   ```sh
   $ docker images
   $ docker images centos #查看某类镜像
   $ docker images ubuntu
   $ docker images nginx
   
   # 只列出
   $ docker images -q
   
   # 表格形式、格式化显示想要的信息
   $ docker images --format "{{.ID}}\t{{.Repository}}\t{{.Tag}}"
   ```


3. 删除镜像

   ```sh
   # 删除容器
   $ docker rm 容器id
   
   # 删除镜像（被删除的镜像不能有依赖的容器记录）
   $ docker rmi 镜像id｜名称等
   ```

4. 综合管理

   ```sh
   # 批量删除镜像，慎用
   $ docker rmi `docker images -aq`
   # 批量删除容器
   $ docker rm `docker ps -aq`
   
   # 导出镜像
   $ docker image save centos:centos7 > /opt/centos7.tgz
   
   # 导入镜像
   $ docker image load -i /opt/centos7.tgz
   
   # 查看docker服务的信息
   $ docker info
   # 查看镜像的信息
   $ docker image inspect 镜像id 
   ```

   

## docker容器管理

`docker run` 等于创建 + 启动

> docker run 镜像名，如果镜像在本地不存在，则会在线下载该镜像

**注意：容器内的进程必须处于前台运行状态，否则容器就会直接退出，**如果容器内，什么事也没做，容器也会挂掉，容器内，必须有一个进程在前台运行。

运行 nginx 基础镜像，没有运行任何程序，因此容器直接挂掉。

```sh
# 这样运行，会产生多条容器记录，且容器内没有程序在跑，因此直接就挂了
$ docker run centos:centos7

# 运行容器，并进入容器内执行某个命令
$ docker run -it centos:centos7 sh

$ sh-4.2# cat /etc/redhat-release 
CentOS Linux release 7.9.2009 (AltArch)

# 开启一个容器，并运行某个程序，属于前台运行，会卡住终端
$ docker run centos:centos7 ping baidu.com
PING baidu.com (39.156.66.10) 56(84) bytes of data.

# 运行一个容器，docker ps 可以看到容器
# -d：让容器后台运行（针对宿主机而言）
$ docker run -d centos:centos7 ping baidu.com

# 丰富 docker 运行的参数
# --rm: 容器运行结束后删除运行记录
# --name: 对运行容器命名
$ docker run -d --rm --name centos_test centos:centos7 ping baidu.com

# 查看容器日志
$ docker logs -f
# 查看最后5条日志
$ docker logs 容器id | tail -5

# 进入正在运行的容器内
$ docker exec -it 容器id bash

# 查看容器的运行信息
$ docker container inspect 容器id

# 容器的端口映射
$ docker run -d --name nginx_test -p 80:80 nginx
# 查看容器端口转发情况
$ docker port 容器id
# 随机端口映射
$ docker run -d --name nginx_test -P nginx

# 容器的提交(这样可以把容器打包为镜像，在运行镜像，就携带了之前容器已安装的内容，方便复用、分发)
$ docker commit 容器id 新镜像名
```



## dockerfile

### dockerfile 指令

> FROM  这个镜像来于哪（指定基础镜像）
>
> MAINTAINER  告诉别人，谁负责养它（指定维护者信息，可以没有）
>
> RUN  你想让它干啥（在命令前加上 RUN 即可）
>
> ADD  添加宿主机的文件到容器内，还多了一个自动解压多功能
>
> WORKDIR 设置当前工作目录
>
> VOLUME  设置卷，挂载主机目录
>
> EXPOSE  指定对外暴露的端口
>
> CMD  指定容器启动后执行的命令















