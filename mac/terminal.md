# Homebrew

Homebrew 是 Mac OS 平台下的软件包管理工具。

安装：

```sh
/bin/zsh -c "$(curl -fsSL https://gitee.com/cunkai/HomebrewCN/raw/master/Homebrew.sh)"
```

应为墙的原因，使用国内镜像地址安装，这里最好选择 中科大，比较快。

> **关于Homebrew：**
> 1.Homebrew的命令是以brew开头。 例如：brew -v 查看Homebrew版本
> 2.Homebrew 的默认安装目录为 /usr/local
> 3.通过 brew 安装的程序都会默认安装到 /usr/local/Cellars/程序名/版本号/ 目录下

> **Homebrew相关的使用命令：**
> brew -v：查看brew版本：
> brew help：查看Homebrew命令
> brew install <packageName> ：安装任意包，例如安装rvm：brew install rvm
> brew --repo ： 查看路径
> brew uninstall <packageName>：卸载任意包，例如卸载rvm：brew uninstall rvm
> brew search <packageName>：查询可用包
> brew list：查询已安装包列表
> brew info <packageName>：查看任意包信息
> brew update：更新Homebrew



# Ruby

修改 ruby 镜像源

查看当前源：

```sh
gem sources -l
```

修改为 `RubyChina` ：

```sh
gem source -r https://rubygems.org/
gem source -a https://gems.ruby-china.com/ 
```

或：

```sh
gem sources --add https://gems.ruby-china.com/ --remove https://rubygems.org/
```

`gem sources -l` 查看是否修改成功：

```sh
*** CURRENT SOURCES ***

https://gems.ruby-china.com/
```



# Cocoapods

安装：

```sh
sudo gem install cocoapods
```

如果报错，没有/usr/bin的读写权限，执行以下命令：

```sh
sudo gem install cocoapods -n /usr/local/bin
```

完成后运行：

```sh
sudo gem install ffi
```

最后运行：

```sh
pod setup
```

```sh
pod --version
```



# nodejs

