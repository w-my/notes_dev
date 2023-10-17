//
//  AppDelegate.m
//  LoadView
//
//  Created by WTW on 2020/2/10.
//  Copyright © 2020 WTW. All rights reserved.
//

#import "AppDelegate.h"
#import "ViewController.h"

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
   
    self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    
    self.window.backgroundColor = [UIColor greenColor];
    
    ViewController *vc = [[ViewController alloc] init];
    
    self.window.rootViewController = vc;
    
    [self.window makeKeyAndVisible];
    
    return YES;
}



@end
