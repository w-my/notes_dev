//
//  RedView.swift
//  性能优化
//
//  Created by WTW on 2022/5/5.
//  Copyright © 2022 wtw. All rights reserved.
//

import UIKit

class RedView: UIView {
    
    /// 如果使用 CALayer 绘图只能在如下方法中绘制
    /// 或者在delegate中的相应方法绘制
    /// 同样也是调用setNeedDisplay等间接调用以上方法
//    override func draw(_ layer: CALayer, in ctx: CGContext) {
//
//    }
    
   
    // Only override draw() if you perform custom drawing.
    // An empty implementation adversely affects performance during animation.
    override func draw(_ rect: CGRect) {
        
        print(" == draw ==")
        
    }
       
    /// 对子控件进行重新布局
    override func layoutSubviews() {
        
        print(" == layoutSubviews ==")
        
        
    }

    override init(frame: CGRect) {
        super.init(frame: frame)
       
        addSubview(scrollView)
        
    }
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    fileprivate lazy var scrollView : UIScrollView = {
       
        let scrollView = UIScrollView()
        scrollView.backgroundColor = .green
        scrollView.contentSize = CGSize(width: 100, height: 100)
        scrollView.frame = CGRect(x: 0, y: 0, width: 50, height: 50)
        return scrollView
    }()
    
}
