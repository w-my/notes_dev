//
//  AppDelegate.m
//  WKWebViewDemo
//
//  Created by WTW on 2020/2/13.
//  Copyright © 2020 WTW. All rights reserved.
//

#import "AppDelegate.h"
#import "ViewController.h"
#import "TestViewController.h"

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    
    self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    
    TestViewController *vc = [[TestViewController alloc] init];
    
    UINavigationController *nav = [[UINavigationController alloc] initWithRootViewController:vc];
    
    self.window.rootViewController = nav;
    
    [self.window makeKeyAndVisible];
    
    return YES;
}




@end
