//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSMutableDictionary, UploadNetReachability;

@interface QZUploadConnectionPool : NSObject
{
    NSMutableDictionary *_poolDict;
    UploadNetReachability *_reachability;
}

+ (id)sharedInstance;
@property(retain, nonatomic) UploadNetReachability *reachability; // @synthesize reachability=_reachability;
@property(retain, nonatomic) NSMutableDictionary *poolDict; // @synthesize poolDict=_poolDict;
- (void).cxx_destruct;
- (void)reachabilityChanged:(id)arg1;
- (void)stopNetReachabilityListen;
- (void)startNetReachabilityListen;
- (void)resetPoolOfKey:(id)arg1;
- (void)resetPool;
- (void)clearAllConnectionNeedRedirectOfKey:(id)arg1;
- (void)restoreConnection:(id)arg1 ofKey:(id)arg2;
- (id)createConnectionOfKey:(id)arg1 ip:(id)arg2;
- (void)clearExpiredConnectionOfPool:(id)arg1;
- (id)getConnectionListWithCount:(long long)arg1 ofKey:(id)arg2 ip:(id)arg3;
- (id)getConnectionOfKey:(id)arg1 ip:(id)arg2;
- (id)init;

@end

