##  CocoaPods 使用

#### 清除历史旧数据

全新安装前，先检查是否有安装残留，如果之前装过 `cocopods` ，最好先卸载掉，卸载命令：

```sh
$ sudo gem uninstall cocoapods
```
先查看本地安装过的 `cocopods` 相关东西，命令如下：
```sh
$ gem list --local | grep cocoapods

=> log
cocoapods-core (0.39.0)
cocoapods-downloader (0.9.3)
cocoapods-plugins (0.4.2)
cocoapods-search (0.1.0)
cocoapods-stats (0.6.2)
cocoapods-trunk (0.6.4)
cocoapods-try (0.5.1)
```
然后逐个删除吧：
```sh
$ sudo gem uninstall cocoapods-core
```

先把Mac隐藏文件夹显示出来：

```sh
$ defaults write com.apple.finder AppleShowAllFiles -bool false
```
重启Finder

```sh
$ killall Finder
```

如果不确定，可以把主目录下的隐藏文件都给删了，重新安装 `Ruby` 和 `cocopods` 。



#### 总体步骤

Xcode—>Homebrew—>rvm—>ruby—>cocopods



##### Homebrew

Homebrew是一款Mac OS平台下的软件包管理工具，拥有`安装`、`卸载`、`更新`、`查看`、`搜索`等很多实用的功能。简单的一条指令，就可以实现包管理，而不用你关心各种依赖和文件路径的情况，十分方便快捷。所以我们需要下载Homebrew来安装Ruby。

**安装HomeBrew：**

1.打开终端，输入一下命令，地址选择的国内的地址来下载安装Homebrew。然后等待...

```bash
/bin/zsh -c "$(curl -fsSL https://gitee.com/cunkai/HomebrewCN/raw/master/Homebrew.sh)"
```

