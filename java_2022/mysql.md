# mysql


---
## mysql 下载安装
[mysql下载](https://dev.mysql.com/downloads/mysql/) ，
直接下载 dmg 格式执行安装，安装过程中最后会让设置数据库密码，需要记住自己设置的密码。


---
## mysql 配置
打开终端，执行：
```sh
cd ~
touch .bash_profile
open -e .bash_profile
```
在打开的文件最后输入
```sh
# mysql
export PATH=${PATH}:/usr/local/mysql/bin
```
然后保存退出，刷新配置，使配置生效：
```sh
source ~/.bash_profile
```


---
## mysql 使用
可以通过以下命令登录 mysql，执行命令需要输入数据库密码：
```sh
mysql -u root -p
```
可以通过以下命令修改密码：
```sh
SET PASSWORD FOR 'root'@'localhost' = PASSWORD('新密码');
```


---
## idea 配置 mysql
打开 idea 选择 Database，添加 Data Source，选择 MySql，输入数据库连接配置
```text
Host: localhost
Port: 3306
User: root
Password: root1234
Database: #db_name#
URL: jdbc:mysql://localhost:3306/ys_goods?characterEncoding=UTF8&serviceTimezone=UTC&useSSL=false
```


---
## 项目配置 mysql 连接
`application.properties`
```properties
# jdbc
spring.datasource.username=root
spring.datasource.password=root1234
spring.datasource.driver-class-name=com.mysql.cj.jdbc.Driver
spring.datasource.url=jdbc:mysql://127.0.0.1:3306/ys_goods?characterEncoding=UTF8&serviceTimezone=UTC&useSSL=false
```

