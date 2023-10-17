//
//  ViewController.swift
//  RXSwift
//
//  Created by WTW on 2020/7/10.
//  Copyright © 2020 WTW. All rights reserved.
//

import UIKit
import RxSwift
import RxCocoa

/**
 * https://leomobiledeveloper.blog.csdn.net/article/details/51859330
 * https://beeth0ven.github.io/RxSwift-Chinese-Documentation/content/rxswift_core/observable/driver.html
 *
 * throttle 忽略上一个信号的一段时间的变化,也就是说一段时间没有新的信号输入，才会向下发送
 * distinctUntilChanged 直到信号改变了再发送
 * retry 如果失败，重新尝试的次数
 * flatMapLatest 仅仅执行最新的信号，当有新的信号来的时候，取消上一次未执行完的整个序列
 *
 */

class ViewController: UIViewController {
    
    let disposeBag = DisposeBag()
    
    fileprivate lazy var label: UILabel = {
       
        let label = UILabel()
        label.textColor = .red
        return label
        
    }()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.view.backgroundColor = .white
        
        label.frame = CGRect(x: 100, y: 100, width: 200, height: 100)
        self.view.addSubview(label)
                
        // MARK: - Observable 序列
        // 作用就是可以异步产生一系列的 Event(事件)，即一个 Observable<T>对象会随着时间推移不定期发出event(element: T) 这样的东西
        // 这些 Event 还携带数据，他的泛型<T> 就是用来指定这个 Event 携带的数据的类型的
        // 有了可观察序列，需要一个 Observer (订阅者) 来订阅它，这样订阅者才能收到 Observable<T>发出的Event
        
        /*
         public enum Event<Element> {
             /// Next element is produced.
             case next(Element)
          
             /// Sequence terminated with an error.
             case error(Swift.Error)
          
             /// Sequence completed successfully.
             case completed
         }
         */
        
        // 源码可以看出事件一共有三种：
        /*
         next 事件就是那个可以携带数据<T>的事件，可以说是一个”最正常“的事件
         error 标识一个错误，可以携带具体的错误内容，一旦 Observable 发出了 error event，则这个 Observable 就等于终止了，以后它再也不会发出 event 事件了
         completed 事件表示 Observable 发出的事件正常地结束了，跟 error 一样，一旦 Observable 发出了 completed event，则这个 Observable 就等于终止了，以后它再也不会发出 event 事件了
         */
        
        // Observable 和 Sequence 对比：
        /*
         为更好地理解，我们可以把每一个 Observable 的实例想象成于一个 Swift 中的 Sequence：
         即一个 Observable（ObservableType）相当于一个序列 Sequence（SequenceType）。
         ObservableType.subscribe(_:) 方法其实就相当于 SequenceType.generate()

         但它们之间还是有许多区别的：
         Swift 中的 SequenceType 是同步的循环，而 Observable 是异步的。
         Observable 对象会在有任何 Event 时候，自动将 Event 作为一个参数通过 ObservableType.subscribe(_:) 发出，并不需要使用 next 方法。
         */
        
        // MARK: Observable 序列的创建
        // MARK: just() 方法 - 通过传入一个默认值来初始化
        // Observable<Int> 说明携带的数据类型必须是Int类型
//         let observable = Observable<Int>.just(5)
        
        // MARK: of() 方法 - 该方法可以接受可变数量的参数(参数必须是同类型的),不显示声明类型，也会自动推断
        // let observabel = Observable.of("A","B","C")

        // MARK: from() 方法 - 该方法需要传入一个数组参数
        // let observable = Observable.from(["A","B","C"])
        
        // MARK: empty() 方法 - 该方法创建一个空内容的 Observable 序列
        // let observable = Observable<Int>.empty()
        
        // MARK: never() 方法 - 该方法创建一个永远不会发出 Event(也不会终止)的 Observable 序列
        // let observable = Observable<Int>.never()
        
        // MARK: error() 方法 - 该方法创建一个不做任何操作，而是直接发送一个错误的 Observable 序列
        /*
        enum MyError: Error {
            case A
            case B
        }
        let observable = Observable<Int>.error(MyError.A)
        */
        
        // MARK: range()方法 - 该方法通过指定起始和结束数值，创建一个以这个范围内所有值作为序列的 Observabel 序列
        // let observable = Observable.range(start:1, count:5)
        // 等同
        // let observable = Observable.of(1,2,3,4,5)
        
        // MARK: repeatElement() 方法 - 该方法创建一个无限发出给定元素的 Event 的 Observable 序列(永不终止)
        // let observable = Observable.repeatElement(1)
        
        
        // MARK: generate() 方法 - 创建一个只有当提供的判断条件都为 true 的时候，才会给出动作的 Observabel 序列
//        let observable = Observable.generate(
//            initialState: 0,
//            condition: { $0 <= 10 },
//            iterate: { $0 + 2}
//        )
        
        // 等同于
        // let observable = observable.of(0,2,4,6,8,10)
        
        
        // MARK: create() 方法 - 接受一个 block 形式的参数，任务是对每一个过来的订阅进行处理
        // 这个 block 有一个回调参数 observer 就是订阅这个 observable 对象的订阅者
        // 当一个订阅者订阅这个 Observable 对象的时候，就会将订阅者作为参数传入这个 block 来执行一些内容
        let observable = Observable<String>.create { observer in

            observer.onNext("A")
            
            observer.onCompleted()

            return Disposables.create()
        }

//        observable.subscribe(<#T##observer: ObserverType##ObserverType#>)
//        observable.subscribe { <#Event<String>#> in
//            <#code#>
//        }
//        observable.subscribe(onNext: <#T##((String) -> Void)?##((String) -> Void)?##(String) -> Void#>, onError: <#T##((Error) -> Void)?##((Error) -> Void)?##(Error) -> Void#>, onCompleted: <#T##(() -> Void)?##(() -> Void)?##() -> Void#>, onDisposed: <#T##(() -> Void)?##(() -> Void)?##() -> Void#>)
        observable.subscribe { (event) in
            print(event)
        }
        
        /*
         next(A)
         next(B)
         completed
         */
        
        // MARK: deferred() 方法  - 相当于是创建一个 Observable 工厂，通过传入一个 block 来执行延迟 Observable 序列创建的行为，而这个 block 里就是真正的实例化序列对象的地方
//        var isOdd = true
//
//        let factory : Observable<Int> = Observable.deferred {
//
//            // 让每次执行这个 block 时候都会让奇偶交替
//            isOdd = !isOdd
//
//            if isOdd {
//                return Observable.of(1,3,5,7)
//            }else {
//                return Observable.of(2,4,6,8)
//            }
//        }
//
//        // 第一次订阅测试
//        factory.subscribe { event in
//            print("\(isOdd)",event)
//        }
//
//        // 第二次订阅
//        factory.subscribe { event in
//            print("\(isOdd)",event)
//        }
        
        /*
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
         */
        
        //MARK: interval() 方法 - 创建的 Observable 序列每隔一段设定的时间，会发出一个索引数的元素。而且它会一直发送下去
//        let observable = Observable<Int>.interval(1, scheduler: MainScheduler.instance)
//        observable.subscribe { (event) in
//            print(event)
//        }
        
        /*
         next(0)
         next(1)
         next(2)
         next(3)
         next(4)
         next(5)
         next(6)
         next(7)
         next(8)
         */
        
        // MARK: timer() 方法 - 两种用法，一种是创建的 Observable 序列在经过设定的一段时间后，产生唯一的一个元素。
        // 另一种是创建的 Observable 序列在经过设定的一段时间后，每隔一段时间产生一个元素
        
        // 五秒后发出唯一的一个元素 0
//        let observable = Observable<Int>.timer(5, scheduler: MainScheduler.instance)
//        observable.subscribe { (event) in
//            print(event)
//        }
        
        /*
         next(0)
         completed
         */
        
        //延迟五秒，每隔1秒发出一个元素
//        let observable = Observable<Int>.timer(5, period: 1, scheduler: MainScheduler.instance)
//        observable.subscribe { (event) in
//            print(event)
//        }
        
        /*
         next(0)
         next(1)
         next(2)
         next(3)
         next(4)
         next(5)
         */
        
        // MARK: - 订阅 Observable
        // 有了 Observable，我们还要使用 subscribe() 方法来订阅它，接收它发出的 Event。
        
        //MARK: 第一种用法 subscribe()
        // 使用 subscribe() 订阅一个 Observable 对象，该方法的 block 回调参数就是被发出的 event 事件
//        let observable = Observable.of("A","B","C","D")
//        observable.subscribe { (event) in
//            print(event)
//        }
        
        // 初始化 Observable 序列时设置的默认值都是按照顺序通过.next 事件发送出来的
        // 当Observable 序列的初始化数据都发送完毕，还会自动发一个 .completed 事件出来
        
        /*
         next(A)
         next(B)
         next(C)
         next(D)
         completed
         */
        
        // 如果想要获取到这个事件里的数据，可以通过 event.element 得到
//        observable.subscribe { (event) in
//            print(event.element)
//        }
        
        /*
         Optional("A")
         Optional("B")
         Optional("C")
         Optional("D")
         nil
         */
        
        // MARK: 第二种用法   可以把 event 进行分类，通过不同的 block 回调处理不同类型的 event
        // onNext、onError、onCompleted 和 onDisposed 这四个回调 block 参数都是有默认值的，即它们都是可选的
        // 可以只处理 onNext 而不管其他的情况
//        let obsevable = Observable.of("A","B","C","D")
//        obsevable.subscribe(onNext: { (element) in
//            print(element)
//        }, onError: { (error) in
//            print(error)
//        }, onCompleted: {
//            print("completed")
//        }) {
//            print("disposed")
//        }
        
        /*
         A
         B
         C
         D
         completed
         disposed
         */
        
