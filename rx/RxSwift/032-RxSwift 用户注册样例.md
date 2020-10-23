# RxSwift - 用户注册样例



## 登录样例

本文同样是一个 `MVVM` 架构的样例（使用 `Driver`）。主要实现输入内容的条件验证，以及验证结果与视图的绑定。

#### 效果

- 输入用户名时会同步检查该用户名是否符合条件（只能为数字或字母），以及是否已存在（网络请求），并在输入框下方显示验证结果。
- 输入密码时会检查密码是否符合条件（最少要 5 位），并在输入框下方显示验证结果。
- 再次输入密码时会检查两个密码是否一致，并在输入框下方显示验证结果。

#### 网络请求服务

首先将网络请求：验证用户名是否存在，用户注册封装起来（`GitHubNetworkService.swift`），方便后面使用。

```swift
import Foundation
import RxSwift
 
// GitHub网络请求服务
class GitHubNetworkService {
     
    // 验证用户是否存在
    func usernameAvailable(_ username: String) -> Observable<Bool> {
        // 通过检查这个用户的GitHub主页是否存在来判断用户是否存在
        let url = URL(string: "https://github.com/\(username.URLEscaped)")!
        let request = URLRequest(url: url)
        return URLSession.shared.rx.response(request: request)
            .map { pair in
                // 如果不存在该用户主页，则说明这个用户名可用
                return pair.response.statusCode == 404
            }
            .catchErrorJustReturn(false)
    }
     
    // 注册用户
    func signup(_ username: String, password: String) -> Observable<Bool> {
        // 这里我们没有真正去发起请求，而是模拟这个操作（平均每3次有1次失败）
        let signupResult = arc4random() % 3 == 0 ? false : true
        return Observable.just(signupResult)
            .delay(1.5, scheduler: MainScheduler.instance) // 结果延迟1.5秒返回
    }
}
 
// 扩展String
extension String {
    // 字符串的url地址转义
    var URLEscaped: String {
        return self.addingPercentEncoding(withAllowedCharacters: .urlHostAllowed) ?? ""
    }
}
```

#### 用户注册验证服务

（1）首先定义一个用于表示验证结果和信息的枚举（`ValidationResult`），后面我们会将它作为验证结果绑定到界面上。

```swift
import UIKit
 
// 验证结果和信息的枚举
enum ValidationResult {
    case validating  // 正在验证中
    case empty  // 输入为空
    case ok(message: String) // 验证通过
    case failed(message: String)  // 验证失败
}
 
// 扩展ValidationResult，对应不同的验证结果返回验证是成功还是失败
extension ValidationResult {
    var isValid: Bool {
        switch self {
        case .ok:
            return true
        default:
            return false
        }
    }
}
 
// 扩展ValidationResult，对应不同的验证结果返回不同的文字描述
extension ValidationResult: CustomStringConvertible {
    var description: String {
        switch self {
        case .validating:
            return "正在验证..."
        case .empty:
            return ""
        case let .ok(message):
            return message
        case let .failed(message):
            return message
        }
    }
}
 
// 扩展ValidationResult，对应不同的验证结果返回不同的文字颜色
extension ValidationResult {
    var textColor: UIColor {
        switch self {
        case .validating:
            return UIColor.gray
        case .empty:
            return UIColor.black
        case .ok:
            return UIColor(red: 0/255, green: 130/255, blue: 0/255, alpha: 1)
        case .failed:
            return UIColor.red
        }
    }
}
```

（2）接着将用户名、密码等各种需要用到的验证封装起来（`GitHubSignupService.swift`），方便后面使用。（返回的就是上面定义的 `ValidationResult`）

