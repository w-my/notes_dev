//
//  ViewController.swift
//  自定义刷新控件
//
//  Created by WTW on 2020/11/25.
//  Copyright © 2020 WTW. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    
    lazy var tableView: UITableView = {
        let tableView = UITableView(frame: self.view.bounds)
        tableView.delegate = self
        tableView.dataSource = self
        tableView.register(UITableViewCell.self, forCellReuseIdentifier: "cell")
        return tableView
    }()
    
    lazy var statusLabel: UILabel = {
        
       let statusLabel = UILabel(frame: CGRect(x: 0, y: 0, width: UIScreen.main.bounds.size.width, height: 30))
       statusLabel.text = "上拉可以加载更多..."
       statusLabel.textColor = .white
       statusLabel.textAlignment = .center
        return statusLabel
    }()
    
    lazy var footer: UIView = {
       
        let footer = UIView(frame: CGRect(x: 0, y: 0, width: UIScreen.main.bounds.size.width, height: 45))
        footer.backgroundColor = UIColor.red
        footer.addSubview(statusLabel)
        return footer
    }()
    
    /// 标识footer是否正在刷新
    var footerRefresing: Bool = false
    
    /// 标识是否正在下拉刷新
    var headerRefresing: Bool = false
    
    //********* header 刷新控件 ************//
    
    lazy var headerStatusLabel: UILabel = {
        
       let headerStatusLabel = UILabel(frame: CGRect(x: 0, y: 0, width: UIScreen.main.bounds.size.width, height: 50))
       headerStatusLabel.text = "下拉可以刷新..."
       headerStatusLabel.textColor = .white
       headerStatusLabel.textAlignment = .center
       return headerStatusLabel
    }()
    
    lazy var header: UIView = {
       
        let header = UIView(frame: CGRect(x: 0, y: -50, width: UIScreen.main.bounds.size.width, height: 50))
        header.backgroundColor = UIColor.red
        header.addSubview(headerStatusLabel)
        return header
    }()
    
    //*********************************//
    
    lazy var tableVieHeader: UILabel = {
       
        let header = UILabel(frame: CGRect(x: 0, y: 0, width: UIScreen.main.bounds.size.width, height: 40))
        header.text = "header"
        header.backgroundColor = .green
        header.textAlignment = .center
        header.textColor = .white
        return header
    }()
    
    /// 数据源
    var dataCount: Int = 30
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.view.addSubview(tableView)
        
//        header 不能这样给，因为用户可能会直接使用headerview
//        self.tableView.tableHeaderView = header
        self.tableView.tableHeaderView = tableVieHeader
        
        // 所以下拉刷新的控件可以通过添加到tabelView 上来实现，而不是作为 headerview
        self.tableView.addSubview(header)
        
        self.tableView.tableFooterView = footer
        
    }
   
    func scrollViewDidScroll(_ scrollView: UIScrollView) {
            
        // 处理header
        handleHeader()
        
        // 处理footer
        handleFooter()
    }
    
    /// 一共是三种状态 下拉刷新
    func scrollViewDidEndDragging(_ scrollView: UIScrollView, willDecelerate decelerate: Bool) {
        
        let offsetY = -(self.tableView.contentInset.top + self.header.frame.height + 64)
                
        if self.tableView.contentOffset.y <= offsetY {
            self.headerStatusLabel.text = "正在刷新数据。。。。"
            self.headerStatusLabel.backgroundColor = .blue
            self.headerRefresing = true
            
            /// 为了让刷新的状态保持，不至于立马回弹回去，通过增加顶部内边距的方法解决
            UIView.animate(withDuration: 0.25) {
                var inset = self.tableView.contentInset
                inset.top += self.header.frame.height
                self.tableView.contentInset = inset
            }
            
            // 在这里发送网络请求
            DispatchQueue.main.asyncAfter(deadline: .now() + 3) {
                
                print("数据回来了")
                
                self.dataCount = 10
                self.tableView.reloadData()
                
                // 结束刷新
                self.headerRefresing = false
                // 减回内边距
                UIView.animate(withDuration: 0.25) {
                    var inset = self.tableView.contentInset
                    inset.top -= self.header.frame.height
                    self.tableView.contentInset = inset
                }
                
            }
        }
    }
    
    /// 处理下拉刷新
    func handleHeader()  {
       
        /// 如果正在下拉刷新 直接return
        if self.headerRefresing { return }
        
        // 当 scrollview 的偏移量y值 <= offsetY 时，代表 header 已经完全出现
        let offsetY = -(self.tableView.contentInset.top + self.header.frame.height + 64)
        
        print(self.tableView.contentInset.top,self.tableView.contentOffset.y,offsetY)
        
        if self.tableView.contentOffset.y <= offsetY { // header 完全展示
            self.headerStatusLabel.text = "松开立即刷新"
            self.headerStatusLabel.backgroundColor = .gray
        }else {
            self.headerStatusLabel.text = "下拉可以刷新"
            self.headerStatusLabel.backgroundColor = .red
        }
    }
    
    /// 处理上拉加载更多
    func handleFooter()  {
        
        // 还没有内容的时候不处理
        if self.tableView.contentSize.height == 0 { return }
        
        // 如果正在刷新 直接返回
        if footerRefresing { return }
        
        // 当scrollView 的偏移量y值 >= offsetY 时代表 footer 已经完全出现
        let offsetY = self.tableView.contentSize.height - self.tableView.frame.height
        
//        print(self.tableView.contentOffset.y,self.tableView.frame.height,offsetY)
        
        // self.tableView.contentOffset.y > -(self.tableView.contentInset.top) ，目的是为了避免在数据比较少的时候，下拉会触发上拉的处理去请求数据
        if self.tableView.contentOffset.y >= offsetY && self.tableView.contentOffset.y > -(self.tableView.contentInset.top){
                        
            // 进入刷新状态
            footerRefresing = true
            
            self.statusLabel.text = "正在加载更多数据....."
            self.statusLabel.textColor = .blue
            
            //发送请求
            print("上拉刷新发送请求数据")
            DispatchQueue.main.asyncAfter(deadline: .now() + 2) {
                
                self.dataCount += 10
                self.tableView.reloadData()
                
                /// 结束刷新
                self.footerRefresing = false
                
                self.statusLabel.text = "上拉可以加载更多...."
                self.statusLabel.textColor = .white
                
            }
        }
        
    }

}

extension ViewController: UITableViewDelegate, UITableViewDataSource {
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        
        /// 没有数据的时候隐藏
        self.footer.isHidden = (self.dataCount == 0)
        
        return self.dataCount
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        
        let cell = tableView.dequeueReusableCell(withIdentifier: "cell", for: indexPath)
        
        cell.textLabel?.text = "\(indexPath.row)"
        
        return cell
    }
    
}

