# 运行错误记录



## M1 Mac 引用 YYKit 模拟器运行报错

> In /Users/xxx/Pods/YYKit/Vendor/WebP.framework/WebP(anim_decode.o), building for iOS Simulator, but linking in object file built for iOS, file '/Users/xxx/Pods/YYKit/Vendor/WebP.framework/WebP' for architecture arm64

解决方法：

1. 项目添加 `arm64`：打开路径：`左侧项目名一级目录` -> `PROJECT` -> `项目名` -> `Build Settings` -> `Excluded Architectures` 里面在 `Debug` 和 `Release` 模式下，分别添加：`Any iOS Simulator SDK` ->  `arm64`；
2. `Pod` 添加 `arm64`：打开路径：`左侧Pods一级目录` -> `PROJECT` -> `Pods` -> `Build Settings` -> `Excluded Architectures` 里面在`Debug`和`Release`模式下，分别添加：`Any iOS Simulator SDK` -> `arm64`；



## XCode15 运行 MBProgressHUD 抛错

```[(id)indicator setProgress:progress];``` 报如下错误：

`Multiple methods named 'setProgress:' found with mismatched result, parameter type or attributes`

**fix：**

id -> UIProgressView *

```[(UIProgressView *)indicator setProgress:progress];```



## libarclite

**error:**

```
SDK does not contain 'libarclite' at the path 
'/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/
lib/arc/libarclite_iphonesimulator.a'; try increasing the minimum deployment target
```

**fix:**

这个路径: 缺少文件, 那么进入这个路径进行查看

```undefined
/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/
lib/
```

报错的情况下没有 arc 文件夹,也没有 libarclite_iphonesimulator.a 文件,
 1、新建arc文件夹
 2、下载:[https://github.com/kamyarelyasi/Libarclite-Files](https://links.jianshu.com/go?to=https%3A%2F%2Fgithub.com%2Fkamyarelyasi%2FLibarclite-Files)中的libarclite_iphonesimulator.a
 3、将下载下来的文件粘贴到/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/arc下



**error:**

```
SDK does not contain 'libarclite' at the path '/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/arc/libarclite_iphoneos.a'; try increasing the minimum deployment target
```

**fix:**

如果是真机调试运行会出现iPhone.a文件丢失
  		1. 新建arc文件夹
  		2. 下载:https://github.com/kamyarelyasi/Libarclite-Files中的libarclite_iphoneos.a
  		3. 将下载下来的文件粘贴到/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/arc下
  		4. 重新运行后将修复这个问题
