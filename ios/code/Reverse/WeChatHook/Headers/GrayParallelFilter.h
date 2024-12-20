//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MyCamGPUFilter.h"

@interface GrayParallelFilter : MyCamGPUFilter
{
    float width;
    float height;
    float centerX;
    float centerY;
    float radiusIn;
    float radiusOut;
    float theta;
}

- (void)setProperty:(id)arg1 value:(id)arg2;
- (void)setImageWidth:(float)arg1 andHeight:(float)arg2;
- (void)setCenterX:(float)arg1 centerY:(float)arg2 withRadiusIn:(float)arg3 withRadiusOut:(float)arg4 withTheta:(float)arg5;
- (void)newFrameReadyAtTime:(CDStruct_1b6d18a9)arg1 atIndex:(long long)arg2;
- (id)init;

@end

