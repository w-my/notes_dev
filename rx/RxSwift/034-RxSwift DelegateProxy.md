# RxSwift - DelegateProxy



## 获取地理定位信息

委托（`delegate`） iOS 开发中十分常见。不管是使用系统自带的库，还是一些第三方组件时，我们总能看到 `delegate` 的身影。使用 `delegate` 可以实现代码的松耦合，减少代码复杂度。但如果我们项目中使用 `RxSwift`，那么原先的 `delegate` 方式与我们链式编程方式就不相称了。

解决办法就是将代理方法进行一层 `Rx` 封装，这样做不仅会减少许多不必要的工作（比如原先需要遵守不同的代理，并且要实现相应的代理方法），还会使得代码的聚合度更高，更加符合响应式编程的规范。

其实在 RxCocoa 源码中我们也可以发现，它已经对标准的 `Cocoa` 做了大量的封装（比如 `tableView` 的 `itemSelected`）。下面我将通过样例演示如何将代理方法进行 `Rx` 化。



### 对 Delegate进行Rx封装原理

#### DelegateProxy

（1）`DelegateProxy` 是代理委托，我们可以将它看作是代理的代理。

（2）`DelegateProxy` 的作用是做为一个中间代理，他会先把系统的 `delegate` 对象保存一份，然后拦截 `delegate`的方法。也就是说在每次触发 `delegate` 方法之前，会先调用 `DelegateProxy` 这边对应的方法，我们可以在这里发射序列给多个订阅者。

#### 流程图

这里以 `UIScrollView` 为例，`Delegate proxy` 便是其代理委托，它遵守 `DelegateProxyType` 与 `UIScrollViewDelegate`，并能响应 `UIScrollViewDelegate` 的代理方法，这里我们可以为代理委托设计它所要响应的方法（即为订阅者发送观察序列）。

```xml
/***
  
 +-------------------------------------------+
 |                                           |
 | UIView subclass (UIScrollView)            |
 |                                           |
 +-----------+-------------------------------+
             |
             | Delegate
             |
             |
 +-----------v-------------------------------+
 |                                           |
 | Delegate proxy : DelegateProxyType        +-----+---->  Observable<T1>
 |                , UIScrollViewDelegate     |     |
 +-----------+-------------------------------+     +---->  Observable<T2>
             |                                     |
             |                                     +---->  Observable<T3>
             |                                     |
             | forwards events                     |
             | to custom delegate                  |
             |                                     v
 +-----------v-------------------------------+
 |                                           |
 | Custom delegate (UIScrollViewDelegate)    |
 |                                           |
 +-------------------------------------------+
 
 **/
```



### 获取地理定位信息样例

这个是 `RxSwift` 的一个官方样例，演示的是如何对 `CLLocationManagerDelegate` 进行 `Rx` 封装。

#### 效果

（1）第一次运行时会申请定位权限，如果当前`App`可以使用定位信息时，界面上会实时更新显示当前的经纬度。

（2）如果当前 `App` 被禁止使用定位信息，界面上会出现一个提示按钮，点击后会自动跳转到系统权限设置页面。

#### 准备工作

（1）`RxCLLocationManagerDelegateProxy.swift`

首先继承 `DelegateProxy` 创建一个关于定位服务的代理委托，同时它还要遵守 `DelegateProxyType` 和 `CLLocationManagerDelegate` 协议。

```swift
import CoreLocation
import RxSwift
import RxCocoa
 
extension CLLocationManager: HasDelegate {
    public typealias Delegate = CLLocationManagerDelegate
}
 
public class RxCLLocationManagerDelegateProxy
    : DelegateProxy<CLLocationManager, CLLocationManagerDelegate>
    , DelegateProxyType , CLLocationManagerDelegate {
     
    public init(locationManager: CLLocationManager) {
        super.init(parentObject: locationManager,
                   delegateProxy: RxCLLocationManagerDelegateProxy.self)
    }
     
    public static func registerKnownImplementations() {
        self.register { RxCLLocationManagerDelegateProxy(locationManager: $0) }
    }
     
    internal lazy var didUpdateLocationsSubject = PublishSubject<[CLLocation]>()
    internal lazy var didFailWithErrorSubject = PublishSubject<Error>()
     
    public func locationManager(_ manager: CLLocationManager,
                                didUpdateLocations locations: [CLLocation]) {
        _forwardToDelegate?.locationManager?(manager, didUpdateLocations: locations)
        didUpdateLocationsSubject.onNext(locations)
    }
     
    public func locationManager(_ manager: CLLocationManager,
                                didFailWithError error: Error) {
        _forwardToDelegate?.locationManager?(manager, didFailWithError: error)
        didFailWithErrorSubject.onNext(error)
    }
     
    deinit {
        self.didUpdateLocationsSubject.on(.completed)
        self.didFailWithErrorSubject.on(.completed)
    }
}
```

