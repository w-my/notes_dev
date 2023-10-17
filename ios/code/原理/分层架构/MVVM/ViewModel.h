//
//  ViewModel.h
//  分层架构
//
//  Created by WTW on 2020/4/10.
//  Copyright © 2020 wtw. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ViewModel : NSObject

- (instancetype)initWithController:(UIViewController *)controller;

@end

NS_ASSUME_NONNULL_END
