//
//  ViewController.swift
//  swift语法汇编初探
//
//  Created by WTW on 2020/3/23.
//  Copyright © 2020 WTW. All rights reserved.
//

/*
 swiftc 存放在 /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin下
 
 一些操作：
 生成语法树：swiftc -dump-ast main.swift
 生成最简洁的 SIL 代码： swiftc -emit-sil main.swift
 生成 LLVM 代码： swiftc -emit-ir main.swift -o main.ll
 生成汇编代码：swiftc -emit-assembly main.swift -o main.s
 */


import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
       
        
        
    }


}