        //MARK:- 监听事件的生命周期
        // 使用 doOn 方法来监听事件的生命周期，它会在每一次事件发送前被调用
        // 同时它和 subscribe 一样，可以通过不同的 block 回调处理不同类型的 event。
        /*
         do(onNext:) 方法就是在 subscribe(onNext:) 前调用
         而 do(onCompleted:) 方法则会在 subscribe(onCompleted:) 前面调用
         */
//        let observable = Observable.of("A","B","C")
//        observable
//        .do(onNext: { element in
//            print("Intercepted Next：", element)
//        }, onError: { error in
//            print("Intercepted Error：", error)
//        }, onCompleted: {
//            print("Intercepted Completed")
//        }, onDispose: {
//            print("Intercepted Disposed")
//        })
//        .subscribe(onNext: { element in
//            print(element)
//        }, onError: { error in
//            print(error)
//        }, onCompleted: {
//            print("completed")
//        }, onDisposed: {
//            print("disposed")
//        })
        
        /*
         Intercepted Next： A
         A
         Intercepted Next： B
         B
         Intercepted Next： C
         C
         Intercepted Completed
         completed
         disposed
         Intercepted Disposed
         */
        
        
        // MARK:- Observable 的销毁 Dispose
        // 一个 Observable 序列被创建出来后不会立马被激活而发出 Event，而是等到它被某个订阅者订阅了才会被激活
        // 而 Observable 序列激活之后要一直等到它发出 .error 或者 .completed 的 event 后，它才被终结
        
        // MARK: dispose() 方法
        // 可以用于手动取消一个订阅行为，如果觉得这个订阅结束了不需要了，可以调用dispose() 方法把这个订阅给销毁掉，防止内存泄露
        // 一个订阅行为被 dispose() 了，那么之后 Observable 如果再发出 event ，这个 dispose 的订阅就收不到消息了
        
        // MARK: DisposeBag
        // 除了 dispose() 方法之外，经常用一个DisposeBag的对象来管理多个订阅行为的销毁
        // 可以把 DisposeBag 对象看做是一个垃圾袋，把用过的订阅行为都放进去
        // 而这个 DisposeBag 就会在自己将要 dealloc 的时候，对它里面的所有订阅行为都调用dispose() 方法
        
        
        // MARK: - 观察者 (Observer)
        // 监听事件，然后对这个事件做出响应，或者说任何响应事件的行为都是观察者
        // 当我们点击按钮，弹出一个提示框。那么这个“弹出一个提示框”就是观察者 Observer<Void>
        // 当我们请求一个远程的 json 数据后，将其打印出来。那么这个“打印 json 数据”就是观察者 Observer<JSON>

        // MARK: 直接在 subscribe、bind 方法中创建观察者
        // 1、在 subscribe 方法中创建
        // 创建观察者最直接的方法就是在 Observable 的 subscribe 方法后面描述当事件发生时，需要如何做出响应
        // 比如下面的样例，观察者就是由后面的 onNext，onError，onCompleted 这些闭包构建出来的。
//        let observable1 = Observable.of("A","B","C")
//        observable1.subscribe(onNext: { element in
//            print(element)
//        }, onError: { error in
//            print(error)
//        }, onCompleted: {
//            print("onCompleted")
//        })
        
        //2、 在 bind 方法中创建
//        let observable1 = Observable<Int>.interval(1, scheduler: MainScheduler.instance)
//
//        observable1
//            .map { "当前索引是 \($0)"}
//            .bind {[weak self] text in
//
//                self?.label.text = text
//        }
//        .disposed(by: disposeBag)
        
        // MARK: 使用 AnyObserver 用来描述任意一种观察者
        
        // 1、 配合 subscribe 方法使用
        
//        let observer: AnyObserver<String> = AnyObserver { (event) in
//            switch event {
//            case .next(let data):
//                print(data)
//            case .error(let error):
//                print(error)
//            case .completed:
//                print("completed")
//            }
//        }
//
//        let observable = Observable.of("A", "B", "C")
//        observable.subscribe(observer)
        
        // 2、配合 bindTo 方法使用
        
//        let observer: AnyObserver<String> = AnyObserver { [weak self] (event) in
//            switch event {
//            case .next(let text):
//                //收到发出的索引数后显示到label上
//                self?.label.text = text
//            default:
//                break
//            }
//        }
//
//        //Observable序列（每隔1秒钟发出一个索引数）
//        let observable = Observable<Int>.interval(1, scheduler: MainScheduler.instance)
//        observable
//            .map { "当前索引数：\($0 )"}
//            .bind(to: observer)
//            .disposed(by: disposeBag)
        

        // MARK: 使用 Binder 创建观察者
        // 相较于 AnyObserver 的大而全，Binder 更专注于特定的场景。Binder 主要有以下两个特征：
        //      不会处理错误事件
        //      确保绑定都是在给定 Scheduler 上执行（默认 MainScheduler）
        // 一旦产生错误事件，在调试环境下将执行 fatalError，在发布环境下将打印错误信息
        
        // MARK: 自定义可绑定属性
        // 有时我们想让 UI 控件创建出来后默认就有一些观察者，而不必每次都为它们单独去创建观察者。
        // 比如我们想要让所有的 UIlabel 都有个 fontSize 可绑定属性，它会根据事件值自动改变标签的字体大小
        
        // 方式一：通过对 UI 类进行扩展
        // Observable序列（每隔0.5秒钟发出一个索引数）
//        let observable = Observable<Int>.interval(0.5, scheduler: MainScheduler.instance)
//        observable
//            .map { CGFloat($0) }
//            .bind(to: label.fontSize) //根据索引数不断变放大字体
//            .disposed(by: disposeBag)
//
//        extension UILabel {
//            public var fontSize: Binder<CGFloat> {
//                return Binder(self) { label, fontSize in
//                    label.font = UIFont.systemFont(ofSize: fontSize)
//                }
//            }
//        }
        
        // 方式二： 通过对 Reactive 类进行扩展
        //Observable序列（每隔0.5秒钟发出一个索引数）
//            let observable = Observable<Int>.interval(0.5, scheduler: MainScheduler.instance)
//            observable
//                .map { CGFloat($0) }
//                .bind(to: label.rx.fontSize) //根据索引数不断变放大字体
//                .disposed(by: disposeBag)
//
//        extension Reactive where Base: UILabel {
//            public var fontSize: Binder<CGFloat> {
//                return Binder(self.base) { label, fontSize in
//                    label.font = UIFont.systemFont(ofSize: fontSize)
//                }
//            }
//        }
        
        // MARK: RxSwift 自带的可绑定属性（UI 观察者）
        
//        let observable1 = Observable<Int>.interval(1, scheduler: MainScheduler.instance)
//
//        observable1
//            .map { "当前索引为 \($0)"}
//            .bind(to: label.rx.text)
//            .disposed(by: disposeBag)
        
        
        //MARK: - 调试操作
        //MARK: debug
        
        Observable.of("B","C")
            .startWith("A")
            .debug()
            .subscribe(onNext: { print($0)})
            .disposed(by: disposeBag)
        
        /*
         2020-07-28 15:37:36.299: RxSwiftDemo1Controller.swift:23 (viewDidLoad()) -> subscribed
         2020-07-28 15:37:36.308: RxSwiftDemo1Controller.swift:23 (viewDidLoad()) -> Event next(A)
         A
         2020-07-28 15:37:36.311: RxSwiftDemo1Controller.swift:23 (viewDidLoad()) -> Event next(B)
         B
         2020-07-28 15:37:36.311: RxSwiftDemo1Controller.swift:23 (viewDidLoad()) -> Event next(C)
         C
         2020-07-28 15:37:36.311: RxSwiftDemo1Controller.swift:23 (viewDidLoad()) -> Event completed
         2020-07-28 15:37:36.311: RxSwiftDemo1Controller.swift:23 (viewDidLoad()) -> isDisposed
         */
        
        
        // 多个 deug 时方便区分，可以传入标记
        Observable.of("2","3")
            .startWith("1")
            .debug("debug标识1")
            .subscribe (onNext:{print($0)})
            .disposed(by: disposeBag)
        
        
        /*
         2020-07-28 15:41:22.126: debug标识1 -> subscribed
         2020-07-28 15:41:22.126: debug标识1 -> Event next(1)
         1
         2020-07-28 15:41:22.126: debug标识1 -> Event next(2)
         2
         2020-07-28 15:41:22.126: debug标识1 -> Event next(3)
         3
         2020-07-28 15:41:22.126: debug标识1 -> Event completed
         2020-07-28 15:41:22.126: debug标识1 -> isDisposed
         */
        
        //MARK: RxSwift.Resources.total
        // 查看 RxSwift 申请的所有资源数量，检查内存泄露的时候非常有用
        //
        
//        print(RxSwift.Resources.total)
        
        Observable.of("BBB", "CCC")
            .startWith("AAA")
            .subscribe(onNext: { print($0) })
            .disposed(by: disposeBag)
        
//        print(RxSwift.Resources.total)
        
        /*
         4
         AAA
         BBB
         CCC
         5
         */
        
        // 内存泄露问题 [unowned self]
        Observable<Any>.create ({ (observer) -> Disposable in
            observer.onNext("1")
            print(self)
            return Disposables.create()
        }).subscribe(onNext: { (val) in
            print("\(val)")
        }).disposed(by: disposeBag)
        
        Observable<Any>.create({(observer) -> Disposable in
            observer.onNext("1")
            print(self)
            return Disposables.create()
        }).subscribe(onNext: {[unowned self] (val) in
            print("\(val)")
            print(self)
        }).disposed(by: disposeBag)
        
        
        
        //MARK:- 过滤 Filtering Observables
        // 从源 Observer 中选择特定的数据发送
        
        //MARK:filter - 过滤不符合要求的事件
        Observable.of(2, 30, 22, 5, 60, 3, 40 ,9)
            .filter { $0 > 10
        }.subscribe(onNext: {
            print($0)
        }).disposed(by: disposeBag)
        
