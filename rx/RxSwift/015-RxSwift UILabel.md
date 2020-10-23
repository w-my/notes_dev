# RxSwift - UILabel



#### 将数据绑定到 text 属性上

```swift
import UIKit
import RxSwift
import RxCocoa
 
class ViewController: UIViewController {
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
         
        // 创建文本标签
        let label = UILabel(frame:CGRect(x:20, y:40, width:300, height:100))
        self.view.addSubview(label)
         
        // 创建一个计时器（每0.1秒发送一个索引数）
        let timer = Observable<Int>.interval(RxTimeInterval.milliseconds(100), scheduler: MainScheduler.instance)
         
        // 将已过去的时间格式化成想要的字符串，并绑定到label上
        timer.map{ String(format: "%0.2d:%0.2d.%0.1d", [($0 / 600) % 600, ($0 % 600 ) / 10, $0 % 10]) }
        .bind(to: label.rx.text)
        .disposed(by: disposeBag)
    }
}
```



#### 将数据绑定到 attributedText 属性上（富文本）

这个样例功能和前面样例是一样的，不过我们修改了分和秒这部分的文字样式，以及背景色。

```swift
import UIKit
import RxSwift
import RxCocoa
 
class ViewController: UIViewController {
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
         
        // 创建文本标签
        let label = UILabel(frame:CGRect(x:20, y:40, width:300, height:100))
        self.view.addSubview(label)
         
        // 创建一个计时器（每0.1秒发送一个索引数）
        let timer = Observable<Int>.interval(RxTimeInterval.milliseconds(100), scheduler: MainScheduler.instance)
         
        // 将已过去的时间格式化成想要的字符串，并绑定到label上
        timer.map(formatTimeInterval)
        .bind(to: label.rx.attributedText)
        .disposed(by: disposeBag)
    }
     
    // 将数字转成对应的富文本
    func formatTimeInterval(ms: NSInteger) -> NSMutableAttributedString {
        let string = String(format: "%0.2d:%0.2d.%0.1d", [(ms / 600) % 600, (ms % 600 ) / 10, ms % 10])
        // 富文本设置
        let attributeString = NSMutableAttributedString(string: string)
        // 从文本0开始6个字符字体HelveticaNeue-Bold,16号
        attributeString.addAttribute(NSAttributedString.Key.font,
                                     value: UIFont(name: "HelveticaNeue-Bold", size: 16)!,
                                     range: NSMakeRange(0, 5))
        // 设置字体颜色
        attributeString.addAttribute(NSAttributedString.Key.foregroundColor,
                                     value: UIColor.white, range: NSMakeRange(0, 5))
        // 设置文字背景颜色
        attributeString.addAttribute(NSAttributedString.Key.backgroundColor,
                                     value: UIColor.orange, range: NSMakeRange(0, 5))
        return attributeString
    }
}
```