//
//  LoginViewController.m
//  ReactiveCocoa
//
//  Created by WTW on 2019/8/14.
//  Copyright © 2019 wtw. All rights reserved.
//

#import "LoginViewController.h"
#import <ReactiveObjC/ReactiveObjC.h>
#import "loginViewModel.h"

@interface LoginViewController ()

@property (nonatomic,strong) UITextField *userNamerTextFiled;
@property (nonatomic,strong) UITextField *passWordTextFiled;
@property (nonatomic,strong) UIButton *loginButton;

@property (nonatomic,strong) LoginViewModel *loginviewModel;


@end

@implementation LoginViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self setupUI];
    
    //账号 密码 绑定信号
    RAC(self.loginviewModel,usernameStr) = _userNamerTextFiled.rac_textSignal;
    RAC(self.loginviewModel,passwordStr) = _passWordTextFiled.rac_textSignal;
    
    //处理文本框业务逻辑 按钮是否可以点击
    RAC(self.loginButton, enabled) = self.loginviewModel.loginEnableSignal;
    
    //监听按钮点击
   @weakify(self)
    [[_loginButton rac_signalForControlEvents:UIControlEventTouchUpInside] subscribeNext:^(__kindof UIControl * _Nullable x) {
        //处理登录事件
        @strongify(self);
        [self.loginviewModel.loginBtnCommand execute:nil];
    }];
}

- (void)setupUI {
    self.view.backgroundColor = [UIColor whiteColor];
    [self.view addSubview:self.userNamerTextFiled];
    [self.view addSubview:self.passWordTextFiled];
    [self.view addSubview:self.loginButton];
}

- (UITextField *)userNamerTextFiled {
    if (!_userNamerTextFiled) {
        _userNamerTextFiled = [[UITextField alloc] initWithFrame:CGRectMake(100, 100, 100, 40)];
        _userNamerTextFiled.placeholder = @"姓名";
    }
    return _userNamerTextFiled;
}

- (UITextField *)passWordTextFiled {
    if (!_passWordTextFiled) {
        _passWordTextFiled = [[UITextField alloc] initWithFrame:CGRectMake(100, 160, 100, 40)];
        _passWordTextFiled.placeholder = @"密码";
    }
    return _passWordTextFiled;
}

- (UIButton *)loginButton {
    if (!_loginButton) {
        _loginButton = [UIButton buttonWithType:UIButtonTypeCustom];
        _loginButton.frame = CGRectMake(100, 250, 100, 50);
        [_loginButton setTitle:@"login" forState:UIControlStateNormal];
        [_loginButton setTitleColor:[UIColor darkGrayColor] forState:UIControlStateDisabled];
        [_loginButton setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        _loginButton.enabled = NO;
    }
    return _loginButton;
}

- (LoginViewModel *)loginviewModel {
    if (!_loginviewModel) {
        _loginviewModel = [[LoginViewModel alloc] init];
    }
    return _loginviewModel;
}

@end
