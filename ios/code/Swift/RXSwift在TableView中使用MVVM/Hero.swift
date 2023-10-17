//
//  Hero.swift
//  RXSwift在TableView中使用MVVM
//
//  Created by WTW on 2020/3/25.
//  Copyright © 2020 WTW. All rights reserved.
//

import UIKit

class Hero: NSObject {
    @objc var icon : String = ""
    @objc var intro : String = ""
    @objc var name : String = ""
    
    init(dict : [String : Any]) {
        super.init()
        setValuesForKeys(dict)
    }
}
