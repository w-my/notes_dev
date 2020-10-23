# RxSwift - URLSession



## 请求网络数据

#### 通过 rx.response 请求数据

- 状态码在 **200 ~ 300** 则**正常显示数据**。
- 如果是异常状态码（比如：**404**）则**弹出告警提示框**。

```swift
//创建URL对象
let urlString = "https://www.douban.com/j/app/radio/channels"
let url = URL(string:urlString)
//创建请求对象
let request = URLRequest(url: url!)
 
//创建并发起请求
URLSession.shared.rx.response(request: request).subscribe(onNext: {
    (response, data) in
    //判断响应结果状态码
    if 200 ..< 300 ~= response.statusCode {
        let str = String(data: data, encoding: String.Encoding.utf8)
        print("请求成功！返回的数据是：", str ?? "")
    }else{
        print("请求失败！")
    }
}).disposed(by: disposeBag)
```

#### 通过 rx.data 请求数据

> `rx.data` 与 `rx.response` 的区别：
>
> - 如果不需要获取底层的 `response`，只需知道请求是否成功，以及成功时返回的结果，那么建议使用 `rx.data`。
> - 因为 `rx.data` 会自动对响应状态码进行判断，只有成功的响应（状态码为 200~300）才会进入到 `onNext` 这个回调，否则进入 `onError` 这个回调。

（1）如果不需要考虑请求失败的情况，只对成功返回的结果做处理可以在 `onNext` 回调中进行相关操作。

（2）如果还要处理失败的情况，可以在 `onError` 回调中操作。

```swift
// 创建URL对象
let urlString = "https://www.douban.com/xxxxxx/app/radio/channels"
let url = URL(string:urlString)
// 创建请求对象
let request = URLRequest(url: url!)
 
// 创建并发起请求
URLSession.shared.rx.data(request: request).subscribe(onNext: {
    data in
    let str = String(data: data, encoding: String.Encoding.utf8)
    print("请求成功！返回的数据是：", str ?? "")
}, onError: { error in
    print("请求失败！错误原因：", error)
}).disposed(by: disposeBag)
```



## 手动发起请求、取消请求

```swift
import UIKit
import RxSwift
import RxCocoa
 
class ViewController: UIViewController {
     
    @IBOutlet weak var startBtn: UIButton!
    @IBOutlet weak var cancelBtn: UIButton!
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
        super.viewDidLoad()
         
        // 创建URL对象
        let urlString = "https://www.douban.com/j/app/radio/channels"
        let url = URL(string:urlString)
        // 创建请求对象
        let request = URLRequest(url: url!)
         
        // 发起请求按钮点击
        startBtn.rx.tap.asObservable()
            .flatMap {
                URLSession.shared.rx.data(request: request)
                    .takeUntil(self.cancelBtn.rx.tap) // 如果“取消按钮”点击则停止请求
            }
            .subscribe(onNext: {
                data in
                let str = String(data: data, encoding: String.Encoding.utf8)
                print("请求成功！返回的数据是：", str ?? "")
            }, onError: { error in
                print("请求失败！错误原因：", error)
            }).disposed(by: disposeBag)
    }
}
```



## 将结果转为 JSON 对象

```swift
// 创建URL对象
let urlString = "https://www.douban.com/j/app/radio/channels"
let url = URL(string:urlString)
// 创建请求对象
let request = URLRequest(url: url!)
 
// 创建并发起请求
URLSession.shared.rx.data(request: request).subscribe(onNext: {
    data in
    let json = try? JSONSerialization.jsonObject(with: data, options: .allowFragments)
        as! [String: Any]
    print("--- 请求成功！返回的如下数据 ---")
    print(json!)
}).disposed(by: disposeBag)
```

在订阅前就进行转换也是可以的：

```swift
// 创建URL对象
let urlString = "https://www.douban.com/j/app/radio/channels"
let url = URL(string:urlString)
// 创建请求对象
let request = URLRequest(url: url!)
 
// 创建并发起请求
URLSession.shared.rx.data(request: request)
    .map {
        try JSONSerialization.jsonObject(with: $0, options: .allowFragments)
            as! [String: Any]
    }
    .subscribe(onNext: {
        data in
        print("--- 请求成功！返回的如下数据 ---")
        print(data)
    }).disposed(by: disposeBag)
```

更简单的方法，就是直接使用 `RxSwift` 提供的 `rx.json` 方法去获取数据，它会直接将结果转成 `JSON` 对象。

```csharp
// 创建URL对象
let urlString = "https://www.douban.com/j/app/radio/channels"
let url = URL(string:urlString)
// 创建请求对象
let request = URLRequest(url: url!)
 
// 创建并发起请求
URLSession.shared.rx.json(request: request).subscribe(onNext: {
    data in
    let json = data as! [String: Any]
    print("--- 请求成功！返回的如下数据 ---")
    print(json )
}).disposed(by: disposeBag)
```

