//
//  Person.h
//  block
//
//  Created by WTW on 2019/7/26.
//  Copyright © 2019 wtw. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/** 不管是 arc 还是 mrc 都建议使用 copy 
 MRC下block属性的建议写法
    @property (copy, nonatomic) void (^block)(void);
 
 ARC下block属性的建议写法
     @property (strong, nonatomic) void (^block)(void);
     @property (copy, nonatomic) void (^block)(void);
 */

@interface Person : NSObject

@property (nonatomic,copy) void(^block)(void);
@property (nonatomic,assign) int age;

@end

NS_ASSUME_NONNULL_END
