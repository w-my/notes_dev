//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class TSAReachability;

@interface TSAAsyncReachability : NSObject
{
    TSAReachability *_myReachability;
    long long _networkStatus;
}

+ (id)sharedInstance;
@property(nonatomic) long long networkStatus; // @synthesize networkStatus=_networkStatus;
@property(retain, nonatomic) TSAReachability *myReachability; // @synthesize myReachability=_myReachability;
- (void).cxx_destruct;
- (void)didNetworkStatusChangedFromApp:(id)arg1;
- (void)didNetworkStatusChanged;
- (long long)currentNetworkStatus;
- (void)dealloc;
- (id)init;

@end

