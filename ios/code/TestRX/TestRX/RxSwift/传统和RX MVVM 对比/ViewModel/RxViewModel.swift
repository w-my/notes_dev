//
//  RxViewModel.swift
//  TestRX
//
//  Created by WTW on 2020/7/28.
//  Copyright © 2020 Mac. All rights reserved.
//

import UIKit
import RxSwift

// 数据源
// Rxswift 对传统进行改造
// 变成一个可观察序列对象
struct MusicListRxViewModel {
    
    let data = Observable.just([
        Music(name: "无条件", singer: "陈奕迅"),
        Music(name: "你曾是少年", singer: "S.H.E"),
        Music(name: "从前的我", singer: "陈洁仪"),
        Music(name: "在木星", singer: "朴树"),
    ])
}
