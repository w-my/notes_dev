//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "FSImageWrapFilter.h"

@class MVGhostTrailBlendFilter, NSMutableArray;

@interface MVImageGhostTrailFilter : FSImageWrapFilter
{
    int _frameCount;
    NSMutableArray *_bufferList;
    MVGhostTrailBlendFilter *_ghostTrailBlendFilter;
}

@property(retain, nonatomic) MVGhostTrailBlendFilter *ghostTrailBlendFilter; // @synthesize ghostTrailBlendFilter=_ghostTrailBlendFilter;
@property(retain, nonatomic) NSMutableArray *bufferList; // @synthesize bufferList=_bufferList;
@property(nonatomic) int frameCount; // @synthesize frameCount=_frameCount;
- (void).cxx_destruct;
- (void)setAlpha4:(double)arg1;
- (void)setAlpha3:(double)arg1;
- (void)setAlpha2:(double)arg1;
- (void)setAlpha:(double)arg1;
- (id)imageFromCurrentFramebufferWithOrientation:(long long)arg1;
- (id)imageFromCurrentFramebuffer;
- (id)framebufferForOutput;
- (void)useNextFrameForImageCapture;
- (void)setFrameProcessingCompletionBlock:(CDUnknownBlockType)arg1;
- (void)removeTarget:(id)arg1;
- (void)addTarget:(id)arg1;
- (void)newFrameReadyAtTime:(CDStruct_1b6d18a9)arg1 atIndex:(long long)arg2;
- (void)removeAllCachedFrames;
- (void)cleanFilter;
- (void)removeAllTargets;
- (void)dealloc;
- (id)init;

@end
