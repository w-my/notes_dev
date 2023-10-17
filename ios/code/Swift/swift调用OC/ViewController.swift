//
//  ViewController.swift
//  swift调用OC
//
//  Created by WTW on 2020/3/27.
//  Copyright © 2020 WTW. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        
        
        let person = Person(name: "name", age: 10)
        print(person.name,person.age)
        
        var error : Error?
        person.write("hello", error:error as? AutoreleasingUnsafeMutablePointer<NSError?>)
    }


}

