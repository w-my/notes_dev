//
//  BasicView.m
//  事件的传递
//
//  Created by WTW on 2020/2/13.
//  Copyright © 2020 WTW. All rights reserved.
//

#import "BasicView.h"

@implementation BasicView

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    NSLog(@"%s ==  %@",__func__,[self class]);
}

@end
