//
//  TestByVal.swift
//  闭包
//
//  Created by WTW on 2020/4/5.
//  Copyright © 2020 WTW. All rights reserved.
// 测试传值

import UIKit

typealias myBlcok = (String,String,String)->(Void)

class TestByVal: NSObject {

    private var tempBlock : myBlcok?
    
    func testOne(back:@escaping (String,String,String) -> Void) {
        self.tempBlock = back
        self.perform(#selector(test),with: nil,afterDelay: 3)
    }
    
    @objc func test() -> Void {
        self.tempBlock!("测试1","测试2","测试3")
    }
    
}
