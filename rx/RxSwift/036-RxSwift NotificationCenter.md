# RxSwfit - NotificationCenter



## 系统通知的注册与响应

#### 监听应用进入后台的通知

程序进入后台时除了会执行 `AppDelegate.swift` 里的 `applicationDidEnterBackground` 方法外，还会发送 `UIApplicationDidEnterBackground` 通知，这里我们使用 `NotificationCenter` 的 `Rx` 扩展方法来监听这个通知。

关于 `.takeUntil(self.rx.deallocated)：`
它的作用是保证页面销毁的时候自动移除通知注册，避免内存浪费或奔溃。

```swift
import UIKit
import RxSwift
import RxCocoa
 
class ViewController: UIViewController {
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
        super.viewDidLoad()
         
        // 监听应用进入后台通知
        _ = NotificationCenter.default.rx
            .notification(NSNotification.Name.UIApplicationDidEnterBackground)
            .takeUntil(self.rx.deallocated) // 页面销毁自动移除通知监听
            .subscribe(onNext: { _ in
                print("程序进入到后台了")
            })
    }
}
```



#### 监听键盘的通知

```swift
import UIKit
import RxSwift
import RxCocoa
 
class ViewController: UIViewController {
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
        super.viewDidLoad()
         
        // 添加文本输入框
        let textField = UITextField(frame: CGRect(x:20, y:100, width:200, height:30))
        textField.borderStyle = UITextBorderStyle.roundedRect
        textField.returnKeyType = .done
        self.view.addSubview(textField)
         
        // 点击键盘上的完成按钮后，收起键盘
        textField.rx.controlEvent(.editingDidEndOnExit)
            .subscribe(onNext: {  _ in
                // 收起键盘
                textField.resignFirstResponder()
            })
            .disposed(by: disposeBag)
         
        // 监听键盘弹出通知
        _ = NotificationCenter.default.rx
            .notification(NSNotification.Name.UIKeyboardWillShow)
            .takeUntil(self.rx.deallocated) // 页面销毁自动移除通知监听
            .subscribe(onNext: { _ in
                print("键盘出现了")
            })
         
        // 监听键盘隐藏通知
        _ = NotificationCenter.default.rx
            .notification(NSNotification.Name.UIKeyboardWillHide)
            .takeUntil(self.rx.deallocated) // 页面销毁自动移除通知监听
            .subscribe(onNext: { _ in
                print("键盘消失了")
            })
    }
}
```



## 自定义通知的发送与接收

（1）`ViewController.swift`（我们发出一个携带有自定义数据的通知，同时创建两个观察者来接收这个通知。）

```swift
import UIKit
import RxSwift
import RxCocoa
 
class ViewController: UIViewController {
     
    let disposeBag = DisposeBag()
     
    let observers = [MyObserver(name: "观察器1"), MyObserver(name: "观察器2")]
     
    override func viewDidLoad() {
        super.viewDidLoad()
         
        print("发送通知")
        let notificationName = Notification.Name(rawValue: "DownloadImageNotification")
        NotificationCenter.default.post(name: notificationName, object: self,
                                        userInfo: ["value1":"hangge.com", "value2" : 12345])
        print("通知完毕")
    }
}
```

（2）`MyObserver.swift`（观察者在收到通知后的执行的处理函数中，添加了个 **3** 秒的等待。）

```swift
import UIKit
import RxSwift
import RxCocoa
 
class MyObserver: NSObject {
     
    var name:String = ""
     
    init(name:String){
        super.init()
         
        self.name = name
         
        // 接收通知：
        let notificationName = Notification.Name(rawValue: "DownloadImageNotification")
        _ = NotificationCenter.default.rx
            .notification(notificationName)
            .takeUntil(self.rx.deallocated) // 页面销毁自动移除通知监听
            .subscribe(onNext: { notification in
                // 获取通知数据
                let userInfo = notification.userInfo as! [String: AnyObject]
                let value1 = userInfo["value1"] as! String
                let value2 = userInfo["value2"] as! Int
                print("\(name) 获取到通知，用户数据是［\(value1),\(value2)］")
                // 等待3秒
                sleep(3)
                print("\(name) 执行完毕")
            })
    }
}
```





