//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "FSImageWrapFilter.h"

@class GPUImageFramebuffer, GPUImageTwoInputFilter;

@interface MVInputImageFilter : FSImageWrapFilter
{
    GPUImageFramebuffer *_inputFrameBuffer;
    GPUImageTwoInputFilter *_twoInputFilter;
}

@property(retain, nonatomic) GPUImageTwoInputFilter *twoInputFilter; // @synthesize twoInputFilter=_twoInputFilter;
@property(retain, nonatomic) GPUImageFramebuffer *inputFrameBuffer; // @synthesize inputFrameBuffer=_inputFrameBuffer;
- (void).cxx_destruct;
- (id)imageFromCurrentFramebufferWithOrientation:(long long)arg1;
- (id)imageFromCurrentFramebuffer;
- (id)framebufferForOutput;
- (void)useNextFrameForImageCapture;
- (void)setFrameProcessingCompletionBlock:(CDUnknownBlockType)arg1;
- (void)removeTarget:(id)arg1;
- (void)removeAllTargets;
- (void)addTarget:(id)arg1;
- (void)newFrameReadyAtTime:(CDStruct_1b6d18a9)arg1 atIndex:(long long)arg2;
- (void)setInputImage:(id)arg1;
- (void)setInputImagePath:(id)arg1;
- (void)dealloc;
- (id)initWithBlendFragmentShaderFromString:(id)arg1;

@end
