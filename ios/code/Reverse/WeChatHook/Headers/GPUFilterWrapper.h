//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CPUImageFilter.h"

@class GPUImagePicture, MyCamGPUFilter;

@interface GPUFilterWrapper : CPUImageFilter
{
    float param;
    int gpuFilterId;
    GPUImagePicture *_stillImageSource;
    MyCamGPUFilter *_gpuFilter;
}

@property(retain, nonatomic) MyCamGPUFilter *gpuFilter; // @synthesize gpuFilter=_gpuFilter;
@property(retain, nonatomic) GPUImagePicture *stillImageSource; // @synthesize stillImageSource=_stillImageSource;
- (void).cxx_destruct;
- (void)setProperty:(id)arg1 value:(id)arg2;
- (id)main;
- (void)dealloc;
- (id)initWithGPUFilterId:(int)arg1;

@end
