//
//  TDGirlModel.swift
//  RXDemo1
//
//  Created by WTW on 2020/11/11.
//  Copyright © 2020 WTW. All rights reserved.
//

import UIKit
import ObjectMapper
import RxDataSources

/**
 * category = MeiTui;
 * "group_url" = "https://www.dbmeinv.com:443/dbgroup/1737011";
 * "image_url" = "https://wx3.sinaimg.cn/large/0060lm7Tgy1ftc0odsk55j30dw0ii7b1.jpg";
 * objectId = 5b4cc34e0b616000310b6a42;
 * "thumb_url" = "https://wx3.sinaimg.cn/small/0060lm7Tgy1ftc0odsk55j30dw0ii7b1.jpg";
 * title = "\U597d\U4e27\U554a\Uff0c\U6765\U4e00\U6ce2\U8c46\U6cb9\U5427\U3002";
 */

struct TDGirlModel: Mappable  {

    var category = ""
    var group_url: String = ""
    var image_url: String = ""
    var objectId: String = ""
    var thumb_url: String = ""
    var title: String = ""

    init?(map: Map) {
           
    }
    
    mutating func mapping(map: Map) {
        
        category <- map["category"]
        group_url <- map["group_url"]
        image_url <- map["image_url"]
        objectId <- map["objectId"]
        thumb_url <- map["thumb_url"]
        title <- map["title"]
        
    }
    
}

struct TDSection {
    
    var items: [Item]
}

extension TDSection: SectionModelType {
    
    typealias Item = TDGirlModel
    
    init(original: Self, items: [Self.Item]) {
        self = original
        self.items = items
    }
}
