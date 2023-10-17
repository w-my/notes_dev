//
//  CustomWindow.m
//  事件的传递
//
//  Created by WTW on 2020/2/13.
//  Copyright © 2020 WTW. All rights reserved.
//

#import "CustomWindow.h"
#import "WhiteView.h"

@implementation CustomWindow

// 作用：寻找最适合的View
// 什么时候调用：当一个事件传递给当前View 就会调用
// 返回值：返回的是谁，谁就是最合适的Viwe (就会调用最适合view 的 Touch 方法)
- (UIView *)hitTest:(CGPoint)point withEvent:(UIEvent *)event {
   
    NSLog(@"%s",__func__);
    
    // hitTest 的底层实现
    //1、自己能否接收触摸事件？ (hitTest)
    // 返回nil表示不能处理事件
    if (self.userInteractionEnabled == NO || self.hidden == YES || self.alpha <= 0.01) {
        return nil;
    }
    
    // 2、触摸点是否在自己身上？ (pointInside)
    if (![self pointInside:point withEvent:event]) {
        return nil;
    }
    
    //3、从后往前遍历子控件，重复前面的两个步骤
    int count = (int)self.subviews.count;
    for (int i = count -1; i >= 0; i--) {
        // 取出每个子控件
        UIView *childView = self.subviews[i];
        // 转换坐标系
        CGPoint chilePoint = [self convertPoint:point toView:childView];
        UIView *fitView =  [childView hitTest:chilePoint withEvent:event];
        // 判断有没有找到适合的View
        if (fitView) {
            return fitView;
        }
    }
    //4、如果没有符合条件的子控件，那么就自己就是最适合的View
    return self;
}

// 作用：判断当前点在不在它点击的View身上(谁调用pointInside，这个View 就是谁)
// 什么时候调用：它是在 hitTest 方法中调用
// point 必须和方法调用者在同一坐标系中
- (BOOL)pointInside:(CGPoint)point withEvent:(UIEvent *)event {
    NSLog(@"%s",__func__);
//    return NO;
    return YES;
}

@end
