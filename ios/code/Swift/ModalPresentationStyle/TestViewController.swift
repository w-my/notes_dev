//
//  TestViewController.swift
//  ModalPresentationStyle
//
//  Created by WTW on 2020/5/15.
//  Copyright © 2020 WTW. All rights reserved.
//

import UIKit

class TestViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()

        let view = UIView()
        
        view.frame = CGRect(x: 0, y: 100, width: UIScreen.main.bounds.size.width, height: UIScreen.main.bounds.size.height - 100)

        view.backgroundColor = .green
        
        self.view.addSubview(view)
        
        
        self.view.backgroundColor = .green
    }
    
    
    
    

   

}
