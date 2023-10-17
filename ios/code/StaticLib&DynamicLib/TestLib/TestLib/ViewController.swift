//
//  ViewController.swift
//  TestLib
//
//  Created by WTW on 2021/1/3.
//  Copyright © 2021 WTW. All rights reserved.
//

import UIKit
import StaticFramework
import DynamicFramework

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }


    override func touchesBegan(_ touches: Set<UITouch>, with event: UIEvent?) {
        
        StaticFramework().log()
        
        DynamicFramework().log()
        
    }
    
}