（2）`CLLocationManager+Rx.swift`

接着我们对 `CLLocationManager` 进行`Rx` 扩展，作用是将`CLLocationManager`与前面创建的代理委托关联起来，将定位相关的 `delegate` 方法转为可观察序列。

注意：下面代码中将 `methodInvoked`方法替换成 `sentMessage` 其实也可以。

```swift
import CoreLocation
import RxSwift
import RxCocoa
 
extension Reactive where Base: CLLocationManager {
     
    /**
     Reactive wrapper for `delegate`.
      
     For more information take a look at `DelegateProxyType` protocol documentation.
     */
    public var delegate: DelegateProxy<CLLocationManager, CLLocationManagerDelegate> {
        return RxCLLocationManagerDelegateProxy.proxy(for: base)
    }
     
    // MARK: Responding to Location Events
     
    /**
     Reactive wrapper for `delegate` message.
     */
    public var didUpdateLocations: Observable<[CLLocation]> {
        return RxCLLocationManagerDelegateProxy.proxy(for: base)
            .didUpdateLocationsSubject.asObservable()
    }
     
    /**
     Reactive wrapper for `delegate` message.
     */
    public var didFailWithError: Observable<Error> {
        return RxCLLocationManagerDelegateProxy.proxy(for: base)
            .didFailWithErrorSubject.asObservable()
    }
     
    #if os(iOS) || os(macOS)
    /**
     Reactive wrapper for `delegate` message.
     */
    public var didFinishDeferredUpdatesWithError: Observable<Error?> {
        return delegate.methodInvoked(#selector(CLLocationManagerDelegate
            .locationManager(_:didFinishDeferredUpdatesWithError:)))
            .map { a in
                return try castOptionalOrThrow(Error.self, a[1])
        }
    }
    #endif
     
    #if os(iOS)
     
    // MARK: Pausing Location Updates
     
    /**
     Reactive wrapper for `delegate` message.
     */
    public var didPauseLocationUpdates: Observable<Void> {
        return delegate.methodInvoked(#selector(CLLocationManagerDelegate
            .locationManagerDidPauseLocationUpdates(_:)))
            .map { _ in
                return ()
        }
    }
     
    /**
     Reactive wrapper for `delegate` message.
     */
    public var didResumeLocationUpdates: Observable<Void> {
        return delegate.methodInvoked( #selector(CLLocationManagerDelegate
            .locationManagerDidResumeLocationUpdates(_:)))
            .map { _ in
                return ()
        }
    }
     
    // MARK: Responding to Heading Events
     
    /**
     Reactive wrapper for `delegate` message.
     */
    public var didUpdateHeading: Observable<CLHeading> {
        return delegate.methodInvoked(#selector(CLLocationManagerDelegate
            .locationManager(_:didUpdateHeading:)))
            .map { a in
                return try castOrThrow(CLHeading.self, a[1])
        }
    }
     
    // MARK: Responding to Region Events
     
    /**
     Reactive wrapper for `delegate` message.
     */
    public var didEnterRegion: Observable<CLRegion> {
        return delegate.methodInvoked(#selector(CLLocationManagerDelegate
            .locationManager(_:didEnterRegion:)))
            .map { a in
                return try castOrThrow(CLRegion.self, a[1])
        }
    }
     
    /**
     Reactive wrapper for `delegate` message.
     */
    public var didExitRegion: Observable<CLRegion> {
        return delegate.methodInvoked(#selector(CLLocationManagerDelegate
            .locationManager(_:didExitRegion:)))
            .map { a in
                return try castOrThrow(CLRegion.self, a[1])
        }
    }
     
    #endif
     
    #if os(iOS) || os(macOS)
     
    /**
     Reactive wrapper for `delegate` message.
     */
    @available(OSX 10.10, *)
    public var didDetermineStateForRegion: Observable<(state: CLRegionState,
        region: CLRegion)> {
        return delegate.methodInvoked(#selector(CLLocationManagerDelegate
            .locationManager(_:didDetermineState:for:)))
            .map { a in
                let stateNumber = try castOrThrow(NSNumber.self, a[1])
                let state = CLRegionState(rawValue: stateNumber.intValue)
                    ?? CLRegionState.unknown
                let region = try castOrThrow(CLRegion.self, a[2])
                return (state: state, region: region)
        }
    }
     
    /**
     Reactive wrapper for `delegate` message.
     */
    public var monitoringDidFailForRegionWithError:
        Observable<(region: CLRegion?, error: Error)> {
        return delegate.methodInvoked(#selector(CLLocationManagerDelegate
            .locationManager(_:monitoringDidFailFor:withError:)))
            .map { a in
                let region = try castOptionalOrThrow(CLRegion.self, a[1])
                let error = try castOrThrow(Error.self, a[2])
                return (region: region, error: error)
        }
    }
     
    /**
     Reactive wrapper for `delegate` message.
     */
    public var didStartMonitoringForRegion: Observable<CLRegion> {
        return delegate.methodInvoked(#selector(CLLocationManagerDelegate
            .locationManager(_:didStartMonitoringFor:)))
            .map { a in
                return try castOrThrow(CLRegion.self, a[1])
        }
    }
     
    #endif
     
    #if os(iOS)
     
    // MARK: Responding to Ranging Events
     
    /**
     Reactive wrapper for `delegate` message.
     */
    public var didRangeBeaconsInRegion: Observable<(beacons: [CLBeacon],
        region: CLBeaconRegion)> {
        return delegate.methodInvoked(#selector(CLLocationManagerDelegate
            .locationManager(_:didRangeBeacons:in:)))
            .map { a in
                let beacons = try castOrThrow([CLBeacon].self, a[1])
                let region = try castOrThrow(CLBeaconRegion.self, a[2])
                return (beacons: beacons, region: region)
        }
    }
     
    /**
     Reactive wrapper for `delegate` message.
     */
    public var rangingBeaconsDidFailForRegionWithError:
        Observable<(region: CLBeaconRegion, error: Error)> {
        return delegate.methodInvoked(#selector(CLLocationManagerDelegate
            .locationManager(_:rangingBeaconsDidFailFor:withError:)))
            .map { a in
                let region = try castOrThrow(CLBeaconRegion.self, a[1])
                let error = try castOrThrow(Error.self, a[2])
                return (region: region, error: error)
        }
    }
     
    // MARK: Responding to Visit Events
     
    /**
     Reactive wrapper for `delegate` message.
     */
    @available(iOS 8.0, *)
    public var didVisit: Observable<CLVisit> {
        return delegate.methodInvoked(#selector(CLLocationManagerDelegate
            .locationManager(_:didVisit:)))
            .map { a in
                return try castOrThrow(CLVisit.self, a[1])
        }
    }
     
    #endif
     
    // MARK: Responding to Authorization Changes
     
    /**
     Reactive wrapper for `delegate` message.
     */
    public var didChangeAuthorizationStatus: Observable<CLAuthorizationStatus> {
        return delegate.methodInvoked(#selector(CLLocationManagerDelegate
            .locationManager(_:didChangeAuthorization:)))
            .map { a in
                let number = try castOrThrow(NSNumber.self, a[1])
                return CLAuthorizationStatus(rawValue: Int32(number.intValue))
                    ?? .notDetermined
        }
    }
}
 
 
fileprivate func castOrThrow<T>(_ resultType: T.Type, _ object: Any) throws -> T {
    guard let returnValue = object as? T else {
        throw RxCocoaError.castingError(object: object, targetType: resultType)
    }
     
    return returnValue
}
 
fileprivate func castOptionalOrThrow<T>(_ resultType: T.Type,
                                        _ object: Any) throws -> T? {
    if NSNull().isEqual(object) {
        return nil
    }
     
    guard let returnValue = object as? T else {
        throw RxCocoaError.castingError(object: object, targetType: resultType)
    }
     
    return returnValue
}
```