[官网 https://nodejs.org/en/ ](https://nodejs.org/en/) 下载 current 包，手动安装

查看当前版本：

```sh
node -v
```



# GitHub

### Token 错误

github 取消了账号密码认证，向 Github 推送代码时，报如下错误：

```
remote: Support for password authentication was removed on August 13, 2021. Please use a personal access token instead.
remote: Please see https://github.blog/2020-12-15-token-authentication-requirements-for-git-operations/ for more information.
```

解决方法：

1. 先去官网申请 Person Access Token

个人主页下 Settings，选择 Developer Settings，选择 Person Access Token，添加一个 token

2. 新建仓库时使用

```sh
$ git clone ...
Username: <username>
Password: <Person Access Token>
```

3. 已有仓库使用

清除已有的账号密码，然后进行相关操作时输入新账号密码

```sh
sudo git config --system --unset credential.helper
```

### 433 错误

LibreSSL SSL_connect: SSL_ERROR_SYSCALL in connection to github.com:443

GitHub无法访问、443 Operation timed out的解决

1. 记录以上三个网址下的 IP Address

https://github.com.ipaddress.com

https://fastly.net.ipaddress.com/github.global.ssl.fastly.net#ipinfo

https://github.com.ipaddress.com/assets-cdn.github.com

例如：

```sh
140.82.114.3  		github.com
199.232.69.194		github.global.ssl.fastly.net
185.199.108.153		assets-cdn.github.com
185.199.109.153		assets-cdn.github.com
185.199.110.153		assets-cdn.github.com
185.199.111.153		assets-cdn.github.com
```

2. 将网址映射保存到 /etc/hosts 文件最后

编辑 /etc/hosts 文件，将上面网址复制的 IP Address 保存到最后

```sh
vim /etc/hosts
```

注意：需要 root 权限，做如下操作即可：

```sh
sudo su
su -
vim /etc/hosts
```

3. 刷新DNS，然后就可以神奇的访问 Github 了

```sh
sudo killall -HUP mDNSResponder;say DNS cache has been flushed
```

### SSH

```sh
$ ssh-keygen -t rsa -C "email@qq.com"
$ ssh-keygen -t rsa -C "email@qq.com" -f ~/.ssh/github_rsa
$ ssh-keygen -t rsa -C "email@qq.com" -f ~/.ssh/gitee_rsa
$ ssh-keygen -t rsa -C "email@qq.com" -f ~/.ssh/gitlab_rsa
```

##### 配置多个publickey

```sh
$ vim config

# gitee
Host gitee.com
     HostName gitee.io
     User w-my
     IdentityFile ~/.ssh/gitee_rsa

# github
Host github.com
     HostName github.com
     User w-my
     IdentityFile ~/.ssh/github_rsa

# gitlab
Host 192.168.2.107
     HostName 192.168.2.107
     User weimy
     IdentityFile ~/.ssh/gitlab_rsa

# other
Host *
     User wmy
     IdentityFile ~/.ssh/id_rsa
```

远程私有库

```sh
$ pod repo add ServyouCocoaPod <url>
```

##### 配置github

申请**SSH**

> 1、检查Mac上是否存在**SSH** `$ cd ~/.ssh`，提示`No such file or directory`说明不存在。
> 2、若不存在，创建**SSH** `$ ssh-keygen -t rsa -C xxxxxx@163.com`（邮箱为`github`的注册邮箱）
> 3、然后会提示**SSH** `rsa key`的存放路径，使用默认路径的话，直接回车就好了。
> 4、然后为**SSH**设定一个密码，输入完密码和确认密码，**SSH**的创建就完成了。

配置**SSH**

> 1、若上面的步骤 `3` 没有修改路径的话，默认路径为 `~/.ssh` 。因此打开Spotlight 输入 `~/.ssh` 即可打开该路径。
> 2、打开 `~/.ssh` 路径下的 `id_rsa.pub` ，拷贝里面的内容。
> 3、登录 [github](https://github.com) 账号，右上角点击 `头像` ，选择 `Settings` 进入设置。
> 4、选择 `SSH and GPG keys`  -->  `New SSH key` ，然后随意填写 `title` 项，`key` 需要填写步骤 `1` 拷贝到的内容，然后点击 `Add SSH key` 完成**SSH**的设置。

验证关联 `github` 账号是否成功

`$ ssh -T git@github.com` ，若提示 `Hi xxx! You've successfully authenticated, but GitHub does not provide shell access.` 则表示连接成功。

### 上传

登录 [github](https://github.com)，创建`Repository `

> 1、`Repository name` 仓库名称
> 2、`Description (optional)` 添加仓库描述
> 3、选择`Public`
> 4、点击`Create repository` 完成创建

创建完成后，就可以使用终端上传项目了

> 1、先`cd`到项目目录下
> 2、`$ echo "# 项目名" >> README.md` 新建更新描述文档
> 3、`$ git init` 初始化本地仓库
> 4、`$ git add .` 添加
> 5、`$ git commit -m "first commit"` 添加提交说明
> 6、`$ git remote add origin git@github.com:Wmy6611/GithubTest.git` 
> `git@github.com:Wmy6611/GithubTest.git`为创建`github`仓库完成时给的链接
> 7、`$ git push -u origin master`将本地项目更新到`github`项目上去

### 拉取

拉取`github`上的代码

> `$ git clone https://github.com/Wmy6611/GithubTest`

### 更新

本地更新的代码提交到`github`代码仓库去

> 1、`$ git add "filename"`  添加单个要更新的类
> **或** `$ git add *` 添加所有需要更新的类
> 2、`$ git commit -m "说明内容"` 提交更新说明
> 3、`$ git push origin master` 提交到`github`的`master`分支上

### 连接仓库

连接远程仓库

> `$ git remote add origin git@github.com:Wmy6611/GithubTest.git`

查询是否连接成功

> `$ git remote -v`





