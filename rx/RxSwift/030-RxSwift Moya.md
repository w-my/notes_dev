# RXSwift - Moya

`Moya` 是一个基于 `Alamofire` 的更高层网络请求封装抽象层。它可以对我们项目中的所有请求进行集中管理，方便开发与维护。同时 `Moya` 自身也提供了对 `RxSwift` 的扩展，通过与 `RxSwift` 的结合，能让 `Moya` 变得更加强大。下面我就通过样例演示如何使用“`RxSwift + Moya`”这个组合进行开发。



## 安装配置

需要用到的库

- RxSwift：[https://github.com/ReactiveX/RxSwift](https://link.jianshu.com/?t=https%3A%2F%2Fgithub.com%2FReactiveX%2FRxSwift)
- Alamofire：[https://github.com/Alamofire/Alamofire](https://link.jianshu.com/?t=https%3A%2F%2Fgithub.com%2FAlamofire%2FAlamofire)
- Moya：[https://github.com/Moya/Moya](https://link.jianshu.com/?t=https%3A%2F%2Fgithub.com%2FMoya%2FMoya)
- Result：[https://github.com/antitypical/Result](https://link.jianshu.com/?t=https%3A%2F%2Fgithub.com%2Fantitypical%2FResult)



## 数据请求样例



我们先创建一个 `DouBanAPI.swift` 文件作为网络请求层，里面的内容如下：

- 首先定义一个 `provider`，即请求发起对象。往后我们如果要发起网络请求就使用这个 `provider`。
- 接着声明一个 `enum` 来对请求进行明确分类，这里我们定义两个枚举值分别表示获取频道列表、获取歌曲信息。
- 最后让这个 `enum` 实现 `TargetType` 协议，在这里面定义我们各个请求的 `url`、参数、`header` 等信息。

```swift
import Foundation
import Moya
import RxMoya
 
// 初始化豆瓣FM请求的provider
let DouBanProvider = MoyaProvider<DouBanAPI>()
 
/** 下面定义豆瓣FM请求的endpoints（供provider使用）**/
// 请求分类
public enum DouBanAPI {
    case channels  // 获取频道列表
    case playlist(String) // 获取歌曲
}
 
// 请求配置
extension DouBanAPI: TargetType {
    // 服务器地址
    public var baseURL: URL {
        switch self {
        case .channels:
            return URL(string: "https://www.douban.com")!
        case .playlist(_):
            return URL(string: "https://douban.fm")!
        }
    }
     
    // 各个请求的具体路径
    public var path: String {
        switch self {
        case .channels:
            return "/j/app/radio/channels"
        case .playlist(_):
            return "/j/mine/playlist"
        }
    }
     
    // 请求类型
    public var method: Moya.Method {
        return .get
    }
     
    // 请求任务事件（这里附带上参数）
    public var task: Task {
        switch self {
        case .playlist(let channel):
            var params: [String: Any] = [:]
            params["channel"] = channel
            params["type"] = "n"
            params["from"] = "mainsite"
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

##### 使用样例

（1）我们在视图控制器中通过上面的定义的 `provider` 即可发起请求，获取数据。

```swift
import UIKit
import RxSwift
import RxCocoa
 
class ViewController: UIViewController {
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
        super.viewDidLoad()
         
        // 获取数据
        DouBanProvider.rx.request(.channels)
            .subscribe { event in
                switch event {
                case let .success(response):
                    // 数据处理
                    let str = String(data: response.data, encoding: String.Encoding.utf8)
                    print("返回的数据是：", str ?? "")
                case let .error(error):
                    print("数据请求失败!错误原因：", error)
                }
            }.disposed(by: disposeBag)
        }
}
```

（2）订阅相关的代码还可以换种方式写：

```swift
import UIKit
import RxSwift
import RxCocoa
 
class ViewController: UIViewController {
 
     let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
        super.viewDidLoad()
        
        // 获取数据
        DouBanProvider.rx.request(.channels)
            .subscribe(onSuccess: { response in
                // 数据处理
                let str = String(data: response.data, encoding: String.Encoding.utf8)
                print("返回的数据是：", str ?? "")
            },onError: { error in
                print("数据请求失败!错误原因：", error)
            }).disposed(by: disposeBag)
    }
}
```



## 将结果转为 JSON 对象

```swift
// 获取数据
DouBanProvider.rx.request(.channels)
    .subscribe(onSuccess: { response in
        // 数据处理
        let json = try? response.mapJSON() as! [String: Any]
        print("--- 请求成功！返回的如下数据 ---")
        print(json!)
    },onError: { error in
        print("数据请求失败!错误原因：", error)
         
    }).disposed(by: disposeBag)
```

或

```dart
// 获取数据
DouBanProvider.rx.request(.channels)
    .mapJSON()
    .subscribe(onSuccess: { data in
        // 数据处理
        let json = data as! [String: Any]
        print("--- 请求成功！返回的如下数据 ---")
        print(json)
    },onError: { error in
        print("数据请求失败!错误原因：", error)
         
    }).disposed(by: disposeBag)
```

#### 使用样例

```swift
import UIKit
import RxSwift
import RxCocoa
 
class ViewController: UIViewController {
     
    // 显示频道列表的tableView
    var tableView:UITableView!
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
        super.viewDidLoad()
         
        // 创建表视图
        self.tableView = UITableView(frame:self.view.frame, style:.plain)
        // 创建一个重用的单元格
        self.tableView!.register(UITableViewCell.self, forCellReuseIdentifier: "Cell")
        self.view.addSubview(self.tableView!)
         
        // 获取列表数据
        let data = DouBanProvider.rx.request(.channels)
            .mapJSON()
            .map{ data -> [[String: Any]] in
                if let json = data as? [String: Any],
                    let channels = json["channels"] as? [[String: Any]] {
                    return channels
                }else{
                    return []
                }
            }.asObservable()
         
        // 将数据绑定到表格
        data.bind(to: tableView.rx.items) { (tableView, row, element) in
            let cell = tableView.dequeueReusableCell(withIdentifier: "Cell")!
            cell.textLabel?.text = "\(element["name"]!)"
            cell.accessoryType = .disclosureIndicator
            return cell
            }.disposed(by: disposeBag)
         
        // 单元格点击
        tableView.rx.modelSelected([String: Any].self)
            .map{ $0["channel_id"] as! String }
            .flatMap{ DouBanProvider.rx.request(.playlist($0)) }
            .mapJSON()
            .subscribe(onNext: {[weak self] data in
                // 解析数据，获取歌曲信息
                if let json = data as? [String: Any],
                    let musics = json["song"] as? [[String: Any]]{
                    let artist = musics[0]["artist"]!
                    let title = musics[0]["title"]!
                    let message = "歌手：\(artist)\n歌曲：\(title)"
                    // 将歌曲信息弹出显示
                    self?.showAlert(title: "歌曲信息", message: message)
                }               
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



## 将结果映射成自定义对象

（1）要实现数据转模型（`model`），我们这里还要先引入一个第三方的数据模型转换框架：`ObjectMapper`。

- [使用ObjectMapper实现模型转换（JSON与Model的相互转换）](https://www.hangge.com/blog/cache/detail_1673.html)

（2）为了让 `ObjectMapper` 能够更好地与 `Moya` 配合使用，我们需要使用 `Moya-ObjectMapper` 这个 `Observable`扩展库。它的作用是增加数据转模型对象、以及数据转模型对象数组这两个方法。

- GitHub 主页：[https://github.com/ivanbruel/Moya-ObjectMapper](https://link.jianshu.com/?t=https%3A%2F%2Fgithub.com%2Fivanbruel%2FMoya-ObjectMapper)

（3）`Moya-ObjectMapper` 配置很简单只需把 `sourcs` 文件夹中的如下 **3** 个文件添加到项目中来即可。

- Response+ObjectMapper.swift
- ObservableType+ObjectMapper.swift
- Single+ObjectMapper.swift



#### 使用样例

```swift
// 豆瓣接口模型
struct Douban: Mappable {
    // 频道列表
    var channels: [Channel]?
     
    init?(map: Map) { }
     
    // Mappable
    mutating func mapping(map: Map) {
        channels <- map["channels"]
    }
}
 
// 频道模型
struct Channel: Mappable {
    var name: String?
    var nameEn:String?
    var channelId: String?
    var seqId: Int?
    var abbrEn: String?
     
    init?(map: Map) { }
     
    // Mappable
    mutating func mapping(map: Map) {
        name <- map["name"]
        nameEn <- map["name_en"]
        channelId <- map["channel_id"]
        seqId <- map["seq_id"]
        abbrEn <- map["abbr_en"]
    }
}
 
// 歌曲列表模型
struct Playlist: Mappable {
    var r: Int!
    var isShowQuickStart: Int!
    var song:[Song]!
     
    init?(map: Map) { }
     
    // Mappable
    mutating func mapping(map: Map) {
        r <- map["r"]
        isShowQuickStart <- map["is_show_quick_start"]
        song <- map["song"]
    }
}
 
// 歌曲模型
struct Song: Mappable {
    var title: String!
    var artist: String!
     
    init?(map: Map) { }
     
    // Mappable
    mutating func mapping(map: Map) {
        title <- map["title"]
        artist <- map["artist"]
    }
}
```

获取数据，并转换成对应的模型。

```swift
// 获取数据
DouBanProvider.rx.request(.channels)
    .mapObject(Douban.self)
    .subscribe(onSuccess: { douban in
        if let channels = douban.channels {
            print("--- 共\(channels.count)个频道 ---")
            for channel in channels {
                if let name = channel.name, let channelId = channel.channelId {
                    print("\(name) （id:\(channelId)）")
                }
            }
        }
    }, onError: { error in
        print("数据请求失败!错误原因：", error)
    })
    .disposed(by: disposeBag)
```

将数据换成模型，并绑定到表格上显示。

```swift
import UIKit
import RxSwift
import RxCocoa
import ObjectMapper
 
class ViewController: UIViewController {
     
    // 显示频道列表的tableView
    var tableView:UITableView!
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
        super.viewDidLoad()
         
        // 创建表视图
        self.tableView = UITableView(frame:self.view.frame, style:.plain)
        // 创建一个重用的单元格
        self.tableView!.register(UITableViewCell.self, forCellReuseIdentifier: "Cell")
        self.view.addSubview(self.tableView!)
         
        // 获取列表数据
        let data = DouBanProvider.rx.request(.channels)
            .mapObject(Douban.self)
            .map{ $0.channels ?? [] }
            .asObservable()
         
        // 将数据绑定到表格
        data.bind(to: tableView.rx.items) { (tableView, row, element) in
            let cell = tableView.dequeueReusableCell(withIdentifier: "Cell")!
            cell.textLabel?.text = "\(element.name!)"
            cell.accessoryType = .disclosureIndicator
            return cell
            }.disposed(by: disposeBag)
         
        // 单元格点击
        tableView.rx.modelSelected(Channel.self)
            .map{ $0.channelId! }
            .flatMap{ DouBanProvider.rx.request(.playlist($0)) }
            .mapObject(Playlist.self)
            .subscribe(onNext: {[weak self] playlist in
                // 解析数据，获取歌曲信息
                if playlist.song.count > 0 {
                    let artist = playlist.song[0].artist!
                    let title = playlist.song[0].title!
                    let message = "歌手：\(artist)\n歌曲：\(title)"
                    // 将歌曲信息弹出显示
                    self?.showAlert(title: "歌曲信息", message: message)
                }
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
}
```



## 将网络请求服务提取出来

（1）上面的样例中我们是在 `VC` 里是直接调用 `Moya` 的 `Provider` 进行数据请求，并进行模型转换。

（2）我们也可以把网络请求和数据转换相关代码提取出来，作为一个专门的 `Service`。比如 `DouBanNetworkService`。

```swift
import RxSwift
import RxCocoa
import ObjectMapper
 
class DouBanNetworkService {
     
    // 获取频道数据
    func loadChannels() -> Observable<[Channel]> {
        return DouBanProvider.rx.request(.channels)
            .mapObject(Douban.self)
            .map{ $0.channels ?? [] }
            .asObservable()
    }
     
    // 获取歌曲列表数据
    func loadPlaylist(channelId:String) -> Observable<Playlist> {
        return DouBanProvider.rx.request(.playlist(channelId))
            .mapObject(Playlist.self)
            .asObservable()
    }
     
    // 获取频道下第一首歌曲
    func loadFirstSong(channelId:String) -> Observable<Song> {
        return loadPlaylist(channelId: channelId)
            .filter{ $0.song.count > 0}
            .map{ $0.song[0] }
    }
}
```

（3）`VC` 这边不再直接调用 `provider`，而是通过这个 `Service` 就获取需要的数据。

```swift
import UIKit
import RxSwift
import RxCocoa
import ObjectMapper
 
class ViewController: UIViewController {
     
    var tableView:UITableView!
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
        super.viewDidLoad()
         
        self.tableView = UITableView(frame:self.view.frame, style:.plain)
        self.tableView!.register(UITableViewCell.self, forCellReuseIdentifier: "Cell")
        self.view.addSubview(self.tableView!)
         
        // 豆瓣网络请求服务
        let networkService = DouBanNetworkService()
         
        // 获取列表数据
        let data = networkService.loadChannels()
         
        // 将数据绑定到表格
        data.bind(to: tableView.rx.items) { (tableView, row, element) in
            let cell = tableView.dequeueReusableCell(withIdentifier: "Cell")!
            cell.textLabel?.text = "\(element.name!)"
            cell.accessoryType = .disclosureIndicator
            return cell
            }.disposed(by: disposeBag)
         
        // 单元格点击
        tableView.rx.modelSelected(Channel.self)
            .map{ $0.channelId! }
            .flatMap(networkService.loadFirstSong)
            .subscribe(onNext: {[weak self] song in
                // 将歌曲信息弹出显示
                let message = "歌手：\(song.artist!)\n歌曲：\(song.title!)"
                self?.showAlert(title: "歌曲信息", message: message)
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
}
```