（3）`GeolocationService.swift`

虽然现在我们已经可以直接 `CLLocationManager` 的 `rx` 扩展方法获取位置信息了。但为了更加方便使用，我们这里对 `CLLocationManager` 再次进行封装，定义一个地理定位的 `service` 层，作用如下：

- 自动申请定位权限，以及授权判断。
- 自动开启定位服务更新。
- 自动实现经纬度数据的转换。

```swift
import CoreLocation
import RxSwift
import RxCocoa
 
// 地理定位服务层
class GeolocationService {
    // 单例模式
    static let instance = GeolocationService()
     
    // 定位权限序列
    private (set) var authorized: Driver<Bool>
     
    // 经纬度信息序列
    private (set) var location: Driver<CLLocationCoordinate2D>
     
    // 定位管理器
    private let locationManager = CLLocationManager()
     
    private init() {
         
        // 更新距离
        locationManager.distanceFilter = kCLDistanceFilterNone
        // 设置定位精度
        locationManager.desiredAccuracy = kCLLocationAccuracyBestForNavigation
         
        // 获取定位权限序列
        authorized = Observable.deferred { [weak locationManager] in
                let status = CLLocationManager.authorizationStatus()
                guard let locationManager = locationManager else {
                    return Observable.just(status)
                }
                return locationManager
                    .rx.didChangeAuthorizationStatus
                    .startWith(status)
            }
            .asDriver(onErrorJustReturn: CLAuthorizationStatus.notDetermined)
            .map {
                switch $0 {
                case .authorizedAlways:
                    return true
                default:
                    return false
                }
        }
         
        // 获取经纬度信息序列
        location = locationManager.rx.didUpdateLocations
            .asDriver(onErrorJustReturn: [])
            .flatMap {
                return $0.last.map(Driver.just) ?? Driver.empty()
            }
            .map { $0.coordinate }
         
        // 发送授权申请
        locationManager.requestAlwaysAuthorization()
        // 允许使用定位服务的话，开启定位服务更新
        locationManager.startUpdatingLocation()
    }
}
```

