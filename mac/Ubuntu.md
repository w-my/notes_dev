# Ubuntu

[Ubuntu Server 22.04.2 LTS](https://ubuntu.com/download/server/arm)

## 安装

使用默认配置一路安装即可



## 开放root账户

由于不是用的root账号进行登录，在操作命令前需要增加sodo 。

```sh
$ sudo vi /etc/ssh/sshd_config
```

修改如下配置：

```sh
# PermitRootLogin prohibit-password
=>
PermitRootLogin yes
```

重启sshd服务

```sh
$ sudo systemctl restart sshd
```

设置root账号密码

```sh
$ sudo passwd root
```

输入两次密码即可

重启系统，并使用root账户登录

```sh
$ shutdown -r now
```





## 更改ssh登录端口

编辑sshd_config文件

    $ vi /etc/ssh/sshd_config

修改如下配置：

```sh
Port 22
=>
Port 20022
```

重启sshd服务：

```sh
$ sudo systemctl restart sshd
```

可退出系统重新用root和新的端口进行登录尝试。



## 设置固定IP

编辑 00-installer-config.yaml 文件

```sh
$ vi /etc/netplan/00-installer-config.yaml
```

目前默认是开启DHCP的

```sh
network:
	ethernets:
		ens160:
			dhcp4: true
	version: 2
```

修改为：

```sh
network:
	ethernets:
		ens160:
			dhcp4: no
			dhcp6: no
			adresses:
				- 192.168.56.100/24
			routes:
				- to: default
					via: 192.168.56.1
			nameservers:
				addresses:
					- 223.5.5.5
					- 223.6.6.6
	version: 2
```

使配置生效

```sh
$ netplan apply
```

IP更改完后需要重新登录新的IP。

查看ip

```sh
$ ip addr show
```

开启ssh服务

```sh
$ apt-get update   							 #更新apt
$ apt-get install openssh-server  #通过apt安装openssh-server
$ ps -e | grep ssh 
```

允许外部ip访问本机22/tcp(ssh)端口

```sh
$ sudo ufw allow 22/tcp
```

Mac端访问服务器

```sh
$ ssh root@192.168.56.100
```





# Mongodb 6.0.5

## 安装

1. 安装依赖

```sh
$ apt-get install libcurl4 openssl
```

2. 如果安装过mongodb，先停服务并删除

```sh
$ service mongodb stop
$ apt-get remove mongodb
```

3. 导入6.0版本公匙

```
$ wget -qO - https://www.mongodb.org/static/pgp/server-6.0.asc | sudo apt-key add -

wget -qO - https://www.mongodb.org/static/pgp/server-6.0.asc
sudo apt-key add server-6.0.asc

or
$ curl -fsSL https://www.mongodb.org/static/pgp/server-6.0.asc | sudo apt-key add -
```

```sh
$ apt-key list
```

```sh
$ apt-get install gnupg
```





```bash
wget -O- https://www.mongodb.org/static/pgp/server-6.0.asc |
    gpg --dearmor |
    sudo tee /etc/apt/keyrings/server-6.0.asc > /dev/null
```

































