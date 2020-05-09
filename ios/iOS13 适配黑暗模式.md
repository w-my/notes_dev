# iOS13 适配黑暗模式 DarkMode

**禁用黑暗模式**

在Info.plist 文件中，添加`UIUserInterfaceStyle` 设置为 `Light`

**适配**

主要是两个方面：颜色、图片



#### 颜色适配

iOS13 `UIColor` 是一个动态颜色，可以在 `LightMode` 和 `DarkMode` 拥有不同的颜色。

```swift
// UIColor 增加的颜色
@available(iOS 13.0, *)
open class var systemBackground: UIColor { get }
@available(iOS 13.0, *)
open class var label: UIColor { get }
@available(iOS 13.0, *)
open class var placeholderText: UIColor { get }
...

view.backgroundColor = UIColor.systemBackground
label.textColor = UIColor.label
placeholderLabel.textColor = UIColor.placeholderText
```

##### 如何自己创建一个动态的 UIColor

通过iOS13 `UIColor` 新增初始化方法，创建动态颜色。

```swift
@available(iOS 13.0, *)
public init(dynamicProvider: @escaping (UITraitCollection) -> UIColor)
```

这个方法要求传一个闭包进去，当系统从 LightMode 和 DarkMode 之间切换的时候就会触发这个回调。

这个闭包返回一个 `UITraitCollection` 类，这个类的 `userInterfaceStyle` 属性是一个枚举：

```swift
@available(iOS 12.0, *)
public enum UIUserInterfaceStyle : Int {
    case unspecified
    case light
    case dark
}
```

通过 `userInterfaceStyle` 这个枚举，可以知道当前是 LightMode or DarkMode。

```swift
let backgroundColor = UIColor { (trainCollection) -> UIColor in
    if trainCollection.userInterfaceStyle == .dark {
        return UIColor.black
    } else {
        return UIColor.white
    }
}
view.backgroundColor = backgroundColor

let labelColor = UIColor { (trainCollection) -> UIColor in
    if trainCollection.userInterfaceStyle == .dark {
        return UIColor.white
    } else {
        return UIColor.black
    }
}
label.textColor = labelColor
```



#### 图片适配

打开 `Assets.xcassets`，添加图片后右侧工具栏中 `Appearances` 可以选择 `Any, Dark`，然后添加必要的图片就可以了。

```swift
imageView.image = UIImage(named: "icon")
```



#### UIVisualEffectView适配

```objective-c
UIBlurEffectStyle style;
if (@available(iOS 13.0, *)) {
    style = UIBlurEffectStyleSystemMaterial;
}else {
    style = UIBlurEffectStyleLight;
}
UIVisualEffectView *visualEffectView = [[UIVisualEffectView alloc] initWithEffect:[UIBlurEffect effectWithStyle:style]];
```



## 获取当前模式（Light or Dark）

颜色和图片，适配都是系统自动完成的。但在某些场景下需要获取当前视图的样式，可以在 `UIViewController` 或 `UIView` 中调用 `traitCollection.userInterfaceStyle` 来获取，代码如下：

```swiftj
if trainCollection.userInterfaceStyle == .dark {
    // Dark
} else {
    // Light
}
```



#### 颜色

对于 `CGColor` 还有还有另一种适配方法，`resolvedColor` 方法会根据传递进去的 `traitCollection` 返回对应的颜色，代码如下

```swift
let resolvedColor = labelColor.resolvedColor(with: traitCollection)
layer.borderColor = resolvedColor.cgColor
```



####  图片

对于 `UIImage` 也有类似的方法，代码如下

```swift
let image = UIImage(named: "icon")
let resovledImage = image?.imageAsset?.image(with: traitCollection)
```



## 监听模式变化

```swift
override func traitCollectionDidChange(_ previousTraitCollection: UITraitCollection?) {
    super.traitCollectionDidChange(previousTraitCollection)
    if traitCollection.hasDifferentColorAppearance(comparedTo: previousTraitCollection) {
        // 适配代码
    }
}
```



