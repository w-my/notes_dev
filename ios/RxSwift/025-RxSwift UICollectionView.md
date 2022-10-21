# RxSwift - UICollectionView



## 基本用法

#### 单个分区的集合视图

（1）首先自定义一个单元格类：

```swift
import UIKit
 
class MyCollectionViewCell: UICollectionViewCell {
     
    var label:UILabel!
     
    override init(frame: CGRect) {
        super.init(frame: frame)
         
        // 背景设为橙色
        self.backgroundColor = UIColor.orange
         
        // 创建文本标签
        label = UILabel(frame: frame)
        label.textColor = UIColor.white
        label.textAlignment = .center
        self.contentView.addSubview(label)
    }
     
    override func layoutSubviews() {
        super.layoutSubviews()
        label.frame = bounds
    }
 
    required init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
}
```

（2）主视图控制器代码如下：

```swift
import UIKit
import RxSwift
import RxCocoa
 
class ViewController: UIViewController {
     
    var collectionView:UICollectionView!
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
        super.viewDidLoad()
         
        // 定义布局方式以及单元格大小
        let flowLayout = UICollectionViewFlowLayout()
        flowLayout.itemSize = CGSize(width: 100, height: 70)
         
        // 创建集合视图
        self.collectionView = UICollectionView(frame: self.view.frame,
                                               collectionViewLayout: flowLayout)
        self.collectionView.backgroundColor = UIColor.white
         
        // 创建一个重用的单元格
        self.collectionView.register(MyCollectionViewCell.self,
                                     forCellWithReuseIdentifier: "Cell")
        self.view.addSubview(self.collectionView!)
         
        // 初始化数据
        let items = Observable.just([
            "Swift",
            "PHP",
            "Ruby",
            "Java",
            "C++",
            ])
         
        // 设置单元格数据（其实就是对 cellForItemAt 的封装）
        items
            .bind(to: collectionView.rx.items) { (collectionView, row, element) in
                let indexPath = IndexPath(row: row, section: 0)
                let cell = collectionView.dequeueReusableCell(withReuseIdentifier: "Cell",
                                                for: indexPath) as! MyCollectionViewCell
                cell.label.text = "\(row)：\(element)"
                return cell
            }
            .disposed(by: disposeBag)
    }
}
```

#### 单元格选中事件响应

```swift
// 获取选中项的索引
collectionView.rx.itemSelected.subscribe(onNext: { [weak self] indexPath in
    self?.showMessage("选中项的indexPath为：\(indexPath)")
}).disposed(by: disposeBag)
 
// 获取选中项的内容
collectionView.rx.modelSelected(String.self).subscribe(onNext: {[weak self] item in
    self?.showMessage("选中项的标题为：\(item)")
}).disposed(by: disposeBag)
```

同时获取选中项的索引，以及内容可以这么写：

```swift
Observable.zip(collectionView.rx.itemSelected, collectionView.rx.modelSelected(String.self))
    .bind { [weak self] indexPath, item in
        self?.showMessage("选中项的indexPath为：\(indexPath)")
        self?.showMessage("选中项的标题为：\(item)")
    }
    .disposed(by: disposeBag)
```

#### 单元格取消选中事件响应

```swift
// 获取被取消选中项的索引
collectionView.rx.itemDeselected.subscribe(onNext: { [weak self] indexPath in
    self?.showMessage("被取消选中项的indexPath为：\(indexPath)")
}).disposed(by: disposeBag)
 
// 获取被取消选中项的内容
collectionView.rx.modelDeselected(String.self).subscribe(onNext: {[weak self] item in
    self?.showMessage("被取消选中项的的标题为：\(item)")
}).disposed(by: disposeBag)
```

同时获取：

```swift
Observable
    .zip(collectionView.rx.itemDeselected, collectionView.rx.modelDeselected(String.self))
    .bind { [weak self] indexPath, item in
        self?.showMessage("被取消选中项的indexPath为：\(indexPath)")
        self?.showMessage("被取消选中项的的标题为：\(item)")
    }
    .disposed(by: disposeBag)
```

