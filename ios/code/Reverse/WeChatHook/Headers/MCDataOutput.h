//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "GPUImageInput.h"

@class GLProgram, GPUImageFramebuffer, NSString;

@interface MCDataOutput : NSObject <GPUImageInput>
{
    struct __CVOpenGLESTextureCache *coreVideoTextureCache;
    struct __CVBuffer *renderTarget;
    struct __CVBuffer *renderTexture;
    struct CGSize videoSize;
    unsigned int movieFramebuffer;
    unsigned int movieRenderbuffer;
    GLProgram *colorSwizzlingProgram;
    int colorSwizzlingPositionAttribute;
    int colorSwizzlingTextureCoordinateAttribute;
    int colorSwizzlingFormatUniform;
    int colorSwizzlingVideoWidthUniform;
    int colorSwizzlingVideoHeightUniform;
    int colorSwizzlingInputTextureUniform;
    GPUImageFramebuffer *inputTextureForMovieRendering;
    CDStruct_1b6d18a9 previousFrameTime;
    struct __CVBuffer *reusePixelBuffer;
    _Bool supportsFastTextureUpload;
    _Bool _ignoreIOSurfaceBack;
    _Bool _enableCostLog;
    int _format;
    id <MCDataOutputDelegate> _delegate;
    double _skipVideoHeaderTime;
    struct opaqueCMSampleBuffer *_referenceBuffer;
    CDStruct_1b6d18a9 _startTime;
}

@property CDStruct_1b6d18a9 startTime; // @synthesize startTime=_startTime;
@property(nonatomic) _Bool enableCostLog; // @synthesize enableCostLog=_enableCostLog;
@property(nonatomic) _Bool ignoreIOSurfaceBack; // @synthesize ignoreIOSurfaceBack=_ignoreIOSurfaceBack;
@property(nonatomic) struct opaqueCMSampleBuffer *referenceBuffer; // @synthesize referenceBuffer=_referenceBuffer;
@property(nonatomic) int format; // @synthesize format=_format;
@property(nonatomic) double skipVideoHeaderTime; // @synthesize skipVideoHeaderTime=_skipVideoHeaderTime;
@property(nonatomic) __weak id <MCDataOutputDelegate> delegate; // @synthesize delegate=_delegate;
- (void).cxx_destruct;
- (void)setCurrentlyReceivingMonochromeInput:(_Bool)arg1;
- (_Bool)wantsMonochromeInput;
- (_Bool)enabled;
- (_Bool)shouldIgnoreUpdatesToThisTarget;
- (void)endProcessing;
- (struct CGSize)maximumOutputSize;
- (void)setInputRotation:(unsigned long long)arg1 atIndex:(long long)arg2;
- (void)setInputSize:(struct CGSize)arg1 atIndex:(long long)arg2;
- (long long)nextAvailableTextureIndex;
- (void)setInputFramebuffer:(id)arg1 atIndex:(long long)arg2;
- (void)newFrameReadyAtTime:(CDStruct_1b6d18a9)arg1 atIndex:(long long)arg2;
- (void)renderAtInternalSize;
- (void)setFilterFBO;
- (void)destroyDataFBO;
- (void)createDataFBO;
- (void)finishOutputing:(CDUnknownBlockType)arg1;
- (void)dealloc;
- (id)initWithVideoSize:(struct CGSize)arg1 format:(int)arg2;
- (id)initWithVideoSize:(struct CGSize)arg1;
- (void)newImageReady;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
