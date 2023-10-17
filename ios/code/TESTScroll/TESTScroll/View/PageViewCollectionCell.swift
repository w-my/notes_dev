//
//  PageViewCollectionCell.swift
//  TESTScroll
//
//  Created by WTW on 2021/1/21.
//

import UIKit

protocol PageViewCellScrollDelegate : NSObjectProtocol{
    
    func pageViewCollectionCellDidScroll(cell:PageViewCollectionCell,scrollView:UIScrollView)
    
}

class PageViewCollectionCell: UICollectionViewCell {
 
    weak var delegate: PageViewCellScrollDelegate?
    
    override init(frame: CGRect) {
        super.init(frame: frame)
        
        setupUI()
    }
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    func setupUI() {
     
        addSubview(collectionView)
    }
    
    fileprivate lazy var collectionView: UICollectionView = {
       
        let layout = UICollectionViewFlowLayout()
        layout.itemSize = CGSize(width: UIScreen.main.bounds.size.width, height: CGFloat(arc4random_uniform(80)) + 30)
        layout.scrollDirection = .vertical
        
        let collectionview = UICollectionView(frame: CGRect.zero, collectionViewLayout: layout)
        collectionview.register(UICollectionViewCell.self, forCellWithReuseIdentifier: "PageViewCell")
        collectionview.backgroundColor = .white
        collectionview.contentInset = UIEdgeInsets(top: 190, left: 0, bottom: 0, right: 0)
        collectionview.dataSource = self
        return collectionview
    }()
    
    
    override func layoutSubviews() {
        super.layoutSubviews()
        
        collectionView.frame = self.bounds
        
        collectionView.delegate = self
    }
    
}

extension PageViewCollectionCell: UICollectionViewDataSource,UICollectionViewDelegate {
    
    func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        return 100
    }
    
    func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
        let cell = collectionView.dequeueReusableCell(withReuseIdentifier: "PageViewCell", for: indexPath)
        
        cell.backgroundColor =  UIColor(displayP3Red: CGFloat(arc4random_uniform(255))/255.0, green: CGFloat(arc4random_uniform(255))/255.0, blue: CGFloat(arc4random_uniform(255))/255.0, alpha: 1.0)
        
        return cell
    }
    
    func scrollViewDidScroll(_ scrollView: UIScrollView) {
        
        delegate?.pageViewCollectionCellDidScroll(cell: self, scrollView: scrollView)
        
//        print(collectionView.contentOffset.y)
    }
}

