//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MultiFilterConnect.h"

@class Lens, TTGPUImageGaussianBlurFilter, USMFilter;

@interface Sharpen : MultiFilterConnect
{
    TTGPUImageGaussianBlurFilter *gauss;
    USMFilter *usm;
    Lens *lens;
    float amount;
}

@property(nonatomic) float amount; // @synthesize amount;
- (void).cxx_destruct;
- (void)setProperty:(id)arg1 value:(id)arg2;
- (void)NewFilter;
- (void)setParameter:(float)arg1;
- (id)init;

@end

