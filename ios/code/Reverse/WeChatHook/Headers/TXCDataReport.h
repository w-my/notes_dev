//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "TXCModule.h"

@class NSMutableDictionary, NSString;

@interface TXCDataReport : TXCModule
{
    NSMutableDictionary *_stats;
    long long _lastReport;
    long long _statusReportInterval;
    _Bool _isReportBegin;
    long long _lastBlockCount;
    unsigned long long _startTime;
    int _maxVideoCache;
    int _sumVideoCache;
    int _numVideoCache;
    unsigned long long _realTimePlayStartTime;
    _Bool _realTimeMode;
    _Bool _isp2p;
    NSString *_url;
    NSString *_realUrl;
}

+ (_Bool)isTencentHost:(id)arg1;
@property(nonatomic) _Bool isp2p; // @synthesize isp2p=_isp2p;
@property(copy, nonatomic) NSString *realUrl; // @synthesize realUrl=_realUrl;
@property(copy, nonatomic) NSString *url; // @synthesize url=_url;
@property(nonatomic) _Bool realTimeMode; // @synthesize realTimeMode=_realTimeMode;
- (void).cxx_destruct;
- (void)execGBNDNSParseTask;
- (void)reportRealTimePlayStatusInternal;
- (void)reportRealTimePlayEndEvt;
- (void)reportRealTimePlayBeginEvt:(_Bool)arg1;
- (id)getParamsFromStreamUrl:(id)arg1 streamUrl:(id)arg2;
- (id)getStringFromNumber:(id)arg1;
- (id)getStringFromValue:(long long)arg1;
- (void)setupStats;
- (void)reportPlayStatusInternal;
- (void)reportPushStatusInternal;
- (void)reportPlayBeginEvt;
- (void)reportPushBeginEvt;
- (void)reportRealTimePlayStatisticInfo;
- (void)reportPlayFailed;
- (void)reportPlayEndEvt;
- (void)reportPushFailed;
- (void)reportPushEndEvt;
- (void)reportPlayStatus;
- (void)stopPlay;
- (void)reportPushStatus;
- (void)getCNAME:(id)arg1;
- (long long)checkTencentStream;
- (void)stopPush;
- (void)start;
- (void)initParam;
- (id)init;

@end

