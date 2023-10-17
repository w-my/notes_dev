//
//  AppDelegate.m
//  网络相关
//
//  Created by WTW on 2019/11/19.
//  Copyright © 2019 WTW. All rights reserved.
//

#import "AppDelegate.h"

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    
      //共享URL缓存实例
//    NSURLCache *urlCache = [NSURLCache sharedURLCache];
    
    // 此方法已废弃
//    NSURLCache *urlCache = [[NSURLCache alloc] initWithMemoryCapacity:4 * 1024 * 1024 diskCapacity:20 * 1024 * 1024 diskPath:nil];
    
    //在指定目录中创建具有指定内存和磁盘容量的URL缓存对象
    NSURLCache *urlCache = [[NSURLCache alloc] initWithMemoryCapacity:4 * 1024 * 1024 diskCapacity:20 * 1024 * 1024 directoryURL:nil];

    [NSURLCache setSharedURLCache:urlCache];
    
    //其实默认就已经设置好了512kb的内存缓存空间，以及10MB的磁盘缓存空间
    NSLog(@"diskCapacity == %lu",(unsigned long)[NSURLCache sharedURLCache].diskCapacity);      // 10000000  10M
    NSLog(@"memoryCapacity == %lu",(unsigned long)[NSURLCache sharedURLCache].memoryCapacity);  //512000     512K
    
    return YES;
}

@end
