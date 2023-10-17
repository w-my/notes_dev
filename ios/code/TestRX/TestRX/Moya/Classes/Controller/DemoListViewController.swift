//
//  DemoListViewController.swift
//  TestRX
//
//  Created by WTW on 2020/7/30.
//  Copyright © 2020 Mac. All rights reserved.
//

import UIKit
import RxCocoa
import RxSwift
import RxDataSources
import Reusable

class DemoListViewController: UIViewController {

        
    fileprivate lazy var tabelView: UITableView = {
       
        let tableView = UITableView(frame: view.bounds, style: .plain)
        
        tableView.register(cellType: DemoListTableViewCell.self)
        
        return tableView
    }()
    
    override func viewDidLoad() {
        super.viewDidLoad()

        self.view.addSubview(tabelView)
        
        let dataSource = RxTableViewSectionedReloadDataSource<DemoListSection> (configureCell: { dataSource, tableView, indexPath, item -> UITableViewCell in
            
            let cell = tableView.dequeueReusableCell(for: indexPath) as DemoListTableViewCell
            
            cell.textLabel?.text = item.name
            
            return cell
            
        })
        
                    
        Network.request(.channels, success: { (result) in
            print(result)
        }) { (error) in
            print(error)
        }
    }
    
}


