//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@interface ODKCurrentSessionInfo : NSObject
{
    unsigned int _session1Id;
    unsigned int _session2Id;
    unsigned int _session1State;
    unsigned int _session2State;
    unsigned long long _session1StartTime;
    unsigned long long _session2StartTime;
    unsigned long long _session1Du;
    unsigned long long _session2Du;
    unsigned long long _session1interval;
    unsigned long long _session2interval;
}

@property(nonatomic) unsigned long long session2interval; // @synthesize session2interval=_session2interval;
@property(nonatomic) unsigned long long session1interval; // @synthesize session1interval=_session1interval;
@property(nonatomic) unsigned int session2State; // @synthesize session2State=_session2State;
@property(nonatomic) unsigned int session1State; // @synthesize session1State=_session1State;
@property(nonatomic) unsigned long long session2Du; // @synthesize session2Du=_session2Du;
@property(nonatomic) unsigned long long session1Du; // @synthesize session1Du=_session1Du;
@property(nonatomic) unsigned long long session2StartTime; // @synthesize session2StartTime=_session2StartTime;
@property(nonatomic) unsigned long long session1StartTime; // @synthesize session1StartTime=_session1StartTime;
@property(nonatomic) unsigned int session2Id; // @synthesize session2Id=_session2Id;
@property(nonatomic) unsigned int session1Id; // @synthesize session1Id=_session1Id;
- (id)init;

@end

