//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSString;

@interface QNProfilerStageLogEntry : NSObject
{
    double _lastCheckpointTime;
    NSString *_stage;
    double _enterTime;
    double _duration;
    double _sealTime;
}

@property(readonly, nonatomic) double sealTime; // @synthesize sealTime=_sealTime;
@property(readonly, nonatomic) double duration; // @synthesize duration=_duration;
@property(readonly, nonatomic) double enterTime; // @synthesize enterTime=_enterTime;
@property(readonly, nonatomic) NSString *stage; // @synthesize stage=_stage;
- (void).cxx_destruct;
- (id)description;
- (void)seal;
- (void)checkpoint:(id)arg1 filename:(const char *)arg2 lineNumber:(int)arg3;
- (id)initWithStage:(id)arg1 enterTime:(double)arg2;

@end