        /* 结果
         30
         22
         60
         40
         */
        
        //MARK:distinctUntilChanged - 过滤掉连续重复的事件
        Observable.of(1, 2, 3, 1, 1, 4)
            .distinctUntilChanged()
            .subscribe(onNext: { print($0) })
            .disposed(by: disposeBag)
        
        /* 结果
         1
         2
         3
         1
         4
         */
        
        //MARK: single - 限制只发送一次事件，或者满足条件的第一个事件
        // 如果存在多个事件或者没有事件都会发出一个 error 事件
        // 如果只有一个事件，则不会发出 error 事件
        Observable.of(1, 2, 3, 4)
            .single{ $0 == 2 }
            .subscribe(onNext: { print($0) })
            .disposed(by: disposeBag)
        
        Observable.of("A", "B", "C", "D")
            .single()
            .subscribe(onNext: { print($0) })
            .disposed(by: disposeBag)
        
        /* 结果
         2
         A
         Unhandled error happened: Sequence contains more than one element.
         */
        
        //MARK: elementAt -只处理在指定位置的事件
        Observable.of(1,2,3,4)
            .elementAt(2)
            .subscribe(onNext: {print($0)})
            .disposed(by: disposeBag)
        
        /* 结果
         3
         */
        
        // MARK:ignoreElements - 忽略掉所有元素，只发出 error 和 completed 事件
        // 如果我们并不关心 Observable 的任何元素，只想知道 Observable 在什么时候终止，那就可以使用 ignoreElements 操作符
        Observable.of(1, 2, 3, 4)
            .ignoreElements()
            .subscribe{
                print($0)
        }
        .disposed(by: disposeBag)
        
        /* 结果
         completed
         */
        
        // MARK: take - 仅发送 Observable 序列中的前 n 个事件，在满足数量之后会自动 .completed
        Observable.of(1, 2, 3, 4)
            .take(2)
            .subscribe(onNext: { print($0) })
            .disposed(by: disposeBag)
        
        /* 结果
         1
         2
         */
        
        // MARK: takeLast - 仅发送 Observable 序列中的后 n 个事件
        Observable.of(1, 2, 3, 4)
            .takeLast(1)
            .subscribe(onNext: { print($0) })
            .disposed(by: disposeBag)
        
        /* 结果
         4
         */
        
        //MARK: skip - 跳过源 Observable 序列发出的前 n 个事件
        Observable.of(1, 2, 3, 4)
            .skip(2)
            .subscribe(onNext: { print($0) })
            .disposed(by: disposeBag)
        
        /* 结果
         3
         4
         */
        
        // MARK: Sample - 除了订阅源 Observable 外，还可以监视另外一个 Observable， 即 notifier
        // 每当收到 notifier 事件，就会从源序列取一个最新的事件并发送。而如果两次 notifier 事件之间没有源序列的事件，则不发送值
        
        let source = PublishSubject<Int>()
        let notifier = PublishSubject<String>()
        
        source
            .sample(notifier)
            .subscribe(onNext: { print($0) })
            .disposed(by: disposeBag)
        
        source.onNext(1)
        
        //让源序列接收接收消息
        notifier.onNext("A")
        
        source.onNext(2)
        
        //让源序列接收接收消息
        notifier.onNext("B")
        notifier.onNext("C")
        
        source.onNext(3)
        source.onNext(4)
        
        //让源序列接收接收消息
        notifier.onNext("D")
        
        source.onNext(5)
        
        //让源序列接收接收消息
        notifier.onCompleted()
        
        /* 结果
         1
         2
         4
         5
         */
        
        // MARK: debounce - 滤掉高频产生的元素，它只会发出这种元素：该元素产生后，一段时间内没有新元素产生
        // 队列中的元素如果和下一个元素的间隔小于了指定的时间间隔，那么这个元素将被过滤掉
        // 常用在用户输入的时候，不需要每个字母敲进去都发送一个事件，而是稍等一下取最后一个事件
        
        //定义好每个事件里的值以及发送的时间
        //        let times = [
        //            [ "value": 1, "time": 0.1 ],
        //            [ "value": 2, "time": 1.1 ],
        //            [ "value": 3, "time": 1.2 ],
        //            [ "value": 4, "time": 1.2 ],
        //            [ "value": 5, "time": 1.4 ],
        //            [ "value": 6, "time": 2.1 ]
        //        ]
        //
        //生成对应的 Observable 序列并订阅
        //        Observable.from(times)
        //            .flatMap { item in
        //                return Observable.of(Int(item["value"]!))
        //                    .delaySubscription(Double(item["time"]!),
        //                                       scheduler: MainScheduler.instance)
        //            }
        //            .debounce(0.5, scheduler: MainScheduler.instance) //只发出与下一个间隔超过0.5秒的元素
        //            .subscribe(onNext: { print($0) })
        //            .disposed(by: disposeBag)
        
        /*
         1
         5
         6
         */
        
        
        // MARK:- 变换操作 对原始的 Observable 序列进行一些转换
        // 类似于 Swift 中 CollectionType 的各种转换
        
        // MARK: buffer - 缓冲组合 第一个参数是缓冲事件，第二个参数是缓冲个数，第三个参数是线程
        // 简单来说就是缓存 Observable 中发出的新元素，当元素达到某个数量，或者经历了特定的时间，就会将这个元素集合发送出来
        let subject = PublishSubject<String>()
        
        // 每缓存3个元素则组合起来一起发出
        // 如果1秒内不够3个也会发出(有几个发几个，一个都没有就发空数组)
        //        subject.buffer(timeSpan: 1, count: 3, scheduler: MainScheduler.instance)
        //        .subscribe(onNext: {print($0)})
        //        .disposed(by: disposeBag)
        //
        //        subject.onNext("1")
        //        subject.onNext("2")
        //        subject.onNext("3")
        //
        //        subject.onNext("a")
        //        subject.onNext("b")
        //        subject.onNext("c")
        
        /*
         ["1", "2", "3"]
         ["a", "b", "c"]
         []
         []
         []
         []
         */
        
        // MARK: window 和 buffer 十分相似。不过 buffer 是周期性的将缓存的元素集合发送出来，而 window 周期性的将元素集合以 Observable 的形态发送出来。
        // 同时 buffer 要等到元素搜集完毕后，才会发出元素序列。而 window 可以实时发出元素序列
        //        let subject1 = PublishSubject<String>()
        
        // 每3个元素作为一个子 Observable发出
        //        subject1.window(timeSpan: 1, count: 3, scheduler: MainScheduler.instance)
        //            .subscribe(onNext:{ [weak self] in
        //                print("subscribe:\($0)")
        //                $0.asObservable()
        //                .subscribe(onNext:{print($0)})
        //                    .disposed(by: self!.disposeBag)
        //
        //            }).disposed(by: disposeBag)
        //
        //        subject1.onNext("1")
        //        subject1.onNext("2")
        //        subject1.onNext("3")
        //
        //        subject1.onNext("a")
        //        subject1.onNext("b")
        //        subject1.onNext("c")
        
        /*
         subscribe:RxSwift.AddRef<Swift.String>
         1
         2
         3
         subscribe:RxSwift.AddRef<Swift.String>
         a
         b
         c
         subscribe:RxSwift.AddRef<Swift.String>
         subscribe:RxSwift.AddRef<Swift.String>
         subscribe:RxSwift.AddRef<Swift.String>
         subscribe:RxSwift.AddRef<Swift.String>
         */
        
        
        // MARK: map - 通过传入一个函数闭包把原来的 Observable 序列转变为一个新的 Observable 序列
        //        Observable.of(1, 2, 3)
        //        .map { $0 * 10}
        //        .subscribe(onNext: { print($0) })
        //        .disposed(by: disposeBag)
        
        /*
         10
         20
         30
         */
        
        // MARK: flatMap - flatMap 操作符会对源 Observable 的每一个元素应用一个转换方法，将他们转换成 Observables。 然后将这些 Observables 的元素合并之后再发送出来
        // map 在做转换的时候容易出现“升维”的情况。即转变之后，从一个序列变成了一个序列的序列。
        // 而 flatMap 操作符会对源 Observable 的每一个元素应用一个转换方法，将他们转换成 Observables。 然后将这些 Observables 的元素合并之后再发送出来。即又将其 "拍扁"（降维）成一个 Observable 序列。
        // 这个操作符是非常有用的。比如当 Observable 的元素本生拥有其他的 Observable 时，我们可以将所有子 Observables 的元素发送出来
        let subject2 = BehaviorSubject(value: "A")
        let subject3 = BehaviorSubject(value: "1")
        
        let variable = Variable(subject2)
        variable.asObservable()
            .flatMap { $0 }
            .subscribe(onNext: { print($0) })
            .disposed(by: disposeBag)
        
        subject2.onNext("B")
        variable.value = subject2
        subject3.onNext("2")
        subject2.onNext("C")
        
        /*
         A
         B
         B
         C
         C
         */
        
        // MARK: flatMapLatest - 与 flatMap 的唯一区别是：flatMapLatest 只会接收最新的 value 事件
        
        // MARK: flatMapFirst - 与 flatMapLatest 正好相反：flatMapFirst 只会接收最初的 value 事件。
        // 该操作符可以防止重复请求：比如点击一个按钮发送一个请求，当该请求完成前，该按钮点击都不应该继续发送请求。便可该使用 flatMapFirst 操作符。
        
        // MARK: concatMap - 与 flatMap 的唯一区别是：当前一个 Observable 元素发送完毕后，后一个Observable 才可以开始发出元素
        // 或者说等待前一个 Observable 产生完成事件后，才对后一个 Observable 进行订阅
        
        
        // MARK: scan - 先给一个初始化的数，然后不断的拿前一个结果和最新的值进行处理操作
        Observable.of(1, 2, 3, 4, 5)
            .scan(0) { acum, elem in
                acum + elem
        }
        .subscribe(onNext: { print($0) })
        .disposed(by: disposeBag)
        
