//
//  UIControl+Extension.h
//  Runtime 方法交换
//
//  Created by WTW on 2020/3/10.
//  Copyright © 2020 wtw. All rights reserved.
//

/*
1、在按钮点击之前处理事情
2、防止按钮频繁点击
*/

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIControl (Extension)

//button 点击间隔
@property (nonatomic, assign) NSTimeInterval timeInterval;
//用于设置单个按钮不需要被hook
@property (nonatomic, assign) BOOL isIgnore;

@end

NS_ASSUME_NONNULL_END
