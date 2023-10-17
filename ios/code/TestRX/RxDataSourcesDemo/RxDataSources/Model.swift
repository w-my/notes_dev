//
//  Model.swift
//  RxDataSourcesDemo
//
//  Created by WTW on 2022/3/31.
//  Copyright © 2022 Mac. All rights reserved.
//

import UIKit
import Differentiator

struct CustomData {
    var name: String
    var age: Int
}


/*****************************************************************************/
struct SectionOfCustomData<T> {
    
    var header: String
    var items: [T]
}

extension SectionOfCustomData: SectionModelType {
    
    typealias Item = T
    
    init(original: SectionOfCustomData, items: [T]) {
        self = original
        self.items = items
    }
}

/*****************************************************************************/

/*
 1、首先使用符合 SectionModelType 协议的结构定义您的部分
 2、创建一个 dataSource 对象并将您的 SectionOfCustomData 类型传递给它
 */
