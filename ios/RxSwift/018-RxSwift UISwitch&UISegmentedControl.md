# RxSwift - UISwitch、UISegmentedControl



## UISwitch

```swift
switch1.rx.isOn.asObservable()
    .subscribe(onNext: {
        print("当前开关状态：\($0)")
    })
    .disposed(by: disposeBag)
```



```swift
switch1.rx.isOn
    .bind(to: button1.rx.isEnabled)
    .disposed(by: disposeBag)
```



## UISegmentedControl

```swift
segmented.rx.selectedSegmentIndex.asObservable()
    .subscribe(onNext: {
        print("当前项：\($0)")
    })
    .disposed(by: disposeBag)
```

```swift
import UIKit
import RxSwift
import RxCocoa
 
class ViewController: UIViewController {
     
    @IBOutlet weak var segmented: UISegmentedControl!
    @IBOutlet weak var imageView: UIImageView!
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
        // 创建一个当前需要显示的图片的可观察序列
        let showImageObservable: Observable<UIImage> =
            segmented.rx.selectedSegmentIndex.asObservable().map {
                let images = ["js.png", "php.png", "react.png"]
                return UIImage(named: images[$0])!
        }
         
        // 把需要显示的图片绑定到 imageView 上
        showImageObservable.bind(to: imageView.rx.image)
            .disposed(by: disposeBag)
    }
}
```