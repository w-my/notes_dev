# RxSwift - MJRefresh



## 下拉刷新

#### 对 MJRefresh 进行扩展

为了让 `MJRefresh` 可以更好地与 `RxSwift` 配合使用，这里对它进行扩展（`MJRefresh+Rx.swift`），内容如下：

- 将下拉、上拉的刷新事件转为 `ControlEvent` 类型的可观察序列。
- 增加一个用于停止刷新的绑定属性。

```swift
import RxSwift
import RxCocoa
 
// 对MJRefreshComponent增加rx扩展
extension Reactive where Base: MJRefreshComponent {
     
    // 正在刷新事件
    var refreshing: ControlEvent<Void> {
        let source: Observable<Void> = Observable.create {
            [weak control = self.base] observer  in
            if let control = control {
                control.refreshingBlock = {
                    observer.on(.next(()))
                }
            }
            return Disposables.create()
        }
        return ControlEvent(events: source)
    }
     
    // 停止刷新
    var endRefreshing: Binder<Bool> {
        return Binder(base) { refresh, isEnd in
            if isEnd {
                refresh.endRefreshing()
            }
        }
    }
}
```

#### 网络请求服务

这里专门封装了一个网络请求服务层（`NetworkService.swift`），作用是当表格发生上拉、或下拉时，通过它获取数据。为了方便演示，这里没有真正去发起网络请求，而是随机生成 **15** 条数据，并延迟 **1** 秒返回。

```swift
import RxSwift
import RxCocoa

// 网络请求服务
class NetworkService {
     
    // 获取随机数据
    func getRandomResult() -> Driver<[String]> {
        print("正在请求数据......")
        let items = (0 ..< 15).map {_ in
            "随机数据\(Int(arc4random()))"
        }
        let observable = Observable.just(items)
        return observable
            .delay(1, scheduler: MainScheduler.instance)
            .asDriver(onErrorDriveWith: Driver.empty())
     }
}
```



## 下拉刷新的样例

###### `ViewModel.swift`

主要是根据下拉刷新事件序列去查询数据，同时数据返回后除了生成表格数据序列外，还有个停止刷新状态的序列。

```swift
import RxSwift
import RxCocoa
 
class ViewModel {
     
    // 表格数据序列
    let tableData:Driver<[String]>
     
    // 停止刷新状态序列
    let endHeaderRefreshing: Driver<Bool>
     
    // ViewModel初始化（根据输入实现对应的输出）
    init(headerRefresh: Driver<Void>) {
         
        // 网络请求服务
        let networkService = NetworkService()
         
        // 生成查询结果序列
        self.tableData = headerRefresh
            .startWith(()) // 初始化完毕时会自动加载一次数据
            .flatMapLatest{ _ in networkService.getRandomResult() }
         
        // 生成停止刷新状态序列
        self.endHeaderRefreshing = self.tableData.map{ _ in true }
    }
}
```

###### `ViewController.swift`
`ViewModel` 初始化后，将表格数据序列绑定到 `tableView` 上显示数据，同时将停止刷新序列绑定到 `tableView` 的 `mj_header` 上让其自动停止刷新。

```swift
import UIKit
import RxSwift
import RxCocoa
 
class ViewController: UIViewController {
     
    var tableView:UITableView!
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
        super.viewDidLoad()
         
        // 创建表格视图
        self.tableView = UITableView(frame: self.view.frame, style:.plain)
        // 创建一个重用的单元格
        self.tableView!.register(UITableViewCell.self,
                                 forCellReuseIdentifier: "Cell")
        self.view.addSubview(self.tableView!)
         
        // 设置头部刷新控件
        self.tableView.mj_header = MJRefreshNormalHeader()
         
        // 初始化ViewModel
        let viewModel = ViewModel(headerRefresh:
            self.tableView.mj_header.rx.refreshing.asDriver())
         
        // 单元格数据的绑定
        viewModel.tableData.asDriver()
            .drive(tableView.rx.items) { (tableView, row, element) in
                let cell = tableView.dequeueReusableCell(withIdentifier: "Cell")!
                cell.textLabel?.text = "\(row+1)、\(element)"
                return cell
            }
            .disposed(by: disposeBag)
         
        // 下拉刷新状态结束的绑定
        viewModel.endHeaderRefreshing
            .drive(self.tableView.mj_header.rx.endRefreshing)
            .disposed(by: disposeBag)
    }
}
```



