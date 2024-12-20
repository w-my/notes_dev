//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "GPUImageFilter.h"

#import "MCGridMultiOuputFilterGroupOutputProtocol.h"

@class GPUImageOutput<GPUImageInput>, MCSegmentMVModel, MetalSegmentFilter, NSArray, NSDictionary, NSString;

@interface MCSegmentMVFilter : GPUImageFilter <MCGridMultiOuputFilterGroupOutputProtocol>
{
    NSDictionary *_inputBufferParamsMap;
    NSArray *_inputBufferParamsArray;
    CDStruct_1b6d18a9 _currentProcessTime;
    MetalSegmentFilter *_segFilter;
    GPUImageOutput<GPUImageInput> *_bgframeEffect;
    GPUImageOutput<GPUImageInput> *_bgframeMesh;
    MCSegmentMVModel *_mvModel;
    GPUImageFilter *_filterForFramebuffer;
}

@property(retain, nonatomic) GPUImageFilter *filterForFramebuffer; // @synthesize filterForFramebuffer=_filterForFramebuffer;
@property(retain, nonatomic) MCSegmentMVModel *mvModel; // @synthesize mvModel=_mvModel;
@property(retain, nonatomic) GPUImageOutput<GPUImageInput> *bgframeMesh; // @synthesize bgframeMesh=_bgframeMesh;
@property(retain, nonatomic) GPUImageOutput<GPUImageInput> *bgframeEffect; // @synthesize bgframeEffect=_bgframeEffect;
@property(retain, nonatomic) MetalSegmentFilter *segFilter; // @synthesize segFilter=_segFilter;
- (void).cxx_destruct;
- (void)renderToTextureWithVertices:(const float *)arg1 textureCoordinates:(const float *)arg2;
- (void)newFrameReadyAtTime:(CDStruct_1b6d18a9)arg1 atIndex:(long long)arg2;
- (void)prepareProcessNextCameraFrameParams:(CDStruct_1b6d18a9)arg1;
- (void)_clearAllBuffers;
- (void)_unlockAllBuffers;
- (void)_lockAllBuffers;
- (void)setInputFramebufferMaps:(id)arg1;
- (long long)currentPeriodActivePartIndex;
- (id)currentShowMVGridSettingObject;
- (struct CGSize)preferFilterInputSizeWithRenderId:(long long)arg1;
- (id)currentOpenInputFilterRenderIds;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

