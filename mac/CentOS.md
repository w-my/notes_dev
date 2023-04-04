# CentOS

## Max VMware 装 CentOS 

[CentOS下载](https://www.centos.org/download/)，选择 `ARM64(aarch64)` 



### VMware 安装 CentOS

https://zhuanlan.zhihu.com/c_1147221774730076160?utm_id=0

选择下载的镜像文件，选择配置 2+20 即可，执行安装 Install Centos7。

=> 选择语言 

=> 选择安装软件：GNOME桌面 + 开发工具

=> 安装位置：我要配置分区，手动分区，选标准分区，添加挂载点 /boot(200MiB)，然后再添加挂载点：swap(4096MiB) 和 /(15.8GiB)，然后点完成。或者使用默认自动分区。

=> 关闭 kdump（一般底层开发才用）；

=> 配置打开以太网，例如：

​		IPv4：（手动）

​				地址：192.168.56.102

​				子网掩码：255.255.255.0

​				网关：192.168.56.2

​				DNS：192.168.56.2

=> 设置root用户密码

=> 安装完成后，重启，接受许可，完成配置

=> 配置root账号等信息，完成后进入系统 *digiqal0*



## Mac terminal 连接 CentOS

需要开放防火墙端口

```sh
$ ssh -l root *.*.*.*
```

端口默认22，没有修改。

如果改变端口：

```sh
$ ssh -p 448(端口) -l root(用户名) *.*.*.*
```



## Mac terminal 传文件到 ContOS

```sh
$ scp -P 22 ./Downloads/a.png root@192.168.56.102:/usr/local
```

> 22：为服务器端口号
>
> ./Downloads/a.png ：为本地文件
>
> root：服务器用户名
>
> 192.168.56.102：服务器地址
>
> /usr/local：保存文件到的目标目录



**问题**

1. ssh 连接的时候 Host key verification failed .

解决方法：

```sh
$ vi ~/.ssh/known_hosts
```

进入此目录，删除192.168.56.102的相关rsa的信息即可.

或者删除这个文件:

```sh
$ cd ~/.ssh/
$ rm known_hosts
```



## CentOS 安装 Nginx

### 安装

1. 依次执行以下命令，安装依赖

```sh
$ yum install gcc-c++
$ yum install -y pcre pcre-devel
$ yum install -y zlib zlib-devel
$ yum install -y openssl openssl-devel
```

2. 下载 Linux 版本的 [Nginx](https://nginx.org/en/download.html) 安装包

​		e.g.：Stable versions --> nginx-1.22.1

3. 安装

```sh
$ cd /usr/local
$ mkdir nginx
```

将下载的 nginx 安装包采用finalshell或者Xftp软件等上传至/usr/local/nginx下：

```sh
$ scp -P 22 ./Downloads/nginx-1.22.1.tar.gz root@192.168.56.102:/usr/local/nginx/
```

进入目录，解压 nginx 包：

```sh
$ cd /usr/local/nginx
$ tar -zxvf nginx-1.22.1.tar.gz
```

执行初始化配置：

```sh
$ cd nginx-1.22.1
$ ./configure
```

执行编译：

```sh
$ make
```

执行安装：

```sh
$ make install
```

4. 运行 nginx

```sh
$ whereis nginx   # 查找安装路径
nginx: /usr/local/nginx   # 返回路径
```

```sh
$ cd /usr/local/nginx   # 进入安装路径
$ ./sbin/nginx   # 运行
```

查看运行是否成功：

```sh
$ ps -ef | grep nginx
root     19735     1  0 14:30 ?        00:00:00 nginx: master process ./sbin/nginx
nobody   19736 19735  0 14:30 ?        00:00:00 nginx: worker process
root     19738 16629  0 14:31 pts/1    00:00:00 grep --color=auto nginx
```

5. 浏览器 ip:80 访问 nginx

看到 `Welcome to nginx!` 说明成功了。



### 无法访问

无法访问：

```sh
# 关闭防火墙
$ systemctl stop firewalld.service
# 或
# 查询端口是否开放
$ firewall-cmd --query-port=80/tcp
# 开放80端口
$ firewall-cmd --permanent --add-port=80/tcp
# 移除端口
$ firewall-cmd --permanent --remove-port=8080/tcp
# 重启防火墙(修改配置后要重启防火墙)
$ firewall-cmd --reload
```



### 常用命令

```sh
$ cd /usr/local/nginx   # 进入安装路径
$ ./sbin/nginx   # 启动
$ ./sbin/nginx -s reload   # 重载
$ ./sbin/nginx -s stop   # 关闭
$ ./sbin/nginx -s quit   # 优雅关闭（当请求被处理完成之后才关闭）
```

```sh
$ ps -aux | grep nginx      # 查看nginx的进程
$ kill -quit 进程号          # 停止某进程，比较安全的退出
$ kill -term 进程号					# 强制退出  
$ kill -9 进程号							# 强制退出
```



### 修改 nginx 的监听端口

```sh
$ cd /usr/local/nginx/
$ vim conf/nginx.conf
```

```
##############################################
把
    #gzip  on;

    server {
        listen       80;
改为
    #gzip  on;

    server {
        listen       8080;
```

```sh
$ ./sbin/nginx -s reload
```

用 `ip:8080` 测试访问。



## Nginx 部署 Vue 应用

### 部署

打包好的 dist 文件压缩后，上传到服务器 html 目录下：

```sh
$ scp -P 22 ./Downloads/webapp.zip root@192.168.56.102:/usr/local/nginx/html
```

解压缩

```sh
$ unzip webapp.zip
```

修改 `nginx.conf` 配置

```sh
$ cd /nginx
$ vim conf/nginx.conf
```

修改如下 `listen` `server_name` `location-root` 配置项：

```
    server {
        listen       9001; # 修改端口号
        server_name  www.webapp.com; # 修改域名

        #charset koi8-r;

        #access_log  logs/host.access.log  main;

        location / {
            root   html/webapp; # 修改项目目录
            index  index.html index.htm;
        }
```

保存后，重启 nginx

```sh
$ ./sbin/nginx -s reload
```

重新访问地址 192.168.56.102 就是部署好的项目了。



### 更新部署

1. 上传新包 `webapp.zip` 到服务器

```sh
$ scp -P 22 ./Downloads/webapp.zip root@192.168.56.102:/usr/local/nginx/html
```

2. 连接服务器并进入 `html` 目录

```sh
$ ssh -l root 192.168.56.102
$ cd /usr/local/nginx/html
```

3. 重命名原目录

```sh
$ mv webapp webapp20230101
```

4. 解压新项目

```sh
$ unzip webapp.zip
```

5. 重启 nginx

```sh
$ ./sbin/nginx -s reload
```

然后就可以刷新访问了：`192.168.56.102:9001`





## MongoDB

### 部署

[MongoDB 下载地址](https://www.mongodb.com/try/download/community-kubernetes-operator)

1. 安装依赖

```sh
$ yum -y install libcurl openssl
$ yum install -y libcurl openssl xz-libs
```

2. 下载 mongodb 包

```sh
$ cd /usr/src
[root@localhost src]$ wget https://fastdl.mongodb.org/linux/mongodb-linux-x86_64-rhel70-6.0.5.tgz
[root@localhost src]$ wget https://fastdl.mongodb.org/linux/mongodb-linux-aarch64-rhel82-6.0.5.tgz

wget https://fastdl.mongodb.org/linux/mongodb-linux-x86_64-rhel70-4.0.28.tgz
```

3. 解压包

```sh
[root@localhost src]$ tar xf mongodb-linux-x86_64-rhel70-6.0.5.tgz
[root@localhost src]$ mv mongodb-linux-x86_64-rhel70-6.0.5 /usr/local/mongodb
```

4. 创建数据存储目录和日志文件目录

```sh
$ mkdir -p /usr/local/mongodb/data/db
$ mkdir -p /usr/local/mongodb/logs
$ touch /usr/local/mongodb/logs/mongodb.log
chmod 777 /usr/local/mongodb/logs
chmod 777 /usr/local/mongodb/db
```

5. 编辑 MongoDB 启动配置文件

```sh
$ cd /usr/local/mongodb/bin
$ vim mongodb.conf
#数据存储目录
dbpath=/usr/local/mongodb/data/db
#日志文件目录
logpath=/usr/local/mongodb/logs/mongodb.log
#后台运行
fork=true
auth=true
bind_ip=0.0.0.0
```

**参数说明**

| **参数**       | **参数说明**                        |
| :------------- | :---------------------------------- |
| **–dbpath**    | 数据存放路径                        |
| **–logpath**   | 日志文件路径                        |
| **–logappend** | 日志输出方式                        |
| **–port**      | 启用端口号                          |
| **–fork**      | 在后台运行                          |
| **–auth**      | 是否需要验证权限登录 (用户名和密码) |
| **–bind_ip**   | 限制访问的 ip                       |
| **–shutdown**  | 关闭数据库                          |

6. MongoDB 的可执行文件位于 bin 目录下，需要将其添加到 PATH 路径中

```sh
$ vim /etc/profile
export MONGODB_HOME=/usr/local/mongodb
export PATH=$PATH:$MONGODB_HOME/bin   # 末尾处添加
```

重新加载环境变量

```sh
$ source /etc/profile 
```

查看是否添加

```sh
$ echo $PATH
```

7. 启动 MongoDB

```sh
$ cd /usr/local/mongodb/bin
$ mongod -f mongodb.conf
```

8. 访问

```sh
[root@localhost ~]$ mongo
MongoDB shell version v4.0.10
connecting to: mongodb://127.0.0.1:27017/?gssapiServiceName=mongodb
Implicit session: session { "id" : UUID("cdd40824-7611-41cb-a3ab-ef737a82068d") }
MongoDB server version: 4.0.10
Welcome to the MongoDB shell.
For interactive help, type "help".
For more comprehensive documentation, see
    http://docs.mongodb.org/
Questions? Try the support group
    http://groups.google.com/group/mongodb-user
>
[root@localhost bin]$mongod -f mongodb.conf --shutdown  #关闭服务
```

9. 使用脚本加入开机自启

给系统添加 MongoDB 管理脚本：

```sh
cat > /usr/lib/systemd/system/mongod.service << EOF
[Unit]
Description=MongoDB database server
After=network.target
[Service]
Type=forking
#PIDFile=/home/dp/data/mongodb/pid
ExecStart=/usr/local/mongodb/bin/mongod -f /usr/local/mongodb/bin/mongodb.conf
PrivateTmp=true
[Install]
WantedBy=multi-user.target
EOF
```

然后加载启动： 

```sh
[root@localhost ~]$systemctl daemon-reload
[root@localhost ~]$systemctl start  mongod
[root@localhost ~]$systemctl status  mongod
● mongod.service - MongoDB database server
   Loaded: loaded (/usr/lib/systemd/system/mongod.service; disabled; vendor preset: disabled)
   Active: active (running) since Wed 2019-07-03 11:41:13 CST; 1min 29s ago
 Main PID: 18489 (mongod)
   CGroup: /system.slice/mongod.service
           └─18489 /usr/local/mongodb/bin/mongod -f /usr/local/mongodb/bin/mongodb.conf
Jul 03 11:41:12 localhost.localdomain systemd[1]: Starting MongoDB database server...
Jul 03 11:41:12 localhost.localdomain mongod[18487]: about to fork child process, waiting until server is ready for connections.
Jul 03 11:41:12 localhost.localdomain mongod[18487]: forked process: 18489
Jul 03 11:41:13 localhost.localdomain mongod[18487]: child process started successfully, parent exiting
Jul 03 11:41:13 localhost.localdomain systemd[1]: Started MongoDB database server.
[root@localhost ~]$systemctl enable  mongod
Created symlink from /etc/systemd/system/multi-user.target.wants/mongod.service to /usr/lib/systemd/system/mongod.service.
```

这样就能够实现比较简单的管理了。



### 数据库的启动与关闭

启动：

```sh
$ mongod --dbpath=/usr/local/mongodb/data --logpath=/usr/local/mongodb/log/mongodb.log --port=27017 --logappend --fork
```

关闭：

```sh
$ mongod --shutdown  --dbpath=/usr/local/mongodb/data --logpath=/usr/local/mongodb/log/mongodb.log --port=27017 --logappend --fork
```

**参数说明：**

| **参数**       | **参数说明**                        |
| :------------- | :---------------------------------- |
| **–dbpath**    | 数据存放路径                        |
| **–logpath**   | 日志文件路径                        |
| **–logappend** | 日志输出方式                        |
| **–port**      | 启用端口号                          |
| **–fork**      | 在后台运行                          |
| **–auth**      | 是否需要验证权限登录 (用户名和密码) |
| **–bind_ip**   | 限制访问的 ip                       |
| **–shutdown**  | 关闭数据库                          |



### 使用配置文件的方式管理数据库

#### 普通格式配置文件

```sh
[mongod@MongoDB conf]$ vim mongod1.conf 
dbpath=/usr/local/mongodb/data
logpath=/usr/local/mongodb/log/mongodb.log
port=27017
logappend=1
fork=1
```

使用配置文件时的启动与关闭：

```sh
启动：mongod -f mongod1.conf 
关闭：mongod -f mongod1.conf  --shutdown
```



#### YAML 格式配置文件（官方推荐使用）

```sh
[mongod@MongoDB conf]$ cat  mongod.conf 
systemLog:
   destination: file
   path: "/usr/local/mongodb/log/mongod.log"
   logAppend: true
storage:
   journal:
      enabled: true
   dbPath: "/usr/local/mongodb/data"
processManagement:
   fork: true
net:
   port: 27017
```

注：mongod 进程收到 [SIGINT](https://so.csdn.net/so/search?q=SIGINT&spm=1001.2101.3001.7020) 信号或者 SIGTERM 信号，会做一些处理

- 关闭所有打开的连接
- 将内存数据强制刷新到磁盘
- 当前的操作执行完毕
- 安全停止



#### 切忌 kill -9

如果使用 kill -9 直接关闭数据库，可能会造成数据丢失，数据文件损失等风险。

可通过如下安全的方式进行关闭。

```sh
$ kill -2 PID
　　原理：-2表示向mongod进程发送SIGINT信号。
$ kill -4 PID
　　原理：-4表示向mognod进程发送SIGTERM信号。
```

当然也可以通过使用systemctl stop mongod来关闭数据库。













































