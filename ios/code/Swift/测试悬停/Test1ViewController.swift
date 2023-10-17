//
//  Test1ViewController.swift
//  测试悬停
//
//  Created by WTW on 2020/5/27.
//  Copyright © 2020 WTW. All rights reserved.
//

import UIKit

let kHeaderHeight: CGFloat = 40
let KScreenWidth = UIScreen.main.bounds.size.width
let KScreenHeight = UIScreen.main.bounds.size.height

class Test1ViewController: UITableViewController {
    
    override func viewDidLoad() {
        super.viewDidLoad()

        tableView.register(UITableViewCell.self, forCellReuseIdentifier: "reuseIdentifier")
    }
   
    // MARK: - Table view data source

    override func numberOfSections(in tableView: UITableView) -> Int {
        
        return 3
    }

    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
       
        return 20
    }

    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "reuseIdentifier", for: indexPath)

        return cell
    }
    
    override func tableView(_ tableView: UITableView, heightForHeaderInSection section: Int) -> CGFloat {
        return kHeaderHeight + 9
    }
    
    override func tableView(_ tableView: UITableView, viewForHeaderInSection section: Int) -> UIView? {
        let view = UIView(frame: CGRect(x: 0, y: 0, width: KScreenWidth, height: kHeaderHeight))
        view.backgroundColor = .red
        
        let label: UILabel = UILabel(frame: CGRect(x: 0, y: 9, width: KScreenWidth, height: kHeaderHeight))
        label.text = "== \(section) == "
        label.textColor = .white
        view.addSubview(label)
        
        return view
    }
    
    override func tableView(_ tableView: UITableView, heightForFooterInSection section: Int) -> CGFloat {
        return 20
    }
    
    override func tableView(_ tableView: UITableView, viewForFooterInSection section: Int) -> UIView? {
        let view = UIView(frame: CGRect(x: 0, y: 0, width: 100, height: 30))
        view.backgroundColor = .green
        return view
    }
        
}
