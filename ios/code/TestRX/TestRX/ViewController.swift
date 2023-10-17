//
//  ViewController.swift
//  TestRX
//
//  Created by WTW on 2020/7/28.
//  Copyright © 2020 Mac. All rights reserved.
//

/*
  RxDataSources 资源：
    https://www.hangge.com/blog/cache/detail_1982.html
 */

import UIKit
import RxSwift
import RxCocoa

class Person {
    
    var name: String = ""
    var age: Int = 0
}

class ViewController: UIViewController {

    var tableView: UITableView!
    
    var disposeBag: DisposeBag = DisposeBag()
    
    let dataSource = ["Moya demo1",
                      "传统MVVM",
                      "Swift Sequence",
                      "Rx改造的MVVM",
                      "Rx常见操作",
                      "CollectionView基本使用1",
                      "Collection刷新使用",
                      "tableView的基本使用",
                      "tableview 种不同的类型的cell",
                      "测试基础控件",
                      "DemoListView Moya"
    ]
    
    override func viewDidLoad() {
        super.viewDidLoad()
       
        let person = Person()
        person.name = "name"
        person.age = 10
        
//        Observable.just(person).subscribe { element in
//            print(element)
//        }.disposed(by: disposeBag)

        /// 产生序列
//        Observable.just(<#T##element: _##_#>)
//        Observable.of(<#T##elements: _...##_#>)
//        Observable.from(<#T##array: [_]##[_]#>)
//        Observable.empty()
//        Observable.never()
//        Observable.error(<#T##error: Error##Error#>)
//        Observable.range(start: <#T##_#>, count: <#T##_#>)
//        Observable.repeatElement(<#T##element: _##_#>)
//        Observable.generate(initialState: <#T##_#>, condition: <#T##(_) throws -> Bool#>, iterate: <#T##(_) throws -> _#>)
//        Observable.create(<#T##subscribe: (AnyObserver<_>) -> Disposable##(AnyObserver<_>) -> Disposable#>)
//        Observable.deferred(<#T##observableFactory: () throws -> Observable<_>##() throws -> Observable<_>#>)
//        Observable.interval(<#T##period: RxTimeInterval##RxTimeInterval#>, scheduler: <#T##SchedulerType#>)
//        Observable.timer(<#T##dueTime: RxTimeInterval##RxTimeInterval#>, period: <#T##RxTimeInterval?#>, scheduler: <#T##SchedulerType#>)
        
        /// 订阅序列
//        Observable.just(1).subscribe(onNext: <#T##((Int) -> Void)?##((Int) -> Void)?##(Int) -> Void#>, onError: <#T##((Error) -> Void)?##((Error) -> Void)?##(Error) -> Void#>, onCompleted: <#T##(() -> Void)?##(() -> Void)?##() -> Void#>, onDisposed: <#T##(() -> Void)?##(() -> Void)?##() -> Void#>)
//        Observable.just(1).subscribe(<#T##on: (Event<Int>) -> Void##(Event<Int>) -> Void#>)
//        Observable.just(1).do(onNext: <#T##((Double) throws -> Void)?##((Double) throws -> Void)?##(Double) throws -> Void#>, afterNext: <#T##((Double) throws -> Void)?##((Double) throws -> Void)?##(Double) throws -> Void#>, onError: <#T##((Error) throws -> Void)?##((Error) throws -> Void)?##(Error) throws -> Void#>, afterError: <#T##((Error) throws -> Void)?##((Error) throws -> Void)?##(Error) throws -> Void#>, onCompleted: <#T##(() throws -> Void)?##(() throws -> Void)?##() throws -> Void#>, afterCompleted: <#T##(() throws -> Void)?##(() throws -> Void)?##() throws -> Void#>, onSubscribe: <#T##(() -> Void)?##(() -> Void)?##() -> Void#>, onSubscribed: <#T##(() -> Void)?##(() -> Void)?##() -> Void#>, onDispose: <#T##(() -> Void)?##(() -> Void)?##() -> Void#>)
        
        /// 取消订阅 dispose
//        Observable.just(1).subscribe(<#T##observer: ObserverType##ObserverType#>).dispose()
        
        /// 观察者 Observer
//        Observable.just(1).subscribe(<#T##observer: ObserverType##ObserverType#>)
//        Observable.just(1).bindTo(<#T##observer: ObserverType##ObserverType#>)
        
        /// AnyObserver  创建观察者
//        let observer: AnyObserver<String> =  AnyObserver{ (event) in
//            switch event {
//            case .next(let data):
//                print(data)
//            case .error(let error):
//                print(error)
//            case .completed:
//                print("completed")
//            }
//        }
//        Observable.just("hello").subscribe(observer).disposed(by: disposeBag)
//        Observable.just("hello").bind(to: observer).disposed(by: disposeBag)
        
        /// Binder 创建观察者
        /// 不处理错误事件
        /// 绑定在 给定的 Scheduler
//        Binder(self,MainScheduler.instance,(){
//
//        })
            
        /// RxSwift 自带的可绑定属性
//        self.view.rx.backgroundColor
//        self.view.rx.alpha
        
        /// debug 调试
//        Observable.just(1).debug("debug 标识 ==").subscribe {print($0)}.disposed(by: disposeBag)

//        Observable.just(1).filter(<#T##predicate: (Int) throws -> Bool##(Int) throws -> Bool#>)
//        Observable.just(1).distinctUntilChanged() /// 连续去重
//        Observable.just('1').single()   /// 只发一次
//        Observable.just(1).elementAt(<#T##index: Int##Int#>)  /// 只处理指定位置
//        Observable.just(1).ignoreElements()  /// 忽略所有元素 只关心结果
//        Observable.just(1).take(<#T##count: Int##Int#>)  /// 只发送前几个
//        Observable.just(1).takeLast(<#T##count: Int##Int#>)  /// 只发送后几个
//        Observable.just(1).skip(<#T##Int#>) /// 跳过前几个
//        Observable.just(1).skipUntil(<#T##other: ObservableType##ObservableType#>)
//        Observable.just(1).debounce(<#T##dueTime: RxTimeInterval##RxTimeInterval#>, scheduler: <#T##SchedulerType#>)
//        Observable.just(1).map(<#T##(Element) -> Result#>)
//        Observable.just(1).flatMap(<#T##selector: (Double) throws -> ObservableConvertibleType##(Double) throws -> ObservableConvertibleType#>)
//        Observable.just(1).flatMapFirst(<#T##(Element) -> Source#>)
//        Observable.just(1).flatMapLatest(<#T##(Element) -> Source#>)
//        Observable.just(1).concatMap(<#T##selector: (Int) throws -> ObservableConvertibleType##(Int) throws -> ObservableConvertibleType#>)
//        Observable.just(1).groupBy(keySelector: <#T##(Element) -> Key#>)
//        Observable.just(1).amb(<#T##right: ObservableType##ObservableType#>) /// 多个序列只处理第一个，其他丢弃
//        Observable.just(1).takeWhile(<#T##(Element) -> Bool#>)  /// 根据条件发送
//        Observable.just(1).takeUntil(<#T##other: ObservableType##ObservableType#>)
//        Observable.just(1).skipWhile(<#T##predicate: (Int) throws -> Bool##(Int) throws -> Bool#>)
//        Observable.of(<#T##Element#>).merge
        
        /// Subjects / Observable
        /// Observable 是数据都准备好了
        /// Subjects 可以动态接收输数据
        /// 既是订阅者，也是被订阅者
        /// PublishSubject / BehaviorSubject / ReplaySubject / Variable
        /// 都是 Observable ,订阅者都能收到他们发出的新的 Event
        /// 区别：新的订阅者刚订阅它的时候，能不能收到 Subject 以前发出过的旧 Event，如果能的话又能收到多少个
        /// PublishSubject 收不到以前的
        /// BehaviorSubject 一个默认值创建 ，立马收到上一个 event
        /// ReplaySubject bufferSize 需要设置一个缓存，新订阅者订阅的时候能收到前面的的缓存个数个event
        /// Variable(已废弃)  BehaviorSubject 的封装
        /// BehaviorRelay Variable 的替代品
        
        
        /// 特征序列  Single、Completable、Maybe、Driver、ControlEvent
        /// Single 只发出一个元素, 它要么只能发出一个元素，要么产生一个 error 事件
        /// Maybe 要么产生一个 completed 事件，要么产生一个 error 事件
        /// Driver
        
        
        view.rx.alpha
        
        tableView = UITableView(frame: view.bounds, style: .plain)
        tableView.register(UITableViewCell.self, forCellReuseIdentifier: "CellID")
        tableView.delegate = self
        tableView.dataSource = self
        self.view.addSubview(tableView)
        
    }
}

