//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MCBaseFilter.h"

@interface MCFaceSkinBalanceFilter : MCBaseFilter
{
    char *vertexSamplingCoordinates;
    _Bool _needBalanceSkin;
    struct GPUVector3 _modelRGB;
    struct GPUVector3 _modelRGB2;
    struct GPUVector3 _userSkinRGB;
    struct GPUVector3 _diffSkinRGB;
    struct CGSize _pixelBufferSize;
}

@property(nonatomic) _Bool needBalanceSkin; // @synthesize needBalanceSkin=_needBalanceSkin;
@property(nonatomic) struct GPUVector3 diffSkinRGB; // @synthesize diffSkinRGB=_diffSkinRGB;
@property(nonatomic) struct GPUVector3 userSkinRGB; // @synthesize userSkinRGB=_userSkinRGB;
@property(nonatomic) struct GPUVector3 modelRGB2; // @synthesize modelRGB2=_modelRGB2;
@property(nonatomic) struct GPUVector3 modelRGB; // @synthesize modelRGB=_modelRGB;
@property(nonatomic) struct CGSize pixelBufferSize; // @synthesize pixelBufferSize=_pixelBufferSize;
- (void)renderToTextureWithVertices:(const float *)arg1 textureCoordinates:(const float *)arg2;
- (void)setSkinColor:(struct GPUVector3)arg1 needBalanceSkin:(_Bool)arg2;
- (void)setupEnviroment;
- (void)dealloc;
- (id)init;

@end

