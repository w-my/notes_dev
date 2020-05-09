## Github

[iOS组件化-私有podSpecs](https://blog.csdn.net/MPK_Github/article/details/80825780)
[GitLab 的安装及使用](https://www.jianshu.com/p/b04356e014fa)

#### SSH

```cmd
$ ssh-keygen -t rsa -C "email@qq.com"
$ ssh-keygen -t rsa -C "email@qq.com" -f ~/.ssh/github_rsa
$ ssh-keygen -t rsa -C "email@qq.com" -f ~/.ssh/gitee_rsa
$ ssh-keygen -t rsa -C "email@qq.com" -f ~/.ssh/gitlab_rsa
```



#### 配置多个publickey

```cmd
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
```cmd
$ pod repo add ServyouCocoaPod <url>
```



#### 配置github

###### 申请**SSH**

> 1、检查Mac上是否存在**SSH** `$ cd ~/.ssh`，提示`No such file or directory`说明不存在。
> 2、若不存在，创建**SSH** `$ ssh-keygen -t rsa -C xxxxxx@163.com`（邮箱为`github`的注册邮箱）
> 3、然后会提示**SSH** `rsa key`的存放路径，使用默认路径的话，直接回车就好了。
> 4、然后为**SSH**设定一个密码，输入完密码和确认密码，**SSH**的创建就完成了。

###### 配置**SSH**

> 1、若上面的步骤 `3` 没有修改路径的话，默认路径为 `~/.ssh` 。因此打开Spotlight 输入 `~/.ssh` 即可打开该路径。
> 2、打开 `~/.ssh` 路径下的 `id_rsa.pub` ，拷贝里面的内容。
> 3、登录 [github](https://github.com) 账号，右上角点击 `头像` ，选择 `Settings` 进入设置。
> 4、选择 `SSH and GPG keys`  -->  `New SSH key` ，然后随意填写 `title` 项，`key` 需要填写步骤 `1` 拷贝到的内容，然后点击 `Add SSH key` 完成**SSH**的设置。

###### 验证关联 `github` 账号是否成功

`$ ssh -T git@github.com` ，若提示 `Hi xxx! You've successfully authenticated, but GitHub does not provide shell access.` 则表示连接成功。



#### 上传

###### 登录 [github](https://github.com)，创建`Repository `

> 1、`Repository name` 仓库名称
> 2、`Description (optional)` 添加仓库描述
> 3、选择`Public`
> 4、点击`Create repository` 完成创建
###### 创建完成后，就可以使用终端上传项目了

> 1、先`cd`到项目目录下
> 2、`$ echo "# 项目名" >> README.md` 新建更新描述文档
> 3、`$ git init` 初始化本地仓库
> 4、`$ git add .` 添加
> 5、`$ git commit -m "first commit"` 添加提交说明
> 6、`$ git remote add origin git@github.com:Wmy6611/GithubTest.git` 
> `git@github.com:Wmy6611/GithubTest.git`为创建`github`仓库完成时给的链接
> 7、`$ git push -u origin master`将本地项目更新到`github`项目上去



#### 拉取

###### 拉取`github`上的代码

> `$ git clone https://github.com/Wmy6611/GithubTest`



#### 更新

###### 本地更新的代码提交到`github`代码仓库去

> 1、`$ git add "filename"`  添加单个要更新的类
> **或** `$ git add *` 添加所有需要更新的类
> 2、`$ git commit -m "说明内容"` 提交更新说明
> 3、`$ git push origin master` 提交到`github`的`master`分支上



#### 连接仓库

###### 连接远程仓库

> `$ git remote add origin git@github.com:Wmy6611/GithubTest.git`
###### 查询是否连接成功

> `$ git remote -v`