//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MVVideoEffectGPUAction.h"

@class MVGPUImageMaskImageListFilter, MVVideoEffectBlendImageListActionXMLItem;

@interface MVVideoEffectBlendImageListAction : MVVideoEffectGPUAction
{
    MVVideoEffectBlendImageListActionXMLItem *_blendXMLItem;
    MVGPUImageMaskImageListFilter *_blendFilter;
}

@property(retain, nonatomic) MVGPUImageMaskImageListFilter *blendFilter; // @synthesize blendFilter=_blendFilter;
@property(retain, nonatomic) MVVideoEffectBlendImageListActionXMLItem *blendXMLItem; // @synthesize blendXMLItem=_blendXMLItem;
- (void).cxx_destruct;
- (void)setVideoTime:(double)arg1;
- (void)createFilter;
- (void)reset;
- (void)prepareForProcessing;
- (id)outputFilter;
- (void)removeAllTargets;
- (id)initWithXMLItem:(id)arg1;

@end
