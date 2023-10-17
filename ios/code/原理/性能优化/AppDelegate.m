//
//  AppDelegate.m
//  性能优化
//
//  Created by WTW on 2019/9/6.
//  Copyright © 2019 wtw. All rights reserved.
//

#import "AppDelegate.h"
#import "HPInstrumentation.h"

@interface AppDelegate ()

@end

@implementation AppDelegate

//- (BOOL)application:(UIApplication *)application shouldRestoreApplicationState:(NSCoder *)coder {
//    NSLog(@"%s",__func__);
//    return YES;
//}
//
//- (void)application:(UIApplication *)application didDecodeRestorableStateWithCoder:(NSCoder *)coder {
//    NSLog(@"%s",__func__);
//}

- (BOOL)application:(UIApplication *)application willFinishLaunchingWithOptions:(NSDictionary<UIApplicationLaunchOptionsKey,id> *)launchOptions {
    
    NSString *deviceId = [[[UIDevice currentDevice] identifierForVendor] UUIDString];
//    NSLog(@"%@",deviceId);
    
    HPInstrumentation *analytics = [[HPInstrumentation alloc] initWithAPIKey:@""];
    [HPInstrumentation setSharedInstance:analytics];
    [HPInstrumentation logEvent:@"App Launched"];
    
    
    NSLog(@"%s",__func__);
    return YES;
}

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    
    NSLog(@"%s",__func__);
    
    return YES;
}


- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and invalidate graphics rendering callbacks. Games should use this method to pause the game.
}


- (void)applicationDidEnterBackground:(UIApplication *)application {
    NSLog(@"%s",__func__);
}


- (void)applicationWillEnterForeground:(UIApplication *)application {
    NSLog(@"%s",__func__);
}


- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}


- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}


@end