## 上拉加载的样例

###### `ViewModel.swift`

由于“**加载更多**”功能需要把新数据添加到老数据尾部，这里我使用 `BehaviorRelay` 作为表格数据序列，因为它可以获取到之前的数据。

```swift
import RxSwift
import RxCocoa
 
class ViewModel {
     
    // 表格数据序列
    let tableData = BehaviorRelay<[String]>(value: [])
     
    // 停止上拉加载刷新状态序列
    let endFooterRefreshing: Driver<Bool>
     
    // ViewModel初始化（根据输入实现对应的输出）
    init(footerRefresh: Driver<Void>,
         dependency: (
            disposeBag:DisposeBag,
            networkService: NetworkService )) {
         
        // 上拉结果序列
        let footerRefreshData = footerRefresh
            .startWith(()) // 初始化完毕时会自动加载一次数据
            .flatMapLatest{ return dependency.networkService.getRandomResult() }
         
        // 生成停止上拉加载刷新状态序列
        self.endFooterRefreshing = footerRefreshData.map{ _ in true }
         
        // 上拉加载时，将查询到的结果拼接到原数据底部
        footerRefreshData.drive(onNext: { items in
            self.tableData.accept(self.tableData.value + items )
        }).disposed(by: dependency.disposeBag)
    }
}
```

###### `ViewController.swift`

`ViewModel` 初始化后，将表格数据序列绑定到 `tableView`上显示数据。同时将停止刷新序列绑定到 `tableView` 的 `mj_footer` 上让其自动停止刷新。

```swift
import UIKit
import RxSwift
import RxCocoa
 
class ViewController: UIViewController {
     
    var tableView:UITableView!
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
        super.viewDidLoad()
         
        // 创建表格视图
        self.tableView = UITableView(frame: self.view.frame, style:.plain)
        // 创建一个重用的单元格
        self.tableView!.register(UITableViewCell.self,
                                 forCellReuseIdentifier: "Cell")
        self.view.addSubview(self.tableView!)
         
        // 设置尾部刷新控件
        self.tableView.mj_footer = MJRefreshBackNormalFooter()
         
        // 初始化ViewModel
        let viewModel = ViewModel(
            footerRefresh: self.tableView.mj_footer.rx.refreshing.asDriver(),
            dependency: (
                disposeBag: self.disposeBag,
                networkService: NetworkService()))
         
        // 单元格数据的绑定
        viewModel.tableData.asDriver()
            .drive(tableView.rx.items) { (tableView, row, element) in
                let cell = tableView.dequeueReusableCell(withIdentifier: "Cell")!
                cell.textLabel?.text = "\(row+1)、\(element)"
                return cell
            }
            .disposed(by: disposeBag)
         
        // 上拉刷新状态结束的绑定
        viewModel.endFooterRefreshing
            .drive(self.tableView.mj_footer.rx.endRefreshing)
            .disposed(by: disposeBag)
    }
}
```



## 下拉刷新 + 上拉加载的样例

###### `ViewModel.swift`

这里同样使用 `BehaviorRelay` 作为表格数据序列，同时还定义了两个停止刷新序列（分别表示停止下拉刷新、停止上拉刷新）。

