## Git



#### 配置
###### 设置邮箱用户名

```cmd
$ git config --global user.name "Your Name"
$ git config --global user.email "email@example.com"
```
如果用了 `--global` 选项，那么更改的配置文件就是位于你用户主目录下的那个，以后所有的项目都会默认使用这里配置的用户信息。
如果要在某个特定的项目中使用其他名字或者电邮，只要去掉 `--global` 选项重新配置即可，新的设定保存在当前项目的 `.git/config` 文件里。

###### 查看配置信息

```cmd
$ git config --list
```



#### git 命令

```cmd
$ git init
$ git add <file>
$ git commit -m <message>
$ git status
$ git diff
$ git diff HEAD -- <file> 			# 查看和版本库的区别
$ git log
$ git log --pretty=oneline 			# 单行显示日志
$ git log --graph --pretty=oneline --abbrev-commit  # 查看分支合并图
$ git reflog
$ git reset --hard HEAD^ 				# 回到上一个版本
$ git reset --hard <commit_id>  # 回到对应id版本
$ git checkout -- <file>				# 让这个文件回到最近一次git commit或git add时的状态 
$ git reset HEAD <file>					# 撤销暂存区的修改，重新放回工作区
$ git rm test.txt
```



```cmd
start a working area (see also: git help tutorial)
   clone      Clone a repository into a new directory
   init       Create an empty Git repository or reinitialize an existing one

work on the current change (see also: git help everyday)
   add        Add file contents to the index
   mv         Move or rename a file, a directory, or a symlink
   reset      Reset current HEAD to the specified state
   rm         Remove files from the working tree and from the index

examine the history and state (see also: git help revisions)
   bisect     Use binary search to find the commit that introduced a bug
   grep       Print lines matching a pattern
   log        Show commit logs
   show       Show various types of objects
   status     Show the working tree status

grow, mark and tweak your common history
   branch     List, create, or delete branches
   checkout   Switch branches or restore working tree files
   commit     Record changes to the repository
   diff       Show changes between commits, commit and working tree, etc
   merge      Join two or more development histories together
   rebase     Reapply commits on top of another base tip
   tag        Create, list, delete or verify a tag object signed with GPG

collaborate (see also: git help workflows)
   fetch      Download objects and refs from another repository
   pull       Fetch from and integrate with another repository or a local branch
   push       Update remote refs along with associated objects
```



#### 本地仓库

```cmd
$ mkdir learngit
$ cd learngit
$ git init
$ ls -a
$ vim readme.txt
$ cat readme.txt
$ git add readme.txt
$ git commit -m "add readme.txt"
$ rm -f test.txt
```



#### 远程仓库

###### 创建SSH Key
用户主目录下是否有 `.ssh` 目录，再看看 `.ssh` 目录下有没有 `id_rsa` 和 `id_rsa.pub` 这两个文件，如果有则跳到下一步。没有则创建：

```cmd
$ ssh-keygen -t rsa -C "youremail@example.com"
```
邮件地址换成自己的邮件地址，然后一路回车，即使用默认值，这个 `Key` 也无需设置密码。
完成后就可以在用户主目录里找到 `.ssh` 目录，里面有 `id_rsa` 和 `id_rsa.pub` 两个文件，`id_rsa `是私钥，不能泄露出去，`id_rsa.pub `是公钥，可以放心地告诉任何人。

###### 配置SSH Key
登陆 `GitHub` -> `Settings` -> `SSH and GPG keys` -> `New SSH key`，然后填上任意Title，在Key文本框里粘贴 `id_rsa.pub` 文件的内容，最后点 `Add SSH key`。

##### 添加远程库
###### 创建一个新仓库
点击`Create a new repository`，填入仓库名称`learngit `，点击`Create repository`，这样一个远程仓库就创建好了。

###### 关联远程仓库
在本地`learngit`仓库下关联远端仓库

```cmd
$ git remote add origin git@github.com:w-my/learngit.git
```

###### 把本地库的内容推送到远程仓库

```cmd
$ git push -u origin master
```
由于远程库是空的，第一次推送 `master` 分支时，加上了 `-u` 参数，`Git` 不但会把本地的 `master` 分支内容推送的远程新的 `master` 分支，还会把本地的 `master` 分支和远程的 `master` 分支关联起来，在以后的推送或者拉取时就可以简化命令。
推送成功后，可以立刻在GitHub页面中看到远程库的内容已经和本地一样了。

###### 之后提交只需要用以下方式就可以把本地master分支的最新修改推送至GitHub：

```cmd
$ git push origin master
```

###### SSH警告
第一次使用 `Git` 的 `clone` 或者 `push` 命令连接 `GitHub` 时，会得到一个警告：

> The authenticity of host 'github.com (13.229.188.59)' can't be established.
> RSA key fingerprint is SHA256:nThbg6kXUpJWGl7E1IGOCspRomTxdCARLviKw6E5SY8.
> Are you sure you want to continue connecting (yes/no)? 

