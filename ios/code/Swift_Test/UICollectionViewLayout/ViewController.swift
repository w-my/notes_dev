//
//  ViewController.swift
//  UICollectionView
//
//  Created by WTW on 2020/6/5.
//  Copyright © 2020 WTW. All rights reserved.
//

import UIKit

let Width = UIScreen.main.bounds.size.width
let Height = UIScreen.main.bounds.size.height

class ViewController: UIViewController {

    fileprivate let ListData = ["custom Waterfall"]
    
    override func viewDidLoad() {
        super.viewDidLoad()
       
        
        self.view.addSubview(tableView)
        tableView.frame = CGRect(x: 0, y: 0, width: Width, height: Height)
    }

    fileprivate lazy var tableView: UITableView = {
       
        let tableView = UITableView()
        
        tableView.dataSource = self
        tableView.delegate = self
        
        tableView.register(UITableViewCell.self, forCellReuseIdentifier: "cell")
        
        return tableView
        
    }()
    
}

extension ViewController: UITableViewDelegate,UITableViewDataSource {
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return ListData.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "cell", for: indexPath)
        
        cell.textLabel?.text = ListData[indexPath.row]
        
        return cell
    }
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        switch indexPath.row {
        case 0:
            self.navigationController?.pushViewController(BaseCollectionController(), animated: true)
        default:
            break
        }
    }
}
