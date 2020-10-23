# RxSwift - UIGestureRecognizer



#### 滑动手势为例

（1）第一种响应回调的写法

```swift
import UIKit
import RxSwift
import RxCocoa
 
class ViewController: UIViewController {
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
        super.viewDidLoad()
 
        // 添加一个上滑手势
        let swipe = UISwipeGestureRecognizer()
        swipe.direction = .up
        self.view.addGestureRecognizer(swipe)
         
        // 手势响应
        swipe.rx.event
            .subscribe(onNext: { [weak self] recognizer in
                // 这个点是滑动的起点
                let point = recognizer.location(in: recognizer.view)
                self?.showAlert(title: "向上划动", message: "\(point.x) \(point.y)")
            })
            .disposed(by: disposeBag)
    }
     
    // 显示消息提示框
    func showAlert(title: String, message: String) {
        let alert = UIAlertController(title: title, message: message,
                                      preferredStyle: .alert)
        alert.addAction(UIAlertAction(title: "确定", style: .cancel))
        self.present(alert, animated: true)
    }
}
```

（2）第二种响应回调的写法

```swift
import UIKit
import RxSwift
import RxCocoa
 
class ViewController: UIViewController {
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
        super.viewDidLoad()
 
        // 添加一个上滑手势
        let swipe = UISwipeGestureRecognizer()
        swipe.direction = .up
        self.view.addGestureRecognizer(swipe)
         
        // 手势响应
        swipe.rx.event
            .bind { [weak self] recognizer in
                // 这个点是滑动的起点
                let point = recognizer.location(in: recognizer.view)
                self?.showAlert(title: "向上划动", message: "\(point.x) \(point.y)")
            }
            .disposed(by: disposeBag)
    }
     
    // 显示消息提示框
    func showAlert(title: String, message: String) {
        let alert = UIAlertController(title: title, message: message,
                                      preferredStyle: .alert)
        alert.addAction(UIAlertAction(title: "确定", style: .cancel))
        self.present(alert, animated: true)
    }
}
```