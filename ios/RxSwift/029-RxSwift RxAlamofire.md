# RxSwift - RxAlamofire

#### [RxAlamofire](https://github.com/RxSwiftCommunity/RxAlamofire)



## 基本用法

#### 使用 request 请求数据

```swift
// 创建URL对象
let urlString = "https://www.douban.com/j/app/radio/channels"
let url = URL(string:urlString)!

// 创建并发起请求
request(.get, url)
    .data()
    .subscribe(onNext: {
        data in
        // 数据处理
        let str = String(data: data, encoding: String.Encoding.utf8)
        print("返回的数据是：", str ?? "")
    }, onError: { error in
        print("请求失败！错误原因：", error)
    }).disposed(by: disposeBag)
```

#### 使用 requestData 请求数据

```swift
// 创建URL对象
let urlString = "https://www.douban.com/j/app/radio/channels"
let url = URL(string:urlString)!
 
// 创建并发起请求
requestData(.get, url).subscribe(onNext: {
    response, data in
    // 判断响应结果状态码
    if 200 ..< 300 ~= response.statusCode {
        let str = String(data: data, encoding: String.Encoding.utf8)
        print("请求成功！返回的数据是：", str ?? "")
    }else{
        print("请求失败！")
    }
}).disposed(by: disposeBag)
```

#### 获取 String 类型数据

```swift
// 创建URL对象
let urlString = "https://www.douban.com/j/app/radio/channels"
let url = URL(string:urlString)!
 
// 创建并发起请求
requestString(.get, url)
    .subscribe(onNext: {
        response, data in
        // 数据处理
        print("返回的数据是：", data)
    }).disposed(by: disposeBag)
```



## 手动发起请求、取消请求

```swift
import UIKit
import RxSwift
import RxCocoa
import Alamofire
 
 
class ViewController: UIViewController {
     
    @IBOutlet weak var startBtn: UIButton!
    @IBOutlet weak var cancelBtn: UIButton!
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
        super.viewDidLoad()
         
        // 创建URL对象
        let urlString = "https://www.douban.com/j/app/radio/channels"
        let url = URL(string:urlString)!
         
        // 发起请求按钮点击
        startBtn.rx.tap.asObservable()
            .flatMap {
                request(.get, url).responseString()
                    .takeUntil(self.cancelBtn.rx.tap) // 如果“取消按钮”点击则停止请求
            }
            .subscribe(onNext: {
                response, data in
                print("请求成功！返回的数据是：", data)
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
let url = URL(string:urlString)!
 
// 创建并发起请求
request(.get, url)
    .data()
    .subscribe(onNext: {
        data in
        let json = try? JSONSerialization.jsonObject(with: data, options: .allowFragments)
            as! [String: Any]
        print("--- 请求成功！返回的如下数据 ---")
        print(json!)
    }).disposed(by: disposeBag)
```

在订阅前使用 `responseJSON()` 进行转换：

```swift
// 创建URL对象
let urlString = "https://www.douban.com/j/app/radio/channels"
let url = URL(string:urlString)!
 
// 创建并发起请求
request(.get, url)
    .responseJSON()
    .subscribe(onNext: {
        dataResponse in
        let json = dataResponse.value as! [String: Any]
        print("--- 请求成功！返回的如下数据 ---")
        print(json)
    }).disposed(by: disposeBag)
```

最简单的还是直接使用 `requestJSON` 方法去获取 `JSON` 数据。

```swift
// 创建URL对象
let urlString = "https://www.douban.com/j/app/radio/channels"
let url = URL(string:urlString)!
 
// 创建并发起请求
requestJSON(.get, url)
    .subscribe(onNext: {
        response, data in
        let json = data as! [String: Any]
        print("--- 请求成功！返回的如下数据 ---")
        print(json)
    }).disposed(by: disposeBag)
```

