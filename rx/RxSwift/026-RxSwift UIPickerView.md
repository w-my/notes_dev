# RxSwift - UIPickerView

引入 `RxDataSources` 第三方库。它提供了许多 `pickerView` 适配器可以方便开发。



#### 单列

```swift
import UIKit
import RxSwift
import RxCocoa
import RxDataSources
 
class ViewController:UIViewController {
     
    var pickerView:UIPickerView!
     
    // 最简单的pickerView适配器（显示普通文本）
    private let stringPickerAdapter = RxPickerViewStringAdapter<[String]>(
        components: [],
        numberOfComponents: { _,_,_  in 1 },
        numberOfRowsInComponent: { (_, _, items, _) -> Int in
            return items.count},
        titleForRow: { (_, _, items, row, _) -> String? in
            return items[row]}
    )
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
        super.viewDidLoad()
         
        // 创建pickerView
        pickerView = UIPickerView()
        self.view.addSubview(pickerView)
         
        // 绑定pickerView数据
        Observable.just(["One", "Two", "Tree"])
            .bind(to: pickerView.rx.items(adapter: stringPickerAdapter))
            .disposed(by: disposeBag)
         
        // 建立一个按钮，触摸按钮时获得选择框被选择的索引
        let button = UIButton(frame:CGRect(x:0, y:0, width:100, height:30))
        button.center = self.view.center
        button.backgroundColor = UIColor.blue
        button.setTitle("获取信息",for:.normal)
        // 按钮点击响应
        button.rx.tap
            .bind { [weak self] in
                self?.getPickerViewValue()
            }
            .disposed(by: disposeBag)
        self.view.addSubview(button)
    }
     
    // 触摸按钮时，获得被选中的索引
    @objc func getPickerViewValue(){
        let message = String(pickerView.selectedRow(inComponent: 0))
        let alertController = UIAlertController(title: "被选中的索引为",
                                                message: message, preferredStyle: .alert)
        let okAction = UIAlertAction(title: "OK", style: .cancel, handler: nil)
        alertController.addAction(okAction)
        self.present(alertController, animated: true, completion: nil)
    }
}
```



#### 多列

```swift
import UIKit
import RxSwift
import RxCocoa
import RxDataSources
 
class ViewController:UIViewController {
     
    var pickerView:UIPickerView!
     
    // 最简单的pickerView适配器（显示普通文本）
    private let stringPickerAdapter = RxPickerViewStringAdapter<[[String]]>(
        components: [],
        numberOfComponents: { dataSource,pickerView,components  in components.count },
        numberOfRowsInComponent: { (_, _, components, component) -> Int in
            return components[component].count},
        titleForRow: { (_, _, components, row, component) -> String? in
            return components[component][row]}
    )
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
        super.viewDidLoad()
         
        // 创建pickerView
        pickerView = UIPickerView()
        self.view.addSubview(pickerView)
         
        // 绑定pickerView数据
        Observable.just([["One", "Two", "Tree"],
                         ["A", "B", "C", "D"]])
            .bind(to: pickerView.rx.items(adapter: stringPickerAdapter))
            .disposed(by: disposeBag)
         
        // 建立一个按钮，触摸按钮时获得选择框被选择的索引
        let button = UIButton(frame:CGRect(x:0, y:0, width:100, height:30))
        button.center = self.view.center
        button.backgroundColor = UIColor.blue
        button.setTitle("获取信息",for:.normal)
        // 按钮点击响应
        button.rx.tap
            .bind { [weak self] in
                self?.getPickerViewValue()
            }
            .disposed(by: disposeBag)
        self.view.addSubview(button)
    }
     
    // 触摸按钮时，获得被选中的索引
    @objc func getPickerViewValue(){
        let message = String(pickerView.selectedRow(inComponent: 0)) + "-"
            + String(pickerView!.selectedRow(inComponent: 1))
        let alertController = UIAlertController(title: "被选中的索引为",
                                                message: message, preferredStyle: .alert)
        let okAction = UIAlertAction(title: "OK", style: .cancel, handler: nil)
        alertController.addAction(okAction)
        self.present(alertController, animated: true, completion: nil)
    }
}
```



#### 修改样式

```swift
import UIKit
import RxSwift
import RxCocoa
import RxDataSources
 
class ViewController:UIViewController {
     
    var pickerView:UIPickerView!
     
    // 设置文字属性的pickerView适配器
    private let attrStringPickerAdapter = RxPickerViewAttributedStringAdapter<[String]>(
        components: [],
        numberOfComponents: { _,_,_  in 1 },
        numberOfRowsInComponent: { (_, _, items, _) -> Int in
            return items.count}
        ){ (_, _, items, row, _) -> NSAttributedString? in
            return NSAttributedString(string: items[row],
              attributes: [
                NSAttributedStringKey.foregroundColor: UIColor.orange, // 橙色文字
                NSAttributedStringKey.underlineStyle:
                    NSUnderlineStyle.styleDouble.rawValue, // 双下划线
                NSAttributedStringKey.textEffect:
                    NSAttributedString.TextEffectStyle.letterpressStyle
            ])
        }
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
        super.viewDidLoad()
         
        // 创建pickerView
        pickerView = UIPickerView()
        self.view.addSubview(pickerView)
         
        // 绑定pickerView数据
        Observable.just(["One", "Two", "Tree"])
            .bind(to: pickerView.rx.items(adapter: attrStringPickerAdapter))
            .disposed(by: disposeBag)
    }
}
```



#### 使用自定义视图

```swift
import UIKit
import RxSwift
import RxCocoa
import RxDataSources
 
class ViewController:UIViewController {
     
    var pickerView:UIPickerView!
     
    // 设置自定义视图的pickerView适配器
    private let viewPickerAdapter = RxPickerViewViewAdapter<[UIColor]>(
        components: [],
        numberOfComponents: { _,_,_  in 1 },
        numberOfRowsInComponent: { (_, _, items, _) -> Int in
            return items.count}
        ){ (_, _, items, row, _, view) -> UIView in
            let componentView = view ?? UIView()
            componentView.backgroundColor = items[row]
            return componentView
        }
     
    let disposeBag = DisposeBag()
     
    override func viewDidLoad() {
        super.viewDidLoad()
         
        // 创建pickerView
        pickerView = UIPickerView()
        self.view.addSubview(pickerView)
         
        // 绑定pickerView数据
        Observable.just([UIColor.red, UIColor.orange, UIColor.yellow])
            .bind(to: pickerView.rx.items(adapter: viewPickerAdapter))
            .disposed(by: disposeBag)
    }
}
```



