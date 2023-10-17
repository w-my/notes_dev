//
//  BaseCollectionController.swift
//  UICollectionViewLayout
//
//  Created by WTW on 2020/6/12.
//  Copyright © 2020 WTW. All rights reserved.
//

import UIKit

let headerHeght = CGFloat(150)

let CollectionViewCellTest1ID = "CollectionViewCellTest1ID"
let CollectionReusableViewHeaderID = "CollectionReusableViewHeaderID"
let CollectionReusableViewFooterID = "CollectionReusableViewFooterID"

class BaseCollectionController: UIViewController {
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        view.addSubview(collectionView)
        
        collectionView.addSubview(headerView)
        
    }
    
    // 瀑布流效果
    //    fileprivate lazy var collectionViewlayout: CustomLayout = {
    //
    //        let layout = CustomLayout()
    //
    //        layout.itemCount = 100
    //
    //        layout.scrollDirection = .vertical
    //
    //        return layout
    //    }()
    
    
    // 圆环效果布局
//    fileprivate lazy var collectionViewlayout: CustomCircleLayout = {
//        
//        let layout = CustomCircleLayout()
//        
//        layout.scrollDirection = .vertical
//        
//        return layout
//    }()
    
    fileprivate lazy var collectionView: UICollectionView = {
        
        let collectionView = UICollectionView(frame: self.view.bounds, collectionViewLayout: collectionViewlayout)
        
        collectionView.delegate = self
        
        collectionView.dataSource = self
        
        collectionView.contentInset = UIEdgeInsets(top: headerHeght, left: 0, bottom: 0, right: 0)
        
        collectionView.register(UINib(nibName: "CollectionViewCellTest1", bundle: nil), forCellWithReuseIdentifier: CollectionViewCellTest1ID)
        
        collectionView.register(UINib(nibName: "CollectionReusableViewHeader", bundle: nil), forSupplementaryViewOfKind: UICollectionView.elementKindSectionHeader, withReuseIdentifier: CollectionReusableViewHeaderID)
        
        collectionView.register(UINib(nibName: "CollectionReusableViewFooter", bundle: nil), forSupplementaryViewOfKind: UICollectionView.elementKindSectionFooter, withReuseIdentifier: CollectionReusableViewFooterID)
        
        collectionView.backgroundColor = UIColor.systemPink
        
        return collectionView
        
    }()
    
    fileprivate lazy var headerView: HeaderView = {
        
        let view = HeaderView()
        
        view.frame = CGRect(x: 0, y: -headerHeght, width: Width, height: headerHeght)
        
        view.backgroundColor = .red
        
        return view
    }()
    
}

//MARK:- UICollectionViewDataSource
extension BaseCollectionController : UICollectionViewDataSource {
    
    func numberOfSections(in collectionView: UICollectionView) -> Int {
        return 1
    }
    func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        return 100
    }
    func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
        
        let cell = collectionView.dequeueReusableCell(withReuseIdentifier: CollectionViewCellTest1ID, for: indexPath) as! CollectionViewCellTest1
        
        cell.titleLabel.text = "==\(indexPath.row)=="
        cell.bgImage.image = UIImage(named: "cashAlipy")
        
        return cell
    }
    
    func collectionView(_ collectionView: UICollectionView, viewForSupplementaryElementOfKind kind: String, at indexPath: IndexPath) -> UICollectionReusableView {
        
        if kind == UICollectionView.elementKindSectionHeader {
            
            let header = collectionView.dequeueReusableSupplementaryView(ofKind: UICollectionView.elementKindSectionHeader, withReuseIdentifier: CollectionReusableViewHeaderID, for: indexPath)
            
            return header
        }else {
            
            let footer = collectionView.dequeueReusableSupplementaryView(ofKind: UICollectionView.elementKindSectionFooter, withReuseIdentifier: CollectionReusableViewFooterID, for: indexPath)
            
            return footer
        }
    }
    
}

//MARK:- UICollectionViewDelegate
extension BaseCollectionController: UICollectionViewDelegate {
    
    func collectionView(_ collectionView: UICollectionView, didSelectItemAt indexPath: IndexPath) {
        print(collectionView.indexPathsForSelectedItems as Any)  // 所有选中的
    }
    
    func collectionView(_ collectionView: UICollectionView, didDeselectItemAt indexPath: IndexPath) {
        print(indexPath.section,indexPath.item)
    }
}

