# RxSwift - MVVM架构

`RxSwift` 结合 `MVVM` 简直太合适不过了，或者说 `RxSwift` 就是为 `MVVM` 而生。



## 一个使用 Observable 的 MVVM 样例

#### 效果

（1）当我们在表格上方的搜索框中输入文字时，会实时地去请求 `GitHub` 接口查询相匹配的资源库。

（2）数据返回后，将查询结果数量显示在导航栏标题上，同时把匹配度最高的资源条目显示显示在表格中。

（3）点击某个单元格，会弹出显示该资源的详细信息（全名和描述）

（4）删除搜索框的文字后，表格内容同步清空，导航栏标题变成显示 “`hangge.com`”

#### 准备工作

（1）首先我们在项目中配置好 `RxSwift`、`Alamofire`、`Moya`、`Result` 这几个库。

（2）为了方便将结果映射成自定义对象，我们还需要引入 `ObjectMapper`、`Moya-ObjectMapper` 这两个第三方库。

#### 样例代码

（1）我们先创建一个 `GitHubAPI.swift` 文件作为网络请求层，里面的内容如下：

- 首先定义一个 `provider`，即请求发起对象。往后我们如果要发起网络请求就使用这个 `provider`。
- 接着声明一个 `enum` 来对请求进行明确分类，这里我们只有一个枚举值表示查询资源。
- 最后让这个 `enum` 实现 `TargetType` 协议，在这里面定义我们各个请求的 `url`、参数、`header` 等信息。

```swift
import Foundation
import Moya
import RxMoya
 
// 初始化GitHub请求的provider
let GitHubProvider = MoyaProvider<GitHubAPI>()
 
/** 下面定义GitHub请求的endpoints（供provider使用）**/
// 请求分类
public enum GitHubAPI {
    case repositories(String)  // 查询资源库
}
 
// 请求配置
extension GitHubAPI: TargetType {
    // 服务器地址
    public var baseURL: URL {
        return URL(string: "https://api.github.com")!
    }
     
    // 各个请求的具体路径
    public var path: String {
        switch self {
        case .repositories:
            return "/search/repositories"
        }
    }
     
    // 请求类型
    public var method: Moya.Method {
        return .get
    }
     
    // 请求任务事件（这里附带上参数）
    public var task: Task {
        print("发起请求。")
        switch self {
        case .repositories(let query):
            var params: [String: Any] = [:]
            params["q"] = query
            params["sort"] = "stars"
            params["order"] = "desc"
            return .requestParameters(parameters: params,
                                      encoding: URLEncoding.default)
        default:
            return .requestPlain
        }
    }
     
    // 是否执行Alamofire验证
    public var validate: Bool {
        return false
    }
     
    // 这个就是做单元测试模拟的数据，只会在单元测试文件中有作用
    public var sampleData: Data {
        return "{}".data(using: String.Encoding.utf8)!
    }
     
    // 请求头
    public var headers: [String: String]? {
        return nil
    }
}
```

（2）接着定义好相关模型：`GitHubModel.swift`（需要实现 `ObjectMapper` 的 `Mappable` 协议，并设置好成员对象与 `JSON` 属性的相互映射关系。）

```swift
import Foundation
import ObjectMapper
 
// 包含查询返回的所有库模型
struct GitHubRepositories: Mappable {
    var totalCount: Int!
    var incompleteResults: Bool!
    var items: [GitHubRepository]! // 本次查询返回的所有仓库集合
     
    init() {
        print("init()")
        totalCount = 0
        incompleteResults = false
        items = []
    }
     
    init?(map: Map) { }
     
    // Mappable
    mutating func mapping(map: Map) {
        totalCount <- map["total_count"]
        incompleteResults <- map["incomplete_results"]
        items <- map["items"]
    }
}
 
// 单个仓库模型
struct GitHubRepository: Mappable {
    var id: Int!
    var name: String!
    var fullName:String!
    var htmlUrl:String!
    var description:String!
     
    init?(map: Map) { }
     
    // Mappable
    mutating func mapping(map: Map) {
        id <- map["id"]
        name <- map["name"]
        fullName <- map["full_name"]
        htmlUrl <- map["html_url"]
        description <- map["description"]
    }
}
```

（3）下面就是本文的重头戏了。我们创建一个 `ViewModel`，它的作用就是将用户各种输入行为，转换成输出状态。本样例中，不管输入还是输出都是 `Observable` 类型。

