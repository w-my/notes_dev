//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "TVKSelfPlayerMTLRenderer.h"

@class MTLTextureDescriptor;

@interface TVKSelfPlayerMTLI420Renderer : TVKSelfPlayerMTLRenderer
{
    id <MTLTexture> _yTexture;
    id <MTLTexture> _uTexture;
    id <MTLTexture> _vTexture;
    MTLTextureDescriptor *_descriptor;
    MTLTextureDescriptor *_chromaDescriptor;
    int _width;
    int _height;
    int _chromaWidth;
    int _chromaHeight;
}

- (void).cxx_destruct;
- (void)onFinshed;
- (void)uploadTexturesToRenderEncoder:(id)arg1;
- (_Bool)setupTexturesForFrame:(id)arg1;
- (id)fragmentFunctionSourceName;
- (id)vertexFunctionSourceName;
- (id)shaderSource;
- (_Bool)addRenderingDestination:(id)arg1;
- (void)dealloc;
- (id)init;

@end
