//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "RapidNetMetal.h"

@class SegmentPreprocessLayer;

@interface YTSegmenterNetMetal : RapidNetMetal
{
    _Bool _flipX;
    _Bool _flipY;
    SegmentPreprocessLayer *_preprocessLayer;
}

@property(retain, nonatomic) SegmentPreprocessLayer *preprocessLayer; // @synthesize preprocessLayer=_preprocessLayer;
@property(nonatomic) _Bool flipY; // @synthesize flipY=_flipY;
@property(nonatomic) _Bool flipX; // @synthesize flipX=_flipX;
- (void).cxx_destruct;
- (id)forwardWithCNNImage:(id)arg1 commandBuffer:(id)arg2;
- (void)preloadForDataDimension:(struct CNNDimension)arg1;
- (void)preloadForDataDimension:(struct CNNDimension)arg1 netInputDimension:(struct CNNDimension)arg2;
- (id)constructNetworkWith:(id)arg1;

@end