```swift
import Foundation
import RxSwift
import Result
 
class ViewModel {
    /**** 输入部分 ***/
    // 查询行为
    fileprivate let searchAction:Observable<String>
     
    /**** 输出部分 ***/
    // 所有的查询结果
    let searchResult: Observable<GitHubRepositories>
     
    // 查询结果里的资源列表
    let repositories: Observable<[GitHubRepository]>
     
    // 清空结果动作
    let cleanResult: Observable<Void>
     
    // 导航栏标题
    let navigationTitle: Observable<String>
     
    // ViewModel初始化（根据输入实现对应的输出）
    init(searchAction:Observable<String>) {
        self.searchAction = searchAction
         
        // 生成查询结果序列
        self.searchResult = searchAction
            .filter { !$0.isEmpty } // 如果输入为空则不发送请求了
            .flatMapLatest{
                GitHubProvider.rx.request(.repositories($0))
                    .filterSuccessfulStatusCodes()
                    .mapObject(GitHubRepositories.self)
                    .asObservable()
                    .catchError({ error in
                        print("发生错误：",error.localizedDescription)
                        return Observable<GitHubRepositories>.empty()
                    })
            }.share(replay: 1) // 让HTTP请求是被共享的
         
        // 生成清空结果动作序列
        self.cleanResult = searchAction.filter{ $0.isEmpty }.map{ _ in Void() }
         
        // 生成查询结果里的资源列表序列（如果查询到结果则返回结果，如果是清空数据则返回空数组）
        self.repositories = Observable.of(searchResult.map{ $0.items },
                                          cleanResult.map{[]}).merge()
         
        // 生成导航栏标题序列（如果查询到结果则返回数量，如果是清空数据则返回默认标题）
        self.navigationTitle = Observable.of(
            searchResult.map{ "共有 \($0.totalCount!) 个结果" },
            cleanResult.map{ "hangge.com" })
            .merge()
    }
}
```

（4）最后我们视图控制器（`ViewController`）只需要调用 `ViewModel` 进行数据绑定就可以了。可以看到由于网络请求、数据处理等逻辑已经被剥离到 `ViewModel` 中，`VC` 这边的负担大大减轻了。

```swift
import UIKit
import RxSwift
import RxCocoa
 
class ViewController: UIViewController {
     
    // 显示资源列表的tableView
    var tableView:UITableView!
     
    // 搜索栏
    var searchBar:UISearchBar!
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
        super.viewDidLoad()
         
        // 创建表视图
        self.tableView = UITableView(frame:self.view.frame, style:.plain)
        // 创建一个重用的单元格
        self.tableView!.register(UITableViewCell.self, forCellReuseIdentifier: "Cell")
        self.view.addSubview(self.tableView!)
         
        // 创建表头的搜索栏
        self.searchBar = UISearchBar(frame: CGRect(x: 0, y: 0,
                                                   width: self.view.bounds.size.width, height: 56))
        self.tableView.tableHeaderView =  self.searchBar
         
        // 查询条件输入
        let searchAction = searchBar.rx.text.orEmpty
            .throttle(0.5, scheduler: MainScheduler.instance) // 只有间隔超过0.5k秒才发送
            .distinctUntilChanged()
            .asObservable()
         
        // 初始化ViewModel
        let viewModel = ViewModel(searchAction: searchAction)
         
        // 绑定导航栏标题数据
        viewModel.navigationTitle.bind(to: self.navigationItem.rx.title).disposed(by: disposeBag)
         
        // 将数据绑定到表格
        viewModel.repositories.bind(to: tableView.rx.items) { (tableView, row, element) in
            let cell = UITableViewCell(style: .subtitle, reuseIdentifier: "Cell")
            cell.textLabel?.text = element.name
            cell.detailTextLabel?.text = element.htmlUrl
            return cell
            }.disposed(by: disposeBag)
         
        // 单元格点击
        tableView.rx.modelSelected(GitHubRepository.self)
            .subscribe(onNext: {[weak self] item in
                // 显示资源信息（完整名称和描述信息）
                self?.showAlert(title: item.fullName, message: item.description)
            }).disposed(by: disposeBag)
    }
     
    // 显示消息
    func showAlert(title:String, message:String){
        let alertController = UIAlertController(title: title,
                                                message: message, preferredStyle: .alert)
        let cancelAction = UIAlertAction(title: "确定", style: .cancel, handler: nil)
        alertController.addAction(cancelAction)
        self.present(alertController, animated: true, completion: nil)
    }
     
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
    }
}
```



