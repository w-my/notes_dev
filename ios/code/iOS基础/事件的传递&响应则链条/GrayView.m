//
//  GrayView.m
//  事件的传递
//
//  Created by WTW on 2020/2/13.
//  Copyright © 2020 WTW. All rights reserved.
//

#import "GrayView.h"

@implementation GrayView

- (UIView *)hitTest:(CGPoint)point withEvent:(UIEvent *)event {
    NSLog(@"%s",__func__);
    return [super hitTest:point withEvent:event];
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    NSLog(@"%s ==  %@",__func__,[self class]);
    
//    [self getCurrentViewController];
}

/// 通过响应链找到视图的视图控制器
- (UIViewController *)getCurrentViewController {
    
    UIResponder *responser = self;
    
    /// 遍历响应者链 返回第一个找到的视图控制器
    while ((responser = [responser nextResponder])) {
    
        // WhiteView  ViewController
        NSLog(@"responser ==>%@ ",responser);
        
        if ([responser isKindOfClass:[UIViewController class]]) {
            return  (UIViewController *)responser;
        }
    }
    
    return nil;
}

@end
