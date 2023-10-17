//
//  XMGChatController.h
//  XMGEaseMob5
//
//  Created by xiaomage on 15/12/27.
//  Copyright © 2015年 xiaomage. All rights reserved.
//

#import "XMGRootController.h"

@interface XMGChatController : XMGRootController

/** 用户信息 */
@property (nonatomic, strong) EMBuddy *budddy;

@property (nonatomic,strong) EMGroup *group;

- (instancetype)initWithIsGroup:(BOOL)isGroup;

@end
