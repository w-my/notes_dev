//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "TXCBeautifyFilter.h"

@class TXCWxdySmoothFilter;

@interface TXCWxdyBeautifyFilter : TXCBeautifyFilter
{
    float _smoothDegree;
    TXCWxdySmoothFilter *_smoothFilter;
}

- (void).cxx_destruct;
- (void)newFrameReadyAtTime:(CDStruct_1b6d18a9)arg1 atIndex:(long long)arg2;
- (void)setBeautyLevel:(float)arg1;
- (id)init;

@end

