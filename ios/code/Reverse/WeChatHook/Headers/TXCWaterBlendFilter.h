//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "TXCAlphaBlendFilter.h"

@interface TXCWaterBlendFilter : TXCAlphaBlendFilter
{
    float cropTextureCoordinates[8];
}

- (void)calculateCropTextureCoordinates:(struct CGSize)arg1 canvasSize:(struct CGSize)arg2 rotation:(unsigned long long)arg3;
- (void)renderToTextureWithVertices:(const float *)arg1 textureCoordinates:(const float *)arg2;
- (id)init;

@end

