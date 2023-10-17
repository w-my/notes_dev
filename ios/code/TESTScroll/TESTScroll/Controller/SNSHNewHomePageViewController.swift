//
//  ViewController.swift
//  TESTScroll
//
//  Created by WTW on 2021/1/21.
//


/**
 *
 * SNSHScrollPageContentView
 *   SNSHScrollPageCollectionView
 *       UICollectionViewCell
 *          SNHomeCollectionView
 *          SNSHGuessYouLikeSliderBar
 * SNSHHeadSearchView
 * SNSHTPSliderHeader
 *
 */

import UIKit
import SnapKit

class SNSHNewHomePageViewController: UIViewController {

    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        navigationController?.navigationBar.isHidden = true
    }
    
    override func viewDidDisappear(_ animated: Bool) {
        super.viewDidDisappear(animated)
        
        navigationController?.navigationBar.isHidden = false
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
               
        setupUI()
    }
    

    func setupUI()  {
        
        view.addSubview(collectionView)
        view.addSubview(sliderView)
        view.addSubview(navigationView)
        
        
        navigationView.snp.makeConstraints { (make) in
            make.left.right.equalToSuperview()
            make.top.equalToSuperview()
            make.height.equalTo(160)
        }
        
        sliderView.snp.makeConstraints { (make) in
            make.left.right.equalToSuperview()
            make.height.equalTo(40)
            make.top.equalToSuperview().offset(160)
        }
        
    }
    
    fileprivate lazy var scrollView: UIScrollView = {
       
        let scrollView = UIScrollView()
        scrollView.delegate = self
        return scrollView
    }()

    /// collectionview
    fileprivate lazy var collectionView: UICollectionView  = {
        
        let layout = UICollectionViewFlowLayout()
        layout.scrollDirection = .horizontal
        layout.minimumLineSpacing = 0
        layout.minimumInteritemSpacing = 0
//        layout.itemSize = CGSize(width: UIScreen.main.bounds.size.width, height: UIScreen.main.bounds.size.height - 200)
        layout.itemSize = CGSize(width: UIScreen.main.bounds.size.width, height: UIScreen.main.bounds.size.height)
        
        let collectionView = UICollectionView(frame: view.bounds, collectionViewLayout: layout)
        collectionView.register(PageViewCollectionCell.self, forCellWithReuseIdentifier: "collectionView")
        collectionView.delegate = self
        collectionView.dataSource = self
        collectionView.isPagingEnabled = true
        collectionView.backgroundColor = .systemPink
//        collectionView.contentInset = UIEdgeInsets(top: 180, left: 0, bottom: 0, right: 0)
        return collectionView
    }()
    
    /// sliderview
    fileprivate lazy var sliderView: UIView = {
       
        let sliderView = UIView(frame: CGRect(x: 0, y: 140, width: UIScreen.main.bounds.size.width, height: 40))
        sliderView.backgroundColor = .red
        return sliderView
    }()
    
    /// nav
    fileprivate lazy var navigationView: NavgationHeaderView = {
       
        let navigationView = NavgationHeaderView(frame: CGRect(x: 0, y: 0, width: UIScreen.main.bounds.size.width, height: 140))
        navigationView.backgroundColor = .brown
        return navigationView
    }()
}

extension SNSHNewHomePageViewController: UICollectionViewDataSource,UICollectionViewDelegate {
    
    func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        return 5
    }
    
    func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
        
        let cell = collectionView.dequeueReusableCell(withReuseIdentifier: "collectionView", for: indexPath) as! PageViewCollectionCell
        
        cell.backgroundColor = UIColor(displayP3Red: CGFloat(arc4random_uniform(255))/255.0, green: CGFloat(arc4random_uniform(255))/255.0, blue: CGFloat(arc4random_uniform(255))/255.0, alpha: 1.0)
        
        cell.delegate = self
        
        return cell
    }
    
}

extension SNSHNewHomePageViewController : UIScrollViewDelegate {
    
    func scrollViewDidScroll(_ scrollView: UIScrollView) {
        
        print("contentOffset == \(scrollView.contentOffset)");
    }
}

extension SNSHNewHomePageViewController: PageViewCellScrollDelegate {
    
    func pageViewCollectionCellDidScroll(cell: PageViewCollectionCell, scrollView: UIScrollView) {
        
        print(scrollView.contentOffset.y)
        
        let offsetY = scrollView.contentOffset.y
        
        /// 处理顶部选项
        if offsetY >= -190 {  // 向上滑动
            
            if offsetY > -110 {
                
                let heightOffset = 110 - abs(offsetY) > 80 ? 80 : 110 - abs(offsetY)
                
                /// 大于0 情况待处理
                sliderView.snp.updateConstraints { (make) in
                    
                    make.top.equalToSuperview().offset(160-heightOffset)
                }
            }else {
                
                sliderView.snp.updateConstraints { (make) in
                    make.top.equalToSuperview().offset(160)
                }
            }
        }else { // 向下滑动
            
            sliderView.snp.updateConstraints { (make) in
                make.top.equalToSuperview().offset(abs(offsetY) - 30)
            }
        }
        
        /// 处理搜索框
        navigationView.updateSearchViewFrame(offset:offsetY)
        
        if offsetY > -110 {
            
            let heightOffset = 110 - abs(offsetY)
            
            if offsetY < -30 {
                
                navigationView.snp.updateConstraints { (make) in
                    make.height.equalTo(160 - heightOffset)
                }
            }else {
                
                navigationView.snp.updateConstraints { (make) in
                    make.height.equalTo(80)
                }
            }
        }
    }
    
}
