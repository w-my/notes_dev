//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSArray, NSTimer, QNLiveOrderDataStore;

@interface QNLiveOrderManager : NSObject
{
    _Bool _isOrderChange;
    NSArray *_willBeginItems;
    QNLiveOrderDataStore *_liveOrderDataStore;
    NSArray *_liveOrderListItems;
    NSArray *_failedAddOrders;
    NSArray *_failedRemoveOrders;
    long long _network;
    NSTimer *_timer;
}

+ (id)sharedInstance;
@property(retain, nonatomic) NSTimer *timer; // @synthesize timer=_timer;
@property(nonatomic) long long network; // @synthesize network=_network;
@property(copy, nonatomic) NSArray *failedRemoveOrders; // @synthesize failedRemoveOrders=_failedRemoveOrders;
@property(copy, nonatomic) NSArray *failedAddOrders; // @synthesize failedAddOrders=_failedAddOrders;
@property(copy, nonatomic) NSArray *liveOrderListItems; // @synthesize liveOrderListItems=_liveOrderListItems;
@property(retain, nonatomic) QNLiveOrderDataStore *liveOrderDataStore; // @synthesize liveOrderDataStore=_liveOrderDataStore;
@property(nonatomic) _Bool isOrderChange; // @synthesize isOrderChange=_isOrderChange;
@property(copy, nonatomic) NSArray *willBeginItems; // @synthesize willBeginItems=_willBeginItems;
- (void).cxx_destruct;
- (void)p_checkLivePushOK:(id)arg1;
- (void)p_requestRemoveOrderLive:(id)arg1;
- (void)p_requestAddOrderLive:(id)arg1;
- (void)writeToDisk;
- (void)loadLocalData;
- (long long)liveOrderTimerInterval;
- (_Bool)p_liveOrderWillBegin:(id)arg1;
- (id)p_lessThan48Hours:(id)arg1;
- (void)p_generateWillBeginItems:(id)arg1;
- (void)p_generateLiveOrderTime;
- (void)startTimer;
- (void)stopTimer;
- (void)removeLiveOrder:(id)arg1;
- (void)addLiveOrder:(id)arg1;
- (_Bool)hasLiveOrder:(id)arg1;
- (void)syncAddRemove;
- (void)dealloc;
- (id)init;

@end
