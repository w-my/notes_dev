//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MyCamGPUFilter.h"

@class GPUImageFramebuffer;

@interface MCSDKWatermarkFilter : MyCamGPUFilter
{
    int alphaTypeUniform;
    _Bool _isGreaterThanIOS10;
    GPUImageFramebuffer *_watermark;
    struct CGSize _canvasSize;
    struct CGRect _imageRect;
}

@property(nonatomic) _Bool isGreaterThanIOS10; // @synthesize isGreaterThanIOS10=_isGreaterThanIOS10;
@property(retain) GPUImageFramebuffer *watermark; // @synthesize watermark=_watermark;
@property(nonatomic) struct CGSize canvasSize; // @synthesize canvasSize=_canvasSize;
@property(nonatomic) struct CGRect imageRect; // @synthesize imageRect=_imageRect;
- (void).cxx_destruct;
- (void)renderToTextureWithVertices:(const float *)arg1 textureCoordinates:(const float *)arg2;
- (id)initWithWatermakImage:(id)arg1 canvasSize:(struct CGSize)arg2 imageRect:(struct CGRect)arg3;

@end

