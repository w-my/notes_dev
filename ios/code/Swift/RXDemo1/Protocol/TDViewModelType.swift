//
//  TDViewModelType.swift
//  RXDemo1
//
//  Created by WTW on 2020/11/11.
//  Copyright © 2020 WTW. All rights reserved.
//

import Foundation

// ViewModel 需要实现这个协议，实现输人 -> 输出方法，算是viewModel 的基本范式
protocol TDViewModelType {
    
    associatedtype Input
    associatedtype Output
    
    func transform(input: Input) -> Output
}
