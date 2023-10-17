//
//  XMGContentView.m
//  XMGEaseMob5
//
//  Created by xiaomage on 15/12/27.
//  Copyright © 2015年 xiaomage. All rights reserved.
//

#import "XMGContentView.h"

@implementation XMGContentView

- (instancetype)initWithFrame:(CGRect)frame
{
    if (self = [super initWithFrame:frame]) {
        self.showsHorizontalScrollIndicator = NO;
        self.showsVerticalScrollIndicator = NO;
    }
    return self;
}

// 往view中添加了子控件
- (void)didAddSubview:(UIView *)subview
{
    [self scrollViewToFit];
}

// 从view中移除了子控件
- (void)willRemoveSubview:(UIView *)subview
{
    [self scrollViewToFit];
}



- (void)scrollViewToFit
{
    CGRect contentRect = CGRectZero;
    
    for (UIView *view in self.subviews) {
        // 返回一个包裹二者的rect
        contentRect = CGRectUnion(contentRect, view.frame);
    }
    
    CGFloat contentRectHeight = contentRect.size.height;
    // 如果当前的高度大于scrollview的高度  那么加一个间距
    if (contentRectHeight > self.height) {
        contentRectHeight += kWeChatPadding;
    }else{
        contentRectHeight = self.height;
    }
    
    self.contentSize = CGSizeMake(kWeChatScreenWidth, contentRectHeight);
    
}

@end
