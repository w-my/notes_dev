//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSError, QSComTopicDetailReplyListData;

@protocol QSComTopicDetailReplyListDataDelegate <NSObject>
- (void)comTopicDetailReplyListData:(QSComTopicDetailReplyListData *)arg1 didGetReplyListFinishAtIndex:(unsigned long long)arg2 error:(NSError *)arg3;
@end
