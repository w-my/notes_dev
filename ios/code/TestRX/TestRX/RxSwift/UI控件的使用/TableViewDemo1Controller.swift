//
//  TableViewDemo1Controller.swift
//  TestRX
//
//  Created by WTW on 2020/7/29.
//  Copyright © 2020 Mac. All rights reserved.
//

import UIKit
import RxSwift
import RxCocoa
import RxDataSources

class TableViewDemo1Controller: UIViewController {

    var tableView:UITableView!
        
    let disposeBag = DisposeBag()
        
    override func viewDidLoad() {
        super.viewDidLoad()

        //创建表格视图
        self.tableView = UITableView(frame: self.view.frame, style:.plain)
        //创建一个重用的单元格
        self.tableView!.register(UITableViewCell.self, forCellReuseIdentifier: "Cell")
        self.view.addSubview(self.tableView!)
         
        //初始化数据
        let items = Observable.just([
            "文本输入框的用法",
            "开关按钮的用法",
            "进度条的用法",
            "文本标签的用法",
            ])
        
        items.bind(to: tableView.rx.items) { (tableView, row, element) in
            let cell = tableView.dequeueReusableCell(withIdentifier: "Cell")!
            cell.textLabel?.text = "\(row)：\(element)"
            return cell
        }.disposed(by: disposeBag)
       
    }
    


}
