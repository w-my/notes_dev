//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "GPUImageFilter.h"

@class NSMutableDictionary;

@interface MCGridMultiInputFilter : GPUImageFilter
{
    NSMutableDictionary *_inputBufferParamsMap;
    _Bool _enableInformTargets;
    long long _outputFramebufferIndex;
}

@property(nonatomic) long long outputFramebufferIndex; // @synthesize outputFramebufferIndex=_outputFramebufferIndex;
@property(nonatomic) _Bool enableInformTargets; // @synthesize enableInformTargets=_enableInformTargets;
- (void).cxx_destruct;
- (void)informTargetsAboutNewFrameAtTime:(CDStruct_1b6d18a9)arg1;
- (void)renderToTextureWithVertices:(const float *)arg1 textureCoordinates:(const float *)arg2;
- (void)newFrameReadyAtTime:(CDStruct_1b6d18a9)arg1 atIndex:(long long)arg2;
- (void)setInputFramebuffer:(id)arg1 atIndex:(long long)arg2;
- (void)addTarget:(id)arg1 atTextureLocation:(long long)arg2;
- (void)removeOutputFramebuffer;
- (void)clearAllCachedFrameBuffer;
- (id)getAllCachedFrameBuffer;
- (id)getCachedFrameBufferAtIndex:(long long)arg1;
- (void)dealloc;
- (id)init;

@end

