//
//  TDBeautifulGirlCell.swift
//  RXDemo1
//
//  Created by WTW on 2020/11/11.
//  Copyright © 2020 WTW. All rights reserved.
//

import UIKit
import Kingfisher
import SnapKit
import Reusable

class TDBeautifulGirlCell: UICollectionViewCell,Reusable {
    
    var model: TDGirlModel? {
    
        didSet {
            
            guard let model = model else { return }
            
            imgView.kf.setImage(with: URL(string: model.thumb_url))
            
        }
    }
    
    override init(frame: CGRect) {
        super.init(frame: frame)
        
        addSubview(imgView)
        imgView.snp.makeConstraints { (make) in
            make.edges.equalToSuperview()
        }
    }
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    fileprivate lazy var imgView: UIImageView = {
       
        let img = UIImageView()
        
        img.contentMode = .scaleToFill
        
        return img
    }()
    
}
