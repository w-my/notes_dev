//
//  ViewController.swift
//  测试悬停
//
//  Created by WTW on 2020/5/27.
//  Copyright © 2020 WTW. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    fileprivate var dataSource:[String] = ["1"]
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.view.addSubview(tableView)
    }
    
    fileprivate lazy var tableView: UITableView = {
       
        let tab = UITableView(frame: CGRect(x: 0, y: 0, width: UIScreen.main.bounds.size.width, height: UIScreen.main.bounds.size.height))
        
        tab.delegate = self
        tab.dataSource = self
        
        return tab
    }()

}

extension ViewController : UITableViewDelegate,UITableViewDataSource {
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return dataSource.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        var cell = tableView.dequeueReusableCell(withIdentifier: "cell")
        if cell == nil {
            cell = UITableViewCell(style: .default, reuseIdentifier: "cell")
        }
        
        cell?.textLabel?.text = dataSource[indexPath.row]
        
        return cell!
    }
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        switch indexPath.row {
        case 0:
            self.navigationController?.pushViewController(Test1ViewController(), animated: true)
        default:
            break
        }
    }
}

