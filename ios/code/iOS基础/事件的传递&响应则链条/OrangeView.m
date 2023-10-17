//
//  OrangeView.m
//  事件的传递
//
//  Created by WTW on 2020/2/13.
//  Copyright © 2020 WTW. All rights reserved.
//

#import "OrangeView.h"

@implementation OrangeView

- (UIView *)hitTest:(CGPoint)point withEvent:(UIEvent *)event {
   
    NSLog(@"%s",__func__);
    
    return [super hitTest:point withEvent:event];
    // 无论点击谁 都让 OrangeView 响应事件
//    return self;
}

//- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
//    NSLog(@"%s ==  %@",__func__,[self class]);
//}

@end
