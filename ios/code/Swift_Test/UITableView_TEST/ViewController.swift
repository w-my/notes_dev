//
//  ViewController.swift
//  UITableView_TEST
//
//  Created by WTW on 2020/6/9.
//  Copyright © 2020 WTW. All rights reserved.
//

import UIKit

let WIDTH = UIScreen.main.bounds.size.width

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
               
        self.view.addSubview(tableView)
        
        self.view.addSubview(headerView)
//        tableView.tableHeaderView = headerView
        
//        print(UIApplication.shared.statusBarFrame.height)  // 44
//        print(self.navigationController?.navigationBar.frame.size.height)  // 44
        
    }

    func scrollViewDidScroll(_ scrollView: UIScrollView) {
        
        print(scrollView.contentOffset.y)
        
        if scrollView.contentOffset.y >= 0 {
            headerView.selectView.frame.origin.y = 88
        }else {
            headerView.selectView.frame.origin.y = 88 - scrollView.contentOffset.y
        }
        
    }
    
    fileprivate lazy var headerView: HeaderView = {
       
        let headerView = HeaderView(frame: CGRect(x: 0, y: 0, width: WIDTH, height: 44))
        
        headerView.backgroundColor = .red
        
        return headerView
        
    }()
    
    fileprivate lazy var tableView: UITableView = {
       
        let tableView = UITableView(frame: self.view.bounds, style: UITableView.Style.grouped)
        
        tableView.delegate = self
        
        tableView.dataSource = self
        
        tableView.register(UITableViewCell.self, forCellReuseIdentifier: "cell")
        
        return tableView
        
    }()

}

extension ViewController : UITableViewDelegate,UITableViewDataSource {
    
    func numberOfSections(in tableView: UITableView) -> Int {
        5
    }
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        40
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        
        let cell = tableView.dequeueReusableCell(withIdentifier: "cell", for: indexPath)

        cell.textLabel?.text = "\(indexPath.row)" + "cell"
        
        return cell
    }
    
    func tableView(_ tableView: UITableView, viewForHeaderInSection section: Int) -> UIView? {
        let v = UIView()
        
        v.backgroundColor = .green
        
        return v
    }
    
    func tableView(_ tableView: UITableView, heightForHeaderInSection section: Int) -> CGFloat {
        return 44
    }
    
    func tableView(_ tableView: UITableView, heightForFooterInSection section: Int) -> CGFloat {
        return 0.01
    }
}

class HeaderView: UIView {
    
    override init(frame: CGRect) {
        super.init(frame: frame)
        
        self.addSubview(selectView)
    }
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    lazy var selectView: UIView = {
        
        let view = UIView(frame: CGRect(x: 0, y: 0, width: WIDTH, height: 44))
        
        view.backgroundColor = .blue
        
        return view
    }()
    
}
