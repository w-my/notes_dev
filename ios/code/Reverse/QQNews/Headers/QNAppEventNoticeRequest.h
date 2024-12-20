//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSMutableDictionary;

@interface QNAppEventNoticeRequest : NSObject
{
    NSMutableDictionary *_noticeQueue;
}

+ (id)shareNoticeRequest;
@property(retain, nonatomic) NSMutableDictionary *noticeQueue; // @synthesize noticeQueue=_noticeQueue;
- (void).cxx_destruct;
- (void)p_removeAllNotice;
- (void)p_removeNoticeWithRequest:(id)arg1;
- (void)reportVideoSmartViewOperation:(unsigned long long)arg1 vid:(id)arg2;
- (void)reportBulletScreenCommit:(id)arg1;
- (void)eventNotice:(id)arg1 params:(id)arg2;
- (void)eventNotice:(id)arg1;
- (void)dealloc;
- (id)init;

@end

