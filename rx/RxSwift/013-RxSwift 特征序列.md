# RxSwift - 特征序列：Single、Completable、Maybe、Driver、ControlProperty、 ControlEvent

特征序列（`Traits`）：`Single`、`Completable`、`Maybe`、`Driver`、`ControlEvent`。

可以将这些 `Traits` 看作是 `Observable` 的另外一个版本。它们之间的区别是：

- `Observable` 是能够用于任何上下文环境的通用序列。
- 而 `Traits` 可以帮助我们更准确的描述序列。同时它们还为我们提供上下文含义、语法糖，让我们能够用更加优雅的方式书写代码。



## Single

`Single` 是 `Observable` 的另外一个版本。但它不像 `Observable` 可以发出多个元素，它要么只能发出一个元素，要么产生一个 `error` 事件。

- 发出一个元素，或一个 `error` 事件
- 不会共享状态变化

#### 应用场景

`Single` 比较常见的例子就是执行 `HTTP` 请求，然后返回一个应答或错误。不过我们也可以用 `Single` 来描述任何只有一个元素的序列。

#### SingleEvent

为方便使用，`RxSwift` 还为 `Single` 订阅提供了一个枚举（`SingleEvent`）：

- `.success`：里面包含该`Single`的一个元素值
- `.error`：用于包含错误

```swift
public enum SingleEvent<Element> {
    case success(Element)
    case error(Swift.Error)
}
```

#### 使用样例

创建 `Single` 和创建 `Observable` 非常相似。下面定义一个用于生成网络请求 `Single` 的函数：

```swift
// 获取某频道下的歌曲信息
func getPlaylist(_ channel: String) -> Single<[String: Any]> {
    return Single<[String: Any]>.create { single in
        let url = "https://douban.fm/j/mine/playlist?"
            + "type=n&channel=\(channel)&from=mainsite"
        let task = URLSession.shared.dataTask(with: URL(string: url)!) { data, _, error in
            if let error = error {
                single(.error(error))
                return
            }
             
            guard let data = data,
                let json = try? JSONSerialization.jsonObject(with: data,
                                                             options: .mutableLeaves),
                let result = json as? [String: Any] else {
                    single(.error(DataError.cantParseJSON))
                    return
            }
             
            single(.success(result))
        }
         
        task.resume()
         
        return Disposables.create { task.cancel() }
    }
}
 
// 与数据相关的错误类型
enum DataError: Error {
    case cantParseJSON
}
```

接着就可以使用如下方式使用这个 `Single`：

```swift
import UIKit
import RxSwift
import RxCocoa
 
class ViewController: UIViewController {
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
        // 获取第0个频道的歌曲信息
        getPlaylist("0")
            .subscribe { event in
                switch event {
                case .success(let json):
                    print("JSON结果: ", json)
                case .error(let error):
                    print("发生错误: ", error)
                }
            }
            .disposed(by: disposeBag)
    }
}
```

也可以使用 `subscribe(onSuccess:onError:)`这种方式：

```swift
import UIKit
import RxSwift
import RxCocoa
 
class ViewController: UIViewController {
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
        // 获取第0个频道的歌曲信息
        getPlaylist("0")
            .subscribe(onSuccess: { json in
                print("JSON结果: ", json)
            }, onError: { error in
                print("发生错误: ", error)
            })
            .disposed(by: disposeBag)
    }
}
```

#### asSingle()

可以通过调用 `Observable` 序列的 `.asSingle()` 方法，将它转换为 `Single`。

```swift
let disposeBag = DisposeBag()
 
Observable.of("1")
    .asSingle()
    .subscribe({ print($0) })
    .disposed(by: disposeBag)
```



## Completable

`Completable` 是 `Observable` 的另外一个版本。不像 `Observable` 可以发出多个元素，它要么只能产生一个 `completed` 事件，要么产生一个 `error` 事件。

- 不会发出任何元素
- 只会发出一个 `completed` 事件或者一个 `error` 事件
- 不会共享状态变化

#### 应用场景

`Completable` 和 `Observable<Void>` 有点类似。适用于那些只关心任务是否完成，而不需要在意任务返回值的情况。比如：在程序退出时将一些数据缓存到本地文件，供下次启动时加载。像这种情况我们只关心缓存是否成功。

#### CompletableEvent

为方便使用，`RxSwift` 为 `Completable` 订阅提供了一个枚举（`CompletableEvent`）：

