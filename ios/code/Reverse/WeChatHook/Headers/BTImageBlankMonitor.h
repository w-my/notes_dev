//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMService.h"

#import "MMImageLoaderEventNotification.h"
#import "MMService.h"
#import "MMWebImageViewLoadEventDelegate.h"

@class NSMutableDictionary, NSString;

@interface BTImageBlankMonitor : MMService <MMImageLoaderEventNotification, MMWebImageViewLoadEventDelegate, MMService>
{
    NSMutableDictionary *m_taskDict;
    unsigned int m_reportCacheCount;
    unsigned int m_reportFileCount;
    unsigned int m_reportNetCount;
}

- (void).cxx_destruct;
- (void)onServiceClearData;
- (void)onServiceReloadData;
- (void)onServiceInit;
- (void)reportRecordsTotalCount;
- (void)updateReportCount:(id)arg1;
- (void)onLoadEvent:(int)arg1 url:(id)arg2 reqContext:(id)arg3 extraInfo:(id)arg4;
- (void)onEventImageLoadNotificationType:(int)arg1 url:(id)arg2 extraInfo:(id)arg3;
- (void)onEventImageEndLoadWithUrl:(id)arg1 image:(id)arg2 data:(id)arg3 extraInfo:(id)arg4;
- (void)reportWithKey:(id)arg1 extraInfo:(id)arg2;
- (void)stopRecordSubTime:(id)arg1 scene:(int)arg2;
- (void)startRecordSubTime:(id)arg1 scene:(int)arg2;
- (void)onUserInvisibleWithKey:(id)arg1;
- (void)onUserVisibleWithKey:(id)arg1;
- (void)stopWithKey:(id)arg1;
- (void)startWithKey:(id)arg1 posInTL:(unsigned int)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
