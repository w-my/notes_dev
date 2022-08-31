# Linux & Nginx



## Linux



### Linux 安装



#### VmWare 虚拟机安装

网上下载安装后破解即可。



#### CentOS 安装



#### Linux 远程访问

使用远程访问软件：**CRT**，实现远程访问。



### Linux 目录结构

- bin （binaries）存放二进制可执行文件
- sbin（super user binaries）存放二进制可执行文件，只有root才能访问
- etc（etcetera）存放系统配置文件
- usr（unix shared resources）存放共享的系统资源
- home 存放用户文件的根目录
- root 超级用户目录
- dev（devices）存放设备文件
- lib（library）存放根文件系统中的程序运行所需要的共享库及内核模块
- mnt（mount）系统管理员安装临时文件系统的安装点
- boot 存放用于系统引导时使用的各种文件
- tmp（temporary）存放各种临时文件
- var（variable）存放运行时需要改变数据的文件

> root 管理员的 home 目录是 root
>
> 其他用户的 home 目录是 home



### Linux 常用命令

#### 切换目录：`cd`

```bash
cd dir // 进入目录
cd ..  // 切换到上一层目录
cd / 	 // 切换到系统根目录
cd ~   // 切换到用户主目录
cd -	 // 切换到上一个所在目录
```

#### 列出文件：`ls` `ll`

```bash
ls
ls -a // 显示所有文件和目录（包括隐藏文件）
ls -l // 显示文件的部分信息，缩写成 ll
```

#### 创建和移除目录：`mkdir` `rmdir`

```bash
mkdir aa // 创建目录aa
mkdir -p aa/bb // 级联创建目录 aa/bb
```

```bash
rmdir aa // 删除空目录aa
```

#### 文件浏览：`cat` `more` `less`

```bash
cat [参数]<文件名> ：显示文件内容
cat yum.conf
more yum.conf
less yum.conf
```

```
tail ：显示文件后几行的内容
tail -10 a.log // 查看后10行数据
tail -f a.log // 动态查看日志

ctrl+c // 结束查看
```

#### 文件操作：`rm` `cp` `mv` `tar` `find` `grep`

```bash
rm [选项]... 文件...
	rm a.txt
	rm -f a.txt 	// 不询问，直接删除
	rm -r a 			// 递归删除，不询问
	rm -rf a			// 不询问递归删除
	rm -rf * 			// 删除所有文件
	rm -rf /* 		// 自杀!!!
```

```bash
cp a.txt b.txt 	// a.txt 复制为 b.txt
```

```bash
mv a.txt ../		// 移动文件到上一层目录
mv a.txt b.txt	// a.txt 重命名为 b.txt
```

```bash
	tar 命令位于 /bin 目录下，它能够将用户所指定的文件或目录打包成一个文件，但不做压缩。一般Linux上常用的压缩方式是选用tar将许多文件打包成一个文件，再以gzip压缩命令压缩成xxx.tar.gz(或称为xxx.tgz)的文件。常用参数：
  -c：创建一个新tar文件
  -v：显示运行过程的信息
  -f：指定文件名
  -z：调用gzip压缩命令进行压缩
  -t：查看压缩文件的内容
  -x：解开tar文件

打包：
	tar –cvf xxx.tar ./*
打包并且压缩：
	tar –zcvf xxx.tar.gz ./* 

解压 
	tar –xvf xxx.tar
	tar -zxvf xxx.tar.gz -C /usr/aaa // 解压文件并放到指定文件夹下
```

```bash
find 指令用于查找符合条件的文件
  find / -name “ins*” 						// 查找文件名称是以ins开头的文件
  find / -name “ins*” –ls 
  find / –user aaa –ls 						// 查找用户aaa的文件
  find / –user aaa –type d –ls 		// 查找用户aaa的目录
  find /-perm -777 –type d-ls 		// 查找权限是777的文件
```

