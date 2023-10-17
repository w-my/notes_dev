//
//  CustomFlowLayout.swift
//  UICollectionViewCustomLayout
//
//  Created by WTW on 2020/8/17.
//  Copyright © 2020 WTW. All rights reserved.
//

import UIKit

class CustomFlowLayout: UICollectionViewFlowLayout {

    override func layoutAttributesForElements(in rect: CGRect) -> [UICollectionViewLayoutAttributes]? {
        
        let attributesArr = super.layoutAttributesForElements(in: rect)!
        
        for attr in attributesArr {
            
            if attr.indexPath.section == 1 {
               
                var frame = attr.frame
                
                frame.size.width = (self.collectionView?.bounds.size.width)!
                frame.size.height = frame.size.height * 2
                
                attr.frame = frame
                
            }
            
            if (attr.indexPath.section == 2) {
                
                var  frame = attr.frame;
                
                frame.origin.y += frame.size.height;
                
                attr.frame = frame;
            }
            
        }
     
        return attributesArr
        
    }
    
}