#### 使用样例

（1）要获取定位信息，首先我们需要在 `info.plist` 里加入相关的定位描述：

- `Privacy - Location Always and When In Use Usage Description`：我们需要通过您的地理位置信息获取您周边的相关数据
- `Privacy - Location When In Use Usage Description`：我们需要通过您的地理位置信息获取您周边的相关数据

（2）Main.storyboard

在 `StoryBoard` 中添加一个`Label` 和 `Button`，分别用来显示经纬度信息，以及没有权限时的提示。并将它们与代码做 `@IBOutlet` 绑定。

（3）UILabel+Rx.swift

为了能让 `Label` 直接绑定显示经纬度信息，这里对其做个扩展。

```swift
import RxSwift
import RxCocoa
import CoreLocation
 
// UILabel的Rx扩展
extension Reactive where Base: UILabel {
    // 实现CLLocationCoordinate2D经纬度信息的绑定显示
    var coordinates: Binder<CLLocationCoordinate2D> {
        return Binder(base) { label, location in
            label.text = "经度: \(location.longitude)\n纬度: \(location.latitude)"
        }
    }
}
```

（4）ViewController.swift
主视图控制器代码如下，可以看到我们获取定位信息变得十分简单。

```swift
import UIKit
import RxSwift
import RxCocoa
 
class ViewController: UIViewController {
     
    @IBOutlet weak private var button: UIButton!
    @IBOutlet weak var label: UILabel!
 
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
        super.viewDidLoad()
         
        // 获取地理定位服务
        let geolocationService = GeolocationService.instance
         
        // 定位权限绑定到按钮上(是否可见)
        geolocationService.authorized
            .drive(button.rx.isHidden)
            .disposed(by: disposeBag)
         
        // 经纬度信息绑定到label上显示
        geolocationService.location
            .drive(label.rx.coordinates)
            .disposed(by: disposeBag)
         
        // 按钮点击
        button.rx.tap
            .bind { [weak self] _ -> Void in
                self?.openAppPreferences()
            }
            .disposed(by: disposeBag)
    }
     
    // 跳转到应有偏好的设置页面
    private func openAppPreferences() {
        UIApplication.shared.open(URL(string: UIApplicationOpenSettingsURLString)!)
    }
}
```





## 图片选择功能

接下来介绍的同样是 `RxSwift` 的官方样例，演示的是如何对 `UIImagePickerControllerDelegate` 进行 `Rx` 封装，方便我们在`RxSwift`项目中选择图片（可以通过拍照、或者从相簿中选取）



### 从本地相册、或摄像头获取图片

#### 准备工作

（1）`RxImagePickerDelegateProxy.swift`

首先我们继承 `DelegateProxy` 创建一个关于图片选择的代理委托，同时它还要遵守 `DelegateProxyType`、`UIImagePickerControllerDelegate`、`UINavigationControllerDelegate` 协议。

```swift
import RxSwift
import RxCocoa
import UIKit
 
// 图片选择控制器（UIImagePickerController）代理委托
public class RxImagePickerDelegateProxy :
    DelegateProxy<UIImagePickerController,
     UIImagePickerControllerDelegate & UINavigationControllerDelegate>,
    DelegateProxyType,
    UIImagePickerControllerDelegate,
    UINavigationControllerDelegate {
     
    public init(imagePicker: UIImagePickerController) {
        super.init(parentObject: imagePicker,
                   delegateProxy: RxImagePickerDelegateProxy.self)
    }
     
    public static func registerKnownImplementations() {
        self.register { RxImagePickerDelegateProxy(imagePicker: $0) }
    }
     
    public static func currentDelegate(for object: UIImagePickerController)
        -> (UIImagePickerControllerDelegate & UINavigationControllerDelegate)? {
            return object.delegate
    }
     
    public static func setCurrentDelegate(_ delegate: (UIImagePickerControllerDelegate
        & UINavigationControllerDelegate)?, to object: UIImagePickerController) {
        object.delegate = delegate
    }
}
```

