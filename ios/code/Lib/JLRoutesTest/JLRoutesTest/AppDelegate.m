//
//  AppDelegate.m
//  JLRoutesTest
//
//  Created by wtw on 2018/9/14.
//  Copyright © 2018年 wtw. All rights reserved.
//

#import "AppDelegate.h"
#import "JLRoutes.h"

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
   
    //globalRoutes 全局Routes注册
//    [[JLRoutes globalRoutes] addRoute:@"/:controller" handler:^BOOL(NSDictionary<NSString *,id> * _Nonnull parameters) {
//        NSString *controller = parameters[@"controller"];
//
//        [self.window.rootViewController presentViewController:[[NSClassFromString(controller) alloc] init] animated:YES completion:^{
//
//        }];
//
//        return YES;
//    }];
    
    //自定义命名空间注册
    [[JLRoutes routesForScheme:@"JLRoutesTestOne"] addRoute:@"/:controller/:userID/:pass" handler:^BOOL(NSDictionary<NSString *,id> * _Nonnull parameters) {
        NSString *controller = parameters[@"controller"];
        
        NSLog(@"parameters: %@",parameters);
        NSLog(@"userID: %@",parameters[@"userID"]);
        NSLog(@"pass: %@",parameters[@"pass"]);
        
        [self.window.rootViewController presentViewController:[[NSClassFromString(controller) alloc] init] animated:YES completion:^{

        }];
        return YES; //一旦匹配立即返回YES
    }];
    
    //定义优先级注册
//    [[JLRoutes globalRoutes] addRoute:@"/:controller" priority:1 handler:^BOOL(NSDictionary<NSString *,id> * _Nonnull parameters) {
//
//        return YES;
//    }];
    return YES;
}

- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options {
    
    [[JLRoutes routesForScheme:@"JLRoutesTestOne"] routeURL:url];
    
    return YES;
}

@end
