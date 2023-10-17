//
//  ZoomTableViewController.swift
//  ZoomHeader
//
//  Created by WTW on 2021/1/14.
//  Copyright © 2021 WTW. All rights reserved.
//

import UIKit

class ZoomTableViewController: UITableViewController {

    
    lazy var userHeaderView: PagingViewTableHeaderView = preferredTableHeaderView()
    
    override func viewDidLoad() {
        super.viewDidLoad()

        tableView.register(UITableViewCell.self, forCellReuseIdentifier: "reuseIdentifier")
        
        tableView.tableHeaderView = userHeaderView
    }

    func preferredTableHeaderView() -> PagingViewTableHeaderView {
        return PagingViewTableHeaderView(frame: CGRect(x: 0, y: 0, width: UIScreen.main.bounds.size.width, height: 200))
    }
    
    override func scrollViewDidScroll(_ scrollView: UIScrollView) {
           
       var frame = userHeaderView.imageViewFrame
       frame.size.height -= scrollView.contentOffset.y
       frame.origin.y = scrollView.contentOffset.y
       userHeaderView.imageView.frame = frame
    }
    
    // MARK: - Table view data source

    override func numberOfSections(in tableView: UITableView) -> Int {
        return 10
    }

    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return 10
    }

    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        
        let cell = tableView.dequeueReusableCell(withIdentifier: "reuseIdentifier", for: indexPath)
                
        return cell
    }
   
   

}
