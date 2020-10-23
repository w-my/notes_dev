# RxSwift - UIActivityIndicatorView、UIApplication



## UIActivityIndicatorView

```swift
mySwitch.rx.value
    .bind(to: activityIndicator.rx.isAnimating)
    .disposed(by: disposeBag)
```



## UIApplication

```swift
mySwitch.rx.value
    .bind(to: UIApplication.shared.rx.isNetworkActivityIndicatorVisible)
    .disposed(by: disposeBag)
```

