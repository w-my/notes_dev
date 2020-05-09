#### 系统信任

安装三方软件，系统提示无法打开或损坏，可以关闭系统保护

###### 关闭系统保护

```cmd
$ sudo spctl --master-disable
```

###### 打开系统保护

```cmd
$ sudo spctl --master-enable
```



#### 隐藏文件显示隐藏

###### 显示隐藏文件，重启 finder 生效

```cmd
$ defaults write com.apple.finder AppleShowAllFiles -bool true
```

###### 隐藏 隐藏文件，重启 finder 生效

```cmd
$ defaults write com.apple.finder AppleShowAllFiles -bool false
```



#### 重启 Finder

```cmd
$ killall Finder
```



#### 资源库

###### 显示资源库

```cmd
$ chflags nohidden ~/Library/
```

###### 隐藏资源库

```cmd
$ chflags hidden ~/Library/
```



#### Finder 标题栏显示完整路径，重启 Finder 生效

```cmd
$ defaults write com.apple.finder _FXShowPosixPathInTitle -bool YES
```



#### 其他命令

```cmd
// 显示单个文件，重启Finder生效
$ chflags nohidden <file>
// 隐藏单个文件，重启Finder生效
$ chflags hidden <file>
// 删除废纸篓中某个或某几个文件
$ sudo rm - rf <file>

// 查看当前目录文件
$ ls
// 进入目录
$ cd filepath
// 显示当前目录的路径名 
$ pwd

// 创建文件夹
$ mkdir <file> 
// 删除文件夹
$ rmdir <file>
// 删除文件文件夹 `-r` 删除文件夹内的子文件夹及内容 `-f` 强制删除参数
$ rm -rf <file>

// 可以创建文件
$ touch <file>
// 把file重名名为newfile
$ mv <file> <newfile>
// 查看文件类型
$ file <file>
// 查看文件内容
$ cat <file> 
// 查看文件编码
$ vi
// 进入编辑状态
$ i 

// 显示系统的当前日期和时间
$ date
// 显示日历
$ cal 
// 显示日历 2020年1月
$ cal 01 2020
```









