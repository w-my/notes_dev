//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSArray, NSMutableArray;

@interface WCSmartGroupRunInfo : NSObject
{
    _Bool _isOnlyRecommendGroups;
    _Bool _bRepick;
    unsigned int _totalGroupCnt;
    unsigned int _totalMMCnt;
    unsigned long long _seq;
    NSArray *_arrInputMemlist;
    NSArray *_arrSessionCopy;
    unsigned long long _taskBeginTime;
    unsigned long long _taskEndTime;
    NSMutableArray *_arrResult;
    NSMutableArray *_arrTimeCost;
    NSMutableArray *_arrSharedGroupCnt;
    NSArray *_arrSharedGroup;
}

@property(retain, nonatomic) NSArray *arrSharedGroup; // @synthesize arrSharedGroup=_arrSharedGroup;
@property(retain, nonatomic) NSMutableArray *arrSharedGroupCnt; // @synthesize arrSharedGroupCnt=_arrSharedGroupCnt;
@property(retain, nonatomic) NSMutableArray *arrTimeCost; // @synthesize arrTimeCost=_arrTimeCost;
@property(retain, nonatomic) NSMutableArray *arrResult; // @synthesize arrResult=_arrResult;
@property(nonatomic) _Bool bRepick; // @synthesize bRepick=_bRepick;
@property(nonatomic) unsigned int totalMMCnt; // @synthesize totalMMCnt=_totalMMCnt;
@property(nonatomic) unsigned int totalGroupCnt; // @synthesize totalGroupCnt=_totalGroupCnt;
@property(nonatomic) unsigned long long taskEndTime; // @synthesize taskEndTime=_taskEndTime;
@property(nonatomic) unsigned long long taskBeginTime; // @synthesize taskBeginTime=_taskBeginTime;
@property(retain, nonatomic) NSArray *arrSessionCopy; // @synthesize arrSessionCopy=_arrSessionCopy;
@property(retain, nonatomic) NSArray *arrInputMemlist; // @synthesize arrInputMemlist=_arrInputMemlist;
@property(nonatomic) _Bool isOnlyRecommendGroups; // @synthesize isOnlyRecommendGroups=_isOnlyRecommendGroups;
@property(nonatomic) unsigned long long seq; // @synthesize seq=_seq;
- (void).cxx_destruct;
- (id)getSessionByUserName:(id)arg1;
- (id)getInputMemDesc;

@end