#### 单元格高亮完成后的事件响应

```csharp
// 获取选中并高亮完成后的索引
collectionView.rx.itemHighlighted.subscribe(onNext: { indexPath in
    print("高亮单元格的indexPath为：\(indexPath)")
}).disposed(by: disposeBag)
```

#### 高亮转成非高亮完成的事件响应

```csharp
// 获取高亮转成非高亮完成后的索引
collectionView.rx.itemUnhighlighted.subscribe(onNext: { indexPath in
    print("失去高亮的单元格的indexPath为：\(indexPath)")
}).disposed(by: disposeBag)
```

#### 单元格将要显示出来的事件响应

```dart
// 单元格将要显示出来的事件响应
collectionView.rx.willDisplayCell.subscribe(onNext: { cell, indexPath in
    print("将要显示单元格indexPath为：\(indexPath)")
    print("将要显示单元格cell为：\(cell)\n")
}).disposed(by: disposeBag)
```

#### 分区头部或尾部将要显示出来的事件响应

```dart
// 分区头部、尾部将要显示出来的事件响应
collectionView.rx.willDisplaySupplementaryView.subscribe(onNext: { view, kind, indexPath in
    print("将要显示分区indexPath为：\(indexPath)")
    print("将要显示的是头部还是尾部：\(kind)")
    print("将要显示头部或尾部视图：\(view)\n")
}).disposed(by: disposeBag)
```



## RxDataSources

#### 单分区的 CollectionView

```swift
import UIKit
 
class MyCollectionViewCell: UICollectionViewCell {
     
    var label:UILabel!
     
    override init(frame: CGRect) {
        super.init(frame: frame)
         
        // 背景设为橙色
        self.backgroundColor = UIColor.orange
         
        // 创建文本标签
        label = UILabel(frame: frame)
        label.textColor = UIColor.white
        label.textAlignment = .center
        self.contentView.addSubview(label)
    }
     
    override func layoutSubviews() {
        super.layoutSubviews()
        label.frame = bounds
    }
 
    required init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
}
```

- **方式一**：使用自带的 `Section`

```swift
import UIKit
import RxSwift
import RxCocoa
import RxDataSources
 
class ViewController: UIViewController {
     
    var collectionView:UICollectionView!
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
        super.viewDidLoad()
         
        // 定义布局方式以及单元格大小
        let flowLayout = UICollectionViewFlowLayout()
        flowLayout.itemSize = CGSize(width: 100, height: 70)
         
        // 创建集合视图
        self.collectionView = UICollectionView(frame: self.view.frame,
                                               collectionViewLayout: flowLayout)
        self.collectionView.backgroundColor = UIColor.white
         
        // 创建一个重用的单元格
        self.collectionView.register(MyCollectionViewCell.self,
                                     forCellWithReuseIdentifier: "Cell")
        self.view.addSubview(self.collectionView!)
         
        // 初始化数据
        let items = Observable.just([
            SectionModel(model: "", items: [
                "Swift",
                "PHP",
                "Python",
                "Java",
                "javascript",
                "C#"
                ])
            ])
         
        // 创建数据源
        let dataSource = RxCollectionViewSectionedReloadDataSource
            <SectionModel<String, String>>(
            configureCell: { (dataSource, collectionView, indexPath, element) in
                let cell = collectionView.dequeueReusableCell(withReuseIdentifier: "Cell",
                                                for: indexPath) as! MyCollectionViewCell
                cell.label.text = "\(element)"
                return cell}
        )
         
        // 绑定单元格数据
        items
            .bind(to: collectionView.rx.items(dataSource: dataSource))
            .disposed(by: disposeBag)
    }
}
```

- **方式二**：使用自定义的 `Section`

