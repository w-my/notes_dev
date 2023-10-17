//
//  DemoListViewModel.swift
//  TestRX
//
//  Created by WTW on 2020/7/30.
//  Copyright © 2020 Mac. All rights reserved.
//

import Foundation
import RxSwift
import RxCocoa
import HandyJSON
import NSObject_Rx
import Moya
import ObjectMapper


class DemoListViewModel  {

    // 存放解析完的模型数组
    let models = BehaviorRelay<[DemoListModel]>(value:[])
    // 记录当前的索引
    var index: Int = 1
    
    
    var dataSource = BehaviorRelay<[MainClassModelMapObject_sub]>(value:[])
    var networkError = BehaviorRelay(value: Error.self)
    let disposeBag = DisposeBag()

}

extension DemoListViewModel {
    
    typealias Input = DemoInput
    typealias Output = DemoOutput
    
    
    struct DemoInput {
    
        // 网络请求类型
        let category: APIManager
        
        init(category: APIManager) {
            self.category = category
        }
    }
    
    struct DemoOutput {
        
        //tableView 的 sections 数据
        let sections: Driver<[DemoListSection]>
        // 外界通过该属性告诉ViewModel 加载数据(传入的值是为了标志是否重新加载)
        let requestCommond = PublishSubject<Bool>()
        // 告诉外界的 tableView 当前的刷新状态
//        let refreshStatus = Variable<LXFRefreshStatus>(.none)
        
        init(sections: Driver<[DemoListSection]>) {
            self.sections = sections
        }
        
    }
    
    
//    func transform(input: DemoListViewModel.DemoInput) -> DemoListViewModel.DemoOutput {
//        
//    }
    
    
    
    
    // 网络请求 - ObjectMapper
    func getListWithMapObject(){
        Network.provider.rx.request(.channels).asObservable().mapObjectModel(DemoListModelMapJson.self).subscribe({
            [unowned self] (event) in
            
            switch event {
            case let  .next(classModel):
                print("ObjectMapper -- 加载网络成功")
                self.dataSource.accept(classModel.data)
                
            case let .error( error):
                print("error:", error)
                self.networkError.accept(error as! Error.Protocol)
            case .completed: break
            }
            
            }).disposed(by: disposeBag)
    }
    
    
    // 网络请求 - HandyJSON
    func getListData()  {
        
        Network.provider.rx.request(.channels).asObservable().mapHandyJsonModel(DemoListModel.self).subscribe({ [unowned self] (event) in
            
            switch event {
                
            case let .next(classModel):
                print("Handy Json - 加载网络成功")
            case let .error(error):
                print(" error:",error)
                
            case .completed: break
            }
        }).disposed(by:disposeBag)
        
        
    }
    
}
