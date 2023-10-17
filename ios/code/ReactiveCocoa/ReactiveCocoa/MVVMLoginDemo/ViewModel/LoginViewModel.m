//
//  LoginViewModel.m
//  ReactiveCocoa
//
//  Created by WTW on 2019/8/14.
//  Copyright © 2019 wtw. All rights reserved.
//

#import "LoginViewModel.h"
#import <ReactiveObjC/ReactiveObjC.h>

@implementation LoginViewModel

- (instancetype)init {
    if (self = [super init]) {
        [self setup];
    }
    return self;
}

- (void)setup {
    _loginEnableSignal = [RACSignal combineLatest:@[RACObserve(self,usernameStr),RACObserve(self,passwordStr)] reduce:^id(NSString *namestr,NSString *passwordStr){
        return @(namestr.length && passwordStr.length);
    }];
    
    _loginBtnCommand = [[RACCommand alloc] initWithSignalBlock:^RACSignal * _Nonnull(id  _Nullable input) {
        NSLog(@"发送网络请求");
        return [RACSignal createSignal:^RACDisposable * _Nullable(id<RACSubscriber>  _Nonnull subscriber) {
            NSLog(@"发送数据");
            [subscriber sendNext:@"网络请求回来的数据"];
            [subscriber sendCompleted];
            return nil;
        }];
    }];
    //处理结果
    [_loginBtnCommand.executionSignals.switchToLatest subscribeNext:^(id  _Nullable x) {
        NSLog(@"%@",x);
    }];
    //可以处理进度 HUD 等
    [[_loginBtnCommand.executing skip:1] subscribeNext:^(NSNumber * _Nullable x) {
        if ([x boolValue] == YES) {
            NSLog(@"正在执行");
        }else {
            NSLog(@"执行完成");
        }
    }];
}

@end
