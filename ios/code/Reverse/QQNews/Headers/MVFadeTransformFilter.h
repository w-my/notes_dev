//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "FSImageWrapFilter.h"

@class GPUImageAlphaBlendFilter, GPUImageTransformFilter;

@interface MVFadeTransformFilter : FSImageWrapFilter
{
    double _mix;
    GPUImageTransformFilter *_transformFilter1;
    GPUImageTransformFilter *_transformFilter2;
    GPUImageAlphaBlendFilter *_alphaBlendFilter;
    struct CGAffineTransform _transform1;
    struct CGAffineTransform _transform2;
}

@property(retain, nonatomic) GPUImageAlphaBlendFilter *alphaBlendFilter; // @synthesize alphaBlendFilter=_alphaBlendFilter;
@property(retain, nonatomic) GPUImageTransformFilter *transformFilter2; // @synthesize transformFilter2=_transformFilter2;
@property(retain, nonatomic) GPUImageTransformFilter *transformFilter1; // @synthesize transformFilter1=_transformFilter1;
@property(nonatomic) double mix; // @synthesize mix=_mix;
@property(nonatomic) struct CGAffineTransform transform2; // @synthesize transform2=_transform2;
@property(nonatomic) struct CGAffineTransform transform1; // @synthesize transform1=_transform1;
- (void).cxx_destruct;
- (id)imageFromCurrentFramebufferWithOrientation:(long long)arg1;
- (id)imageFromCurrentFramebuffer;
- (id)framebufferForOutput;
- (void)useNextFrameForImageCapture;
- (void)setFrameProcessingCompletionBlock:(CDUnknownBlockType)arg1;
- (void)removeTarget:(id)arg1;
- (void)addTarget:(id)arg1;
- (void)newFrameReadyAtTime:(CDStruct_1b6d18a9)arg1 atIndex:(long long)arg2;
- (void)cleanFilter;
- (void)removeAllTargets;
- (id)init;

@end

