//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class MVMediaComposition;

@protocol MVMediaAction <NSObject>
@property(nonatomic) __weak MVMediaComposition *superComposition;
@property(nonatomic) float rate;
@property(nonatomic) long long mediaState;
@property(nonatomic) long long repeatCount;
@property(nonatomic) double duration;
@property(nonatomic) double startTime;
- (void)seekToTime:(struct _QZEVMediaTime)arg1;
- (void)updateWithTime:(struct _QZEVMediaTime)arg1;
- (void)didResignActive;
- (void)willBecomeActive;

@optional
- (void)didMixWithMixer:(id <MVMediaMixer>)arg1;
@end

