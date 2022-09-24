# OC 与 Swift 的区别

## 枚举：

```objectivec
typedef NS_ENUM(NSInteger, PlayerState) {
    PlayerStateNone = 0,
    PlayerStatePlaying,
    PlayerStatePause,
    PlayerStateBuffer,
    PlayerStateFailed,
};
typedef NS_OPTIONS(NSUInteger, XXViewAnimationOptions) {
    XXViewAnimationOptionNone            = 1 <<  0,
    XXViewAnimationOptionSelcted1        = 1 <<  1,
    XXViewAnimationOptionSelcted2        = 1 <<  2,
}
```

```swift
enum PlayerState: Int {
    case none = 0
    case playing
    case pause
    case buffer
    case failed
}
struct ViewAnimationOptions: OptionSet {
    let rawValue: UInt
    static let None = ViewAnimationOptions(rawValue: 1<<0)
    static let Selected1 = ViewAnimationOptions(rawValue: 1<<0)
    static let Selected2 = ViewAnimationOptions(rawValue: 1 << 2)
    //...
}
```



## 懒加载

```objectivec
- (Object *)object {
    if (!_object) {
        _object = [Object new];
    }
    return _object;
}
```

```swift
lazy var object: Object = {
    let object = Object()
    return imagobjecteView
}()
```



## 闭包

```objectivec
typedef void (^DownloadStateBlock)(BOOL isComplete);
```

```swift
typealias DownloadStateBlock = ((_ isComplete: Bool) -> Void)
```



## 单例

```objectivec
+ (XXManager *)sharedInstance {
		static XXManager *_instance = nil;
		static dispatch_once_t onceToken;
		dispatch_once(&onceToken, ^{
				_instance = [[self alloc] init];
		});
		return _instance;
}
```

Swift 方式一：

```swift
let shared = XXManager()// 声明在全局命名区（global namespace）
Class XXManager { 
}
```

可能会疑惑，为何没有**`dispatch_once`**，如何保证多线程下建立的惟一性？实际上是这样的，Swift中全局变量是懒加载，在AppDelegate中被初始化，以后全部的调用都会使用该实例。并且全局变量的初始化是默认使用**`dispatch_once`**的，这保证了全局变量的构造器（initializer）只会被调用一次，保证了**`shard`** 的原子性。

Swift 方式二：

```swift
Class XXManager {
    static let shared = XXManager()
    private override init() {
        // do something 
    }
}
```

Swift 2 开始增长了**`static`** 关键字，用于限定变量的做用域。若是不使用**`static`**，那么每个**`shared`** 都会对应一个实例。而使用 **`static`** 以后，**`shared`** 成为全局变量，就成了跟上面第一种方式原理一致。能够注意到，因为构造器使用了 **`private`** 关键字，因此也保证了单例的原子性。



## 初始化方法和析构函数

对于初始化方法OC先调用父类的初始化方法，而后初始本身的成员变量。Swift先初始化本身的成员变量，而后在调用父类的初始化方法。

```objectivec
// 初始化方法
@interface MainView : UIView
@property (nonatomic, copy) NSString *title;
- (instancetype)initWithFrame:(CGRect)frame title:(NSString *)title NS_DESIGNATED_INITIALIZER;
@end

@implementation MainView
- (instancetype)initWithFrame:(CGRect)frame title:(NSString *)title {
    if (self = [super initWithFrame:frame]) {
        self.title = title;
    }
    return self;
}
@end
// 析构函数
- (void)dealloc {
    // dealloc
}
```

```swift
class MainView: UIView {
    let title: String
    init(frame: CGRect, title: String) {
        self.title = title
        super.init(frame: frame)
    }
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    deinit {
      // deinit
    }
}
```



## 函数调用

```objectivec
// 实例函数（共有方法）
- (void)configModelWith:(XXModel *)model {}
// 实例函数（私有方法）
- (void)calculateProgress {}
// 类函数
+ (void)configModelWith:(XXModel *)model {}
```

```swift
// 实例函数（共有方法）
func configModel(with model: XXModel) {}
// 实例函数（私有方法）
private func calculateProgress() {}
// 类函数（不能够被子类重写）
static func configModel(with model: XXModel) {}
// 类函数（能够被子类重写）
class func configModel(with model: XXModel) {}
// 类函数（不能够被子类重写）
class final func configModel(with model: XXModel) {}
```



## NSNotification

```objc
// add observer
[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(method) name:@"NotificationName" object:nil];
// post
[NSNotificationCenter.defaultCenter postNotificationName:@"NotificationName" object:nil];
```

```swift
// add observer
NotificationCenter.default.addObserver(self, selector: #selector(method), name: NSNotification.Name(rawValue: "NotificationName"), object: nil)
// post
NotificationCenter.default.post(name: NSNotification.Name(rawValue: "NotificationName"), object: self)
```

上面的 swift 代码能够改成：

```swift
extension NSNotification.Name {
    static let NotificationName = NSNotification.Name("NotificationName")
}
// add observer
NotificationCenter.default.addObserver(self, selector: #selector(method), name: .NotificationName, object: nil)
// post
NotificationCenter.default.post(name: .NotificationName, object: self)
```



## protocol (协议/代理)

```objc
@protocol XXManagerDelegate <NSObject>
- (void)downloadFileFailed:(NSError *)error;
@optional
- (void)downloadFileComplete;
@end

@interface XXManager: NSObject
@property (nonatomic, weak) id<XXManagerDelegate> delegate;  
@end
```

