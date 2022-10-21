# RxSwift - UITableView



## UITableView 的基本用法

#### 单个分区的表格

```swift
import UIKit
import RxSwift
import RxCocoa
 
class ViewController: UIViewController {
     
    var tableView: UITableView!
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
        super.viewDidLoad()
         
        self.tableView = UITableView(frame: self.view.frame, style:.plain)
        self.tableView!.register(UITableViewCell.self, forCellReuseIdentifier: "Cell")
        self.view.addSubview(self.tableView!)
         
        let items = Observable.just([
            "文本输入框的用法",
            "开关按钮的用法",
            "进度条的用法",
            "文本标签的用法",
        ])
         
        items
            .bind(to: tableView.rx.items) { (tableView, row, element) in
                let cell = tableView.dequeueReusableCell(withIdentifier: "Cell")!
                cell.textLabel?.text = "\(row)：\(element)"
                return cell
            }
            .disposed(by: disposeBag)
    }
}
```



#### 单元格选中事件响应

```swift
// 获取选中项的索引
tableView.rx.itemSelected.subscribe(onNext: { indexPath in
    print("选中项的indexPath为：\(indexPath)")
}).disposed(by: disposeBag)
 
// 获取选中项的内容
tableView.rx.modelSelected(String.self).subscribe(onNext: { item in
    print("选中项的标题为：\(item)")
}).disposed(by: disposeBag)
```



#### 单元格取消选中事件响应

```swift
// 获取被取消选中项的索引
tableView.rx.itemDeselected.subscribe(onNext: { [weak self] indexPath in
    self?.showMessage("被取消选中项的indexPath为：\(indexPath)")
}).disposed(by: disposeBag)
 
// 获取被取消选中项的内容
tableView.rx.modelDeselected(String.self).subscribe(onNext: {[weak self] item in
    self?.showMessage("被取消选中项的的标题为：\(item)")
}).disposed(by: disposeBag)
```



#### 单元格删除事件响应

```swift
// 获取删除项的索引
tableView.rx.itemDeleted.subscribe(onNext: { [weak self] indexPath in
    self?.showMessage("删除项的indexPath为：\(indexPath)")
}).disposed(by: disposeBag)
 
// 获取删除项的内容
tableView.rx.modelDeleted(String.self).subscribe(onNext: {[weak self] item in
    self?.showMessage("删除项的的标题为：\(item)")
}).disposed(by: disposeBag)
```



#### 单元格移动事件响应

```objectivec
// 获取移动项的索引
tableView.rx.itemMoved.subscribe(onNext: { [weak self]
    sourceIndexPath, destinationIndexPath in
    self?.showMessage("移动项原来的indexPath为：\(sourceIndexPath)")
    self?.showMessage("移动项现在的indexPath为：\(destinationIndexPath)")
}).disposed(by: disposeBag)
```



#### 单元格插入事件响应

```objectivec
// 获取插入项的索引
tableView.rx.itemInserted.subscribe(onNext: { [weak self] indexPath in
    self?.showMessage("插入项的indexPath为：\(indexPath)")
}).disposed(by: disposeBag)
```



#### 单元格尾部附件（图标）点击事件响应

```objectivec
// 获取点击的尾部图标的索引
tableView.rx.itemAccessoryButtonTapped.subscribe(onNext: { [weak self] indexPath in
    self?.showMessage("尾部项的indexPath为：\(indexPath)")
}).disposed(by: disposeBag)
```



## [RxDataSources](https://github.com/RxSwiftCommunity/RxDataSources)

#### RxDataSources 介绍

（1）如果我们的 `tableview` 需要显示多个 `section`、或者更加复杂的编辑功能时，可以借助 `RxDataSource` 这个第三方库帮我们完成。

（2）`RxDataSource` 的本质就是使用 `RxSwift` 对 `UITableView` 和 `UICollectionView` 的数据源做了一层包装。



#### 单分区的 TableView

