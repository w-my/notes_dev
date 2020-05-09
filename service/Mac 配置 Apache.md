## Mac OS 配置 Apache

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



#### 配置 Apache 目录

###### Apache系统级根目录及对应网址

> /Library/WebServer/Documents
> http://127.0.0.1 或 http://localhost

###### 用户级的根目录及对应网址

> ~/Sites 
> http://localhost/~haibor/

###### 用户级站点根目录需要手动创建

> 1、建立站点文件夹 `$ sudo mkdir ~/Sites`
> 2、`$ cd /etc/apache2/users` 检查目录下是否存在 `Wmy.conf ` 文件，`Wmy` 为当前用户名，如果没有则创建一个 `$ sudo touch Wmy.conf `，并修改文件权限 `$ sudo chmod 644 Wmy.conf `。
> 3、创建之后，打开  Guest.conf 文件，`$ sudo vi Wmy.conf` 将下面的配置信息写入文件。
>  <Directory "/Users/Wmy/Sites/">
>      Options Indexes MultiViews
>      Require all granted
>      Allow Override all
>      Order allow,deny
>      allow from all
>  </Directory>
> 4、编辑 httpd.conf文件 `$ sudo vi /etc/apache2/httpd.conf`，将下面两行代码前面的注释符号 `#`删掉。内容比较多，可以使用 ctrl+w 搜索关键词找到对应位置。
> `Include /private/etc/apache2/extra/httpd-userdir.conf`
> `LoadModule userdir_module libexec/apache2/mod_userdir.so`
> 5、编辑 httpd-userdir.conf 文件 `$ sudo vi /etc/apache2/extra/httpd-userdir.conf`，找到下列代码，并将前面的注释符号 # 删除
> 6、重启 Apache：`$ sudo apachectl restart`

在浏览器中输入 http://127.0.0.1/~Wmy 或 http://localhost/~Wmy ，即可测试用户目录是否工作。