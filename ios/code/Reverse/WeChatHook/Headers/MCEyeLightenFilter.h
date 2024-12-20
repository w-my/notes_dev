//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MCBaseFilter.h"

@class TTGpuImageTexture;

@interface MCEyeLightenFilter : MCBaseFilter
{
    int filterTextureCoordinateAttribute2;
    char *FaceMeshTriangles;
    int triangleCount;
    char *vertexSamplingCoordinates;
    struct CGSize previousInputTextureSize;
    float srcFaceVertices[1380];
    float srcFaceTexCoords[1380];
    float grayScaleFaceTexCoords[312];
    TTGpuImageTexture *_maskTexture;
    unsigned long long _maxCount;
    double _alphaValue;
}

+ (id)complementedForeheadPoints:(float (*)[2])arg1;
@property(nonatomic) double alphaValue; // @synthesize alphaValue=_alphaValue;
@property(nonatomic) unsigned long long maxCount; // @synthesize maxCount=_maxCount;
@property(retain, nonatomic) TTGpuImageTexture *maskTexture; // @synthesize maskTexture=_maskTexture;
- (void).cxx_destruct;
- (void)renderToTextureWithVertices:(const float *)arg1 textureCoordinates:(const float *)arg2;
- (void)setupMaterialFaceVertex:(id)arg1 imageSize:(struct CGSize)arg2;
- (void)_setWidth:(float)arg1 height:(float)arg2;
- (void)setWidth:(int)arg1 andHeight:(int)arg2;
- (void)setupEnviroment;
- (void)dealloc;
- (id)initWithVertexShaderFromFile:(id)arg1 fragmentShaderFromFile:(id)arg2;
- (id)init;

@end

