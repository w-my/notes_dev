//
//  Person.m
//  内存管理-weak指针
//
//  Created by WTW on 2019/9/2.
//  Copyright © 2019 wtw. All rights reserved.
//

#import "Person.h"

@implementation Person

- (void)dealloc {
    NSLog(@"%s",__func__);
}

@end
