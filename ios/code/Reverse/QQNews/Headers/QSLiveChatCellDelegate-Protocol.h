//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class QSLiveChatBaseCell;

@protocol QSLiveChatCellDelegate <NSObject>

@optional
- (void)wantsToViewWholeContentOfLiveChatCell:(QSLiveChatBaseCell *)arg1;
- (void)wantsToReplyLiveChatCell:(QSLiveChatBaseCell *)arg1;
- (void)wantsToReportLiveChatCell:(QSLiveChatBaseCell *)arg1;
@end