- `.completed`：用于产生完成事件
- `.error`：用于产生一个错误

```swift
public enum CompletableEvent {
    case error(Swift.Error)
    case completed
}
```

#### 使用样例

创建 `Completable` 和创建 `Observable` 非常相似。下面代码我们使用 `Completable` 来模拟一个数据缓存本地的操作：

```swift
// 将数据缓存到本地
func cacheLocally() -> Completable {
    return Completable.create { completable in
        // 将数据缓存到本地（这里掠过具体的业务代码，随机成功或失败）
        let success = (arc4random() % 2 == 0)
         
        guard success else {
            completable(.error(CacheError.failedCaching))
            return Disposables.create {}
        }
         
        completable(.completed)
        return Disposables.create {}
    }
}
 
// 与缓存相关的错误类型
enum CacheError: Error {
    case failedCaching
}
```

接着可以使用如下方式使用这个 `Completable`：

```swift
cacheLocally()
    .subscribe { completable in
        switch completable {
        case .completed:
            print("保存成功!")
        case .error(let error):
            print("保存失败: \(error.localizedDescription)")
        }
    }
    .disposed(by: disposeBag)
```

也可以使用 `subscribe(onCompleted:onError:)` 这种方式：

```swift
cacheLocally()
    .subscribe(onCompleted: {
         print("保存成功!")
    }, onError: { error in
        print("保存失败: \(error.localizedDescription)")
    })
    .disposed(by: disposeBag)
```



## Maybe

`Maybe` 同样是 `Observable` 的另外一个版本。它介于 `Single` 和 `Completable` 之间，它要么只能发出一个元素，要么产生一个 `completed` 事件，要么产生一个 `error` 事件。

- 发出一个元素、或者一个 `completed` 事件、或者一个 `error` 事件
- 不会共享状态变化

#### 应用场景

`Maybe` 适合那种可能需要发出一个元素，又可能不需要发出的情况。

#### MaybeEvent

为方便使用，`RxSwift` 为 `Maybe` 订阅提供了一个枚举（`MaybeEvent`）：

- `.success`：里包含该 `Maybe` 的一个元素值
- `.completed`：用于产生完成事件
- `.error`：用于产生一个错误

```swift
public enum MaybeEvent<Element> {
    case success(Element)
    case error(Swift.Error)
    case completed
}
```

#### 使用样例

创建 `Maybe` 和创建 `Observable` 同样非常相似：

```swift
func generateString() -> Maybe<String> {
    return Maybe<String>.create { maybe in
         
        // 成功并发出一个元素
        maybe(.success("hangge.com"))
         
        // 成功但不发出任何元素
        maybe(.completed)
         
        // 失败
        // maybe(.error(StringError.failedGenerate))
         
        return Disposables.create {}
    }
}
 
// 与缓存相关的错误类型
enum StringError: Error {
    case failedGenerate
}
```

接着可以使用如下方式使用这个 `Maybe`：

```swift
generateString()
    .subscribe { maybe in
        switch maybe {
        case .success(let element):
            print("执行完毕，并获得元素：\(element)")
        case .completed:
            print("执行完毕，且没有任何元素。")
        case .error(let error):
            print("执行失败: \(error.localizedDescription)")
   
        }
    }
    .disposed(by: disposeBag)
```

也可以使用 `subscribe(onSuccess:onCompleted:onError:)` 这种方式：

```swift
generateString()
    .subscribe(onSuccess: { element in
        print("执行完毕，并获得元素：\(element)")
    },
               onError: { error in
                print("执行失败: \(error.localizedDescription)")
    },
               onCompleted: {
                print("执行完毕，且没有任何元素。")
    })
    .disposed(by: disposeBag)
```

#### asMaybe()

可以通过调用 `Observable` 序列的 `.asMaybe()`方法，将它转换为 `Maybe`。

```swift
let disposeBag = DisposeBag()
 
Observable.of("1")
    .asMaybe()
    .subscribe({ print($0) })
    .disposed(by: disposeBag)
```



## Driver

（1）`Driver` 可以说是最复杂的 `trait`，它的目标是提供一种简便的方式在 `UI` 层编写响应式代码。

（2）如果我们的序列满足如下特征，就可以使用它：

- 不会产生 `error` 事件
- 一定在主线程监听（`MainScheduler`）
- 共享状态变化（`shareReplayLatestWhileConnected`）

#### 为什么要使用 Driver?

