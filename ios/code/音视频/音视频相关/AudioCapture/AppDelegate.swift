//
//  AppDelegate.swift
//  AudioCapture
//
//  Created by WTW on 2021/4/28.
//  Copyright © 2021 WTW. All rights reserved.
//

import UIKit
import AVFoundation

@main
class AppDelegate: UIResponder, UIApplicationDelegate {

    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        
        // 配置音频会话
        let audioSession = AVAudioSession.sharedInstance()
        try? audioSession.setCategory(.playback) // 关屏 和 声音关闭开关关闭都能听到声音
        try? audioSession.setActive(true,options: .notifyOthersOnDeactivation)  // 激活会话
//        audioSession.setMode(<#T##mode: AVAudioSession.Mode##AVAudioSession.Mode#>)
        
        /// 获取当前的Categor
        /// 默认值  AVAudioSessionCategorySoloAmbient
        print(AVAudioSession.sharedInstance().category)
        /// 查看当前设备支持哪些类别
        /// [__C.AVAudioSessionCategory(_rawValue: AVAudioSessionCategoryAmbient),
        /// __C.AVAudioSessionCategory(_rawValue: AVAudioSessionCategorySoloAmbient),
        /// __C.AVAudioSessionCategory(_rawValue: AVAudioSessionCategoryPlayback),
        ///  __C.AVAudioSessionCategory(_rawValue: AVAudioSessionCategoryRecord),
        ///  __C.AVAudioSessionCategory(_rawValue: AVAudioSessionCategoryPlayAndRecord),
        ///   __C.AVAudioSessionCategory(_rawValue: AVAudioSessionCategoryMultiRoute)]
        print(AVAudioSession.sharedInstance().availableCategories)
        /// 类别的选项 (相当于对于七大类别进行微调)
        /// AVAudioSessionCategoryOptions(rawValue: 0)
        print(AVAudioSession.sharedInstance().categoryOptions)
        /// 查看支持的模式
        /// [__C.AVAudioSessionMode(_rawValue: AVAudioSessionModeDefault),
        /// __C.AVAudioSessionMode(_rawValue: AVAudioSessionModeVoiceChat),
        /// __C.AVAudioSessionMode(_rawValue: AVAudioSessionModeVideoRecording),
        /// __C.AVAudioSessionMode(_rawValue: AVAudioSessionModeMeasurement),
        /// __C.AVAudioSessionMode(_rawValue: AVAudioSessionModeMoviePlayback),
        ///  __C.AVAudioSessionMode(_rawValue: AVAudioSessionModeVideoChat),
        ///  __C.AVAudioSessionMode(_rawValue: AVAudioSessionModeSpokenAudio),
        ///   __C.AVAudioSessionMode(_rawValue: AVAudioSessionModeVoicePrompt)]
        print(AVAudioSession.sharedInstance().availableModes)
        
        return true
    }

    // MARK: UISceneSession Lifecycle

    func application(_ application: UIApplication, configurationForConnecting connectingSceneSession: UISceneSession, options: UIScene.ConnectionOptions) -> UISceneConfiguration {
        // Called when a new scene session is being created.
        // Use this method to select a configuration to create the new scene with.
        return UISceneConfiguration(name: "Default Configuration", sessionRole: connectingSceneSession.role)
    }

    func application(_ application: UIApplication, didDiscardSceneSessions sceneSessions: Set<UISceneSession>) {
        // Called when the user discards a scene session.
        // If any sessions were discarded while the application was not running, this will be called shortly after application:didFinishLaunchingWithOptions.
        // Use this method to release any resources that were specific to the discarded scenes, as they will not return.
    }


}

