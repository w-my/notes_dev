//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSMutableArray, NSString, NSURLSession, TADReachability;

@interface TADNetworkManager : NSObject
{
    id <TADRequestProtocol> _requestDelegate;
    NSURLSession *_defaultSession;
    TADReachability *_reachability;
    NSMutableArray *_reachabilityListenerArray;
    NSString *_defaultUserAgent;
}

+ (long long)errorToTaskError:(id)arg1;
+ (id)sharedManager;
@property(retain, nonatomic) NSString *defaultUserAgent; // @synthesize defaultUserAgent=_defaultUserAgent;
@property(retain, nonatomic) NSMutableArray *reachabilityListenerArray; // @synthesize reachabilityListenerArray=_reachabilityListenerArray;
@property(retain, nonatomic) TADReachability *reachability; // @synthesize reachability=_reachability;
@property(retain, nonatomic) NSURLSession *defaultSession; // @synthesize defaultSession=_defaultSession;
@property(nonatomic) __weak id <TADRequestProtocol> requestDelegate; // @synthesize requestDelegate=_requestDelegate;
- (void).cxx_destruct;
- (void)didNetworkStatusChanged;
- (void)removeReachabilityListener:(CDUnknownBlockType)arg1;
- (void)addReachabilityListener:(CDUnknownBlockType)arg1;
- (void)stopMonitoring;
- (void)startMonitoring;
- (_Bool)isReachableViaWiFi;
- (_Bool)isReachableViaWWAN;
- (_Bool)isReachable;
- (id)urlEncode:(id)arg1;
- (id)updateUrl:(id)arg1 withParam:(id)arg2;
- (id)urlWithClientRetryCount:(id)arg1 retryCount:(long long)arg2;
- (id)cookiesFilter:(id)arg1;
- (id)cookiesFromString:(id)arg1 url:(id)arg2;
- (void)saveCookieString:(id)arg1 url:(id)arg2;
- (id)delegateRequestWith:(id)arg1 requestId:(id)arg2 success:(CDUnknownBlockType)arg3 failure:(CDUnknownBlockType)arg4;
- (id)httpRequestWith:(id)arg1 success:(CDUnknownBlockType)arg2 failure:(CDUnknownBlockType)arg3;
- (id)requestWith:(id)arg1 success:(CDUnknownBlockType)arg2 failure:(CDUnknownBlockType)arg3;
- (id)requestWith:(id)arg1 postData:(id)arg2 success:(CDUnknownBlockType)arg3 failure:(CDUnknownBlockType)arg4;
- (id)defaultConfigration;
- (id)init;

@end
