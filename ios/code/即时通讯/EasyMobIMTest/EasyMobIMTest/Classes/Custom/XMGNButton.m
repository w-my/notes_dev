//
//  XMGNButton.m
//  XMGEaseMob5
//
//  Created by xiaomage on 15/12/27.
//  Copyright © 2015年 xiaomage. All rights reserved.
//

#import "XMGNButton.h"

@implementation XMGNButton

- (instancetype)initWithFrame:(CGRect)frame
{
    if (self = [super initWithFrame:frame]) {
        [self addTarget:self action:@selector(click:) forControlEvents:UIControlEventTouchUpInside];
    }
    return self;
}

- (void)click:(XMGNButton *)btn
{
    if (_block) {
        _block(btn);
    }
}

+ (instancetype)createXMGButton
{
    return [XMGNButton buttonWithType:UIButtonTypeCustom];
}

@end