#### 功能改进：将网络请求服务提取出来

（1）从上面的样例可以发现，我们在 `ViewModel` 中是直接调用 `Moya` 的 `Provider` 进行数据请求，并进行模型转换。

（2）我们也可以把网络请求和数据转换相关代码提取出来，作为一个专门的 `Service`。比如 `GitHubNetworkService`，内容如下：

```swift
import RxSwift
import RxCocoa
import ObjectMapper
 
class GitHubNetworkService {
     
    // 搜索资源数据
    func searchRepositories(query:String) -> Observable<GitHubRepositories> {
        return GitHubProvider.rx.request(.repositories(query))
            .filterSuccessfulStatusCodes()
            .mapObject(GitHubRepositories.self)
            .asObservable()
            .catchError({ error in
                print("发生错误：",error.localizedDescription)
                return Observable<GitHubRepositories>.empty()
            })
    }
}
```

（3）`ViewModel` 这边不再直接调用 `provider`，而是通过这个 `Service` 就获取需要的数据。可以看到代码简洁许多：

```swift
import Foundation
import RxSwift
import Result
 
class ViewModel {
    /**** 数据请求服务 ***/
    let networkService = GitHubNetworkService()
     
    /**** 输入部分 ***/
    // 查询行为
    fileprivate let searchAction:Observable<String>
     
    /**** 输出部分 ***/
    // 所有的查询结果
    let searchResult: Observable<GitHubRepositories>
     
    // 查询结果里的资源列表
    let repositories: Observable<[GitHubRepository]>
     
    // 清空结果动作
    let cleanResult: Observable<Void>
     
    // 导航栏标题
    let navigationTitle: Observable<String>
     
    // ViewModel初始化（根据输入实现对应的输出）
    init(searchAction:Observable<String>) {
        self.searchAction = searchAction
         
        // 生成查询结果序列
        self.searchResult = searchAction
            .filter { !$0.isEmpty } // 如果输入为空则不发送请求了
            .flatMapLatest(networkService.searchRepositories)
            .share(replay: 1) // 让HTTP请求是被共享的
         
        // 生成清空结果动作序列
        self.cleanResult = searchAction.filter{ $0.isEmpty }.map{ _ in Void() }
         
        // 生成查询结果里的资源列表序列（如果查询到结果则返回结果，如果是清空数据则返回空数组）
        self.repositories = Observable.of(searchResult.map{ $0.items },
                                          cleanResult.map{[]}).merge()
         
        // 生成导航栏标题序列（如果查询到结果则返回数量，如果是清空数据则返回默认标题）
        self.navigationTitle = Observable.of(
            searchResult.map{ "共有 \($0.totalCount!) 个结果" },
            cleanResult.map{"hangge.com"})
            .merge()
    }
}
```



## 使用 Driver 的 MVVM 样例

（1）我们先创建一个 `GitHubAPI.swift` 文件作为网络请求层，里面的内容如下（这个同前文一样）：

- 首先定义一个 `provider`，即请求发起对象。往后我们如果要发起网络请求就使用这个 `provider`。
- 接着声明一个 `enum` 来对请求进行明确分类，这里我们只有一个枚举值表示查询资源。
- 最后让这个 `enum` 实现 `TargetType` 协议，在这里面定义我们各个请求的 `url`、参数、`header` 等信息。

```swift
import Foundation
import Moya
import RxMoya
 
// 初始化GitHub请求的provider
let GitHubProvider = MoyaProvider<GitHubAPI>()
 
/** 下面定义GitHub请求的endpoints（供provider使用）**/
// 请求分类
public enum GitHubAPI {
    case repositories(String)  // 查询资源库
}
 
// 请求配置
extension GitHubAPI: TargetType {
    // 服务器地址
    public var baseURL: URL {
        return URL(string: "https://api.github.com")!
    }
     
    // 各个请求的具体路径
    public var path: String {
        switch self {
        case .repositories:
            return "/search/repositories"
        }
    }
     
    // 请求类型
    public var method: Moya.Method {
        return .get
    }
     
    // 请求任务事件（这里附带上参数）
    public var task: Task {
        print("发起请求。")
        switch self {
        case .repositories(let query):
            var params: [String: Any] = [:]
            params["q"] = query
            params["sort"] = "stars"
            params["order"] = "desc"
            return .requestParameters(parameters: params,
                                      encoding: URLEncoding.default)
        default:
            return .requestPlain
        }
    }
     
    // 是否执行Alamofire验证
    public var validate: Bool {
        return false
    }
     
    // 这个就是做单元测试模拟的数据，只会在单元测试文件中有作用
    public var sampleData: Data {
        return "{}".data(using: String.Encoding.utf8)!
    }
     
    // 请求头
    public var headers: [String: String]? {
        return nil
    }
}
```

