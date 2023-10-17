//
//  ViewController.swift
//  RXDemo1
//
//  Created by WTW on 2020/11/11.
//  Copyright © 2020 WTW. All rights reserved.
//

/**
 * https://segmentfault.com/a/1190000020352689
 * 用到第三放库
 * 网络请求 Moya
 * 数据解析 ObjectMapper
 * 布局 Snpkit
 * 刷新 MJrefresh
 * loding SVP
 * 图片加载 Kingfisher
 */

import UIKit
import Moya
import RxSwift
import RxCocoa
import RxDataSources
//import MJRefresh
//import SYPhotoBrowser
import Then
import NSObject_Rx
import Reusable

let screenWidth: CGFloat = UIScreen.main.bounds.size.width
let screenHeight: CGFloat = UIScreen.main.bounds.size.height
let itemWidth: CGFloat = (screenWidth - 6) / 3

class ViewController: UIViewController {

    let viewModel = TDViewModel()
        
   lazy var layout = UICollectionViewFlowLayout().then {
        $0.minimumLineSpacing = 2
        $0.minimumInteritemSpacing = 2
        $0.itemSize = CGSize(width: itemWidth, height: itemWidth)
    }
    
    lazy var collectionView = UICollectionView(frame: CGRect(x: 0, y: 0, width: screenWidth, height: screenHeight), collectionViewLayout: layout).then {
        $0.backgroundColor = .white
        $0.register(cellType: TDBeautifulGirlCell.self)
        $0.collectionViewLayout = UICollectionViewFlowLayout()
    }
    
    let dataSource = RxCollectionViewSectionedReloadDataSource<TDSection>(configureCell:{ (dataSource, collectionView, indexPath, itemModel) in
        
        let cell = collectionView.dequeueReusableCell(for: indexPath, cellType: TDBeautifulGirlCell.self)

        cell.model = itemModel
        
        cell.setNeedsDisplay()
        
        return cell
    })
    
    var page: Int = 0
    var category = BehaviorRelay<ApiManager.TDGirlCategory>(value: .GirlCategoryAll)
    let vmOutput: TDViewModel.Output? = nil

    override func viewDidLoad() {
        super.viewDidLoad()
        
        setupUI()
        bindView()
        navigationItem()
        // 加载数据
        collectionView.mj_header?.beginRefreshing()
    }
}

extension ViewController {
    
    fileprivate func setupUI() {
        
        view.backgroundColor = .white
        view.addSubview(self.collectionView)
    }
    
    fileprivate func navigationItem(){
        
        let dropdownMenu = SYNavigationDropdownMenu(navigationController: self.navigationController!)
        dropdownMenu?.dataSource = self
        dropdownMenu!.delegate = self
        self.navigationItem.titleView = dropdownMenu
    }
    
    // 实现数据绑定，达到操作UI数据刷新的目的
    fileprivate func bindView(){
        
        let vmInput = TDViewModel.Input(category: self.category)
        
        let vmOutput = viewModel.transform(input: vmInput)
        
        vmOutput.sections.asDriver().drive(collectionView.rx.items(dataSource: dataSource)).disposed(by: rx.disposeBag)
        
        vmOutput.refreshStatus.asObservable().subscribe(onNext: {[weak self] status in
            switch status {
            case .beginFooterRefresh:
                self?.collectionView.mj_header?.beginRefreshing()
            case .endHeaderRefresh:
                self?.collectionView.mj_header?.endRefreshing()
            case .beginFooterRefresh:
                self?.collectionView.mj_footer?.beginRefreshing()
            case .endFooterRefresh:
                self?.collectionView.mj_footer?.endRefreshing()
            case .noMoreData:
                self?.collectionView.mj_footer?.endRefreshingWithNoMoreData()
            default:
                break
            }
        }).disposed(by: rx.disposeBag)
        
        collectionView.rx.modelSelected(TDGirlModel.self).subscribe(onNext:{[weak self] itemModel in

            print("current selected model is \(itemModel)")
            let photoBrowser: SYPhotoBrowser = SYPhotoBrowser(imageSourceArray: [itemModel.image_url], caption: nil, delegate: self)
            
            UIApplication.shared.delegate?.window?!.rootViewController?.present(photoBrowser, animated: true)

        }).disposed(by: rx.disposeBag)
        
        collectionView.mj_header = MJRefreshNormalHeader(refreshingBlock: {
            vmOutput.requestCommand.onNext(true)
        })
        
        collectionView.mj_footer = MJRefreshAutoNormalFooter(refreshingBlock: {
            vmOutput.requestCommand.onNext(false)
        })
    }
}

extension ViewController: SYNavigationDropdownMenuDataSource, SYNavigationDropdownMenuDelegate{
    func titleArray(for navigationDropdownMenu: SYNavigationDropdownMenu!) -> [String]! {
        return ["所有", "大胸", "翘臀", "黑丝", "美腿", "清新", "杂烩"]
    }
    
    func arrowImage(for navigationDropdownMenu: SYNavigationDropdownMenu!) -> UIImage! {
        return UIImage.init(named: "Arrow")
    }
    func arrowPadding(for navigationDropdownMenu: SYNavigationDropdownMenu!) -> CGFloat {
        return 8.0
    }
    
    func keepCellSelection(for navigationDropdownMenu: SYNavigationDropdownMenu!) -> Bool {
        return false
    }
    
    func navigationDropdownMenu(_ navigationDropdownMenu: SYNavigationDropdownMenu!, didSelectTitleAt index: UInt) {
//        self.category = BehaviorRelay(value: ApiManager.indexToCategory(index: Int(index)))
        self.category.accept(ApiManager.indexToCategory(index: Int(index)))
        print("self.category = \(self.category) index =\(index)")
        self.collectionView.mj_header?.beginRefreshing()
    }
}
