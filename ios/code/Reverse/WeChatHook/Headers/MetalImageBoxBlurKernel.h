//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MetalImageKernel.h"

@interface MetalImageBoxBlurKernel : MetalImageKernel
{
    id <MTLFunction> k_fuction2;
    id <MTLComputePipelineState> k_computePipelineState2;
    unsigned int _radius;
    id <MTLBuffer> _dimensionBuffer;
}

@property(retain, nonatomic) id <MTLBuffer> dimensionBuffer; // @synthesize dimensionBuffer=_dimensionBuffer;
@property(nonatomic) unsigned int radius; // @synthesize radius=_radius;
- (void).cxx_destruct;
- (void)newTextureReadyAtTime:(CDStruct_1b6d18a9)arg1 atIndex:(long long)arg2;
- (id)init;

@end