**`Ps`**：建议选用中科大，如果安装Homebrew中间遇到了文件目录问题可以使用[这篇文章](https://links.jianshu.com/go?to=https%3A%2F%2Fzhuanlan.zhihu.com%2Fp%2F259222579)的方法。由于我已经安装过了所以重新安装会删除之前的软件。

> **关于Homebrew：**
> 1.Homebrew的命令是以brew开头 例如：brew -v 查看Homebrew版本
> 2.Homebrew 的默认安装目录为 /usr/local
> 3.通过 brew 安装的程序都会默认安装到 /usr/local/Cellars/程序名/版本号/ 目录下
>
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



##### RVM

> RVM 全称是 ruby version manager， 是一个命令行工具，可以提供一个便捷的多版本 ruby 环境的管理和切换。所以我们需要下载RVM来方便我们管理Ruby。

**`Ps`**：RVM 不仅可以提供一个多 Ruby 版本共存的环境，还可以根据项目管理不同的 gemset.gemset 可以理解为是一个独立的虚拟 Gem 环境，每一个 gemset 都是相互独立的。

**安装rvm：**

1.打开终端，如果没有安装 curl，先使用命令安装 curl (Mac一般是自带的)

```sh
curl sudo apt-get install curl
```

2.终端中输入安装 RVM 的命令。

```sh
curl -sSL https://get.rvm.io | bash -s stable
```

3.加载 RVM(**加载后才能使用！！**)

```sh
source ~/.rvm/scripts/rvm
```

> 如果安装rvm中遇到
> `Failed to connect to raw.githubusercontent.com port 443: Connection refused` 大概率是因为raw.githubusercontent.com域名解析被污染导致的。可以按照下面步骤操作
>
> 1.查询aw.githubusercontent.com域名真实IP 在[https://www.ipaddress.com/](https://links.jianshu.com/go?to=https%3A%2F%2Fwww.ipaddress.com%2F)查询raw.githubusercontent.com的真实IP。
>
> 2.进入/etc/hosts 修改hosts文件内容
>
> - 2.1通过finder->前往->前往文件夹
> - 2.2输入/etc/hosts后在当前文件夹中找hosts 文件。
> - 2.3到把hosts 文件复制到桌面，然后用文本编辑器打开 加上你查询到的ip地址
>   例如：199.232.96.133 raw.githubusercontent.com
> - 2.4保存编辑好的hosts 文件，并替换/etc/hosts中的hosts 文件。
> - 2.5然后在重新按照上面的步骤安装RVM



> **RVM使用相关命名：**
> rvm list known：查看ruby版本
> rvm install 版本号：下载指定版本的ruby，例如：rvm install 2.4.0
> rvm -v：查看rvm版本
> rvm use 版本号：切换ruby版本，例如：rvm use 2.2.0
> rvm use 版本号 --default ：切换并设置ruby版本为默认版本，例如：rvm use 2.2.0 --default
> rvm remove 版本号：移除指定版本的ruby，例如：rvm remove 2.2.0
> rvm implode：卸载

##### ruby

> Ruby，一种简单快捷的面向对象（面向对象程序设计）脚本语言，在20世纪90年代由日本人松本行弘(Yukihiro Matsumoto)开发，遵守GPL协议和Ruby License。Ruby 的特性与 `Smalltalk`、`Perl` 和 `Python` 类似。Perl、Python 和 Smalltalk 是脚本语言。Smalltalk 是一个真正的面向对象语言。Ruby，与 Smalltalk 一样，是一个完美的面向对象语言。使用 Ruby 的语法比使用 Smalltalk 的语法要容易得多。`cocoapods就是基于ruby语言编写而成的`。因此要真的很会用cocoapods，还是需要学习ruby语言的。

**安装ruby**

1.打开终端，通过rvm查看ruby有哪些版本

```sh
rvm list known
```

2.然后选择你需要下载的版本，这里选择的是2.7版本

```sh
rvm install 2.7
```

##### 什么是RubyGems

> RubyGems（简称 gems）是一个用于对 Ruby组件进行打包的 Ruby 打包系统。 它提供一个分发 Ruby 程序和库的标准格式，还提供一个管理程序包安装的工具。RubyGems的功能类似于Linux下的apt-get。使用它可以方便的从远程服务器下载并安装Rails。**`一般使用rvm安装ruby后，会自带RubyGems`**。所以下载ruby后使用命令 gem -v 查看一下是否已安装了Gem。
>
> Gem使用相关命令：
> gem -v ： 查看 gem 版本
> gem source ： 查看 gem 配置源
> gem source -l ： 查看 gem 配置源目录
> gem sources -a url ： 添加 gem 配置源（url 需换成网址）
> gem sources --add url ： 添加 gem 配置源（url 需换成网址）
> gem sources -r url ： 删除 gem 配置源（url 需换成网址）
> gem sources --remove url ： 删除 gem 配置源（url 需换成网址）
> gem update ：更新 所有包
> gem update --system ：更新 Ruby Gems 软件
> sudo gem -v ：查看 gem 版本（以管理员权限）
> sudo gem install cocoa pods ： 安装 CocoaPods（以管理员权限）
> sudo gem install cocoapods ： 安装 CocoaPods（以管理员权限）
> sudo gem install cocoapods --pre ： 安装 CocoaPods 至预览版（以管理员权限）
> sudo gem install cocoapods -v 0.39.0 ： 安装 CocoaPods 指定版本（以管理员权限）
> sudo gem update cocoapods ： 更新 CocoaPods 至最新版（以管理员权限）
> sudo gem update cocoapods --pre ： 更新 CocoaPods 至预览版（以管理员权限）
> sudo gem uninstall cocoapods -v 0.39.0 ： 移除 CocoaPods 指定版本（以管理员权限）



##### M1 MacBook

找到终端，右键选择显示简介，勾选使用Rosetta打开，这个一定要勾选。

新电脑基本都安装好了最新的roby了，可以查看下版本和sources

```sh
$ ruby -v
$ gem sources
```



##### 准备工作：
首先要切换到 [Ruby China 镜像](http://gems.ruby-china.com/) 
镜像服务器，不然下面各个步骤会很慢甚至没有进展，这有可能是因为 `Ruby` 的默认源使用的是 `cocoapods.org` ，国内访问这个网址有时候会有问题，网上的一种解决方案是将源替换成 `RubyChina` 的。
查询：

```sh
$ gem sources -l 
```
可以查看当前是什么连接，然后替换方式如下：
```sh
$ gem source -r https://rubygems.org/
$ gem source -a https://gems.ruby-china.com/ 
或
$ gem sources --add https://gems.ruby-china.com/ --remove https://rubygems.org/
$ gem sources -l
正常的输出结果：
*** CURRENT SOURCES ***
$ https://gems.ruby-china.com
`请确保只有 gems.ruby-china.com`
$ gem install rails
```
 要想验证是否替换成功了，可以执行：
```sh
$ gem sources -l  
正常的输出结果：
　　　　　　CURRENT SOURCES　　　　　　　　　　　　
　　　　　　https://gems.ruby-china.com/　　　　　　　　　　　　
到这里就已经把Ruby环境成功的安装到了Mac上，接下来就可以进行相应的开发使用了。
```



#### 安装cocopods

```sh
$ sudo gem install cocoapods（步骤有点慢，不要急）
这里大概率会遇到报错，告诉你没有读写/usr/bin的权限，两种选择，一是重启进入保护模式，修改读写权限，太麻烦了，所以我们用第二种处理方式，
$ sudo gem install cocoapods -n /usr/local/bin
完成之后运行
$ sudo gem install ffi
最后运行
$ pod setup（步骤有点慢，不要急）
```



#### 使用CocoaPods

`cd` 到项目所在目录，利用 `vim` 创建 `Podfile` 文件。

```sh
$ vim Podfile
```
按键盘 `i` 进入 `Podfile` 文件的编辑状态，输入如下：
```sh
platform :ios, '8.0'
target 'MyApp' do
    pod 'AFNetworking', '~> 3.0'
end
swift如下：
source 'https://github.com/CocoaPods/Specs.git'
platform :ios, '10.0'
use_frameworks!
target '<Your Target Name>' do
    pod 'Alamofire', '~> 4.7'
    pod 'SnapKit', '~> 4.0.0'
end
```

然后按 `esc` 输入 `$ :wq` 保存并退出，这时，就会在项目目录中出现 `Podfile` 文件。`Podfile` 文件应该和工程文件.xcodeproj在同一个目录下。也可输入 `$ vi Podfile` 再次进入编辑。
之后就可以利用CocoPods导入AFNetworking类库

```sh
$ pod install
```
查看最新的类库
```sh
$ pod search AFNetworking
```
修改 `Podfile` 文件
```sh
$ vi Podfile
```
更新引入类库
```sh
$ pod update
```
注意：
`$ pod install `只会按照 `Podfile` 的要求来请求类库，如果类库版本号有变化，那么将获取失败。但是  `$ pod update `会更新所有的类库，获取最新版本的类库。每次更改了 `Podfile` 文件，都需要执行 `$ pod update` 命令。
当执行 `pod install` 之后，除了 `Podfile` 之外，还会生成一个 `Podfile.lock` 文件，不应该把这个问题件引入到版本控制中，应为这个文件将锁定当前各依赖库的版本，之后多次执行 `pod install` 也不会更改版本，只有执行 `pod update` 才会改变  `Podfile.lock`  文件。因此，在多人协作开发中，版本控制中不要引入 `Podfile.lock` 文件，防止升级时造成大家的三方库版本都不一致。

- 举个 `Podfile` 文件的栗子：
```sh
platform :ios, '8.0'
target 'CocoapodsTest' do
    pod 'AFNetworking'
    pod 'Masonry'
    pod 'SVProgressHUD'
    pod 'FMDB'
    pod 'MJRefresh'
    pod 'Base64'
    pod 'RTRootNavigationController'
end
```



```sh
$ pod repo update --verbose
$ pod update --verbose --no-repo-update

// 私有库
$ pod repo add <filename> <url>
```



##### 问题1

###### CocoaPods 【warning: Insecure world writable dir /usr/local/bin in PATH, mode 040777】

目录被赋予777的权限，不安全。

解决：将提示权限改为775，问题即可解决。

``` sh
$ sudo chmod go-w /usr/local/bin
$ sudo chmod 775 /usr/local
```



##### 问题2

###### 首次CocoaPods拉取repos过慢

在GitHub上下载CocoaPods/Specs项目

> 地址：[https://github.com/CocoaPods/Specs](https://links.jianshu.com/go?to=https%3A%2F%2Fgithub.com%2FCocoaPods%2FSpecs)

将解压所得到的三个文件（Specs / CocoaPods-version.yml / README.md）拷贝至/Users/电脑用户名/.cocoapods/repos/master文件夹中

打开Git远端仓库 

> 打开master路径：cd ~/.cocoapods/repos/master
>
> 初始化git：git init
>
> 关联仓库：git remote add origin https://github.com/CocoaPods/Specs

验证是否成功

> 终端输入：pod repo，如果输出以下信息 说明没问题：
>
> mater
>
> URL: https://github.com/CocoaPods/Specs.git
>
> Path: /Users/电脑用户名/.cocoapods/repos/master

 

##### 问题3

###### RPC failed; curl 56 LibreSSL SSL_read: SSL_ERROR_SYSCALL, errno 60

###### 尝试1 ：

确定gem 版本 sudo gem update —system 
确定pod update (更新项目podfile) 
确定repo 最新 pod repo update 或者 pod repo update —verbose 
最后 重新pod setup

###### 尝试2 ：

重装cocoapods 
终端 gem list 查找cocoa 开头配置 全部移除 sudo uninstall cocoapods-xxx 
重新安装 cocoapods sudo gem install -n /usr/local/bin cocoapods 
重新下载GitHub spec 既 ./cocoapods 目录下repo 文件中的内容 pod setup

###### 尝试3：

删除./cocoapods 目录下repo 文件中所有文件 
重新pod setup 或者直接到spec GitHub 地址 直接下载下来更改文件名称为 master 拖进repos 文件目录下，并进入repos git pull 
或者是直接pod setup