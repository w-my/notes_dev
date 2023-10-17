//
//  TestMJRefreshController.swift
//  RXDataSourceTest
//
//  Created by WTW on 2020/11/17.
//  Copyright © 2020 WTW. All rights reserved.
//

import UIKit

class TestMJRefreshController: UIViewController {

    let tableView = UITableView().then {
        $0.frame = CGRect(x: 0, y: 0, width: UIScreen.main.bounds.size.width, height: UIScreen.main.bounds.size.height)
        $0.backgroundColor = .white
        $0.register(cellType: TitleSwitchCell.self)
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()

        view.addSubview(tableView)
        
    }
       
}