这是因为 `Git` 使用 `SSH` 连接，而 `SSH` 连接在第一次验证 `GitHub` 服务器的 `Key` 时，需要你确认 `GitHub` 的 `Key` 的指纹信息是否真的来自 `GitHub` 的服务器，输入 `yes` 回车即可。
`Git `会输出一个警告，告诉你已经把 `GitHub` 的 `Key` 添加到本机的一个信任列表里了：

> Warning: Permanently added 'github.com,13.229.188.59' (RSA) to the list of known hosts.



#### 从远程库克隆

###### 创建一个新仓库
点击 `Create a new repository` ，填入仓库名称 `learngit ` ，勾选 `Initialize this repository with a README` ，这样GitHub会自动创建一个 `README.md` 文件，点击 `Create repository` ，这样远程仓库就创建好了。

###### 克隆远程库

```cmd
$ git clone git@github.com:w-my/learngit.git
```



#### 分支管理

##### 创建与合并分支
```cmd
$ git branch							# 查看分支
$ git branch <name>			  # 创建分支
$ git checkout <name>		  # 切换分支
$ git checkout -b <name>	# 创建+切换分支
$ git merge <name>			  # 合并某分支到当前分支
$ git branch -d <name>		# 删除分支
```

##### 解决冲突

`git merge` 提示有冲突：

```cmd
$ git merge fix

Auto-merging README.md
CONFLICT (content): Merge conflict in README.md
Automatic merge failed; fix conflicts and then commit the result.
```

`git status` 也会提示有冲突

```cmd
$ git status

On branch dev
You have unmerged paths.
  (fix conflicts and run "git commit")
  (use "git merge --abort" to abort the merge)

Unmerged paths:
  (use "git add <file>..." to mark resolution)

	both modified:   README.md

no changes added to commit (use "git add" and/or "git commit -a")
```
需要修改解决冲突后，再次添加提交。

使用 `log `可以查看分支图
```cmd
$ git log --graph --pretty=oneline --abbrev-commit
```


##### 分支管理策略
使用`--no-ff`方式的`git merge`：
```cmd
$ git merge --no-ff -m "merge with no-ff" dev
```
因为本次合并要创建一个新的commit，所以加上-m参数，把commit描述写进去。

合并后，用git log看看分支历史：
```cmd
$ git log --graph --pretty=oneline --abbrev-commit
```
合并分支时，加上`--no-ff`参数就可以用普通模式合并，合并后的历史有分支，能看出来曾经做过合并，而`fast forward`合并就看不出来曾经做过合并。

