//
//  Note.swift
//  错误处理
//
//  Created by WTW on 2020/3/26.
//  Copyright © 2020 WTW. All rights reserved.
//

import UIKit

class Note: NSObject {
    var date: Date?
    var content: String?
    
    init(date:Date?,content:String?) {
        self.date = date
        self.content = content
    }
}