```swift
import UIKit
import RxSwift
 
// 用户注册服务
class GitHubSignupService {
     
    // 密码最少位数
    let minPasswordCount = 5
     
    // 网络请求服务
    lazy var networkService = {
        return GitHubNetworkService()
    }()
     
    // 验证用户名
    func validateUsername(_ username: String) -> Observable<ValidationResult> {
        // 判断用户名是否为空
        if username.isEmpty {
            return .just(.empty)
        }
         
        // 判断用户名是否只有数字和字母
        if username.rangeOfCharacter(from: CharacterSet.alphanumerics.inverted) != nil {
            return .just(.failed(message: "用户名只能包含数字和字母"))
        }
         
        // 发起网络请求检查用户名是否已存在
        return networkService
            .usernameAvailable(username)
            .map { available in
                // 根据查询情况返回不同的验证结果
                if available {
                    return .ok(message: "用户名可用")
                } else {
                    return .failed(message: "用户名已存在")
                }
            }
            .startWith(.validating) // 在发起网络请求前，先返回一个“正在检查”的验证结果
    }
     
    // 验证密码
    func validatePassword(_ password: String) -> ValidationResult {
        let numberOfCharacters = password.count
         
        // 判断密码是否为空
        if numberOfCharacters == 0 {
            return .empty
        }
         
        // 判断密码位数
        if numberOfCharacters < minPasswordCount {
            return .failed(message: "密码至少需要 \(minPasswordCount) 个字符")
        }
         
        // 返回验证成功的结果
        return .ok(message: "密码有效")
    }
     
    // 验证二次输入的密码
    func validateRepeatedPassword(_ password: String, repeatedPassword: String)
        -> ValidationResult {
        // 判断密码是否为空
        if repeatedPassword.count == 0 {
            return .empty
        }
         
        // 判断两次输入的密码是否一致
        if repeatedPassword == password {
            return .ok(message: "密码有效")
        } else {
            return .failed(message: "两次输入的密码不一致")
        }
    }
}
```

#### ViewModel 定义

下面是本文的重点，我们创建一个用户注册页面的 `ViewModel（GitHubSignupViewModel.swift）`，它的作用就是将用户各种输入行为，转换成输出状态。

```swift
import RxSwift
import RxCocoa
 
class GitHubSignupViewModel {
     
    // 用户名验证结果
    let validatedUsername: Driver<ValidationResult>
     
    // 密码验证结果
    let validatedPassword: Driver<ValidationResult>
     
    // 再次输入密码验证结果
    let validatedPasswordRepeated: Driver<ValidationResult>
     
    // 注册按钮是否可用
    let signupEnabled: Driver<Bool>
     
    // 注册结果
    let signupResult: Driver<Bool>
     
    // ViewModel初始化（根据输入实现对应的输出）
    init(
        input: (
        username: Driver<String>,
        password: Driver<String>,
        repeatedPassword: Driver<String>,
        loginTaps: Signal<Void>
        ),
        dependency: (
        networkService: GitHubNetworkService,
        signupService: GitHubSignupService
        )) {
         
        // 用户名验证
        validatedUsername = input.username
            .flatMapLatest { username in
                return dependency.signupService.validateUsername(username)
                    .asDriver(onErrorJustReturn: .failed(message: "服务器发生错误!"))
        }
         
        // 用户名密码验证
        validatedPassword = input.password
            .map { password in
                return dependency.signupService.validatePassword(password)
        }
         
        // 重复输入密码验证
        validatedPasswordRepeated = Driver.combineLatest(
            input.password,
            input.repeatedPassword,
            resultSelector: dependency.signupService.validateRepeatedPassword)
         
        // 注册按钮是否可用
        signupEnabled = Driver.combineLatest(
            validatedUsername,
            validatedPassword,
            validatedPasswordRepeated
        ) { username, password, repeatPassword in
            username.isValid && password.isValid && repeatPassword.isValid
            }
            .distinctUntilChanged()
         
        // 获取最新的用户名和密码
        let usernameAndPassword = Driver.combineLatest(input.username, input.password) {
            (username: $0, password: $1) }
         
        // 注册按钮点击结果
        signupResult = input.loginTaps.withLatestFrom(usernameAndPassword)
            .flatMapLatest { pair in
                return dependency.networkService.signup(pair.username,
                                                        password: pair.password)
                    .asDriver(onErrorJustReturn: false)
        }
    }
}
```

#### ViewModel 与视图的绑定

（1）首先为了让 `ValidationResult` 能绑定到 `label` 上，我们要对 `UILabel` 进行扩展（`BindingExtensions.swift`）

