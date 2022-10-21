# RxSwift - UISlider、UIStepper



## UISlider

```swift
import UIKit
import RxSwift
import RxCocoa
 
class ViewController: UIViewController {
     
    @IBOutlet weak var slider: UISlider!
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
        slider.rx.value.asObservable()
            .subscribe(onNext: {
                print("当前值为：\($0)")
            })
            .disposed(by: disposeBag)
    }
}
```



## UIStepper

```csharp
slider.rx.value
    .map{ Double($0) }  // 由于slider值为Float类型，而stepper的stepValue为Double类型，因此需要转换
    .bind(to: stepper.rx.stepValue)
    .disposed(by: disposeBag)
```

