# RxSwift - Observable



## Observable

#### Observable<T>

`Observable<T>` 这个类就是`Rx` 框架的基础，可以称它为可观察序列。它可以异步地产生一系列的 `Event`，即一个 `Observable<T>` 对象会随着时间推移不定期地发出 `event(element : T)` 这样一个东西。

有了可观察序列，还需要有一个 `Observer`（订阅者）来订阅它，这样这个订阅者才能收到 `Observable<T>` 不时发出的 `Event`。

#### Event

```swift
public enum Event<Element> {
    /// Next element is produced.
    case next(Element)
    /// Sequence terminated with an error.
    case error(Swift.Error)
    /// Sequence completed successfully.
    case completed
}
```



## 创建 Observable 序列

#### just() 方法

```swift
let observable = Observable<Int>.just(5)
```

#### of() 方法

```swift
let observable = Observable.of("A", "B", "C")
```

#### from() 方法

```swift
let observable = Observable.from(["A", "B", "C"])
```

#### empty() 方法

创建一个空内容的 `Observable` 序列。

```swift
let observable = Observable<Int>.empty()
```

#### never() 方法

创建一个永远不会发出 `Event`（也不会终止）的 `Observable` 序列。

```swift
let observable = Observable<Int>.never()
```

#### error() 方法

创建一个不做任何操作，而是直接发送一个错误的 `Observable` 序列。

```swift
enum MyError: Error {
    case A
    case B
}  
let observable = Observable<Int>.error(MyError.A)
```

#### range() 方法

```swift
// 使用range()
let observable = Observable.range(start: 1, count: 5)
// 使用of()
let observable = Observable.of(1, 2, 3 ,4 ,5)
```

#### repeatElement() 方法

创建一个可以无限发出给定元素的 `Event`的 `Observable` 序列（永不终止）。

```swift
let observable = Observable.repeatElement(1)
```

#### generate() 方法

```swift
// 使用generate()方法
let observable = Observable.generate(
    initialState: 0,
    condition: { $0 <= 10 },
    iterate: { $0 + 2 }
)
 
// 使用of()方法
let observable = Observable.of(0 , 2 ,4 ,6 ,8 ,10)
```

#### create() 方法

```swift
// 这个block有一个回调参数observer就是订阅这个Observable对象的订阅者
// 当一个订阅者订阅这个Observable对象的时候，就会将订阅者作为参数传入这个block来执行一些内容
let observable = Observable<String>.create{observer in
    // 对订阅者发出了.next事件，且携带了一个数据"hangge.com"
    observer.onNext("hangge.com")
    // 对订阅者发出了.completed事件
    observer.onCompleted()
    // 因为一个订阅行为会有一个Disposable类型的返回值，所以在结尾一定要returen一个Disposable
    return Disposables.create()
}
 
// 订阅测试
observable.subscribe {
    print($0)
}

# 输出以下内容
next(hangge.com)
completed
```

#### deferred() 方法

```swift
// 用于标记是奇数、还是偶数
var isOdd = true
 
// 使用deferred()方法延迟Observable序列的初始化，通过传入的block来实现Observable序列的初始化并且返回。
let factory : Observable<Int> = Observable.deferred {
     
    // 让每次执行这个block时候都会让奇、偶数进行交替
    isOdd = !isOdd
     
    // 根据isOdd参数，决定创建并返回的是奇数Observable、还是偶数Observable
    if isOdd {
        return Observable.of(1, 3, 5 ,7)
    }else {
        return Observable.of(2, 4, 6, 8)
    }
}
 
// 第1次订阅测试
factory.subscribe { event in
    print("\(isOdd)", event)
}
 
// 第2次订阅测试
factory.subscribe { event in
    print("\(isOdd)", event)
}

# 输出以下内容
false next(2)
false next(4)
false next(6)
false next(8)
false completed
true next(1)
true next(3)
true next(5)
true next(7)
true completed
```

#### interval() 方法

创建的 `Observable` 序列每隔一段设定的时间，会发出一个索引数的元素。而且它会一直发送下去。

下面方法让其每 1 秒发送一次，并且是在主线程（`MainScheduler`）发送。

