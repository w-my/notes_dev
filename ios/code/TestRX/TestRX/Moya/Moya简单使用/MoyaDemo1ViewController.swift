//
//  MoyaDemo1ViewController.swift
//  TestRX
//
//  Created by WTW on 2020/7/28.
//  Copyright © 2020 Mac. All rights reserved.
//   

import UIKit
import SwiftyJSON

class MoyaDemo1ViewController: UIViewController {

    // 显示频道列表的 tableView
    var tableView: UITableView!
    
    // 频道列表数据
    var channels: Array<JSON> = []
    
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
        
        // 使用 provider 进行网络请求
        DouBanProvider.request(.channels) { result in
           if case let .success(response) = result {
                //解析数据
                let data = try? response.mapJSON()
                let json = JSON(data!)
                self.channels = json["channels"].arrayValue

                //刷新表格数据
                DispatchQueue.main.async{
                    self.tableView.reloadData()
                }
            }

        }
        
    }
}


extension MoyaDemo1ViewController : UITableViewDataSource,UITableViewDelegate {
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return channels.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "SwiftCell", for: indexPath)
        cell.accessoryType = .disclosureIndicator
        cell.textLabel?.text = channels[indexPath.row]["name"].stringValue
        return cell
    }
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        let channelName = channels[indexPath.row]["name"].stringValue
        let channelId = channels[indexPath.row]["channel_id"].stringValue
        //使用我们的provider进行网络请求（根据频道ID获取下面的歌曲）
//        DouBanProvider.request(.playlist(channelId)) { result in
//            if case let .success(response) = result {
//                //解析数据，获取歌曲信息
//                let data = try? response.mapJSON()
//                let json = JSON(data!)
//                let music = json["song"].arrayValue[0]
//                let artist = music["artist"].stringValue
//                let title = music["title"].stringValue
//                let message = "歌手：\(artist)\n歌曲：\(title)"
//
//                //将歌曲信息弹出显示
//                self.showAlert(title: channelName, message: message)
//            }
//        }
        
        // 使用 adapter 请求数据
//        Network.request(.playlist(channelId), success: { json in
//            //获取歌曲信息
//            let music = json["song"].arrayValue[0]
//            let artist = music["artist"].stringValue
//            let title = music["title"].stringValue
//            let message = "歌手：\(artist)\n歌曲：\(title)"
//            //将歌曲信息弹出显示
//            self.showAlert(title: channelName, message: message)
//        }, error: { statusCode in
//            //服务器报错等问题
//            print("请求错误！错误码：\(statusCode)")
//        }, failure: { error in
//            //没有网络等问题
//            print("请求失败！错误信息：\(error.errorDescription ?? "")")
//        })
        
    }
    
    func showAlert(title:String, message:String){
        let alertController = UIAlertController(title: title,
                                                message: message, preferredStyle: .alert)
        let cancelAction = UIAlertAction(title: "确定", style: .cancel, handler: nil)
        alertController.addAction(cancelAction)
        self.present(alertController, animated: true, completion: nil)
    }
}
