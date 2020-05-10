## 动画小案例

#### 按钮点击后的弹动效果

```swift
self.btn.isEnabled = false
let bounds = self.btn.bounds

UIView.animate(withDuration: 0.1, delay: 0.0, options: .curveEaseOut, animations: {
    self.btn.bounds = CGRect(x: bounds.origin.x - 10,
                             y: bounds.origin.y,
                             width: bounds.width + 20,
                             height: bounds.height)
}, completion: { _ in
    UIView.animate(withDuration: 0.2, delay: 0.0, usingSpringWithDamping: 0.2, initialSpringVelocity: 10, options: .curveLinear, animations: {
        self.btn.bounds = bounds
    }, completion: { _ in
        self.btn.isEnabled = true
    })
})
```



#### TableViewCell 入场动画

```swift
func animate() {
    tbView.reloadData()
    
    let cells = tbView.visibleCells
    let tableHeight: CGFloat = tbView.bounds.size.height
    
    for (index, cell) in cells.enumerated() {
        cell.transform = CGAffineTransform(translationX: 0, y: tableHeight)
        UIView.animate(withDuration: 1.0,
                       delay: 0.05 * Double(index),
                       usingSpringWithDamping: 0.8,
                       initialSpringVelocity: 0,
                       options: [],
                       animations: {
                        cell.transform = CGAffineTransform(translationX: 0, y: 0);
        }, completion: nil)
    }
}
```

