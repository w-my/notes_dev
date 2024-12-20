//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSArray, NSObject<OS_dispatch_queue>, NSString, TADItemInfo, TADSplashItem, TSASplashAsyncLoader;

@interface TADSplashPreLoaderHelper : NSObject
{
    NSObject<OS_dispatch_queue> *_loaderQueue;
    int playStrategy[2][5];
    _Bool _isLastTimeEmptyOrder;
    _Bool _preSelectFlag;
    TSASplashAsyncLoader *_loader;
    TADSplashItem *_splashItem;
    long long _loadStatus;
    NSString *_synchronizedToken;
    double _timeRecord;
    NSArray *_playTimeInterControl;
    double _realOrderTimeRecord;
    TADItemInfo *_currentOrderItem;
}

+ (id)shareInstance;
@property(retain, nonatomic) TADItemInfo *currentOrderItem; // @synthesize currentOrderItem=_currentOrderItem;
@property(nonatomic) _Bool preSelectFlag; // @synthesize preSelectFlag=_preSelectFlag;
@property(nonatomic) double realOrderTimeRecord; // @synthesize realOrderTimeRecord=_realOrderTimeRecord;
@property(nonatomic) _Bool isLastTimeEmptyOrder; // @synthesize isLastTimeEmptyOrder=_isLastTimeEmptyOrder;
@property(retain, nonatomic) NSArray *playTimeInterControl; // @synthesize playTimeInterControl=_playTimeInterControl;
@property(nonatomic) double timeRecord; // @synthesize timeRecord=_timeRecord;
@property(retain, nonatomic) NSString *synchronizedToken; // @synthesize synchronizedToken=_synchronizedToken;
@property(nonatomic) long long loadStatus; // @synthesize loadStatus=_loadStatus;
@property(retain, nonatomic) TADSplashItem *splashItem; // @synthesize splashItem=_splashItem;
@property(retain, nonatomic) TSASplashAsyncLoader *loader; // @synthesize loader=_loader;
- (void).cxx_destruct;
- (_Bool)_checkLocalOrderIsValid;
- (_Bool)_checkCurrentTimeCompareWithTime:(double)arg1 playControl:(double)arg2;
- (void)_emptyOrderTimeRecord;
- (void)_recordTime;
- (void)_pingPVForEmptyOrder:(id)arg1 withPlayControlTime:(double)arg2;
- (void)_pingPVForSplashItem:(id)arg1;
- (_Bool)enableSplashAdInLaunchingType:(long long)arg1 from:(long long)arg2;
- (id)callID;
- (id)currentSplashItemParams;
- (id)currentSplashAdOid;
@property(readonly, nonatomic) long long status;
- (id)currentSplashItem;
- (void)disableSplashAdWithReasonCode:(long long)arg1;
- (void)_internalSelectSplashAdOrderWithPlayTimeControl:(double)arg1 withCompletion:(CDUnknownBlockType)arg2;
- (_Bool)_selectSplashOrderWithPlayTimeControl:(double)arg1 withCompletion:(CDUnknownBlockType)arg2;
- (_Bool)selectCurrentSplashAdOrder;
- (_Bool)preCheckCurrentSplashAdOrderWithCompleteHandle:(CDUnknownBlockType)arg1;
- (id)preCheckCurrentSplashAdOrder;
- (void)_preLoadSplashAdOrderWithUserInfo:(id)arg1;
- (void)preLoadSplashAdOrderWithUserInfo:(id)arg1;
- (void)startSplashSDKWithLaunchingType:(long long)arg1 callFrom:(long long)arg2;
- (id)init;

@end