- **方式一：使用自带的Section**

```swift
import UIKit
import RxSwift
import RxCocoa
import RxDataSources
 
class ViewController: UIViewController {
     
    var tableView:UITableView!
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
        super.viewDidLoad()
         
        // 创建表格视图
        self.tableView = UITableView(frame: self.view.frame, style:.plain)
        // 创建一个重用的单元格
        self.tableView!.register(UITableViewCell.self, forCellReuseIdentifier: "Cell")
        self.view.addSubview(self.tableView!)
         
        // 初始化数据
        let items = Observable.just([
            SectionModel(model: "", items: [
                "UILable的用法",
                "UIText的用法",
                "UIButton的用法"
                ])
            ])
         
        // 创建数据源
        let dataSource = RxTableViewSectionedReloadDataSource
            <SectionModel<String, String>>(configureCell: {
                (dataSource, tv, indexPath, element) in
                let cell = tv.dequeueReusableCell(withIdentifier: "Cell")!
                cell.textLabel?.text = "\(indexPath.row)：\(element)"
                return cell
            })
         
        // 绑定单元格数据
        items
            .bind(to: tableView.rx.items(dataSource: dataSource))
            .disposed(by: disposeBag)
    }
}
```

- **方式二：使用自定义的Section**

```swift
import UIKit
import RxSwift
import RxCocoa
import RxDataSources
 
class ViewController: UIViewController {
     
    var tableView:UITableView!
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
        super.viewDidLoad()
         
        // 创建表格视图
        self.tableView = UITableView(frame: self.view.frame, style:.plain)
        // 创建一个重用的单元格
        self.tableView!.register(UITableViewCell.self, forCellReuseIdentifier: "Cell")
        self.view.addSubview(self.tableView!)
         
        // 初始化数据
        let sections = Observable.just([
            MySection(header: "", items: [
                "UILable的用法",
                "UIText的用法",
                "UIButton的用法"
                ])
            ])
         
        // 创建数据源
        let dataSource = RxTableViewSectionedAnimatedDataSource<MySection>(
            //设置单元格
            configureCell: { ds, tv, ip, item in
                let cell = tv.dequeueReusableCell(withIdentifier: "Cell")
                    ?? UITableViewCell(style: .default, reuseIdentifier: "Cell")
                cell.textLabel?.text = "\(ip.row)：\(item)"
                 
                return cell
        })
         
        // 绑定单元格数据
        sections
            .bind(to: tableView.rx.items(dataSource: dataSource))
            .disposed(by: disposeBag)
    }
}
 
// 自定义Section
struct MySection {
    var header: String
    var items: [Item]
}
 
extension MySection : AnimatableSectionModelType {
    typealias Item = String
     
    var identity: String {
        return header
    }
     
    init(original: MySection, items: [Item]) {
        self = original
        self.items = items
    }
}
```



#### 多分区的 TableView

- **方式一：使用自带的Section**

```swift
import UIKit
import RxSwift
import RxCocoa
import RxDataSources
 
class ViewController: UIViewController {
     
    var tableView:UITableView!
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
        super.viewDidLoad()
         
        // 创建表格视图
        self.tableView = UITableView(frame: self.view.frame, style:.plain)
        // 创建一个重用的单元格
        self.tableView!.register(UITableViewCell.self, forCellReuseIdentifier: "Cell")
        self.view.addSubview(self.tableView!)
         
        // 初始化数据
        let items = Observable.just([
            SectionModel(model: "基本控件", items: [
                "UILable的用法",
                "UIText的用法",
                "UIButton的用法"
                ]),
            SectionModel(model: "高级控件", items: [
                "UITableView的用法",
                "UICollectionViews的用法"
                ])
            ])
         
        // 创建数据源
        let dataSource = RxTableViewSectionedReloadDataSource
            <SectionModel<String, String>>(configureCell: {
            (dataSource, tv, indexPath, element) in
            let cell = tv.dequeueReusableCell(withIdentifier: "Cell")!
            cell.textLabel?.text = "\(indexPath.row)：\(element)"
            return cell
        })
         
        // 设置分区头标题
        dataSource.titleForHeaderInSection = { ds, index in
            return ds.sectionModels[index].model
        }
         
        // 设置分区尾标题
        //dataSource.titleForFooterInSection = { ds, index in
        //    return "footer"
        //}
         
        // 绑定单元格数据
        items
            .bind(to: tableView.rx.items(dataSource: dataSource))
            .disposed(by: disposeBag)
    }
}
```

