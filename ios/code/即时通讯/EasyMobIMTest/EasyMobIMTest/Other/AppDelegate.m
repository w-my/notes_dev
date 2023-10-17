//
//  AppDelegate.m
//  EasyMobIMTest
//
//  Created by WTW on 2020/3/19.
//  Copyright © 2020 WTW. All rights reserved.
//

#import "AppDelegate.h"
#import "XMGLoginController.h"
#import "XMGRootNavigationController.h"
#import "XMGMeController.h"
#import "XMGContactController.h"
#import "XMGConversationController.h"

@interface AppDelegate ()<EMChatManagerDelegate>
@property (nonatomic, strong) XMGRootNavgationController *loginNav;
@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    
    // 初始化环信
    EMOptions *options = [EMOptions optionsWithAppkey:kEaseMobAppKey];
    // apnsCertName是证书名称，可以先传nil，等后期配置apns推送时在传入证书名称
    options.apnsCertName = nil;
    [[EMClient sharedClient] initializeSDKWithOptions:options];

    self.window = [[UIWindow alloc]initWithFrame:[UIScreen mainScreen].bounds];

    XMGLoginController *loginCtr = [[XMGLoginController alloc]init];

    XMGRootNavigationController *loginNav = [[XMGRootNavigationController alloc]initWithRootViewController:loginCtr];

    self.window.rootViewController = loginNav;

    self.window.backgroundColor = [UIColor whiteColor];

    [self.window makeKeyAndVisible];

// 设置导航条
    // 背景图片
    [[UINavigationBar appearance] setBackgroundImage:[UIImage imageNamed:@"topbarbg_ios7"] forBarMetrics:UIBarMetricsDefault];
    // 文字颜色
    [[UINavigationBar appearance] setTitleTextAttributes:@{NSForegroundColorAttributeName:[UIColor whiteColor]}];
    
    // 调用环信的程序加载完毕的方法 才能添加代理
    [[EaseMob sharedInstance] application:application didFinishLaunchingWithOptions:launchOptions];

    
//    EMError *error = [[EaseMob sharedInstance] registerSDKWithAppKey:@"xjcoder#xmg5easemob" apnsCertName:@""];
    
    // kSDKConfigEnableConsoleLogger 关闭控制台登录信息的打印
    [[EaseMob sharedInstance] registerSDKWithAppKey:@"xjcoder#xmg5easemob" apnsCertName:@"" otherConfig:@{kSDKConfigEnableConsoleLogger:@NO}];
    
    // 添加代理方法
    [[EaseMob sharedInstance].chatManager addDelegate:self delegateQueue:nil];

    // 自动登录
    if ([[EaseMob sharedInstance].chatManager isAutoLoginEnabled]) {
        [MBProgressHUD showMessag:@"正在登录" toView:self.window];
    }
    
        return YES;
}
// 登录成功
- (void)loginSuccess
{
    UITabBarController *tabbarCtr = [[UITabBarController alloc]init];
    XMGConversationController *conversationCtr = [[XMGConversationController alloc]init];
    XMGRootNavgationController *conversationNav = [[XMGRootNavgationController alloc]initWithRootViewController:conversationCtr];
    conversationCtr.tabBarItem.image = [UIImage imageNamed:@"tabbar_mainframe"];
    conversationCtr.tabBarItem.selectedImage = [UIImage imageNamed:@"tabbar_mainframeHL"];
    conversationCtr.title = @"会话";
    
    
    XMGContactController *contactCtr = [[XMGContactController alloc]init];
    XMGRootNavgationController *contactNav = [[XMGRootNavgationController alloc]initWithRootViewController:contactCtr];
    contactCtr.tabBarItem.image = [UIImage imageNamed:@"tabbar_contacts"];
    contactCtr.tabBarItem.selectedImage = [UIImage imageNamed:@"tabbar_contactsHL"];
    contactCtr.title = @"通讯录";
    
    
    XMGMeController *meCtr = [[XMGMeController alloc]init];
    XMGRootNavgationController *meNav = [[XMGRootNavgationController alloc]initWithRootViewController:meCtr];
    meCtr.tabBarItem.image = [UIImage imageNamed:@"tabbar_me"];
    meCtr.tabBarItem.selectedImage = [UIImage imageNamed:@"tabbar_meHL"];
    meCtr.title = @"我";
    
    tabbarCtr.viewControllers = @[conversationNav,contactNav,meNav];
    
    self.window.rootViewController = tabbarCtr;
}

// 退出登录
- (void)logoutSuccess
{
    self.window.rootViewController = self.loginNav;
    // 退出登录成功之后  不能在设置自动登录
    [[EaseMob sharedInstance].chatManager setIsAutoLoginEnabled:NO];
}

#pragma mark - EMChatManagerDelegate
- (void)willAutoLoginWithInfo:(NSDictionary *)loginInfo error:(EMError *)error
{
    NSLog(@"即将自动登录");
}

- (void)didAutoLoginWithInfo:(NSDictionary *)loginInfo error:(EMError *)error
{
    [MBProgressHUD hideAllHUDsForView:self.window animated:YES];
    // 切换控制器
    [self loginSuccess];

    NSLog(@"自动登录成功");
}

// App进入后台
- (void)applicationDidEnterBackground:(UIApplication *)application
{
    [[EaseMob sharedInstance] applicationDidEnterBackground:application];
}

// App将要从后台返回
- (void)applicationWillEnterForeground:(UIApplication *)application
{
    [[EaseMob sharedInstance] applicationWillEnterForeground:application];
}

// 申请处理时间
- (void)applicationWillTerminate:(UIApplication *)application
{
    [[EaseMob sharedInstance] applicationWillTerminate:application];
}


@end
