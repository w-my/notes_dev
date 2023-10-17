//
//  Person.m
//  KVO的本质
//
//  Created by wtw on 2019/3/29.
//  Copyright © 2019 wtw. All rights reserved.
//

#import "Person.h"

@implementation Person

- (void)personTest {
    NSLog(@"%s",__func__);
}

// 默认是 yes 如果修改为 no 就需要手动触发 kvo 
+ (BOOL)automaticallyNotifiesObserversOfAge {
    return NO;
}

@end
