//
//  NewsService.m
//  分层架构
//
//  Created by WTW on 2020/2/23.
//  Copyright © 2020 wtw. All rights reserved.
//

#import "NewsService.h"
#import "HTTPTool.h"
#import "DBTool.h"

@implementation NewsService

+ (void)loadNewsWithParam:(NSDictionary *)param
                  success:(void (^)(NSArray * _Nonnull))success
                   faile :(void (^)(NSError *error))faile {
    
    // 先取本地数据处理
//    [DBTool xxx]
    
    // 成功失败回调
//    success(xxx);
//    faile(xxx);
    
   
    // 本地没有数据，去网络加载
//    [HTTPTool xxx];
        
}

@end
