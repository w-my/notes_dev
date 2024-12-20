//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MVEffectAction.h"

@class GPUImageFilter;

@interface MVVideoRenderAction : MVEffectAction
{
    GPUImageFilter *_filter;
    id <GPUImageInput> _input;
}

@property(retain, nonatomic) id <GPUImageInput> input; // @synthesize input=_input;
@property(retain, nonatomic) GPUImageFilter *filter; // @synthesize filter=_filter;
- (void).cxx_destruct;
- (void)updateFilterChain;

@end

