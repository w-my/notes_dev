//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "RapidNet.h"

@interface RPNSegmenter : RapidNet
{
}

- (id)gpuSegmentWithImageRGBA:(id)arg1 flipX:(_Bool)arg2 flipY:(_Bool)arg3 commandBuffer:(id)arg4;
- (id)gpuSegmentWithTextureRGBA:(id)arg1 flipX:(_Bool)arg2 flipY:(_Bool)arg3 commandBuffer:(id)arg4;
- (struct Mat)cpuSegmentWithImageRGB:(const struct Mat *)arg1 inputBlob:(struct rpd_blob<float> *)arg2 outputBlob:(struct rpd_blob<float> *)arg3;
- (struct Mat)cpuSegmentWithImageRGB:(const struct Mat *)arg1;
- (Class)rapidNetMetalClass;
- (Class)rapidNetCPUClass;

@end

