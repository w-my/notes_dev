//
//  ViewController.swift
//  UICollectionView
//
//  Created by WTW on 2020/6/5.
//  Copyright © 2020 WTW. All rights reserved.
// https://blog.csdn.net/LVXIANGAN/article/details/73826108?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.nonecase&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.nonecase

import UIKit

let Width = UIScreen.main.bounds.size.width
let Height = UIScreen.main.bounds.size.height

let headerHeght = CGFloat(150)

let CollectionViewCellTest1ID = "CollectionViewCellTest1ID"
let CollectionReusableViewHeaderID = "CollectionReusableViewHeaderID"
let CollectionReusableViewFooterID = "CollectionReusableViewFooterID"

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
       
        view.addSubview(collectionView)
        
        collectionView.addSubview(headerView)
        
        self.navigationItem.rightBarButtonItem = UIBarButtonItem(title: "Click", style: .plain, target: self, action: #selector(BtnClick))
    }

    @ objc func BtnClick() {
        
        let index = IndexPath(item: 10, section: 0)
        
        collectionView.scrollToItem(at: index, at: .top, animated: true)
        
    }
    
    fileprivate lazy var collectionViewlayout: UICollectionViewFlowLayout = {

        let layout = UICollectionViewFlowLayout()

        layout.scrollDirection = .vertical

//        layout.itemSize = CGSize(width: ((Width - 20)/2 - 5) , height: 100)

//        layout.minimumLineSpacing = 5
//
//        layout.minimumInteritemSpacing = 5

        // 设置头部 尾部 Size
//        layout.headerReferenceSize = CGSize(width: Width, height: 45)
//
//        layout.footerReferenceSize = CGSize(width: Width , height: 35)

        layout.sectionInset = UIEdgeInsets(top: 0, left: 10, bottom: 0, right: 10)
        
        // section header 的悬浮 iOS9 以后才支持
        // sectionHeadersPinToVisibleBounds
        layout.sectionHeadersPinToVisibleBounds = true

        return layout
    }()
    
    
    fileprivate lazy var collectionView: UICollectionView = {
        
        let collectionView = UICollectionView(frame: self.view.bounds, collectionViewLayout: collectionViewlayout)
        
        collectionView.delegate = self
        
        collectionView.dataSource = self
        
//        collectionView.contentInset = UIEdgeInsets(top: 10, left: 10, bottom: 0, right: 10)
        
        collectionView.contentInset = UIEdgeInsets(top: headerHeght, left: 0, bottom: 0, right: 0)
        
        collectionView.register(UINib(nibName: "CollectionViewCellTest1", bundle: nil), forCellWithReuseIdentifier: CollectionViewCellTest1ID)
        
        collectionView.register(UINib(nibName: "CollectionReusableViewHeader", bundle: nil), forSupplementaryViewOfKind: UICollectionView.elementKindSectionHeader, withReuseIdentifier: CollectionReusableViewHeaderID)
        
        collectionView.register(UINib(nibName: "CollectionReusableViewFooter", bundle: nil), forSupplementaryViewOfKind: UICollectionView.elementKindSectionFooter, withReuseIdentifier: CollectionReusableViewFooterID)
        
        collectionView.backgroundColor = UIColor.systemPink
        
        collectionView.allowsMultipleSelection = true  // 允许多选
        
        return collectionView
        
    }()
    
    fileprivate lazy var headerView: HeaderView = {
       
        let view = HeaderView()
        
        view.frame = CGRect(x: 0, y: -headerHeght, width: Width, height: headerHeght)
        
        view.backgroundColor = .red
        
        return view
    }()
    
    // 可以重新设置 collection 的布局  实现这两个方法可以实现炫酷的动画效果
    //collectionView.setCollectionViewLayout(<#T##layout: UICollectionViewLayout##UICollectionViewLayout#>, animated: <#T##Bool#>)
    //collectionView.setCollectionViewLayout(<#T##layout: UICollectionViewLayout##UICollectionViewLayout#>, animated: <#T##Bool#>, completion: <#T##((Bool) -> Void)?##((Bool) -> Void)?##(Bool) -> Void#>)
    
}

//MARK:- UICollectionViewDataSource
extension ViewController : UICollectionViewDataSource {
    
    func numberOfSections(in collectionView: UICollectionView) -> Int {
        return 3
    }
    func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        return 20
    }
    func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
        
        let cell = collectionView.dequeueReusableCell(withReuseIdentifier: CollectionViewCellTest1ID, for: indexPath) as! CollectionViewCellTest1
        
        cell.labelText.text = "\(indexPath.section)"
        
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
extension ViewController: UICollectionViewDelegate {
    
    func collectionView(_ collectionView: UICollectionView, didSelectItemAt indexPath: IndexPath) {
        print(collectionView.indexPathsForSelectedItems as Any)  // 所有选中的
    }
    
    func collectionView(_ collectionView: UICollectionView, didDeselectItemAt indexPath: IndexPath) {
        print(indexPath.section,indexPath.item)
    }
}

//MARK:- UICollectionViewDelegateFlowLayout
extension ViewController: UICollectionViewDelegateFlowLayout {
    
    func collectionView(_ collectionView: UICollectionView, layout collectionViewLayout: UICollectionViewLayout, sizeForItemAt indexPath: IndexPath) -> CGSize {
        return CGSize(width: ((Width - 20 - 5)/2 ) , height: 100)
    }
    
    func collectionView(_ collectionView: UICollectionView, layout collectionViewLayout: UICollectionViewLayout, minimumLineSpacingForSectionAt section: Int) -> CGFloat {
        return 5
    }
    
    func collectionView(_ collectionView: UICollectionView, layout collectionViewLayout: UICollectionViewLayout, minimumInteritemSpacingForSectionAt section: Int) -> CGFloat {
        return 5
    }
    
    func collectionView(_ collectionView: UICollectionView, layout collectionViewLayout: UICollectionViewLayout, referenceSizeForHeaderInSection section: Int) -> CGSize {
        return CGSize(width: Width, height: 45)
    }

    func collectionView(_ collectionView: UICollectionView, layout collectionViewLayout: UICollectionViewLayout, referenceSizeForFooterInSection section: Int) -> CGSize {
        return CGSize(width: Width, height: 65)
    }
    
}