- **方式二：使用自定义的Section**

```swift
import UIKit
import RxSwift
import RxCocoa
import RxDataSources
 
class ViewController: UIViewController {
     
    var tableView:UITableView!
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
        super.viewDidLoad()
         
        // 创建表格视图
        self.tableView = UITableView(frame: self.view.frame, style:.plain)
        // 创建一个重用的单元格
        self.tableView!.register(UITableViewCell.self, forCellReuseIdentifier: "Cell")
        self.view.addSubview(self.tableView!)
         
        // 初始化数据
        let sections = Observable.just([
            MySection(header: "基本控件", items: [
                "UILable的用法",
                "UIText的用法",
                "UIButton的用法"
                ]),
            MySection(header: "高级控件", items: [
                "UITableView的用法",
                "UICollectionViews的用法"
                ])
            ])
         
        // 创建数据源
        let dataSource = RxTableViewSectionedAnimatedDataSource<MySection>(
            // 设置单元格
            configureCell: { ds, tv, ip, item in
                let cell = tv.dequeueReusableCell(withIdentifier: "Cell")
                    ?? UITableViewCell(style: .default, reuseIdentifier: "Cell")
                cell.textLabel?.text = "\(ip.row)：\(item)"
                 
                return cell
            },
            // 设置分区头标题
            titleForHeaderInSection: { ds, index in
                return ds.sectionModels[index].header
            }
        )
         
        // 绑定单元格数据
        sections
            .bind(to: tableView.rx.items(dataSource: dataSource))
            .disposed(by: disposeBag)
    }
}
 
// 自定义Section
struct MySection {
    var header: String
    var items: [Item]
}
 
extension MySection : AnimatableSectionModelType {
    typealias Item = String
     
    var identity: String {
        return header
    }
     
    init(original: MySection, items: [Item]) {
        self = original
        self.items = items
    }
}
```



## 数据刷新

```swift
import UIKit
import RxSwift
import RxCocoa
import RxDataSources
 
class ViewController: UIViewController {
     
    // 刷新按钮
    @IBOutlet weak var refreshButton: UIBarButtonItem!
     
    // 表格
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
         
        // 随机的表格数据
        let randomResult = refreshButton.rx.tap.asObservable()
            .startWith(()) // 加这个为了让一开始就能自动请求一次数据
            .flatMapLatest(getRandomResult)
            .share(replay: 1)
         
        // 创建数据源
        let dataSource = RxTableViewSectionedReloadDataSource
            <SectionModel<String, Int>>(configureCell: {
                (dataSource, tv, indexPath, element) in
                let cell = tv.dequeueReusableCell(withIdentifier: "Cell")!
                cell.textLabel?.text = "条目\(indexPath.row)：\(element)"
                return cell
            })
         
        // 绑定单元格数据
        randomResult
            .bind(to: tableView.rx.items(dataSource: dataSource))
            .disposed(by: disposeBag)
    }
     
    // 获取随机数据
    func getRandomResult() -> Observable<[SectionModel<String, Int>]> {
        print("正在请求数据......")
        let items = (0 ..< 5).map {_ in
            Int(arc4random())
        }
        let observable = Observable.just([SectionModel(model: "S", items: items)])
        return observable.delay(2, scheduler: MainScheduler.instance)
    }
}
```

#### 防止表格多次刷新的说明

