//
//  RefreshViewModel.swift
//  RXDataSourceTest
//
//  Created by WTW on 2020/11/17.
//  Copyright © 2020 WTW. All rights reserved.
//

import UIKit
import RxCocoa
import RxSwift

class RefreshViewModel {

    // 表格数据序列
    let tableData = BehaviorRelay<[String]>(value: [])
    
    // 停止上拉加载刷新状态序列
    let endFooterRefreshing: Driver<Bool>
    
    // ViewModel 初始化 (根据输入显示对应的输出)
    init(footerRefresh: Driver<Void>,dependency:(disposeBag:DisposeBag,networkService:Networ)) {
        
    }
}
