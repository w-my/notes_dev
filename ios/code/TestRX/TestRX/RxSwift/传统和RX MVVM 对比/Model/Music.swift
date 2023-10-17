//
//  Music.swift
//  TestRX
//
//  Created by WTW on 2020/7/28.
//  Copyright © 2020 Mac. All rights reserved.
//

import UIKit

struct Music {
    let name: String
    let singer: String
    
    init(name: String,singer: String) {
        self.name = name
        self.singer = singer
    }
}

/// 实现 CustomStringConvertible 协议，方便输出调试
extension Music: CustomStringConvertible {
    var description: String {
        return "name:\(name) singer:\(singer)"
    }
    
}