```swift
import UIKit
import RxSwift
import RxCocoa
import RxDataSources
 
class ViewController: UIViewController {
     
    var collectionView:UICollectionView!
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
        super.viewDidLoad()
         
        // 定义布局方式以及单元格大小
        let flowLayout = UICollectionViewFlowLayout()
        flowLayout.itemSize = CGSize(width: 100, height: 70)
         
        // 创建集合视图
        self.collectionView = UICollectionView(frame: self.view.frame,
                                               collectionViewLayout: flowLayout)
        self.collectionView.backgroundColor = UIColor.white
         
        // 创建一个重用的单元格
        self.collectionView.register(MyCollectionViewCell.self,
                                     forCellWithReuseIdentifier: "Cell")
        self.view.addSubview(self.collectionView!)
         
        // 初始化数据
        let sections = Observable.just([
            MySection(header: "", items: [
                "Swift",
                "PHP",
                "Python",
                "Java",
                "javascript",
                "C#"
                ])
            ])
         
        // 创建数据源
        let dataSource = RxCollectionViewSectionedReloadDataSource<MySection>(
            configureCell: { (dataSource, collectionView, indexPath, element) in
                let cell = collectionView.dequeueReusableCell(withReuseIdentifier: "Cell",
                                                for: indexPath) as! MyCollectionViewCell
                cell.label.text = "\(element)"
                return cell}
        )
         
        // 绑定单元格数据
        sections
            .bind(to: collectionView.rx.items(dataSource: dataSource))
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

#### 多分区的 CollectionView

```swift
import UIKit
 
class MySectionHeader: UICollectionReusableView {
    var label:UILabel!
     
    override init(frame: CGRect) {
        super.init(frame: frame)
         
        // 背景设为黑色
        self.backgroundColor = UIColor.black
         
        // 创建文本标签
        label = UILabel(frame: frame)
        label.textColor = UIColor.white
        label.textAlignment = .center
        self.addSubview(label)
    }
     
    override func layoutSubviews() {
        super.layoutSubviews()
        label.frame = bounds
    }
     
    required init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
}
```

- **方式一**：使用自带的 `Section`

```swift
import UIKit
import RxSwift
import RxCocoa
import RxDataSources
 
class ViewController: UIViewController {
     
    var collectionView:UICollectionView!
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
        super.viewDidLoad()
         
        // 定义布局方式以及单元格大小
        let flowLayout = UICollectionViewFlowLayout()
        flowLayout.itemSize = CGSize(width: 100, height: 70)
        flowLayout.headerReferenceSize = CGSize(width: self.view.frame.width, height: 40)
         
        // 创建集合视图
        self.collectionView = UICollectionView(frame: self.view.frame,
                                               collectionViewLayout: flowLayout)
        self.collectionView.backgroundColor = UIColor.white
         
        // 创建一个重用的单元格
        self.collectionView.register(MyCollectionViewCell.self,
                                     forCellWithReuseIdentifier: "Cell")
        // 创建一个重用的分区头
        self.collectionView.register(MySectionHeader.self,
                    forSupplementaryViewOfKind: UICollectionElementKindSectionHeader,
                                     withReuseIdentifier: "Section")
        self.view.addSubview(self.collectionView!)
         
 
        // 初始化数据
        let items = Observable.just([
            SectionModel(model: "脚本语言", items: [
                "Python",
                "javascript",
                "PHP",
                ]),
            SectionModel(model: "高级语言", items: [
                "Swift",
                "C++",
                "Java",
                "C#"
                ])
            ])
         
        // 创建数据源
        let dataSource = RxCollectionViewSectionedReloadDataSource
            <SectionModel<String, String>>(
            configureCell: { (dataSource, collectionView, indexPath, element) in
                let cell = collectionView.dequeueReusableCell(withReuseIdentifier: "Cell",
                                                for: indexPath) as! MyCollectionViewCell
                cell.label.text = "\(element)"
                return cell},
            configureSupplementaryView: {
                (ds ,cv, kind, ip) in
                let section = cv.dequeueReusableSupplementaryView(ofKind: kind,
                            withReuseIdentifier: "Section", for: ip) as! MySectionHeader
                section.label.text = "\(ds[ip.section].model)"
                return section
        })
         
