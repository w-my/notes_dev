//
//  CalculatorManager.h
//  ReactiveCocoa
//
//  Created by wtw on 2018/12/5.
//  Copyright © 2018 wtw. All rights reserved.
// 链式编程

#import <Foundation/Foundation.h>

@interface CalculatorManager : NSObject

@property (nonatomic,assign) NSInteger result;
@property (nonatomic,assign) BOOL isEqule;

//加法运算 并返回自己
- (CalculatorManager *(^)(NSInteger))add;


- (CalculatorManager *)jisuan:(NSInteger (^)(NSInteger result))block;
- (CalculatorManager *)log;
- (CalculatorManager *)equle:(BOOL (^)(NSInteger result))operation;

@end
