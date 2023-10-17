//
//  AppDelegate.m
//  事件的传递
//
//  Created by WTW on 2020/2/13.
//  Copyright © 2020 WTW. All rights reserved.
//

#import "AppDelegate.h"
#import "CustomWindow.h"
#import "ViewController.h"

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
   
    self.window = [[CustomWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
        
    UIStoryboard *storyboard = [UIStoryboard storyboardWithName:@"Main" bundle:nil];
    
    self.window.rootViewController = storyboard.instantiateInitialViewController;
    
    [self.window makeKeyAndVisible];
    
    return YES;
}

@end