（1）`Driver` 最常使用的场景应该就是需要用序列来驱动应用程序的情况了，比如：

- 通过 `CoreData` 模型驱动 `UI`
- 使用一个 `UI` 元素值（绑定）来驱动另一个 `UI` 元素值

（2）与普通的操作系统驱动程序一样，如果出现序列错误，应用程序将停止响应用户输入。

（3）在主线程上观察到这些元素也是极其重要的，因为 `UI` 元素和应用程序逻辑通常不是线程安全的。

（4）此外，使用构建 `Driver` 的可观察的序列，它是共享状态变化。

#### 使用样例

 这个是官方提供的样例，大致的意思是根据一个输入框的关键字，来请求数据，然后将获取到的结果绑定到另一个 `Label` 和 `TableView` 中。

（1）初学者使用 `Observable` 序列加 `bindTo` 绑定来实现这个功能的话可能会这么写：

```swift
let results = query.rx.text
    .throttle(0.3, scheduler: MainScheduler.instance) // 在主线程中操作，0.3秒内值若多次改变，取最后一次
    .flatMapLatest { query in // 筛选出空值, 拍平序列
        fetchAutoCompleteItems(query) // 向服务器请求一组结果
}
 
// 将返回的结果绑定到用于显示结果数量的label上
results
    .map { "\($0.count)" }
    .bind(to: resultCount.rx.text)
    .disposed(by: disposeBag)
 
// 将返回的结果绑定到tableView上
results
    .bind(to: resultsTableView.rx.items(cellIdentifier: "Cell")) { (_, result, cell) in
        cell.textLabel?.text = "\(result)"
    }
    .disposed(by: disposeBag)
```

但这个代码存在如下 3 个问题：

- 如果 `fetchAutoCompleteItems` 的序列产生了一个错误（网络请求失败），这个错误将取消所有绑定。此后用户再输入一个新的关键字时，是无法发起新的网络请求。
- 如果 `fetchAutoCompleteItems` 在后台返回序列，那么刷新页面也会在后台进行，这样就会出现异常崩溃。
- 返回的结果被绑定到两个 `UI` 元素上。那就意味着，每次用户输入一个新的关键字时，就会分别为两个 `UI`元素发起 `HTTP`请求，这并不是我们想要的结果。

把上面几个问题修改后的代码是这样的：

```swift
let results = query.rx.text
    .throttle(0.3, scheduler: MainScheduler.instance) // 在主线程中操作，0.3秒内值若多次改变，取最后一次
    .flatMapLatest { query in // 筛选出空值, 拍平序列
        fetchAutoCompleteItems(query)   // 向服务器请求一组结果
            .observeOn(MainScheduler.instance)  // 将返回结果切换到到主线程上
            .catchErrorJustReturn([])       // 错误被处理了，这样至少不会终止整个序列
    }
    .shareReplay(1)                // HTTP 请求是被共享的
 
// 将返回的结果绑定到显示结果数量的label上
results
    .map { "\($0.count)" }
    .bind(to: resultCount.rx.text)
    .disposed(by: disposeBag)
 
// 将返回的结果绑定到tableView上
results
    .bind(to: resultsTableView.rx.items(cellIdentifier: "Cell")) { (_, result, cell) in
        cell.textLabel?.text = "\(result)"
    }
    .disposed(by: disposeBag)
```

虽然我们通过增加一些额外的处理，让程序可以正确运行。到对于一个大型的项目来说，如果都这么干也太麻烦了，而且容易遗漏出错。

#### 使用 `Driver` 来实现

而如果使用 `Driver` 来实现的话就简单了，代码如下：

```swift
代码讲解：
（1）首先我们使用 asDriver 方法将 ControlProperty 转换为 Driver。
（2）接着我们可以用 .asDriver(onErrorJustReturn: []) 方法将任何 Observable 序列都转成 Driver，因为我们知道序列转换为 Driver 要他满足 3 个条件：

*   不会产生 error 事件
*   一定在主线程监听（MainScheduler）
*   共享状态变化（shareReplayLatestWhileConnected）

而 asDriver(onErrorJustReturn: []) 相当于以下代码：
      let safeSequence = xs
         .observeOn(MainScheduler.instance) // 主线程监听
         .catchErrorJustReturn(onErrorJustReturn) // 无法产生错误
         .share(replay: 1, scope: .whileConnected)// 共享状态变化
         return Driver(raw: safeSequence) // 封装
（3）同时在 Driver 中，框架已经默认帮我们加上了 shareReplayLatestWhileConnected，所以我们也没必要再加上"replay"相关的语句了。
（4）最后记得使用 drive 而不是 bindTo
```