（1）`flatMapLatest` 的作用是当在短时间内（上一个请求还没回来）连续点击多次“刷新”按钮，虽然仍会发起多次请求，但表格只会接收并显示最后一次请求。避免表格出现连续刷新的现象。

```csharp
// 随机的表格数据
let randomResult = refreshButton.rx.tap.asObservable()
    .startWith(()) // 加这个为了让一开始就能自动请求一次数据
    .flatMapLatest(getRandomResult)
    .share(replay: 1)
```

（2）我们也对源头进行限制下。即通过 `throttle` 设置个阀值（比如 1 秒），如果在1秒内有多次点击则只取最后一次，那么自然也就只发送一次数据请求。

```csharp
// 随机的表格数据
let randomResult = refreshButton.rx.tap.asObservable()
    .throttle(1, scheduler: MainScheduler.instance) // 在主线程中操作，1秒内值若多次改变，取最后一次
    .startWith(()) // 加这个为了让一开始就能自动请求一次数据
    .flatMapLatest(getRandomResult)
    .share(replay: 1)
```

#### 停止数据请求

在实际项目中我们可能会需要对一个未完成的网络请求进行中断操作。比如切换页面或者分类时，如果上一次的请求还未完成就要将其取消掉。

该功能简单说就是通过 `takeUntil` 操作符实现。当 `takeUntil` 中的 `Observable` 发送一个值时，便会结束对应的 `Observable`。

```swift
import UIKit
import RxSwift
import RxCocoa
import RxDataSources
 
class ViewController: UIViewController {
     
    // 刷新按钮
    @IBOutlet weak var refreshButton: UIBarButtonItem!
     
    // 停止按钮
    @IBOutlet weak var cancelButton: UIBarButtonItem!
     
    // 表格
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
         
        // 随机的表格数据
        let randomResult = refreshButton.rx.tap.asObservable()
            .startWith(()) // 加这个为了让一开始就能自动请求一次数据
            .flatMapLatest{
                self.getRandomResult().takeUntil(self.cancelButton.rx.tap)
            }
            .share(replay: 1)
         
        // 创建数据源
        let dataSource = RxTableViewSectionedReloadDataSource
            <SectionModel<String, Int>>(configureCell: {
                (dataSource, tv, indexPath, element) in
                let cell = tv.dequeueReusableCell(withIdentifier: "Cell")!
                cell.textLabel?.text = "条目\(indexPath.row)：\(element)"
                return cell
            })
         
        // 绑定单元格数据
        randomResult
            .bind(to: tableView.rx.items(dataSource: dataSource))
            .disposed(by: disposeBag)
    }
     
    // 获取随机数据
    func getRandomResult() -> Observable<[SectionModel<String, Int>]> {
        print("正在请求数据......")
        let items = (0 ..< 5).map {_ in
            Int(arc4random())
        }
        let observable = Observable.just([SectionModel(model: "S", items: items)])
        return observable.delay(2, scheduler: MainScheduler.instance)
    }
}
```



## 数据搜索过滤

对已获取到的数据进行过滤，即每次输入文字时不会重新发起请求。