        /*
         1
         3
         6
         10
         15
         */
        
        // MARK: groupBy - 将源 Observable 分解为多个子 Observable，然后将这些子 Observable 发送出来
        // 也就是说该操作符会将元素通过某个键进行分组，然后将分组后的元素序列以 Observable 的形态发送出来。
        //将奇数偶数分成两组
        Observable<Int>.of(0, 1, 2, 3, 4, 5)
            .groupBy(keySelector: { (element) -> String in
                return element % 2 == 0 ? "偶数" : "基数"
            })
            .subscribe { (event) in
                switch event {
                case .next(let group):
                    group.asObservable().subscribe({ (event) in
                        print("key：\(group.key)    event：\(event)")
                    })
                        .disposed(by: self.disposeBag)
                default:
                    print("")
                }
        }
        .disposed(by: disposeBag)
        
        /*
         key：偶数    event：next(0)
         key：基数    event：next(1)
         key：偶数    event：next(2)
         key：基数    event：next(3)
         key：偶数    event：next(4)
         key：基数    event：next(5)
         key：基数    event：completed
         key：偶数    event：completed
         */
        
        // MARK: - Subjects
        // 前面说的 Observable 实际是创建一个 Observable 的时候就要预先将要发出的数据都准备好，等到有人订阅它时再将数据通过 Event 发出去
        // 我们希望 Observable 在运行时能动态地“获得”或者说“产生”出一个新的数据，再通过 Event 发送出去，就需要使用 Subjects
        /*
         Subjects 既是订阅者，也是 Observable：
         说它是订阅者，是因为它能够动态地接收新的值。
         说它又是一个 Observable，是因为当 Subjects 有了新的值之后，就会通过 Event 将新值发出给他的所有订阅者
         一共有四种 Subjects，分别为：PublishSubject、BehaviorSubject、ReplaySubject、Variable。他们之间既有各自的特点，也有相同之处：
         首先他们都是 Observable，他们的订阅者都能收到他们发出的新的 Event。
         直到 Subject 发出 .complete 或者 .error 的 Event 后，该 Subject 便终结了，同时它也就不会再发出 .next 事件。
         对于那些在 Subject 终结后再订阅他的订阅者，也能收到 subject 发出的一条 .complete 或 .error 的 event，告诉这个新的订阅者它已经终结了。
         他们之间最大的区别只是在于：当一个新的订阅者刚订阅它的时候，能不能收到 Subject 以前发出过的旧 Event，如果能的话又能收到多少个。
        
         Subject 常用的几个方法：
         onNext(:)：是 on(.next(:)) 的简便写法。该方法相当于 subject 接收到一个 .next 事件。
         onError(:)：是 on(.error(:)) 的简便写法。该方法相当于 subject 接收到一个 .error 事件。
         onCompleted()：是 on(.completed) 的简便写法。该方法相当于 subject 接收到一个 .completed 事件。
         */
        
        // MARK: PublishSubject  - 最普通的 Subject，它不需要初始值就能创建
        // PublishSubject 的订阅者从他们开始订阅的时间点起，可以收到订阅后 Subject 发出的新 Event，而不会收到他们在订阅前已发出的 Event。
        
        //创建一个PublishSubject
        let subject4 = PublishSubject<String>()
        
        //由于当前没有任何订阅者，所以这条信息不会输出到控制台
        subject4.onNext("111")
        
        //第1次订阅subject
        subject4.subscribe(onNext: { string in
            print("第1次订阅：", string)
        }, onCompleted:{
            print("第1次订阅：onCompleted")
        }).disposed(by: disposeBag)
        
        //当前有1个订阅，则该信息会输出到控制台
        subject4.onNext("222")
        
        //第2次订阅subject
        subject4.subscribe(onNext: { string in
            print("第2次订阅：", string)
        }, onCompleted:{
            print("第2次订阅：onCompleted")
        }).disposed(by: disposeBag)
        
        //当前有2个订阅，则该信息会输出到控制台
        subject4.onNext("333")
        
        //让subject结束
        subject4.onCompleted()
        
        //subject完成后会发出.next事件了。
        subject4.onNext("444")
        
        //subject完成后它的所有订阅（包括结束后的订阅），都能收到subject的.completed事件，
        subject4.subscribe(onNext: { string in
            print("第3次订阅：", string)
        }, onCompleted:{
            print("第3次订阅：onCompleted")
        }).disposed(by: disposeBag)
        
        
        /*
         第1次订阅： 222
         第1次订阅： 333
         第2次订阅： 333
         第1次订阅：onCompleted
         第2次订阅：onCompleted
         第3次订阅：onCompleted
         */
        
        
        // MARK: BehaviorSubject - 通过一个默认初始值来创建
        // 当一个订阅者来订阅它的时候，这个订阅者会立即收到 BehaviorSubjects 上一个发出的 event。之后就跟正常的情况一样，它也会接收到 BehaviorSubject 之后发出的新的 event。
        
        //创建一个BehaviorSubject
        let subject5 = BehaviorSubject(value: "111")
        
        //第1次订阅subject
        subject5.subscribe { event in
            print("第1次订阅：", event)
        }.disposed(by: disposeBag)
        
        //发送next事件
        subject5.onNext("222")
        
        //发送error事件
        subject5.onError(NSError(domain: "local", code: 0, userInfo: nil))
        
        //第2次订阅subject
        subject5.subscribe { event in
            print("第2次订阅：", event)
        }.disposed(by: disposeBag)
        
        /*
         第1次订阅： next(111)
         第1次订阅： next(222)
         第1次订阅： error(Error Domain=local Code=0 "(null)")
         第2次订阅： error(Error Domain=local Code=0 "(null)")
         */
        
        // MARK: ReplaySubject - 在创建时候需要设置一个 bufferSize，表示它对于它发送过的 event 的缓存个数
        // 比如一个 ReplaySubject 的 bufferSize 设置为 2，它发出了 3 个 .next 的 event，那么它会将后两个（最近的两个）event 给缓存起来。此时如果有一个 subscriber 订阅了这个 ReplaySubject，那么这个 subscriber 就会立即收到前面缓存的两个 .next 的 event。
        // 如果一个 subscriber 订阅已经结束的 ReplaySubject，除了会收到缓存的 .next 的 event 外，还会收到那个终结的 .error 或者 .complete 的 event。
        
        //创建一个bufferSize为2的ReplaySubject
        let subject6 = ReplaySubject<String>.create(bufferSize: 2)
        
        //连续发送3个next事件
        subject6.onNext("111")
        subject6.onNext("222")
        subject6.onNext("333")
        
        //第1次订阅subject
        subject6.subscribe { event in
            print("第1次订阅：", event)
        }.disposed(by: disposeBag)
        
        //再发送1个next事件
        subject6.onNext("444")
        
        //第2次订阅subject
        subject6.subscribe { event in
            print("第2次订阅：", event)
        }.disposed(by: disposeBag)
        
        //让subject结束
        subject6.onCompleted()
        
        //第3次订阅subject
        subject6.subscribe { event in
            print("第3次订阅：", event)
        }.disposed(by: disposeBag)
        
        /*
         第1次订阅： next(222)
         第1次订阅： next(333)
         第1次订阅： next(444)
         第2次订阅： next(333)
         第2次订阅： next(444)
         第1次订阅： completed
         第2次订阅： completed
         第3次订阅： next(333)
         第3次订阅： next(444)
         第3次订阅： completed
         */
        
        //MARK: Variable - 就是对 BehaviorSubject 的封装，所以它也必须要通过一个默认的初始值进行创建
        // 由于 Variable 在之后版本中将被废弃，建议使用 Varible 的地方都改用下面介绍的 BehaviorRelay 作为替代
        // Variable 具有 BehaviorSubject 的功能，能够向它的订阅者发出上一个 event 以及之后新创建的 event
        // 不同的是，Variable 还把会把当前发出的值保存为自己的状态。同时它会在销毁时自动发送 .complete 的 event，不需要也不能手动给 Variables 发送 completed 或者 error 事件来结束它。
        // 简单地说就是 Variable 有一个 value 属性，我们改变这个 value 属性的值就相当于调用一般 Subjects 的 onNext() 方法，而这个最新的 onNext() 的值就被保存在 value 属性里了，直到我们再次修改它
        // Variables 本身没有 subscribe() 方法，但是所有 Subjects 都有一个 asObservable() 方法。我们可以使用这个方法返回这个 Variable 的 Observable 类型，拿到这个 Observable 类型我们就能订阅它了。
        
        //创建一个初始值为111的Variable
        let variable1 = Variable("111")
        
        //修改value值
        variable1.value = "222"
        
        //第1次订阅
        variable1.asObservable().subscribe {
            print("第1次订阅：", $0)
        }.disposed(by: disposeBag)
        
        //修改value值
        variable1.value = "333"
        
        //第2次订阅
        variable1.asObservable().subscribe {
            print("第2次订阅：", $0)
        }.disposed(by: disposeBag)
        
        //修改value值
        variable1.value = "444"
        
        /*
         第1次订阅： next(222)
         第1次订阅： next(333)
         第2次订阅： next(333)
         第1次订阅： next(444)
         第2次订阅： next(444)
         第1次订阅： completed
         第2次订阅： completed
         由于 Variable 对象在 viewDidLoad() 方法内初始化，所以它的生命周期就被限制在该方法内。当这个方法执行完毕后，这个 Variable 对象就会被销毁，同时它也就自动地向它的所有订阅者发出 .completed 事件
         */
        