（2）`UIImagePickerController+Rx.swift`

接着我们对 `UIImagePickerController` 进行 `Rx` 扩展，作用是将 `UIImagePickerController` 与前面创建的代理委托关联起来，将图片选择相关的 `delegate` 方法转为可观察序列。

注意：下面代码中将 `methodInvoked` 方法替换成 `sentMessage` 其实也可以。

```swift
import RxSwift
import RxCocoa
import UIKit
 
// 图片选择控制器（UIImagePickerController）的Rx扩展
extension Reactive where Base: UIImagePickerController {
     
    // 代理委托
    public var pickerDelegate: DelegateProxy<UIImagePickerController,
        UIImagePickerControllerDelegate & UINavigationControllerDelegate > {
        return RxImagePickerDelegateProxy.proxy(for: base)
    }
     
    // 图片选择完毕代理方法的封装
    public var didFinishPickingMediaWithInfo: Observable<[String : AnyObject]> {
         
        return pickerDelegate
            .methodInvoked(#selector(UIImagePickerControllerDelegate
                .imagePickerController(_:didFinishPickingMediaWithInfo:)))
            .map({ (a) in
                return try castOrThrow(Dictionary<String, AnyObject>.self, a[1])
            })
    }
     
    // 图片取消选择代理方法的封装
    public var didCancel: Observable<()> {
        return pickerDelegate
            .methodInvoked(#selector(UIImagePickerControllerDelegate
                .imagePickerControllerDidCancel(_:)))
            .map {_ in () }
    }
}
 
// 转类型的函数（转换失败后，会发出Error）
fileprivate func castOrThrow<T>(_ resultType: T.Type, _ object: Any) throws -> T {
    guard let returnValue = object as? T else {
        throw RxCocoaError.castingError(object: object, targetType: resultType)
    }
    return returnValue
}
```

#### 使用样例

（1）要获取照片或者进行拍照，首先我们需要在 `info.plist`里加入相关的描述：

- `Privacy - Camera Usage Description`：App 需要访问您的相机
- `Privacy - Photo Library Usage Description`：App 需要访问您的照片

（2）`Main.storyboard`

在 `StoryBoard`中添加 **3** 个 `Button` 以及 **1** 个 `ImageView`，并将它们与代码做 `@IBOutlet` 绑定。

（3）`ViewController.swift`

主视图控制器代码如下，可以看到原来图片选择完毕这个代理方法现在已经变成响应式的了。

```swift
import UIKit
import RxSwift
import RxCocoa
 
class ViewController: UIViewController {
     
    // 拍照按钮
    @IBOutlet weak var cameraButton: UIButton!
     
    // 选择照片按钮
    @IBOutlet weak var galleryButton: UIButton!
     
    // 选择照片并裁剪按钮
    @IBOutlet weak var cropButton: UIButton!
     
    // 显示照片的imageView
    @IBOutlet weak var imageView: UIImageView!
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
        super.viewDidLoad()
         
        // 初始化图片控制器
        let imagePicker = UIImagePickerController()
         
        // 判断并决定"拍照"按钮是否可用
        cameraButton.isEnabled = UIImagePickerController.isSourceTypeAvailable(.camera)
         
        // “拍照”按钮点击
        cameraButton.rx.tap
            .bind { [weak self] _ -> Void in
                imagePicker.sourceType = .camera // 来源为相机
                imagePicker.allowsEditing = false // 不可编辑
                // 弹出控制器，显示界面
                self?.present(imagePicker, animated: true)
            }
            .disposed(by: disposeBag)
         
        // “选择照片”按钮点击
        galleryButton.rx.tap
            .bind { [weak self] _ -> Void in
                imagePicker.sourceType = .photoLibrary // 来源为相册
                imagePicker.allowsEditing = false // 不可编辑
                // 弹出控制器，显示界面
                self?.present(imagePicker, animated: true)
            }
            .disposed(by: disposeBag)
         
        // “选择照片并裁剪”按钮点击
        cropButton.rx.tap
            .bind { [weak self] _ -> Void in
                imagePicker.sourceType = .photoLibrary // 来源为相册
                imagePicker.allowsEditing = true // 不可编辑
                // 弹出控制器，显示界面
                self?.present(imagePicker, animated: true)
            }
            .disposed(by: disposeBag)
         
        // 图片选择完毕后，将其绑定到imageView上显示
        imagePicker.rx.didFinishPickingMediaWithInfo
            .map { info in
                // 根据情况选择是使用原始图片还是编辑后的图片
                if imagePicker.allowsEditing {
                    return info[UIImagePickerControllerEditedImage] as! UIImage
                } else {
                    return info[UIImagePickerControllerOriginalImage] as! UIImage
                }
            }
            .bind(to: imageView.rx.image)
            .disposed(by: disposeBag)
         
        // 图片选择完毕后，退出图片控制器
        imagePicker.rx.didFinishPickingMediaWithInfo
            .subscribe(onNext: { _ in
                imagePicker.dismiss(animated: true)
            })
            .disposed(by: disposeBag)
    }
}
```



