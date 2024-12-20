//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MyCamGPUFilter.h"

@interface FrameFilter : MyCamGPUFilter
{
    float width_offset;
    float height_offset;
    struct CGSize frameSize;
    int effectIndex;
}

- (void)updateParams;
- (void)setProperty:(id)arg1 value:(id)arg2;
- (void)newFrameReadyAtTime:(CDStruct_1b6d18a9)arg1 atIndex:(long long)arg2;
- (void)setupFilterForSize:(struct CGSize)arg1;
- (struct CGSize)sizeOfFBO;
- (id)initWithEffecIndex:(int)arg1;

@end