        // MARK: BehaviorRelay - BehaviorRelay 是作为 Variable 的替代者出现的。
        // 它的本质其实也是对 BehaviorSubject 的封装，所以它也必须要通过一个默认的初始值进行创建
        // BehaviorRelay 具有 BehaviorSubject 的功能，能够向它的订阅者发出上一个 event 以及之后新创建的 event
        // 与 BehaviorSubject 不同的是，不需要也不能手动给 BehaviorReply 发送 completed 或者 error 事件来结束它（BehaviorRelay 会在销毁时也不会自动发送 .complete 的 event）
        // BehaviorRelay 有一个 value 属性，我们通过这个属性可以获取最新值。而通过它的 accept() 方法可以对值进行修改
        
        //创建一个初始值为111的BehaviorRelay
        let subject7 = BehaviorRelay<String>(value: "111")
        
        //修改value值
        subject7.accept("222")
        
        //第1次订阅
        subject7.asObservable().subscribe {
            print("第1次订阅：", $0)
        }.disposed(by: disposeBag)
        
        //修改value值
        subject7.accept("333")
        
        //第2次订阅
        subject7.asObservable().subscribe {
            print("第2次订阅：", $0)
        }.disposed(by: disposeBag)
        
        //修改value值
        subject7.accept("444")
        
        /*
         第1次订阅： next(222)
         第1次订阅： next(333)
         第2次订阅： next(333)
         第1次订阅： next(444)
         第2次订阅： next(444)
         */
        
        // 如果想将新值合并到原值上，可以通过 accept() 方法与 value 属性配合来实现。（这个常用在表格上拉加载功能上，BehaviorRelay 用来保存所有加载到的数据）
        //创建一个初始值为包含一个元素的数组的BehaviorRelay
        let subject8 = BehaviorRelay<[String]>(value: ["1"])
        
        //修改value值
        subject8.accept(subject8.value + ["2", "3"])
        
        //第1次订阅
        subject8.asObservable().subscribe {
            print("第1次订阅：", $0)
        }.disposed(by: disposeBag)
        
        //修改value值
        subject8.accept(subject8.value + ["4", "5"])
        
        //第2次订阅
        subject8.asObservable().subscribe {
            print("第2次订阅：", $0)
        }.disposed(by: disposeBag)
        
        //修改value值
        subject8.accept(subject8.value + ["6", "7"])
        
        /*
         第1次订阅： next(["1", "2", "3"])
         第1次订阅： next(["1", "2", "3", "4", "5"])
         第2次订阅： next(["1", "2", "3", "4", "5"])
         第1次订阅： next(["1", "2", "3", "4", "5", "6", "7"])
         第2次订阅： next(["1", "2", "3", "4", "5", "6", "7"])
         */
        
        // MARK: - 条件和布尔操作符（Conditional and Boolean Operators）
        // 操作符 https://beeth0ven.github.io/RxSwift-Chinese-Documentation/content/rxswift_core/operator.html
        // 条件和布尔操作会根据条件发射或变换 Observables，或者对他们做布尔运算
        
        // MARK: amb - 当传入多个 Observables 到 amb 操作符时，它将取第一个发出元素或产生事件的 Observable，然后只发出它的元素。并忽略掉其他的 Observables
        //        let subject1 = PublishSubject<Int>()
        //        let subject2 = PublishSubject<Int>()
        //        let subject3 = PublishSubject<Int>()
        //
        //        subject1
        //            .amb(subject2)
        //            .amb(subject3)
        //            .subscribe(onNext: { print($0) })
        //            .disposed(by: disposeBag)
        //
        //        subject2.onNext(1)
        //        subject1.onNext(20)
        //        subject2.onNext(2)
        //        subject1.onNext(40)
        //        subject3.onNext(0)
        //        subject2.onNext(3)
        //        subject1.onNext(60)
        //        subject3.onNext(0)
        //        subject3.onNext(0)
        
        /*
         1
         2
         3
         */
        
        // MARK: takeWhile - 依次判断 Observable 序列的每一个值是否满足给定的条件。 当第一个不满足条件的值出现时，它便自动完成
        Observable.of(2, 3, 4, 5, 6)
            .takeWhile { $0 < 4 }
            .subscribe(onNext: { print($0) })
            .disposed(by: disposeBag)
        
        /*
         2
         3
         */
        
        // MARK: takeUntil - 除了订阅源 Observable 外，通过 takeUntil 方法我们还可以监视另外一个 Observable， 即 notifier
        // 如果 notifier 发出值或 complete 通知，那么源 Observable 便自动完成，停止发送事件
        
        //        let source = PublishSubject<String>()
        //        let notifier = PublishSubject<String>()
        //
        //        source
        //            .takeUntil(notifier)
        //            .subscribe(onNext: { print($0) })
        //            .disposed(by: disposeBag)
        //
        //        source.onNext("a")
        //        source.onNext("b")
        //        source.onNext("c")
        //        source.onNext("d")
        //
        //        //停止接收消息
        //        notifier.onNext("z")
        //
        //        source.onNext("e")
        //        source.onNext("f")
        //        source.onNext("g")
        
        
        /*
         a
         b
         c
         d
         */
        
        // MARK: skipWhile - 跳过前面所有满足条件的事件，一旦遇到不满足条件的事件，之后就不会再跳过了
        Observable.of(2, 3, 4, 5, 6)
            .skipWhile { $0 < 4 }
            .subscribe(onNext: { print($0) })
            .disposed(by: disposeBag)
        
        /*
         4
         5
         6
         */
        
        // MARK: skipUntil - takeUntil 一样，skipUntil 除了订阅源 Observable 外，通过 skipUntil 方法我们还可以监视另外一个 Observable， 即 notifier 。
        // 与 takeUntil 相反的是。源 Observable 序列事件默认会一直跳过，直到 notifier 发出值或 complete 通知
        //
        //        let source = PublishSubject<Int>()
        //        let notifier = PublishSubject<Int>()
        //
        //        source
        //            .skipUntil(notifier)
        //            .subscribe(onNext: { print($0) })
        //            .disposed(by: disposeBag)
        //
        //        source.onNext(1)
        //        source.onNext(2)
        //        source.onNext(3)
        //        source.onNext(4)
        //        source.onNext(5)
        //
        //        //开始接收消息
        //        notifier.onNext(0)
        //
        //        source.onNext(6)
        //        source.onNext(7)
        //        source.onNext(8)
        //
        //        //仍然接收消息
        //        notifier.onNext(0)
        //
        //        source.onNext(9)
        
        /*
         6
         7
         8
         9
         */
        
        //MARK:- 结合操作（Combining Observables）
        // MARK: startWith  - 在 Observable 序列开始之前插入一些事件元素。即发出事件消息之前，会先发出这些预先插入的事件消息
        Observable.of("2", "3")
            .startWith("1")
            .subscribe(onNext: { print($0) })
            .disposed(by: disposeBag)
        
        /*
         1
         2
         3
         */
        
        // 插入多个数据也可以
        Observable.of("2", "3")
            .startWith("a")
            .startWith("b")
            .startWith("c")
            .subscribe(onNext: { print($0) })
            .disposed(by: disposeBag)
        
        /*
         c
         b
         a
         2
         3
         */
        
        //MARK: merge - 将多个（两个或两个以上的）Observable 序列合并成一个 Observable 序列
        //        let subject11 = PublishSubject<Int>()
        //        let subject22 = PublishSubject<Int>()
        //
        //        Observable.of(subject11, subject22)
        //            .merge()
        //            .subscribe(onNext: { print($0) })
        //            .disposed(by: disposeBag)
        //
        //        subject11.onNext(20)
        //        subject11.onNext(40)
        //        subject11.onNext(60)
        //        subject22.onNext(1)
        //        subject11.onNext(80)
        //        subject11.onNext(100)
        //        subject22.onNext(1)
        
        /*
         20
         40
         60
         1
         80
         100
         1
         */
        
        // MARK: zip - 将多个（两个或两个以上的）Observable 序列压缩成一个 Observable 序列
        // 会等到每个 Observable 事件一一对应地凑齐之后再合并
        //        let subject11 = PublishSubject<Int>()
        //        let subject22 = PublishSubject<String>()
        //
        //        Observable.zip(subject11, subject22) {
        //            "\($0)\($1)"
        //            }
        //            .subscribe(onNext: { print($0) })
        //            .disposed(by: disposeBag)
        //
        //        subject11.onNext(1)
        //        subject22.onNext("A")
        //        subject11.onNext(2)
        //        subject22.onNext("B")
        //        subject22.onNext("C")
        //        subject22.onNext("D")
        //        subject11.onNext(3)
        //        subject11.onNext(4)
        //        subject11.onNext(5)
        
        /*
         1A
         2B
         3C
         4D
         */
        
        // 常用在整合网络请求上。 比如同时发送两个请求，只有当两个请求都成功后，再将两者的结果整合起来继续往下处理。这个功能就可以通过 zip 来实现
        /*
         //第一个请求
         let userRequest: Observable<User> = API.getUser("me")
         
         //第二个请求
         let friendsRequest: Observable<Friends> = API.getFriends("me")
         
         //将两个请求合并处理
         Observable.zip(userRequest, friendsRequest) {
         user, friends in
         //将两个信号合并成一个信号，并压缩成一个元组返回（两个信号均成功）
         return (user, friends)
         }
         .observeOn(MainScheduler.instance) //加这个是应为请求在后台线程，下面的绑定在前台线程。
         .subscribe(onNext: { (user, friends) in
         //将数据绑定到界面上
         //.......
         })
         .disposed(by: disposeBag)
         */
        
