# RxSwift - Observer观察者



## 直接在 subscribe、bind 方法中创建观察者

#### 在 subscribe 方法中创建

```swift
let observable = Observable.of("A", "B", "C")
          
observable.subscribe(onNext: { element in
    print(element)
}, onError: { error in
    print(error)
}, onCompleted: {
    print("completed")
})
```

#### 在 bind 方法中创建

```swift
import UIKit
import RxSwift
import RxCocoa
 
class ViewController: UIViewController {
     
    @IBOutlet weak var label: UILabel!
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
         
        // Observable序列（每隔1秒钟发出一个索引数）
        let observable = Observable<Int>.interval(1, scheduler: MainScheduler.instance)
 
        observable
            .map { "当前索引数：\($0 )"}
            .bind { [weak self](text) in
                //收到发出的索引数后显示到label上
                self?.label.text = text
            }
            .disposed(by: disposeBag)
    }
}
```



## 使用 AnyObserver 创建观察者

#### 配合 subscribe 方法使用

```swift
// 观察者
let observer: AnyObserver<String> = AnyObserver { (event) in
    switch event {
    case .next(let data):
        print(data)
    case .error(let error):
        print(error)
    case .completed:
        print("completed")
    }
}
 
let observable = Observable.of("A", "B", "C")
observable.subscribe(observer)
```

#### 配合 bindTo 方法使用

```swift
import UIKit
import RxSwift
import RxCocoa
 
class ViewController: UIViewController {
     
    @IBOutlet weak var label: UILabel!
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
         
        // 观察者
        let observer: AnyObserver<String> = AnyObserver { [weak self] (event) in
            switch event {
            case .next(let text):
                // 收到发出的索引数后显示到label上
                self?.label.text = text
            default:
                break
            }
        }
         
        // Observable序列（每隔1秒钟发出一个索引数）
        let observable = Observable<Int>.interval(1, scheduler: MainScheduler.instance)
        observable
            .map { "当前索引数：\($0 )"}
            .bind(to: observer)
            .disposed(by: disposeBag)
    }
}
```



## 使用 Binder 创建观察者

（1）相较于 `AnyObserver` 的大而全，`Binder` 更专注于特定的场景。`Binder` 主要有以下两个特征：

- 不会处理错误事件
- 确保绑定都是在给定 `Scheduler` 上执行（默认 `MainScheduler`）

（2）一旦产生错误事件，在调试环境下将执行 `fatalError`，在发布环境下将打印错误信息。

```swift
import UIKit
import RxSwift
import RxCocoa
 
class ViewController: UIViewController {
     
    @IBOutlet weak var label: UILabel!
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
                 
        // 观察者
        let observer: Binder<String> = Binder(label) { (view, text) in
            //收到发出的索引数后显示到label上
            view.text = text
        }
         
        // Observable序列（每隔1秒钟发出一个索引数）
        let observable = Observable<Int>.interval(1, scheduler: MainScheduler.instance)
        observable
            .map { "当前索引数：\($0 )"}
            .bind(to: observer)
            .disposed(by: disposeBag)
    }
}
```



## 自定义可绑定属性

#### 方式一：通过对 UI 类进行扩展

这里通过对 `UILabel` 进行扩展，增加了一个 `fontSize` 可绑定属性。

```swift
import UIKit
import RxSwift
import RxCocoa
 
class ViewController: UIViewController {
     
    @IBOutlet weak var label: UILabel!
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
         
        // Observable序列（每隔0.5秒钟发出一个索引数）
        let observable = Observable<Int>.interval(0.5, scheduler: MainScheduler.instance)
        observable
            .map { CGFloat($0) }
            .bind(to: label.fontSize) // 根据索引数不断变放大字体
            .disposed(by: disposeBag)
    }
}
 
extension UILabel {
    public var fontSize: Binder<CGFloat> {
        return Binder(self) { label, fontSize in
            label.font = UIFont.systemFont(ofSize: fontSize)
        }
    }
}
```

#### 方式二：通过对 Reactive 类进行扩展（推荐使用，更规范）

```swift
import UIKit
import RxSwift
import RxCocoa
 
class ViewController: UIViewController {
     
    @IBOutlet weak var label: UILabel!
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
         
        // Observable序列（每隔0.5秒钟发出一个索引数）
        let observable = Observable<Int>.interval(0.5, scheduler: MainScheduler.instance)
        observable
            .map { CGFloat($0) }
            .bind(to: label.rx.fontSize) // 根据索引数不断变放大字体
            .disposed(by: disposeBag)
    }
}
 
extension Reactive where Base: UILabel {
    public var fontSize: Binder<CGFloat> {
        return Binder(self.base) { label, fontSize in
            label.font = UIFont.systemFont(ofSize: fontSize)
        }
    }
}
```



## RxSwift 自带的可绑定属性（UI 观察者）

（1） `RxSwift` 已经为我们提供许多常用的可绑定属性。比如 `UILabel` 就有 `text` 和 `attributedText` 这两个可绑定属性。

```swift
import RxSwift
import UIKit
 
extension Reactive where Base: UILabel {
     
    /// Bindable sink for `text` property.
    public var text: Binder<String?> {
        return Binder(self.base) { label, text in
            label.text = text
        }
    }
 
    /// Bindable sink for `attributedText` property.
    public var attributedText: Binder<NSAttributedString?> {
        return Binder(self.base) { label, text in
            label.attributedText = text
        }
    }
     
}
```

（2）那么上文那个定时显示索引数的样例，其实不需要自定义 `UI` 观察者，直接使用 `RxSwift` 提供的绑定属性即可。

```swift
import UIKit
import RxSwift
import RxCocoa
 
class ViewController: UIViewController {
     
    @IBOutlet weak var label: UILabel!
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
         
        // Observable序列（每隔1秒钟发出一个索引数）
        let observable = Observable<Int>.interval(1, scheduler: MainScheduler.instance)
        observable
            .map { "当前索引数：\($0 )"}
            .bind(to: label.rx.text) // 收到发出的索引数后显示到label上
            .disposed(by: disposeBag)
    }
}
```

