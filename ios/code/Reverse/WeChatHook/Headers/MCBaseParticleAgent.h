//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class ARFrame;

@interface MCBaseParticleAgent : NSObject
{
    _Bool _frontCameraMirror;
    ARFrame *_arframe;
}

+ (double)rotateAngleOfXZ:(double)arg1 Y:(double)arg2;
+ (double)rotateAngleOfX:(double)arg1 Z:(double)arg2;
+ (double)interAngleOfX:(double)arg1 Y:(double)arg2;
@property(nonatomic) __weak ARFrame *arframe; // @synthesize arframe=_arframe;
@property(nonatomic) _Bool frontCameraMirror; // @synthesize frontCameraMirror=_frontCameraMirror;
- (void).cxx_destruct;
- (void)endPan;
- (void)panChangedAtPosition:(union _GLKVector3)arg1;
- (void)panChangedAtScreenPoint:(struct CGPoint)arg1 withFBOSize:(struct CGSize)arg2;
- (void)startPanAtPosition:(union _GLKVector3)arg1;
- (void)startPanAtScreenPoint:(struct CGPoint)arg1 withFBOSize:(struct CGSize)arg2;
- (void)touchAtScreenPoint:(struct CGPoint)arg1 withFBOSize:(struct CGSize)arg2;
- (union _GLKVector3)screenPosToScenePos:(struct CGPoint)arg1 withFBOSize:(struct CGSize)arg2;
- (void)touchAtLocationX:(float)arg1 Y:(float)arg2 Z:(float)arg3;
- (float *)rotationAtIndex:(long long)arg1;
- (unsigned int)blendModeAtIndex:(long long)arg1;
- (float *)tintColorsAtIndex:(long long)arg1;
- (float *)textureCoordsAtIndex:(long long)arg1;
- (float *)vertexCoordsAtIndex:(long long)arg1;
- (long long)numParticleNodeCountAtIndex:(long long)arg1;
- (unsigned int)glTextureAtIndex:(long long)arg1;
- (void)updateParticleAttributes;
- (void)advanceTime:(double)arg1;
- (_Bool)hasTouchElement;
- (void)setAudioEnable:(_Bool)arg1;
- (_Bool)hasAudio;
- (void)clearResource;
- (void)preloadResource;
@property(readonly, nonatomic) long long numParticleSystemCount;
- (void)arFrameDidUpdate:(id)arg1;
- (void)dealloc;
- (id)init;

@end

