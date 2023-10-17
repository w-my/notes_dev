//
//  APIManager.swift
//  TestRX
//
//  Created by WTW on 2020/7/30.
//  Copyright © 2020 Mac. All rights reserved.
//

import Foundation
import Moya

/// 定义请求的 endpoints (供 provider 使用)
public enum APIManager {
    case channels // 获取频道列表
    case playlist(String) // 获取歌曲
    case demo(String,String) // demo
}

// 请求配置
extension APIManager: TargetType {
    
    // 请求服务器地址
    public var baseURL: URL {
        switch self {
        case .channels:
            
            return URL(string: "https://www.douban.com")!
        case .playlist(_):
            
              return URL(string: "https://douban.fm")!
        default:
            return URL(string: "https://douban.fm")!
        }
    }
    
    // 各个API对应的具体路径
    public var path: String {
        switch self {
            
        case .channels:
            
            return "/j/app/radio/channels"
            
        case .playlist(_):
            
            return "/j/mine/playlist"
         
        case .demo(_, _):
            
            return "demo url"
            
        default:
            
            return ""
        }
    }
    
    // 接口请求方式 get 或者 post
    public var method: Moya.Method {
        switch self {
        case .channels:
            
            return .get
         
        case .demo(_, _):
            
            return .post
            
        default:
            return .get
        }
    }
    
    // 请求任务(带构建参数)
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


/// Network.request
struct Network {
   
    /// 成功的回调
    typealias successCallback = (_ result: Any) -> Void
    
    /// 失败的回调
    typealias failureCallback = (_ error: MoyaError) -> Void
    
    /// 请求的 Provider (单例)
    static let provider = MoyaProvider<APIManager>()
    
    static func request(_ target: APIManager,
                            success:  @escaping successCallback,
                            failure:  @escaping failureCallback) {
        
       provider.request(target) { result in
            switch result {
            case let .success(response):
                do {
                    try success(response.mapJSON())
                } catch  {
                    failure(MoyaError.jsonMapping(response))
                }
            case let .failure(error):
                    failure(error)
            }
        }
        
    }
}
