//
//  LoginViewModel.h
//  ReactiveCocoa
//
//  Created by WTW on 2019/8/14.
//  Copyright © 2019 wtw. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ReactiveObjC/ReactiveObjC.h>

NS_ASSUME_NONNULL_BEGIN

@interface LoginViewModel : NSObject

@property (nonatomic,copy) NSString *usernameStr;
@property (nonatomic,copy) NSString *passwordStr;

@property (nonatomic,strong) RACSignal *loginEnableSignal;

@property (nonatomic,strong) RACCommand *loginBtnCommand;

@end

NS_ASSUME_NONNULL_END
