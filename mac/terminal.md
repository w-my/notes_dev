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









