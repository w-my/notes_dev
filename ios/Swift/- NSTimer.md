## NSTimer
- @ 计时器的简单使用



#### 计时器的简单使用

```swift
var timer: Timer? = Timer() // 使用'?'
```

```swift
func startTimer() {
  	timer = Timer.scheduledTimer(timeInterval: 0.1, target: self, selector: #selector(updateTimer), userInfo: nil, repeats: true)
}
```

```swift
func endTimer() {
		if let timerTemp = timer {
        timerTemp.invalidate()
      	timerTemp = nil
		}
}
```

```swift
@objc func updateTimer() { }
```

