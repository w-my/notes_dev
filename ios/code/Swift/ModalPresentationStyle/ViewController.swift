//
//  ViewController.swift
//  ModalPresentationStyle
//
//  Created by WTW on 2020/5/15.
//  Copyright © 2020 WTW. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    
        
        self.navigationItem.title = "title"
                
        // 已经没效果了，需要使用 barTintColor
        self.navigationController?.navigationBar.tintColor = .red
        
        self.navigationController?.navigationBar.barTintColor = .green
        
    }

    
    
    
    // https://juejin.im/post/5cb6d41ce51d456e6d133486
    
    /*
     case fullScreen (全屏)   在各种 Size Class 情况下都是全屏展示

     case pageSheet  被推出视图部分的遮盖下层视图

     case formSheet

     case currentContext

     case custom

     case overFullScreen

     case overCurrentContext

     case popover
     
     case none

     case automatic
     */
    
    
    /*
     case coverVertical  (默认的)

     case flipHorizontal (水平翻转)

     case crossDissolve (淡入淡出)
    
     case partialCurl  (部分卷曲 卷页)
     */
    
    let testVc = TestViewController()
    
    override func touchesBegan(_ touches: Set<UITouch>, with event: UIEvent?) {
        
        testVc.view.backgroundColor = .clear
        
        testVc.modalPresentationStyle = .pageSheet
        
//        testVc.modalTransitionStyle = .crossDissolve   // 转场
        
        present(testVc, animated: true, completion: nil)
        
        
        DispatchQueue.main.asyncAfter(deadline: .now() + 3) {
            self.testVc.dismiss(animated: true, completion: nil)
        }
    }
    

}

