# RxSwift - [unowned self] & [weak self]）



```swift
import UIKit
 
class DetailViewController: UIViewController {
 
    @IBOutlet weak var textField: UITextField!
    @IBOutlet weak var label: UILabel!
     
    override func viewDidLoad() {
        super.viewDidLoad()
    }
 
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
    }
     
    deinit {
        print(#file, #function)
    }
}
```



## 内存泄漏的样例

```swift
import UIKit
import RxSwift
import RxCocoa
 
class DetailViewController: UIViewController {
     
    @IBOutlet weak var textField: UITextField!
     
    @IBOutlet weak var label: UILabel!
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
        super.viewDidLoad()
         
        textField.rx.text.orEmpty.asDriver().drive(onNext: {
            text in
            DispatchQueue.main.asyncAfter(deadline: .now() + 4) {
                print("当前输入内容：\(String(describing: text))")
                self.label.text = text
            }
        }).disposed(by: disposeBag)
    }
     
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
    }
     
    deinit {
        print(#file, #function)
    }
}
```



## 内存泄漏的解决

#### [weak self] 与 [unowned self] 介绍

​    我们只需将闭包捕获列表定义为弱引用（`weak`）、或者无主引用（`unowned`）即可解决问题，这二者的使用场景分别如下：

- 如果捕获（比如 `self`）可以被设置为 `nil`，也就是说它可能在闭包前被销毁，那么就要将捕获定义为 `weak`。
- 如果它们一直是相互引用，即同时销毁的，那么就可以将捕获定义为 `unowned`。

#### [weak self] 样例

（1）这里我对上面的样例代码稍作修改，增加个 `[weak self]`：

```swift
import UIKit
import RxSwift
import RxCocoa
 
class DetailViewController: UIViewController {
     
    @IBOutlet weak var textField: UITextField!
     
    @IBOutlet weak var label: UILabel!
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
        super.viewDidLoad()
         
        textField.rx.text.orEmpty.asDriver().drive(onNext: {
            [weak self] text in
            DispatchQueue.main.asyncAfter(deadline: .now() + 4) {
                print("当前输入内容：\(String(describing: text))")
                self?.label.text = text
            }
             
        }).disposed(by: disposeBag)
    }
     
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
    }
     
    deinit {
        print(#file, #function)
    }
}
```

（2）仍然按上面的操作步骤测试一下，看到 `deinit`方法成功被调用，说明页面被释放。

#### [unowned self] 样例

（1）如果我们不用 `[weak self]` 而改用 `[unowned self]`，返回主页面　**4**　秒钟后由于详情页早已被销毁，这时访问 `label` 将会导致异常抛出。

```swift
import UIKit
import RxSwift
import RxCocoa
 
class DetailViewController: UIViewController {
     
    @IBOutlet weak var textField: UITextField!
     
    @IBOutlet weak var label: UILabel!
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
        super.viewDidLoad()
         
        textField.rx.text.orEmpty.asDriver().drive(onNext: {
            [unowned self] text in
            DispatchQueue.main.asyncAfter(deadline: .now() + 4) {
                print("当前输入内容：\(String(describing: text))")
                self.label.text = text
            }
             
        }).disposed(by: disposeBag)
    }
     
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
    }
     
    deinit {
        print(#file, #function)
    }
}
```

（2）当然如果我们把延时去掉的话，使用 `[unowned self]` 是完全没有问题的。

```swift
import UIKit
import RxSwift
import RxCocoa
 
class DetailViewController: UIViewController {
     
    @IBOutlet weak var textField: UITextField!
     
    @IBOutlet weak var label: UILabel!
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
        super.viewDidLoad()
         
        textField.rx.text.orEmpty.asDriver().drive(onNext: {
            [unowned self] text in
            print("当前输入内容：\(String(describing: text))")
            self.label.text = text
        }).disposed(by: disposeBag)
    }
     
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
    }
     
    deinit {
        print(#file, #function)
    }
}
```