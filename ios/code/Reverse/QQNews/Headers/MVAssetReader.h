//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class AVAsset, AVAssetImageGenerator, AVAudioMix, AVVideoComposition, NSError;

@interface MVAssetReader : NSObject
{
    _Bool _canRead;
    _Bool _isReadingToEndTime;
    AVAsset *_asset;
    AVVideoComposition *_videoComposition;
    AVAudioMix *_audioMix;
    NSError *_error;
    double _timeRangeDuration;
    CDUnknownBlockType _didReadyToRead;
    CDUnknownBlockType _didFailToRead;
    double _timeRangeStart;
    AVAssetImageGenerator *_imageGenerator;
    CDStruct_e83c9415 _timeRange;
}

@property(retain, nonatomic) AVAssetImageGenerator *imageGenerator; // @synthesize imageGenerator=_imageGenerator;
@property(nonatomic) double timeRangeStart; // @synthesize timeRangeStart=_timeRangeStart;
@property(copy, nonatomic) CDUnknownBlockType didFailToRead; // @synthesize didFailToRead=_didFailToRead;
@property(copy, nonatomic) CDUnknownBlockType didReadyToRead; // @synthesize didReadyToRead=_didReadyToRead;
@property(nonatomic) CDStruct_e83c9415 timeRange; // @synthesize timeRange=_timeRange;
@property(readonly, nonatomic) double timeRangeDuration; // @synthesize timeRangeDuration=_timeRangeDuration;
@property(readonly, nonatomic) _Bool isReadingToEndTime; // @synthesize isReadingToEndTime=_isReadingToEndTime;
@property(readonly, nonatomic) _Bool canRead; // @synthesize canRead=_canRead;
@property(readonly, nonatomic) NSError *error; // @synthesize error=_error;
@property(retain, nonatomic) AVAudioMix *audioMix; // @synthesize audioMix=_audioMix;
@property(retain, nonatomic) AVVideoComposition *videoComposition; // @synthesize videoComposition=_videoComposition;
@property(retain, nonatomic) AVAsset *asset; // @synthesize asset=_asset;
- (void).cxx_destruct;
- (CDStruct_1b6d18a9)minimumIntervalOfTimes:(id)arg1;
- (void)initImageGenerator;
- (void)releaseSampleBuffer:(struct opaqueCMSampleBuffer *)arg1;
- (double)timeAtProgress:(double)arg1;
- (double)progressAtTime:(double)arg1;
- (void)videoFrameImagesAtTimes:(id)arg1 completion:(CDUnknownBlockType)arg2;
- (struct CGImage *)videoFrameImageAtTime:(CDStruct_1b6d18a9)arg1 actualTime:(CDStruct_1b6d18a9 *)arg2;
- (struct opaqueCMSampleBuffer *)nextVideoFrameBuffer;
- (void)stop;
- (_Bool)start;
- (void)setTimeRangeWithStartTime:(double)arg1 endTime:(double)arg2;
@property(readonly, nonatomic) struct CGAffineTransform preferredTransform;
@property(readonly, nonatomic) _Bool isSeeking;
- (id)initWithAsset:(id)arg1 videoComposition:(id)arg2 audioMix:(id)arg3;
- (id)initWithAsset:(id)arg1;

@end

