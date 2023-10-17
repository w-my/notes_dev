//
//  TraditionViewController.swift
//  TestRX
//
//  Created by WTW on 2020/7/28.
//  Copyright © 2020 Mac. All rights reserved.
//

import UIKit
import RxSwift

class TraditionViewController: UIViewController {

    var tableView: UITableView!
    
    //歌曲列表数据源
    let musicListViewModel = MusicListViewModel()
    
    override func viewDidLoad() {
        super.viewDidLoad()

        //创建表视图
        self.tableView = UITableView(frame:self.view.frame, style:.plain)
        self.tableView!.delegate = self
        self.tableView!.dataSource = self
        //创建一个重用的单元格
        self.tableView!.register(UITableViewCell.self,
                                 forCellReuseIdentifier: "SwiftCell")
        self.view.addSubview(self.tableView!)
    }
}

extension TraditionViewController : UITableViewDataSource,UITableViewDelegate {
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return musicListViewModel.data.count
    }

    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        
        let cell = tableView.dequeueReusableCell(withIdentifier: "SwiftCell")!
        let music = musicListViewModel.data[indexPath.row]
        cell.textLabel?.text = music.name
        cell.detailTextLabel?.text = music.singer
        return cell
    }
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        print("你选中的歌曲信息【\(musicListViewModel.data[indexPath.row])】")
    }
}

