//
//  NewsService.h
//  分层架构
//
//  Created by WTW on 2020/2/23.
//  Copyright © 2020 wtw. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NewsService : NSObject

+ (void)loadNewsWithParam:(NSDictionary *)param
                  success:(void(^)(NSArray *dataArr))success
                    faile:(void(^)(NSError *error))faile;

@end

NS_ASSUME_NONNULL_END
