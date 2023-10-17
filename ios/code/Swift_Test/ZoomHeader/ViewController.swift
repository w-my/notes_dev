//
//  ViewController.swift
//  ZoomHeader
//
//  Created by WTW on 2021/1/14.
//  Copyright © 2021 WTW. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }


    override func touchesBegan(_ touches: Set<UITouch>, with event: UIEvent?) {
        
        navigationController?.pushViewController(ZoomTableViewController(), animated: true)
    }
    
}

