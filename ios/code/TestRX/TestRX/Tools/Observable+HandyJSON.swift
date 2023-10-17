//
//  Observable+HandyJSON.swift
//  TestRX
//
//  Created by WTW on 2020/7/30.
//  Copyright © 2020 Mac. All rights reserved.
//

import Foundation
import RxSwift
import Moya
import HandyJSON

extension ObservableType where Element == Response {
    public func mapHandyJsonModel<T: HandyJSON>(_ type: T.Type) -> Observable<T> {
        return flatMap { response -> Observable<T> in
            return Observable.just(response.mapHandyJsonModel(T.self))
        }
    }
}

extension Response {
    func mapHandyJsonModel<T: HandyJSON>(_ type: T.Type) -> T {
        let jsonString = String.init(data: data, encoding: .utf8)
        if let modelT = JSONDeserializer<T>.deserializeFrom(json: jsonString) {
            return modelT
        }
        return JSONDeserializer<T>.deserializeFrom(json: "{\"msg\":\"请求有误\"}")!
    }
}
