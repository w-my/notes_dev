//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MVVideoEffectGPUAction.h"

@class MVImageBlinkFilter, MVVideoEffectBlinkActionXMLItem;

@interface MVVideoEffectBlinkAction : MVVideoEffectGPUAction
{
    MVVideoEffectBlinkActionXMLItem *_blinkXMLItem;
    MVImageBlinkFilter *_blinkFilter;
}

@property(retain, nonatomic) MVImageBlinkFilter *blinkFilter; // @synthesize blinkFilter=_blinkFilter;
@property(retain, nonatomic) MVVideoEffectBlinkActionXMLItem *blinkXMLItem; // @synthesize blinkXMLItem=_blinkXMLItem;
- (void).cxx_destruct;
- (void)setVideoTime:(double)arg1;
- (void)createFilter;
- (id)outputFilter;
- (void)removeAllTargets;
- (void)dealloc;
- (id)initWithXMLItem:(id)arg1;

@end
