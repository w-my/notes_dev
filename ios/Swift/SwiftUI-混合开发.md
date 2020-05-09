# SwiftUI-混合开发

在目前阶段，SwiftUI 很难独立开发一款功能强大的 App，还是需要与 UIKit 一起合作，借助 UIKit 成熟完善的知识体系，二者相互嵌套形成混合开发。

## UIKit in SwiftUI

| UIKit            | SwiftUI                       |
| :--------------- | :---------------------------- |
| UIView           | UIViewRepresentable           |
| UIViewController | UIViewControllerRepresentable |

### UIViewRepresentable

- 要使 UIView 在 SwiftUI 中可用，需要用`UIViewRepresentable`对 UIView 进行包装。

- ```swfit
  UIViewRepresentable
  ```

  中主要有两个方法需要实现：

  - `makeUIView`：创建`View`。
  - `updateUIView`：根据条件和业务逻辑设置`View`的状态。

- 案例一

  ```swift
  import SwiftUI
  import UIKit
  
  struct ActivityIndicator: UIViewRepresentable {
      var isAnimating: Bool
  
      func makeUIView(context: Context) -> UIActivityIndicatorView {
          let v = UIActivityIndicatorView()
          v.color = .orange
          return v
      }
  
      func updateUIView(_ uiView: UIActivityIndicatorView, context: Context) {
          if isAnimating {
              uiView.startAnimating()
          } else {
              uiView.stopAnimating()
          }
      }
  }
  
  struct ContentView : View {
      var isAnimating: Bool = true  
      var body: some View {
          ActivityIndicator(isAnimating: isAnimating)
      }
  }
  ```

- 案例二

  ```swift
  import UIKit
  import SwiftUI
  import MapKit
  
  struct Map: UIViewRepresentable {
  
      var locationManager:CLLocationManager = CLLocationManager()
  
      func setupManager(){
  
          locationManager.desiredAccuracy = kCLLocationAccuracyBest  
          locationManager.requestWhenInUseAuthorization()
          locationManager.requestAlwaysAuthorization()
      }
  
      func makeUIView(context: Context) -> MKMapView {
          self.setupManager() 
        
          let map = MKMapView(frame: UIScreen.main.bounds)
          map.showsUserLocation = true    
          map.userTrackingMode = .followWithHeading 
          return map
      }
  
      func updateUIView(_ uiView: MKMapView, context: Context) {
  
      }
  }
  
  struct ContentView : View {
      var body: some View {
          Map()
      }
  }
  ```

- 案例三

  ```swift
  // 定义一个类负责实现代理
  class TextFieldDelegate: NSObject, UITextFieldDelegate {
  
      func textFieldDidBeginEditing(_ textField: UITextField) {
          print("开始编辑")
      }
  }
  
  // 定义UIViewRepresentable
  struct MyTextField: UIViewRepresentable {
  
      var text: String
      var placeholder: String  
      private let delegate = TextFieldDelegate()
  
      func makeUIView(context: UIViewRepresentableContext<MyTextField>) -> UITextField {
          let tmpView = UITextField()
          tmpView.text = text
          tmpView.borderStyle = .roundedRect
          tmpView.placeholder = placeholder
          tmpView.delegate = delegate
          return tmpView
      }
  
      func updateUIView(_ uiView: UITextField, context: UIViewRepresentableContext<MyTextField>) {
      }
  }
  
  // SwiftUI使用
  struct ContentView : View {
      var body: some View {        
          MyTextField(text: "", placeholder: "请输入内容").frame(height: 40).padding()
      }
  }
  ```

- 如果要桥接 UIKit 的数据绑定（Delegate，Target/Action），需要使用`Coordinator`进行协调。

  ```swift
  import SwiftUI
  import UIKit
  
  // 自定义个SegmentControl控件
  struct SegmentControl: UIViewRepresentable {
  
      @Binding var selectedSegmentIndex: Int
  
      // 下面两个方法都是和 UIKit 相关
      func makeUIView(context: Context) -> UISegmentedControl {
  
          let segmentControl = UISegmentedControl()
          segmentControl.insertSegment(withTitle: "红", at: 0, animated: true)
          segmentControl.insertSegment(withTitle: "黄", at: 1, animated: true)
          segmentControl.insertSegment(withTitle: "蓝", at: 2, animated: true)
          segmentControl.selectedSegmentIndex = selectedSegmentIndex
  
          // 注意这里的参数，与Coordinator有关
          segmentControl.addTarget(
              context.coordinator,
              action: #selector(Coordinator.updateCurrentPage(sender:)),
              for: .valueChanged)
  
          return segmentControl
      }
  
      func updateUIView(_ uiView: UISegmentedControl, context: Context) {
          uiView.selectedSegmentIndex = selectedSegmentIndex
      }
  
      // 协议的方法之一，返回一个协调器
      func makeCoordinator() -> Coordinator {
          Coordinator(self)
      }
  
      // 自定义协调器，UIKit与SwiftUI交互的地方
      class Coordinator: NSObject {
          var control: SegmentControl
  
          init(_ control: SegmentControl) {
              self.control = control
          }
  
          @objc func updateCurrentPage(sender: UISegmentedControl) {
              control.selectedSegmentIndex = sender.selectedSegmentIndex
          }
      }
  }
  
  struct ContentView : View {
      @State private var selectedSegmentIndex: Int = 1
      var body: some View {
          SegmentControl(selectedSegmentIndex: $selectedSegmentIndex)
      }
  }
  ```

### UIViewControllerRepresentable

- 要使 UIViewController 在 SwiftUI 中可用，需要用`UIViewControllerRepresentable`对 UIViewController 进行包装。

- ```
  UIViewControllerRepresentable
  ```

  中主要有两个方法需要实现：

  - `makeUIViewController`：创建`UIViewController`。
  - `updateUIViewController`：根据条件和业务逻辑设置`UIViewController`的状态。

- 案例

```swift
import SwiftUI
import UIKit

struct NavigationViewController: UIViewControllerRepresentable {

    var vc: UIViewController
    var title: String

    func makeUIViewController(context: Context) -> UINavigationController {
        let nvc = UINavigationController(rootViewController: vc)  
        return nvc
    }

    func updateUIViewController(_ navigationController: UINavigationController, context: Context) {
        navigationController.viewControllers[0].title = title        
    }
}

struct ContentView : View {
    var body: some View {        
        NavigationViewController(vc: UIViewController(), title: "UIViewControllerRepresentable")
    }
}
```



## SwiftUI in UIKit

SwiftUI 中的 View 需要使用`UIHostingController`包装以后才可以给 UIKit 使用。

### UIHostingController

在**开发 iOS 项目**章节已经分析过启动流程，就是通过`UIHostingController`包装 `ContentView`，然后赋值给`window.rootViewController`。

```swift
// 可以是复杂的ContentView
let vc = UIHostingController(rootView: ContentView())
```

```swift
// 也可以时简单的Text等其他View
let vc = UIHostingController(rootView: Text("Hello SwiftUI"))
```

