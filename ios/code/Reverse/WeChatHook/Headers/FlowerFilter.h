//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MultiFilterConnect.h"

@class BrightnessFilter, ContrastFilter, HSVAdjuster_ColorChannel;

@interface FlowerFilter : MultiFilterConnect
{
    HSVAdjuster_ColorChannel *h;
    ContrastFilter *c;
    BrightnessFilter *b;
}

- (void).cxx_destruct;
- (void)setProperty:(id)arg1 value:(id)arg2;
- (void)NewFilter;
- (id)init;

@end

