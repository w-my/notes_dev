//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MVAVAsset.h"

@class AVMutableAudioMix, AVMutableComposition, AVMutableVideoComposition;

@interface MVVideoAsset : MVAVAsset
{
    _Bool _clips;
    _Bool _containsOriginalAudio;
    _Bool _containsBGM;
    AVMutableComposition *_asset;
    AVMutableVideoComposition *_videoComposition;
    AVMutableAudioMix *_audioMix;
    struct CGSize _videoSize;
}

+ (id)assetForVideoWithMedia:(id)arg1 videoSettings:(id)arg2 clips:(_Bool)arg3;
+ (id)assetWithMedia:(id)arg1 videoSettings:(id)arg2 options:(id)arg3;
@property(readonly, nonatomic) _Bool containsBGM; // @synthesize containsBGM=_containsBGM;
@property(readonly, nonatomic) _Bool containsOriginalAudio; // @synthesize containsOriginalAudio=_containsOriginalAudio;
@property(readonly, nonatomic) _Bool clips; // @synthesize clips=_clips;
@property(readonly, nonatomic) struct CGSize videoSize; // @synthesize videoSize=_videoSize;
@property(readonly, nonatomic) AVMutableAudioMix *audioMix; // @synthesize audioMix=_audioMix;
@property(readonly, nonatomic) AVMutableVideoComposition *videoComposition; // @synthesize videoComposition=_videoComposition;
@property(readonly, nonatomic) AVMutableComposition *asset; // @synthesize asset=_asset;
- (void).cxx_destruct;
- (void)printDebugInfo;
- (void)setupAVObjectsWithMedia:(id)arg1 videoSettings:(id)arg2;
- (void)clipWithMedia:(id)arg1 options:(id)arg2;
- (void)addAudioWithMedia:(id)arg1 options:(id)arg2;
- (void)addVideoWithMedia:(id)arg1;

@end