###### 分支策略
在实际开发中，我们应该按照几个基本原则进行分支管理：
首先，`master`分支应该是非常稳定的，也就是仅用来发布新版本，平时不能在上面干活；
那在哪干活呢？干活都在`dev`分支上，也就是说，`dev`分支是不稳定的，到某个时候，比如`1.0`版本发布时，再把`dev`分支合并到`master`上，在`master`分支发布`1.0`版本；
你和你的小伙伴们每个人都在`dev`分支上干活，每个人都有自己的分支，时不时地往`dev`分支上合并就可以了。
![分支策略](https://upload-images.jianshu.io/upload_images/1599548-47dbcf8071aadfce.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


#####  Bug分支
当前分支还为开发完，需要零时切换分支做别的事情，可以使用`git stash`把当前分支内容暂存起来。
```cmd
$ git stash
```

使用`git stash list`可以查看暂存列表
```cmd
$ git stash list
```

当处理完其他内容回到工作分支后，可以使用`git stash apply`来恢复之前的工作内容，然后使用`git stash drop`删除暂存历史信息。也可以使用`git stash pop`来恢复暂存内容并删除暂存列表信息。
```cmd
$ git stash apply
$ git stash drop
$ git stash pop
```
###### 小结
修复bug时，我们会通过创建新的bug分支进行修复，然后合并，最后删除；
当手头工作没有完成时，先把工作现场`git stash`一下，然后去修复bug，修复后，再`git stash pop`，回到工作现场。


##### Feature分支
开发一个新feature，最好新建一个分支；
如果要丢弃一个没有被合并过的分支，可以通过`git branch -D <name>`强行删除。
```cmd
$ git branch -D <name>
```


##### 多人协作
Git会把本地的`master`分支和远程的`master`分支对应起来了，并且，远程仓库的默认名称是`origin`。
要查看远程库的信息，用`git remote` 或 `git remote -v`
```cmd
$ git remote
git remote -v
```

###### 推送分支
```cmd
$ git push origin master
```
如果要推送其他分支，比如`dev`，就改成：
```cmd
$ git push origin dev
```

但是，并不是一定要把本地分支往远程推送，那么，哪些分支需要推送，哪些不需要呢？
`master`分支是主分支，因此要时刻与远程同步；
`dev`分支是开发分支，团队所有成员都需要在上面工作，所以也需要与远程同步；
`bug`分支只用于在本地修复bug，就没必要推到远程了，除非老板要看看你每周到底修复了几个bug；
`feature`分支是否推到远程，取决于你是否和你的小伙伴合作在上面开发。
总之，就是在Git中，分支完全可以在本地自己藏着玩，是否推送，视你的心情而定！

###### 抓取分支
1、 远端有 `dev` 分支
基于远程 `dev` 分支创建本地 `dev` 分支

```cmd
$ git checkout -b dev origin/dev
```

2、 远端只有 `mater` 分支

- 创建本地新的 `dev` 分支
```cmd
$ git branch dev
```

- 发布 `dev` 分支
发布`dev` 分支指的是同步 `dev` 分支的代码到远程服务器，这样远程仓库也有一个 `dev` 分支了
```cmd
$ git push origin dev:dev
```

- 切换到 `dev `分支进行开发
```cmd
$ git checkout dev
```

- 开发代码之后，我们有两个选择

第一个：如果功能开发完成了，可以合并主分支
```cmd
$ git checkout master  # 切换到主分支
$ git merge dev  # 把dev分支的更改和master合并
$ git push  # 提交主分支代码远程
$ git checkout dev  # 切换到dev远程分支
$ git push  # 提交dev分支到远程
```

第二个：如果功能没有完成，可以直接推送
```cmd
$ git push  # 提交到dev远程分支
```
注意：在分支切换之前最好先commit全部的改变，除非你真的知道自己在做什么

- 删除分支
```cmd
$ git push origin :dev  # 删除远程dev分支，危险命令哦
```
下面两条是删除本地分支
```cmd
$ git checkout master  # 切换到master分支
$ git branch -d dev  # 删除本地dev分支
```

###### 推送修改
```cmd
$ git push origin dev
```
当小伙伴的最新提交和你试图推送的提交有冲突，则`push`会失败，Git提示我们，先用`git pull`把最新的提交从`origin/dev`抓下来，然后，在本地合并，解决冲突，再推送：
```cmd
$ git pull
```
`git pull`也失败了，原因是没有指定本地`dev`分支与远程`origin/dev`分支的链接，根据提示，设置`dev`和`origin/dev`的链接：
```cmd
$ git branch --set-upstream-to=origin/dev dev
```
再`pull`：
```cmd
$ git pull
```
这回`git pull`成功，但是合并有冲突，手动解决后，提交，再`push`
```cmd
$ git push origin dev
```

###### 因此，多人协作的工作模  式通常是这样：

1.  首先，可以试图用`git push origin <branch-name>`推送自己的修改；
2.  如果推送失败，则因为远程分支比你的本地更新，需要先用`git pull`试图合并；
3.  如果合并有冲突，则解决冲突，并在本地提交；
4.  没有冲突或者解决掉冲突后，再用`git push origin <branch-name>`推送就能成功！

如果`git pull`提示`no tracking information`，则说明本地分支和远程分支的链接关系没有创建，用命令`git branch --set-upstream-to=origin/<branch-name> <branch-name>`。


#####  Rebase
`rebase`操作可以把本地未`push`的分叉提交历史整理成直线；
`rebase`的目的是使得我们在查看历史提交的变化时更容易，因为分叉的提交需要三方对比。



#### 标签管理

##### 创建标签
```cmd
$ git tag <tagname>  #新建标签，默认为HEAD，也可以指定一个commit id；
$ git tag -a <tagname> -m "message"  #新建标签同时指定标签信息；
$ git tag  #查看所有标签
$ git show <tagname>  #查看指定标签处信息
```

查看提交列表
```cmd
$ git log --pretty=oneline --abbrev-commit
```

给指定`commit id`位置添加标签
```cmd
$ git tag -a v1.0.0 -m "version 1.0.0 released" 1094adb
```

##### 操作标签
删除指定标签：
```cmd
$ git tag -d <tagname>
```

推送指定标签到远端：
```cmd
$ git push origin <tagname>
```

或者，一次性推送全部尚未推送到远端的本地标签：
```cmd
$ git push origin --tags
```

要删除已经推送到远端的标签，需先从本地删除：
```cmd
$ git tag -d <tagname>
```
然后，从远程删除。删除命令也是push：
```cmd
$ git push origin :refs/tags/<tagname>
```



#### 使用GitHub

[github](https://github.com)



#### 使用码云

[码云](https://gitee.com)



#### 自定义Git

##### 忽略特殊文件
在Git工作区的根目录下创建一个特殊的`.gitignore`文件，然后把要忽略的文件名填进去，Git就会自动忽略这些文件。
不需要从头写`.gitignore`文件，GitHub已经为我们准备了各种配置文件，只需要组合一下就可以使用了。所有配置文件可以直接在线浏览：[https://github.com/github/gitignore](https://github.com/github/gitignore)


##### 配置别名
告诉Git，以后st就表示status：
```cmd
$ git config --global alias.st status
```

其他
```cmd
$ git config --global alias.co checkout
$ git config --global alias.ci commit
$ git config --global alias.br branch
$ git config --global alias.unstage 'reset HEAD'
```

而当前用户的Git配置文件放在用户主目录下的一个隐藏文件`.gitconfig`中：
```cmd
$ cat .gitconfig
[alias]
    co = checkout
    ci = commit
    br = branch
    st = status
[user]
    name = Your Name
    email = your@email.com
```
配置别名也可以直接修改这个文件，如果改错了，可以删掉文件重新通过命令配置。


##### 搭建Git服务器



#### 总结

