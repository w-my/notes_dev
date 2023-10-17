//
//  SingletonTool.h
//  单例模式
//
//  Created by WTW on 2020/2/6.
//  Copyright © 2020 wtw. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SingletonTool : NSObject<NSCopying,NSMutableCopying>

/*
  提供类方法
 1、方便访问
 2、表明身份
 3、写法 share + 类名 |  default + 类名  | share  | default | 类名 等方式都可以 
 */
+ (instancetype)shareTool;

@end

NS_ASSUME_NONNULL_END
