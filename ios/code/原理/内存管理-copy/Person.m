//
//  Person.m
//  内存管理-copy
//
//  Created by WTW on 2019/9/4.
//  Copyright © 2019 wtw. All rights reserved.
//

#import "Person.h"

@implementation Person

// 如果是 copy 的话，效果相当于如下代码
- (void)setData:(NSMutableArray *)data {
    if (_data != data) {
        [_data release];
        _data = [data copy];
    }
}

- (void)dealloc {
    
    self.data = nil;
    [super dealloc];
}

@end
