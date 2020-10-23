# RxSwift - 键值观察KVO

- `KVO`（键值观察）是一种 `Objective-C` 的回调机制，全称为：`key-value-observing`。
- 该机制简单来说就是在某个对象注册监听者后，当被监听的对象发生改变时，对象会发送一个通知给监听者，以便监听者执行回调操作。



## RxSwift 中的 KVO

`RxCocoa` 提供了 **2** 个可观察序列 `rx.observe` 和 `rx.observeWeakly`，它们都是对 `KVO` 机制的封装，二者的区别如下。

（1）性能比较

- `rx.observe` 更加高效，因为它是一个 `KVO` 机制的简单封装。
- `rx.observeWeakly` 执行效率要低一些，因为它要处理对象的释放防止弱引用（对象的 `dealloc` 关系）。

（2）使用场景比较

- 在可以使用 `rx.observe` 的地方都可以使用 `rx.observeWeakly`。
- 使用 `rx.observe` 时路径只能包括 `strong` 属性，否则就会有系统崩溃的风险。而 `rx.observeWeakly` 可以用在 `weak` 属性上。



## 使用样例

#### 监听基本类型的属性

（1）我们创建一个定时器，每隔 **1** 秒钟给变量 `message` 尾部添加一个感叹号（!）。同时对这个属性进行监听，当值改变时将最新值输出到控制台中。

注意：

- 监听的属性需要有 `dynamic` 修饰符。
- 本样例需要使用 `rx.observeWeakly`，不能用 `rx.observe`，否则会造成循环引用，引起内存泄露。

```swift
import UIKit
import RxSwift
import RxCocoa
 
class ViewController: UIViewController {
     
    let disposeBag = DisposeBag()
     
    @objc dynamic var message = "hangge.com"
     
    override func viewDidLoad() {
        super.viewDidLoad()
       
        // 定时器（1秒执行一次）
        Observable<Int>.interval(1, scheduler: MainScheduler.instance)
            .subscribe(onNext: { [unowned self] _ in
                // 每次给字符串尾部添加一个感叹号
                self.message.append("!")
            }).disposed(by: disposeBag)
         
        // 监听message变量的变化
        _ = self.rx.observeWeakly(String.self, "message")
            .subscribe(onNext: { (value) in
            print(value ?? "")
        })
    }
}
```

#### 监听视图尺寸变化

（1）我们对 `view.frame` 进行监听，当其改变时将最新值输出到控制台中。

注意：这里必须使用 `rx.observe`，如果使用 `rx.observeWeakly` 则监听不到。

```swift
import UIKit
import RxSwift
import RxCocoa
 
class ViewController: UIViewController {
     
    override func viewDidLoad() {
        super.viewDidLoad()
         
        // 监听视图frame的变化
        _ = self.rx.observe(CGRect.self, "view.frame")
            .subscribe(onNext: { frame in
                print("--- 视图尺寸发生变化 ---")
                print(frame!)
                print("\n")
            })
    }
}
```

（2）程序启动后默认是竖屏状态，接着我们将其变成横屏显示。

#### 渐变导航栏效果

（1）导航栏会随着 `tableView` 的滑动而发生不同的变化：

- 默认情况下，导航栏背景是完全透明的。
- 当 `tableView` 向上滑动时，导航栏背景逐渐显示出来。
- 当 `tableView` 下载滑动时，导航栏背景又逐渐消失。

（2）我们可以通过`KVO` 监听偏移量的变化来动态改变导航栏的背景透明度，这个我在之前的文章中也介绍过（[点击查看](http://www.hangge.com/blog/cache/detail_2068.html)）。如果在 `RxSwift` 项目中的话，`KVO` 使用起来会简单许多。

```swift
import UIKit
import RxSwift
import RxCocoa
 
class ViewController: UIViewController {
     
    var tableView:UITableView!
     
    // 导航栏背景视图
    var barImageView:UIView?
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
        super.viewDidLoad()
         
        // 导航栏背景色为橙色
        self.navigationController?.navigationBar.barTintColor = .orange
         
        // 获取导航栏背景视图
        self.barImageView = self.navigationController?.navigationBar.subviews.first
         
        // 创建表格视图
        self.tableView = UITableView(frame: self.view.frame, style:.plain)
        // 创建一个重用的单元格
        self.tableView!.register(UITableViewCell.self, forCellReuseIdentifier: "Cell")
        self.view.addSubview(self.tableView!)
         
        // 初始化数据
        let items = Observable.just(Array(0...100).map{ "这个是条目\($0)"})
         
        // 设置单元格数据（其实就是对 cellForRowAt 的封装）
        items.bind(to: tableView.rx.items) { (tableView, row, element) in
            let cell = tableView.dequeueReusableCell(withIdentifier: "Cell")!
            cell.textLabel?.text = "\(element)"
            return cell
        }
        .disposed(by: disposeBag)
         
        // 使用kvo来监听视图偏移量变化
        _ = self.tableView.rx.observe(CGPoint.self, "contentOffset")
            .subscribe(onNext: {[weak self] offset in
                var delta = offset!.y / CGFloat(64) + 1
                delta = CGFloat.maximum(delta, 0)
                self?.barImageView?.alpha = CGFloat.minimum(delta, 1)
            })
    }
}
```