        // MARK: combineLatest - 同样是将多个（两个或两个以上的）Observable 序列元素进行合并
        // 不同的是，每当任意一个 Observable 有新的事件发出时，它会将每个 Observable 序列的最新的一个事件元素进行合并
        //        let subject11 = PublishSubject<Int>()
        //        let subject22 = PublishSubject<String>()
        //
        //        Observable.combineLatest(subject11, subject22) {
        //            "\($0)\($1)"
        //            }
        //            .subscribe(onNext: { print($0) })
        //            .disposed(by: disposeBag)
        //
        //        subject11.onNext(1)
        //        subject22.onNext("A")
        //        subject11.onNext(2)
        //        subject22.onNext("B")
        //        subject22.onNext("C")
        //        subject22.onNext("D")
        //        subject11.onNext(3)
        //        subject11.onNext(4)
        //        subject11.onNext(5)
        
        /*
         1A
         2A
         2B
         2C
         2D
         3D
         4D
         5D
         */
        
        //MARK: withLatestFrom - 将两个 Observable 序列合并为一个。每当 self 队列发射一个元素时，便从第二个序列中取出最新的一个值
        
        //        let subject11 = PublishSubject<String>()
        //        let subject22 = PublishSubject<String>()
        //
        //        subject11.withLatestFrom(subject22)
        //            .subscribe(onNext: { print($0) })
        //            .disposed(by: disposeBag)
        //
        //        subject11.onNext("A")
        //        subject22.onNext("1")
        //        subject11.onNext("B")
        //        subject11.onNext("C")
        //        subject22.onNext("2")
        //        subject11.onNext("D")
        
        /*
         1
         1
         2
         */
        
        // MARK: switchLatest - switchLatest 有点像其他语言的 switch 方法，可以对事件流进行转换
        // 比如本来监听的 subject1，我可以通过更改 variable 里面的 value 更换事件源。变成监听 subject2
        
        let subject11 = BehaviorSubject(value: "A")
        let subject22 = BehaviorSubject(value: "1")
        
        let variable11 = Variable(subject11)
        
        variable11.asObservable()
            .switchLatest()
            .subscribe(onNext: { print($0) })
            .disposed(by: disposeBag)
        
        subject11.onNext("B")
        subject11.onNext("C")
        
        //改变事件源
        variable11.value = subject22
        subject11.onNext("D")
        subject22.onNext("2")
        
        //改变事件源
        variable11.value = subject11
        subject22.onNext("3")
        subject11.onNext("E")
        
        /*
         A
         B
         C
         1
         2
         D
         E
         */
        
        // MARK: - 算数、以及聚合操作（Mathematical and Aggregate Operators）
        // MARK: toArray  - 先把一个序列转成一个数组，并作为一个单一的事件发送，然后结束
        Observable.of(1,2,3)
            .toArray()
            .subscribe({ print($0) })
            .disposed(by:disposeBag)
        
        
        /*
         success([1, 2, 3])
         */
        
        // MARK: reduce - 接受一个初始值，和一个操作符号。
        // 将给定的初始值，与序列里的每个值进行累计运算。得到一个最终结果，并将其作为单个值发送出去
        Observable.of(1,2,3,4,5)
            .reduce(0, accumulator: +)
            .subscribe(onNext: {print($0)})
            .disposed(by: disposeBag)
        
        /*
         15
         */
        
        // MARK: concat - 会把多个 Observable 序列合并（串联）为一个 Observable 序列
        // 并且只有当前面一个 Observable 序列发出了 completed 事件，才会开始发送下一个 Observable 序列事件
        let subject33 = BehaviorSubject(value: 1)
        let subject44 = BehaviorSubject(value: 2)
        
        let variable33 = Variable(subject33)
        variable33.asObservable()
            .concat()
            .subscribe(onNext: {
                print($0)
            })
            .disposed(by: disposeBag)
        
        subject44.onNext(2)
        subject33.onNext(1)
        subject33.onNext(1)
        subject33.onCompleted()
        
        variable33.value = subject44
        subject44.onNext(2)
        
        /*
         1
         1
         1
         2
         2
         */
        
        
        //MARK: - 连接操作（Connectable Observable Operators）
        // 可连接的序列（Connectable Observable）：
        // （1）可连接的序列和一般序列不同在于：有订阅时不会立刻开始发送事件消息，只有当调用 connect() 之后才会开始发送值。
        // （2）可连接的序列可以让所有的订阅者订阅后，才开始发出事件消息，从而保证我们想要的所有订阅者都能接收到事件消息。
        
        // 普通序列
        // 每隔1秒发送1个事件
//        let interval = Observable<Int>.interval(1, scheduler: MainScheduler.instance)
//        // 第一个订阅者
//        interval.subscribe(onNext: {
//            print("订阅1 \($0)")
//        }).disposed(by: disposeBag)
//
//        // 第二个订阅者
//        delay(5) {
//            interval.subscribe(onNext: { print("订阅2： \($0)")
//            }).disposed(by: self.disposeBag)
//        }
        
        /*
         订阅1 0
         订阅1 1
         订阅1 2
         订阅1 3
         订阅1 4
         订阅1 5
         订阅2： 0
         订阅1 6
         订阅2： 1
         */
        
        
        // MARK: publish - 将一个正常的序列转换成一个可连接的序列。同时该序列不会立刻发送事件，只有在调用 connect 之后才会开始。
        //每隔1秒钟发送1个事件
//        let interval = Observable<Int>.interval(1, scheduler: MainScheduler.instance)
//            .publish()
//
//        //第一个订阅者（立刻开始订阅）
//        _ = interval
//            .subscribe(onNext: { print("订阅1: \($0)") })
//
//        //相当于把事件消息推迟了两秒
//        delay(2) {
//            _ = interval.connect()
//        }
//
//        //第二个订阅者（延迟5秒开始订阅）
//        delay(5) {
//            _ = interval
//                .subscribe(onNext: { print("订阅2: \($0)") })
//        }
        
        /*
         订阅1: 0
         订阅1: 1
         订阅1: 2
         订阅2: 2
         订阅1: 3
         订阅2: 3
         订阅1: 4
         订阅2: 4
         订阅1: 5
         订阅2: 5
         */
        
        // MARK: replay - replay 同上面的 publish 方法相同之处在于：会将将一个正常的序列转换成一个可连接的序列。同时该序列不会立刻发送事件，只有在调用 connect 之后才会开始。
        // replay 与 publish 不同在于：新的订阅者还能接收到订阅之前的事件消息（数量由设置的 bufferSize 决定）
        //每隔1秒钟发送1个事件
//        let interval = Observable<Int>.interval(1, scheduler: MainScheduler.instance)
//            .replay(5)
//
//        //第一个订阅者（立刻开始订阅）
//        _ = interval
//            .subscribe(onNext: { print("订阅1: \($0)") })
//
//        //相当于把事件消息推迟了两秒
//        delay(2) {
//            _ = interval.connect()
//        }
//
//        //第二个订阅者（延迟5秒开始订阅）
//        delay(5) {
//            _ = interval
//                .subscribe(onNext: { print("订阅2: \($0)") })
//        }
        
        /*
         订阅1: 0
         订阅1: 1
         订阅2: 0
         订阅2: 1
         订阅1: 2
         订阅2: 2
         订阅1: 3
         订阅2: 3
         订阅1: 4
         订阅2: 4
         订阅1: 5
         订阅2: 5
         */
        
        // MARK: multicast - 同样是将一个正常的序列转换成一个可连接的序列。
        // 同时 multicast 方法还可以传入一个 Subject，每当序列发送事件时都会触发这个 Subject 的发送。
       
//        //创建一个Subject（后面的multicast()方法中传入）
//        let subject55 = PublishSubject<Int>()
//
//        //这个Subject的订阅
//        _ = subject55
//            .subscribe(onNext: { print("Subject: \($0)") })
//
//        //每隔1秒钟发送1个事件
//        let interval = Observable<Int>.interval(1, scheduler: MainScheduler.instance)
//            .multicast(subject55)
//
//        //第一个订阅者（立刻开始订阅）
//        _ = interval
//            .subscribe(onNext: { print("订阅1: \($0)") })
//
//        //相当于把事件消息推迟了两秒
//        delay(2) {
//            _ = interval.connect()
//        }
//
//        //第二个订阅者（延迟5秒开始订阅）
//        delay(5) {
//            _ = interval
//                .subscribe(onNext: { print("订阅2: \($0)") })
//        }

        /*
         Subject: 0
         订阅1: 0
         Subject: 1
         订阅1: 1
         Subject: 2
         订阅1: 2
         Subject: 3
         订阅1: 3
         订阅2: 3
         Subject: 4
         订阅1: 4
         订阅2: 4
         Subject: 5
         订阅1: 5
         订阅2: 5
         */
        
        
        // MARK: refCount - refCount 操作符可以将可被连接的 Observable 转换为普通 Observable
        // 即该操作符可以自动连接和断开可连接的 Observable。当第一个观察者对可连接的 Observable 订阅时，那么底层的 Observable 将被自动连接。当最后一个观察者离开时，那么底层的 Observable 将被自动断开连接
        
        //每隔1秒钟发送1个事件
//        let interval = Observable<Int>.interval(1, scheduler: MainScheduler.instance)
//            .publish()
//            .refCount()
//
//        //第一个订阅者（立刻开始订阅）
//        _ = interval
//            .subscribe(onNext: { print("订阅1: \($0)") })
//
//        //第二个订阅者（延迟5秒开始订阅）
//        delay(5) {
//            _ = interval
//                .subscribe(onNext: { print("订阅2: \($0)") })
//        }
        
        /*
         订阅1: 0
         订阅1: 1
         订阅1: 2
         订阅1: 3
         订阅1: 4
         订阅1: 5
         订阅2: 5
         订阅1: 6
         订阅2: 6
         订阅1: 7
         订阅2: 7
         订阅1: 8
         订阅2: 8
         订阅1: 9
         订阅2: 9
         */
        
