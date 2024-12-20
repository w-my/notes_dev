//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class AVAudioPlayer, FSVideoInput, GPUImageFilter, GPUImageFramebuffer, MCSegmentMVEffect, MCSegmentMVGridSettingObj, MCSegmentMVTransition, NSArray, NSString, TTGPUImageLayer, TTGPUImageLayerFilter;

@interface MCSegmentMVPart : NSObject
{
    _Bool _disableVideo;
    int _backgroundAlphaType;
    int _backgroundAspectMode;
    int _backgroundBlendMode;
    int _coverAspectMode;
    int _coverBlendMode;
    int _foregroundAlphaType;
    int _foregroundAspectMode;
    int _foregroundBlendMode;
    double _duration;
    long long _backgroundType;
    FSVideoInput *_backgroundVideo;
    MCSegmentMVEffect *_cameraFrameEffect;
    GPUImageFramebuffer *_coverImageBuffer;
    FSVideoInput *_foregroundVideo;
    GPUImageFilter *_effectFilter;
    NSArray *_filterParams;
    MCSegmentMVTransition *_finishTransition;
    AVAudioPlayer *_bgmAudio;
    double _advancedTime;
    MCSegmentMVGridSettingObj *_gridSettingFile;
    long long _backgroundTime;
    long long _foregroundTime;
    NSString *_backgroundVideoPath;
    NSString *_foregroundVideoPath;
    NSArray *_gridSettingFiles;
    TTGPUImageLayer *_canvasNode;
    TTGPUImageLayer *_gridNode;
    TTGPUImageLayer *_backgroundNode;
    TTGPUImageLayer *_frameNode;
    TTGPUImageLayer *_coverNode;
    TTGPUImageLayer *_foregroundNode;
    TTGPUImageLayerFilter *_nodeRenderFilter;
}

+ (id)parsePartDictionary:(id)arg1 templateDir:(id)arg2;
@property(retain, nonatomic) TTGPUImageLayerFilter *nodeRenderFilter; // @synthesize nodeRenderFilter=_nodeRenderFilter;
@property(retain, nonatomic) TTGPUImageLayer *foregroundNode; // @synthesize foregroundNode=_foregroundNode;
@property(retain, nonatomic) TTGPUImageLayer *coverNode; // @synthesize coverNode=_coverNode;
@property(retain, nonatomic) TTGPUImageLayer *frameNode; // @synthesize frameNode=_frameNode;
@property(retain, nonatomic) TTGPUImageLayer *backgroundNode; // @synthesize backgroundNode=_backgroundNode;
@property(retain, nonatomic) TTGPUImageLayer *gridNode; // @synthesize gridNode=_gridNode;
@property(retain, nonatomic) TTGPUImageLayer *canvasNode; // @synthesize canvasNode=_canvasNode;
@property(retain, nonatomic) NSArray *gridSettingFiles; // @synthesize gridSettingFiles=_gridSettingFiles;
@property(copy, nonatomic) NSString *foregroundVideoPath; // @synthesize foregroundVideoPath=_foregroundVideoPath;
@property(copy, nonatomic) NSString *backgroundVideoPath; // @synthesize backgroundVideoPath=_backgroundVideoPath;
@property(nonatomic) long long foregroundTime; // @synthesize foregroundTime=_foregroundTime;
@property(nonatomic) long long backgroundTime; // @synthesize backgroundTime=_backgroundTime;
@property(nonatomic) _Bool disableVideo; // @synthesize disableVideo=_disableVideo;
@property(retain, nonatomic) MCSegmentMVGridSettingObj *gridSettingFile; // @synthesize gridSettingFile=_gridSettingFile;
@property(nonatomic) double advancedTime; // @synthesize advancedTime=_advancedTime;
@property(retain, nonatomic) AVAudioPlayer *bgmAudio; // @synthesize bgmAudio=_bgmAudio;
@property(retain, nonatomic) MCSegmentMVTransition *finishTransition; // @synthesize finishTransition=_finishTransition;
@property(retain, nonatomic) NSArray *filterParams; // @synthesize filterParams=_filterParams;
@property(retain, nonatomic) GPUImageFilter *effectFilter; // @synthesize effectFilter=_effectFilter;
@property(nonatomic) int foregroundBlendMode; // @synthesize foregroundBlendMode=_foregroundBlendMode;
@property(nonatomic) int foregroundAspectMode; // @synthesize foregroundAspectMode=_foregroundAspectMode;
@property(nonatomic) int foregroundAlphaType; // @synthesize foregroundAlphaType=_foregroundAlphaType;
@property(retain, nonatomic) FSVideoInput *foregroundVideo; // @synthesize foregroundVideo=_foregroundVideo;
@property(nonatomic) int coverBlendMode; // @synthesize coverBlendMode=_coverBlendMode;
@property(nonatomic) int coverAspectMode; // @synthesize coverAspectMode=_coverAspectMode;
@property(retain, nonatomic) GPUImageFramebuffer *coverImageBuffer; // @synthesize coverImageBuffer=_coverImageBuffer;
@property(retain, nonatomic) MCSegmentMVEffect *cameraFrameEffect; // @synthesize cameraFrameEffect=_cameraFrameEffect;
@property(nonatomic) int backgroundBlendMode; // @synthesize backgroundBlendMode=_backgroundBlendMode;
@property(nonatomic) int backgroundAspectMode; // @synthesize backgroundAspectMode=_backgroundAspectMode;
@property(nonatomic) int backgroundAlphaType; // @synthesize backgroundAlphaType=_backgroundAlphaType;
@property(retain, nonatomic) FSVideoInput *backgroundVideo; // @synthesize backgroundVideo=_backgroundVideo;
@property(nonatomic) long long backgroundType; // @synthesize backgroundType=_backgroundType;
@property(nonatomic) double duration; // @synthesize duration=_duration;
- (void).cxx_destruct;
- (id)processGrid:(id)arg1 canvas:(id)arg2 progress:(double)arg3 ignoreRender:(_Bool)arg4 gridOrder:(_Bool)arg5;
- (id)processGrid:(id)arg1 canvas:(id)arg2 progress:(double)arg3;
- (_Bool)gridOrderCanvas:(id)arg1 progress:(double)arg2;
- (void)resetFrameNode:(id)arg1 parentSize:(struct CGSize)arg2;
- (_Bool)getFilterParam:(double)arg1;
- (id)processCameraFrame:(id)arg1 backgroundFrame:(id)arg2 withEffect:(id)arg3;
- (id)processCameraFrames:(id)arg1 backgroundFrame:(id)arg2 withEffect:(id)arg3;
- (void)prepareProcessNextCameraFrameParams:(CDStruct_1b6d18a9)arg1;
- (void)createNodes:(struct CGSize)arg1;
- (void)pauseAudio;
- (void)stopAudio;
- (void)stopReading;
- (void)reset;
- (void)prepare;
- (id)init;
- (id)initWithPartDictionary:(id)arg1 templateDir:(id)arg2;

@end

