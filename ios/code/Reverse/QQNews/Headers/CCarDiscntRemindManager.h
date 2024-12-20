//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CCarBaseManager.h"

@class CCarHomeInfo, NSString;

@interface CCarDiscntRemindManager : CCarBaseManager
{
    CCarHomeInfo *_homeInfo;
    NSString *_curCityId;
    double _timeStamp;
}

+ (id)sharedDiscntRemind;
@property(nonatomic) double timeStamp; // @synthesize timeStamp=_timeStamp;
@property(copy, nonatomic) NSString *curCityId; // @synthesize curCityId=_curCityId;
@property(retain, nonatomic) CCarHomeInfo *homeInfo; // @synthesize homeInfo=_homeInfo;
- (void).cxx_destruct;
- (void)makeShowedWithTag:(int)arg1;
- (void)writeRemindVersionToDisk;
- (_Bool)versionLoadFromDisk;
- (id)btnsToShow;
- (void)dataLoaderDownLoadDataFailed:(id)arg1;
- (void)dataLoaderDownLoadDataComplete:(id)arg1;
- (id)parseJSONResponse:(id)arg1;
- (id)getRequestURL;
- (id)adDictInfo;
- (void)startRequest;
- (id)init;

@end

