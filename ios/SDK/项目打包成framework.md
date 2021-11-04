# iOS项目打包成.framework

## 创建项目

两个项目 `Demo` 和 `Test`  ，一个Framework `DeomSDK` :

- `Demo` 将要被打包成 SDK 的项目

- `DemoFramework` 将项目打包成的 Framework

- `Test` 测试打包成的 Framework

三个项目都添加 `Podfile` 文件，`pod install` 初始化三方库，用来测试三方库的打包。

`Demo` 中使用pod引入的三方库，在 `DemoSDK` 和 `Test` 中同样需要通过pod引入。

```sh
inhibit_all_warnings!

platform :ios, '9.0'

target 'XXXx' do
  pod 'Masonry'
  pod 'SVProgressHUD'
end
```



## Demo

包含内容：三方库、pch文件、图片 xib 等文件



## DemoFramework

#### 导入项目

打开被打包项目目录，将与 `.xcodeproj` 同级的项目文件夹，直接拖进 `framework` 项目中。

#### 修改设置

##### General

- Deployment Info ：设置支持的版本，支持的设备

##### Build Settings

- Architectures
  - Build Active Architecture Only ：设置为NO（YES打包的Framework，只能用于当前打包所选设备使用）
  - Architectures ：模拟器下添加 armv7s，真机模式下不要添加，否则会报错
- Linking
  - Mach-O Type ：设置为 Static Library（非官方Framework只能使用静态模式）

- Apple Clang - Language
  - Prefix Header ：设置 pch 文件路径（如： `DemoFramework/Demo/PrefixHeader.pch`）

###### Build Phases

- Headers 
  - Public ：设置对外暴露的接口（需要暴露的 `.h` 文件，同时需要在创建 Framework 项目自动生成的 `.h` 头文件中，按指定格式 `import` 。如：`#import <DemoFramework/PublicHeader.h>` ）
  - Project ：设置需要引入 framework 的文件，删除 `AppDelegate.h` ，否则 framework 被导入项目中，和项目中的 `AppDelegate.h` 文件冲突。
- Link Binary With Libraries ：手动添加项目使用到的未自动添加进来的库
- Copy Bundle Resources ：删除 `info.plist` 文件

#### 修改项目

##### 三方库

`framework` 和使用 `framework` 的项目同样需要导入 `被打包项目` 中使用的三方库

##### pch 文件

需要在 `framework` 中，配置 `pch` 文件路径

##### 图片、xib 等

需要打包成 `Bundle` ，同样需要导入到 `framework` 和使用 `framework` 的项目

```objective-c
[UIImage imageNamed:@"DemoFramework.bundle/nav_goback"];
```

```objective-c
NSBundle *bundle = [NSBundle bundleWithPath:[[NSBundle mainBundle]
												 pathForResource:@"DemoFramework"
												 ofType:@"bundle"]];
	self = [bundle loadNibNamed:NSStringFromClass([self class])
						  owner:self
						options:nil].lastObject;
```

##### plist 文件

同图片一样

或

把plist文件拖进framework中，重新编译framework，把重新编译的framework和plist文件都拖到demo中，这样就可以使用plist文件了



#### 生成 framework

选择真机和模拟器分别编译一下，生成真机和模拟器framework，使用命令合并framework

```sh
lipo -create /Users/xx/Desktop/DemoFramework/Build/Products/Debug-iphoneos/DemoFramework.framework/DemoFramework /Users/xx/Desktop/DemoFramework/Build/Products/Debug-iphonesimulator/DemoFramework.framework/DemoFramework -output /Users/yq/Desktop/sdk
```

会生成一个 `.lipo` 文件，把它重命名为 `DemoFramework` ，然后就可以拿去使用了。

#### 脚本生成 framework

在 `TARGETS` 点击 `+` ，选择 `Other` 下的 `Aggregate` ，创建项目 `FrameRunScript`

选中脚本，选择 `Build Phases` ，点击 `+` ，选择 `New Run Script Phase` 

在添加脚本位置，添加如下脚本命令，然后选择 `Any ios Device` 执行 `Commond + B`

```sh
```





## 打包 bundle

#### 创建 bundle

新建项目，选择 macOS -> Bundle 创建

#### 修改设置

TARGETS 选中创建的 target，修改配置

##### Build Settings

- Architectures
  - Base SDK ：改为 iOS
- User-Defined
  - COMBINE_HIDPI_IMAGES ：改为 NO（否则Bundle图片格式就会为tiff格式）
- Deployment
  - Skip Install ：改为 NO（作为资源包只需要编译就好，不需要安装相关配置，同时删除Installation Directory的键值）
  - Installation Directory ：删除值

##### Build Phases

- Copy Bundle Resources ：添加需要打包的文件

#### 生成 bundle

选择新创建的 bundle 的 Scheme，运行，会在 Products 文件夹下生成 bundle 文件，就那个导入到 framework 项目中 或 导入到测试项目中使用了。



## Test

#### 使用

导入 framework 和 bundle 文件；

引入 framework 中使用的三方库；





## 使用自己打包的framework错误

- `ld: warning: Could not find or use auto-linked framework 'XxxFramework'` 或 `ld: 2 duplicate symbols for architecture arm64`

如果自己的 `framework` 中使用的第三方 `framework`，则需要将第三方改为 `.a` 引入使用



## framework中使用其他的framework库

以支付宝为例，新建文件夹，找到 `AlipaySDK.framework` 里 `AlipaySDK` 修改其后缀名为.a并copy 此 `framework` 包内所有文件到新建的文件夹，然后导入到需要打包的项目中

> 注：1.如果framework使用categary需在引用的项目中target->build setting->other link flag 中添加 -ObjC
>  2.若打包的framework使用了三方库，那么引用的项目也需导入三方库所需的系统库

如果使用打包完的 `Framework` 有出现崩溃的情况，可以考虑在项目 `Other linker flags` 中加入一些参数，三个常用参数：

>-ObjC：加了这个参数后，链接器就会把静态库中所有的 Objective-C 类和分类都加载到最后的可执行文件中。
>
>-all_load：会让链接器把所有找到的目标文件都加载到可执行文件中，但是千万不要随便使用这个参数！假如你使用了不止一个静态库文件，然后又使用了这个参数，那么你很有可能会遇到 ld: duplicate symbol 错误，因为不同的库文件里面可能会有相同的目标文件，所以建议在遇到 -ObjC 失效的情况下使用 -force_load 参数。
>
>-force_load：所做的事情跟 -all_load 其实是一样的，但是 -force_load 需要指定要进行全部加载的库文件的路径，这样的话，你就只是完全加载了一个库文件，不影响其余库文件的按需加载。









## Framework 打包错误

- The linked library 'xxxx.a/Framework' is missing one or more architectures required by this target: armv7.

解决方法：在 TARGETS ——> Build Settings-Excluded Architectures 中添加以下代码：

```sh
EXCLUDED_ARCHS__EFFECTIVE_PLATFORM_SUFFIX_simulator__NATIVE_ARCH_64_BIT_x86_64=arm64 arm64e armv7 armv7s armv6 armv8 EXCLUDED_ARCHS=$(inherited) $(EXCLUDED_ARCHS__EFFECTIVE_PLATFORM_SUFFIX_$(EFFECTIVE_PLATFORM_SUFFIX)__NATIVE_ARCH_64_BIT_$(NATIVE_ARCH_64_BIT))
```



