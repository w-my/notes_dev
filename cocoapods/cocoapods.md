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

##### 安装RVM

`RVM` 是干什么的这里就不解释了，后面你将会慢慢搞明白。

```sh
$ curl -L https://get.rvm.io | bash -s stable
```
期间可能会问你 `sudo` 管理员密码，以及自动通过 `homebrew` 安装依赖包，等待一段时间后就可以成功安装好  `RVM` 。
然后，载入 `RVM` 环境（新开 `Termal` 就不用这么做了，会自动重新载入的）

```sh
$ source ~/.rvm/scripts/rvm
```
检查一下是否安装正确
```sh
$ rvm -v
=> log
rvm 1.22.17 (stable) by Wayne E. Seguin <wayneeseguin@gmail.com>, Michal Papis <mpapis@gmail.com> [https://rvm.io/]
```
2、用 `RVM` 安装 `Ruby` 环境
列出已知的 `ruby` 版本

```sh
$ rvm list known
```
可以选择现有的rvm版本来进行安装（下面以rvm 2.0.0版本的安装为例）
```sh
$ rvm install 2.4
```
提示输入 `Enter` 时，输入 `Enter` 后继续
同样继续等待漫长的下载，编译过程，完成以后，`Ruby` , `Ruby Gems` 就安装好了。
另附：
查询已经安装的 `ruby`

```sh
$ rvm list
```
卸载一个已安装版本 
```sh
$ rvm remove 1.9.2
```
3、设置 `Ruby` 版本
`RVM` 装好以后，需要执行下面的命令将指定版本的 `Ruby` 设置为系统默认版本

```sh
$ rvm 2.0.0 --default
```
同样，也可以用其他版本号，前提是你有用 `rvm install` 安装过那个版本
这个时候你可以测试是否正确

```sh
$ ruby -v
ruby 2.0.0p247 (2013-06-27 revision 41674) [x86_64-darwin13.0.0]
$ gem -v
```



#### 准备工作：
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
到这里就已经把Ruby环境成功的安装到了Mac OS X上，接下来就可以进行相应的开发使用了。
```



#### 安装cocopods

```sh
$ sudo gem install cocoapods（步骤有点慢，不要急）
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