        // MARK: share(relay:) - 使得观察者共享源 Observable，并且缓存最新的 n 个元素，将这些元素直接发送给新的观察者。
        // 简单来说 shareReplay 就是 replay 和 refCount 的组合。
        //每隔1秒钟发送1个事件
//        let interval = Observable<Int>.interval(1, scheduler: MainScheduler.instance)
//            .share(replay: 5)
//
//        //第一个订阅者（立刻开始订阅）
//        _ = interval
//            .subscribe(onNext: { print("订阅1: \($0)") })
//
//        //第二个订阅者（延迟5秒开始订阅）
//        delay(5) {
//            _ = interval
//                .subscribe(onNext: { print("订阅2: \($0)") })
//        }
        
        /*
         订阅1: 0
         订阅1: 1
         订阅1: 2
         订阅1: 3
         订阅1: 4
         订阅2: 0
         订阅2: 1
         订阅2: 2
         订阅2: 3
         订阅2: 4
         订阅1: 5
         订阅2: 5
         订阅1: 6
         订阅2: 6
         */
        
        // MARK: - 特征序列
        // 除了 Observable，RxSwift 还为我们提供了一些特征序列（Traits）：Single、Completable、Maybe、Driver、Signal、ControlEvent。
        // 我们可以将这些 Traits(特征) 看作是 Observable 的另外一个版本。它们之间的区别是：
        // Observable 是能够用于任何上下文环境的通用序列。
        // 而 Traits(特征序列) 可以帮助我们更准确的描述序列。同时它们还为我们提供上下文含义、语法糖，让我们能够用更加优雅的方式书写代码。
        
        // MARK: Single - 是 Observable 的另外一个版本。但它不像 Observable 可以发出多个元素，它要么只能发出一个元素，要么产生一个 error 事件
        // 发出一个元素，或一个 error 事件
        // 不会共享状态变化
        
        // 应用场景
        // 常见的例子就是执行 HTTP 请求，然后返回一个应答或错误。不过我们也可以用 Single 来描述任何只有一个元素的序列。
        
        // SingleEvent  为方便使用，RxSwift 还为 Single 订阅提供了一个枚举（SingleEvent）
        // .success：里面包含该 Single 的一个元素值
        // .error：用于包含错误
        /*
        public enum SingleEvent<Element> {
            case success(Element)
            case error(Swift.Error)
        }*/
        
        // 例子 定义一个用于生成网络请求 Single 的函数
        /*
         //获取豆瓣某频道下的歌曲信息
         func getPlaylist(_ channel: String) -> Single<[String: Any]> {
             return Single<[String: Any]>.create { single in
                 let url = "https://douban.fm/j/mine/playlist?"
                     + "type=n&channel=\(channel)&from=mainsite"
                 let task = URLSession.shared.dataTask(with: URL(string: url)!) { data, _, error in
                     if let error = error {
                         single(.error(error))
                         return
                     }
                      
                     guard let data = data,
                         let json = try? JSONSerialization.jsonObject(with: data,
                                                                      options: .mutableLeaves),
                         let result = json as? [String: Any] else {
                             single(.error(DataError.cantParseJSON))
                             return
                     }
                      
                     single(.success(result))
                 }
                  
                 task.resume()
                  
                 return Disposables.create { task.cancel() }
             }
         }
          
         //与数据相关的错误类型
         enum DataError: Error {
             case cantParseJSON
         }
         
         
         // 使用：
         import UIKit
         import RxSwift
         import RxCocoa
          
         class ViewController: UIViewController {
             let disposeBag = DisposeBag()
              
             override func viewDidLoad() {
                 //获取第0个频道的歌曲信息
                 getPlaylist("0")
                     .subscribe { event in
                         switch event {
                         case .success(let json):
                             print("JSON结果: ", json)
                         case .error(let error):
                             print("发生错误: ", error)
                         }
                     }
                     .disposed(by: disposeBag)
             }
         }
         
         // 或者：
         import UIKit
         import RxSwift
         import RxCocoa
          
         class ViewController: UIViewController {
             let disposeBag = DisposeBag()
              
             override func viewDidLoad() {
                 //获取第0个频道的歌曲信息
                 getPlaylist("0")
                     .subscribe(onSuccess: { json in
                         print("JSON结果: ", json)
                     }, onError: { error in
                         print("发生错误: ", error)
                     })
                     .disposed(by: disposeBag)
             }
         }

         */
        
        // asSingle()
        // 可以通过调用 Observable 序列的 .asSingle() 方法，将它转换为 Single
        Observable.of("1")
        .asSingle()
        .subscribe({ print($0) })
        .disposed(by: disposeBag)
        
        // MARK: Completable - Observable 的另外一个版本。不像 Observable 可以发出多个元素，它要么只能产生一个 completed 事件，要么产生一个 error 事件
        /*
         不会发出任何元素(发出零个元素)
         只会发出一个 completed 事件或者一个 error 事件
         不会共享状态变化
         
         // 应用场景
         Completable 和 Observable<Void> 有点类似。适用于那些只关心任务是否完成，而不需要在意任务返回值的情况。比如：在程序退出时将一些数据缓存到本地文件，供下次启动时加载。像这种情况我们只关心缓存是否成功
         
         // CompletableEvent
         RxSwift 为 Completable 订阅提供了一个枚举（CompletableEvent）：
         .completed：用于产生完成事件
         .error：用于产生一个错误
    
         public enum CompletableEvent {
             case error(Swift.Error)
             case completed
         }
       */
        
        // 例子：创建 Completable 和创建 Observable 非常相似。下面代码我们使用 Completable 来模拟一个数据缓存本地的操作
        //将数据缓存到本地
//        func cacheLocally() -> Completable {
//            return Completable.create { completable in
//                //将数据缓存到本地（这里掠过具体的业务代码，随机成功或失败）
//                let success = (arc4random() % 2 == 0)
//
//                guard success else {
//                    completable(.error(CacheError.failedCaching))
//                    return Disposables.create {}
//                }
//
//                completable(.completed)
//                return Disposables.create {}
//            }
//        }
//
//        //与缓存相关的错误类型
//        enum CacheError: Error {
//            case failedCaching
//        }
//
//        // 使用方式1：
//        cacheLocally()
//        .subscribe { completable in
//            switch completable {
//            case .completed:
//                print("保存成功!")
//            case .error(let error):
//                print("保存失败: \(error.localizedDescription)")
//            }
//        }
//        .disposed(by: disposeBag)
//
//        // 使用方式2：
//        cacheLocally()
//        .subscribe(onCompleted: {
//             print("保存成功!")
//        }, onError: { error in
//            print("保存失败: \(error.localizedDescription)")
//        })
//        .disposed(by: disposeBag)
        
        // MARK: Maybe - 同样是 Observable 的另外一个版本。它介于 Single 和 Completable 之间，它要么只能发出一个元素，要么产生一个 completed 事件，要么产生一个 error 事件
        /*
         发出一个元素、或者一个 completed 事件、或者一个 error 事件
         不会共享状态变化
         
         // 应用场景：
         那种可能需要发出一个元素，又可能不需要发出的情况
         */
        // MaybeEvent  RxSwift 为 Maybe 订阅提供了一个枚举（MaybeEvent）
        /*
         .success：里包含该 Maybe 的一个元素值
         .completed：用于产生完成事件
         .error：用于产生一个错误
         
         public enum MaybeEvent<Element> {
             case success(Element)
             case error(Swift.Error)
             case completed
         }
         */
        
        // 使用例子：
//        func generateString() -> Maybe<String> {
//            return Maybe<String>.create { maybe in
//
//                //成功并发出一个元素
//                maybe(.success("hangge.com"))
//
//                //或者成功但不发出任何元素
//                maybe(.completed)
//
//                //或者失败
//                //maybe(.error(StringError.failedGenerate))
//
//                return Disposables.create {}
//            }
//        }
//
//        //与缓存相关的错误类型
//        enum StringError: Error {
//            case failedGenerate
//        }
//
//        // 使用1：
//        generateString()
//         .subscribe { maybe in
//             switch maybe {
//             case .success(let element):
//                 print("执行完毕，并获得元素：\(element)")
//             case .completed:
//                 print("执行完毕，且没有任何元素。")
//             case .error(let error):
//                 print("执行失败: \(error.localizedDescription)")
//
//             }
//         }
//         .disposed(by: disposeBag)
//
//        // 使用2：
//        generateString()
//        .subscribe(onSuccess: { element in
//            print("执行完毕，并获得元素：\(element)")
//        },
//                   onError: { error in
//                    print("执行失败: \(error.localizedDescription)")
//        },
//                   onCompleted: {
//                    print("执行完毕，且没有任何元素。")
//        })
//        .disposed(by: disposeBag)
        
        // asMaybe() 可以通过调用 Observable 序列的 .asMaybe() 方法，将它转换为 Maybe
        Observable.of("1")
        .asMaybe()
        .subscribe({ print($0) })
        .disposed(by: disposeBag)
        
        
        //MARK: Driver - 最复杂的 trait，它的目标是提供一种简便的方式在 UI 层编写响应式代码
        //准确来说 Driver 和 ControlEvent 应该算是 RxCocoa traits 因为他们主要是服务于 RxCocoa 工程的
        // https://www.hangge.com/blog/cache/detail_1942.html
        /*
         如果我们的序列满足如下特征(都是UI驱动的序列所具备的特征)，就可以使用它：
         不会产生 error 事件
         一定在主线程监听（MainScheduler）
         共享状态变化（shareReplayLatestWhileConnected）
         */
        // 为什么使用
        /*
         （1）Driver 最常使用的场景应该就是需要用序列来驱动应用程序的情况了，比如：
                 通过 CoreData 模型驱动 UI
                 使用一个 UI 元素值（绑定）来驱动另一个 UI 元素值
         （2）与普通的操作系统驱动程序一样，如果出现序列错误，应用程序将停止响应用户输入。
         （3）在主线程上观察到这些元素也是极其重要的，因为 UI 元素和应用程序逻辑通常不是线程安全的。
         （4）此外，使用构建 Driver 的可观察的序列，它是共享状态变化。
         */
        // 样例： 根据一个输入框的关键字，来请求数据，然后将获取到的结果绑定到另一个 Label 和 TableView 中。
        