```swift
import UIKit
import RxSwift
import RxCocoa
 
// 扩展UILabel
extension Reactive where Base: UILabel {
    // 让验证结果（ValidationResult类型）可以绑定到label上
    var validationResult: Binder<ValidationResult> {
        return Binder(base) { label, result in
            label.textColor = result.textColor
            label.text = result.description
        }
    }
}
```

（2）最后在主视图控制器中使用 `ViewModel` 进行绑定即可。

```swift
import UIKit
import RxSwift
import RxCocoa
 
class ViewController: UIViewController {
    // 用户名输入框、以及验证结果显示标签
    @IBOutlet weak var usernameOutlet: UITextField!
    @IBOutlet weak var usernameValidationOutlet: UILabel!
     
    // 密码输入框、以及验证结果显示标签
    @IBOutlet weak var passwordOutlet: UITextField!
    @IBOutlet weak var passwordValidationOutlet: UILabel!
     
    // 重复密码输入框、以及验证结果显示标签
    @IBOutlet weak var repeatedPasswordOutlet: UITextField!
    @IBOutlet weak var repeatedPasswordValidationOutlet: UILabel!
     
    // 注册按钮
    @IBOutlet weak var signupOutlet: UIButton!
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
        super.viewDidLoad()
         
        // 初始化ViewModel
        let viewModel = GitHubSignupViewModel(
            input: (
                username: usernameOutlet.rx.text.orEmpty.asDriver(),
                password: passwordOutlet.rx.text.orEmpty.asDriver(),
                repeatedPassword: repeatedPasswordOutlet.rx.text.orEmpty.asDriver(),
                loginTaps: signupOutlet.rx.tap.asSignal()
            ),
            dependency: (
                networkService: GitHubNetworkService(),
                signupService: GitHubSignupService()
            )
        )
         
        // 用户名验证结果绑定
        viewModel.validatedUsername
            .drive(usernameValidationOutlet.rx.validationResult)
            .disposed(by: disposeBag)
         
        // 密码验证结果绑定
        viewModel.validatedPassword
            .drive(passwordValidationOutlet.rx.validationResult)
            .disposed(by: disposeBag)
         
        // 再次输入密码验证结果绑定
        viewModel.validatedPasswordRepeated
            .drive(repeatedPasswordValidationOutlet.rx.validationResult)
            .disposed(by: disposeBag)
         
        // 注册按钮是否可用
        viewModel.signupEnabled
            .drive(onNext: { [weak self] valid  in
                self?.signupOutlet.isEnabled = valid
                self?.signupOutlet.alpha = valid ? 1.0 : 0.3
            })
            .disposed(by: disposeBag)
         
        // 注册结果绑定
        viewModel.signupResult
            .drive(onNext: { [unowned self] result in
                self.showMessage("注册" + (result ? "成功" : "失败") + "!")
            })
            .disposed(by: disposeBag)
    }
     
    // 详细提示框
    func showMessage(_ message: String) {
        let alertController = UIAlertController(title: nil,
                                                message: message, preferredStyle: .alert)
        let okAction = UIAlertAction(title: "确定", style: .cancel, handler: nil)
        alertController.addAction(okAction)
        self.present(alertController, animated: true, completion: nil)
    }
}
```



## 显示网络请求活动指示器

#### 引入 ActivityIndicator

（1）`ActivityIndicator` 类可不是苹果自带的 `UIActivityIndicator`，它是一个用来监测是否有序列正在发送元素的类：

- 如果至少还有一个序列正在工作，那么它会返回一个 `true`。
- 如果没有序列在工作了，那么它会返回一个 `false` 值。

（2）默认情况下项目引入的 `RxSwift` 和 `RxCocoa` 库中是不会有个类的，我们需要手动将 `RxSwift` 源码包中的 `RxExample/Services/ActivityIndicator.swift` 这个文件添加到我们项目中来。

#### 修改 ViewModel

（1）接着对前文的 `GitHubSignupViewModel` 做个修改，增加了个 `signingIn` 序列，用于表示当前是否正在“发请求注册中”。

