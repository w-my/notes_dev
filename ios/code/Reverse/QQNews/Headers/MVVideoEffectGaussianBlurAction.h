//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MVVideoEffectGPUAction.h"

@class MVFastGaussFilter, MVVideoEffectGaussianBlurActionXMLItem;

@interface MVVideoEffectGaussianBlurAction : MVVideoEffectGPUAction
{
    MVVideoEffectGaussianBlurActionXMLItem *_gaussianBlurXMLItem;
    MVFastGaussFilter *_gaussianBlurFilter;
}

@property(retain, nonatomic) MVFastGaussFilter *gaussianBlurFilter; // @synthesize gaussianBlurFilter=_gaussianBlurFilter;
@property(retain, nonatomic) MVVideoEffectGaussianBlurActionXMLItem *gaussianBlurXMLItem; // @synthesize gaussianBlurXMLItem=_gaussianBlurXMLItem;
- (void).cxx_destruct;
- (void)setVideoTime:(double)arg1;
- (double)progressAtTime:(double)arg1;
- (void)createFilter;
- (id)outputFilter;
- (void)removeAllTargets;
- (id)initWithXMLItem:(id)arg1;

@end
