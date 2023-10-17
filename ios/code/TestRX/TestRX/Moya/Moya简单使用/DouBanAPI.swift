//
//  DouBanAPI.swift
//  TestRX
//
//  Created by WTW on 2020/7/28.
//  Copyright © 2020 Mac. All rights reserved.
//  https://www.hangge.com/blog/cache/detail_1806.html
//  https://www.cnblogs.com/taoweiji/p/11538178.html

/*
 Moya 使用方法 : https://www.hangge.com/blog/cache/detail_1797.html
 */

import Foundation
import SwiftyJSON
import Moya

/// 初始化请求的 Provider
let DouBanProvider = MoyaProvider<DouBanService>()

/** 下面定义豆瓣FM请求的 endpoints (供provider 使用)  **/
public enum DouBanService {
    case channels // 获取频道列表
    case playlist(String) // 获取歌曲
}

//请求配置
extension DouBanService: TargetType {
    
    // 服务器地址
    public var baseURL: URL {
        switch self {
        case .channels:
            return URL(string: "https://www.douban.com")!
        case .playlist(_):
            return URL(string: "https://douban.fm")!
        }
    }
    
    // 各个请求的具体路径
    public var path: String {
        switch self {
        case .channels:
            return "/j/app/radio/channels"
        case .playlist(_):
            return "/j/mine/playlist"
        }
    }
    
    // 接口请求方式
    public var method: Moya.Method {
        switch self {
        case .channels:
            return .get
        case .playlist(_):
            return .get
        default:
            return .get
        }
    }
    
    // 请求任务事件 (附带参数)
    // 构建参数
    public var task: Task {
        switch self {
            
        case .playlist(let channel):
            
            var params: [String: Any] = [:]
            params["channel"] = channel
            params["type"] = "n"
            params["from"] = "mainsite"
            return .requestParameters(parameters: params,
                                      encoding: URLEncoding.default)
        default:
            return .requestPlain
        }
    }
    
    // 是否执行 Alamofire 验证
    public var validate: Bool {
        return false
    }
    
    // 这个就是做单元测试模拟的数据，只会在单元测试文件中有作用
    public var sampleData: Data{
        switch self {
        case .channels:
            return "{}".data(using: String.Encoding.utf8)!
        default:
            return "{}".data(using: String.Encoding.utf8)!
        }
        
    }
    
    // 请求头
    public var headers: [String : String]?{
        return ["Content-type" : "application/json"]
    }
}

// MARK: - 优化
// 每次请求都要对结果进行判断，定义一个适配器，将请求和结果的判断处理都封装起来，通过三个回调函数返回相应的结果
//struct Network {
//   
//    /// 初始化请求的 Provider
//    static let provider = MoyaProvider<DouBanService>()
//    
//    static func request(_ target: DouBanService,
//                        success successCallback: @escaping (JSON) ->Void,
//                        error errorCallback: @escaping (Int) -> Void,
//                        failure failureCallback: @escaping (MoyaError) -> Void) {
//        
//       provider.request(target) { result in
//            switch result {
//            case let .success(response):
//                do {
//                    //如果数据返回成功则直接将结果转为JSON
//                    try response.filterSuccessfulStatusCodes()
//                    let json = try JSON(response.mapJSON())
//                    successCallback(json)
//                }
//                catch let error {
//                    //如果数据获取失败，则返回错误状态码
//                    errorCallback((error as! MoyaError).response!.statusCode)
//                }
//            case let .failure(error):
//                //如果连接异常，则返回错误信息（必要时还可以将尝试重新发起请求）
//                //if target.shouldRetry {
//                //    retryWhenReachable(target, successCallback, errorCallback,
//                //      failureCallback)
//                //}
//                //else {
//                    failureCallback(error)
//                //}
//            }
//        }
//    }
//    
//}