（2）我们在请求序列中使用 `trackActivity` 方法可以把这个请求序列放入制定的 `activityIndicator` 中进行监测，监测结果则做为 `signingIn` 序列。

```swift
import RxSwift
import RxCocoa
 
class GitHubSignupViewModel {
     
    // 用户名验证结果
    let validatedUsername: Driver<ValidationResult>
     
    // 密码验证结果
    let validatedPassword: Driver<ValidationResult>
     
    // 再次输入密码验证结果
    let validatedPasswordRepeated: Driver<ValidationResult>
     
    // 注册按钮是否可用
    let signupEnabled: Driver<Bool>
     
    // 正在注册中
    let signingIn: Driver<Bool>
     
    // 注册结果
    let signupResult: Driver<Bool>
     
    // ViewModel初始化（根据输入实现对应的输出）
    init(
        input: (
        username: Driver<String>,
        password: Driver<String>,
        repeatedPassword: Driver<String>,
        loginTaps: Signal<Void>
        ),
        dependency: (
        networkService: GitHubNetworkService,
        signupService: GitHubSignupService
        )) {
         
        // 用户名验证
        validatedUsername = input.username
            .flatMapLatest { username in
                return dependency.signupService.validateUsername(username)
                    .asDriver(onErrorJustReturn: .failed(message: "服务器发生错误!"))
        }
          
        // 用户名密码验证
        validatedPassword = input.password
            .map { password in
                return dependency.signupService.validatePassword(password)
        }
         
        // 重复输入密码验证
        validatedPasswordRepeated = Driver.combineLatest(
            input.password,
            input.repeatedPassword,
            resultSelector: dependency.signupService.validateRepeatedPassword)
         
        // 注册按钮是否可用
        signupEnabled = Driver.combineLatest(
            validatedUsername,
            validatedPassword,
            validatedPasswordRepeated
        ) { username, password, repeatPassword in
            username.isValid && password.isValid && repeatPassword.isValid
            }
            .distinctUntilChanged()
         
        // 获取最新的用户名和密码
        let usernameAndPassword = Driver.combineLatest(input.username, input.password) {
            (username: $0, password: $1) }
         
        // 用于检测是否正在请求数据
        let activityIndicator = ActivityIndicator()
        self.signingIn = activityIndicator.asDriver()
         
        // 注册按钮点击结果
        signupResult = input.loginTaps.withLatestFrom(usernameAndPassword)
            .flatMapLatest { pair in
                return dependency.networkService.signup(pair.username,
                                                        password: pair.password)
                    .trackActivity(activityIndicator) // 把当前序列放入signing序列中进行检测
                    .asDriver(onErrorJustReturn: false)
        }
    }
}
```



## 顶部状态栏联网指示器的绑定

#### 样例代码

这个只需要在主视图控制器中将 `signingIn` 绑定到 `UIApplication` 的 `isNetworkActivityIndicatorVisible` 属性上即可。

