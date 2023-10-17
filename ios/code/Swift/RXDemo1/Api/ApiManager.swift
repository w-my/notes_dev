//
//  ApiManager.swift
//  RXDemo1
//
//  Created by WTW on 2020/11/11.
//  Copyright © 2020 WTW. All rights reserved.
//

import UIKit
import Moya

enum ApiManager {
    
    enum TDGirlCategory: String {
        
        case GirlCategoryAll = "All"
        case GirlCategoryDaXiong = "DaXiong"
        case GirlCategoryQiaoTun = "QiaoTun"
        case GirlCategoryHeisi = "Heisi"
        case GirlCategoryMeiTui = "MeiTui"
        case GirlCategoryQingXin = "QingXin"
        case GirlCategoryZaHui = "ZaHui"
    }
    
    case requestWithCategory(type: TDGirlCategory,index: Int)
    
    static func indexToCategory(index: Int) -> TDGirlCategory {
        
        var category: TDGirlCategory
        
        switch index {
            case 0:
                category = TDGirlCategory.GirlCategoryAll
            case 1:
                category = TDGirlCategory.GirlCategoryDaXiong
            case 2:
                category = TDGirlCategory.GirlCategoryQiaoTun
            case 3:
                category = TDGirlCategory.GirlCategoryHeisi
            case 4:
                category = TDGirlCategory.GirlCategoryMeiTui
            case 5:
                category = TDGirlCategory.GirlCategoryQingXin
            case 6:
                category = TDGirlCategory.GirlCategoryZaHui
            default:
                category = TDGirlCategory.GirlCategoryAll
        }
        
        return category
    }
}

extension ApiManager: TargetType {
 
    var baseURL: URL {
        
        return URL(string: "https://meizi.leanapp.cn")!
    }
    
    var task: Task {
        
        return .requestPlain
    }
    
    var headers: [String : String]? {
        
         return ["Content-type": "application/json"]
    }
    
    var path: String {
        
        switch self {
        
            // 此处是枚举值,必须使用 rawValue ,否则请求不到数据
        case .requestWithCategory(type: let category, let page):
            return "/category/\(category.rawValue)/page/\(page)"
        }
    }
    
    var method: Moya.Method {
        
        return .get
    }
    
    var parameters: [String: Any]? {
        
        return nil
    }
    
    var parameterEncoding: ParameterEncoding {
           
        return URLEncoding.default
    }
    
    var sampleData: Data {
        
        return "ningjianwen".data(using: String.Encoding.utf8)!
    }
    
    var validate: Bool {
        
        return false
    }
}

let TDNetTool = MoyaProvider<ApiManager>()