### 附：功能改进

虽然前面我们对 `UIImagePickerController` 进行了 `Rx` 扩展，但使用起来还是有些不便，比如图片选择完毕后还需要在代码中手动退出选择器。下面对它做个功能改进，让其可以自动关闭退出。

#### UIImagePickerController+RxCreate.swift

这里再一次对 `UIImagePickerController` 进行 `Rx` 扩展，增加一个创建图片选择控制器的静态方法，后面当我们使用该方法初始化 `ImagePickerController` 时会自动将其弹出显示，并且在选择完毕后会自动关闭。

```swift
import UIKit
import RxSwift
import RxCocoa
 
// 取消指定视图控制器函数
func dismissViewController(_ viewController: UIViewController, animated: Bool) {
    if viewController.isBeingDismissed || viewController.isBeingPresented {
        DispatchQueue.main.async {
            dismissViewController(viewController, animated: animated)
        }
        return
    }
     
    if viewController.presentingViewController != nil {
        viewController.dismiss(animated: animated, completion: nil)
    }
}
 
// 对UIImagePickerController进行Rx扩展
extension Reactive where Base: UIImagePickerController {
    // 用于创建并自动显示图片选择控制器的静态方法
    static func createWithParent(_ parent: UIViewController?,
        animated: Bool = true,
        configureImagePicker: @escaping (UIImagePickerController) throws -> () = { x in })
        -> Observable<UIImagePickerController> {
             
            // 返回可观察序列
            return Observable.create { [weak parent] observer in
                 
                // 初始化一个图片选择控制器
                let imagePicker = UIImagePickerController()
                 
                // 不管图片选择完毕还是取消选择，都会发出.completed事件
                let dismissDisposable = Observable.merge(
                        imagePicker.rx.didFinishPickingMediaWithInfo.map{_ in ()},
                        imagePicker.rx.didCancel
                    )
                    .subscribe(onNext: {  _ in
                        observer.on(.completed)
                    })
                 
                // 设置图片选择控制器初始参数，参数不正确则发出.error事件
                do {
                    try configureImagePicker(imagePicker)
                }
                catch let error {
                    observer.on(.error(error))
                    return Disposables.create()
                }
                 
                // 判断parent是否存在，不存在则发出.completed事件
                guard let parent = parent else {
                    observer.on(.completed)
                    return Disposables.create()
                }
                 
                // 弹出控制器，显示界面
                parent.present(imagePicker, animated: animated, completion: nil)
                // 发出.next事件（携带的是控制器对象）
                observer.on(.next(imagePicker))
                 
                // 销毁时自动退出图片控制器
                return Disposables.create(dismissDisposable, Disposables.create {
                    dismissViewController(imagePicker, animated: animated)
                })
            }
    }
}
```

#### ViewController.swift

主视图控制器代码如下，可以看到我们现在不需要去关心图片选择界面如何关闭了。

