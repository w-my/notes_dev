//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MCBaseFilter.h"

@interface MCVideoFaceCropFilter : MCBaseFilter
{
    float *quadVertexCoord;
    float *quadFragmentCoord;
}

+ (id)complementedForeheadPoints:(float (*)[2])arg1;
- (void)renderToTextureWithVertices:(const float *)arg1 textureCoordinates:(const float *)arg2;
- (void)drawCameraBuffereWithVertices:(const float *)arg1 textureCoordinates:(const float *)arg2;
- (void)dealloc;
- (void)setupEnviroment;
- (id)initWithVertexShaderFromFile:(id)arg1 fragmentShaderFromFile:(id)arg2;

@end

