//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "TXCFilterGroup.h"

@class TXCDissolveBlendFilter, TXCImageBuffer;

@interface TXCVEFGhostShadowFilter : TXCFilterGroup
{
    TXCImageBuffer *_imageBuffer;
    TXCDissolveBlendFilter *_dissolveBlendFilter;
    unsigned long long _delayNumber;
}

@property(nonatomic) unsigned long long delayNumber; // @synthesize delayNumber=_delayNumber;
- (void).cxx_destruct;
- (void)addTarget:(id)arg1 atTextureLocation:(long long)arg2;
- (id)init;

@end

