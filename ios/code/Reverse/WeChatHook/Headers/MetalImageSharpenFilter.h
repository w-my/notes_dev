//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MetalImageFilter.h"

@interface MetalImageSharpenFilter : MetalImageFilter
{
    float _sharpness;
    id <MTLBuffer> _buffer;
}

@property(retain, nonatomic) id <MTLBuffer> buffer; // @synthesize buffer=_buffer;
@property(nonatomic) float sharpness; // @synthesize sharpness=_sharpness;
- (void).cxx_destruct;
- (void)assembleRenderEncoder:(id)arg1;
- (void)renderToTextureWithVertices:(const struct MTLFloat4 *)arg1 textureCoordinates:(const struct MTLFloat2 *)arg2;
- (id)init;

@end