        // 初学者使用 Observable 序列加 bindTo 绑定来实现这个功能的话可能会这么写：
        /*
         let results = query.rx.text
             .throttle(0.3, scheduler: MainScheduler.instance) //在主线程中操作，0.3秒内值若多次改变，取最后一次
             .flatMapLatest { query in //筛选出空值, 拍平序列
                 fetchAutoCompleteItems(query) //向服务器请求一组结果
         }
          
         //将返回的结果绑定到用于显示结果数量的label上
         results
             .map { "\($0.count)" }
             .bind(to: resultCount.rx.text)
             .disposed(by: disposeBag)
          
         //将返回的结果绑定到tableView上
         results
             .bind(to: resultsTableView.rx.items(cellIdentifier: "Cell")) { (_, result, cell) in
                 cell.textLabel?.text = "\(result)"
             }
             .disposed(by: disposeBag)
         */
//        但是以上代码存在如下 3 个问题：
//        如果 fetchAutoCompleteItems 的序列产生了一个错误（网络请求失败），这个错误将取消所有绑定。此后用户再输入一个新的关键字时，是无法发起新的网络请求。
//        如果 fetchAutoCompleteItems 在后台返回序列，那么刷新页面也会在后台进行，这样就会出现异常崩溃。
//        返回的结果被绑定到两个 UI 元素上。那就意味着，每次用户输入一个新的关键字时，就会分别为两个 UI 元素发起 HTTP 请求，这并不是我们想要的结果。
        
        // 以上代码修改后
        /*
         let results = query.rx.text
             .throttle(0.3, scheduler: MainScheduler.instance)//在主线程中操作，0.3秒内值若多次改变，取最后一次
             .flatMapLatest { query in //筛选出空值, 拍平序列
                 fetchAutoCompleteItems(query)   //向服务器请求一组结果
                     .observeOn(MainScheduler.instance)  //将返回结果切换到到主线程上
                     .catchErrorJustReturn([])       //错误被处理了，这样至少不会终止整个序列
             }
             .shareReplay(1)                //HTTP 请求是被共享的
          
         //将返回的结果绑定到显示结果数量的label上
         results
             .map { "\($0.count)" }
             .bind(to: resultCount.rx.text)
             .disposed(by: disposeBag)
          
         //将返回的结果绑定到tableView上
         results
             .bind(to: resultsTableView.rx.items(cellIdentifier: "Cell")) { (_, result, cell) in
                 cell.textLabel?.text = "\(result)"
             }
             .disposed(by: disposeBag)
         */
        // 虽然我们通过增加一些额外的处理，让程序可以正确运行。到对于一个大型的项目来说，如果都这么干也太麻烦了，而且容易遗漏出错。
        
//        使用 Driver 来实现的话就简单了，代码如下
        /*
         （1）首先我们使用 asDriver 方法将 ControlProperty 转换为 Driver。
         （2）接着我们可以用 .asDriver(onErrorJustReturn: []) 方法将任何 Observable 序列都转成 Driver，因为我们知道序列转换为 Driver 要他满足 3 个条件：
         不会产生 error 事件
         一定在主线程监听（MainScheduler）
         共享状态变化（shareReplayLatestWhileConnected）
         而 asDriver(onErrorJustReturn: []) 相当于以下代码：
                 let safeSequence = xs
                  .observeOn(MainScheduler.instance) // 主线程监听
                  .catchErrorJustReturn(onErrorJustReturn) // 无法产生错误
                  .share(replay: 1, scope: .whileConnected)// 共享状态变化
                  return Driver(raw: safeSequence) // 封装
         （3）同时在 Driver 中，框架已经默认帮我们加上了 shareReplayLatestWhileConnected，所以我们也没必要再加上"replay"相关的语句了。
         （4）最后记得使用 drive 而不是 bindTo
         
         let results = query.rx.text.asDriver()        // 将普通序列转换为 Driver
             .throttle(0.3, scheduler: MainScheduler.instance)
             .flatMapLatest { query in
                 fetchAutoCompleteItems(query)
                     .asDriver(onErrorJustReturn: [])  // 仅仅提供发生错误时的备选返回值
             }
          
         //将返回的结果绑定到显示结果数量的label上
         results
             .map { "\($0.count)" }
             .drive(resultCount.rx.text) // 这里使用 drive 而不是 bindTo
             .disposed(by: disposeBag)
          
         //将返回的结果绑定到tableView上
         results
             .drive(resultsTableView.rx.items(cellIdentifier: "Cell")) { //  同样使用 drive 而不是 bindTo
                 (_, result, cell) in
                 cell.textLabel?.text = "\(result)"
             }
             .disposed(by: disposeBag)
         */
        
        // 由于 drive 方法只能被 Driver 调用。这意味着，如果代码存在 drive，那么这个序列不会产生错误事件并且一定在主线程监听。这样我们就可以安全的绑定 UI 元素。
        
        
        // MARK: - Signal 和 Driver 相似，唯一的区别是，Driver 会对新观察者回放（重新发送）上一个元素，而 Signal 不会对新观察者回放上一个元素。
        // https://beeth0ven.github.io/RxSwift-Chinese-Documentation/content/rxswift_core/observable/signal.html
        // 不会产生 error 事件
        // 一定在 MainScheduler 监听（主线程监听）
        // 共享附加作用
        
        
        //MARK:  ControlEvent ControlEvent 专门用于描述 UI 控件所产生的事件，它具有以下特征：
        // 不会产生 error 事件
        // 一定在 MainScheduler 订阅（主线程订阅）
        // 一定在 MainScheduler 监听（主线程监听）
        // 共享附加作用
        
    // MARK: -  RxSwift 调度器、subscribeOn、observeOn
       
       // MARK: 调度器
       
       // 调度器（Schedulers）是 RxSwift 实现多线程的核心模块，它主要用于控制任务在哪个线程或队列运行
       // 内置了如下几种的Schedulers
       // CurrentThreadScheduler：表示当前线程 Scheduler。（默认使用这个）
       // MainScheduler：表示主线程。如果我们需要执行一些和 UI 相关的任务，就需要切换到该 Scheduler 运行。
       // SerialDispatchQueueScheduler：封装了 GCD 的串行队列。如果我们需要执行一些串行任务，可以切换到这个 Scheduler 运行。
       // ConcurrentDispatchQueueScheduler：封装了 GCD 的并行队列。如果我们需要执行一些并发任务，可以切换到这个 Scheduler 运行。
       // OperationQueueScheduler：封装了 NSOperationQueue。
       
       // 以网络请求数据并展示为例：后台发起网络请求，然后解析数据，最后在主线程刷新页面。
       
       // GCD 的实现逻辑如下：
        // 后台获取数据
//        DispatchQueue.global(qos: .userInitiated).async {
////            let data = try? Data(contentsOf: "")
//
//            // 主线程更新UI
//            DispatchQueue.main.async {
//
//            }
//        }
        
        // RXSwift 来实现：
//        let rxData: Observable<Data> = ...
//
//        rxData
//            .subscribeOn(ConcurrentDispatchQueueScheduler(qos: .userInitiated)) //后台构建序列
//            .observeOn(MainScheduler.instance)  //主线程监听并处理序列结果
//            .subscribe(onNext: { [weak self] data in
//                self?.data = data
//            })
//            .disposed(by: disposeBag)
        
        
        // MARK: subscribeOn 和 observeOn 区别
        
        // subscribeOn 决定序列函数在哪个 Schedulers 上运行 (由于获取数据、解析数据需要花费一段时间的时间，所以通过 subscribeOn 将其切换到后台 Scheduler 来执行。这样可以避免主线程被阻塞)
        // observeOn 决定在哪个 Schedulers 监听序列(比如获取并解析完毕数据后又通过 observeOn 方法切换到主线程来监听并且处理结果)
        
        
        
        // MARK : 共享附加作用
//        共享 附加作用：
//        Driver
//        Signal
//        ControlEvent
//        ...
//        不共享 附加作用：
//
//        Single
//        Completable
//        Maybe
//        ...
        
        // 共享 附加作用：
//        let observable: Observable<Teacher> = API.teacher(teacherId: 1)
//        let shareSideEffects: Driver<Teacher> = observable.asDriver(onErrorDriveWith: .empty())
//
//        let observer0: (Teacher) -> () = ...
//        let observer1: (Teacher) -> () = ...
//
//        shareSideEffects.drive(onNext: observer0)
//        shareSideEffects.drive(onNext: observer1) // 第二次订阅
//        如果一个序列共享 附加作用，那在第二次订阅时，不会重新发起网络请求，而是共享第一次网络请求（附加作用）。
  
//        不共享 附加作用：
//        let observable: Observable<Teacher> = API.teacher(teacherId: 1)
//        let notShareSideEffects: Single<Teacher> = observable.asSingle()
//
//        let observer0: (Teacher) -> () = ...
//        let observer1: (Teacher) -> () = ...
//
//        notShareSideEffects.subscribe(onSuccess: observer0)
//        notShareSideEffects.subscribe(onSuccess: observer1) // 第二次订阅
//        如果一个序列不共享 附加作用，那在第二次订阅时，会重新发起网络请求，而不是共享第一次网络请求（附加作用）。
//
//        因此我们需要注意，如果一个网络请求序列，他不共享 附加作用，那每一次订阅时就会单独发起网络请求。这时最好改用 共享 附加作用 的序列，或者使用 share 操作符。
        
    }
    
//    public func delay(_ delay: Double, closure: @escaping () -> Void) {
//        DispatchQueue.main.asyncAfter(deadline: .now() + delay) {
//            closure()
//        }
//    }
    
    deinit {
//        print("当前页面销毁:RX 计数 \(RxSwift.Resources.total)")
    }
}

