//
//  ViewController.swift
//  UICollectionViewCustomLayout
//
//  Created by WTW on 2020/8/17.
//  Copyright © 2020 WTW. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
     
        self.view.addSubview(collectionView)
    }
    
    
    fileprivate lazy var collectionViewlayout: CustomFlowLayout = {
       
        let collectionViewlayout = CustomFlowLayout()
        
        collectionViewlayout.itemSize = CGSize(width: UIScreen.main.bounds.size.width / 4 , height: 100)
        
        collectionViewlayout.minimumLineSpacing = 0
        collectionViewlayout.minimumInteritemSpacing = 0
        
        return collectionViewlayout
        
    }()
    
    fileprivate lazy var collectionView: UICollectionView = {
        
        let collectionView = UICollectionView(frame: self.view.bounds, collectionViewLayout: collectionViewlayout)
        
        collectionView.delegate = self
        
        collectionView.dataSource = self
        
        
        collectionView.register(UINib(nibName: "CollectionViewCellTest1", bundle: nil), forCellWithReuseIdentifier: "CollectionViewCellTest1ID")
        
        
        collectionView.backgroundColor = .white
        
        return collectionView
        
    }()


}

extension ViewController : UICollectionViewDataSource ,UICollectionViewDelegate {
    
    func numberOfSections(in collectionView: UICollectionView) -> Int {
        return 3
    }
    
    func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        if section == 0 || section == 2 {
            return 4
        }
        return 1
    }
    
    func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
        let cell = collectionView.dequeueReusableCell(withReuseIdentifier: "CollectionViewCellTest1ID", for: indexPath) as! CollectionViewCellTest1
        
        cell.backgroundColor = .red
        
        return cell
    }
    
    
    
}

