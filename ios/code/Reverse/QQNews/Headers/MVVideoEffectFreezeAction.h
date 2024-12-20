//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MVVideoEffectGPUAction.h"

@class MVImageFreezeFilter;

@interface MVVideoEffectFreezeAction : MVVideoEffectGPUAction
{
    MVImageFreezeFilter *_freezeFilter;
}

@property(retain, nonatomic) MVImageFreezeFilter *freezeFilter; // @synthesize freezeFilter=_freezeFilter;
- (void).cxx_destruct;
- (void)setVideoTime:(double)arg1;
- (void)clearCachedBuffer;
- (void)reset;
- (_Bool)shouldProcessFrameAtTime:(double)arg1;
- (void)createFilter;
- (id)outputFilter;
- (void)removeAllTargets;
- (void)dealloc;
- (id)initWithXMLItem:(id)arg1;

@end

