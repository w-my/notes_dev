//
//  TestModel.swift
//  RXDataSourceTest
//
//  Created by WTW on 2020/11/13.
//  Copyright © 2020 WTW. All rights reserved.
//

import UIKit
import RxDataSources

struct TestModel {
    
}

// 自定义 Section
struct TDSection {
    var header: String
    var items: [Item]
}

extension TDSection: SectionModelType {
//    typealias Item = TestModel
    
    typealias Item = String
    
    var identity: String {
        return header
    }
    
    init(original: Self, items: [Item]) {
        self = original
        self.items = items
    }
}
