//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MVVideoEffectGPUAction.h"

@class GPUImageTransformFilter, MVVideoEffectTransformActionXMLItem;

@interface MVVideoEffectTransformAction : MVVideoEffectGPUAction
{
    MVVideoEffectTransformActionXMLItem *_transformXMLItem;
    GPUImageTransformFilter *_trasformFilter;
}

@property(retain, nonatomic) GPUImageTransformFilter *trasformFilter; // @synthesize trasformFilter=_trasformFilter;
@property(retain, nonatomic) MVVideoEffectTransformActionXMLItem *transformXMLItem; // @synthesize transformXMLItem=_transformXMLItem;
- (void).cxx_destruct;
- (void)setVideoTime:(double)arg1;
- (void)createFilter;
- (id)outputFilter;
- (void)removeAllTargets;
- (id)initWithXMLItem:(id)arg1;

@end

