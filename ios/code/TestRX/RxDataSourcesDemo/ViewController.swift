//
//  ViewController.swift
//  RxDataSourcesDemo
//
//  Created by WTW on 2022/3/31.
//  Copyright © 2022 Mac. All rights reserved.
//

import UIKit
import Then
import RxDataSources
import Reusable
import RxCocoa
import RxSwift

class ViewController: UIViewController {

    let disposebag: DisposeBag = DisposeBag()
    
    let dataSource = RxTableViewSectionedReloadDataSource<SectionOfCustomData<CustomData>>(configureCell: { datasource, tableView, index, item in
        let cell = tableView.dequeueReusableCell(for: index, cellType: CustomTableViewCell.self)
        cell.lable.text = item.name
        return cell
    })
    
    lazy var tableView = UITableView().then {
        $0.frame = UIScreen.main.bounds
        $0.tableFooterView = UIView()
        $0.register(cellType: CustomTableViewCell.self)
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
                
        view.addSubview(tableView)
      
        let section = SectionOfCustomData<CustomData>(header: "",
                                                      items: [CustomData(name: "lilei", age: 10),
                                                              CustomData(name: "lishi", age: 20),
                                                              CustomData(name: "wangwu", age: 30)])
        
        Observable.just([section]).bind(to: tableView.rx.items(dataSource: dataSource)).disposed(by: disposebag)
        
        Observable.zip(tableView.rx.itemSelected, tableView.rx.modelSelected(CustomData.self)).subscribe(onNext: { (index, item) in
            
            print(index.row,item.name)
            
        }).disposed(by: disposebag)
     
        tableView.rx.itemSelected.subscribe { (index) in
            print("选中索引 \(index)")
        }.disposed(by: disposebag)

        tableView.rx.modelSelected(CustomData.self).subscribe { (item) in
            print("选中内容 \(item)")
        }.disposed(by: disposebag)

    }
}



