//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSMutableArray, NSMutableDictionary, NSObject<OS_dispatch_queue>, NSString;

@interface ODKVInternal : NSObject
{
    _Bool _isForeground;
    _Bool _isAdditionSent;
    _Bool _isStart;
    unsigned int _currentSessionId;
    int _lastSequenceNumber;
    NSMutableDictionary *_timePages;
    NSMutableDictionary *_timeEvents;
    NSObject<OS_dispatch_queue> *_taskQueue;
    NSString *_currentPageName;
    NSString *_lastPageName;
    unsigned long long _lastTimeStamp;
    NSMutableArray *_cachedEvents;
}

+ (void)setIsEnable:(_Bool)arg1;
+ (_Bool)getIsEnable;
+ (id)sharedInstance;
@property(retain, nonatomic) NSMutableArray *cachedEvents; // @synthesize cachedEvents=_cachedEvents;
@property(nonatomic) _Bool isStart; // @synthesize isStart=_isStart;
@property _Bool isAdditionSent; // @synthesize isAdditionSent=_isAdditionSent;
@property int lastSequenceNumber; // @synthesize lastSequenceNumber=_lastSequenceNumber;
@property unsigned long long lastTimeStamp; // @synthesize lastTimeStamp=_lastTimeStamp;
@property(retain) NSString *lastPageName; // @synthesize lastPageName=_lastPageName;
@property(retain) NSString *currentPageName; // @synthesize currentPageName=_currentPageName;
@property(retain, nonatomic) NSObject<OS_dispatch_queue> *taskQueue; // @synthesize taskQueue=_taskQueue;
@property _Bool isForeground; // @synthesize isForeground=_isForeground;
- (void).cxx_destruct;
- (void)reportCustomKVDuration:(unsigned int)arg1 withEventid:(id)arg2 props:(id)arg3 appkey:(id)arg4 isRealTime:(_Bool)arg5;
- (void)reportCustomKV:(id)arg1 props:(id)arg2 appkey:(id)arg3 isRealTime:(_Bool)arg4;
- (void)reportSession:(_Bool)arg1;
- (void)sendEvent:(id)arg1;
- (void)reportEventInternal:(id)arg1;
- (void)reportEvent:(id)arg1;
- (void)setConfig;
- (void)startWithAppkey:(id)arg1;
- (void)dealloc;
- (void)onWillApplicationWillTerminate;
- (void)onWillApplicationEnterForeground;
- (void)onDidApplicationBecomeActive;
- (void)onWillApplicationEnterBackground;
- (void)onWillApplicationResignActive;
- (id)initUniqueInstance;
@property unsigned int currentSessionId; // @synthesize currentSessionId=_currentSessionId;
@property(retain, nonatomic) NSMutableDictionary *timeEvents; // @synthesize timeEvents=_timeEvents;
@property(retain, nonatomic) NSMutableDictionary *timePages; // @synthesize timePages=_timePages;

@end

