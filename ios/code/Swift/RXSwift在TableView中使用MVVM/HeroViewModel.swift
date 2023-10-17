//
//  HeroViewModel.swift
//  RXSwift在TableView中使用MVVM
//
//  Created by WTW on 2020/3/25.
//  Copyright © 2020 WTW. All rights reserved.
//

import UIKit
import RxSwift

class HeroViewModel: NSObject {

    var herosObserable : Variable<[Hero]> = {
        let path = Bundle.main.path(forResource: "heros.plist", ofType: nil)!
        let array = NSArray(contentsOfFile: path) as! [[String : Any]]
        var heros : [Hero] = [Hero]()
        for dict in array {
           heros.append(Hero(dict: dict))
       }
        return Variable(heros)
    }()
    
    // 网络回来更新添加数据
//    let hero = Hero(dict: ["name":"aa","intro":"bb","icon":"cc"])
//    herosObserable.value = [hero]
}
