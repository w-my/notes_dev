//
//  main.m
//  性能优化
//
//  Created by WTW on 2019/9/6.
//  Copyright © 2019 wtw. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AppDelegate.h"

int main(int argc, char * argv[]) {
    @autoreleasepool {
        NSLog(@"LaunchStartTime: %f", CACurrentMediaTime());
        return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class]));
    }
}
