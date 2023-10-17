//
//  CollectionRefreshViewController.swift
//  TestRX
//
//  Created by WTW on 2020/7/28.
//  Copyright © 2020 Mac. All rights reserved.
//

import UIKit
import RxSwift
import RxCocoa
import RxDataSources

class CollectionRefreshViewController: UIViewController {

    var collectionView:UICollectionView!
    
    let disposeBag = DisposeBag()
    
    override func viewDidLoad() {
        super.viewDidLoad()

        self.navigationItem.rightBarButtonItem = UIBarButtonItem(title: "刷新", style: .plain, target: self, action: #selector(refreshClick))
        
        //定义布局方式以及单元格大小
        let flowLayout = UICollectionViewFlowLayout()
        flowLayout.itemSize = CGSize(width: 100, height: 70)
         
        //创建集合视图
        self.collectionView = UICollectionView(frame: self.view.frame,
                                               collectionViewLayout: flowLayout)
        self.collectionView.backgroundColor = UIColor.white
        
        //创建一个重用的单元格
        self.collectionView.register(Demo1CollectionViewCell.self,
                                     forCellWithReuseIdentifier: "Cell")
        self.view.addSubview(self.collectionView!)
        
        //随机的表格数据
        let randomResult = self.navigationItem.rightBarButtonItem?.rx.tap.asObservable()
           .startWith(()) //加这个为了让一开始就能自动请求一次数据
           .flatMapLatest(getRandomResult)
           .share(replay: 1)
        
        // 创建数据源
        let dataSource = RxCollectionViewSectionedReloadDataSource<SectionModel<String,Int>>(
            configureCell: { (dataSource, collectionView, indexPath, element) in
            
                let cell = collectionView.dequeueReusableCell(withReuseIdentifier: "Cell",
                                            for: indexPath) as! Demo1CollectionViewCell
                cell.label.text = "\(element)"
                
                return cell}
        )
        
        //绑定单元格数据
        randomResult?
            .bind(to: collectionView.rx.items(dataSource: dataSource))
            .disposed(by: disposeBag)
        
        
        // 设置代理
        collectionView.rx.setDelegate(self).disposed(by:disposeBag)
        
    }
    
    //获取随机数据
    func getRandomResult() -> Observable<[SectionModel<String, Int>]> {
        print("正在请求数据......")
        let items = (0 ..< 5).map {_ in
            Int(arc4random_uniform(100000))
        }
        let observable = Observable.just([SectionModel(model: "S", items: items)])
        return observable.delay(2, scheduler: MainScheduler.instance)
    }
    
    @objc func refreshClick() {
        
    }
  
}

// collectonview 代理实现
extension CollectionRefreshViewController : UICollectionViewDelegateFlowLayout {
    
    func collectionView(_ collectionView: UICollectionView, layout collectionViewLayout: UICollectionViewLayout, sizeForItemAt indexPath: IndexPath) -> CGSize {
        let width = collectionView.bounds.width
        let cellWidth = (width - 30)/4
        return CGSize(width: cellWidth, height: cellWidth)
    }
    
}
