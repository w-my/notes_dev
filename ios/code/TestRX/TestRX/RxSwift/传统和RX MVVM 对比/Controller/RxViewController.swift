//
//  TraditionViewController.swift
//  TestRX
//
//  Created by WTW on 2020/7/28.
//  Copyright © 2020 Mac. All rights reserved.
//  https://www.hangge.com/blog/cache/detail_1922.html

import UIKit
import RxSwift
import RxCocoa

class RxViewController: UIViewController {

    var tableView: UITableView!
    
    //歌曲列表数据源
    let musicListViewModel = MusicListRxViewModel()
     
    //负责对象销毁
    let disposeBag = DisposeBag()
    
    override func viewDidLoad() {
        super.viewDidLoad()

        //创建表视图
        self.tableView = UITableView(frame:self.view.frame, style:.plain)
        
        //创建一个重用的单元格
        self.tableView!.register(UITableViewCell.self,
                                 forCellReuseIdentifier: "SwiftCell")
        
        self.view.addSubview(self.tableView!)
        
        // 将数据绑定到 tableView 上
        musicListViewModel.data.bind(to: tableView.rx.items(cellIdentifier:"SwiftCell")){ _, music, cell in
            cell.textLabel?.text = music.name
            cell.detailTextLabel?.text = music.singer
        }.disposed(by: disposeBag)
        
        // tableView 点击响应
        tableView.rx.modelSelected(Music.self).subscribe(onNext: { music in
             print("你选中的歌曲信息【\(music)】")
            }).disposed(by: disposeBag)
    }
}