```swift
import UIKit
import RxSwift
import RxCocoa
import RxDataSources
 
class ViewController: UIViewController {
     
    // 刷新按钮
    @IBOutlet weak var refreshButton: UIBarButtonItem!
     
    // 表格
    var tableView:UITableView!
     
    // 搜索栏
    var searchBar:UISearchBar!
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
        super.viewDidLoad()
         
        // 创建表格视图
        self.tableView = UITableView(frame: self.view.frame, style:.plain)
        // 创建一个重用的单元格
        self.tableView!.register(UITableViewCell.self,
                                 forCellReuseIdentifier: "Cell")
        self.view.addSubview(self.tableView!)
         
        // 创建表头的搜索栏
        self.searchBar = UISearchBar(frame: CGRect(x: 0, y: 0,
                            width: self.view.bounds.size.width, height: 56))
        self.tableView.tableHeaderView =  self.searchBar
         
        // 随机的表格数据
        let randomResult = refreshButton.rx.tap.asObservable()
            .startWith(()) // 加这个为了让一开始就能自动请求一次数据
            .flatMapLatest(getRandomResult) // 获取数据
            .flatMap(filterResult) // 筛选数据
            .share(replay: 1)
         
        // 创建数据源
        let dataSource = RxTableViewSectionedReloadDataSource
            <SectionModel<String, Int>>(configureCell: {
                (dataSource, tv, indexPath, element) in
                let cell = tv.dequeueReusableCell(withIdentifier: "Cell")!
                cell.textLabel?.text = "条目\(indexPath.row)：\(element)"
                return cell
            })
         
        // 绑定单元格数据
        randomResult
            .bind(to: tableView.rx.items(dataSource: dataSource))
            .disposed(by: disposeBag)
    }
     
    // 获取随机数据
    func getRandomResult() -> Observable<[SectionModel<String, Int>]> {
        print("正在请求数据......")
        let items = (0 ..< 5).map {_ in
            Int(arc4random())
        }
        let observable = Observable.just([SectionModel(model: "S", items: items)])
        return observable.delay(2, scheduler: MainScheduler.instance)
    }
     
    // 过滤数据
    func filterResult(data:[SectionModel<String, Int>])
        -> Observable<[SectionModel<String, Int>]> {
        return self.searchBar.rx.text.orEmpty
            // .debounce(0.5, scheduler: MainScheduler.instance) //只有间隔超过0.5秒才发送
            .flatMapLatest{
                query -> Observable<[SectionModel<String, Int>]> in
                print("正在筛选数据（条件为：\(query)）")
                // 输入条件为空，则直接返回原始数据
                if query.isEmpty {
                    return Observable.just(data)
                }
                // 输入条件为不空，则只返回包含有该文字的数据
                else{
                    var newData:[SectionModel<String, Int>] = []
                    for sectionModel in data {
                        let items = sectionModel.items.filter{ "\($0)".contains(query) }
                        newData.append(SectionModel(model: sectionModel.model, items: items))
                    }
                    return Observable.just(newData)
                }
        }
    }
}
```



## 编辑表格

```tsx
// 定义各种操作命令
enum TableEditingCommand {
    case setItems(items: [String])  // 设置表格数据
    case addItem(item: String)  // 新增数据
    case moveItem(from: IndexPath, to: IndexPath) // 移动数据
    case deleteItem(IndexPath) // 删除数据
}
```

```swift
// 定义表格对应的ViewModel
struct TableViewModel {
    // 表格数据项
    fileprivate var items:[String]
      
    init(items: [String] = []) {
        self.items = items
    }
      
    // 执行相应的命令，并返回最终的结果
    func execute(command: TableEditingCommand) -> TableViewModel {
        switch command {
        case .setItems(let items):
            print("设置表格数据。")
            return TableViewModel(items: items)
        case .addItem(let item):
            print("新增数据项。")
            var items = self.items
            items.append(item)
            return TableViewModel(items: items)
        case .moveItem(let from, let to):
            print("移动数据项。")
            var items = self.items
            items.insert(items.remove(at: from.row), at: to.row)
            return TableViewModel(items: items)
        case .deleteItem(let indexPath):
            print("删除数据项。")
            var items = self.items
            items.remove(at: indexPath.row)
            return TableViewModel(items: items)
        }
    }
}
```

