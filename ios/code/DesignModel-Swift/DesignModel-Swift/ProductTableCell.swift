//
//  ProductTableCell.swift
//  DesignModel-Swift
//
//  Created by WTW on 2021/1/13.
//  Copyright © 2021 WTW. All rights reserved.
//

import UIKit

class ProductTableCell: UITableViewCell {

    @IBOutlet weak var nameLabel: UILabel!
   
    @IBOutlet weak var descriptionLabel: UILabel!
    
    @IBOutlet weak var stockStepper: UIStepper!
    
    @IBOutlet weak var stockField: UITextField!
    
    var productId: Int?
    
    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }

    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }

}