        // 绑定单元格数据
        items
            .bind(to: collectionView.rx.items(dataSource: dataSource))
            .disposed(by: disposeBag)
    }
}
```

- **方式二**：使用自定义的 `Section`

```swift
import UIKit
import RxSwift
import RxCocoa
import RxDataSources
 
class ViewController: UIViewController {
     
    var collectionView:UICollectionView!
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
        super.viewDidLoad()
         
        // 定义布局方式以及单元格大小
        let flowLayout = UICollectionViewFlowLayout()
        flowLayout.itemSize = CGSize(width: 100, height: 70)
        flowLayout.headerReferenceSize = CGSize(width: self.view.frame.width, height: 40)
         
        // 创建集合视图
        self.collectionView = UICollectionView(frame: self.view.frame,
                                               collectionViewLayout: flowLayout)
        self.collectionView.backgroundColor = UIColor.white
         
        // 创建一个重用的单元格
        self.collectionView.register(MyCollectionViewCell.self,
                                     forCellWithReuseIdentifier: "Cell")
        // 创建一个重用的分区头
        self.collectionView.register(MySectionHeader.self,
                    forSupplementaryViewOfKind: UICollectionElementKindSectionHeader,
                                     withReuseIdentifier: "Section")
        self.view.addSubview(self.collectionView!)
         
 
        // 初始化数据
        let sections = Observable.just([
            MySection(header: "脚本语言", items: [
                "Python",
                "javascript",
                "PHP",
                ]),
            MySection(header: "高级语言", items: [
                "Swift",
                "C++",
                "Java",
                "C#"
                ])
            ])
         
        // 创建数据源
        let dataSource = RxCollectionViewSectionedReloadDataSource<MySection>(
            configureCell: { (dataSource, collectionView, indexPath, element) in
                let cell = collectionView.dequeueReusableCell(withReuseIdentifier: "Cell",
                                                for: indexPath) as! MyCollectionViewCell
                cell.label.text = "\(element)"
                return cell},
            configureSupplementaryView: {
                (ds ,cv, kind, ip) in
                let section = cv.dequeueReusableSupplementaryView(ofKind: kind,
                            withReuseIdentifier: "Section", for: ip) as! MySectionHeader
                section.label.text = "\(ds[ip.section].header)"
                return section
        })
         
        // 绑定单元格数据
        sections
            .bind(to: collectionView.rx.items(dataSource: dataSource))
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
     
    // 集合视图
    var collectionView:UICollectionView!
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
        super.viewDidLoad()
         
        // 定义布局方式以及单元格大小
        let flowLayout = UICollectionViewFlowLayout()
        flowLayout.itemSize = CGSize(width: 100, height: 70)
         
        // 创建集合视图
        self.collectionView = UICollectionView(frame: self.view.frame,
                                               collectionViewLayout: flowLayout)
        self.collectionView.backgroundColor = UIColor.white
         
        // 创建一个重用的单元格
        self.collectionView.register(MyCollectionViewCell.self,
                                     forCellWithReuseIdentifier: "Cell")
        self.view.addSubview(self.collectionView!)
         
        // 随机的表格数据
        let randomResult = refreshButton.rx.tap.asObservable()
            .startWith(()) // 加这个为了让一开始就能自动请求一次数据
            .flatMapLatest(getRandomResult)
            .share(replay: 1)
         
