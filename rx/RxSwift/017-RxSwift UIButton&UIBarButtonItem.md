# RxSwift - UIButton、UIBarButtonItem

#### 按钮点击响应

```swift
import UIKit
import RxSwift
import RxCocoa
 
class ViewController: UIViewController {
     
    let disposeBag = DisposeBag()
     
    @IBOutlet weak var button: UIButton!
     
    override func viewDidLoad() {
        // 按钮点击响应
        button.rx.tap
            .subscribe(onNext: { [weak self] in
                self?.showMessage("按钮被点击")
            })
            .disposed(by: disposeBag)
    }
     
    // 显示消息提示框
    func showMessage(_ text: String) {
        let alertController = UIAlertController(title: text, message: nil, preferredStyle: .alert)
        let cancelAction = UIAlertAction(title: "确定", style: .cancel, handler: nil)
        alertController.addAction(cancelAction)
        self.present(alertController, animated: true, completion: nil)
    }
}
```



#### 按钮标题（title）的绑定

```swift
// 创建一个计时器（每1秒发送一个索引数）
let timer = Observable<Int>.interval(RxTimeInterval.seconds(1), scheduler: MainScheduler.instance)
 
// 根据索引数拼接最新的标题，并绑定到button上
timer.map{"计数\($0)"}
    .bind(to: button.rx.title(for: .normal))
    .disposed(by: disposeBag)
```



#### 按钮富文本标题（attributedTitle）的绑定

```swift
import UIKit
import RxSwift
import RxCocoa
 
class ViewController: UIViewController {
     
    let disposeBag = DisposeBag()
     
    @IBOutlet weak var button: UIButton!
     
    override func viewDidLoad() {
        // 创建一个计时器（每1秒发送一个索引数）
        let timer = Observable<Int>.interval(1, scheduler: MainScheduler.instance)
         
        // 将已过去的时间格式化成想要的字符串，并绑定到button上
        timer.map(formatTimeInterval)
            .bind(to: button.rx.attributedTitle())
            .disposed(by: disposeBag)
    }
     
    //将数字转成对应的富文本
    func formatTimeInterval(ms: NSInteger) -> NSMutableAttributedString {
        let string = String(format: "%0.2d:%0.2d.%0.1d",
                            arguments: [(ms / 600) % 600, (ms % 600 ) / 10, ms % 10])
        // 富文本设置
        let attributeString = NSMutableAttributedString(string: string)
        // 从文本0开始6个字符字体HelveticaNeue-Bold,16号
        attributeString.addAttribute(NSAttributedStringKey.font,
                                     value: UIFont(name: "HelveticaNeue-Bold", size: 16)!,
                                     range: NSMakeRange(0, 5))
        // 设置字体颜色
        attributeString.addAttribute(NSAttributedStringKey.foregroundColor,
                                     value: UIColor.white, range: NSMakeRange(0, 5))
        // 设置文字背景颜色
        attributeString.addAttribute(NSAttributedStringKey.backgroundColor,
                                     value: UIColor.orange, range: NSMakeRange(0, 5))
        return attributeString
    }
}
```



#### 按钮图标（image）的绑定

```swift
// 创建一个计时器（每1秒发送一个索引数）
let timer = Observable<Int>.interval(RxTimeInterval.seconds(1), scheduler: MainScheduler.instance)
 
// 根据索引数选择对应的按钮图标，并绑定到button上
timer.map({
    let name = $0%2 == 0 ? "back" : "forward"
    return UIImage(named: name)!
})
.bind(to: button.rx.image())
.disposed(by: disposeBag)
```



#### 按钮背景图片（backgroundImage）的绑定

```swift
// 创建一个计时器（每1秒发送一个索引数）
let timer = Observable<Int>.interval(RxTimeInterval.seconds(1), scheduler: MainScheduler.instance)
 
// 根据索引数选择对应的按钮背景图，并绑定到button上
timer.map{ UIImage(named: "\($0%2)")! }
    .bind(to: button.rx.backgroundImage())
    .disposed(by: disposeBag)
```



#### 按钮是否可用（isEnabled）的绑定

```swift
switchView.rx.isOn
    .bind(to: button.rx.isEnabled)
    .disposed(by: disposeBag)
```



#### 按钮是否选中（isSelected）的绑定

实现三个按钮，三选一的效果。

```swift
import UIKit
import RxSwift
import RxCocoa
 
class ViewController: UIViewController {
     
    let disposeBag = DisposeBag()
     
    @IBOutlet weak var button1: UIButton!
    @IBOutlet weak var button2: UIButton!
    @IBOutlet weak var button3: UIButton!
     
    override func viewDidLoad() {
        // 默认选中第一个按钮
        button1.isSelected = true
         
        // 强制解包，避免后面还需要处理可选类型
        let buttons = [button1, button2, button3].map { $0! }
         
        // 创建一个可观察序列，它可以发送最后一次点击的按钮（也就是我们需要选中的按钮）
        let selectedButton = Observable.from(
            buttons.map { button in button.rx.tap.map { button } }
            ).merge()
         
        // 对于每一个按钮都对selectedButton进行订阅，根据它是否是当前选中的按钮绑定isSelected属性
        for button in buttons {
            selectedButton.map { $0 == button }
                .bind(to: button.rx.isSelected)
                .disposed(by: disposeBag)
        }
    }
}
```