```swift
let observable = Observable<Int>.interval(1, scheduler: MainScheduler.instance)
observable.subscribe { event in
    print(event)
}

# 输出以下内容
next(0)
next(1)
next(2)
next(3)
...
```

#### timer() 方法

（1）这个方法有两种用法，一种是创建的 `Observable`序列在经过设定的一段时间后，产生唯一的一个元素。

```swift
// 5秒种后发出唯一的一个元素0
let observable = Observable<Int>.timer(5, scheduler: MainScheduler.instance)
observable.subscribe { event in
    print(event)
}

# 输出以下内容
next(0)
completed
```

（2）另一种是创建的 Observable 序列在经过设定的一段时间后，每隔一段时间产生一个元素。

```swift
// 延时5秒种后，每隔1秒钟发出一个元素
let observable = Observable<Int>.timer(5, period: 1, scheduler: MainScheduler.instance)
observable.subscribe { event in
    print(event)
}

# 5s后开始输出以下内容
next(0)
next(1)
next(2)
next(3)
...
```



## 订阅 Observable

有了 `Observable`，还要使用 `subscribe()` 方法来订阅它，接收它发出的 `Event`。

#### 用法一：

```swift
let observable = Observable.of("A", "B", "C")
         
observable.subscribe { event in
    print(event)
}

# 输出以下内容
next(A)
next(B)
next(C)
completed
```

```swift
let observable = Observable.of("A", "B", "C")
         
observable.subscribe { event in
		// 可以通过 event.element 获取到事件里的数据
    print(event.element)
}

# 输出以下内容
Optional("A")
Optional("B")
Optional("C"))
completed
```



#### 用法二：

使用 `subscribe` 方法对 `event` 方法分类

```swift
let observable = Observable.of("A", "B", "C")
         
observable.subscribe(onNext: { element in
    print(element)
}, onError: { error in
    print(error)
}, onCompleted: {
    print("completed")
}, onDisposed: {
    print("disposed")
})

# 输出以下内容
A
B
C
completed
disposed
```



## 监听事件的生命周期

#### doOn 介绍

可以使用 `doOn` 方法来监听事件的生命周期，它会在每一次事件发送前被调用。

```swift
let observable = Observable.of("A", "B", "C")
 
observable
    .do(onNext: { element in
        print("Intercepted Next：", element)
    }, onError: { error in
        print("Intercepted Error：", error)
    }, onCompleted: {
        print("Intercepted Completed")
    }, onDispose: {
        print("Intercepted Disposed")
    })
    .subscribe(onNext: { element in
        print(element)
    }, onError: { error in
        print(error)
    }, onCompleted: {
        print("completed")
    }, onDisposed: {
        print("disposed")
    })
```



## Observable 的销毁（Dispose）

#### Observable 从创建到终结流程

（1）一个 `Observable` 序列被创建出来后它不会马上就开始被激活从而发出 `Event`，而是要等到它被某个人订阅了才会激活它。

（2）而 `Observable` 序列激活之后要一直等到它发出了`.error` 或者 `.completed` 的 `event` 后，它才被终结。



#### dispose() 方法

（1）使用该方法可以手动取消一个订阅行为。

（2）如果我们觉得这个订阅结束了不再需要了，就可以调用 `dispose()` 方法把这个订阅给销毁掉，防止内存泄漏。

（3）当一个订阅行为被 `dispose` 了，那么之后 `observable` 如果再发出 `event`，这个已经 `dispose` 的订阅就收不到消息了。

```swift
let observable = Observable.of("A", "B", "C")
         
// 使用subscription常量存储这个订阅方法
let subscription = observable.subscribe { event in
    print(event)
}
         
// 调用这个订阅的dispose()方法
subscription.dispose()
```



#### DisposeBag

除了 `dispose()` 方法之外，我们更经常用到的是一个叫 `DisposeBag` 的对象来管理多个订阅行为的销毁：

- 我们可以把一个 `DisposeBag` 对象看成一个垃圾袋，把用过的订阅行为都放进去。
- 而这个 `DisposeBag` 就会在自己快要 `dealloc` 的时候，对它里面的所有订阅行为都调用 `dispose()` 方法。

