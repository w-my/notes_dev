//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class TVKMediaPlayInfo, TVKPlayerScheduleHistory;

@interface TVKPlayerSchedulerContext : NSObject
{
    _Bool _offlineToOnlineDone;
    _Bool _isAudioOnly;
    long long _errorCode;
    unsigned long long _currentStrategy;
    unsigned long long _currentType;
    TVKMediaPlayInfo *_mediaPlayInfo;
    TVKPlayerScheduleHistory *_history;
}

+ (id)contextWithCurrentStrategy:(unsigned long long)arg1 currentType:(unsigned long long)arg2 errorCode:(long long)arg3 mediaPlayInfo:(id)arg4;
@property(retain, nonatomic) TVKPlayerScheduleHistory *history; // @synthesize history=_history;
@property(nonatomic) _Bool isAudioOnly; // @synthesize isAudioOnly=_isAudioOnly;
@property(nonatomic) _Bool offlineToOnlineDone; // @synthesize offlineToOnlineDone=_offlineToOnlineDone;
@property(retain, nonatomic) TVKMediaPlayInfo *mediaPlayInfo; // @synthesize mediaPlayInfo=_mediaPlayInfo;
@property(nonatomic) unsigned long long currentType; // @synthesize currentType=_currentType;
@property(nonatomic) unsigned long long currentStrategy; // @synthesize currentStrategy=_currentStrategy;
@property(nonatomic) long long errorCode; // @synthesize errorCode=_errorCode;
- (void).cxx_destruct;

@end

