//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NLSingletonBase.h"

@class NLReachability;

@interface UtilNetwork : NLSingletonBase
{
    int _lastNetworkType;
    NLReachability *_reach;
}

+ (long long)netStatus;
+ (int)netType;
+ (id)getNetworkTypeStr:(int)arg1;
+ (id)curNetTypeStr;
- (void).cxx_destruct;
- (int)networkChangeType:(int)arg1;
- (void)onNetworkStateChange:(id)arg1;
- (void)doInitNotification;
- (void)dealloc;
- (void)doInitData;
- (id)init;

@end

