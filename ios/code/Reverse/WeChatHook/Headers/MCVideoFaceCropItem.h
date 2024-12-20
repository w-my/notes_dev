//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSArray;

@interface MCVideoFaceCropItem : NSObject
{
    unsigned long long _currentFrameIndex;
    double _frameDuration;
    long long _frames;
    NSArray *_frameItemList;
    double _beginTime;
    double _advancedTotalDuration;
    long long _playedTimes;
}

@property(readonly, nonatomic) unsigned long long currentFrameIndex; // @synthesize currentFrameIndex=_currentFrameIndex;
@property(nonatomic) long long playedTimes; // @synthesize playedTimes=_playedTimes;
@property(nonatomic) double advancedTotalDuration; // @synthesize advancedTotalDuration=_advancedTotalDuration;
@property(nonatomic) double beginTime; // @synthesize beginTime=_beginTime;
@property(retain, nonatomic) NSArray *frameItemList; // @synthesize frameItemList=_frameItemList;
@property(nonatomic) long long frames; // @synthesize frames=_frames;
@property(nonatomic) double frameDuration; // @synthesize frameDuration=_frameDuration;
- (void).cxx_destruct;
- (void)advanceTime:(double)arg1;
- (void)resetTime;

@end