```swift
import RxSwift
import RxCocoa
 
class ViewModel {
     
    // 表格数据序列
    let tableData = BehaviorRelay<[String]>(value: [])
     
    // 停止头部刷新状态
    let endHeaderRefreshing: Driver<Bool>
     
    // 停止尾部刷新状态
    let endFooterRefreshing: Driver<Bool>
     
    // ViewModel初始化（根据输入实现对应的输出）
    init(input: (
            headerRefresh: Driver<Void>,
            footerRefresh: Driver<Void> ),
         dependency: (
            disposeBag:DisposeBag,
            networkService: NetworkService )) {
         
        // 下拉结果序列
        let headerRefreshData = input.headerRefresh
            .startWith(()) // 初始化时会先自动加载一次数据
            .flatMapLatest{ return dependency.networkService.getRandomResult() }
         
        // 上拉结果序列
        let footerRefreshData = input.footerRefresh
            .flatMapLatest{ return dependency.networkService.getRandomResult() }
         
        // 生成停止头部刷新状态序列
        self.endHeaderRefreshing = headerRefreshData.map{ _ in true }
         
        // 生成停止尾部刷新状态序列
        self.endFooterRefreshing = footerRefreshData.map{ _ in true }
         
        // 下拉刷新时，直接将查询到的结果替换原数据
        headerRefreshData.drive(onNext: { items in
            self.tableData.accept(items)
        }).disposed(by: dependency.disposeBag)
         
        // 上拉加载时，将查询到的结果拼接到原数据底部
        footerRefreshData.drive(onNext: { items in
            self.tableData.accept(self.tableData.value + items )
        }).disposed(by: dependency.disposeBag)
    }
}
```

###### `ViewController.swift`

`ViewModel` 初始化后，将表格数据序列绑定到 `tableView`上显示数据。同时将两个停止刷新序列分别绑定到 `tableView` 的 `mj_header` 和 `mj_footer` 上让其自动停止刷新。

```swift
import UIKit
import RxSwift
import RxCocoa
 
class ViewController: UIViewController {
     
    //表格
    var tableView:UITableView!
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
        super.viewDidLoad()
         
        // 创建表格视图
        self.tableView = UITableView(frame: self.view.frame, style:.plain)
        // 创建一个重用的单元格
        self.tableView!.register(UITableViewCell.self,
                                 forCellReuseIdentifier: "Cell")
        self.view.addSubview(self.tableView!)
         
        // 设置头部刷新控件
        self.tableView.mj_header = MJRefreshNormalHeader()
        // 设置尾部刷新控件
        self.tableView.mj_footer = MJRefreshBackNormalFooter()
         
        // 初始化ViewModel
        let viewModel = ViewModel(
            input: (
                headerRefresh: self.tableView.mj_header.rx.refreshing.asDriver(),
                footerRefresh: self.tableView.mj_footer.rx.refreshing.asDriver()),
            dependency: (
                disposeBag: self.disposeBag,
                networkService: NetworkService()))
         
        // 单元格数据的绑定
        viewModel.tableData.asDriver()
            .drive(tableView.rx.items) { (tableView, row, element) in
                let cell = tableView.dequeueReusableCell(withIdentifier: "Cell")!
                cell.textLabel?.text = "\(row+1)、\(element)"
                return cell
            }
            .disposed(by: disposeBag)
         
        // 下拉刷新状态结束的绑定
        viewModel.endHeaderRefreshing
            .drive(self.tableView.mj_header.rx.endRefreshing)
            .disposed(by: disposeBag)
         
        // 上拉刷新状态结束的绑定
        viewModel.endFooterRefreshing
            .drive(self.tableView.mj_footer.rx.endRefreshing)
            .disposed(by: disposeBag)
    }
}
```



## “下拉刷新 + 上拉加载”的功能改进

#### 功能说明

在前面的样例中下拉刷新和上拉加载这两个行为是独立的，互不影响。也就是说当我们下拉刷新后，在数据返回前又进行了次上拉操作，那么之后表格便会连续刷新两次，影响体验。这里对功能做个改进：

- 当下拉刷新时，如果数据还未返回。这时进行上拉加载会取消前面的下拉刷新操作（包括下拉刷新的数据），只进行上拉数据的加载。
- 同样的，当上拉加载时，如果数据还未放回。这时进行下拉刷新会取消上拉加载操作（包括上拉加载的数据），只进行下拉数据的加载。

同时这次不使用 `Driver` 这个特征序列，而是用普通的 `Observable` 序列。

#### 样例代码

###### `NetworkService.swift`

```swift
import RxSwift
import RxCocoa
 
// 网络请求服务
class NetworkService {
     
    // 获取随机数据
    func getRandomResult() -> Observable<[String]> {
        print("正在请求数据......")
        let items = (0 ..< 15).map {_ in
            "随机数据\(Int(arc4random()))"
        }
        let observable = Observable.just(items)
        return observable
            .delay(2, scheduler: MainScheduler.instance)
    }
}
```

