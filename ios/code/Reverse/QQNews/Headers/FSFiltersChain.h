//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "FSImageWrapFilter.h"

@class NSMutableArray;

@interface FSFiltersChain : FSImageWrapFilter
{
    NSMutableArray *_filterList;
}

@property(retain, nonatomic) NSMutableArray *filterList; // @synthesize filterList=_filterList;
- (void).cxx_destruct;
- (void)newFrameReadyAtTime:(CDStruct_1b6d18a9)arg1 atIndex:(long long)arg2;
- (void)cleanFilters;
- (id)filtersChain;
- (id)imageFromCurrentFramebufferWithOrientation:(long long)arg1;
- (id)imageFromCurrentFramebuffer;
- (id)framebufferForOutput;
- (void)useNextFrameForImageCapture;
- (void)removeAllTargets;
- (void)removeTarget:(id)arg1;
- (void)addTarget:(id)arg1 atTextureLocation:(long long)arg2;
- (void)addTarget:(id)arg1;
- (void)addFilter:(id)arg1;
- (id)init;

@end
