//
//  ViewController.swift
//  swift 编译优化
//
//  Created by WTW on 2020/5/18.
//  Copyright © 2020 WTW. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
       
//        let result = CGFloat(M_PI) * (CGFloat((10 + 20 + CGFloat(20) / 60) * 5) - 15)
          
         let result = CGFloat(M_PI) * (CGFloat((10 + 20 + CGFloat(20) / 60) * 5) - 15)

//        print(result)
                
        
        // 编译时间: 3431.7 ms
//        return CGFloat(M_PI) * (CGFloat((hour + hourDelta + CGFloat(minute + minuteDelta) / 60) * 5) - 15) * unit / 180
//
//        // 编译时间: 3.0ms
//        return CGFloat(M_PI) * ((hour + hourDelta + (minute + minuteDelta) / 60) * 5 - 15) * unit / 180
                
        
        // 编译时间: 1250.3ms
//        let systemOptions = [ 7, 14, 30, -1 ]
//        let systemNames = (0...2).map{ String(format: localizedFormat, systemOptions[$0]) } + [NSLocalizedString("everything", comment: "")]
//        // 一些中间的代码
//        labelNames = Array(systemNames[0..<count]) + [systemNames.last!]
//
//        // 编译时间: 25.5ms
//        let systemOptions = [ 7, 14, 30, -1 ]
//        var systemNames = systemOptions.dropLast().map{ String(format: localizedFormat, $0) }
//        systemNames.append(NSLocalizedString("everything", comment: ""))
//        // 一些中间的代码
//        labelNames = Array(systemNames[0..<count])
//        labelNames.append(systemNames.last!)
        
        
        
        // 空合操作符
        
//        // 编译时间: 5238.3ms
//        return CGSize(width: size.width + (rightView?.bounds.width ?? 0) + (leftView?.bounds.width ?? 0) + 22, height: bounds.height)
//
//        // 编译时间: 32.4ms
//        var padding: CGFloat = 22
//        if let rightView = rightView {
//            padding += rightView.bounds.width
//        }
//
//        if let leftView = leftView {
//            padding += leftView.bounds.width
//        }
//        return CGSizeMake(size.width + padding, bounds.height)
        
        
        let label = UILabel()
        
        label.text = "hello how are you"
        
        label.font = UIFont.systemFont(ofSize: 24)
        
        label.frame = CGRect(x: 130, y: 130, width: 150, height: 50)
        
        label.backgroundColor = .white
        
        let bgView = UIView()
        
        bgView.frame = CGRect(x: 120, y: 120, width: 100, height: 100)
        
        bgView.backgroundColor = UIColor.green
        
        let view = UIView()
        
        view.frame = CGRect(x: 100, y: 100, width: 100, height: 100)
        
        view.backgroundColor = .clear
                
        self.view.addSubview(view)
        self.view.addSubview(bgView)
        self.view.addSubview(label)
                
    }


}