```bash
查找文件里符合条件的字符串。
grep [选项]... PATTERN [FILE]...
  grep lang anaconda-ks.cfg  				// 在文件中查找lang
  grep lang anaconda-ks.cfg –color	// 高亮显示
```

#### 其他命令：`pwd` `touch` `clear` `ctrl+l`

```bash
pwd // 显示当前所在目录
touch a.txt // 创建空文件
clear // 清屏
ctrl+l // 清屏
```



### Vi 和 Vim 编辑器

#### vim 使用

```
切换到命令行模式：按Esc键；
切换到插入模式：按 i 、o、a 键；
    i 在当前位置前插入
    I 在当前行首插入
    a 在当前位置后插入
    A 在当前行尾插入
    o 在当前行之后插入一行
    O 在当前行之前插入一行

切换到底行模式：按 :（冒号）；更多详细用法，查询文档《Vim命令合集.docx》和《vi使用方法详细介绍.docx》

打开文件：vim file
退出：esc  :q
修改文件：输入i进入插入模式
保存并退出：esc :wq
不保存退出：esc :q!

三种进入插入模式：
  i:在当前的光标所在处插入
  o:在当前光标所在的行的下一行插入
  a:在光标所在的下一个字符插入

快捷键：
  dd – 快速删除一行
  yy - 复制当前行
  nyy - 从当前行向后复制几行
  p - 粘贴
  R – 替换
```

#### 重定向输出 > 和 >>

```
> 重定向输出，覆盖原有内容；
>> 重定向输出，有追加功能；

	cat /etc/passwd > a.txt  将输出定向到a.txt中
	cat /etc/passwd >> a.txt  输出并且追加

	ifconfig > ifconfig.txt
```

#### 系统管理命令

```
ps 正在运行的某个进程的状态
  ps –ef  查看所有进程
  ps –ef | grep ssh 查找某一进程
  kill 2868  杀掉2868编号的进程
  kill -9 2868  强制杀死进程
```

#### 管道 | 

```
管道是Linux命令中重要的一个概念，其作用是将一个命令的输出用作另一个命令的输入。
  ls --help | more  分页查询帮助信息
  ps –ef | grep java  查询名称中包含java的进程
  ifconfig | more
  cat index.html | more
  ps –ef | grep aio
```



### Linux 的权限命令

#### 文件权限

```
r: 对文件是指可读取内容 对目录是可以ls
w: 对文件是指可修改文件内容，对目录是指可以在其中创建或删除子节点(目录或文件)
x: 对文件是指是否可以运行这个文件，对目录是指是否可以cd进入这个目录
```

#### Linux 三种文件类型

```
普通文件：包括文本文件、数据文件、可执行的二进制程序文件等。 
目录文件：Linux系统把目录看成是一种特殊的文件，利用它构成文件系统的树型结构。  
设备文件：Linux系统把每一个设备都看成是一个文件
```

#### 文件类型标识

```
- ：普通文件
d ：目录
l ：符号链接（快捷文件）
* 进入etc可以查看，相当于快捷方式字符设备文件（c）块设备文件（s）套接字（s）命名管道（p）
```

#### 文件权限管理

```
chmod 变更文件或目录的权限。
chmod 755 a.txt 
chmod u=rwx,g=rx,o=rx a.txt
```



### Linux 网络操作

#### 主机名配置

```
hostname 查看主机名
hostname xxx 修改主机名 重启后无效
如果想要永久生效，可以修改 /etc/sysconfig/network 文件
```

#### IP 地址配置

```
ifconfig 查看(修改)ip地址(重启后无效)
ifconfig eth0 192.168.12.22 修改ip地址
如果想要永久生效
修改 /etc/sysconfig/network-scripts/ifcfg-eth0 文件
DEVICE=eth0 #网卡名称
BOOTPROTO=static #获取ip的方式(static/dhcp/bootp/none)
HWADDR=00:0C:29:B5:B2:69 #MAC地址
IPADDR=12.168.177.129 #IP地址
NETMASK=255.255.255.0 #子网掩码
NETWORK=192.168.177.0 #网络地址
BROADCAST=192.168.0.255 #广播地址
NBOOT=yes #系统启动时是否设置此网络接口，设置为yes时，系统启动时激活此设备。
```