extension ViewController : UITableViewDataSource {
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return dataSource.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        
        let cell = tableView.dequeueReusableCell(withIdentifier: "CellID")!
        cell.textLabel?.text = self.dataSource[indexPath.row]
        return cell
    }
}

extension ViewController : UITableViewDelegate {
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        
        switch indexPath.row {
        case 0:
            self.navigationController?.pushViewController(MoyaDemo1ViewController(), animated: true)
        case 1:
            self.navigationController?.pushViewController(TraditionViewController(), animated: true)
//        case 2:
//            self.navigationController?.pushViewController(SequenceTestController(), animated: true)
        case 3:
            self.navigationController?.pushViewController(RxViewController(), animated: true)
//        case 4:
//            self.navigationController?.pushViewController(RxSwiftDemo1Controller(), animated: true)
        case 5:
            self.navigationController?.pushViewController(CollectionViewControllerDemo1(), animated: true)
        case 6:
            self.navigationController?.pushViewController(CollectionRefreshViewController(), animated: true)
//        case 7:
//            self.navigationController?.pushViewController(SingleTableViewController(), animated: true)
//        case 8:
//            self.navigationController?.pushViewController(MultipleTableViewController(), animated: true)
        case 9:
            self.navigationController?.pushViewController(DemoListViewController(), animated: true)
        case 10:
            self.navigationController?.pushViewController(TestBaseWidgetController(), animated: true)
        default:
            self.navigationController?.pushViewController(MoyaDemo1ViewController(), animated: true)
        }
        
    }
}
