//
//  ViewController.swift
//  协议
//
//  Created by WTW on 2020/3/1.
//  Copyright © 2020 WTW. All rights reserved.
//

// 扩展遵从协议的效果更好
// 不同协议在不同扩展中遵从，不会出现多个协议方法混在一起，提高程序的可读性

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
       let tableView = UITableView(frame: view.bounds, style: .grouped)
       tableView.backgroundColor = UIColor.white
       view.addSubview(tableView)
       tableView.dataSource = self
       tableView.delegate = self
    }
}

extension ViewController : UITableViewDataSource {
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return 10;
    }
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let  cellId = "testCellId"
        var cell = tableView.dequeueReusableCell(withIdentifier: cellId)
        if cell == nil {
            cell = UITableViewCell(style: .subtitle, reuseIdentifier: cellId)
        }
        
        cell?.textLabel?.text = "哈哈"
        cell?.detailTextLabel?.text = "detail"
        
        return cell!
    }
}

extension ViewController : UITableViewDelegate {
    func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        return 44.0
    }
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        print(indexPath.row)
    }
}
