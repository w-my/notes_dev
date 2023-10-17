//
//  CalculatorManager.m
//  ReactiveCocoa
//
//  Created by wtw on 2018/12/5.
//  Copyright © 2018 wtw. All rights reserved.
//

#import "CalculatorManager.h"

@implementation CalculatorManager

#pragma mark - 链式编程
-(CalculatorManager *(^)(NSInteger))add {
    return ^(NSInteger value){
        _result += value;
        return self;
    };
}

#pragma mark - 函数式 编程
- (CalculatorManager *)jisuan:(NSInteger (^)(NSInteger result))block {
    _result = block(_result);
    return self;
}

- (CalculatorManager *)log {
    NSLog(@"_result 值为 ===== %zd ====== ",_result);
    return self;
}

- (CalculatorManager *)equle:(BOOL (^)(NSInteger result))operation {
    _isEqule = operation(_result);
    return self;
}

@end
