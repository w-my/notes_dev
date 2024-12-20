//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@interface TXAudioJitterBufferReportInfo : NSObject
{
    int _loadTime;
    int _loadCnt;
    int _loadMaxTime;
    int _speedCnt;
    int _noDataCnt;
    int _avgCacheTime;
    unsigned int _timeTotalCacheTime;
    unsigned int _timeTotalCacheTimeCnt;
    int _timeTotalJitt;
    int _timeTotalJittCnt;
    unsigned int _timeDropCnt;
    int _isRealTime;
}

@property(nonatomic) int isRealTime; // @synthesize isRealTime=_isRealTime;
@property(nonatomic) unsigned int timeDropCnt; // @synthesize timeDropCnt=_timeDropCnt;
@property(nonatomic) int timeTotalJittCnt; // @synthesize timeTotalJittCnt=_timeTotalJittCnt;
@property(nonatomic) int timeTotalJitt; // @synthesize timeTotalJitt=_timeTotalJitt;
@property(nonatomic) unsigned int timeTotalCacheTimeCnt; // @synthesize timeTotalCacheTimeCnt=_timeTotalCacheTimeCnt;
@property(nonatomic) unsigned int timeTotalCacheTime; // @synthesize timeTotalCacheTime=_timeTotalCacheTime;
@property(nonatomic) int avgCacheTime; // @synthesize avgCacheTime=_avgCacheTime;
@property(nonatomic) int noDataCnt; // @synthesize noDataCnt=_noDataCnt;
@property(nonatomic) int speedCnt; // @synthesize speedCnt=_speedCnt;
@property(nonatomic) int loadMaxTime; // @synthesize loadMaxTime=_loadMaxTime;
@property(nonatomic) int loadCnt; // @synthesize loadCnt=_loadCnt;
@property(nonatomic) int loadTime; // @synthesize loadTime=_loadTime;
- (id)init;

@end