```swift
import UIKit
import RxSwift
import RxCocoa
 
class ViewController: UIViewController {
    // 用户名输入框、以及验证结果显示标签
    @IBOutlet weak var usernameOutlet: UITextField!
    @IBOutlet weak var usernameValidationOutlet: UILabel!
     
    // 密码输入框、以及验证结果显示标签
    @IBOutlet weak var passwordOutlet: UITextField!
    @IBOutlet weak var passwordValidationOutlet: UILabel!
     
    // 重复密码输入框、以及验证结果显示标签
    @IBOutlet weak var repeatedPasswordOutlet: UITextField!
    @IBOutlet weak var repeatedPasswordValidationOutlet: UILabel!
     
    // 注册按钮
    @IBOutlet weak var signupOutlet: UIButton!
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
        super.viewDidLoad()
         
        // 初始化ViewModel
        let viewModel = GitHubSignupViewModel(
            input: (
                username: usernameOutlet.rx.text.orEmpty.asDriver(),
                password: passwordOutlet.rx.text.orEmpty.asDriver(),
                repeatedPassword: repeatedPasswordOutlet.rx.text.orEmpty.asDriver(),
                loginTaps: signupOutlet.rx.tap.asSignal()
            ),
            dependency: (
                networkService: GitHubNetworkService(),
                signupService: GitHubSignupService()
            )
        )
         
        // 用户名验证结果绑定
        viewModel.validatedUsername
            .drive(usernameValidationOutlet.rx.validationResult)
            .disposed(by: disposeBag)
         
        // 密码验证结果绑定
        viewModel.validatedPassword
            .drive(passwordValidationOutlet.rx.validationResult)
            .disposed(by: disposeBag)
         
        // 再次输入密码验证结果绑定
        viewModel.validatedPasswordRepeated
            .drive(repeatedPasswordValidationOutlet.rx.validationResult)
            .disposed(by: disposeBag)
         
        // 注册按钮是否可用
        viewModel.signupEnabled
            .drive(onNext: { [weak self] valid  in
                self?.signupOutlet.isEnabled = valid
                self?.signupOutlet.alpha = valid ? 1.0 : 0.3
            })
            .disposed(by: disposeBag)
         
        // 当前是否正在注册
        viewModel.signingIn
            .drive(UIApplication.shared.rx.isNetworkActivityIndicatorVisible)
            .disposed(by: disposeBag)
         
        // 注册结果绑定
        viewModel.signupResult
            .drive(onNext: { [unowned self] result in
                self.showMessage("注册" + (result ? "成功" : "失败") + "!")
            })
            .disposed(by: disposeBag)
    }
     
    // 详细提示框
    func showMessage(_ message: String) {
        let alertController = UIAlertController(title: nil,
                                                message: message, preferredStyle: .alert)
        let okAction = UIAlertAction(title: "确定", style: .cancel, handler: nil)
        alertController.addAction(okAction)
        self.present(alertController, animated: true, completion: nil)
    }
}
```



## UIActivityIndicatorView 的绑定

#### 样例代码

在主视图控制器中将 `signingIn` 绑定到 `Activity Indicator View` 的 `isAnimating` 属性上。

```swift
import UIKit
import RxSwift
import RxCocoa
 
class ViewController: UIViewController {
    // 用户名输入框、以及验证结果显示标签
    @IBOutlet weak var usernameOutlet: UITextField!
    @IBOutlet weak var usernameValidationOutlet: UILabel!
     
    // 密码输入框、以及验证结果显示标签
    @IBOutlet weak var passwordOutlet: UITextField!
    @IBOutlet weak var passwordValidationOutlet: UILabel!
     
    // 重复密码输入框、以及验证结果显示标签
    @IBOutlet weak var repeatedPasswordOutlet: UITextField!
    @IBOutlet weak var repeatedPasswordValidationOutlet: UILabel!
     
    // 注册按钮
    @IBOutlet weak var signupOutlet: UIButton!
     
    // 注册时的活动指示器
    @IBOutlet weak var signInActivityIndicator: UIActivityIndicatorView!
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
        super.viewDidLoad()
         
        // 初始化ViewModel
        let viewModel = GitHubSignupViewModel(
            input: (
                username: usernameOutlet.rx.text.orEmpty.asDriver(),
                password: passwordOutlet.rx.text.orEmpty.asDriver(),
                repeatedPassword: repeatedPasswordOutlet.rx.text.orEmpty.asDriver(),
                loginTaps: signupOutlet.rx.tap.asSignal()
            ),
            dependency: (
                networkService: GitHubNetworkService(),
                signupService: GitHubSignupService()
            )
        )
         
        // 用户名验证结果绑定
        viewModel.validatedUsername
            .drive(usernameValidationOutlet.rx.validationResult)
            .disposed(by: disposeBag)
         
        // 密码验证结果绑定
        viewModel.validatedPassword
            .drive(passwordValidationOutlet.rx.validationResult)
            .disposed(by: disposeBag)
         
        // 再次输入密码验证结果绑定
        viewModel.validatedPasswordRepeated
            .drive(repeatedPasswordValidationOutlet.rx.validationResult)
            .disposed(by: disposeBag)
         
        // 注册按钮是否可用
        viewModel.signupEnabled
            .drive(onNext: { [weak self] valid  in
                self?.signupOutlet.isEnabled = valid
                self?.signupOutlet.alpha = valid ? 1.0 : 0.3
            })
            .disposed(by: disposeBag)
         
        // 当前是否正在注册
        viewModel.signingIn
            .drive(signInActivityIndicator.rx.isAnimating)
            .disposed(by: disposeBag)
         
        // 注册结果绑定
        viewModel.signupResult
            .drive(onNext: { [unowned self] result in
                self.showMessage("注册" + (result ? "成功" : "失败") + "!")
            })
            .disposed(by: disposeBag)
    }
     
    // 详细提示框
    func showMessage(_ message: String) {
        let alertController = UIAlertController(title: nil,
                                                message: message, preferredStyle: .alert)
        let okAction = UIAlertAction(title: "确定", style: .cancel, handler: nil)
        alertController.addAction(okAction)
        self.present(alertController, animated: true, completion: nil)
    }
}
```



