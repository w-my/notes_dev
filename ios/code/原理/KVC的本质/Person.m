//
//  Person.m
//  KVC的本质
//
//  Created by WTW on 2019/7/18.
//  Copyright © 2019 wtw. All rights reserved.
//

#import "Person.h"

@implementation Person

//- (void)setAge:(int)age {
//    NSLog(@"setAge: %d",age);
//}
//
//- (void)_setAge:(int)age {
//    NSLog(@"_setAge: %d",age);
//}

+ (BOOL)accessInstanceVariablesDirectly {
    return YES;
}

// 会走到如下的方法


// didChangeValueForKey 内部会触发 KVO 的监听
- (void)willChangeValueForKey:(NSString *)key {
    [super willChangeValueForKey:key];
    NSLog(@" == willChangeValueForKey == ");
}

- (void)didChangeValueForKey:(NSString *)key {
    NSLog(@" == didChangeValueForKey == begin ");
    [super didChangeValueForKey:key];
    NSLog(@" == didChangeValueForKey == end ");
}

@end
