## MongoDB

### 安装

1. 查找 [mongo 镜像](https://hub.docker.com/_/mongo/tags)

查看是否支持 arm64 芯片，复制命令

2. 拉取镜像到本地

```sh
$ docker pull mongo:latest
```

3. 启动镜像

```sh
$ docker run -itd --name mongo -p 27017:27017 mongo
```

参数说明你：

> -name mongo：设置容器名称为mongo
>
> -p 27017:27017 ：映射容器服务的 27017 端口到宿主机的 27017 端口。外部可以直接通过 宿主机 ip:27017 访问到 mongo 的服务

4. 使用数据库工具连接

连接名：自定义（mongo-docker）

连接：Standalone

主机：localhost

端口：27017

然后测试，连接。