## 第三方指示器的绑定

这里以 `MBProgressHUD` 这个第三方透明指示器为例做演示

#### 样例代码

```swift
import UIKit
import RxSwift
import RxCocoa
 
class ViewController: UIViewController {
    // 用户名输入框、以及验证结果显示标签
    @IBOutlet weak var usernameOutlet: UITextField!
    @IBOutlet weak var usernameValidationOutlet: UILabel!
     
    // 密码输入框、以及验证结果显示标签
    @IBOutlet weak var passwordOutlet: UITextField!
    @IBOutlet weak var passwordValidationOutlet: UILabel!
     
    // 重复密码输入框、以及验证结果显示标签
    @IBOutlet weak var repeatedPasswordOutlet: UITextField!
    @IBOutlet weak var repeatedPasswordValidationOutlet: UILabel!
     
    // 注册按钮
    @IBOutlet weak var signupOutlet: UIButton!
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
        super.viewDidLoad()
         
        // 初始化ViewModel
        let viewModel = GitHubSignupViewModel(
            input: (
                username: usernameOutlet.rx.text.orEmpty.asDriver(),
                password: passwordOutlet.rx.text.orEmpty.asDriver(),
                repeatedPassword: repeatedPasswordOutlet.rx.text.orEmpty.asDriver(),
                loginTaps: signupOutlet.rx.tap.asSignal()
            ),
            dependency: (
                networkService: GitHubNetworkService(),
                signupService: GitHubSignupService()
            )
        )
         
        // 用户名验证结果绑定
        viewModel.validatedUsername
            .drive(usernameValidationOutlet.rx.validationResult)
            .disposed(by: disposeBag)
         
        // 密码验证结果绑定
        viewModel.validatedPassword
            .drive(passwordValidationOutlet.rx.validationResult)
            .disposed(by: disposeBag)
         
        // 再次输入密码验证结果绑定
        viewModel.validatedPasswordRepeated
            .drive(repeatedPasswordValidationOutlet.rx.validationResult)
            .disposed(by: disposeBag)
         
        // 注册按钮是否可用
        viewModel.signupEnabled
            .drive(onNext: { [weak self] valid  in
                self?.signupOutlet.isEnabled = valid
                self?.signupOutlet.alpha = valid ? 1.0 : 0.3
            })
            .disposed(by: disposeBag)
         
        // 创建一个指示器
        let hud = MBProgressHUD.showAdded(to: self.view, animated: true)
         
        // 当前是否正在注册，决定指示器是否显示
        viewModel.signingIn
            .map{ !$0 }
            .drive(hud.rx.isHidden)
            .disposed(by: disposeBag)
      
        // 注册结果绑定
        viewModel.signupResult
            .drive(onNext: { [unowned self] result in
                self.showMessage("注册" + (result ? "成功" : "失败") + "!")
            })
            .disposed(by: disposeBag)
    }
     
    // 详细提示框
    func showMessage(_ message: String) {
        let alertController = UIAlertController(title: nil,
                                                message: message, preferredStyle: .alert)
        let okAction = UIAlertAction(title: "确定", style: .cancel, handler: nil)
        alertController.addAction(okAction)
        self.present(alertController, animated: true, completion: nil)
    }
}
```









