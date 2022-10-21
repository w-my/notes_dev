# RxSwift - 调试操作



## debug

- 我们可以将 `debug` 调试操作符添加到一个链式步骤当中，这样系统就能将所有的订阅者、事件、和处理等详细信息打印出来，方便我们开发调试。

```swift
let disposeBag = DisposeBag()
 
Observable.of("2", "3")
    .startWith("1")
    .debug()
    .subscribe(onNext: { print($0) })
    .disposed(by: disposeBag)
```

`debug()` 方法还可以传入标记参数，这样当项目中存在多个 `debug` 时可以很方便地区分出来。

```swift
let disposeBag = DisposeBag()
 
Observable.of("2", "3")
    .startWith("1")
    .debug("调试1")
    .subscribe(onNext: { print($0) })
    .disposed(by: disposeBag)
```



## RxSwift.Resources.total

- 通过将 `RxSwift.Resources.total` 打印出来，我们可以查看当前 `RxSwift` 申请的所有资源数量。这个在检查内存泄露的时候非常有用。

```swift
print(RxSwift.Resources.total)
         
let disposeBag = DisposeBag()
 
print(RxSwift.Resources.total)
         
Observable.of("BBB", "CCC")
    .startWith("AAA")
    .subscribe(onNext: { print($0) })
    .disposed(by: disposeBag)
         
print(RxSwift.Resources.total)

# 输出以下内容
0
2
AAA
BBB
3
```