//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MyCamGPUFilter.h"

#import "TTMicBaseFaceInputFaceProtocol.h"

@class NSArray, NSMutableArray, NSString;

@interface MultiFilterConnect : MyCamGPUFilter <TTMicBaseFaceInputFaceProtocol>
{
    NSMutableArray *arrays;
    NSMutableArray *PairArrays;
    NSArray *_faceFeatures;
}

@property(retain, nonatomic) NSArray *faceFeatures; // @synthesize faceFeatures=_faceFeatures;
- (void).cxx_destruct;
- (void)setWidth:(int)arg1 andHeight:(int)arg2;
- (long long)filterCount;
- (void)addFilter:(id)arg1;
- (id)imageByFilteringImage:(id)arg1;
- (id)imageFromCurrentFramebufferWithOrientation:(long long)arg1;
- (id)imageFromCurrentFramebuffer;
- (id)framebufferForOutput;
- (void)useNextFrameForImageCapture;
- (void)setFrameProcessingCompletionBlock:(CDUnknownBlockType)arg1;
- (void)setOutput:(long long)arg1 forInput:(long long)arg2 forIndex:(long long)arg3;
- (void)setVertex:(const float *)arg1;
- (void)setTextureCoordinate:(const float *)arg1;
- (id)targets;
- (void)removeAllTargets;
- (void)removeTarget:(id)arg1;
- (void)addTarget:(id)arg1 atTextureLocation:(long long)arg2;
- (void)addTarget:(id)arg1;
- (void)newFrameReadyAtTime:(CDStruct_1b6d18a9)arg1 atIndex:(long long)arg2;
- (void)cleanFilter;
- (void)NewFilter;
- (id)init;
- (id)getLastFilter;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
