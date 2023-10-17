//
//  main.m
//  内存管理-autorelease释放时机
//
//  Created by WTW on 2019/9/4.
//  Copyright © 2019 wtw. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AppDelegate.h"

int main(int argc, char * argv[]) {
    @autoreleasepool {
        return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class]));
    }
}