#### 域名映射

```
/etc/hosts 文件用于在通过主机名进行访问时做ip地址解析之用,相当于windows系统的C:\Windows\System32\drivers\etc\hosts 文件的功能
```

#### 网络服务管理

```
service network status 查看指定服务的状态
service network stop 停止指定服务
service network start 启动指定服务
service network restart 重启指定服务

service --status–all 查看系统中所有后台服务
netstat –nltp 查看系统中网络进程的端口监听情况

防火墙设置
防火墙根据配置文件 /etc/sysconfig/iptables 来控制本机的”出”、”入”网络访问行为。
service iptables status 查看防火墙状态
service iptables stop 关闭防火墙
service iptables start 启动防火墙
chkconfig iptables off 禁止防火墙自启
```



### Linux 上软件安装

#### Linux 上安装方式

##### 二进制发布包

软件已经针对具体平台编译打包发布，只要解压，修改配置即可。

##### RPM 包

软件已经按照redhat的包管理工具规范RPM进行打包发布，需要获取到相应的软件RPM发布包，然后用RPM命令进行安装。

##### Yum 在线安装

软件已经以RPM规范打包，但发布在了网络上的一些服务器上，可用yum在线安装服务器上的rpm软件，并且会自动解决软件安装过程中的库依赖问题。

##### 源码编译安装

软件以源码工程的形式发布，需要获取到源码工程后用相应开发工具进行编译打包部署。



#### 上传与下载工具介绍

##### FileZilla

##### lrzsz

可以用 yum 方式安装：`yum install lrzsz`

可以在 crt 中设置上传与下载目录。

##### sftp

使用 `alt + p` 组合键打开 `sftp` 窗口。

使用 `put` 命令上传

使用 `get` 命令下载



#### Linux 上安装 JDK

- 上传 JDK 到 Linux 服务器

```
* 上传 JDK
* 卸载 open-JDK

# 查看 jdk 版本
java -version
# 查看安装到 jdk 信息
rpm -ga | grep java
# 卸载 jdk
rpm -e --nodeps java-1.7.0-openjdk-1.7.0.79-2.5.5.4.e16.i686
```

- 在 Linux 服务器上安装 JDK

```
* 通常将软件安装到 /usr/local
* 直接解压就可以
tar -xvf jdk.tar.gz -C 目标路径
```

- 配置 JDK 环境变量

```
vi /etc/profile

# 在末尾添加
	#set java environment
	JAVA_HOME=/usr/local/jdk/jdk1.7.0_71
	CLASSPATH=.:$JAVA_HOME/lib.tools.jar
	PATH=$JAVA_HOME/bin:$PATH
	export JAVA_HOME CLASSPATH PATH

# 保存退出，使更改的配置生效
source /etc/profile
```



#### Linux 上安装 Mysql

- 上传 mysql 安装文件到 Linux 服务器

```
* 解压
* 下载系统自带的 mysql
rpm -ga | grep mysql
```

- 安装 MYSQL 服务端

```
rpm -ivh MySQL-server-5.6.22.1.e16.i686.rpm
* 第一次登录需要修改 root 密码
```

- 安装 MYSQL 客户端

```
* 查看自动生成的 root 密码
cat /root/.mysql_select
* 开启 mysql 服务
service mysql start
* 设置 root 用户密码
set password=password('root');
```

- mysql 远程访问设置

```
grant all privileges on *.* to 'root' @'%' identified by 'root';
flush privileges;
* 在 linux 中很多软件的端口都被防火墙限制，需要关闭防火墙
* 防火墙打开 3306 端口
/sbin/iptables -I INPUT -p tcp --dport 3306 -j ACCEPT
/etc/rc.d/init.d/iptables save
/etc/init.d/iptables status
* 直接关闭防火墙
service iptables stop;
```



