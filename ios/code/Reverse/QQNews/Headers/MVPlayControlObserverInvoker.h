//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "MVMediaTimelineObserver.h"

@class NSString;

@interface MVPlayControlObserverInvoker : NSObject <MVMediaTimelineObserver>
{
    id <MVPlayControl> _playControl;
    id <MVPlaybackTimeObserver> _target;
}

+ (id)invokerWithTarget:(id)arg1 forPlayControl:(id)arg2;
@property(nonatomic) __weak id <MVPlaybackTimeObserver> target; // @synthesize target=_target;
@property(nonatomic) __weak id <MVPlayControl> playControl; // @synthesize playControl=_playControl;
- (void).cxx_destruct;
- (void)didReachEndTime;
- (void)didSeekToTime:(struct _QZEVMediaTime)arg1;
- (void)updateWithTime:(struct _QZEVMediaTime)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
