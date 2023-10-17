//
//  Person.m
//  objc_msgSend
//
//  Created by WTW on 2019/6/6.
//  Copyright © 2019 rocedar. All rights reserved.
//

#import "Person.h"

@implementation Person

- (void)personTest {
    NSLog(@"%s",__func__);
}

- (void)personTest:(int)age {
    NSLog(@"%s == %d",__func__,age);
}

@end
