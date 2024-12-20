//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "WAReportBaseItem.h"

@class NSString;

@interface WAReportMemStatItem : WAReportBaseItem
{
    _Bool _isCache;
    _Bool _isGame;
    unsigned int _eventType;
    unsigned int _openSeq;
    unsigned int _openInterval;
    unsigned int _waThreadMemUsed;
    unsigned int _mainThreadMemUsed;
    unsigned int _lastKillReason;
    long long _processMemUsed;
    NSString *_nickname;
    unsigned long long _coldLaunchInterAfterLastKillInMs;
}

@property(nonatomic) unsigned long long coldLaunchInterAfterLastKillInMs; // @synthesize coldLaunchInterAfterLastKillInMs=_coldLaunchInterAfterLastKillInMs;
@property(nonatomic) unsigned int lastKillReason; // @synthesize lastKillReason=_lastKillReason;
@property(nonatomic) _Bool isGame; // @synthesize isGame=_isGame;
@property(copy, nonatomic) NSString *nickname; // @synthesize nickname=_nickname;
@property(nonatomic) unsigned int mainThreadMemUsed; // @synthesize mainThreadMemUsed=_mainThreadMemUsed;
@property(nonatomic) unsigned int waThreadMemUsed; // @synthesize waThreadMemUsed=_waThreadMemUsed;
@property(nonatomic) long long processMemUsed; // @synthesize processMemUsed=_processMemUsed;
@property(nonatomic) unsigned int openInterval; // @synthesize openInterval=_openInterval;
@property(nonatomic) unsigned int openSeq; // @synthesize openSeq=_openSeq;
@property(nonatomic) _Bool isCache; // @synthesize isCache=_isCache;
@property(nonatomic) unsigned int eventType; // @synthesize eventType=_eventType;
- (void).cxx_destruct;
- (id)reportString;
- (int)reportID;

@end