###### `ViewModel.swift`

```swift
import RxSwift
import RxCocoa
 
class ViewModel {
     
    // 表格数据序列
    let tableData = BehaviorRelay<[String]>(value: [])
     
    // 停止头部刷新状态
    let endHeaderRefreshing: Observable<Bool>
     
    // 停止尾部刷新状态
    let endFooterRefreshing: Observable<Bool>
     
    // ViewModel初始化（根据输入实现对应的输出）
    init(input: (
            headerRefresh: Observable<Void>,
            footerRefresh: Observable<Void> ),
         dependency: (
            disposeBag:DisposeBag,
            networkService: NetworkService )) {
         
        // 下拉结果序列
        let headerRefreshData = input.headerRefresh
            .startWith(()) // 初始化时会先自动加载一次数据
            .flatMapLatest{ _ in
                dependency.networkService.getRandomResult()
                    .takeUntil(input.footerRefresh)
            }.share(replay: 1) // 让HTTP请求是被共享的
         
         
        // 上拉结果序列
        let footerRefreshData = input.footerRefresh
            .flatMapLatest{ _ in
                dependency.networkService.getRandomResult()
                    .takeUntil(input.headerRefresh)
            }.share(replay: 1) // 让HTTP请求是被共享的
         
        // 生成停止头部刷新状态序列
        self.endHeaderRefreshing = Observable.merge(
            headerRefreshData.map{ _ in true },
            input.footerRefresh.map{ _ in true }
        )
         
        // 生成停止尾部刷新状态序列
        self.endFooterRefreshing = Observable.merge(
            footerRefreshData.map{ _ in true },
            input.headerRefresh.map{ _ in true }
         )
         
        // 下拉刷新时，直接将查询到的结果替换原数据
        headerRefreshData.subscribe(onNext: { items in
            self.tableData.accept(items)
        }).disposed(by: dependency.disposeBag)
         
        // 上拉加载时，将查询到的结果拼接到原数据底部
        footerRefreshData.subscribe(onNext: { items in
            self.tableData.accept(self.tableData.value + items )
        }).disposed(by: dependency.disposeBag)
    }
}
```

###### `ViewController.swift`

```swift
import UIKit
import RxSwift
import RxCocoa
 
class ViewController: UIViewController {
     
    var tableView:UITableView!
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
        super.viewDidLoad()
         
        // 创建表格视图
        self.tableView = UITableView(frame: self.view.frame, style:.plain)
        // 创建一个重用的单元格
        self.tableView!.register(UITableViewCell.self,
                                 forCellReuseIdentifier: "Cell")
        self.view.addSubview(self.tableView!)
         
        // 设置头部刷新控件
        self.tableView.mj_header = MJRefreshNormalHeader()
        // 设置尾部刷新控件
        self.tableView.mj_footer = MJRefreshBackNormalFooter()
         
        // 初始化ViewModel
        let viewModel = ViewModel(
            input: (
                headerRefresh: self.tableView.mj_header.rx.refreshing.asObservable() ,
                footerRefresh: self.tableView.mj_footer.rx.refreshing.asObservable()),
            dependency: (
                disposeBag: self.disposeBag,
                networkService: NetworkService()))
         
        // 单元格数据的绑定
        viewModel.tableData
            .bind(to: tableView.rx.items) { (tableView, row, element) in
                let cell = tableView.dequeueReusableCell(withIdentifier: "Cell")!
                cell.textLabel?.text = "\(row+1)、\(element)"
                return cell
            }
            .disposed(by: disposeBag)
         
        // 下拉刷新状态结束的绑定
        viewModel.endHeaderRefreshing
            .bind(to: self.tableView.mj_header.rx.endRefreshing)
            .disposed(by: disposeBag)
         
        // 上拉刷新状态结束的绑定
        viewModel.endFooterRefreshing
            .bind(to: self.tableView.mj_footer.rx.endRefreshing)
            .disposed(by: disposeBag)
    }
}
```

