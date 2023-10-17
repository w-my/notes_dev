//
//  ViewController.swift
//  AudioCapture
//
//  Created by WTW on 2021/4/28.
//  Copyright © 2021 WTW. All rights reserved.
//

/**
 *  音频采集
 *  AVAudioRecorder: 可以指定路径写入到指定的文件中，对于获取实时数据限制较强
 *  AudioCapture
 *  AudioQueue
 *  AudioUnit 最底层的接口，功能强大延迟低，学习成本高，难度大
 *
 *
 *  NSMicrophoneUsageDescription 麦克风权限申请
 *
 *
 *
 * audiosession  
 *
 *  后台播放音频需要在info.plist 中配置
 *  Required background modes
 *  App plays audio or streams audio/video using AirPlay
 */

import UIKit
import AVFoundation

class ViewController: UIViewController {

    var player: AVAudioPlayer?
    
    override func viewDidLoad() {
        super.viewDidLoad()
               
        // 创建 AVAudioPlayer
        /// 对于iOS URL 必须在应用程序沙盒之内或者该URL一定是用户 iPod 库中的一个元素
        let path = Bundle.main.url(forResource: "bgm_demo", withExtension: "mp3")!
        
        /// 创建 AVAudioPlayer 实例
        player = try? AVAudioPlayer(contentsOf: path)
        
        /// 建议调用 prepareToPlay
        /// 可以取的需要的音频硬件并预加载 Audio Queue的缓冲区，降低直接调用 play 的延时
        if self.player != nil {
            self.player?.enableRate = true
            self.player?.prepareToPlay()
        }
        
        // 播放控制
        /// -1 循环播放 大于0 的数，即播放多少次
        player?.numberOfLoops = -1
        /// 立体声播放声音 取值范围 -1 ~ 1 默认 0
        player?.pan = 1
        /// 音量 0 ~ 1
        player?.volume = 0.5
        /// 播放倍率 0.5 ~ 2.0  必须enableRate 设置为 true 才有效果
        player?.rate = 1.0
        
        print(player?.isPlaying) // false
        print(player?.numberOfChannels)  // 2 省道
        print(player?.duration) // 160 时长
        print(player?.currentTime) // 当前的播放进度
        
        // 处理中断事件
        /// 比如电话呼入 闹钟 等等
        /// 默认情况下是会停止播放，电话结束后也不会自动继续播放
        NotificationCenter.default.addObserver(self, selector: #selector(handleInterruption(_:)), name: AVAudioSession.interruptionNotification, object: AVAudioSession.sharedInstance())
        
    }
    
    /// 处理中断
    @objc func handleInterruption(_ noti:Notification) {
        
        let info = noti.userInfo 
                
        /// 中断类型
        let type: UInt = ((info?[AVAudioSessionInterruptionTypeKey] as? UInt)! as? AVAudioSession.InterruptionType)!.rawValue
                
        /// 中断开始和结束
        /// 可以根据情况回调给用户做页面处理
        if type == AVAudioSession.InterruptionType.began.rawValue {
                       
            // 处理中断开始
            self.stop()
            
            // 通过代理回调出去供用户处理UI
//            if self.delegate {
//                self.delegate.playbackStopped
//            }
        }else {
            
            // 处理中断结束
            let options = info?[AVAudioSessionInterruptionOptionKey] as? AVAudioSession.InterruptionOptions
            
            if options == AVAudioSession.InterruptionOptions.shouldResume {
                
                self.play()
                
//                if self.delegate {
//                    self.delegate.playbackBegan
//                }
                
            }
            
        }
    }
    
    /// 播放
    @IBAction func play() {
        if player?.isPlaying == false {
            player?.play()
        }
    }
    
    /// 暂停
    @IBAction func pause() {
        player?.pause()
    }
    
    /// 结束
    @IBAction func stop() {
        if player?.isPlaying == true {
            player?.stop()
            
            print(player?.currentTime)
            
            player?.currentTime = 0.0 // 播放进度回到原点
        }
    }
    
    deinit {
        NotificationCenter.default.removeObserver(self)
    }
}

