//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "MVMediaTimelineObserver.h"

@class MVMediaRealtimeTimelineReference, MVMediaTimelineControl, NSArray, NSMutableArray, NSString;

@interface MVMediaTimeline : NSObject <MVMediaTimelineObserver>
{
    float _rate;
    id <MVMediaTimelineReference> _reference;
    long long _preferredFramesPerSecond;
    double _currentTime;
    long long _state;
    MVMediaTimelineControl *_control;
    MVMediaRealtimeTimelineReference *_defaultReference;
    NSMutableArray *_allObservers;
}

+ (id)timeline;
@property(retain, nonatomic) NSMutableArray *allObservers; // @synthesize allObservers=_allObservers;
@property(retain, nonatomic) MVMediaRealtimeTimelineReference *defaultReference; // @synthesize defaultReference=_defaultReference;
@property(retain, nonatomic) MVMediaTimelineControl *control; // @synthesize control=_control;
@property(readonly, nonatomic) long long state; // @synthesize state=_state;
@property(readonly, nonatomic) double currentTime; // @synthesize currentTime=_currentTime;
@property(nonatomic) float rate; // @synthesize rate=_rate;
@property(nonatomic) long long preferredFramesPerSecond; // @synthesize preferredFramesPerSecond=_preferredFramesPerSecond;
@property(retain, nonatomic) id <MVMediaTimelineReference> reference; // @synthesize reference=_reference;
- (void).cxx_destruct;
- (void)removeAllObservers;
- (id)weakObjectForObserver:(id)arg1;
- (void)removeObserver:(id)arg1;
- (void)addObserver:(id)arg1;
- (void)seekToTime:(double)arg1;
- (void)stop;
- (void)pause;
- (void)start;
@property(readonly, nonatomic) _Bool isValid;
@property(readonly, nonatomic) double terminal;
@property(readonly, nonatomic) double origin;
@property(copy, nonatomic) NSArray *accessableTimeRanges;
@property(readonly, nonatomic) NSArray *observers;
- (void)didReachEndTime;
- (void)didSeekToTime:(struct _QZEVMediaTime)arg1;
- (void)updateWithTime:(struct _QZEVMediaTime)arg1;
- (void)seekToTime:(double)arg1 checkControlActions:(_Bool)arg2;
- (_Bool)handleControlActions:(id)arg1 atTime:(struct _QZEVMediaTime)arg2;
@property(readonly, nonatomic) id <MVMediaTimelineReference> realReference;
- (void)initialize;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
