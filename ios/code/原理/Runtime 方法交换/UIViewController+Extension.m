//
//  UIViewController+Extension.m
//  Runtime 方法交换
//
//  Created by WTW on 2020/3/10.
//  Copyright © 2020 wtw. All rights reserved.
//

#import "UIViewController+Extension.h"
#import <objc/runtime.h>

@implementation UIViewController (Extension)

+ (void)load {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        @autoreleasepool {
            Method method1 = class_getInstanceMethod([self class], @selector(viewDidLoad));
            Method method2 = class_getInstanceMethod([self class], @selector(tw_viewDidLoad));

            Method method3 = class_getInstanceMethod([self class], @selector(viewWillAppear:));
            Method method4 = class_getInstanceMethod([self class], @selector(tw_viewWillAppear:));

            Method method5 = class_getInstanceMethod([self class], @selector(viewWillDisappear:));
            Method method6 = class_getInstanceMethod([self class], @selector(tw_viewWillDisappear:));

            method_exchangeImplementations(method1, method2);
            method_exchangeImplementations(method3, method4);
            method_exchangeImplementations(method5, method6);
            
        }
    });
}

- (void)tw_viewDidLoad {
    NSString *str = [NSString stringWithFormat:@"%@", self.class];
    NSLog(@"%s 可以处理埋点等操作 == %@",__func__,str);

    // 将系统的UIViewController的对象剔除掉 
    if(![str containsString:@"UI"]){
           NSLog(@"统计打点 : %@", self.class);
    }
    
    [self tw_viewDidLoad];
}

- (void)tw_viewWillAppear:(BOOL)animated {
    NSString *str = [NSString stringWithFormat:@"%@", self.class];
    NSLog(@"%s 可以处理埋点等操作 == %@",__func__,str);

    if(![str containsString:@"UI"]){
           NSLog(@"统计打点 : %@", self.class);
    }
    
    [self tw_viewWillAppear:animated];
}

- (void)tw_viewWillDisappear:(BOOL)animated {
    NSLog(@"%s 可以处理埋点等操作",__func__);
    [self tw_viewWillDisappear:animated];
}
@end
