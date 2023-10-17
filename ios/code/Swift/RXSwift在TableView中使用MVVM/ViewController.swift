//
//  ViewController.swift
//  RXSwift在TableView中使用MVVM
//
//  Created by WTW on 2020/3/25.
//  Copyright © 2020 WTW. All rights reserved.
//

import UIKit
import RxSwift
import RxCocoa

class ViewController: UIViewController {

    fileprivate var heros: [Hero]?
    fileprivate var tableview: UITableView = UITableView()
    fileprivate var bag: DisposeBag = DisposeBag()
        
    let heroVM = HeroViewModel()
    
    override func viewDidLoad() {
        super.viewDidLoad()
       
        tableview.frame = view.bounds
        view.addSubview(tableview)
        tableview.register(UITableViewCell.classForCoder(), forCellReuseIdentifier: "cell")
               
        heroVM.herosObserable.asObservable()
            .bindTo(tableview.rx.items(cellIdentifier: "cell", cellType: UITableViewCell.self)) { row,hero,cell in
            cell.textLabel?.text = hero.name
            cell.detailTextLabel?.text = hero.intro
            cell.imageView?.image = UIImage(named: hero.icon)
        }.disposed(by: bag)
        
        // 点击
        tableview.rx.itemSelected.subscribe(onNext: { (indexPath) in
          print(indexPath)
            }).disposed(by: bag)
        
        // 点击获取数据
        tableview.rx.modelSelected(Hero.self).subscribe(onNext: { (Hero) in
            print(Hero.name)
            }).disposed(by: bag)
    }
}