（2）接着定义好相关模型：`GitHubModel.swift`（这个还是同前文一样）

```swift
import Foundation
import ObjectMapper
 
// 包含查询返回的所有库模型
struct GitHubRepositories: Mappable {
    var totalCount: Int!
    var incompleteResults: Bool!
    var items: [GitHubRepository]! // 本次查询返回的所有仓库集合
     
    init() {
        print("init()")
        totalCount = 0
        incompleteResults = false
        items = []
    }
     
    init?(map: Map) { }
     
    // Mappable
    mutating func mapping(map: Map) {
        totalCount <- map["total_count"]
        incompleteResults <- map["incomplete_results"]
        items <- map["items"]
    }
}
 
// 单个仓库模型
struct GitHubRepository: Mappable {
    var id: Int!
    var name: String!
    var fullName:String!
    var htmlUrl:String!
    var description:String!
     
    init?(map: Map) { }
     
    // Mappable
    mutating func mapping(map: Map) {
        id <- map["id"]
        name <- map["name"]
        fullName <- map["full_name"]
        htmlUrl <- map["html_url"]
        description <- map["description"]
    }
}
```

（3）下面就是本文的重头戏了。我们创建一个 `ViewModel`，它的作用就是将用户各种输入行为，转换成输出状态。和前文不同的是，本样例中不管输入还是输出都是 `Driver` 类型。

```swift
import Foundation
import RxSwift
import RxCocoa
 
class ViewModel {
    /**** 输入部分 ***/
    // 查询行为
    fileprivate let searchAction:Driver<String>
     
    /**** 输出部分 ***/
    // 所有的查询结果
    let searchResult: Driver<GitHubRepositories>
     
    // 查询结果里的资源列表
    let repositories: Driver<[GitHubRepository]>
     
    // 清空结果动作
    let cleanResult: Driver<Void>
     
    // 导航栏标题
    let navigationTitle: Driver<String>
     
    // ViewModel初始化（根据输入实现对应的输出）
    init(searchAction:Driver<String>) {
        self.searchAction = searchAction
         
        // 生成查询结果序列
        self.searchResult = searchAction
            .filter { !$0.isEmpty } // 如果输入为空则不发送请求了
            .flatMapLatest{
                GitHubProvider.rx.request(.repositories($0))
                    .filterSuccessfulStatusCodes()
                    .mapObject(GitHubRepositories.self)
                    .asDriver(onErrorDriveWith: Driver.empty())
        }
         
        // 生成清空结果动作序列
        self.cleanResult = searchAction.filter{ $0.isEmpty }.map{ _ in Void() }
         
        // 生成查询结果里的资源列表序列（如果查询到结果则返回结果，如果是清空数据则返回空数组）
        self.repositories = Driver.merge(
            searchResult.map{ $0.items },
            cleanResult.map{[]}
        )
         
        // 生成导航栏标题序列（如果查询到结果则返回数量，如果是清空数据则返回默认标题）
        self.navigationTitle = Driver.merge(
            searchResult.map{ "共有 \($0.totalCount!) 个结果" },
            cleanResult.map{ "hangge.com" }
        )
    }
}
```

（4）最后我们视图控制器（`ViewController`）只需要调用 `ViewModel` 进行数据绑定就可以了。可以看到由于网络请求、数据处理等逻辑已经被剥离到 `ViewModel` 中，`VC` 这边的负担大大减轻了。

