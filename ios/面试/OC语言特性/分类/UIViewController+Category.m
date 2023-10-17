//
//  UIViewController+Category.m
//  分类
//
//  Created by wtw on 2018/12/26.
//  Copyright © 2018 wtw. All rights reserved.
//

#import "UIViewController+Category.h"
#import <objc/runtime.h>

@implementation UIViewController (Category)

- (void)setName:(NSString *)name {
    objc_setAssociatedObject(self, @"", @"", OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

@end
