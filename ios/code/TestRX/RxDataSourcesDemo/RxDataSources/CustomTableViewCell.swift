//
//  CustomTableViewCell.swift
//  RxDataSourcesDemo
//
//  Created by WTW on 2022/3/31.
//  Copyright © 2022 Mac. All rights reserved.
//

import UIKit
import Reusable

class CustomTableViewCell: UITableViewCell,Reusable {

    override init(style: UITableViewCell.CellStyle, reuseIdentifier: String?) {
        super.init(style: style, reuseIdentifier: reuseIdentifier)
        addSubview(lable)
        lable.frame = self.bounds
    }
    
    var lable: UILabel = UILabel().then {
        $0.font = UIFont.systemFont(ofSize: 20)
    }
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }

}