```swift
import UIKit
import RxSwift
import RxCocoa
import RxDataSources
 
class ViewController: UIViewController {
     
    // 刷新按钮
    @IBOutlet weak var refreshButton: UIBarButtonItem!
     
    // 新增按钮
    @IBOutlet weak var addButton: UIBarButtonItem!
     
    // 表格
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
         
        // 表格模型
        let initialVM = TableViewModel()
         
        // 刷新数据命令
        let refreshCommand = refreshButton.rx.tap.asObservable()
            .startWith(()) // 加这个为了页面初始化时会自动加载一次数据
            .flatMapLatest(getRandomResult)
            .map(TableEditingCommand.setItems)
         
        // 新增条目命令
        let addCommand = addButton.rx.tap.asObservable()
            .map{ "\(arc4random())" }
            .map(TableEditingCommand.addItem)
         
        // 移动位置命令
        let movedCommand = tableView.rx.itemMoved
            .map(TableEditingCommand.moveItem)
         
        // 删除条目命令
        let deleteCommand = tableView.rx.itemDeleted.asObservable()
            .map(TableEditingCommand.deleteItem)
         
        // 绑定单元格数据
        Observable.of(refreshCommand, addCommand, movedCommand, deleteCommand)
            .merge()
            .scan(initialVM) { (vm: TableViewModel, command: TableEditingCommand)
                -> TableViewModel in
                return vm.execute(command: command)
            }
            .startWith(initialVM)
            .map {
                [AnimatableSectionModel(model: "", items: $0.items)]
            }
            .share(replay: 1)
            .bind(to: tableView.rx.items(dataSource: ViewController.dataSource()))
            .disposed(by: disposeBag)
    }
     
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        tableView.setEditing(true, animated: true)
    }
     
    // 获取随机数据
    func getRandomResult() -> Observable<[String]> {
        print("生成随机数据。")
        let items = (0 ..< 5).map {_ in
            "\(arc4random())"
        }
        return Observable.just(items)
    }
}
 
extension ViewController {
    // 创建表格数据源
    static func dataSource() -> RxTableViewSectionedAnimatedDataSource
        <AnimatableSectionModel<String, String>> {
        return RxTableViewSectionedAnimatedDataSource(
            // 设置插入、删除、移动单元格的动画效果
            animationConfiguration: AnimationConfiguration(insertAnimation: .top,
                                                           reloadAnimation: .fade,
                                                           deleteAnimation: .left),
            configureCell: {
                (dataSource, tv, indexPath, element) in
                let cell = tv.dequeueReusableCell(withIdentifier: "Cell")!
                cell.textLabel?.text = "条目\(indexPath.row)：\(element)"
                return cell
        },
            canEditRowAtIndexPath: { _, _ in
                return true // 单元格可删除
        },
            canMoveRowAtIndexPath: { _, _ in
                return true // 单元格可移动
        }
        )
    }
}
```



## 使用不同类型的 cell

```swift
import UIKit
import RxSwift
import RxCocoa
import RxDataSources
 
class ViewController: UIViewController {
     
    @IBOutlet weak var tableView: UITableView!
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
        super.viewDidLoad()
         
        // 初始化数据
        let sections = Observable.just([
            MySection(header: "我是第一个分区", items: [
                .TitleImageSectionItem(title: "图片数据1", image: UIImage(named: "php")!),
                .TitleImageSectionItem(title: "图片数据2", image: UIImage(named: "react")!),
                .TitleSwitchSectionItem(title: "开关数据1", enabled: true)
                ]),
            MySection(header: "我是第二个分区", items: [
                .TitleSwitchSectionItem(title: "开关数据2", enabled: false),
                .TitleSwitchSectionItem(title: "开关数据3", enabled: false),
                .TitleImageSectionItem(title: "图片数据3", image: UIImage(named: "swift")!)
                ])
            ])
         
        // 创建数据源
        let dataSource = RxTableViewSectionedReloadDataSource<MySection>(
            // 设置单元格
            configureCell: { dataSource, tableView, indexPath, item in
                switch dataSource[indexPath] {
                case let .TitleImageSectionItem(title, image):
                    let cell = tableView.dequeueReusableCell(withIdentifier: "titleImageCell",
                                                             for: indexPath)
                    (cell.viewWithTag(1) as! UILabel).text = title
                    (cell.viewWithTag(2) as! UIImageView).image = image
                    return cell
                     
                case let .TitleSwitchSectionItem(title, enabled):
                    let cell = tableView.dequeueReusableCell(withIdentifier: "titleSwitchCell",
                                                             for: indexPath)
                    (cell.viewWithTag(1) as! UILabel).text = title
                    (cell.viewWithTag(2) as! UISwitch).isOn = enabled
                    return cell
                }
            },
            // 设置分区头标题
            titleForHeaderInSection: { ds, index in
                return ds.sectionModels[index].header
            }
        )
         
        // 绑定单元格数据
        sections
            .bind(to: tableView.rx.items(dataSource: dataSource))
            .disposed(by: disposeBag)
    }
}
 
// 单元格类型
enum SectionItem {
    case TitleImageSectionItem(title: String, image: UIImage)
    case TitleSwitchSectionItem(title: String, enabled: Bool)
}
 
// 自定义Section
struct MySection {
    var header: String
    var items: [SectionItem]
}
 
extension MySection : SectionModelType {
    typealias Item = SectionItem
     
    init(original: MySection, items: [Item]) {
        self = original
        self.items = items
    }
}
```



