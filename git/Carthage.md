# Carthage 包管理

在iOS开发中，我们常会用CocoaPods来进行依赖库的管理。CoaoaPods 是一套整体解决方案，我们在 `Podfile` 中指定好我们需要的第三方库，然后 CocoaPods 就会进行下载，集成，然后修改或者创建我们项目的 `workspace` 文件。

　　相比之下，`Carthage` 就要轻量很多，它也需要一个叫做 `Cartfile` 的描述文件，但 `Carthage` **不会对我们的项目结构进行任何修改**，更不多创建 `workspace`。它只是根据我们描述文件中配置的第三方库，将它们下载到本地，然后使用 `xcodebuild` 构建成 `framework` 文件。然后由我们自己将这些库集成到项目中。`Carthage`使用的是一种**非侵入性**的哲学。作为开发者，必须在 `Carthage` 将第三方库构建完成后，手动的关联到项目中。

　　另外 `Carthage` 除了**非侵入性**，它还是**去中心化**的，它的包管理不像 `CocoaPods` 那样，有一个中心服务器([cocoapods.org](http://cocoapods.org/))，来管理各个包的元信息，而是依赖于每个第三方库自己的源地址，比如 `Github`。这样也是有利有弊，好处就是我们对包管理不再依赖中心服务器，不会受中心服务器信息量和稳定性的限制(尤其是在我们这里的网络访问状况问题)，弊端就是我们想查找第三方库的时候，也没有一个中心服务器来帮助我们进行索引，而是必须从网络上自行查找。

## 1. 安装Carthage

- 打开终端，输入如下指令：

```sh
brew update
brew install carthage
```

安装完成后，在终端执行如下指令，可以查看当前carthage的版本：

```sh
carthage version
```

## 2. 使用Carthage

- 第一步：通过终端进入你的项目文件夹，示例如下：

```
$ cd /dev/iOS-demo
```

- 第二步：创建一个空的carthage文件，指令如下：

```
$ touch Cartfile
```

　　此时项目文件夹里会创建一个名为Cartfile的文件。

- 第三步：使用xcode打开Cartfile文件：

```
$ open -a Xcode Cartfile
```

　　在打开的文件中输入你所要导入的第三方库，示例所示：

```
github "Alamofire/Alamofire"
github "SwiftyJSON/SwiftyJSON"
```

　　当然也可以指定版本号，没有指明版本号的时候，则会自动使用最新的版本。指定版本号示例：

```
github "Alamofire/Alamofire" ~> 3.4.0
```

- 第四步：保存并关闭Cartfile文件，在终端执行如下命令：

```
$ carthage update --platform iOS
```

　　carthage会为你**下载和编译**所需要的第三方库，当命令执行完毕，在你的项目文件夹中会创建一个名为Carthage的文件夹。在 ~/Carthage/Build/iOS里会出现framework和dSYM文件，如下所示：

![img](http://images2015.cnblogs.com/blog/992921/201608/992921-20160801170306512-1336153488.png)

　　【说明】：

1. 由于此处只需要导入iOS平台下的库，所以指定了平台，如果需要全部库，那么去掉后面的"--platform iOS"即可。
2. **Build** 中存放的是构建好的 **framework** 包；
3. **Checkouts** 中存放的是第三方库项目源文件。

-  第五步：回到项目设置，进入 **General** 选项卡，在最下方的 **Linked Frameworks and Libraries** 中，将**Carthage/Build/iOS** 中的 **framework** 文件添加到项目中，如下图所示：

![img](http://images2015.cnblogs.com/blog/992921/201608/992921-20160801172938418-995937339.png)

- 第六步：在 **Build Phrases** 中，点击左上角的 + 号，添加一个 **New Run Script Phrase**，在脚本区域输入: 

```
/usr/local/bin/carthage copy-frameworks
```

　　最后将 **Alamofire** 和 **SwiftyJSON** 的路径添加到 Input Files 中，如下图所示：

![img](http://images2015.cnblogs.com/blog/992921/201608/992921-20160801174021200-18368543.png)

　　添加这个 **Run Script** 的作用是为了让运行时能够找到这个动态库。这点 **Carthage** 官方文档中没有太明确的说明。我实际的实验过，如果不添加这个 `copy-frameworks` 脚本，那么项目在运行的时候会因为找不到这个动态库而在启动的时候崩溃。

## 3. 使用导入库

　　生成和配置好第三方库之后，我们可以很简单的来使用，直接在要使用的文件中导入，示例如下：

```
import Alamofire
import SwiftyJSON
```

##  4. 附录

　　如果需要在调试时进入第三方库内部的代码，那么可以参看下面部分的内容。

　　进入 **Build Phrases** ，然后在右上角点击 **New Copy Files Phrase**，然后将**Carthage/Build/iOS** 目录中的 **dSYM** 符号文件拖动进来，如下图所示：

![img](https://images2015.cnblogs.com/blog/992921/201608/992921-20160801211913356-1948042951.png)

　　这样项目在运行后，就可以在断点中步入 **第三方库** 内部的代码进行调试。

　　如果在导入dSYM文件遇到编译错误，那么检查一下如下配置项，确保其值为**NO**：

![img](https://images2015.cnblogs.com/blog/992921/201608/992921-20160801212121684-661282749.png)