        // 创建数据源
        let dataSource = RxCollectionViewSectionedReloadDataSource
            <SectionModel<String, Int>>(
            configureCell: { (dataSource, collectionView, indexPath, element) in
                let cell = collectionView.dequeueReusableCell(withReuseIdentifier: "Cell",
                                                for: indexPath) as! MyCollectionViewCell
                cell.label.text = "\(element)"
                return cell}
        )
         
        // 绑定单元格数据
        randomResult
            .bind(to: collectionView.rx.items(dataSource: dataSource))
            .disposed(by: disposeBag)
    }
     
    // 获取随机数据
    func getRandomResult() -> Observable<[SectionModel<String, Int>]> {
        print("正在请求数据......")
        let items = (0 ..< 5).map {_ in
            Int(arc4random_uniform(100000))
        }
        let observable = Observable.just([SectionModel(model: "S", items: items)])
        return observable.delay(2, scheduler: MainScheduler.instance)
    }
}
 
// 自定义单元格
class MyCollectionViewCell: UICollectionViewCell {
     
    var label:UILabel!
     
    override init(frame: CGRect) {
        super.init(frame: frame)
         
        // 背景设为橙色
        self.backgroundColor = UIColor.orange
         
        // 创建文本标签
        label = UILabel(frame: frame)
        label.textColor = UIColor.white
        label.textAlignment = .center
        self.contentView.addSubview(label)
    }
     
    override func layoutSubviews() {
        super.layoutSubviews()
        label.frame = bounds
    }
     
    required init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
}
```

#### 防止集合视图多次刷新

（1）`flatMapLatest` 的作用是：当在短时间内（上一个请求还没回来）连续点击多次“**刷新**”按钮，虽然仍会发起多次请求，但 `collectionView` 只会接收并显示最后一次请求。避免集合视图出现连续刷新的现象。

```csharp
// 随机的表格数据
let randomResult = refreshButton.rx.tap.asObservable()
    .startWith(()) // 加这个为了让一开始就能自动请求一次数据
    .flatMapLatest(getRandomResult)
    .share(replay: 1)
```

（2）我们也可以对源头进行限制下。即通过 `throttle` 设置个阀值（比如 **1** 秒），如果在 **1** 秒内有多次点击则只取最后一次，那么自然也就只发送一次数据请求。

```csharp
// 随机的表格数据
let randomResult = refreshButton.rx.tap.asObservable()
    .throttle(1, scheduler: MainScheduler.instance) // 在主线程中操作，1秒内值若多次改变，取最后一次
    .startWith(()) // 加这个为了让一开始就能自动请求一次数据
    .flatMapLatest(getRandomResult)
    .share(replay: 1)
```

#### 停止数据请求

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
     
    // 集合视图
    var collectionView:UICollectionView!
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
        super.viewDidLoad()
         
        // 定义布局方式以及单元格大小
        let flowLayout = UICollectionViewFlowLayout()
        flowLayout.itemSize = CGSize(width: 100, height: 70)
         
        // 创建集合视图
        self.collectionView = UICollectionView(frame: self.view.frame,
                                               collectionViewLayout: flowLayout)
        self.collectionView.backgroundColor = UIColor.white
         
        // 创建一个重用的单元格
        self.collectionView.register(MyCollectionViewCell.self,
                                     forCellWithReuseIdentifier: "Cell")
        self.view.addSubview(self.collectionView!)
         
        // 随机的表格数据
        let randomResult = refreshButton.rx.tap.asObservable()
            .startWith(()) // 加这个为了让一开始就能自动请求一次数据
            .flatMapLatest{
                self.getRandomResult().takeUntil(self.cancelButton.rx.tap)
            }
            .share(replay: 1)
         
        // 创建数据源
        let dataSource = RxCollectionViewSectionedReloadDataSource
            <SectionModel<String, Int>>(
            configureCell: { (dataSource, collectionView, indexPath, element) in
                let cell = collectionView.dequeueReusableCell(withReuseIdentifier: "Cell",
                                                for: indexPath) as! MyCollectionViewCell
                cell.label.text = "\(element)"
                return cell}
        )
         
        // 绑定单元格数据
        randomResult
            .bind(to: collectionView.rx.items(dataSource: dataSource))
            .disposed(by: disposeBag)
    }
     
    // 获取随机数据
    func getRandomResult() -> Observable<[SectionModel<String, Int>]> {
        print("正在请求数据......")
        let items = (0 ..< 5).map {_ in
            Int(arc4random_uniform(100000))
        }
        let observable = Observable.just([SectionModel(model: "S", items: items)])
        return observable.delay(2, scheduler: MainScheduler.instance)
    }
}
 
// 自定义单元格
class MyCollectionViewCell: UICollectionViewCell {
     
    var label:UILabel!
     
    override init(frame: CGRect) {
        super.init(frame: frame)
         
        // 背景设为橙色
        self.backgroundColor = UIColor.orange
         
        // 创建文本标签
        label = UILabel(frame: frame)
        label.textColor = UIColor.white
        label.textAlignment = .center
        self.contentView.addSubview(label)
    }
     
    override func layoutSubviews() {
        super.layoutSubviews()
        label.frame = bounds
    }
     
    required init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
}
```



