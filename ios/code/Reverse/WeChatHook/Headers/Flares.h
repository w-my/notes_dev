//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MyCamGPUFilter.h"

@class NSArray, UIImage;

@interface Flares : MyCamGPUFilter
{
    NSArray *flareImageNames;
    UIImage *flareImage;
    int last_idx;
    float last_ratio;
    int _flare_idx;
    int _index;
}

@property(nonatomic) int index; // @synthesize index=_index;
@property(nonatomic) int flare_idx; // @synthesize flare_idx=_flare_idx;
- (void).cxx_destruct;
- (id)getProperty:(id)arg1;
- (void)setProperty:(id)arg1 value:(id)arg2;
- (id)flareImageAtIndex:(long long)arg1;
- (void)newFrameReadyAtTime:(CDStruct_1b6d18a9)arg1 atIndex:(long long)arg2;
- (void)dealloc;
- (id)initWithIndex:(int)arg1;

@end

