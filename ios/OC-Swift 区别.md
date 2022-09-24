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

```objectivec
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





