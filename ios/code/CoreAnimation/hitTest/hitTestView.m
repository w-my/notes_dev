//
//  hitTestView.m
//  hitTest
//
//  Created by wtw on 2019/3/5.
//  Copyright © 2019 wtw. All rights reserved.
//

#import "hitTestView.h"

@interface hitTestView(){
    UIView *purpleView;
    UIView *greenView;
    UIView *yellowView;
}
@end

@implementation hitTestView

- (instancetype)initWithFrame:(CGRect)frame {
    if (self = [super initWithFrame:frame]) {
        [self initUI];
    }
    return self;
}

- (void)initUI {
    purpleView = [[UIView alloc] initWithFrame:CGRectMake(20, 10, [UIScreen mainScreen].bounds.size.width - 20, 580)];
    purpleView.backgroundColor = [UIColor purpleColor];
    [self addSubview:purpleView];
    
    greenView = [[UIView alloc] initWithFrame:CGRectMake(50, 50, 300, 200)];
    greenView.backgroundColor = [UIColor greenColor];
    [purpleView addSubview:greenView];
    
    yellowView = [[UIView alloc] initWithFrame:CGRectMake(50, 300, 300, 200)];
    yellowView.backgroundColor = [UIColor yellowColor];
    [purpleView addSubview:yellowView];
    
    UIView *viewD = [[UIView alloc] initWithFrame:CGRectMake(40, 40, 120, 50)];
    viewD.backgroundColor = [UIColor redColor];
    [yellowView addSubview:viewD];
    
    UIView *viewE = [[UIView alloc] initWithFrame:CGRectMake(40, 120, 120, 50)];
    viewE.backgroundColor = [UIColor redColor];
    [yellowView addSubview:viewE];
}

- (UIView *)hitTest:(CGPoint)point withEvent:(UIEvent *)event {
    //1、判断自己能够接收触摸事件
    if (self.userInteractionEnabled == NO || self.alpha <=0.1 || self.hidden == YES) {
        return nil;
    }
    //2、判断触摸点是否在自己的范围内
    if (![self pointInside:point withEvent:event]) {
        return nil;
    }
    //3、从后往前遍历自己的子控件 看是否有子控件更适合响应事件
    int count = (int)self.subviews.count;
    for (int i = count -1; i>=0 ; i--) {
        UIView *childView = self.subviews[i];
        CGPoint childPoint = [childView convertPoint:point fromView:self];
        UIView *hitview = [childView hitTest:childPoint withEvent:event];
        if (hitview) {
            return hitview;
        }
    }
    return self;
    
}


@end
