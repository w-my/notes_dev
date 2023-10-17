//
//  XMGLoginController.m
//  XMGEaseMob5
//
//  Created by xiaomage on 15/12/27.
//  Copyright © 2015年 xiaomage. All rights reserved.
//

#import "XMGLoginController.h"
#import "AppDelegate.h"

@interface XMGLoginController ()<EMChatManagerDelegate>

@end

@implementation XMGLoginController

/*
 * 自动登录: 登录成功之后,将用户名 和 密码 存储本地数据库中
 * 下次打开程序的时候直接取出本地数据库中账号 和 密码进行登录 appdelegate中操作
 * 环信已经帮我做好了  只需要设置一个属性就可以了 
 * 属性应该是在登录成功之后设置
 */


- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.title = @"登录";
    
    // 用户名
    UILabel *userLbl = [[UILabel alloc]init];
    userLbl.frame = CGRectMake(20, 50, 60, 44);
    userLbl.text = @"用户名";
    [self.contentView addSubview:userLbl];
    
    // 用户名输入框
    UITextField *userFiled = [[UITextField alloc]init];
    userFiled.frame = CGRectMake(userLbl.right + 10, userLbl.top, 200, 44);
    userFiled.borderStyle = UITextBorderStyleRoundedRect;
    [self.contentView addSubview:userFiled];
    
    // 密码
    UILabel *pswLbl = [[UILabel alloc]init];
    pswLbl.frame = CGRectMake(20, userLbl.bottom + 20, 60, 44);
    pswLbl.text = @"密码";
    [self.contentView addSubview:pswLbl];
    
    // 密码输入框
    UITextField *pswFiled = [[UITextField alloc]init];
    pswFiled.frame = CGRectMake(pswLbl.right + 10, pswLbl.top, 200, 44);
    pswFiled.borderStyle = UITextBorderStyleRoundedRect;
    [self.contentView addSubview:pswFiled];
    
    // 登录按钮
    XMGNButton *loginBtn = [XMGNButton createXMGButton];
    loginBtn.frame = CGRectMake(20, pswFiled.bottom + 800, 100, 44);
    [loginBtn setTitle:@"登录" forState:UIControlStateNormal];
    [loginBtn setBackgroundColor:[UIColor redColor]];
    [self.contentView addSubview:loginBtn];
    
    // 注册按钮
    XMGNButton *registerBtn = [XMGNButton createXMGButton];
    registerBtn.frame = CGRectMake(loginBtn.right + kWeChatAllSubviewHeight, pswFiled.bottom + 800, 100, 44);
    [registerBtn setTitle:@"注册" forState:UIControlStateNormal];
    [registerBtn setBackgroundColor:[UIColor redColor]];
    [self.contentView addSubview:registerBtn];
    
    // 注册事件处理
    registerBtn.block = ^(XMGNButton *btn){
        if (userFiled.text.length == 0) {
            [[TKAlertCenter defaultCenter] postAlertWithMessage:@"用户名不能为空"];
            return ;
        }
        
        if (pswFiled.text.length == 0) {
            [[TKAlertCenter defaultCenter] postAlertWithMessage:@"密码不能为空"];
            return ;
        }
        // 注册
//        BOOL isSuccess = [[EaseMob sharedInstance].chatManager registerNewAccount:userFiled.text password:pswFiled.text error:nil];
//        if (isSuccess) {
//            NSLog(@"注册成功");
//        }
        
        [[EaseMob sharedInstance].chatManager asyncRegisterNewAccount:userFiled.text password:pswFiled.text withCompletion:^(NSString *username, NSString *password, EMError *error) {
            if (!error) {
                [[TKAlertCenter defaultCenter] postAlertWithMessage:@"注册成功"];
            }
        } onQueue:nil];
    };
    
    // 登录事件处理
    loginBtn.block = ^(XMGNButton *btn){
        if (userFiled.text.length == 0) {
            [[TKAlertCenter defaultCenter] postAlertWithMessage:@"用户名不能为空"];
            return ;
        }
        
        if (pswFiled.text.length == 0) {
            [[TKAlertCenter defaultCenter] postAlertWithMessage:@"密码不能为空"];
            return ;
        }
       
        [[EMClient sharedClient] loginWithUsername:@"user1" password:@"123" completion:^(NSString *aUsername, EMError *aError) {
            if (!aError) {
                NSLog(@"登录成功");
                [[TKAlertCenter defaultCenter] postAlertWithMessage:@"登录成功"];
                [self.myAppDelegate loginSuccess];
               
               // 设置自动登录
//               [[EMClient sharedClient] set];
            } else {
                NSLog(@"登录失败的原因---%@", aError.errorDescription);
            }
        }];
        
       
        
    };
    
    // 添加代理
    [[EaseMob sharedInstance].chatManager addDelegate:self delegateQueue:nil];
    
}
// 登录成功代理方法
- (void)didLoginWithInfo:(NSDictionary *)loginInfo error:(EMError *)error
{
    // loginInfo:
//    LastLoginTime = 1451183463240;
//    jid = "xjcoder#xmg5easemob_xmg3@easemob.com";
//    password = Xmg3;
//    resource = mobile;
//    token = "YWMt_VJVmqxAEeWi0Ktov3qQ5gAAAVMWPh76b8FMyXClc3o1dz-WuZNNWSi9qR8";
//    username = xmg3;
    NSLog(@"userName = %@  password = %@",loginInfo[@"username"],loginInfo[@"password"]);
}


- (void)dealloc
{
    [[EaseMob sharedInstance].chatManager removeDelegate:self];
}

@end
