//
//  BaseDemo.h
//  多线程-03(线程同步问题 锁)
//
//  Created by WTW on 2019/7/31.
//  Copyright © 2019 wtw. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface BaseDemo : NSObject

- (void)moneyTest;
- (void)ticketTest;

- (void)otherTest;

#pragma mark - 暴露给子类去使用
- (void)__saveMoney;
- (void)__drawMoney;
- (void)__saleTicket;

@end

NS_ASSUME_NONNULL_END