#### Linux 上安装 tomcat

- tomcat 上传到 linux
- 解压上传到 tomcat
- 在 tomcat/bin 目录下执行 startup.sh （注意防火墙）
- 查看目标 tomcat/logs/catalina.out



#### Linux 上安装 redis

- 安装 gcc-c++

  redis是C语言开发，安装redis需要先将官网下载的源码进行编译，编译依赖gcc环境。

  `yum install gcc-c++`

  输入 `y` 确认

- 安装 redis

  - 下载 redis

    ```wget http://download.redis.io/releases/redis-3.0.4.tar.g```

  - 解压

    `tar -xzvf redis-3.0.4.tar.gz`

  - 编译安装

    切换至程序目录，并执行 make 命令编译：

    `cd redis-3.0.4`

    `make`

  - 执行安装命令

    `make PREFIX=/usr/local/redis install`

    make install安装完成后，会在/usr/local/bin目录下生成下面几个可执行文件，它们的作用分别是：

    redis-server：Redis服务器端启动程序

    redis-cli：Redis客户端操作工具。也可以用telnet根据其纯文本协议来操作

    redis-benchmark：Redis性能测试工具

    redis-check-aof：数据修复工具

    redis-check-dump：检查导出工具

- 配置 redis

  - 复制配置文件到/usr/local/redis/bin目录：

    `cd redis-3.0.4`

    `cp redis.conf /usr/local/redis/bin`

- 启动 redis

  - 进入 redis/bin 目录

    cd redis/bin

  - 启动 redis 服务端

    `./redis-server redis.conf`

  - 克隆新窗口，启动 redis 客户端

    `./redis-cli`



#### 部署项目到 Linux

- 修改 pom 配置

  在 pom.xml 中添加 <finalName>

  ```
  <build>
  	<finalName>travel<finalName>
  	<plugins>
  		<plugin>
  ```

  修改 jdk 版本 1.7

- 修改项目

  - druid.properties

  ```
  driverClassName=com.mysql.jdbc.Driver
  url=jdbc:mysql:///travel?characterEncoding=utf-8
  username=root
  password=root
  initialSize=5
  maxActive=10
  maxWait=3000
  ```

  - header.html

  ```
  location.href="route_list.html?cid="+cid+"&rname="+rname;
  ```

  - route_detail.html

  ```
  location.href="login.html";
  ```

  - 上传 war 包

- 使用 package 命令打包
- 将 travel.war 上传到 tomcat 中的 webapps 目录
- 重启 tomcat
- 导出本地 mysql 数据，并导入 linux 中的 mysql。



## Nginx

Nginx 是一款高性能的 http 服务器/反向代理服务器及电子邮件（IMAP/POP3）代理服务器。由俄罗斯的程序设计师伊戈尔·西索夫（Igor Sysoev）所开发，官方测试 nginx 能够支支撑 5 万并发链接，并且 cpu、内存等资源消耗却非常低，运行非常稳定。

**Nginx** **应用场景：**

1、http 服务器。Nginx 是一个 http 服务可以独立提供 http 服务。可以做网页静态服务器。

2、虚拟主机。可以实现在一台服务器虚拟出多个网站。例如个人网站使用的虚拟主机。

3、反向代理，负载均衡。当网站的访问量达到一定程度后，单台服务器不能满足用户的请求时，需要用多台服务器集群可以使用 nginx 做反向代理。并且多台服务器可以平均分担负载，不会因为某台服务器负载高宕机而某台服务器闲置的情况。



### Nginx 在 Linux 安装

准备一台新的虚拟机作为服务器。

#### 环境准备

- 安装 gcc 环境

  `yum install gcc-c++`

