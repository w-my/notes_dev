



~ Xcode 11 创建的工程在低版本设备上运行黑屏

~ 如何在模式切换时打印日志

~ iOS13中使用蓝牙

~ 推送的 deviceToken 获取到的格式发生变化

~ 模态弹出默认样式改变

~ 弃用 UISearchDisplayController

~ 弃用 MPMoviePlayerController

~ 弃用 LaunchImage

~ UIActivityIndicatorView

~ Status Bar

~ UIWebView 将被禁止提交审核

~ UISegmentedControl 默认样式改变

~ UITableView

~ UITabbar

~ UITabBarItem







## ~ Xcode 11 创建的工程在低版本设备上运行黑屏

使用 Xcode 11 创建的工程，运行设备选择 iOS 13.0 以下的设备，运行应用时会出现黑屏。这是因为 Xcode 11 默认是会创建通过 `UIScene` 管理多个 `UIWindow` 的应用，工程中除了 `AppDelegate` 外会多一个 `SceneDelegate`。

这是为了 iPadOS 的多进程准备的，也就是说 `UIWindow` 不再是 `UIApplication` 中管理，但是旧版本根本没有 `UIScene`。

**解决方法**

在 `AppDelegate` 的头文件加上：

```objective-c
@property (strong, nonatomic) UIWindow *window;
```



## ~ 如何在模式切换时打印日志

在 `Edit scheme` -> `Arguments` 中的 `Arguments Passed On Launch` 里面添加下面这行命令。

```swift
-UITraitCollectionChangeLoggingEnabled YES
```



## ~ iOS13中使用蓝牙