## 样式修改

```swift
import UIKit
import RxSwift
import RxCocoa
import RxDataSources
 
class ViewController: UIViewController {
     
    var collectionView:UICollectionView!
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
        super.viewDidLoad()
         
        // 定义布局方式
        let flowLayout = UICollectionViewFlowLayout()
         
        // 创建集合视图
        self.collectionView = UICollectionView(frame: self.view.frame,
                                               collectionViewLayout: flowLayout)
        self.collectionView.backgroundColor = UIColor.white
         
        // 创建一个重用的单元格
        self.collectionView.register(MyCollectionViewCell.self,
                                     forCellWithReuseIdentifier: "Cell")
        self.view.addSubview(self.collectionView!)
         
        // 初始化数据
        let items = Observable.just([
            SectionModel(model: "", items: [
                "Swift",
                "PHP",
                "Python",
                "Java",
                "C++",
                "C#"
                ])
            ])
         
        // 创建数据源
        let dataSource = RxCollectionViewSectionedReloadDataSource
            <SectionModel<String, String>>(
            configureCell: { (dataSource, collectionView, indexPath, element) in
                let cell = collectionView.dequeueReusableCell(withReuseIdentifier: "Cell",
                                                for: indexPath) as! MyCollectionViewCell
                cell.label.text = "\(element)"
                return cell}
        )
         
        // 绑定单元格数据
        items
            .bind(to: collectionView.rx.items(dataSource: dataSource))
            .disposed(by: disposeBag)
         
        // 设置代理
        collectionView.rx.setDelegate(self)
            .disposed(by: disposeBag)
    }
}
 
// collectionView代理实现
extension ViewController : UICollectionViewDelegateFlowLayout {
    // 设置单元格尺寸
    func collectionView(_ collectionView: UICollectionView,
                        layout collectionViewLayout: UICollectionViewLayout,
                        sizeForItemAt indexPath: IndexPath) -> CGSize {
        let width = collectionView.bounds.width
        let cellWidth = (width - 30) / 4 // 每行显示4个单元格
        return CGSize(width: cellWidth, height: cellWidth * 1.5) // 单元格宽度为高度1.5倍
    }
}
 
// 自定义单元格
class MyCollectionViewCell: UICollectionViewCell {
     
    var label:UILabel!
     
    override init(frame: CGRect) {
        super.init(frame: frame)
         
        // 背景设为橙色
        self.backgroundColor = UIColor.orange
         
        // 创建文本标签
        label = UILabel(frame: frame)
        label.textColor = UIColor.white
        label.textAlignment = .center
        self.contentView.addSubview(label)
    }
     
    override func layoutSubviews() {
        super.layoutSubviews()
        label.frame = bounds
    }
     
    required init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
}
```





