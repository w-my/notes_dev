//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "GPUImageInput.h"

@class AVAssetWriter, AVAssetWriterInput, AVAssetWriterInputPixelBufferAdaptor, GLProgram, GPUImageContext, GPUImageFramebuffer, NSArray, NSObject<OS_dispatch_queue>, NSString, NSURL;

@interface MVVideoWriter : NSObject <GPUImageInput>
{
    _Bool alreadyFinishedRecording;
    NSURL *movieURL;
    NSString *fileType;
    AVAssetWriter *assetWriter;
    AVAssetWriterInput *assetWriterAudioInput;
    AVAssetWriterInput *assetWriterVideoInput;
    AVAssetWriterInputPixelBufferAdaptor *assetWriterPixelBufferInput;
    GPUImageContext *_movieWriterContext;
    struct __CVBuffer *renderTarget;
    struct __CVBuffer *renderTexture;
    struct CGSize videoSize;
    unsigned long long inputRotation;
    unsigned int movieFramebuffer;
    unsigned int movieRenderbuffer;
    GLProgram *colorSwizzlingProgram;
    int colorSwizzlingPositionAttribute;
    int colorSwizzlingTextureCoordinateAttribute;
    int colorSwizzlingInputTextureUniform;
    GPUImageFramebuffer *firstInputFramebuffer;
    NSObject<OS_dispatch_queue> *audioQueue;
    NSObject<OS_dispatch_queue> *videoQueue;
    _Bool audioEncodingIsFinished;
    _Bool videoEncodingIsFinished;
    _Bool isRecording;
    _Bool allowWriteAudio;
    _Bool willFinish;
    CDUnknownBlockType completeHandler;
    struct {
        CDStruct_1b6d18a9 startTime;
        CDStruct_1b6d18a9 previousFrameTime;
        CDStruct_1b6d18a9 previousAudioTime;
        CDStruct_1b6d18a9 offsetTime;
        CDStruct_1b6d18a9 pausedTime;
    } RecordTime;
    _Bool _hasAudioTrack;
    _Bool _encodingLiveVideo;
    _Bool _shouldPassthroughAudio;
    _Bool enabled;
    _Bool _shouldInvalidateAudioSampleWhenDone;
    _Bool _paused;
    CDUnknownBlockType completionBlock;
    CDUnknownBlockType failureBlock;
    CDUnknownBlockType videoInputReadyCallback;
    CDUnknownBlockType audioInputReadyCallback;
    id <GPUImageMovieWriterDelegate> _delegate;
    unsigned long long _section;
    CDUnknownBlockType _audioProcessingCallback;
    CDStruct_1b6d18a9 _minFrameDuration;
}

@property(nonatomic) CDStruct_1b6d18a9 minFrameDuration; // @synthesize minFrameDuration=_minFrameDuration;
@property(copy, nonatomic) CDUnknownBlockType audioProcessingCallback; // @synthesize audioProcessingCallback=_audioProcessingCallback;
@property(nonatomic) unsigned long long section; // @synthesize section=_section;
@property(nonatomic) id <GPUImageMovieWriterDelegate> delegate; // @synthesize delegate=_delegate;
@property(retain, nonatomic) GPUImageContext *movieWriterContext; // @synthesize movieWriterContext=_movieWriterContext;
@property(nonatomic, getter=isPaused) _Bool paused; // @synthesize paused=_paused;
@property(nonatomic) _Bool shouldInvalidateAudioSampleWhenDone; // @synthesize shouldInvalidateAudioSampleWhenDone=_shouldInvalidateAudioSampleWhenDone;
@property(nonatomic) _Bool enabled; // @synthesize enabled;
@property(copy, nonatomic) CDUnknownBlockType audioInputReadyCallback; // @synthesize audioInputReadyCallback;
@property(copy, nonatomic) CDUnknownBlockType videoInputReadyCallback; // @synthesize videoInputReadyCallback;
@property(copy, nonatomic) CDUnknownBlockType failureBlock; // @synthesize failureBlock;
@property(copy, nonatomic) CDUnknownBlockType completionBlock; // @synthesize completionBlock;
@property(nonatomic) _Bool shouldPassthroughAudio; // @synthesize shouldPassthroughAudio=_shouldPassthroughAudio;
@property(nonatomic) _Bool encodingLiveVideo; // @synthesize encodingLiveVideo=_encodingLiveVideo;
@property(nonatomic) _Bool hasAudioTrack; // @synthesize hasAudioTrack=_hasAudioTrack;
- (void).cxx_destruct;
@property(readonly, nonatomic) AVAssetWriter *assetWriter;
@property(nonatomic) struct CGAffineTransform transform;
@property(readonly, nonatomic) CDStruct_1b6d18a9 duration;
@property(copy, nonatomic) NSArray *metaData;
- (void)setHasAudioTrack:(_Bool)arg1 audioSettings:(id)arg2;
- (void)setCurrentlyReceivingMonochromeInput:(_Bool)arg1;
- (_Bool)wantsMonochromeInput;
- (_Bool)shouldIgnoreUpdatesToThisTarget;
- (void)endProcessing;
- (struct CGSize)maximumOutputSize;
- (void)setInputSize:(struct CGSize)arg1 atIndex:(long long)arg2;
- (void)setInputRotation:(unsigned long long)arg1 atIndex:(long long)arg2;
- (void)setInputFramebuffer:(id)arg1 atIndex:(long long)arg2;
- (long long)nextAvailableTextureIndex;
- (void)newFrameReadyAtTime:(CDStruct_1b6d18a9)arg1 atIndex:(long long)arg2;
- (void)renderAtInternalSizeUsingFramebuffer:(id)arg1;
- (void)setFilterFBO;
- (void)destroyDataFBO;
- (void)createDataFBO;
- (void)enableSynchronizationCallbacks;
- (void)processAudioBuffer:(struct opaqueCMSampleBuffer *)arg1;
- (void)finishRecordingWithCompletionHandler:(CDUnknownBlockType)arg1;
- (void)finishRecording;
- (void)cancelRecording;
- (void)startRecordingInOrientation:(struct CGAffineTransform)arg1;
- (void)startRecording;
- (_Bool)isRecording;
- (void)initializeMovieWithOutputSettings:(id)arg1;
- (void)dealloc;
- (id)initWithMovieURL:(id)arg1 size:(struct CGSize)arg2 fileType:(id)arg3 outputSettings:(id)arg4;
- (id)initWithMovieURL:(id)arg1 size:(struct CGSize)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

