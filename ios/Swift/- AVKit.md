## AVKit

- @ 播放视频
- 



#### @ 播放视频

```swift
let playVC = AVPlayerViewController()
var player = AVPlayer()

let path = Bundle.main.path(forResource: "movie", ofType: "mp4")
player = AVPlayer(url: URL(fileURLWithPath: path!))
playVC.player = player
present(playVC, animated: true) {
    self.playVC.player?.play()
}
```

