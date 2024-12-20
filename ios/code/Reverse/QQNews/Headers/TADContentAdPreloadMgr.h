//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "TADHttpRequestDelegate.h"

@class NSArray, NSDate, NSMutableArray, NSString;

@interface TADContentAdPreloadMgr : NSObject <TADHttpRequestDelegate>
{
    NSArray *_articleContentAdTypes;
    NSMutableArray *_requestList;
    NSDate *_lastUpdateTime;
}

+ (id)sharedInstance;
@property(retain, nonatomic) NSDate *lastUpdateTime; // @synthesize lastUpdateTime=_lastUpdateTime;
@property(retain, nonatomic) NSMutableArray *requestList; // @synthesize requestList=_requestList;
@property(retain, nonatomic) NSArray *articleContentAdTypes; // @synthesize articleContentAdTypes=_articleContentAdTypes;
- (void).cxx_destruct;
- (void)p_onAppDidBecomeActiveActiveNotification:(id)arg1;
- (id)cachedAdForChannel:(id)arg1;
- (void)requestFailed:(id)arg1;
- (void)requestFinished:(id)arg1;
- (_Bool)hasResponseHandler;
- (void)loadAdForChannels:(id)arg1;
- (void)fillPoolWithChannels:(id)arg1;
- (void)checkFill;
- (void)start;
- (void)dealloc;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

