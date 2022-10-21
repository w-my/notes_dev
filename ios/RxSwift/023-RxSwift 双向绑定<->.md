# RxSwift - 双向绑定：<->



## RxSwift 自带的双向绑定操作符

（1）如果经常进行双向绑定的话，最好还是自定义一个 `operator` 方便使用。

（2）`RxSwift` 项目文件夹中已经有个现成的（`Operators.swift`），我们将它复制到我们项目中即可使用。



```swift
import RxSwift
 
struct UserViewModel {
  
    let username = Variable("guest")
     
    lazy var userinfo = {
        return self.username.asObservable()
            .map{ $0 == "hangge" ? "您是管理员" : "您是普通访客" }
            .share(replay: 1)
    }()
}
```



```swift
import UIKit
import RxSwift
import RxCocoa
 
class ViewController: UIViewController {
 
    @IBOutlet weak var textField: UITextField!
    @IBOutlet weak var label: UILabel!
     
    var userVM = UserViewModel()
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
        // 将用户名与textField做双向绑定
        _ =  self.textField.rx.textInput <->  self.userVM.username
 
        // 将用户信息绑定到label上
        userVM.userinfo.bind(to: label.rx.text).disposed(by: disposeBag)
    }
}
```