//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSString;

@interface MinimizeReportOpInfo : NSObject
{
    int _opType;
    int _taskType;
    NSString *_miniSessionId;
    NSString *_aggreSessionId;
    unsigned long long _taskIdleTime;
    unsigned long long _aggreWindowExistTime;
    unsigned long long _singleTaskExistTime;
    long long _taskOrder;
    unsigned long long _taskForegroundTime;
}

@property(nonatomic) unsigned long long taskForegroundTime; // @synthesize taskForegroundTime=_taskForegroundTime;
@property(nonatomic) long long taskOrder; // @synthesize taskOrder=_taskOrder;
@property(nonatomic) int taskType; // @synthesize taskType=_taskType;
@property(nonatomic) unsigned long long singleTaskExistTime; // @synthesize singleTaskExistTime=_singleTaskExistTime;
@property(nonatomic) unsigned long long aggreWindowExistTime; // @synthesize aggreWindowExistTime=_aggreWindowExistTime;
@property(nonatomic) unsigned long long taskIdleTime; // @synthesize taskIdleTime=_taskIdleTime;
@property(retain, nonatomic) NSString *aggreSessionId; // @synthesize aggreSessionId=_aggreSessionId;
@property(retain, nonatomic) NSString *miniSessionId; // @synthesize miniSessionId=_miniSessionId;
@property(nonatomic) int opType; // @synthesize opType=_opType;
- (void).cxx_destruct;

@end

