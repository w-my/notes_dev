//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSMutableArray, NSString;

@interface TSAOrderManager : NSObject
{
    NSMutableArray *_updateRecord;
    NSMutableArray *_requstList;
    NSString *_token;
}

+ (id)shareInstance;
@property(copy, nonatomic) NSString *token; // @synthesize token=_token;
@property(retain, nonatomic) NSMutableArray *requstList; // @synthesize requstList=_requstList;
@property(retain, nonatomic) NSMutableArray *updateRecord; // @synthesize updateRecord=_updateRecord;
- (void).cxx_destruct;
- (void)dealloc;
- (_Bool)_shouldUpdateAdFormServer;
- (void)_preloadSplashAdOrder;
- (id)splashFirstAdOrderInfoWithUoid:(id)arg1;
- (_Bool)setTodayFirstAdPlayed;
- (_Bool)canUpdateTodayFirstAdStatus;
- (id)offlineValidCMPOrder;
- (id)todaySplashFirstAdUoid;
- (id)orderInfoWithOid:(id)arg1;
- (id)currentOrderItem;
- (void)preloadSplashAdOrder;
- (void)appDidDidBecomeActiveNotification:(id)arg1;
- (id)init;

@end
