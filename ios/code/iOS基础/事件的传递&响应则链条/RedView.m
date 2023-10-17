//
//  RedView.m
//  事件的传递
//
//  Created by WTW on 2020/2/13.
//  Copyright © 2020 WTW. All rights reserved.
//

// 测试View 的拖拽

#import "RedView.h"

@implementation RedView

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    NSLog(@"%s",__func__);
}

- (void)touchesMoved:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    NSLog(@"%s",__func__);
    
    UITouch *touch = touches.anyObject;
    // 求偏移量
    CGPoint curP = [touch locationInView:self];
    CGPoint preP = [touch previousLocationInView:self];
    CGFloat offsetX = curP.x - preP.x;
    CGFloat offsetY = curP.y - preP.y;
    // 平移
    self.transform = CGAffineTransformTranslate(self.transform, offsetX, offsetY);
}

- (void)touchesEnded:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    NSLog(@"%s",__func__);
}

/// 当发生系统时间的时候，会调用该方法 (比如电话打入或者自动关机等)
- (void)touchesCancelled:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    NSLog(@"%s",__func__);
}


@end