样例代码

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
        self.tableView!.register(UITableViewCell.self, forCellReuseIdentifier: "Cell")
        self.view.addSubview(self.tableView!)
         
        // 创建URL对象
        let urlString = "https://www.douban.com/j/app/radio/channels"
        let url = URL(string:urlString)
        // 创建请求对象
        let request = URLRequest(url: url!)
         
        // 获取列表数据
        let data = URLSession.shared.rx.json(request: request)
            .map{ result -> [[String: Any]] in
                if let data = result as? [String: Any],
                    let channels = data["channels"] as? [[String: Any]] {
                        return channels
                }else{
                        return []
                }
        }
         
        // 将数据绑定到表格
        data.bind(to: tableView.rx.items) { (tableView, row, element) in
            let cell = tableView.dequeueReusableCell(withIdentifier: "Cell")!
            cell.textLabel?.text = "\(row)：\(element["name"]!)"
            return cell
        }.disposed(by: disposeBag)
    }
}
```



## 将结果映射成自定义对象

[使用ObjectMapper实现模型转换（JSON与Model的相互转换）](https://www.hangge.com/blog/cache/detail_1673.html)

为了让 `ObjectMapper` 能够更好地与 `RxSwift` 配合使用，我们对 `Observable` 进行扩展（`RxObjectMapper.swift`），增加数据转模型对象、以及数据转模型对象数组这两个方法。

```swift
import ObjectMapper
import RxSwift
 
//数据映射错误
public enum RxObjectMapperError: Error {
    case parsingError
}
 
// 扩展Observable：增加模型映射方法
public extension Observable where Element:Any {
     
    // 将JSON数据转成对象
    public func mapObject< T>(type:T.Type) -> Observable<T> where T:Mappable {
        let mapper = Mapper<T>()
         
        return self.map { (element) -> T in
            guard let parsedElement = mapper.map(JSONObject: element) else {
                throw RxObjectMapperError.parsingError
            }
             
            return parsedElement
        }
    }
     
    // 将JSON数据转成数组
    public func mapArray< T>(type:T.Type) -> Observable<[T]> where T:Mappable {
        let mapper = Mapper<T>()
         
        return self.map { (element) -> [T] in
            guard let parsedArray = mapper.mapArray(JSONObject: element) else {
                throw RxObjectMapperError.parsingError
            }
             
            return parsedArray
        }
    }
}
```

#### 使用样例

```swift
// 豆瓣接口模型
class Douban: Mappable {
    // 频道列表
    var channels: [Channel]?
     
    init(){
    }
     
    required init?(map: Map) {
    }
     
    // Mappable
    func mapping(map: Map) {
        channels <- map["channels"]
    }
}
 
// 频道模型
class Channel: Mappable {
    var name: String?
    var nameEn:String?
    var channelId: String?
    var seqId: Int?
    var abbrEn: String?
     
    init(){
    }
     
    required init?(map: Map) {
    }
     
    // Mappable
    func mapping(map: Map) {
        name <- map["name"]
        nameEn <- map["name_en"]
        channelId <- map["channel_id"]
        seqId <- map["seq_id"]
        abbrEn <- map["abbr_en"]
    }
}
```

```swift
// 创建URL对象
let urlString = "https://www.douban.com/j/app/radio/channels"
let url = URL(string:urlString)
// 创建请求对象
let request = URLRequest(url: url!)
 
// 创建并发起请求
URLSession.shared.rx.json(request: request)
    .mapObject(type: Douban.self)
    .subscribe(onNext: { (douban: Douban) in
        if let channels = douban.channels {
            print("--- 共\(channels.count)个频道 ---")
            for channel in channels {
                if let name = channel.name, let channelId = channel.channelId {
                    print("\(name) （id:\(channelId)）")
                }
            }
        }
    }).disposed(by: disposeBag)
```

获取数据并绑定到表格上

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
         
        // 创建表格视图
        self.tableView = UITableView(frame: self.view.frame, style:.plain)
        // 创建一个重用的单元格
        self.tableView!.register(UITableViewCell.self, forCellReuseIdentifier: "Cell")
        self.view.addSubview(self.tableView!)
         
        // 创建URL对象
        let urlString = "https://www.douban.com/j/app/radio/channels"
        let url = URL(string:urlString)
        // 创建请求对象
        let request = URLRequest(url: url!)
         
        // 获取列表数据
        let data = URLSession.shared.rx.json(request: request)
            .mapObject(type: Douban.self)
            .map{ $0.channels ?? []}
         
        // 将数据绑定到表格
        data.bind(to: tableView.rx.items) { (tableView, row, element) in
            let cell = tableView.dequeueReusableCell(withIdentifier: "Cell")!
            cell.textLabel?.text = "\(row)：\(element.name!)"
            return cell
        }.disposed(by: disposeBag)
    }
}
```









