//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSArray, NSMutableArray, NSString;

@interface MVAVAssetTrack : NSObject
{
    NSString *_mediaType;
    NSMutableArray *_allSegments;
    CDStruct_e83c9415 _timeRange;
}

+ (id)trackWithMediaType:(id)arg1;
@property(retain, nonatomic) NSMutableArray *allSegments; // @synthesize allSegments=_allSegments;
@property(retain, nonatomic) NSString *mediaType; // @synthesize mediaType=_mediaType;
@property(nonatomic) CDStruct_e83c9415 timeRange; // @synthesize timeRange=_timeRange;
- (void).cxx_destruct;
- (id)description;
@property(readonly, nonatomic) _Bool isEmpty;
@property(readonly, nonatomic) NSArray *segments;
- (void)removeAllSegments;
- (_Bool)addAVSegment:(id)arg1;
- (_Bool)addEmptySegment:(id)arg1;
- (id)init;
- (id)clippedSegmentWithSegment:(id)arg1 accessableTimeRange:(CDStruct_e83c9415)arg2;
- (void)clipWithAccessibleTimeRanges:(id)arg1;
- (void)scaleByRate:(float)arg1;
- (void)appendEmptyTimeRangeWithDuration:(CDStruct_1b6d18a9)arg1;
- (void)insertEmptyTimeRange:(CDStruct_e83c9415)arg1;
- (void)appendPlayTimeRange:(CDStruct_e83c9415)arg1 ofAVItem:(id)arg2 scaleByRate:(float)arg3;
- (_Bool)insertPlayTimeRange:(CDStruct_e83c9415)arg1 ofAVItem:(id)arg2 atTime:(CDStruct_1b6d18a9)arg3 scaleByRate:(float)arg4;
- (void)appendSegment:(id)arg1;
- (_Bool)insertSegment:(id)arg1 atTime:(CDStruct_1b6d18a9)arg2;
- (_Bool)insertSegmentsIntoAVCompositionTrack:(id)arg1 targetAccessableTimeRange:(CDStruct_e83c9415)arg2 outputAudioInputParameters:(id)arg3;
- (_Bool)insertSegmentsIntoAVCompositionTrack:(id)arg1 outputAudioInputParameters:(id)arg2;

@end

