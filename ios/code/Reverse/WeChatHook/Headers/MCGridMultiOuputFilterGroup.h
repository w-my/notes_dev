//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "GPUImageOutput.h"

#import "GPUImageInput.h"

@class MCGridMultiInputFilter, NSArray, NSMutableArray, NSString;

@interface MCGridMultiOuputFilterGroup : GPUImageOutput <GPUImageInput>
{
    NSMutableArray *filters;
    _Bool isEndProcessing;
    NSArray *_faceAnalyzers;
    NSArray *_handBoxes;
    MCGridMultiInputFilter *_recordFrameBufferFilter;
    NSArray *_initialFilters;
    struct CGSize _preferPrefixInputScale;
}

+ (id)filterGroupWithInputFilters:(id)arg1 terminalFilter:(id)arg2;
@property(retain, nonatomic) NSArray *initialFilters; // @synthesize initialFilters=_initialFilters;
@property(retain, nonatomic) MCGridMultiInputFilter *recordFrameBufferFilter; // @synthesize recordFrameBufferFilter=_recordFrameBufferFilter;
@property(retain, nonatomic) NSArray *handBoxes; // @synthesize handBoxes=_handBoxes;
@property(retain, nonatomic) NSArray *faceAnalyzers; // @synthesize faceAnalyzers=_faceAnalyzers;
@property(nonatomic) struct CGSize preferPrefixInputScale; // @synthesize preferPrefixInputScale=_preferPrefixInputScale;
- (void).cxx_destruct;
- (void)informTargetsAboutNewFrameAtTime:(CDStruct_1b6d18a9)arg1 buffers:(id)arg2;
- (id)framebufferForOutput;
- (void)addTarget:(id)arg1 atTextureLocation:(long long)arg2;
- (void)addTarget:(id)arg1;
- (void)setCurrentlyReceivingMonochromeInput:(_Bool)arg1;
- (_Bool)wantsMonochromeInput;
- (void)endProcessing;
- (struct CGSize)maximumOutputSize;
- (void)forceProcessingAtSizeRespectingAspectRatio:(struct CGSize)arg1;
- (void)forceProcessingAtSize:(struct CGSize)arg1;
- (void)setInputRotation:(unsigned long long)arg1 atIndex:(long long)arg2;
- (void)setInputSize:(struct CGSize)arg1 atIndex:(long long)arg2;
- (long long)nextAvailableTextureIndex;
- (void)setInputFramebuffer:(id)arg1 atIndex:(long long)arg2;
- (void)newFrameReadyAtTime:(CDStruct_1b6d18a9)arg1 atIndex:(long long)arg2;
- (struct CGSize)outputFrameSize;
- (long long)processCurrentFilterListId:(id)arg1 atIndex:(long long)arg2;
- (_Bool)shouldProcessCurrentFilterList:(id)arg1 atIndex:(long long)arg2;
- (void)cleanFilters;
- (unsigned long long)filterCount;
- (id)filterAtIndex:(unsigned long long)arg1;
- (void)addFilter:(id)arg1;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
