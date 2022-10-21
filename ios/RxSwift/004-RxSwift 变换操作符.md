# RxSwift - 变换操作符：buffer、map、flatMap（已废弃->改用compactMap）、scan等



## buffer

- `buffer` 方法作用是缓冲组合，第一个参数是缓冲时间，第二个参数是缓冲个数，第三个参数是线程。
- 该方法简单来说就是缓存 `Observable` 中发出的新元素，当元素达到某个数量，或者经过了特定的时间，它就会将这个元素集合发送出来。

```swift
import UIKit
import RxSwift
import RxCocoa
 
class ViewController: UIViewController {
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
 
        let subject = PublishSubject<String>()
 
        // 每缓存3个元素则组合起来一起发出。
        // 如果1秒钟内不够3个也会发出（有几个发几个，一个都没有发空数组 []）
        subject
            .buffer(timeSpan: 1, count: 3, scheduler: MainScheduler.instance)
            .subscribe(onNext: { print($0) })
            .disposed(by: disposeBag)
 
        subject.onNext("a")
        subject.onNext("b")
        subject.onNext("c")
         
        subject.onNext("1")
        subject.onNext("2")
        subject.onNext("3")
    }
}

# 输出以下内容
["a", "b", "c"]
["1", "2", "3"]
[]
[]
[]
...
```



## window

- `window` 操作符和 `buffer` 十分相似。不过 `buffer` 是周期性的将缓存的元素集合发送出来，而 `window` 周期性的将元素集合以 `Observable` 的形态发送出来。
- 同时 `buffer`要等到元素搜集完毕后，才会发出元素序列。而 `window` 可以实时发出元素序列。

```swift
import UIKit
import RxSwift
import RxCocoa
 
class ViewController: UIViewController {
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
         
        let subject = PublishSubject<String>()
         
        // 每3个元素作为一个子Observable发出。
        subject
            .window(timeSpan: 1, count: 3, scheduler: MainScheduler.instance)
            .subscribe(onNext: { [weak self]  in
                print("subscribe: \($0)")
                $0.asObservable()
                    .subscribe(onNext: { print($0) })
                    .disposed(by: self!.disposeBag)
            })
            .disposed(by: disposeBag)
         
        subject.onNext("a")
        subject.onNext("b")
        subject.onNext("c")
         
        subject.onNext("1")
        subject.onNext("2")
        subject.onNext("3")
    }
}

# 输出以下内容
subscribe: RxSwift.AddARef<Swift.String>
a
b
c
subscribe: RxSwift.AddARef<Swift.String>
1
2
3
subscribe: RxSwift.AddARef<Swift.String>
subscribe: RxSwift.AddARef<Swift.String>
subscribe: RxSwift.AddARef<Swift.String>
...
```



## map

- 该操作符通过传入一个函数闭包把原来的 `Observable` 序列转变为一个新的 `Observable` 序列。

```swift
let disposeBag = DisposeBag()
 
Observable.of(1, 2, 3)
    .map { $0 * 10}
    .subscribe(onNext: { print($0) })
    .disposed(by: disposeBag)

# 输出以下内容
10
20
30
```



## flatMap

- `map` 在做转换的时候容易出现“升维”的情况。即转变之后，从一个序列变成了一个序列的序列。
- 而 `flatMap` 操作符会对源 `Observable` 的每一个元素应用一个转换方法，将他们转换成 `Observables`。 然后将这些 `Observables` 的元素合并之后再发送出来。即又将其 "拍扁"（降维）成一个 `Observable` 序列。
- 这个操作符是非常有用的。比如当 `Observable` 的元素本生拥有其他的 `Observable` 时，我们可以将所有子 `Observables` 的元素发送出来。

```swift
let disposeBag = DisposeBag()
 
let subject1 = BehaviorSubject(value: "A")
let subject2 = BehaviorSubject(value: "1")
 
let variable = Variable(subject1)
 
variable.asObservable()
    .flatMap { $0 }
    .subscribe(onNext: { print($0) })
    .disposed(by: disposeBag)
 
subject1.onNext("B")
variable.value = subject2
subject2.onNext("2")
subject1.onNext("C")

# 输出以下内容
A
B
1
2
C
```



## flatMapLatest

- `flatMapLatest` 与 `flatMap` 的唯一区别是：`flatMapLatest` 只会接收最新的 `value` 事件。

```swift
let disposeBag = DisposeBag()
 
let subject1 = BehaviorSubject(value: "A")
let subject2 = BehaviorSubject(value: "1")
 
let variable = Variable(subject1)
 
variable.asObservable()
    .flatMapLatest { $0 }
    .subscribe(onNext: { print($0) })
    .disposed(by: disposeBag)
 
subject1.onNext("B")
variable.value = subject2
subject2.onNext("2")
subject1.onNext("C")
      
# 输出以下内容
A
B
1
2
```



## concatMap

- `concatMap` 与 `flatMap` 的唯一区别是：当前一个 `Observable` 元素发送完毕后，后一个`Observable` 才可以开始发出元素。或者说等待前一个 `Observable` 产生完成事件后，才对后一个 `Observable` 进行订阅。

```swift
let disposeBag = DisposeBag()
 
let subject1 = BehaviorSubject(value: "A")
let subject2 = BehaviorSubject(value: "1")
 
let variable = Variable(subject1)
 
variable.asObservable()
    .concatMap { $0 }
    .subscribe(onNext: { print($0) })
    .disposed(by: disposeBag)
 
subject1.onNext("B")
variable.value = subject2
subject2.onNext("2")
subject1.onNext("C")
subject1.onCompleted() // 只有前一个序列结束后，才能接收下一个序列

# 输出以下内容
A
B
C
2
```



## scan

- `scan` 就是先给一个初始化的数，然后不断的拿前一个结果和最新的值进行处理操作。

```swift
let disposeBag = DisposeBag()
 
Observable.of(1, 2, 3, 4, 5)
    .scan(0) { acum, elem in
        acum + elem
    }
    .subscribe(onNext: { print($0) })
    .disposed(by: disposeBag)

# 输出以下内容
1
3
6
10
15
```



## groupBy

- `groupBy` 操作符将源 `Observable` 分解为多个子 `Observable`，然后将这些子 `Observable` 发送出来。
- 也就是说该操作符会将元素通过某个键进行分组，然后将分组后的元素序列以 `Observable` 的形态发送出来。

```swift
let disposeBag = DisposeBag()
 
// 将奇数偶数分成两组
Observable<Int>.of(0, 1, 2, 3, 4, 5)
    .groupBy(keySelector: { (element) -> String in
        return element % 2 == 0 ? "偶数" : "奇数"
    })
    .subscribe { (event) in
        switch event {
        case .next(let group):
            group.asObservable().subscribe({ (event) in
                print("key：\(group.key)    event：\(event)")
            })
            .disposed(by: disposeBag)
        default:
            print("")
        }
    }
.disposed(by: disposeBag)

# 输出以下内容
key：偶数   event：next(0)
key：奇数   event：next(1)
key：偶数   event：next(2)
key：奇数   event：next(3)
key：偶数   event：next(4)
key：奇数   event：next(5)
key：偶数   event：completed
key：奇数   event：completed
```





