## 样式修改

#### 修改单元格高度

```swift
import UIKit
import RxSwift
import RxCocoa
import RxDataSources
 
class ViewController: UIViewController {
     
    var tableView:UITableView!
     
    var dataSource:RxTableViewSectionedAnimatedDataSource<MySection>?
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
        super.viewDidLoad()
         
        // 创建表格视图
        self.tableView = UITableView(frame: self.view.frame, style:.plain)
        // 创建一个重用的单元格
        self.tableView!.register(UITableViewCell.self, forCellReuseIdentifier: "Cell")
        self.view.addSubview(self.tableView!)
         
        // 初始化数据
        let sections = Observable.just([
            MySection(header: "基本控件", items: [
                "UILable的用法",
                "UIText的用法",
                "UIButton的用法"
                ]),
            MySection(header: "高级控件", items: [
                "UITableView的用法",
                "UICollectionViews的用法"
                ])
            ])
         
        // 创建数据源
        let dataSource = RxTableViewSectionedAnimatedDataSource<MySection>(
            // 设置单元格
            configureCell: { ds, tv, ip, item in
                let cell = tv.dequeueReusableCell(withIdentifier: "Cell")
                    ?? UITableViewCell(style: .default, reuseIdentifier: "Cell")
                cell.textLabel?.text = "\(ip.row)：\(item)"
                 
                return cell
            },
            // 设置分区头标题
            titleForHeaderInSection: { ds, index in
                return ds.sectionModels[index].header
            }
        )
         
        self.dataSource = dataSource
         
        // 绑定单元格数据
        sections
            .bind(to: tableView.rx.items(dataSource: dataSource))
            .disposed(by: disposeBag)
         
        // 设置代理
        tableView.rx.setDelegate(self)
            .disposed(by: disposeBag)
    }
}
 
// tableView代理实现
extension ViewController : UITableViewDelegate {
    // 设置单元格高度
    func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath)
        -> CGFloat {
        guard let _ = dataSource?[indexPath],
            let _ = dataSource?[indexPath.section]
            else {
                return 0.0
        }
        return 60
    }
}
 
// 自定义Section
struct MySection {
    var header: String
    var items: [Item]
}
 
extension MySection : AnimatableSectionModelType {
    typealias Item = String
     
    var identity: String {
        return header
    }
     
    init(original: MySection, items: [Item]) {
        self = original
        self.items = items
    }
}
```

#### 修改分组的头部和尾部

