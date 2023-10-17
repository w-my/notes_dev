//
//  XMGRootController.h
//  XMGEaseMob5
//
//  Created by xiaomage on 15/12/27.
//  Copyright © 2015年 xiaomage. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "XMGContentView.h"
#import "AppDelegate.h"
@interface XMGRootController : UIViewController
/** 控制器的view */
@property (nonatomic, weak) XMGContentView *contentView;

@property (nonatomic, strong) AppDelegate *myAppDelegate;

- (void)setChatDelegate;
@end