```swift
import UIKit
import RxSwift
import RxCocoa
 
class ViewController: UIViewController {
     
    // 拍照按钮
    @IBOutlet weak var cameraButton: UIButton!
     
    // 选择照片按钮
    @IBOutlet weak var galleryButton: UIButton!
     
    // 选择照片并裁剪按钮
    @IBOutlet weak var cropButton: UIButton!
     
    // 显示照片的imageView
    @IBOutlet weak var imageView: UIImageView!
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
        super.viewDidLoad()
         
        // 判断并决定"拍照"按钮是否可用
        cameraButton.isEnabled = UIImagePickerController.isSourceTypeAvailable(.camera)
         
        // “拍照”按钮点击
        cameraButton.rx.tap
            .flatMapLatest { [weak self] _ in
                return UIImagePickerController.rx.createWithParent(self) { picker in
                    picker.sourceType = .camera
                    picker.allowsEditing = false
                    }
                    .flatMap { $0.rx.didFinishPickingMediaWithInfo }
            }
            .map { info in
                return info[UIImagePickerControllerOriginalImage] as? UIImage
            }
            .bind(to: imageView.rx.image)
            .disposed(by: disposeBag)
         
        // “选择照片”按钮点击
        galleryButton.rx.tap
            .flatMapLatest { [weak self] _ in
                return UIImagePickerController.rx.createWithParent(self) { picker in
                    picker.sourceType = .photoLibrary
                    picker.allowsEditing = false
                    }
                    .flatMap { $0.rx.didFinishPickingMediaWithInfo }
            }
            .map { info in
                return info[UIImagePickerControllerOriginalImage] as? UIImage
            }
            .bind(to: imageView.rx.image)
            .disposed(by: disposeBag)
         
        // “选择照片并裁剪”按钮点击
        cropButton.rx.tap
            .flatMapLatest { [weak self] _ in
                return UIImagePickerController.rx.createWithParent(self) { picker in
                    picker.sourceType = .photoLibrary
                    picker.allowsEditing = true
                    }
                    .flatMap { $0.rx.didFinishPickingMediaWithInfo }
            }
            .map { info in
                return info[UIImagePickerControllerEditedImage] as? UIImage
            }
            .bind(to: imageView.rx.image)
            .disposed(by: disposeBag)
    }
}
```



## 应用生命周期的状态变化

我们知道 `UIApplicationDelegate` 协议中定义了关于程序启动各个过程的回调，比如：

- `applicationWillResignActive` 方法：在应用从活动状态进入非活动状态的时候会被调用（比如电话来了）。

- `applicationWillTerminate`方法：在应用终止的时候会被调用。

  过去我们通常都是在 `AppDelegate.swift` 里的相关回调方法中编写相应的业务逻辑。但一旦功能复杂些，这里就会变得十分混乱难以维护。而且有时想在其它模块中使用这些回调也不容易。

  本文演示如何通过对 `UIApplication` 进行 `Rx` 扩展，利用 `RxSwift` 的 `DelegateProxy` 实现 `UIApplicationDelegate` 相关回调方法的封装。从而让 `UIApplicationDelegate` 回调可以在任何模块中都可随时调用。

  

### 监测应用生命周期的状态变化

#### 准备工作

（1）`RxUIApplicationDelegateProxy.swift`

首先我们继承 `DelegateProxy` 创建一个关于应用生命周期变化的代理委托，同时它还要遵守 `DelegateProxyType`、`UIApplicationDelegate` 协议。

```swift
import RxSwift
import RxCocoa
import UIKit
 
// UIApplicationDelegate 代理委托
public class RxUIApplicationDelegateProxy :
    DelegateProxy<UIApplication, UIApplicationDelegate>,
    UIApplicationDelegate, DelegateProxyType {
     
    public weak private(set) var application: UIApplication?
     
    init(application: ParentObject) {
        self.application = application
        super.init(parentObject: application, delegateProxy: RxUIApplicationDelegateProxy.self)
    }
     
    public static func registerKnownImplementations() {
        self.register { RxUIApplicationDelegateProxy(application: $0) }
    }
     
    public static func currentDelegate(for object: UIApplication) -> UIApplicationDelegate? {
        return object.delegate
    }
     
    public static func setCurrentDelegate(_ delegate: UIApplicationDelegate?,
                                          to object: UIApplication) {
        object.delegate = delegate
    }
     
    override open func setForwardToDelegate(_ forwardToDelegate: UIApplicationDelegate?,
                                            retainDelegate: Bool) {
        super.setForwardToDelegate(forwardToDelegate, retainDelegate: true)
    }
}
```

（2）`UIApplication+Rx.swift`

接着我们对 `UIApplication` 进行 `Rx` 扩展，作用是将 `UIApplication` 与前面创建的代理委托关联起来，将状态变化相关的 `delegate` 方法转为可观察序列。

注意1：我们在开头自定义了一个表示应用状态枚举（`AppState`），不使用系统自带的的 `UIApplicationState` 是因为后者没有 `terminated`（终止）这个状态。

注意2：下面代码中将 `methodInvoked` 方法替换成 `sentMessage` 其实也可以。

