# Widget 小组件开发

## Github地址

项目选择对应语言项目小组件部分 Github地址 https://github.com/HahnLoving/iOS_Study

## 创建项目

![图片](https://mmbiz.qpic.cn/mmbiz_png/nVERGuKNwydhFicAx81yr7wk49qDdswS3z5XeiaufH2T78rWR8hmKvpECIXkiaddjr9zvRp2CVYbLSabEbV3FtvMA/640?wx_fmt=png&wxfrom=5&wx_lazy=1&wx_co=1)

![图片](https://mmbiz.qpic.cn/mmbiz_png/nVERGuKNwydhFicAx81yr7wk49qDdswS3OfGtC3EMia80pNYkHuNbf2l4V94sO6wAkOFfSV0F68BWhaX8QnaslWw/640?wx_fmt=png&wxfrom=5&wx_lazy=1&wx_co=1)

## widget 代码说明

#### Provider

```
struct Provider: TimelineProvider {
    // 占位视图，例如网络请求失败、发生未知错误、第一次展示小组件都会展示这个view
    func placeholder(in context: Context) -> SimpleEntry {
        SimpleEntry(date: Date())
    }

    // 定义Widget预览中如何展示，所以提供默认值要在这里
    func getSnapshot(in context: Context, completion: @escaping (SimpleEntry) -> ()) {
        let entry = SimpleEntry(date: Date())
        completion(entry)
    }

    // 决定 Widget 何时刷新
    func getTimeline(in context: Context, completion: @escaping (Timeline<Entry>) -> ()) {
        var entries: [SimpleEntry] = []

        // Generate a timeline consisting of five entries an hour apart, starting from the current date.
        let currentDate = Date()
        for hourOffset in 0 ..< 5 {
            let entryDate = Calendar.current.date(byAdding: .hour, value: hourOffset, to: currentDate)!
            let entry = SimpleEntry(date: entryDate)
            entries.append(entry)
        }

        let timeline = Timeline(entries: entries, policy: .atEnd)
        completion(timeline)
    }
}
```

#### SimpleEntry

```
// 渲染 Widget 所需的数据模型，需要遵守TimelineEntry协议
struct SimpleEntry: TimelineEntry {
    let date: Date
}
```

#### MainWidgetEntryView

```
// 渲染的view
struct MainWidgetEntryView : View {
    var entry: Provider.Entry

    var body: some View {
        Text(entry.date, style: .time)
    }
}
```

#### MainWidget

```
@main
struct MainWidget: Widget {
    // 主件唯一标识符
    let kind: String = "MainWidget"

    var body: some WidgetConfiguration {
        StaticConfiguration(kind: kind, provider: Provider()) { entry in
            MainWidgetEntryView(entry: entry)
        }
        // 标题
        .configurationDisplayName("My Widget")
        // 详情
        .description("This is an example widget.")
        // 枚举设置
        .supportedFamilies([.systemMedium, .systemSmall, .systemLarge])
    }
}
```

#### MainWidget_Previews

```
// SwiftUI Xcode 测试预览视图
struct MainWidget_Previews: PreviewProvider {
    static var previews: some View {
        MainWidgetEntryView(entry: SimpleEntry(date: Date()))
            .previewContext(WidgetPreviewContext(family: .systemSmall))
    }
}
```

#### 效果图

![图片](https://mmbiz.qpic.cn/mmbiz_jpg/nVERGuKNwydhFicAx81yr7wk49qDdswS30TJqS8RbJiawfkRlw05qtbgfCrhOxtTuXeXDlXQNYk7qyDYDUB28c1Q/640?wx_fmt=jpeg&wxfrom=5&wx_lazy=1&wx_co=1)

## widget 分组

widget 有多组和单组区别。 单组包含 小，中，大，特大(iOS 15) 多组包含 小，小，小

单组的例子如系统的天气widget包含小，中，大三个组件

多组以支付宝为例子。包含两个小的组件



## 单组件适配开发

MainWidgetEntryView

```
// 渲染的view
struct MainWidgetEntryView : View {
    var entry: Provider.Entry
    
    // 判断小组件的类型
    @Environment(\.widgetFamily) var family: WidgetFamily

    var body: some View {
//        Text(entry.date, style: .time)
        switch family {
        case .systemSmall:
            VStack(alignment: .center, spacing: 0) {
                Text("小")
                Spacer().frame(height: 20)
                Text(entry.date, style: .time)
            }
        case .systemMedium:
            VStack(alignment: .center, spacing: 0) {
                Text("中")
                Spacer().frame(height: 20)
                Text(entry.date, style: .time)
            }
        default:
            VStack(alignment: .center, spacing: 0) {
                Text("大")
                Spacer().frame(height: 20)
                Text(entry.date, style: .time)
            }
        }
    }
}
```

效果图

![图片](https://mmbiz.qpic.cn/mmbiz_jpg/nVERGuKNwydhFicAx81yr7wk49qDdswS3U2r4tQWKIF8rmyZuKGCPrTQY79tAXyxQxTQnenDcHDCsmc0ibapK0gw/640?wx_fmt=jpeg&wxfrom=5&wx_lazy=1&wx_co=1)

![图片](https://mmbiz.qpic.cn/mmbiz_jpg/nVERGuKNwydhFicAx81yr7wk49qDdswS3TY4xGx7QibIPZx3OgW42msFtIibV0jsSorU9Q2QqUwDvqWKxJiadJibTog/640?wx_fmt=jpeg&wxfrom=5&wx_lazy=1&wx_co=1)

## 多组件开发 WidgetBundle

多组件开发使用了 WidgetBundle 下面用了以下5个案例讲解多组件开发 1.网络请求 NetWorkData 2.网络图片 NetWorkImage 3.编辑小组件 Edit 4.和app本地数据进行交互和点击交互 AppData

MainWidget 先注释全部代码

```
import WidgetKit
import SwiftUI
import Intents

struct SimpleEntry: TimelineEntry {
    public let date: Date
}

struct PlaceholderView : View {
    //这里是PlaceholderView - 提醒用户选择部件功能
    var body: some View {
        Text("Place Holder")
    }
}

@main
struct MainWidget: WidgetBundle {
    @WidgetBundleBuilder
    var body: some Widget {
//        OneWordWidget()
//        FristWidget(title: "hahn", desc: "hahn1")
//        CountDownWidget()
//        Demo(title: "Demo", desc: "Demo")
        NetWorkData(title: "网络请求小组件", desc: "网络请求小组件列表")
        NetWorkImage(title: "网络图片小组件", desc: "网络图片小组件列表")
        Edit(title: "编辑小组件", desc: "编辑小组件列表")
        AppData(title: "app数据交互小组件", desc: "app数据交互小组件列表")
    }
}
```

#### 新建分组的widget

新建SwiftUI文件

![图片](https://mmbiz.qpic.cn/mmbiz_png/nVERGuKNwydhFicAx81yr7wk49qDdswS3onCOwicmeuicXibuGs1XbapazSRxTlwrJk8kBTF4s1Vo6DhoMBdibzgfwQ/640?wx_fmt=png&wxfrom=5&wx_lazy=1&wx_co=1)

新建 SirKit Intent Definition File 文件

![图片](https://mmbiz.qpic.cn/mmbiz_png/nVERGuKNwydhFicAx81yr7wk49qDdswS3yHlY2WfX7dGwQRcX4EYQ1duU7N3lMd8ibrSwTPeaeIqibQ7IfY0yp2Cw/640?wx_fmt=png&wxfrom=5&wx_lazy=1&wx_co=1)

记得勾选这两个，不然会无法编辑的

![图片](https://mmbiz.qpic.cn/mmbiz_png/nVERGuKNwydhFicAx81yr7wk49qDdswS3KffiaXiaOjm0aSL8Me0Wrpmw0gsvPAllPnNyk6n7qnaiafpZZcPXwbF5Q/640?wx_fmt=png&wxfrom=5&wx_lazy=1&wx_co=1)

新建 Intent

![图片](https://mmbiz.qpic.cn/mmbiz_png/nVERGuKNwydhFicAx81yr7wk49qDdswS3C9hA6aTIN5f1icGicyTuiaicIpE7VkVJ7iciaLTGgibwTAicwRv3kicicfibsSxSA/640?wx_fmt=png&wxfrom=5&wx_lazy=1&wx_co=1)

Title就是你对应Widget 名字 Category 选择View 勾Widgets

![图片](https://mmbiz.qpic.cn/mmbiz_png/nVERGuKNwydhFicAx81yr7wk49qDdswS3iaibulwsBUyQtSIjo52zic2vId8HevUsbdNmt9UwnvHOxficKRkY6WXxFQ/640?wx_fmt=png&wxfrom=5&wx_lazy=1&wx_co=1)

### 网络请求 NetWorkData

先按照上面的步骤创建 NetWorkData 的widget 和 Intent文件

注意需要info.plist设置可以网络请求。如果主项目没有网络请求，先做一次网络请求。 我这里使用了Moya 框架进行Api 请求。

为widget 扩展添加pod

```
platform :ios, '14.0'
use_frameworks!
inhibit_all_warnings!

source 'https://github.com/CocoaPods/Specs.git'

target 'StudySwiftUI' do

# swift
end

# Extension 名字  在Targets里面可以查看名字
target 'MainWidgetExtension' do
  pod 'ObjectMapper'
  pod 'Moya'
  pod 'ObjectMapper'
  pod 'HandyJSON'
  pod 'SwiftyJSON'
end
```

请求的json 结构如下

```
{
    "items":[
        {
            "title":"Quiz for Designing",
            "subTitle":"834 questions in tottal",
            "icon":"tlIconDesign1",
            "correctRate":80,
            "submit":48,
            "starCount":4
        },
        {
            "title":"Quiz for Coding",
            "subTitle":"1000 questions in tottal",
            "icon":"tlIconMobile1",
            "correctRate":98,
            "submit":68,
            "starCount":5
        },
        {
            "title":"Quiz for Officing",
            "subTitle":"569 questions in tottal",
            "icon":"tlIconOffice1",
            "correctRate":60,
            "submit":43,
            "starCount":3
        },
        {
            "title":"Quiz for Painting",
            "subTitle":"321 questions in tottal",
            "icon":"tlIconDesign2",
            "correctRate":87,
            "submit":48,
            "starCount":5
        }
    ]
}
```

使用HandyJSON 创建Model

```
import Foundation
import HandyJSON

struct ZModel: HandyJSON {
    var items: [ZQuiz] = []
}

struct ZQuiz: HandyJSON {
    
    var title : String = ""
    var subTitle : String = ""
    var icon : String = ""
    var correctRate : Int = 0
    var submit : Int = 0
    var starCount : Int = 0
}
```

我们取json数组第一个字典的title渲染出来

NetWorkData.swift

```
import WidgetKit
import SwiftUI
import Intents

struct NetWorkDataProvider: IntentTimelineProvider {
    func placeholder(in context: Context) -> NetWorkDataEntry {
        NetWorkDataEntry(date: Date(), configuration: NetWorkDataIntent(), displaySize: context.displaySize, model: ZModel())
    }

    // 定义Widget预览中如何展示，所以提供默认值要在这里
    func getSnapshot(for configuration: NetWorkDataIntent, in context: Context, completion: @escaping (NetWorkDataEntry) -> ()) {
        let entry = NetWorkDataEntry(date: Date(), configuration: configuration, displaySize: context.displaySize, model: ZModel())
        completion(entry)
    }

    // 决定 Widget 何时刷新
    func getTimeline(for configuration: NetWorkDataIntent, in context: Context, completion: @escaping (Timeline<Entry>) -> ()) {
        
        // API请求
        NetWorkRequest(API.getQuizListApi, modelType: ZModel.self) { (model, responseModel) in
            // 每隔2个小时刷新。
            let entry = NetWorkDataEntry(date: Date(), configuration: configuration, displaySize: context.displaySize, model: model)
                // refresh the data every two hours
            let expireDate = Calendar.current.date(byAdding: .hour, value: 2, to: Date()) ?? Date()
            let timeline = Timeline(entries: [entry], policy: .after(expireDate))

            completion(timeline)

        } failureCallback: { (responseModel) in

            
        }
        
    }
}

struct NetWorkDataEntry: TimelineEntry {
    let date: Date
    let configuration: NetWorkDataIntent
    let displaySize: CGSize
    let model: ZModel
}

struct NetWorkDataEntryView : View {
    var entry: NetWorkDataProvider.Entry

    var body: some View {
        Text(entry.model.items.first?.title ?? "0")
    }
}


// 单个
//@main
struct NetWorkData: Widget {
    let kind: String = "NetWorkData"
    var title: String = ""
    var desc: String = ""
    
    var body: some WidgetConfiguration {
        IntentConfiguration(kind: kind, intent: NetWorkDataIntent.self, provider: NetWorkDataProvider()) { entry in
            NetWorkDataEntryView(entry: entry)
        }
        .configurationDisplayName(title)
        .description(desc)
        .supportedFamilies([.systemMedium, .systemSmall])
//        .supportedFamilies([.systemMedium, .systemLarge, .systemSmall])
    }
}
```

效果 渲染出来第一个元素的title



### 网络图片 NetWorkImage

先按照上面的步骤创建 NetWorkImage 的widget 和 Intent文件 注意小组件目前是不支持异步下载的和动画的 所以图片是需要同步下载的

WidgetImageLoader 先对图片下载封装

```
import Foundation
import SwiftUI

enum WidgetError: Error {
    case netError //网络请求出错
    case dataError //数据解析错误
}


/*
 
 由于不支持异步加载图片
 所以暂时在网络请求好之后，直接下载好全部图片
 使用NSCache暂存图片
 */
class WidgetImageLoader {
    
    static var shareLoader = WidgetImageLoader()
    private var cache = NSCache<NSURL, UIImage>()
    
    /// 下载单张图片
    /// - Parameters:
    ///   - imageUrl: 图片URL
    ///   - completion: 成功的回调
    func downLoadImage(imageUrl: String?,completion: @escaping (Result<Image, WidgetError>) -> Void) {
        if let imageUrl = imageUrl {
            if let cacheImage  = self.cache.object(forKey: NSURL(string: imageUrl)!) {
                completion(.success(Image(uiImage: cacheImage)))
            } else {
                URLSession.shared.dataTask(with: URL(string: imageUrl)!) { (data, response, error) in
                    if let data = data,
                       let image = UIImage(data: data) {
                        self.cache.setObject(image, forKey: NSURL(string: imageUrl)!)
                        completion(.success(Image(uiImage: image)))
                    } else {
                        completion(.failure(WidgetError.netError))
                    }
                }.resume()
            }
        } else {
            completion(.failure(WidgetError.dataError))
        }
    }
    
    /// 批量下载图片
    /// - Parameters:
    ///   - imageAry: 图片数组集合
    ///   - placeHolder: 占位图，可传可不传
    ///   - completion: 成功回调
    func downLoadImage(imageAry:[String],placeHolder:Image?,completion: @escaping (Result<[Image], WidgetError>) -> Void) {
        let group:DispatchGroup = DispatchGroup()
        var array = [Image]()
        for image in imageAry {
            group.enter()
            self.downLoadImage(imageUrl: image) { result in
                let image : Image
                if case .success(let response) = result {
                    image = response
                } else {
                    image = placeHolder ?? Image("")
                }
                array.append(image)
                group.leave()
            }
        }
        group.notify(queue: DispatchQueue.main) {
            completion(.success(array))
        }
    }
    
    /// 获取image
    /// - Parameters:
    ///   - imageUrl: 图片地址
    ///   - placeHolderImage: 占位图，请尽量传入
    /// - Returns: 返回结果
    func getImage(_ imageUrl:String, _ placeHolderImage:UIImage?) -> UIImage {
        if let cacheImage  = self.cache.object(forKey: NSURL(string: imageUrl)!) {
            return cacheImage
        } else {
            if let cacheImag = placeHolderImage {
                return cacheImag
            } else {
                return UIImage()
            }
        }
    }
}
```

NetWorkImage

```
import WidgetKit
import SwiftUI
import Intents

struct NetWorkImageProvider: IntentTimelineProvider {
    
    var img = Image("widget_background_test")
    
    func placeholder(in context: Context) -> NetWorkImageEntry {
        NetWorkImageEntry(date: Date(), configuration: NetWorkImageIntent(), displaySize: context.displaySize, img: img)
    }

    // 定义Widget预览中如何展示，所以提供默认值要在这里
    func getSnapshot(for configuration: NetWorkImageIntent, in context: Context, completion: @escaping (NetWorkImageEntry) -> ()) {
        let entry = NetWorkImageEntry(date: Date(), configuration: configuration, displaySize: context.displaySize, img: img)
        completion(entry)
    }

    // 决定 Widget 何时刷新
    func getTimeline(for configuration: NetWorkImageIntent, in context: Context, completion: @escaping (Timeline<Entry>) -> ()) {
        
        var img = Image("widget_background_test")
        // 占位图
        WidgetImageLoader.shareLoader.downLoadImage(imageUrl: "https://lmg.jj20.com/up/allimg/tx18/0217202027012.jpg") { result in
            switch result {
            case .success(let image):
                print("成功 = \(image)")
                img = image
                // 每隔2个小时刷新。
                let entry = NetWorkImageEntry(date: Date(), configuration: configuration, displaySize: context.displaySize,img: img)
                    // refresh the data every two hours
                let expireDate = Calendar.current.date(byAdding: .hour, value: 2, to: Date()) ?? Date()
                let timeline = Timeline(entries: [entry], policy: .after(expireDate))
                
                completion(timeline)
            case .failure(let error):
                print("失败 = \(error)")
            }
        }

    }
}

struct NetWorkImageEntry: TimelineEntry {
    let date: Date
    let configuration: NetWorkImageIntent
    let displaySize: CGSize
    let img: Image
}

struct NetWorkImageEntryView : View {
    var entry: NetWorkImageProvider.Entry

    var body: some View {
        entry.img
            .resizable()
            .frame(width: entry.displaySize.width, height: entry.displaySize.height, alignment: .center)
    }
}


// 单个
//@main
struct NetWorkImage: Widget {
    let kind: String = "NetWorkImage"
    var title: String = ""
    var desc: String = ""
    
    var body: some WidgetConfiguration {
        IntentConfiguration(kind: kind, intent: NetWorkImageIntent.self, provider: NetWorkImageProvider()) { entry in
            NetWorkImageEntryView(entry: entry)
        }
        .configurationDisplayName(title)
        .description(desc)
        .supportedFamilies([.systemMedium, .systemSmall])
//        .supportedFamilies([.systemMedium, .systemLarge, .systemSmall])
    }
}
```

效果

![图片](https://mmbiz.qpic.cn/mmbiz_png/nVERGuKNwydhFicAx81yr7wk49qDdswS3f4iblNW91fJUlh1rDUXxeViaicHZe2pFvTy7Msxzt4uwWAUQiax3TqhKMA/640?wx_fmt=png&wxfrom=5&wx_lazy=1&wx_co=1)

### 编辑小组件 Edit

先按照上面的步骤创建 Edit 的widget 和 Intent文件 这里需要注意要Intent文件一个勾上主项目和你widget，不然小组件编辑无法载入。

在Edit Intent文件创建title字段

![图片](https://mmbiz.qpic.cn/mmbiz_png/nVERGuKNwydhFicAx81yr7wk49qDdswS3078wjnqQ8blbia7IetWsTEp3sDUq8vjCbw1IXzXrE0JAf37earPkb3A/640?wx_fmt=png&wxfrom=5&wx_lazy=1&wx_co=1)

Edit

```
import WidgetKit
import SwiftUI
import Intents


struct EditProvider: IntentTimelineProvider {
    func placeholder(in context: Context) -> EditEntry {
        EditEntry(date: Date(), configuration: EditIntent())
    }
    //    typealias Entry = EditEntry
    func getSnapshot(for configuration: EditIntent, in context: Context, completion: @escaping (EditEntry) -> Void) {
        let entry = EditEntry(date: Date(), configuration: configuration)
        completion(entry)
    }
    func getTimeline(for configuration: EditIntent, in context: Context, completion: @escaping (Timeline<Entry>) -> Void) {
        let entry = EditEntry(date: Date(), configuration: configuration)
            // refresh the data every two hours
        let expireDate = Calendar.current.date(byAdding: .hour, value: 2, to: Date()) ?? Date()
        let timeline = Timeline(entries: [entry], policy: .after(expireDate))
        completion(timeline)
    }
}

struct EditEntry: TimelineEntry {
    public let date: Date
    let configuration: EditIntent
}

struct EditEntryView : View {
    //这里是Widget的类型判断
    var entry: EditProvider.Entry
    
    @ViewBuilder
    var body: some View {
        VStack(alignment: .center) {
            if entry.configuration.title == "请编辑小组件" {
                Text("请编辑小组件吧")
                    .font(.headline)
                    .foregroundColor(Color.gray)
            }else {
                Text(entry.configuration.title ?? "")
                    .font(.headline)
                    .foregroundColor(Color.gray)
            }
        }
        .padding(.all)
    }
    
}



struct Edit: Widget {
    private let kind: String = "Edit"
    var title: String = ""
    var desc: String = ""
    
    public var body: some WidgetConfiguration {
        IntentConfiguration(kind: kind, intent: EditIntent.self, provider: EditProvider()) { entry in
            EditEntryView(entry: entry)
        }
        .configurationDisplayName(title)
        .description(desc)
        .supportedFamilies([.systemSmall])
        
    }
}
```

效果

![图片](https://mmbiz.qpic.cn/mmbiz_png/nVERGuKNwydhFicAx81yr7wk49qDdswS3lhqcwXT1qdhGicLOHDcDMJoicSvkheeBIQmVkt4YwdGiaKicfh4tQYFhnA/640?wx_fmt=png&wxfrom=5&wx_lazy=1&wx_co=1)

![图片](https://mmbiz.qpic.cn/mmbiz_png/nVERGuKNwydhFicAx81yr7wk49qDdswS3kyKNBGYK8SVF9qHSlS7x5VIh4ibBJSB69qtEniaKDGXp9Fedxmiaicq1yA/640?wx_fmt=png&wxfrom=5&wx_lazy=1&wx_co=1)

![图片](https://mmbiz.qpic.cn/mmbiz_png/nVERGuKNwydhFicAx81yr7wk49qDdswS3JHpF7hTVLftLK8wxR081mVxADU0XxkqzNiblflv9u6OMKUJ59t8SsAA/640?wx_fmt=png&wxfrom=5&wx_lazy=1&wx_co=1)

### 和app本地数据进行交互 AppData

先按照上面的步骤创建 AppData 的widget 和 Intent文件

#### 数据交互

小组件和app交互是通过AppGroups的交互的

主项目和子项目都需要创建AppGroups

![图片](https://mmbiz.qpic.cn/mmbiz_png/nVERGuKNwydhFicAx81yr7wk49qDdswS3a66kLgmr3BiaU4Dhue0IL3TCicbght6R2aJIygicJLRhB1cWuUiaDmm3Gg/640?wx_fmt=png&wxfrom=5&wx_lazy=1&wx_co=1)

在主项目保存数据 Swift

```
// appgroup
let z = UserDefaults.init(suiteName: "你的appgroupid")
// 保存数据
z?.set("demo", forKey: "demo")
let demo = z?.value(forKey: "demo")
print("AppGroup交互 = \(String(describing: demo))")

// 全部刷新
WidgetCenter.shared.reloadAllTimelines()
 // 刷新指定的kind
// WidgetCenter.shared.reloadTimelines(ofKind: <#T##String#>)
```

OC 需要创建桥接文件

创建WidgetKitManager.swift 第一次的话会自动配置

WidgetKitManager.swift

```
import WidgetKit

@objc
@available(iOS 14.0, *)
class WidgetKitManager: NSObject {

    @objc
    static let shareManager = WidgetKitManager()
    
    /// MARK: 刷新所有小组件
    @objc
    func reloadAllTimelines() {
       #if arch(arm64) || arch(i386) || arch(x86_64)
            WidgetCenter.shared.reloadAllTimelines()
            #endif
    }

    /// MARK: 刷新单个小组件
    /*
     kind: 小组件Configuration 中的kind
     */
    @objc
    func reloadTimelines(kind: String) {
          #if arch(arm64) || arch(i386) || arch(x86_64)
        WidgetCenter.shared.reloadTimelines(ofKind: kind)
            #endif
    }
}
```

OC

```
#import "WidgetController.h"
#import "StudyOC-Swift.h"

@interface WidgetController ()

@end

@implementation WidgetController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    [self initWidget];
}

- (void)initWidget{
    UIButton *btn = [UIButton new];
    [btn setTitle:@"刷新" forState:UIControlStateNormal];
    [btn setTitleColor:[UIColor redColor] forState:UIControlStateNormal];
    btn.frame = CGRectMake(0, 100, 100, 100);
    [btn addTarget:self action:@selector(clicktBtn1) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:btn];
}

- (void)clicktBtn1{
//    [WidgetCenter];
    //使用 Groups ID 初始化一个供 App Groups 使用的 NSUserDefaults 对象
    NSUserDefaults *userDefaults = [[NSUserDefaults alloc] initWithSuiteName:@"group.zhahntest"];

    //写入数据
    [userDefaults setValue:@"123456789" forKey:@"userID"];

    //读取数据
    NSString *userIDStr = [userDefaults valueForKey:@"userID"];
    NSLog(@"zzr123 = %@",userIDStr);
    [[WidgetKitManager shareManager] reloadAllTimelines];
}
```

效果

一开始是空的

![图片](https://mmbiz.qpic.cn/mmbiz_png/nVERGuKNwydhFicAx81yr7wk49qDdswS3NuwXnP0NEXEa8dsKqx5fFBrmI74SLSJVxBGeY9lfTa6OYibbhrGiaZcQ/640?wx_fmt=png&wxfrom=5&wx_lazy=1&wx_co=1)

执行方法

![图片](https://mmbiz.qpic.cn/mmbiz_png/nVERGuKNwydhFicAx81yr7wk49qDdswS3qJO1IcG2Bmibgl0iaf3xo8lwhlAtgXM7mnlpdGOEiaueVPyZPjJa99jlg/640?wx_fmt=png&wxfrom=5&wx_lazy=1&wx_co=1)

#### 刷新机制

刷新分被动刷新和主动刷新 主动刷新

```
WidgetCenter.shared.reloadAllTimelines()
 // 刷新指定的kind
// WidgetCenter.shared.reloadTimelines(ofKind: <#T##String#>)
```

被动刷新，需要就算设置1分钟，小组件也是最快5分钟刷新一次的

```
    // 决定 Widget 何时刷新
    func getTimeline(for configuration: AppDataIntent, in context: Context, completion: @escaping (Timeline<Entry>) -> ()) {
        
        
        // 每隔2个小时刷新。
        let entry = AppDataEntry(date: Date(), configuration: configuration, str: String(describing: AppData))
            // refresh the data every two hours
        let expireDate = Calendar.current.date(byAdding: .minute, value: 5, to: Date()) ?? Date()
//        print("zzr123 = \(expireDate)")
        let timeline = Timeline(entries: [entry], policy: .after(expireDate))
        
        completion(timeline)
        
    }
```

#### 点击交互

点击是通过link和widgetURL操作，格式是URL sheme

widgetUrl widgetUrl 是针对整个小组件 点击小组件响应(如果有Link 就响应Link)

Link LinK 给元素添加点击事件， Link 对 systemSmall样式的组件不生效(systemSmall 样式的小组件只响应widgetUrl)

```
struct AppDataEntryView : View {
    var entry: AppDataProvider.Entry

    var body: some View {
        VStack
        {
            // 和App数据交互
            Text(entry.str)
            Spacer()
            // 点击交互
            HStack
            {
                Link(destination: URL(string: "https://www.baidu.com?str=left")!) {
                    // 左 View
                    leftView()
                }
                Spacer()
                    .frame(width: 20)

                // 右 View
                Text("right")
                .widgetURL(URL(string: "https://www.baidu.com?str=right"))
                
            }
        }
    }
}


struct leftView : View {

    var body: some View {
        
        HStack {
            
            Text("Left")
        }
    }
}
```

监听是通过openUrl

SwiftUI

```
@main
struct SwiftUIDemoApp: App {
    var body: some Scene {
        WindowGroup {
            ContentView()
                .onOpenURL {
                    print("交互 = \($0)")
                }
        }
    }
}
```

Swift

```
// AppDelegate
func application(_ app: UIApplication, open url: URL, options: [UIApplication.OpenURLOptionsKey : Any] = [:]) -> Bool {
    print("交互 = \(url)")
    return true
}

// SceneDelegate
    func scene(_ scene: UIScene, openURLContexts URLContexts: Set<UIOpenURLContext>) {
        print("交互 = \(URLContexts.first?.url)")
    }
```

OC

```
// AppDelegate
- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options
{
    NSLog(@"交互 = %@",url);
    return YES;
}

// SceneDelegate
- (void)scene:(UIScene *)scene openURLContexts:(NSSet<UIOpenURLContext *> *)URLContexts
{
    NSLog(@"交互 = %@",URLContexts.allObjects.firstObject.URL);
}
```

