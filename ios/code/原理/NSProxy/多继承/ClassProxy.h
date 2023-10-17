//
//  ClassProxy.h
//  NSProxy
//
//  Created by WTW on 2020/3/9.
//  Copyright © 2020 wtw. All rights reserved.
// 实现多继承

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ClassProxy : NSProxy

@property (nonatomic,strong,readonly) NSMutableArray *targetArray;

@property(nonatomic,weak,readonly) id target;

-(void)handleTargets:(NSArray *)targets;

@end

NS_ASSUME_NONNULL_END
