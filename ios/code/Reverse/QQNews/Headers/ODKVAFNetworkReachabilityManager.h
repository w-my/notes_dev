//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@interface ODKVAFNetworkReachabilityManager : NSObject
{
    long long _networkReachabilityStatus;
    struct __SCNetworkReachability *_networkReachability;
    CDUnknownBlockType _networkReachabilityStatusBlock;
}

+ (id)keyPathsForValuesAffectingValueForKey:(id)arg1;
+ (id)manager;
+ (id)managerForAddress:(const void *)arg1;
+ (id)managerForDomain:(id)arg1;
+ (id)sharedManager;
@property(copy, nonatomic) CDUnknownBlockType networkReachabilityStatusBlock; // @synthesize networkReachabilityStatusBlock=_networkReachabilityStatusBlock;
@property(readonly, nonatomic) struct __SCNetworkReachability *networkReachability; // @synthesize networkReachability=_networkReachability;
@property(nonatomic) long long networkReachabilityStatus; // @synthesize networkReachabilityStatus=_networkReachabilityStatus;
- (void).cxx_destruct;
- (void)setReachabilityStatusChangeBlock:(CDUnknownBlockType)arg1;
- (id)localizedNetworkReachabilityStatusString;
- (void)stopMonitoring;
- (void)startMonitoring;
@property(readonly, nonatomic, getter=isReachableViaWiFi) _Bool reachableViaWiFi;
@property(readonly, nonatomic, getter=isReachableViaWWAN) _Bool reachableViaWWAN;
@property(readonly, nonatomic, getter=isReachable) _Bool reachable;
- (void)dealloc;
- (id)init;
- (id)initWithReachability:(struct __SCNetworkReachability *)arg1;

@end

