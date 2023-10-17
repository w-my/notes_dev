//
//  XMGMeController.m
//  XMGEaseMob5
//
//  Created by xiaomage on 15/12/27.
//  Copyright © 2015年 xiaomage. All rights reserved.
//

#import "XMGMeController.h"

@interface XMGMeController ()

@end

@implementation XMGMeController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // 添加一个退出登录按钮
    XMGNButton *logoutBtn = [XMGNButton createXMGButton];
    logoutBtn.frame = CGRectMake(kWeChatPadding,  64, kWeChatScreenWidth - kWeChatPadding*2, kWeChatAllSubviewHeight);
    [logoutBtn setTitle:@"退出登录" forState:UIControlStateNormal];
    [logoutBtn setTitleColor:[UIColor redColor] forState:UIControlStateNormal];
    [self.contentView addSubview:logoutBtn];
    // 退出登录
    // isUnbind 是否解绑  如果是主动退出那么 传 YES  被迫 传NO
    logoutBtn.block = ^(XMGNButton *btn){
        [[EaseMob sharedInstance].chatManager asyncLogoffWithUnbindDeviceToken:YES completion:^(NSDictionary *info, EMError *error) {
            if (!error) {
                [[TKAlertCenter defaultCenter]postAlertWithMessage:@"退出登录成功"];
                [self.myAppDelegate logoutSuccess];
            }
        } onQueue:nil];
    };
}

@end
