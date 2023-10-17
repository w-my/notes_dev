//
//  Nibloadable.swift
//  协议
//
//  Created by WTW on 2020/6/2.
//  Copyright © 2020 WTW. All rights reserved.
//

import UIKit

protocol Nibloadable { }

extension Nibloadable where Self: UIView {
    
    static func loadFromNib() -> Self {
        return Bundle.main.loadNibNamed("\(self)", owner: nil, options: nil)?.first as! Self
    }
}
