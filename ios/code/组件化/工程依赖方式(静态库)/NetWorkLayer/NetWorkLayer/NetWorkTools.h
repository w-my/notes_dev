//
//  NetWorkTools.h
//  NetWorkLayer
//
//  Created by WTW on 2020/3/6.
//  Copyright © 2020 WTW. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NetWorkTools : NSObject

+ (void)requestDataWithParam:(NSDictionary *)param successHandler:(void(^)(NSDictionary *info))successhandler errorHandler:(void(^)(NSError *error))error;

@end

NS_ASSUME_NONNULL_END
