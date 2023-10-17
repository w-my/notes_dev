//
//  XMGNButton.h
//  XMGEaseMob5
//
//  Created by xiaomage on 15/12/27.
//  Copyright © 2015年 xiaomage. All rights reserved.
//

#import <UIKit/UIKit.h>
@class XMGNButton;
typedef void(^XMGNButtonClickBlock)(XMGNButton *);

@interface XMGNButton : UIButton

/** 回调 */
@property (nonatomic, copy) XMGNButtonClickBlock block;

+ (instancetype)createXMGButton;

@end
