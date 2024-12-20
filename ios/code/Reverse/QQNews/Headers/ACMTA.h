//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "ACMTAMainServiceDelegate.h"

@class NSObject<OS_dispatch_queue>, NSString;

@interface ACMTA : NSObject <ACMTAMainServiceDelegate>
{
    NSObject<OS_dispatch_queue> *task_queue;
}

+ (void)sendEvent:(id)arg1 withCachedEvent:(int)arg2;
+ (void)trackCustomKeyValueEventDuration:(unsigned long long)arg1 withEventid:(id)arg2 props:(id)arg3 appKey:(id)arg4 isRealTime:(_Bool)arg5;
+ (void)trackCustomKeyValueEventDuration:(unsigned long long)arg1 withEventid:(id)arg2 props:(id)arg3;
+ (void)trackCustomKeyValueEvent:(id)arg1 props:(id)arg2 appkey:(id)arg3 isRealTime:(_Bool)arg4;
+ (void)trackCustomKeyValueEvent:(id)arg1 props:(id)arg2;
+ (void)startWithAppkey:(id)arg1;
+ (id)getInstance;
+ (_Bool)isEqualToMagic:(id)arg1;
+ (id)filterBodyData:(id)arg1 configData:(id)arg2;
+ (id)getSendData:(id)arg1;
+ (id)getMTAConfigIDFA;
+ (id)getIDFV;
+ (id)getBundleID;
+ (id)getOpenUDID;
- (void).cxx_destruct;
- (id)getTaskQueue;
- (void)onWillApplicationEnterBackground;
- (void)onWillApplicationEnterForeground;
- (void)onDidApplicationBecomeActive;
- (void)onWillApplicationResignActive;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

