//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "GPUImageTwoInputFilter.h"

@class GPUImageFramebuffer;

@interface FSSegmentMergeFilter : GPUImageTwoInputFilter
{
    _Bool _transparentBackground;
    int _strokeGapInPixel;
    int _strokeWidthInPixel;
    GPUImageFramebuffer *_bgImageFramebuffer;
    long long _borderType;
    id <FSSegmentMergeFilterDelegate> _delegate;
    GPUImageFramebuffer *_originFramebuffer;
    struct GPUVector4 _strokeColor;
    struct GPUVector4 _bgColor;
}

@property(retain, nonatomic) GPUImageFramebuffer *originFramebuffer; // @synthesize originFramebuffer=_originFramebuffer;
@property(nonatomic) id <FSSegmentMergeFilterDelegate> delegate; // @synthesize delegate=_delegate;
@property(nonatomic) long long borderType; // @synthesize borderType=_borderType;
@property(nonatomic) int strokeWidthInPixel; // @synthesize strokeWidthInPixel=_strokeWidthInPixel;
@property(nonatomic) int strokeGapInPixel; // @synthesize strokeGapInPixel=_strokeGapInPixel;
@property(nonatomic) struct GPUVector4 bgColor; // @synthesize bgColor=_bgColor;
@property(nonatomic) struct GPUVector4 strokeColor; // @synthesize strokeColor=_strokeColor;
@property(retain, nonatomic) GPUImageFramebuffer *bgImageFramebuffer; // @synthesize bgImageFramebuffer=_bgImageFramebuffer;
@property(nonatomic) _Bool transparentBackground; // @synthesize transparentBackground=_transparentBackground;
- (void).cxx_destruct;
- (void)removeAllTargets;
- (void)setInputFramebufferForTarget:(id)arg1 atIndex:(long long)arg2;
- (void)switchToVertexShader:(id)arg1 fragmentShader:(id)arg2;
- (void)renderToTextureWithVertices:(const float *)arg1 textureCoordinates:(const float *)arg2;
- (void)newFrameReadyAtTime:(CDStruct_1b6d18a9)arg1 atIndex:(long long)arg2;
- (void)setInputFramebuffer:(id)arg1 atIndex:(long long)arg2;
- (id)framebufferAtIndex:(long long)arg1;
- (struct CGSize)outputFrameSize;
- (id)fragmentShaderStringForBorderType:(long long)arg1;
- (void)dealloc;
- (id)init;

@end