使用蓝牙，iOS13前需要申请权限 [NSBluetoothPeripheralUsageDescription](https://link.juejin.im/?target=https%3A%2F%2Fdeveloper.apple.com%2Fdocumentation%2Fbundleresources%2Finformation_property_list%2Fnsbluetoothperipheralusagedescription%3Flanguage%3Dobjc) ，iOS13新增权限 [NSBluetoothAlwaysUsageDescription](https://link.juejin.im/?target=https%3A%2F%2Fdeveloper.apple.com%2Fdocumentation%2Fbundleresources%2Finformation_property_list%2Fnsbluetoothalwaysusagedescription%3Flanguage%3Dobjc)。



## ~ 推送的 deviceToken 获取到的格式发生变化

原本可以直接将 `NSData` 类型的 `deviceToken` 转换成 `NSString` 字符串，然后替换掉多余的符号即可：

```objective-c
- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken {
    NSString *token = [deviceToken description];
    for (NSString *symbol in @[@" ", @"<", @">", @"-"]) {
        token = [token stringByReplacingOccurrencesOfString:symbol withString:@""];
    }
    NSLog(@"deviceToken:%@", token);
}
```

在 iOS 13 中，这种方法已经失效，`NSData`类型的 deviceToken 转换成的字符串变成了：

```objective-c
{length = 32, bytes = 0xd7f9fe34 69be14d1 fa51be22 329ac80d ... 5ad13017 b8ad0736 }
```

**解决方法**

需要进行一次数据格式处理

```objective-c
#include <arpa/inet.h>
- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken
{
    if (![deviceToken isKindOfClass:[NSData class]]) return;
    const unsigned *tokenBytes = (const unsigned *)[deviceToken bytes];
    NSString *hexToken = [NSString stringWithFormat:@"%08x%08x%08x%08x%08x%08x%08x%08x",
                          ntohl(tokenBytes[0]), ntohl(tokenBytes[1]), ntohl(tokenBytes[2]),
                          ntohl(tokenBytes[3]), ntohl(tokenBytes[4]), ntohl(tokenBytes[5]),
                          ntohl(tokenBytes[6]), ntohl(tokenBytes[7])];
    NSLog(@"deviceToken:%@",hexToken);
}
```



## ~ 模态弹出默认样式改变

在 iOS 13，使用 `presentViewController` 方式打开视图，默认是视差视图，通过下滑返回。

这是因为苹果将 `UIViewController` 的 `modalPresentationStyle` 属性的默认值改成了新加的一个枚举值  [UIModalPresentationAutomatic](https://link.juejin.im/?target=https%3A%2F%2Fdeveloper.apple.com%2Fdocumentation%2Fuikit%2Fuimodalpresentationstyle%2Fuimodalpresentationautomatic%3Flanguage%3Dobjc)，对于多数 `UIViewController`，此值会映射成 `UIModalPresentationPageSheet`。

需要注意，这种效果弹出来的页面导航栏部分是会被砍掉的，在 storyboard 中也可以看到，页面布局时需要注意导航栏的内容不要被遮挡。

还有一点注意的是，我们原来以全屏的样式弹出一个页面，那么将这个页面弹出的那个 ViewController 会依次调用 `viewWillDisappear` 和 `viewDidDisappear`。然后在这个页面被 dismiss 的时候，将他弹出的那个 ViewController 的 `viewWillAppear` 和 `viewDidAppear` 会被依次调用。然而使用默认的视差效果弹出页面，将他弹出的那个 ViewController 并不会调用这些方法，原先写在这四个函数中的代码以后都有可能会存在问题。

**解决方法**

如果视差效果的样式可以接受的话，就不需要修改；如果需要改回全屏显示的界面，需要手动设置弹出样式：

```objective-c
- (UIModalPresentationStyle)modalPresentationStyle {
    return UIModalPresentationFullScreen;
}
```



## ~ 弃用 UISearchDisplayController

在 iOS 13 中，如果还继续使用 `UISearchDisplayController` 会直接导致崩溃，崩溃信息如下：

```objective-c
*** Terminating app due to uncaught exception 'NSGenericException', reason: 'UISearchDisplayController is no longer supported when linking against this version of iOS. Please migrate your application to UISearchController.'
```

**解决方法**

使用 `UISearchController` 替换 `UISearchBar` + `UISearchDisplayController` 的组合方案。



## ~ 弃用 MPMoviePlayerController

在 iOS 9 之前播放视频可以使用 `MediaPlayer.framework` 中的MPMoviePlayerController类来完成，它支持本地视频和网络视频播放。但是在 iOS 9 开始被弃用，如果在 iOS 13 中继续使用的话会直接抛出异常：

```objective-c
*** Terminating app due to uncaught exception 'NSInvalidArgumentException', reason: 'MPMoviePlayerController is no longer available. Use AVPlayerViewController in AVKit.'
```

**解决方法**

使用 `AVFoundation` 里的 `AVPlayer` 作为视频播放控件。



## ~ 弃用 LaunchImage

iOS 8 之前我们是在`LaunchImage` 来设置启动图，每当苹果推出新的屏幕尺寸的设备，需要在 assets 里面放入对应的尺寸的启动图。在 iOS 8 苹果引入了 `LaunchScreen`，可以直接在 Storyboard 上设置启动界面样式，可以很方便适配各种屏幕。

需要注意的是，苹果在 [Modernizing Your UI for iOS 13](https://link.juejin.im/?target=https%3A%2F%2Fdeveloper.apple.com%2Fvideos%2Fplay%2Fwwdc2019%2F224%2F)   section 中提到 ，从2020年4月开始，所有支持 iOS 13 的 App 必须提供 `LaunchScreen.storyboard`，否则将无法提交到 App Store 进行审批。



## ~ UIActivityIndicatorView

之前的 `UIActivityIndicatorView` 有三种 `style` 分别为 `whiteLarge`, `white` 和 `gray`，**现在全部废弃**。

增加两种 `style` 分别为 `medium` 和 `large`，指示器颜色用 `color` 属性修改。



## ~ Status Bar

之前 `Status Bar` 有两种状态，`default` 和 `lightContent`

现在 `Status Bar` 有三种状态，`default`,  `darkContent` 和 `lightContent`

现在的 `darkContent` 对应之前的 `default`，现在的 `default` 会根据情况自动选择 `darkContent` 和 `lightContent`



## ~ UIWebView 将被禁止提交审核

在 iOS 13 推出后，苹果在 [UIWebView](https://link.juejin.im/?target=https%3A%2F%2Fdeveloper.apple.com%2Fdocumentation%2Fuikit%2Fuiwebview%3Flanguage%3Dobjc) 的说明上将其支持的系统范围定格在了 iOS 2 ~ iOS 12。如果开发者将包含 `UIWebView` api 的应用更新上传到 App Store 审核后，其将会收到包含 `ITMS-90809` 信息的回复邮件，提示你在下一次提交时将应用中 `UIWebView` 的 api 移除。

>Dear Developer,
>
>We identified one or more issues with a recent delivery for your app, "xxx". Your delivery was successful, but you may wish to correct the following issues in your next delivery:
>
>ITMS-90809: Deprecated API Usage - Apple will stop accepting submissions of apps that use UIWebView APIs . See [developer.apple.com/documentati…](https://link.juejin.im/?target=https%3A%2F%2Fdeveloper.apple.com%2Fdocumentation%2Fuikit%2Fuiwebview) for more information.
>
>After you’ve corrected the issues, you can use Xcode or Application Loader to upload a new binary to App Store Connect.
>
>Best regards,
>
>The App Store Team

**解决方法**

用 `WKWebView` 替代 `UIWebView`，确保所有 `UIWebView` 的 api 都要移除，如果需要适配 iOS 7 的可以通过 `openURL` 的方式在 `Safari` 打开。



## ~ UISegmentedControl 默认样式改变

默认样式变为白底黑字，如果设置修改过颜色的话，页面需要修改。

原本设置选中颜色的 `tintColor` 已经失效，新增了  [selectedSegmentTintColor](https://link.juejin.im/?target=https%3A%2F%2Fdeveloper.apple.com%2Fdocumentation%2Fuikit%2Fuisegmentedcontrol%2F3335209-selectedsegmenttintcolor%3Flanguage%3Dobjc) 属性用以修改选中的颜色。



## ~ UITableView

iOS 13下设置 `cell.contentView.backgroundColor` 会直接影响 cell 本身 selected 与 highlighted 效果。 建议不要对 `contentView.backgroundColor` 修改，而对 `cell` 本身进行设置。

**新增 Diffable DataSource**

在 iOS 13下，对 UITableView 与 UICollectionView 新增了一套 Diffable DataSource API。为了更高效地更新数据源刷新列表，避免了原有粗暴的刷新方法 `- (void)reloadData`，以及手动调用控制列表刷新范围的api，很容易出现计算不准确造成 NSInternalInconsistencyException 而引发App crash。

```objective-c
@interface UITableViewDiffableDataSource<__covariant SectionIdentifierType, __covariant ItemIdentifierType> : NSObject
```



## ~ UITabbar

iOS 13之后，Badge 字体默认由13号变为17号。 可以设置 Badge 的 ViewController 调用 `setBadgeTextAttributes:forState:` 方法

```objective-c
if (@available(iOS 13, *)) {
    [viewController.tabBarItem setBadgeTextAttributes:@{NSFontAttributeName: [UIFont systemFontOfSize:13]} forState:UIControlStateNormal];
    [viewController.tabBarItem setBadgeTextAttributes:@{NSFontAttributeName: [UIFont systemFontOfSize:13]} forState:UIControlStateSelected];
}
```



## ~ UITabBarItem

**加载gif需设置 scale 比例**

```objective-c
NSData *data = [NSData dataWithContentsOfFile:path];
CGImageSourceRef gifSource = CGImageSourceCreateWithData(CFBridgingRetain(data), nil);
size_t gifCount = CGImageSourceGetCount(gifSource);
CGImageRef imageRef = CGImageSourceCreateImageAtIndex(gifSource, i,NULL);

//  iOS 13之前
UIImage *image = [UIImage imageWithCGImage:imageRef]
//  iOS 13之后添加scale比例(该imageView将展示该动图效果)
UIImage *image = [UIImage imageWithCGImage:imageRef scale:image.size.width / CGRectGetWidth(imageView.frame) orientation:UIImageOrientationUp];

CGImageRelease(imageRef);
```

**无文字时图片位置调整**

iOS 13下不需要调整 `imageInsets`，图片会自动居中显示，因此只需要针对iOS 13之前的做适配即可

```objective-c
if (IOS_VERSION < 13.0) {
    viewController.tabBarItem.imageInsets = UIEdgeInsetsMake(5, 0, -5, 0);
}
```

**TabBarItem选中颜色异常**

在 iOS 13下设置 tabbarItem 字体选中状态的颜色，在push到其它 ViewController 再返回时，选中状态的 tabbarItem 颜色会变成默认的蓝色。

设置 tabbar 的 tintColor 属性为原本选中状态的颜色即可。

```objective-c
self.tabBar.tintColor = [UIColor redColor];
```



