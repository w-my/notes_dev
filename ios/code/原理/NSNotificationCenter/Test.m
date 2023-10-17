//
//  Test.m
//  NSNotificationCenter
//
//  Created by WTW on 2020/3/14.
//  Copyright © 2020 wtw. All rights reserved.
//

#import "Test.h"

static NSString *TestNotification = @"TestNotification";

@implementation Test

static int count = 0;

- (void)dealloc {
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

- (void)test {
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(xxx) name:TestNotification object:nil];
}

- (void)xxx {
    NSLog(@"selector %d",++count);
}

@end
