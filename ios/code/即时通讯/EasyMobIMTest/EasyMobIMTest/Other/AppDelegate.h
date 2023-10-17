//
//  AppDelegate.h
//  EasyMobIMTest
//
//  Created by WTW on 2020/3/19.
//  Copyright © 2020 WTW. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface AppDelegate : UIResponder <UIApplicationDelegate>

@property (nonatomic,strong) UIWindow *window;

/*
 * 登录成功
 */
- (void)loginSuccess;

/*
 * 退出登录成功
 */
- (void)logoutSuccess;

@end