Swift中对`protocol`的使用拓宽了许多，不光是`class`对象，`struct`和`enum`也均可以实现协议。须要注意的是`struct`和`enum`为指引用类型，不能使用`weak`修饰。只有指定当前代理只支持类对象，才能使用`weak`。

```swift
@objc protocol XXManagerDelegate {
    func downloadFailFailed(error: Error)
    @objc optional func downloadFileComplete() // 可选协议的实现
}
class XXManager: NSObject {
    weak var delegate: XXManagerDelegate?  
}
```

`@objc`是代表当前代码是针对`NSObject`对象，也就是`class`对象，就能够正常使用weak了。

若是不是针对NSObject对象的delegate，仅仅是普通的class对象能够这样设置代理：

```swift
protocol XXManagerDelegate: class {
    func downloadFailFailed(error: Error)
}
class XXManager {
    weak var delegate: XXManagerDelegate?
}
```

值得注意的是，仅`@objc`标记的`protocol`可使用`@optional`。



# Swift 和 OC 混编注意事项

## 函数名的变化

若是你在一个Swift类里定义了一个delegate方法：

```swift
@objc protocol MarkButtonDelegate {
    func clickBtn(title: String)
}
```

若是你要在OC中实现这个协议，这时候方法名就变成了：

```objc
- (void)clickBtnWithTitle:(NSString *)title {
    // code
}
```



## 在 OC 的头文件里调用 Swift 类

若是要在OC的头文件里引用Swift类，由于Swift没有头文件，而为了让在头文件可以识别该Swift类，须要经过`@class`的方法引入。

```swift
@class SwiftClass;

@interface XXOCClass: NSObject
@property (nonatomic, strong) SwiftClass *object;
@end
```



## 对 OC 类在 Swift 调用下重命名

由于Swift对不一样的module都有命名空间，因此Swift类都不须要添加前缀。若是有一个带前缀的OC公共组件，在Swift环境下调用时不得不指定前缀是一件很不优雅的事情，因此苹果添加了一个宏命令`NS_SWIFT_NAME`，容许在OC类在Swift环境下的重命名：

```objc
NS_SWIFT_NAME(LoginManager)
@interface XXLoginManager: NSObject
@end
```

这样就将`XXLoginManager`在Swift环境下的类名改成了`LoginManager`。



## 引用类型和值类型

- `struct` 和 `enum` 是值类型，类 `class` 是引用类型。
- `String`，`Array`和 `Dictionary`都是结构体，所以赋值直接是拷贝，而`NSString`, `NSArray`和`NSDictionary`则是类，因此是使用引用的方式。
- `struct` 比 `class` 更“轻量级”，`struct` 分配在栈中，`class` 分配在堆中。



## id 类型和 AnyObject

OC 中 `id` 类型被 Swift 调用时会自动转成 `AnyObject`，他们很类似，但却其实概念并不一致。Swift中还有一个概念是`Any`，他们三者的区别是：

- `id` 是一种通用的对象类型，它能够指向属于任何类的对象，在OC中便是能够表明全部继承于`NSObject`的对象。
- `AnyObject`能够表明任何`class`类型的实例。
- `Any`能够表明任何类型，甚至包括`func`类型。

从范围大小比较就是：`id < AnyObject < Any`。



## 其余语法区别及注意事项

1、Swift 语句中不需要加分号 `;`。

2、关于 Bool 类型更加严格，Swift 不再是 OC 中的非 0 就是真，真假只对应 `true` 和 `false`。

3、Swift 类内一般不需要写 `self`，但是闭包内是需要写的。

4、Swift 是强类型语言，必须要指定明确的类型。在 Swift 中 `Int` 和 `Float` 是不能直接做运算的，必须要将他们转成同一类型才可以运算。

5、Swift 抛弃了传统的 `++`，`--` 运算，抛弃了传统的 C 语言式的 `for` 循环写法，而改为 `for-in`。

6、Swift 的 `switch` 操作，不需要在每个 case 语句结束的时候都添加 `break`。

7、Swift 对 `enum` 的使用做了很大的扩展，可以支持任意类型，而 OC 枚举仅支持 `Int` 类型，如果要写兼容代码，要选择 Int 型枚举。

8、Swift 代码要想被 OC 调用，需要在属性和方法名前面加上 `@objc`。

9、Swift 独有的特性，如泛型，`struct`，非 Int 型的 `enum` 等被包含才函数参数中，即使添加 `@objc` 也不会被编译器通过。

10、Swift 支持重载，OC 不支持。

11、带默认值的 Swift 函数再被 OC 调用时会自动展开。



## 语法检查

对于 OC 转 Swift 以后的语法变化还有不少细节值得注意，特别是对于初次使用 Swift 这门语言，很容易遗漏或者待着 OC 的思想去写代码。这里推荐一个语法检查的框架 [SwiftLint](http://www.javashuo.com/link?url=https://github.com/realm/SwiftLint)，能够自动化的检查代码是否符合Swift规范。能够经过`cocoapods`进行引入，配置好以后，每次`Build`的过程，Lint脚本都会执行一遍 Swift 代码的语法检查操做，Lint 还会将代码规范进行分级，严重的代码错误会直接报错，致使程序没法启动，不太严重的会显示代码警告（⚠️）。

若是你感受 SwiftLint 有点过于严格了，还能够经过修改 `.swiftlint.yml`文件，自定义属于本身的语法规范。









