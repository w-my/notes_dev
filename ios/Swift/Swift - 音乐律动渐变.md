## Swift - 音乐律动背景渐变效果

```swift
import UIKit
import AVKit

class ViewController: UIViewController {

    lazy var playBtn: UIButton = {
        let btn = UIButton(type: .system)
        btn.frame = CGRect(x: 0, y: 0, width: 100, height: 100)
        btn.setImage(#imageLiteral(resourceName: "music play"), for: .normal)
        btn.addTarget(self, action: #selector(play), for: .touchUpInside)
        return btn
    }()

    let soudUrl = URL(fileURLWithPath: Bundle.main.path(forResource: "Ecstasy", ofType: "mp3")!)
 
    var audioPlayer: AVAudioPlayer?
    let gradientLayer = CAGradientLayer()
    var timer: Timer?
    
    var bgColor: (r: CGFloat, g: CGFloat, b: CGFloat, a: CGFloat)! {
        didSet {
            let color1 = UIColor(red: bgColor.b,
                                 green: bgColor.g,
                                 blue: 0,
                                 alpha: bgColor.a).cgColor
            let color2 = UIColor(red: bgColor.r,
                                 green: bgColor.g,
                                 blue: bgColor.b,
                                 alpha: bgColor.a).cgColor
            gradientLayer.colors = [color1, color2]
        }
    }

    
    override func viewDidLoad() {
        super.viewDidLoad()
        view.addSubview(playBtn)
        playBtn.center = view.center
    }
    
    override var prefersStatusBarHidden: Bool {
        return true
    }
    
    @objc func play() {
       
        let session = AVAudioSession.sharedInstance()
        
        do {
            // 启动音频会话的管理，此时会阻断后台音乐的播放
            try session.setActive(true, options: AVAudioSession.SetActiveOptions.init())
            // 设置音频操作类别，标示该应用仅支持音频的播放
            try session.setCategory(AVAudioSession.Category.playback)
            // 设置应用程序支持接受远程控制事件
//            UIApplication.shared.beginReceivingRemoteControlEvents()
            
            try audioPlayer = AVAudioPlayer(contentsOf: soudUrl)

            audioPlayer?.prepareToPlay()
            audioPlayer?.volume = 1.0
            audioPlayer?.numberOfLoops = -1
            audioPlayer?.play()
        }
        catch let audioError as NSError {
            print(audioError)
        }
        
        if timer == nil {
            timer = Timer.scheduledTimer(timeInterval: 0.2,
                                         target: self,
                                         selector: #selector(randomColor),
                                         userInfo: nil, repeats: true)
        }

        let redValue = CGFloat(drand48())
        let blueValue = CGFloat(drand48())
        let greenValue = CGFloat(drand48())

        view.backgroundColor = UIColor(red: redValue, green: greenValue, blue: blueValue, alpha: 1.0)

        gradientLayer.frame = view.bounds
        gradientLayer.startPoint = CGPoint(x: 0, y: 0)
        gradientLayer.endPoint = CGPoint(x: 1, y: 1)

        view.layer.addSublayer(gradientLayer)
    }

    @objc func randomColor() {
        let redValue = CGFloat(drand48())
        let blueValue = CGFloat(drand48())
        let greenValue = CGFloat(drand48())
        bgColor = (redValue, blueValue, greenValue, 1)
    }
}
```
