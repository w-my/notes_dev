//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class CMessageWrap, NSString;

@protocol WXGImportMessageHelperDelegate <NSObject>

@optional
- (_Bool)filterMsgBeforeAddToDB:(CMessageWrap *)arg1;
- (void)onImportOneMsgItem:(NSString *)arg1;
- (_Bool)isImportMsgCallBackSync;
@end

