## Nginx

### 安装

1. 查找 [Nginx 镜像](https://hub.docker.com/_/nginx/tags)

```sh
$ docker pull nginx
```

2. 运行容器

```sh
$ docker run --name nginx-docker -p 9001:80 -d nginx
```

此时就可以访问 nginx 了 `http://本机ip:9001`

3. 修改配置

docker拉取下来的nginx配置文件路径

> 日志文件位置：/var/log/nginx
> 配置文件位置：/etc/nginx
> 资源存放的位置：/usr/share/nginx/html

接下来在本地创建对应的目录，并将目录挂载到docker容器的nginx上：

```sh
$ mkdir -p /Users/digiqal/nginx/conf
$ mkdir -p /Users/digiqal/nginx/log
$ mkdir -p /Users/digiqal/nginx/html
```

生成临时镜像：

```sh
$ docker run --name nginx-docker -p 9001:80 -d nginx
```

容器配置复制到宿主机：

```sh
$ docker cp nginx-docker:/etc/nginx/nginx.conf /Users/digiqal/nginx/conf/nginx.conf
$ docker cp nginx-docker:/etc/nginx/conf.d /Users/digiqal/nginx/conf/conf.d
$ docker cp nginx-docker:/usr/share/nginx/html /Users/digiqal/nginx/
```

删除临时镜像：

```sh
$ docker ps -a
$ docker stop nginx-docker
$ docker rm nginx-docker
```

创建正式 nginx：

```sh
$ docker run \
	--name nginx-docker \
	-p 9001:80 \
	-v /Users/digiqal/nginx/conf/nginx.conf:/etc/nginx/nginx.conf:ro \
	-v /Users/digiqal/nginx/conf/conf.d:/etc/nginx/conf.d \
	-v /Users/digiqal/nginx/html:/usr/share/nginx/html \
	-v /Users/digiqal/nginx/log:/var/log/nginx \
	-d nginx
```



### 常用命令

```sh
docker stop nginx-docker
docker start nginx-docker
docker restart nginx-docker
```





### 部署vue项目

拷贝项目文件到 webapp 目录下

`/Users/digiqal/nginx/html/webapp`



修改配置：

```sh
http {
		...

    server {
        listen       80;
        server_name  localhost;
        location / {
            root   /usr/share/nginx/html/webapp;
            index  index.html index.htm;
            try_files $uri $uri/ /index.html;
        }
        error_page  404 /40x.html;
        location = /40x.html {
            root   /usr/share/nginx/html;
        }

        # 下面配置Tomcat或WAS服务器的地址，服务程序会自动进行代理转发
        # 下面就是代理转发，当遇到请求中带有api时就换将api前面的内容，包括api，替换成下面的proxy_pass，proxy_pass地址输入的是后台接口的IP地址，比如我需要联调的后台接口地址是：http://10.120.189.181:8080/。
#        location ^~ /api/ {
#            proxy_pass http://10.120.189.181:8080/;
#        }
    }

    include /etc/nginx/conf.d/*.conf;
}
```

重启服务