```swift
import UIKit
import RxSwift
import RxCocoa
 
class ViewController: UIViewController {
     
    // 显示资源列表的tableView
    var tableView:UITableView!
     
    // 搜索栏
    var searchBar:UISearchBar!
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
        super.viewDidLoad()
         
        // 创建表视图
        self.tableView = UITableView(frame:self.view.frame, style:.plain)
        // 创建一个重用的单元格
        self.tableView!.register(UITableViewCell.self, forCellReuseIdentifier: "Cell")
        self.view.addSubview(self.tableView!)
         
        // 创建表头的搜索栏
        self.searchBar = UISearchBar(frame: CGRect(x: 0, y: 0,
                                                   width: self.view.bounds.size.width, height: 56))
        self.tableView.tableHeaderView =  self.searchBar
         
        // 查询条件输入
        let searchAction = searchBar.rx.text.orEmpty.asDriver()
            .throttle(0.5) // 只有间隔超过0.5k秒才发送
            .distinctUntilChanged()
         
        // 初始化ViewModel
        let viewModel = ViewModel(searchAction: searchAction)
         
        // 绑定导航栏标题数据
        viewModel.navigationTitle.drive(self.navigationItem.rx.title).disposed(by: disposeBag)
         
        // 将数据绑定到表格
        viewModel.repositories.drive(tableView.rx.items) { (tableView, row, element) in
            let cell = UITableViewCell(style: .subtitle, reuseIdentifier: "Cell")
            cell.textLabel?.text = element.name
            cell.detailTextLabel?.text = element.htmlUrl
            return cell
            }.disposed(by: disposeBag)
         
        // 单元格点击
        tableView.rx.modelSelected(GitHubRepository.self)
            .subscribe(onNext: {[weak self] item in
                // 显示资源信息（完整名称和描述信息）
                self?.showAlert(title: item.fullName, message: item.description)
            }).disposed(by: disposeBag)
    }
     
    // 显示消息
    func showAlert(title:String, message:String){
        let alertController = UIAlertController(title: title,
                                                message: message, preferredStyle: .alert)
        let cancelAction = UIAlertAction(title: "确定", style: .cancel, handler: nil)
        alertController.addAction(cancelAction)
        self.present(alertController, animated: true, completion: nil)
    }
     
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
    }
}
```



#### 功能改进：将网络请求服务提取出来

（1）从上面的样例可以发现，我们在 `ViewModel`中是直接调用 `Moya` 的 `Provider` 进行数据请求，并进行模型转换。

（2）我们也可以把网络请求和数据转换相关代码提取出来，作为一个专门的 `Service`。比如 `GitHubNetworkService`，内容如下：

```swift
import RxSwift
import RxCocoa
import ObjectMapper
 
class GitHubNetworkService {
     
    // 搜索资源数据
    func searchRepositories(query:String) -> Driver<GitHubRepositories> {
        return GitHubProvider.rx.request(.repositories(query))
            .filterSuccessfulStatusCodes()
            .mapObject(GitHubRepositories.self)
            .asDriver(onErrorDriveWith: Driver.empty())
    }
}
```

（3）`ViewModel` 这边不再直接调用 `provider`，而是通过这个 `Service` 就获取需要的数据。可以看到代码简洁许多：



```swift
import Foundation
import RxSwift
import RxCocoa
 
class ViewModel {
    /**** 数据请求服务 ***/
    let networkService = GitHubNetworkService()
     
    /**** 输入部分 ***/
    // 查询行为
    fileprivate let searchAction:Driver<String>
     
    /**** 输出部分 ***/
    // 所有的查询结果
    let searchResult: Driver<GitHubRepositories>
     
    // 查询结果里的资源列表
    let repositories: Driver<[GitHubRepository]>
     
    // 清空结果动作
    let cleanResult: Driver<Void>
     
    // 导航栏标题
    let navigationTitle: Driver<String>
     
    // ViewModel初始化（根据输入实现对应的输出）
    init(searchAction:Driver<String>) {
        self.searchAction = searchAction
         
        // 生成查询结果序列
        self.searchResult = searchAction
            .filter { !$0.isEmpty } // 如果输入为空则不发送请求了
            .flatMapLatest(networkService.searchRepositories)
         
        // 生成清空结果动作序列
        self.cleanResult = searchAction.filter{ $0.isEmpty }.map{ _ in Void() }
         
        // 生成查询结果里的资源列表序列（如果查询到结果则返回结果，如果是清空数据则返回空数组）
        self.repositories = Driver.merge(
            searchResult.map{ $0.items },
            cleanResult.map{[]}
        )
         
        // 生成导航栏标题序列（如果查询到结果则返回数量，如果是清空数据则返回默认标题）
        self.navigationTitle = Driver.merge(
            searchResult.map{ "共有 \($0.totalCount!) 个结果" },
            cleanResult.map{ "hangge.com" }
        )
    }
}
```

