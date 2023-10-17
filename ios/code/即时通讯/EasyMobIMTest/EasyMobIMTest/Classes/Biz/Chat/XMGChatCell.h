//
//  XMGChatCell.h
//  XMGEaseMob5
//
//  Created by xiaomage on 15/12/27.
//  Copyright © 2015年 xiaomage. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol XMGChatCellShowImageDelegate <NSObject>
/*
 * 显示大图片
 */
- (void)chatCellWithMessage:(EMMessage *)message;

@end

@interface XMGChatCell : UITableViewCell

/** 消息模型 */
@property (nonatomic, strong) EMMessage *message;

@property (nonatomic, assign)CGFloat rowHeight;

@property (nonatomic,assign)id<XMGChatCellShowImageDelegate> delegate;
@end
