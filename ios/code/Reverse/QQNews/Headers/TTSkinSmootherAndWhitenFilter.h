//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "GPUImageFilterGroup.h"

@class GPUImageLevelsFilter, SkinWhitenFilter, TTBilateralSmootherFilter;

@interface TTSkinSmootherAndWhitenFilter : GPUImageFilterGroup
{
    TTBilateralSmootherFilter *smootherFilter;
    SkinWhitenFilter *whitenFilter;
    GPUImageLevelsFilter *levelFilter;
}

- (void).cxx_destruct;
- (void)setMin:(double)arg1 gamma:(double)arg2 max:(double)arg3 minOut:(double)arg4 maxOut:(double)arg5;
- (void)setSkinFilter:(double)arg1;
@property(nonatomic) float whiten;
@property(nonatomic) float smoothOpacity;
- (id)framebufferForOutput;
- (void)addTarget:(id)arg1;
- (id)init;

@end