## 改变当前模式

```swift
overrideUserInterfaceStyle = .dark
print(traitCollection.userInterfaceStyle)  // dark
```

设置了 `overrideUserInterfaceStyle` 之后，`traitCollection.userInterfaceStyle` 就是设置后的模式了。



**需要给每一个 Controller 和 View 都设置一遍吗（不需要）**

当设置一个 controller 为 dark 之后，这个 controller 下的 view，都会是 dark mode，但是后续推出的 controller 仍然是跟随系统的样式。

因为苹果对 `overrideUserInterfaceStyle` 属性的解释是这样的。

但是当我们在 `window` 上设置 `overrideUserInterfaceStyle` 的时候，就会影响 `window` 下所有的 controller, view，包括后续推出的 controller。

如果想全局控制 App 打开夜间模式，那么只需要设置 `window` 的 `overrideUserInterfaceStyle` 属性就好了。

```swift
// 实际项目中，如果是iOS应用这么写没问题，但是对于iPadOS应用还需要判断scene的状态是否激活
let scene = UIApplication.shared.connectedScenes.first?.delegate as? SceneDelegate
scene?.window?.overrideUserInterfaceStyle = .dark
```



## 系统模式变更时，系统会通知所有 View 及 ViewController 更新样式，会触发以下方法：

###### NSView

```objective-c
- (void)updateLayer;
- (void)drawRect:(NSRect)dirtyRect;
- (void)layout;
- (void)updateConstraints;
```

###### UIView

```objective-c
- (void)traitCollectionDidChange:(UITraitCollection *)previousTraitCollection;
- (void)layoutSubviews;
- (void)drawRect:(NSRect)dirtyRect;
- (void)updateConstraints;
- (void)tintColorDidChange;
```

###### UIViewController

```objective-c
- (void)traitCollectionDidChange:(UITraitCollection *)previousTraitCollection;
- (void)updateViewConstraints;
- (void)viewWillLayoutSubviews;
- (void)viewDidLayoutSubviews;
```

###### UIPresentationController

```objective-c
- (void)traitCollectionDidChange:(UITraitCollection *)previousTraitCollection;
- (void)containerViewWillLayoutSubviews;
- (void)containerViewDidLayoutSubviews;
```

###### UIColor扩展
```swift
extension UIColor {
    /// 动态颜色
    /// - Parameters:
    ///   - lightColor: lightColor
    ///   - darkColor: darkColor
    static func dy_color(lightColor: UIColor, darkColor: UIColor) -> UIColor {
        guard #available(iOS 13.0, *) else {
            return lightColor
        }
        
        return UIColor.init { (trainCollection: UITraitCollection) -> UIColor in
            if trainCollection.userInterfaceStyle == .dark {
                return darkColor
            }else {
                return lightColor
            }
        }
    }

    /// 动态颜色(16进制)
    /// - Parameters:
    ///   - lightColor: lightColor
    ///   - darkColor: darkColor
    static func dy_color(lightColor: Int, darkColor: Int) -> UIColor {
        guard #available(iOS 13.0, *) else {
            return UIColor.y_hex(hex: lightColor)
        }
        
        return UIColor.init { (trainCollection: UITraitCollection) -> UIColor in
            if trainCollection.userInterfaceStyle == .dark {
                return UIColor.y_hex(hex: darkColor)
            }else {
                return UIColor.y_hex(hex: lightColor)
            }
        }
    }

    /// 16进制转UIColor
    /// - Parameters:
    ///   - hex: hex
    ///   - alpha: alpha
    static func y_hex(hex: Int, alpha: CGFloat = 1.0) -> UIColor {
        return self.init(red:CGFloat(((hex & 0xff0000) >> 16)) / 255.0,
                         green: CGFloat(((hex & 0xFF00) >> 8)) / 255.0,
                         blue: CGFloat((hex & 0xFF)) / 255.0,
                         alpha: alpha)

    }
}
```
