//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class CBossReportApi, NSArray, NSDictionary, NSMutableDictionary;

@interface CBoss : NSObject
{
    NSArray *_constantFields;
    NSArray *_defaultFields;
    NSDictionary *_optionalFieldsMap;
    NSMutableDictionary *_bossData;
    NSMutableDictionary *_waitingData;
    NSMutableDictionary *_constantData;
    long long _reportDataCount;
    _Bool _isSending;
    _Bool _isMerging;
    CBossReportApi *_mRequest;
}

+ (id)boss;
@property(nonatomic) _Bool isMerging; // @synthesize isMerging=_isMerging;
@property(nonatomic) _Bool isSending; // @synthesize isSending=_isSending;
@property(retain, nonatomic) CBossReportApi *mRequest; // @synthesize mRequest=_mRequest;
@property(retain, nonatomic) NSMutableDictionary *waitingData; // @synthesize waitingData=_waitingData;
@property(retain, nonatomic) NSMutableDictionary *bossData; // @synthesize bossData=_bossData;
@property(retain, nonatomic) NSDictionary *optionalFieldsMap; // @synthesize optionalFieldsMap=_optionalFieldsMap;
@property(retain, nonatomic) NSArray *defaultFields; // @synthesize defaultFields=_defaultFields;
@property(retain, nonatomic) NSArray *constantFields; // @synthesize constantFields=_constantFields;
- (void).cxx_destruct;
- (_Bool)p_isEmptyData;
- (void)dealloc;
- (void)mergeBossData;
- (void)clearTList;
- (void)reportToServer;
- (id)encodeData:(id)arg1;
- (void)addItem:(id)arg1 forBossID:(long long)arg2;
- (void)validateDefaultData:(id)arg1;
- (void)addTString:(id)arg1 InAItem:(id)arg2;
- (void)addWaitingTString:(id)arg1 forBossID:(long long)arg2;
- (id)mkStringFromDictionary:(id)arg1 withFields:(id)arg2;
- (id)aItemForBossID:(long long)arg1;
- (void)validateConstantData;
- (void)setBusiness:(id)arg1;
- (void)setUserQQ:(id)arg1;
- (void)initConstantData;
- (void)setOptionalFieldsConfig:(id)arg1;
- (void)appDidReceiveMemoryWarning:(id)arg1;
- (void)appWillTerminateNotification:(id)arg1;
- (void)appDidEnterBackgroundNotification:(id)arg1;
- (void)appWillEnterForegroundNotification:(id)arg1;
- (void)initBossData;
- (void)saveBossDataToFile;
- (id)init;

@end

