//
//  UIImage+XMGResizing.m
//  01.WeChat(EaseMobSDK导入)
//
//  Created by 肖剑 on 15/12/14.
//  Copyright © 2015年 肖剑. All rights reserved.
//

#import "UIImage+XMGResizing.h"

@implementation UIImage (XMGResizing)

+ (UIImage *)resizingImageWithName:(NSString *)name
{
    UIImage *normalImg = [UIImage imageNamed:name];
    
    CGFloat w = normalImg.size.width * 0.5f;
    CGFloat h = normalImg.size.height * 0.5f;
    
    return [normalImg resizableImageWithCapInsets:UIEdgeInsetsMake(h, w, h, w)];
}


@end
