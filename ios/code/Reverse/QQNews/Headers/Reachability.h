//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSString;

@interface Reachability : NSObject
{
    NSString *key_;
    struct __SCNetworkReachability *reachabilityRef;
    _Bool _hasStartedNotifier;
    _Bool _shouldAutoEnableAsyncMode;
}

+ (id)reachabilityForLocalWiFi;
+ (id)reachabilityForInternetConnection;
+ (id)reachabilityWithAddress:(const struct sockaddr_in *)arg1;
+ (id)makeAddressKey:(unsigned int)arg1;
+ (id)reachabilityWithHostName:(id)arg1;
+ (_Bool)accessInstanceVariablesDirectly;
@property(nonatomic) _Bool shouldAutoEnableAsyncMode; // @synthesize shouldAutoEnableAsyncMode=_shouldAutoEnableAsyncMode;
@property _Bool hasStartedNotifier; // @synthesize hasStartedNotifier=_hasStartedNotifier;
@property(copy) NSString *key; // @synthesize key=key_;
- (void)_enableAsyncModeForUnsafeMainThreadAccess;
- (unsigned int)reachabilityFlags;
- (_Bool)isReachableViaWiFi;
- (_Bool)isReachableViaWWAN;
- (_Bool)isInterventionRequired;
- (_Bool)isConnectionOnDemand;
- (_Bool)connectionRequired;
- (_Bool)isConnectionRequired;
- (_Bool)isReachable;
- (unsigned int)currentReachabilityStatus;
- (unsigned int)networkStatusForFlags:(unsigned int)arg1;
- (_Bool)isEqual:(id)arg1;
- (void)stopNotifier;
- (_Bool)startNotifier;
- (id)initWithReachabilityRef:(struct __SCNetworkReachability *)arg1;
- (void)dealloc;

@end
