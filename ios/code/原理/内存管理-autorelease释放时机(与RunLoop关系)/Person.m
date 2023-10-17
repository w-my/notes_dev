//
//  Person.m
//  内存管理-autorelease释放时机
//
//  Created by WTW on 2019/9/4.
//  Copyright © 2019 wtw. All rights reserved.
//

#import "Person.h"

@implementation Person

- (void)dealloc {
    NSLog(@"%s",__func__);
    [super dealloc];
}

@end
