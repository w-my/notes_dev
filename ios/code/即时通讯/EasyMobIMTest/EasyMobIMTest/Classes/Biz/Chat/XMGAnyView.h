//
//  XMGAnyView.h
//  XMGEaseMob5
//
//  Created by xiaomage on 15/12/28.
//  Copyright © 2015年 xiaomage. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface XMGAnyView : UIView
- (instancetype)initImageBlock:(void (^)(void))imageBlock talkBlock:(void (^)(void))talkBlock vedioBlock:(void (^)(void))vedioBlock;


@end
