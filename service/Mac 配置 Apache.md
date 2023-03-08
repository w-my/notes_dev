# Mac 配置 Apache

https://www.jianshu.com/p/d22baeae50ea



Mac OS 系统已经集成了 Apache 环境，只需要配置启用就可以了。

#### 启用 Apache
###### 查看 Apache 版本

> `$ httpd -v`
> 版本信息：
> Server version: Apache/2.4.23 (Unix)
> Server built:   Aug  8 2016 18:10:45

###### 启动 Apache 

> `$ sudo apachectl start`
> 在浏览器中输入 http://127.0.0.1 或 http://localhost 如果看到 It Works! 那么 Apache 就启动成功了。

###### 关闭 Apache

> `$ sudo apachectl stop`
###### 重启 Apache

> `$ sudo apachectl restart`



## 配置本地 https 服务

### 自签名证书

#### 新建文件夹

```sh
cd desktop/CustomSSL
```

#### 在SSL文件夹中生成私钥

```sh
openssl genrsa -out server.key 2048
```

#### 生成自签名证书

```sh
openssl req -new -sha256 -x509 -days 365 -key server.key -out server.crt
```

req是证书请求的子命令，-sha256表示算法，-x509表示输出证书，-days365 为有效期，此后根据提示输入证书拥有者信息；

其中要输入国家、省份、地区、公司、邮箱等信息，按照个人情况随便填下就行。
 但 `Common Name` 应该与域名保持一致(如我的电脑搭建的服务器IP地址为`10.73.20.19`)

> e.g: CN, BeiJing, Beijing, Dgq, Dgq, 10.73.20.19

### 配置Apache服务器SSL

#### 放入证书

将`server.crt`和`server.key`两个文件拷贝
放到`/etc/apache2/`目录

#### 修改配置文件

```sh
sudo vim /etc/apache2/httpd.conf
```

搜索下面内容，并去掉注释符号`#`

```sh
LoadModule ssl_module libexec/apache2/mod_ssl.so
Include /private/etc/apache2/extra/httpd-vhosts.conf
Include /private/etc/apache2/extra/httpd-ssl.conf
LoadModule socache_shmcb_module libexec/apache2/mod_socache_shmcb.so
```

```sh
sudo vim /etc/apache2/extra/httpd-ssl.conf
```

去掉以下两项注释并检查是否与之前安装私钥和证书的路径一致

```sh
SSLCertificateFile "/private/etc/apache2/server.crt"
SSLCertificateKeyFile "/private/etc/apache2/server.key"
```

```sh
sudo vim /etc/apache2/extra/httpd-vhosts.conf
```

在 `<VirtualHost *:80> .....</VirtualHost>` 后面添加一段如下内容：

```sh
<VirtualHost *:443>
    SSLEngine on
    SSLCipherSuite ALL:!ADH:!EXPORT56:RC4+RSA:+HIGH:+MEDIUM:+LOW:+SSLv2:+EXP:+eNULL
    SSLCertificateFile /private/etc/apache2/server.crt
    SSLCertificateKeyFile /private/etc/apache2/server.key
    ServerName 10.73.20.19 
    DocumentRoot "/Library/WebServer/Documents"
</VirtualHost>
```

注意 `ServerName` 填写域名与所需访问一致

#### 重启服务器

```sh
sudo apachectl restart
```

访问 `https://10.73.20.19/`
提示不安全什么的(因为自己的证书没添加到浏览器信任列表)，继续访问

HTTPS可以用啦。