- 第三方的开发包

  - PCRE

    PCRE(Perl Compatible Regular Expressions)是一个 Perl 库，包括 perl 兼容的正则表达式库。nginx 的 http 模块使用 pcre 来解析正则表达式，所以需要在 linux 上安装 pcre 库。

    `yum install -y pcre pcre-devel`

    注：pcre-devel 是使用 pcre 开发的一个二次开发库。nginx 也需要此库。

  - zlib

    zlib 库提供了很多种压缩和解压缩的方式，nginx 使用 zlib 对 http 包的内容进行 gzip，所以需要在 linux 上安装 zlib 库。

    `yum install -y zlib zlib-devel`

  - OpenSSL

    OpenSSL 是一个强大的安全套接字层密码库，囊括主要的密码算法、常用的密钥和证书封装管理功能及 SSL 协议，并提供丰富的应用程序供测试或其它目的使用。nginx 不仅支持 http 协议，还支持 https（即在 ssl 协议上传输 http），所以需要在 linux安装 openssl 库。

    `yum install -y openssl openssl-devel`

- Nginx 下载

   [nginx](http://nginx.org/)

- Nginx 安装

  - 上传 nginx 源码包 nginx-1.8.0.tar.gz 到 linux 系统

  - 解压缩

    `tar zxvf nginx-1.8.0.tar.gz`

  - 进入 nignx-1.8.0 目，使用 configure 命令创建 makeFile 文件。

    ```
    ./configure \
    --prefix=/usr/local/nginx \
    --pid-path=/var/run/nginx/nginx.pid \
    --lock-path=/var/lock/nginx.lock \
    --error-log-path=/var/log/nginx/error.log \
    --http-log-path=/var/log/nginx/access.log \
    --with-http_gzip_static_module \
    --http-client-body-temp-path=/var/temp/nginx/client \
    --http-proxy-temp-path=/var/temp/nginx/proxy \
    --http-fastcgi-temp-path=/var/temp/nginx/fastcgi \
    --http-uwsgi-temp-path=/var/temp/nginx/uwsgi \
    --http-scgi-temp-path=/var/temp/nginx/scgi
    ```

    Makefile是一种配置文件， Makefile 一个工程中的源文件不计数，其按类型、功能、模块分别放在若干个目录中，makefile定义了一系列的规则来指定，哪些文件需要先编译，哪些文件需要后编译，哪些文件需要重新编译，甚至于进行更复杂的功能操作，因为 makefile就像一个Shell脚本一样，其中也可以执行操作系统的命令。

    ```
    configure参数
    ./configure \
    --prefix=/usr \                                                        指向安装目录
    --sbin-path=/usr/sbin/nginx \                                 指向（执行）程序文件（nginx）
    --conf-path=/etc/nginx/nginx.conf \                      指向配置文件
    --error-log-path=/var/log/nginx/error.log \              指向log
    --http-log-path=/var/log/nginx/access.log \            指向http-log
    --pid-path=/var/run/nginx/nginx.pid \                      指向pid
    --lock-path=/var/lock/nginx.lock \                         （安装文件锁定，防止安装文件被别人利用，或自己误操作。）
    --user=nginx \
    --group=nginx \
    --with-http_ssl_module \                      启用ngx_http_ssl_module支持（使支持https请求，需已安装openssl）
    --with-http_flv_module \                       启用ngx_http_flv_module支持（提供寻求内存使用基于时间的偏移量文件）
    --with-http_stub_status_module \     启用ngx_http_stub_status_module支持（获取nginx自上次启动以来的工作状态）
    --with-http_gzip_static_module \   启用ngx_http_gzip_static_module支持（在线实时压缩输出数据流）
    --http-client-body-temp-path=/var/tmp/nginx/client/ \ 设定http客户端请求临时文件路径
    --http-proxy-temp-path=/var/tmp/nginx/proxy/ \ 设定http代理临时文件路径
    --http-fastcgi-temp-path=/var/tmp/nginx/fcgi/ \ 设定http fastcgi临时文件路径
    --http-uwsgi-temp-path=/var/tmp/nginx/uwsgi \ 设定http uwsgi临时文件路径
    --http-scgi-temp-path=/var/tmp/nginx/scgi \ 设定http scgi临时文件路径
    --with-pcre 启用pcre库
    ```

  - 编译

    `make`

  - 安装

    `make install`

    

#### Nginx 启动与访问

启动nginx 之前，上边将临时文件目录指定为/var/temp/nginx/client， 需要在 /var 下创建此目录

```
mkdir /var/temp/nginx/client -p
```

进入到Nginx目录下的sbin目录

```
cd /usr/local/ngiux/sbin
```

输入命令启动Nginx

```
./nginx
```

启动后查看进程

```
ps aux|grep nginx
```

地址栏输入虚拟机的IP即可访问（默认为80端口）

关闭 nginx：

```
./nginx -s stop
```

或者

```
./nginx -s quit
```

重启 nginx：

1. 先关闭后启动
2. 刷新配置文件

```
./nginx -s reload
```



### Nginx 静态网站部署

#### 静态网站的部署

将/资料/静态页面/index目录下的所有内容 上传到服务器的/usr/local/nginx/html下即可访问

#### 配置虚拟主机

虚拟主机，也叫“网站空间”，就是把一台运行在互联网上的物理服务器划分成多个“虚拟”服务器。虚拟主机技术极大的促进了网络技术的应用和普及。同时虚拟主机的租用服务也成了网络时代的一种新型经济形式。

- 端口绑定

  - 上传静态网站

    将/资料/静态页面/index目录上传至 /usr/local/nginx/index下

    将/资料/静态页面/regist目录上传至 /usr/local/nginx/regist下

  - 修改Nginx 的配置文件：/usr/local/nginx/conf/nginx.conf

  - 访问测试

    地址栏输入http://192.168.177.129/:81 可以看到首页面

    地址栏输入http://192.168.177.129/:82 可以看到注册页面

- 域名绑定



### Nginx 反向代理与负载均衡

#### 反向代理

反向代理（Reverse Proxy）方式是指以[代理服务器](http://baike.baidu.com/item/代理服务器)来接受internet上的连接请求，然后将请求转发给内部网络上的服务器，并将从服务器上得到的结果返回给internet上请求连接的客户端，此时代理服务器对外就表现为一个反向代理服务器。

##### 配置反向代理

1. 将travel案例部署到tomcat中（ROOT目录），上传到服务器。
2. 启动TOMCAT，输入网址http://192.168.177.129:8080 可以看到网站首页。
3. 在Nginx主机修改 Nginx配置文件
4. 重新启动Nginx 然后用浏览器测试：http://www.hmtravel.com  （此域名须配置域名指向）

#### 负载均衡

负载均衡 建立在现有网络结构之上，它提供了一种廉价有效透明的方法扩展 网络设备 和 服务器 的带宽、增加吞吐量、加强网络数据处理能力、提高网络的灵活性和可用性。

##### 配置负载均衡

1. 将刚才的存放工程的tomcat复制三份，修改端口分别为8080 ，8081，8082 。

2. 分别启动这三个tomcat服务。

3. 为了能够区分是访问哪个服务器的网站，可以在首页标题加上标记以便区分。

4. 修改 Nginx配置文件

   ```
   upstream tomcat-travel {
    	server 192.168.177.129:8080;
    	server 192.168.177.129:8081;
    	server 192.168.177.129:8082;
   }
   
   server {
       listen       80; # 监听的端口
       server_name  www.hmtravel.com; # 域名或ip
       location / {	# 访问路径配置
           # root   index;# 根目录
     proxy_pass http://tomcat-travel;
   
           index  index.html index.htm; # 默认首页
       }
       error_page   500 502 503 504  /50x.html;	# 错误页面
       location = /50x.html {
           root   html;
       }
   }
   ```

   

