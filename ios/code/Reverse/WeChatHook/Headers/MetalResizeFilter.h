//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "GPUImageFilter.h"

@interface MetalResizeFilter : GPUImageFilter
{
    struct CGSize _segmentSize;
}

@property(nonatomic) struct CGSize segmentSize; // @synthesize segmentSize=_segmentSize;
- (struct CGSize)outputFrameSize;
- (struct CGSize)sizeOfFBO;
- (void)setInputSize:(struct CGSize)arg1 atIndex:(long long)arg2;

@end

