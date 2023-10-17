//
//  ViewController.swift
//  移动动画
//
//  Created by wtw on 2019/1/30.
//  Copyright © 2019 wtw. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    var loginButton:UIButton?;
    
    override func viewDidLoad() {
        super.viewDidLoad()
        loginButton = UIButton(frame: CGRect(x: -394, y: 100, width: 100, height: 50))
        loginButton!.backgroundColor = UIColor.red;
        loginButton?.setTitle("hello", for: UIControl.State.normal);
        self.view.addSubview(loginButton!);
    }

    override func viewWillAppear(_ animated: Bool) {
        UIView.animate(withDuration: 1, animations: {
            self.loginButton?.frame = CGRect(x: 200, y: self.loginButton!.frame.origin.y, width: self.loginButton!.frame.width, height: self.loginButton!.frame.height);
        }) { (true) in
            print("complete")
        }
    }
    
    override func viewWillDisappear(_ animated: Bool) {
        
    }
}

