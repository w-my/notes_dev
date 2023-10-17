//
//  AppDelegate.m
//  TouchPainter
//
//  Created by WTW on 2019/12/13.
//  Copyright © 2019 WTW. All rights reserved.
//

#import "AppDelegate.h"
#import "CoordinatingController.h"

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {

    self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    
    CoordinatingController *coordinatingController = [CoordinatingController sharedInstance];
    
    self.window.rootViewController = [[UINavigationController alloc] initWithRootViewController:coordinatingController.canvasViewController];
    
    [self.window makeKeyAndVisible];
    
    return YES;
}




@end
