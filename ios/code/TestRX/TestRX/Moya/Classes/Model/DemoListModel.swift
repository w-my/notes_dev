//
//  DemoListModel.swift
//  TestRX
//
//  Created by WTW on 2020/7/31.
//  Copyright © 2020 Mac. All rights reserved.
//

import UIKit
import HandyJSON
import RxDataSources

struct DemoListModel: HandyJSON {

    var abbr_en = ""
    var channel_id = ""
    var name = ""
    var name_en = ""
    var seq_id = ""
    
}

// RxDataSources

struct DemoListSection {
    var items: [Item]
}

extension DemoListSection: SectionModelType {
    
    typealias Item = DemoListModel
    
    init(original: Self, items: [Self.Item]) {
        self = original
        self.items = items
    }
    
}
