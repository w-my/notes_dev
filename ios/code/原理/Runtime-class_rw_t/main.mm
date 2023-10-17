//
//  main.m
//  Runtime-位运算
//
//  Created by WTW on 2019/9/16.
//  Copyright © 2019 wtw. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AppDelegate.h"
#import "MJClassInfo.h"
#import "Person.h"
#import <objc/runtime.h>

// class_rw_t里面的methods、properties、protocols是二维数组，是可读可写的，包含了类的初始内容、分类的内容

int main(int argc, char * argv[]) {
    @autoreleasepool {
        
        // 通过 MJClassInfo 查看类的相关信息 必须要真机
        
        Person * person = [[Person alloc] init];
        
        struct mj_objc_class *cls = (__bridge struct mj_objc_class *)[person class];
        class_rw_t *data = cls->data();
        
//        NSLog(@"%@ %@",cls,data);
        
        return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class]));
    }
}
