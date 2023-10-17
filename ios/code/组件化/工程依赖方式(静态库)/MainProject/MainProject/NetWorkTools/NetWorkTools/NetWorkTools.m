//
//  NetWorkTools.m
//  NetWorkLayer
//
//  Created by WTW on 2020/3/6.
//  Copyright © 2020 WTW. All rights reserved.
//

#import "NetWorkTools.h"

@implementation NetWorkTools

+ (void)requestDataWithParam:(NSDictionary *)param
              successHandler:(void (^)(NSDictionary * _Nonnull))successhandler
                errorHandler:(void (^)(NSError * _Nonnull))errorhandler {
        
    // 网络请求.....
    
    // 回调.....
    if (successhandler) {
        successhandler(@{@"code":@"200",@"msg":@"请求成功",@"data":[NSData data]});
    }
    if (errorhandler) {
        NSError *error;
        errorhandler(error);
    }
}

@end
