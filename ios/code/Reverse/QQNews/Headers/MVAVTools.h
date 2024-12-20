//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@interface MVAVTools : NSObject
{
}

+ (struct CGSize)resolutionForVideoSize:(struct CGSize)arg1 limitedByResolution:(long long)arg2;
+ (struct CGSize)resolutionForVideoSize:(struct CGSize)arg1 limitedByLongestEdge:(double)arg2;
+ (CDStruct_1b6d18a9)durationOfAudioAtPath:(id)arg1 timeRange:(CDStruct_e83c9415)arg2;
+ (CDStruct_1b6d18a9)audioDurationOfAsset:(id)arg1 timeRange:(CDStruct_e83c9415)arg2;
+ (CDStruct_1b6d18a9)durationOfVideoAtPath:(id)arg1 timeRange:(CDStruct_e83c9415)arg2;
+ (CDStruct_1b6d18a9)durationOfAsset:(id)arg1 timeRange:(CDStruct_e83c9415)arg2;
+ (id)getDeviceName;
+ (id)authorInfo;
+ (id)metaDataForAsset:(id)arg1 withMetaString:(id)arg2;
+ (id)saveOutputVideoWithAsset:(id)arg1 toFilePath:(id)arg2 videoSettings:(id)arg3 audioSettings:(id)arg4 audioMix:(id)arg5 metaInfo:(id)arg6 completion:(CDUnknownBlockType)arg7;
+ (id)saveOutputVideoWithAsset:(id)arg1 toFilePath:(id)arg2 metaInfo:(id)arg3 completion:(CDUnknownBlockType)arg4;
+ (id)mergeVideoFile:(id)arg1 andAudioFile:(id)arg2 videoSpeed:(double)arg3;
+ (id)debugInfoForTracksOfAsset:(id)arg1;
+ (id)audioMixInputParametersWithTrack:(id)arg1 startVolume:(float)arg2 endVolume:(float)arg3 timeRange:(CDStruct_e83c9415)arg4;
+ (id)audioMixInputParametersWithTrack:(id)arg1 volume:(float)arg2;
+ (void)removeTracksWithMediaType:(id)arg1 forComposition:(id)arg2;
+ (void)removeEmptyTracksForComposition:(id)arg1;
+ (void)readAsset:(id)arg1 forVideoSize:(struct CGSize *)arg2 videoBitRate:(long long *)arg3 frameRate:(long long *)arg4 audioBitRate:(long long *)arg5;
+ (id)timeRangesForContentSegmentsOfAsset:(id)arg1;
+ (struct CGSize)videoSizeOfAsset:(id)arg1;
+ (id)videoCompositionWithAsset:(id)arg1 videoSettings:(id)arg2;
+ (id)assetByMergingVideoAsset:(id)arg1 withAudioAsset:(id)arg2;
+ (id)assetByMergingVideoFile:(id)arg1 withAudioFile:(id)arg2;
+ (CDStruct_1b6d18a9)insertTracksOfAsset:(id)arg1 withTimeRange:(CDStruct_e83c9415)arg2 rate:(float)arg3 intoCompositionTrack:(id)arg4 atTime:(CDStruct_1b6d18a9)arg5;
+ (CDStruct_1b6d18a9)cmTime:(CDStruct_1b6d18a9)arg1 mapFromTimeRange:(CDStruct_e83c9415)arg2 toTimeRange:(CDStruct_e83c9415)arg3 preferredTimescale:(int)arg4;
+ (CDStruct_1b6d18a9)cmTime:(CDStruct_1b6d18a9)arg1 mutiplyBy:(double)arg2 preferredTimescale:(int)arg3;
+ (CDStruct_e83c9415)cmTimeRange:(CDStruct_e83c9415)arg1 convertByTimescale:(int)arg2;
+ (CDStruct_1b6d18a9)cmTime:(CDStruct_1b6d18a9)arg1 convertByTimescale:(int)arg2;
+ (struct CGAffineTransform)preferredTransformForTrack:(id)arg1 renderingToSize:(struct CGSize)arg2;
+ (struct CGSize)preferredRenderSizeForTrack:(id)arg1;
+ (id)instructionOfTransform:(struct CGAffineTransform)arg1 forTrack:(id)arg2 timeRange:(CDStruct_e83c9415)arg3;
+ (id)instructionForRenderingTrack:(id)arg1 toSize:(struct CGSize)arg2 atTimeRange:(CDStruct_e83c9415)arg3;
+ (id)instructionWithLayerInstructions:(id)arg1 timeRange:(CDStruct_e83c9415)arg2;
+ (id)layerInstructionOfTransform:(struct CGAffineTransform)arg1 forTrack:(id)arg2 atTime:(CDStruct_1b6d18a9)arg3;
+ (_Bool)insertTimeRange:(CDStruct_e83c9415)arg1 ofTrack:(id)arg2 intoCompositionTrack:(id)arg3 atTime:(CDStruct_1b6d18a9)arg4 scaleToDuration:(CDStruct_1b6d18a9)arg5;
+ (_Bool)mediaTypes:(id)arg1 containsMediaType:(id)arg2;
+ (void)printParamsOfVideo:(id)arg1;
+ (id)passthroughExportWithVideoItem:(id)arg1 videoSettings:(id)arg2 outputFile:(id)arg3 completion:(CDUnknownBlockType)arg4;
+ (id)exportVideoWithVideoItem:(id)arg1 videoSettings:(id)arg2 outputFile:(id)arg3 progress:(CDUnknownBlockType)arg4 completion:(CDUnknownBlockType)arg5;
+ (void)finishExportingVideoWithOutputFile:(id)arg1 error:(id)arg2 callback:(CDUnknownBlockType)arg3;
+ (id)assetForExportingVideoItem:(id)arg1 audioMix:(id *)arg2;
+ (_Bool)isValidVideoOutputSettings:(id)arg1;
+ (_Bool)isValidVideoSettings:(id)arg1;
+ (void)makeImagesWithGenerator:(id)arg1 forTimes:(id)arg2 size:(struct CGSize)arg3 completion:(CDUnknownBlockType)arg4;
+ (void)makeImagesWithGenerator:(id)arg1 count:(long long)arg2 timeRange:(CDStruct_e83c9415)arg3 completion:(CDUnknownBlockType)arg4;
+ (id)makeCoverImagesForAsset:(id)arg1 count:(long long)arg2 completion:(CDUnknownBlockType)arg3;
+ (id)makeCoverImageWithGenerator:(id)arg1 atTime:(double)arg2 actualTime:(double *)arg3;
+ (id)makeCoverImageForAsset:(id)arg1 atTime:(double)arg2 actualTime:(double *)arg3;
+ (id)makeCoverImageForAsset:(id)arg1 atTime:(double)arg2;
+ (id)makeCoverImageForVideoWithPath:(id)arg1 atTime:(double)arg2;
+ (id)lastFrameOfVideo:(id)arg1;
+ (id)makeImageWithImageGenerator:(id)arg1 atTime:(CDStruct_1b6d18a9)arg2 actualTime:(CDStruct_1b6d18a9 *)arg3;

@end

