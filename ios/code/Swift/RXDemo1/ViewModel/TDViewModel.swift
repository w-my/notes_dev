//
//  TDGirlViewModel.swift
//  RXDemo1
//
//  Created by WTW on 2020/11/11.
//  Copyright © 2020 WTW. All rights reserved.
//

import UIKit
import RxSwift
import RxCocoa
import NSObject_Rx

enum TDRefreshStatus {
    
    case none
    case beginHeaderRefresh
    case endHeaderRefresh
    case beginFooterRefresh
    case endFooterRefresh
    case noMoreData
}

class TDViewModel: NSObject {

    let models = Variable<[TDGirlModel]>([])
    var index: Int = 0
}

extension TDViewModel: TDViewModelType {
    
    typealias Input = TDInput
    typealias OutPut = TDOutput
    
    struct TDInput {
      
        var category = BehaviorRelay<ApiManager.TDGirlCategory>(value: .GirlCategoryAll)
        init(category: BehaviorRelay<ApiManager.TDGirlCategory>) {
            self.category = category
        }
        
    }
    
    struct TDOutput {
        
        let sections: Driver<[TDSection]>
        let requestCommand = PublishSubject<Bool>()
        let refreshStatus = Variable<TDRefreshStatus>(.none)
        
        init(sections: Driver<[TDSection]>) {
            self.sections = sections
        }
        
    }
    
    func transform(input: TDViewModel.TDInput) -> TDViewModel.TDOutput {
    
        let sections = models.asObservable().map { (models) -> [TDSection] in
            return [TDSection(items: models)]
        }.asDriver(onErrorJustReturn: [])
        
        let output = Output(sections: sections)
        
        input.category.asObservable().subscribe {
            
            let category = $0.element
            
            output.requestCommand.subscribe(onNext: { [unowned self] isReloadData in
                
                self.index = isReloadData ? 0 : self.index + 1
                
                TDNetTool.rx.request(.requestWithCategory(type: category!, index: self.index))
                .asObservable()
                    .mapArray(TDGirlModel.self)
                    .subscribe ({ [weak self] (event) in
                        switch event {
                            
                        case let .next( modelArr):
                            
                            self?.models.value = isReloadData ? modelArr : (self?.models.value ?? []) + modelArr
                            print("加载成功")
                            
                        case let .error(error):
                            
                            print("加载失败 \(error)")
                            
                        case .completed:
                            
                            output.refreshStatus.value = isReloadData ? TDRefreshStatus.endHeaderRefresh : TDRefreshStatus.endFooterRefresh
                        }
                    }).disposed(by: self.rx.disposeBag)
                
            }).disposed(by: self.rx.disposeBag)
            
            
        }.disposed(by: self.rx.disposeBag)
     
        return output
    }
    
}
