//
//  CustomLayout.swift
//  UICollectionViewLayout
//
//  Created by WTW on 2020/6/5.
//  Copyright © 2020 WTW. All rights reserved.
//  https://my.oschina.net/u/2340880/blog 

import UIKit

class CustomLayout: UICollectionViewFlowLayout {

    // 外界传参 item 个数
    var itemCount: Int = 0
    
    // 自定义的item 配置数组
    fileprivate lazy var attributeArray: [UICollectionViewLayoutAttributes] = []
    
    // 布局前的准备会调用这个方法
    override func prepare() {
        super.prepare()

        // 计算每一个 item 大小
        // 此处写死 2列
        let itemWidth: CGFloat = (UIScreen.main.bounds.width - self.sectionInset.left - self.sectionInset.right - self.minimumInteritemSpacing) / 2
        
        // 定义数组保存每一列的高度
        // 这个数组的左右是保存每一列的总高度 这样在布局是总是吧 item 放在最短的那列中
        var colHight = [self.sectionInset.top,self.sectionInset.bottom]
        
        // 遍历外界传入的 item ,设置每一个 item 的大小
        for i in 0..<itemCount {
            
            //设置每个 item 的位置相关属性
            let index = IndexPath(row: i, section: 0)
            
            // 创建一个布局属性类 通过 indexPath 来创建
            let attris = UICollectionViewLayoutAttributes(forCellWith: index)
            
            // 随机一个高度
            let height: CGFloat = CGFloat(arc4random()%150 + 40)
            
            // 哪一列高度小 放在那一列下面
            // 标记最短的列
            var width = 0
            if colHight[0] < colHight[1] {
                // 将新的 item 高度加入到短的一列
                colHight[0] = CGFloat(colHight[0]) + height + self.minimumLineSpacing
                width = 0
            }else {
                colHight[1] = CGFloat(colHight[1]) + height + self.minimumLineSpacing
                width = 1
            }
            
            // 设置 item 的位置
            attris.frame = CGRect(x: self.sectionInset.left + (self.minimumInteritemSpacing + itemWidth) * CGFloat(width), y: colHight[width] - height - self.minimumLineSpacing, width: itemWidth, height: height)
            attributeArray.append(attris)
        }
        
        // 设置 itemSize 来确保滑动范围的正确， 这里通过将所有的 item 高度平均化 计算出来的(以最高的列为标准)
        if colHight[0] > colHight[1] {
            self.itemSize = CGSize(width: itemWidth, height: (colHight[0] - self.sectionInset.top)*2/CGFloat(itemCount) - self.minimumLineSpacing)
        }else {
            self.itemSize = CGSize(width: itemWidth, height: (colHight[1] - self.sectionInset.top)*2/CGFloat(itemCount) - self.minimumLineSpacing)
        }
    }
    
    override func layoutAttributesForElements(in rect: CGRect) -> [UICollectionViewLayoutAttributes]? {
        return attributeArray as? [UICollectionViewLayoutAttributes]
    }
    
}
