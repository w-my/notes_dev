//
//  ViewController.swift
//  MultiTarget
//
//  Created by WTW on 2021/1/14.
//  Copyright © 2021 WTW. All rights reserved.
//

/**
 * https://juejin.cn/post/6844903537428660238
 * 一个Target 定义了一个单一项目环境，在一个项目工程中可以包含一个或者多个Target，即一个项目可以设置多种环境
 *
 */

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()

        #if TARGET_VERSION
            print("Dev")
        #else
            print("++")
        #endif
        
    }
}