```swift
import RxSwift
import RxCocoa
import UIKit
 
// 自定义应用状态枚举
public enum AppState {
    case active
    case inactive
    case background
    case terminated
}
 
// 扩展
extension UIApplication.State {
    // 将其转为我们自定义的应用状态枚举
    func toAppState() -> AppState{
        switch self {
        case .active:
            return .active
        case .inactive:
            return .inactive
        case .background:
            return .background
        }
    }
}
 
// UIApplication的Rx扩展
extension Reactive where Base: UIApplication {
     
    // 代理委托
    var delegate: DelegateProxy<UIApplication, UIApplicationDelegate> {
        return RxUIApplicationDelegateProxy.proxy(for: base)
    }
     
    // 应用重新回到活动状态
    var didBecomeActive: Observable<AppState> {
        return delegate
            .methodInvoked(#selector(UIApplicationDelegate.applicationDidBecomeActive(_:)))
            .map{ _ in return .active}
    }
     
    // 应用从活动状态进入非活动状态
    var willResignActive: Observable<AppState> {
        return delegate
            .methodInvoked(#selector(UIApplicationDelegate.applicationWillResignActive(_:)))
            .map{ _ in return .inactive}
    }
     
    // 应用从后台恢复至前台（还不是活动状态）
    var willEnterForeground: Observable<AppState> {
        return delegate
            .methodInvoked(#selector(UIApplicationDelegate.applicationWillEnterForeground(_:)))
            .map{ _ in return .inactive}
    }
     
    // 应用进入到后台
    var didEnterBackground: Observable<AppState> {
        return delegate
            .methodInvoked(#selector(UIApplicationDelegate.applicationDidEnterBackground(_:)))
            .map{ _ in return .background}
    }
     
    // 应用终止
    var willTerminate: Observable<AppState> {
        return delegate
            .methodInvoked(#selector(UIApplicationDelegate.applicationWillTerminate(_:)))
            .map{ _ in return .terminated}
    }
     
    // 应用各状态变换序列
    var state: Observable<AppState> {
        return Observable.of(
            didBecomeActive,
            willResignActive,
            willEnterForeground,
            didEnterBackground,
            willTerminate
            )
            .merge()
            .startWith(base.applicationState.toAppState()) // 为了让开始订阅时就能获取到当前状态
    }
}
```



#### 使用样例1

（1）我们可以对各个状态变化行为分别进行订阅：

```swift
import UIKit
import RxSwift
import RxCocoa
 
class ViewController: UIViewController {
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
        super.viewDidLoad()
         
        // 应用重新回到活动状态
        UIApplication.shared.rx
            .didBecomeActive
            .subscribe(onNext: { _ in
                print("应用进入活动状态。")
            })
            .disposed(by: disposeBag)
         
        // 应用从活动状态进入非活动状态
        UIApplication.shared.rx
            .willResignActive
            .subscribe(onNext: { _ in
                print("应用从活动状态进入非活动状态。")
            })
            .disposed(by: disposeBag)
         
        // 应用从后台恢复至前台（还不是活动状态）
        UIApplication.shared.rx
            .willEnterForeground
            .subscribe(onNext: { _ in
                print("应用从后台恢复至前台（还不是活动状态）。")
            })
            .disposed(by: disposeBag)
         
        // 应用进入到后台
        UIApplication.shared.rx
            .didEnterBackground
            .subscribe(onNext: { _ in
                print("应用进入到后台。")
            })
            .disposed(by: disposeBag)
         
        // 应用终止
        UIApplication.shared.rx
            .willTerminate
            .subscribe(onNext: { _ in
                print("应用终止。")
            })
            .disposed(by: disposeBag)
    }
}
```

（2）我们进行在如下一系列操作后，控制台里内容如下：

- 编译运行程序
- 按下 `home` 键程序进入后台
- 双击 `home` 键，选择程序并回到前台

#### 使用样例2

（1）我们也可以对状态变化序列进行订阅：

```swift
import UIKit
import RxSwift
import RxCocoa
 
class ViewController: UIViewController {
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
        super.viewDidLoad()
         
         UIApplication.shared.rx
             .state
             .subscribe(onNext: { state in
                 switch state {
                 case .active:
                     print("应用进入活动状态。")
                 case .inactive:
                     print("应用从后台准备进入活动状态，或准备进入非活动状态。")
                 case .background:
                     print("应用进入到后台。")
                 case .terminated:
                     print("应用终止。")
                 }
             })
             .disposed(by: disposeBag)
    }
}
```

（2）我们进行在如下一系列操作后，控制台里内容如下：

- 编译运行程序
- 按下 `home` 键程序进入后台
- 双击 `home` 键，选择程序并回到前台



