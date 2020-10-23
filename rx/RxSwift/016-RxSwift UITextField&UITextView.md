# RxSwift - UITextField、UITextView



#### 监听单个 textField 内容的变化

```swift
// 当文本框内容改变时，将内容输出到控制台上
textField.rx.text.orEmpty.asObservable()
    .subscribe(onNext: {
        print("输入的是：\($0)")
    })
    .disposed(by: disposeBag)
```

```dart
// 当文本框内容改变时，将内容输出到控制台上
textField.rx.text.orEmpty.changed
    .subscribe(onNext: {
        print("输入的是：\($0)")
    })
    .disposed(by: disposeBag)
```



#### 将内容绑定到其他控件上

```swift
// 当文本框内容改变
let input = inputField.rx.text.orEmpty.asDriver() // 将普通序列转换为 Driver
    .throttle(0.3) // 在主线程中操作，0.3秒内值若多次改变，取最后一次

// 内容绑定到另一个输入框中
input.drive(outputField.rx.text)
    .disposed(by: disposeBag)

// 内容绑定到文本标签中
input.map{ "当前字数：\($0.count)" }
    .drive(label.rx.text)
    .disposed(by: disposeBag)

// 根据内容字数决定按钮是否可用
input.map{ $0.count > 5 }
    .drive(button.rx.isEnabled)
    .disposed(by: disposeBag)
```



#### 同时监听多个 textField 内容的变化

```swift
Observable.combineLatest(textField1.rx.text.orEmpty, textField2.rx.text.orEmpty) {
    textValue1, textValue2 -> String in
    return "输入的是：\(textValue1)-\(textValue2)"
    }
    .map { $0 }
    .bind(to: label.rx.text)
    .disposed(by: disposeBag)
```



####  事件监听

**editingDidBegin**：开始编辑（开始输入内容）

**editingChanged**：输入内容发生改变

**editingDidEnd**：结束编辑

**editingDidEndOnExit**：按下 `return` 键结束编辑

**allEditingEvents**：包含前面的所有编辑相关事件

```swift
textField.rx.controlEvent([.editingDidBegin]) // 状态可以组合
    .asObservable()
    .subscribe(onNext: { _ in
        print("开始编辑内容!")
    }).disposed(by: disposeBag)
```

```swift
// 在用户名输入框中按下 return 键
username.rx.controlEvent(.editingDidEndOnExit).subscribe(onNext: {
    [weak self] (_) in
    self?.password.becomeFirstResponder()
}).disposed(by: disposeBag)

 // 在密码输入框中按下 return 键
password.rx.controlEvent(.editingDidEndOnExit).subscribe(onNext: {
    [weak self] (_) in
    self?.password.resignFirstResponder()
}).disposed(by: disposeBag)
```



#### UITextView 独有的方法

- **didBeginEditing**：开始编辑
- **didEndEditing**：结束编辑
- **didChange**：编辑内容发生改变
- **didChangeSelection**：选中部分发生变化

```swift
// 开始编辑响应
textView.rx.didBeginEditing
    .subscribe(onNext: {
        print("开始编辑")
    })
    .disposed(by: disposeBag)

// 结束编辑响应
textView.rx.didEndEditing
    .subscribe(onNext: {
        print("结束编辑")
    })
    .disposed(by: disposeBag)

// 内容发生变化响应
textView.rx.didChange
    .subscribe(onNext: {
        print("内容发生改变")
    })
    .disposed(by: disposeBag)

// 选中部分变化响应
textView.rx.didChangeSelection
    .subscribe(onNext: {
        print("选中部分发生变化")
    })
    .disposed(by: disposeBag)
```

