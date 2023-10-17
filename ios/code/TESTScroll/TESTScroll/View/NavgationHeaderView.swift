//
//  NavgationHeaderView.swift
//  TESTScroll
//
//  Created by WTW on 2021/1/22.
//

import UIKit

class NavgationHeaderView: UIView {

    override init(frame: CGRect) {
        super.init(frame: frame)
        
        addSubview(searchView)
        
        searchView.snp.makeConstraints { (make) in
            make.height.equalTo(34)
            make.left.equalToSuperview().offset(10)
            make.top.equalToSuperview().offset(65)
            make.right.equalToSuperview().offset(-10)
        }
    }
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    fileprivate lazy var searchView: UIView = {
        
        let searchView = UIView()
        searchView.layer.cornerRadius = 3
        searchView.backgroundColor = .red
        return searchView
    }()
    
    public func updateSearchViewFrame(offset:CGFloat) {
    
        let offsetW = UIScreen.main.bounds.size.width * 0.3
        
                    
        // 临界点 -110
        if offset > -110 {
            
            let topOffsetH = 110 - abs(offset)
            let topScale = topOffsetH / 110
            let offsetValue = 65 * topScale
            
            let offsetTop = offset > 0 ? 25 : ((65-offsetValue) < 25 ? 25 : 65-offsetValue)
            
//            print(offset,topOffsetH,topScale,offsetValue,offsetTop)
            
            searchView.snp.updateConstraints { (make) in
                
                make.right.equalToSuperview().offset(-(offsetW + 10))
                make.top.equalToSuperview().offset(offsetTop)
            }
            
        }else {
            
            let offsetH = 190 - abs(offset)
            let scale = offsetH / 80
            let rightOffset = offsetW * scale + 10 < 10 ? 10 : offsetW * scale + 10
            
            searchView.snp.updateConstraints { (make) in
                
                make.right.equalToSuperview().offset(-rightOffset)
            }
            
        }
    }
    
}