```swift
let results = query.rx.text.asDriver()        // 将普通序列转换为 Driver
    .throttle(0.3, scheduler: MainScheduler.instance)
    .flatMapLatest { query in
        fetchAutoCompleteItems(query)
            .asDriver(onErrorJustReturn: [])  // 仅仅提供发生错误时的备选返回值
    }
 
// 将返回的结果绑定到显示结果数量的label上
results
    .map { "\($0.count)" }
    .drive(resultCount.rx.text) // 这里使用 drive 而不是 bindTo
    .disposed(by: disposeBag)
 
// 将返回的结果绑定到tableView上
results
    .drive(resultsTableView.rx.items(cellIdentifier: "Cell")) { // 同样使用 drive 而不是 bindTo
        (_, result, cell) in
        cell.textLabel?.text = "\(result)"
    }
    .disposed(by: disposeBag)
```

由于 `drive` 方法只能被 `Driver` 调用。这意味着，如果代码存在 `drive`，那么这个序列不会产生错误事件并且一定在主线程监听。这样我们就可以安全的绑定 `UI`元素。



## ControlProperty

（1）`ControlProperty` 是专门用来描述 `UI` 控件属性，拥有该类型的属性都是被观察者（`Observable`）。

（2）`ControlProperty` 具有以下特征：

- 不会产生 `error` 事件
- 一定在 `MainScheduler` 订阅（主线程订阅）
- 一定在 `MainScheduler` 监听（主线程监听）
- 共享状态变化

#### 使用样例

（1）其实在 `RxCocoa` 下许多 `UI` 控件属性都是被观察者（可观察序列）。比如我们查看源码（`UITextField+Rx.swift`），可以发现 `UITextField` 的 `rx.text` 属性类型便是 `ControlProperty<String?>`：

```swift
import RxSwift
import UIKit
 
extension Reactive where Base: UITextField {
 
    public var text: ControlProperty<String?> {
        return value
    }
 
    public var value: ControlProperty<String?> {
        return base.rx.controlPropertyWithDefaultEvents(
            getter: { textField in
                textField.text
        },
            setter: { textField, value in
                if textField.text != value {
                    textField.text = value
                }
        }
        )
    }
     
    //......
}
```

那么我们如果想让一个 `textField` 里输入内容实时地显示在另一个 `label` 上，即前者作为被观察者，后者作为观察者。可以这么写：

```swift
import UIKit
import RxSwift
import RxCocoa
 
class ViewController: UIViewController {
     
    @IBOutlet weak var textField: UITextField!
     
    @IBOutlet weak var label: UILabel!
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
         
        // 将textField输入的文字绑定到label上
        textField.rx.text
            .bind(to: label.rx.text)
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



## ControlEvent

（1）`ControlEvent` 是专门用于描述 `UI` 所产生的事件，拥有该类型的属性都是被观察者（`Observable`）。

（2）`ControlEvent` 和 `ControlProperty` 一样，都具有以下特征：

- 不会产生 `error` 事件
- 一定在 `MainScheduler` 订阅（主线程订阅）
- 一定在 `MainScheduler` 监听（主线程监听）
- 共享状态变化

### 使用样例

（1）同样地，在 `RxCocoa` 下许多 `UI` 控件的事件方法都是被观察者（可观察序列）。比如我们查看源码（`UIButton+Rx.swift`），可以发现 `UIButton` 的 `rx.tap` 方法类型便是 `ControlEvent<Void>`：

```swift
import RxSwift
import UIKit
 
extension Reactive where Base: UIButton {
    public var tap: ControlEvent<Void> {
        return controlEvent(.touchUpInside)
    }
}
```

（2）那么我们如果想实现当一个 `button` 被点击时，在控制台输出一段文字。即前者作为被观察者，后者作为观察者。可以这么写：

```swift
import UIKit
import RxSwift
import RxCocoa
 
class ViewController: UIViewController {
     
    let disposeBag = DisposeBag()
     
    @IBOutlet weak var button: UIButton!
     
    override func viewDidLoad() {
         
        // 订阅按钮点击事件
        button.rx.tap
            .subscribe(onNext: {
                print("欢迎访问hangge.com")
            }).disposed(by: disposeBag)
    }
}
```

