//
//  CustomCircleLayout.swift
//  UICollectionViewLayout
//
//  Created by WTW on 2020/7/16.
//  Copyright © 2020 WTW. All rights reserved.
//

import UIKit

class CustomCircleLayout: UICollectionViewFlowLayout {

    /// 定义存储多少个 item
    var itemCount = 0
    
    var attributeArray = Array<Any>()
 
    
    override func prepare() {
        super.prepare()
        
        itemCount = self.collectionView?.numberOfItems(inSection: 0) ?? 0
        
        // 设定大圆的半径 取长和宽最短的
        var radius = 0
        
        if Int(self.collectionView?.frame.size.width ?? 0) > Int(self.collectionView?.frame.size.height ?? 0) {
            radius = Int(self.collectionView?.frame.size.height ?? 0) / 2
        }else {
            radius = Int(self.collectionView?.frame.size.width ?? 0) / 2
        }
        
        // 计算圆心位置
        let center: CGPoint = CGPoint(x: (self.collectionView?.frame.size.width ?? 0) / 2.0, y: (self.collectionView?.frame.size.height ?? 0)/2.0)
        
        // 设置每个 item 的大小为 50 * 50  则半径为 25
        for i in 0..<itemCount {
            let attris =  UICollectionViewLayoutAttributes(forCellWith: IndexPath(item: i, section: 0))
            
            // 设置 item 大小
            attris.size = CGSize(width: 50, height: 50)
            // 计算每个 item 的圆心位置
            let x: Float = Float(center.x) + cosf(Float(2*M_PI/Double(itemCount)*Double(i)))*(Float(radius) - 25)
            let y: Float = Float(center.y) + sinf(Float(2*M_PI/Double(itemCount)*Double(i)))*(Float(radius) - 25)
            
            attris.center = CGPoint(x: CGFloat(x), y: CGFloat(y))
            attributeArray.append(attris)
        }
        
        
    }
    
   
    
    override func layoutAttributesForElements(in rect: CGRect) -> [UICollectionViewLayoutAttributes]? {
        return attributeArray as? [UICollectionViewLayoutAttributes]
    }
}