```swift
import UIKit
import RxSwift
import RxCocoa
import RxDataSources
 
class ViewController: UIViewController {
     
    var tableView:UITableView!
     
    var dataSource:RxTableViewSectionedAnimatedDataSource<MySection>?
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
        super.viewDidLoad()
         
        // 创建表格视图
        self.tableView = UITableView(frame: self.view.frame, style:.plain)
        // 创建一个重用的单元格
        self.tableView!.register(UITableViewCell.self, forCellReuseIdentifier: "Cell")
        self.view.addSubview(self.tableView!)
         
        // 初始化数据
        let sections = Observable.just([
            MySection(header: "基本控件", items: [
                "UILable的用法",
                "UIText的用法",
                "UIButton的用法"
                ]),
            MySection(header: "高级控件", items: [
                "UITableView的用法",
                "UICollectionViews的用法"
                ])
            ])
         
        // 创建数据源
        let dataSource = RxTableViewSectionedAnimatedDataSource<MySection>(
            // 设置单元格
            configureCell: { ds, tv, ip, item in
                let cell = tv.dequeueReusableCell(withIdentifier: "Cell")
                    ?? UITableViewCell(style: .default, reuseIdentifier: "Cell")
                cell.textLabel?.text = "\(ip.row)：\(item)"
                 
                return cell
            },
            // 设置分区尾部标题
            titleForFooterInSection: { ds, index in
                return "共有\(ds.sectionModels[index].items.count)个控件"
            }
        )
         
        self.dataSource = dataSource
         
        // 绑定单元格数据
        sections
            .bind(to: tableView.rx.items(dataSource: dataSource))
            .disposed(by: disposeBag)
         
        // 设置代理
        tableView.rx.setDelegate(self)
            .disposed(by: disposeBag)
    }
}
 
// tableView代理实现
extension ViewController : UITableViewDelegate {
    // 返回分区头部视图
    func tableView(_ tableView: UITableView, viewForHeaderInSection section: Int)
        -> UIView? {
        let headerView = UIView()
        headerView.backgroundColor = UIColor.black
        let titleLabel = UILabel()
        titleLabel.text = self.dataSource?[section].header
        titleLabel.textColor = UIColor.white
        titleLabel.sizeToFit()
        titleLabel.center = CGPoint(x: self.view.frame.width/2, y: 20)
        headerView.addSubview(titleLabel)
        return headerView
    }
     
    // 返回分区头部高度
    func tableView(_ tableView: UITableView, heightForHeaderInSection section: Int)
        -> CGFloat {
        return 40
    }
}
 
// 自定义Section
struct MySection {
    var header: String
    var items: [Item]
}
 
extension MySection : AnimatableSectionModelType {
    typealias Item = String
     
    var identity: String {
        return header
    }
     
    init(original: MySection, items: [Item]) {
        self = original
        self.items = items
    }
}
```



## 注意：Cell中使用订阅

注意 `prepareForReuse()` 方法里的 `disposeBag = DisposeBag()`
每次 `prepareForReuse()` 方法执行时都会初始化一个新的 `disposeBag`。这是因为 `cell` 是可以复用的，这样当 `cell` 每次重用的时候，便会自动释放之前的 `disposeBag`，从而保证 `cell` 被重用的时候不会被多次订阅，避免错误发生。

```swift
import UIKit
import RxSwift
 
// 单元格类
class MyTableCell: UITableViewCell {
     
    var button:UIButton!
     
    var disposeBag = DisposeBag()
     
    // 单元格重用时调用
    override func prepareForReuse() {
        super.prepareForReuse()
        disposeBag = DisposeBag()
    }
     
    // 初始化
    override init(style: UITableViewCellStyle, reuseIdentifier: String?) {
        super.init(style: style, reuseIdentifier: reuseIdentifier)
         
        // 添加按钮
        button = UIButton(frame:CGRect(x:0, y:0, width:40, height:25))
        button.setTitle("点击", for:.normal) // 普通状态下的文字
        self.addSubview(button)
    }
     
    // 布局
    override func layoutSubviews() {
        super.layoutSubviews()
        button.center = CGPoint(x: bounds.size.width - 35, y: bounds.midY)
    }
 
    required init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
}
```