#### 使用样例

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
        let url = URL(string:urlString)!
         
        // 获取列表数据
        let data = requestJSON(.get, url)
            .map{ response, data -> [[String: Any]] in
                if let json = data as? [String: Any],
                    let channels = json["channels"] as? [[String: Any]] {
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
 
// 数据映射错误
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
let url = URL(string:urlString)!
 
// 创建并发起请求
requestJSON(.get, url)
    .map{$1}
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

将数据换成模型，并绑定到表格上显示。

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
        let url = URL(string:urlString)!
         
        // 获取列表数据
        let data = requestJSON(.get, url)
            .map{$1}
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



## 文件上传

#### 支持的上传类型

`Alamofire` 支持如下上传类型，使用 `RxAlamofire` 也是一样的：

- `File`
- `Data`
- `Stream`
- `MultipartFormData`

#### 使用文件流的形式上传文件

```swift
// 需要上传的文件路径
let fileURL = Bundle.main.url(forResource: "hangge", withExtension: "zip")
// 服务器路径
let uploadURL = URL(string: "http://www.hangge.com/upload.php")!
 
// 将文件上传到服务器
upload(fileURL!, urlRequest: try! urlRequest(.post, uploadURL))
    .subscribe(onCompleted: {
        print("上传完毕!")
    })
    .disposed(by: disposeBag)
```

服务端代码（`upload.php`）

```php
<?php 
/** php 接收流文件
* @param  String  $file 接收后保存的文件名
* @return boolean
*/ 
function receiveStreamFile($receiveFile){   
    $streamData = isset($GLOBALS['HTTP_RAW_POST_DATA'])? $GLOBALS['HTTP_RAW_POST_DATA'] : ''; 
   
    if(empty($streamData)){ 
        $streamData = file_get_contents('php://input'); 
    } 
   
    if($streamData!=''){ 
        $ret = file_put_contents($receiveFile, $streamData, true); 
    }else{ 
        $ret = false; 
    } 
  
    return $ret;   
} 
 
// 定义服务器存储路径和文件名
$receiveFile =  $_SERVER["DOCUMENT_ROOT"]."/uploadFiles/hangge.zip"; 
$ret = receiveStreamFile($receiveFile); 
echo json_encode(array('success'=>(bool)$ret)); 
?>
```

#### 获得上传进度

```swift
// 需要上传的文件路径
let fileURL = Bundle.main.url(forResource: "hangge", withExtension: "zip")
// 服务器路径
let uploadURL = URL(string: "http://www.hangge.com/upload.php")!
 
// 将文件上传到服务器
upload(fileURL!, urlRequest: try! urlRequest(.post, uploadURL))
    .subscribe(onNext: { element in
        print("--- 开始上传 ---")
        element.uploadProgress(closure: { (progress) in
            print("当前进度：\(progress.fractionCompleted)")
            print("  已上传载：\(progress.completedUnitCount/1024)KB")
            print("  总大小：\(progress.totalUnitCount/1024)KB")
        })
    }, onError: { error in
        print("上传失败! 失败原因：\(error)")
    }, onCompleted: {
        print("上传完毕!")
    })
    .disposed(by: disposeBag)
```

将进度转成可观察序列，并绑定到进度条上显示。

```swift
// 需要上传的文件路径
let fileURL = Bundle.main.url(forResource: "hangge", withExtension: "zip")
// 服务器路径
let uploadURL = URL(string: "http://www.hangge.com/upload.php")!
 
// 将文件上传到服务器
upload(fileURL!, urlRequest: try! urlRequest(.post, uploadURL))
    .map{request in
        // 返回一个关于进度的可观察序列
        Observable<Float>.create{observer in
            request.uploadProgress(closure: { (progress) in
                observer.onNext(Float(progress.fractionCompleted))
                if progress.isFinished{
                    observer.onCompleted()
                }
            })
            return Disposables.create()
        }
    }
    .flatMap{$0}
    .bind(to: progressView.rx.progress) // 将进度绑定UIProgressView上
    .disposed(by: disposeBag)
```

#### 上传 MultipartFormData 类型的文件数据（类似于网页上 Form 表单里的文件提交）

上传两个文件

```swift
// 需要上传的文件
let fileURL1 = Bundle.main.url(forResource: "0", withExtension: "png")
let fileURL2 = Bundle.main.url(forResource: "1", withExtension: "png")
 
// 服务器路径
let uploadURL = URL(string: "http://www.hangge.com/upload2.php")!
 
// 将文件上传到服务器
upload(
    multipartFormData: { multipartFormData in
        multipartFormData.append(fileURL1!, withName: "file1")
        multipartFormData.append(fileURL2!, withName: "file2")
    },
    to: uploadURL,
    encodingCompletion: { encodingResult in
        switch encodingResult {
        case .success(let upload, _, _):
            upload.responseJSON { response in
                debugPrint(response)
            }
        case .failure(let encodingError):
            print(encodingError)
        }
    })
```

服务端代码（`upload2.php`）

```php
<? 
move_uploaded_file($_FILES["file1"]["tmp_name"],
    $_SERVER["DOCUMENT_ROOT"]."/uploadFiles/" . $_FILES["file1"]["name"]);
 
move_uploaded_file($_FILES["file2"]["tmp_name"],
    $_SERVER["DOCUMENT_ROOT"]."/uploadFiles/" . $_FILES["file2"]["name"]);
?>
```

文本参数与文件一起提交（文件除了可以使用 `fileURL`，还可以上传 `Data` 类型的文件数据）

```swift
// 字符串
let strData = "hangge.com".data(using: String.Encoding.utf8)
// 数字
let intData = String(10).data(using: String.Encoding.utf8)
// 文件1
let path = Bundle.main.url(forResource: "0", withExtension: "png")!
let file1Data = try! Data(contentsOf: path)
// 文件2
let file2URL = Bundle.main.url(forResource: "1", withExtension: "png")
 
// 服务器路径
let uploadURL = URL(string: "http://www.hangge.com/upload2.php")!
 
// 将文件上传到服务器
upload(
    multipartFormData: { multipartFormData in
        multipartFormData.append(strData!, withName: "value1")
        multipartFormData.append(intData!, withName: "value2")
        multipartFormData.append(file1Data, withName: "file1",
                                 fileName: "php.png", mimeType: "image/png")
        multipartFormData.append(file2URL!, withName: "file2")
    },
    to: uploadURL,
    encodingCompletion: { encodingResult in
        switch encodingResult {
        case .success(let upload, _, _):
            upload.responseJSON { response in
                debugPrint(response)
            }
        case .failure(let encodingError):
            print(encodingError)
        }
    })
```

服务端代码（`upload2.php`）

```php
<?
$value1 = $_POST["value1"];
$value2 = $_POST["value2"];
 
move_uploaded_file($_FILES["file1"]["tmp_name"],
    $_SERVER["DOCUMENT_ROOT"]."/uploadFiles/" . $_FILES["file1"]["name"]);
  
move_uploaded_file($_FILES["file2"]["tmp_name"],
    $_SERVER["DOCUMENT_ROOT"]."/uploadFiles/" . $_FILES["file2"]["name"]);
?>
```



## 文件下载

#### 自定义下载文件的保存目录

将 `logo` 图片下载下来，并保存到用户文档目录下（`Documnets` 目录），文件名不变。

```swift
// 指定下载路径（文件名不变）
let destination: DownloadRequest.DownloadFileDestination = { _, response in
    let documentsURL = FileManager.default.urls(for: .documentDirectory, in: .userDomainMask)[0]
    let fileURL = documentsURL.appendingPathComponent(response.suggestedFilename!)
    // 两个参数表示如果有同名文件则会覆盖，如果路径中文件夹不存在则会自动创建
    return (fileURL, [.removePreviousFile, .createIntermediateDirectories])
}
 
// 需要下载的文件
let fileURL = URL(string: "http://www.hangge.com/blog/images/logo.png")!
 
// 开始下载
download(URLRequest(url: fileURL), to: destination)
    .subscribe(onNext: { element in
        print("开始下载。")
    }, onError: { error in
        print("下载失败! 失败原因：\(error)")
    }, onCompleted: {
        print("下载完毕!")
    })
    .disposed(by: disposeBag)
```

将 `logo` 图片下载下来，并保存到用户文档目录下的 `file1` 子目录（ `Documnets/file1`目录），文件名改成 `myLogo.png`。

```swift
// 指定下载路径和保存文件名
let destination: DownloadRequest.DownloadFileDestination = { _, _ in
    let documentsURL = FileManager.default.urls(for: .documentDirectory, in: .userDomainMask)[0]
    let fileURL = documentsURL.appendingPathComponent("file1/myLogo.png")
    // 两个参数表示如果有同名文件则会覆盖，如果路径中文件夹不存在则会自动创建
    return (fileURL, [.removePreviousFile, .createIntermediateDirectories])
}
 
// 需要下载的文件
let fileURL = URL(string: "http://www.hangge.com/blog/images/logo.png")!
 
// 开始下载
download(URLRequest(url: fileURL), to: destination)
    .subscribe(onNext: { element in
        print("开始下载。")
    }, onError: { error in
        print("下载失败! 失败原因：\(error)")
    }, onCompleted: {
        print("下载完毕!")
    })
    .disposed(by: disposeBag)
```

#### 使用默认提供的下载路径

`Alamofire` 内置的许多常用的下载路径方便我们使用，简化代码。注意的是，使用这种方式如果下载路径下有同名文件，不会覆盖原来的文件。

比如，下载到用户文档目录下可以改成：

```swift
let destination = DownloadRequest.suggestedDownloadDestination(for: .documentDirectory)
```

#### 下载进度

```swift
//开始下载
download(URLRequest(url: fileURL), to: destination)
    .subscribe(onNext: { element in
        print("开始下载。")
        element.downloadProgress(closure: { progress in
            print("当前进度: \(progress.fractionCompleted)")
            print("  已下载：\(progress.completedUnitCount/1024)KB")
            print("  总大小：\(progress.totalUnitCount/1024)KB")
        })
    }, onError: { error in
        print("下载失败! 失败原因：\(error)")
    }, onCompleted: {
        print("下载完毕!")
    }).disposed(by: disposeBag)
```

换种写法，将进度转成可观察序列，并绑定到进度条上显示。

```swift
// 开始下载
download(URLRequest(url: fileURL), to: destination)
    .map{request in
        // 返回一个关于进度的可观察序列
        Observable<Float>.create{observer in
            request.downloadProgress(closure: { (progress) in
                observer.onNext(Float(progress.fractionCompleted))
                if progress.isFinished{
                    observer.onCompleted()
                }
            })
            return Disposables.create()
        }
    }
    .flatMap{$0}
    .bind(to: progressView.rx.progress) // 将进度绑定UIProgressView上
    .disposed(by: disposeBag)
```

