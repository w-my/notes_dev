//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "NSCopying.h"

@class GLKTextureInfo;

@interface CPParticleEmitter : NSObject <NSCopying>
{
    int particleIndex;
    CDStruct_b8b6eb9d *particles;
    struct {
        CDStruct_8e5b4df2 _field1;
        CDStruct_8e5b4df2 _field2;
        CDStruct_8e5b4df2 _field3;
        CDStruct_8e5b4df2 _field4;
    } *quads;
    unsigned short *indices;
    float scaleParticle;
    float audioColorDelta;
    float rotateParticle;
    _Bool _opacityModifyRGB;
    _Bool _active;
    int _emitterType;
    float _angle;
    float _angleVariance;
    float _speed;
    float _speedVariance;
    float _radialAcceleration;
    float _tangentialAcceleration;
    float _radialAccelVariance;
    float _tangentialAccelVariance;
    float _particleLifespan;
    float _particleLifespanVariance;
    float _startParticleSize;
    float _startParticleSizeVariance;
    float _finishParticleSize;
    float _finishParticleSizeVariance;
    unsigned int _maxParticles;
    int _particleCount;
    float _emissionRate;
    float _emitCounter;
    float _elapsedTime;
    float _duration;
    float _rotationStart;
    float _rotationStartVariance;
    float _rotationEnd;
    float _rotationEndVariance;
    int _blendFuncSource;
    int _blendFuncDestination;
    float _maxRadius;
    float _maxRadiusVariance;
    float _radiusSpeed;
    float _minRadius;
    float _minRadiusVariance;
    float _rotatePerSecond;
    float _rotatePerSecondVariance;
    float _scalePos;
    float _timeSpeed;
    GLKTextureInfo *_texture;
    union _GLKVector2 _sourcePosition;
    union _GLKVector2 _sourcePositionVariance;
    union _GLKVector2 _gravity;
    float *_particleVertices;
    float *_particleTextureCoordinates;
    float *_particleColors;
    unsigned short *_particleIndices;
    float *_particlePointsVertice;
    float *_particlePointsSize;
    double _startTime;
    union _GLKVector4 _startColor;
    union _GLKVector4 _startColorVariance;
    union _GLKVector4 _finishColor;
    union _GLKVector4 _finishColorVariance;
}

@property(nonatomic) double startTime; // @synthesize startTime=_startTime;
@property(readonly, nonatomic) float *particlePointsSize; // @synthesize particlePointsSize=_particlePointsSize;
@property(readonly, nonatomic) float *particlePointsVertice; // @synthesize particlePointsVertice=_particlePointsVertice;
@property(readonly, nonatomic) unsigned short *particleIndices; // @synthesize particleIndices=_particleIndices;
@property(readonly, nonatomic) float *particleColors; // @synthesize particleColors=_particleColors;
@property(readonly, nonatomic) float *particleTextureCoordinates; // @synthesize particleTextureCoordinates=_particleTextureCoordinates;
@property(readonly, nonatomic) float *particleVertices; // @synthesize particleVertices=_particleVertices;
@property(nonatomic) float timeSpeed; // @synthesize timeSpeed=_timeSpeed;
@property(nonatomic) float scalePos; // @synthesize scalePos=_scalePos;
@property(nonatomic) _Bool active; // @synthesize active=_active;
@property(nonatomic) float rotatePerSecondVariance; // @synthesize rotatePerSecondVariance=_rotatePerSecondVariance;
@property(nonatomic) float rotatePerSecond; // @synthesize rotatePerSecond=_rotatePerSecond;
@property(nonatomic) float minRadiusVariance; // @synthesize minRadiusVariance=_minRadiusVariance;
@property(nonatomic) float minRadius; // @synthesize minRadius=_minRadius;
@property(nonatomic) float radiusSpeed; // @synthesize radiusSpeed=_radiusSpeed;
@property(nonatomic) float maxRadiusVariance; // @synthesize maxRadiusVariance=_maxRadiusVariance;
@property(nonatomic) float maxRadius; // @synthesize maxRadius=_maxRadius;
@property(nonatomic) _Bool opacityModifyRGB; // @synthesize opacityModifyRGB=_opacityModifyRGB;
@property(nonatomic) int blendFuncDestination; // @synthesize blendFuncDestination=_blendFuncDestination;
@property(nonatomic) int blendFuncSource; // @synthesize blendFuncSource=_blendFuncSource;
@property(nonatomic) float rotationEndVariance; // @synthesize rotationEndVariance=_rotationEndVariance;
@property(nonatomic) float rotationEnd; // @synthesize rotationEnd=_rotationEnd;
@property(nonatomic) float rotationStartVariance; // @synthesize rotationStartVariance=_rotationStartVariance;
@property(nonatomic) float rotationStart; // @synthesize rotationStart=_rotationStart;
@property(nonatomic) float duration; // @synthesize duration=_duration;
@property(nonatomic) float elapsedTime; // @synthesize elapsedTime=_elapsedTime;
@property(nonatomic) float emitCounter; // @synthesize emitCounter=_emitCounter;
@property(nonatomic) float emissionRate; // @synthesize emissionRate=_emissionRate;
@property(nonatomic) int particleCount; // @synthesize particleCount=_particleCount;
@property(nonatomic) unsigned int maxParticles; // @synthesize maxParticles=_maxParticles;
@property(nonatomic) float finishParticleSizeVariance; // @synthesize finishParticleSizeVariance=_finishParticleSizeVariance;
@property(nonatomic) float finishParticleSize; // @synthesize finishParticleSize=_finishParticleSize;
@property(nonatomic) float startParticleSizeVariance; // @synthesize startParticleSizeVariance=_startParticleSizeVariance;
@property(nonatomic) float startParticleSize; // @synthesize startParticleSize=_startParticleSize;
@property(nonatomic) union _GLKVector4 finishColorVariance; // @synthesize finishColorVariance=_finishColorVariance;
@property(nonatomic) union _GLKVector4 finishColor; // @synthesize finishColor=_finishColor;
@property(nonatomic) union _GLKVector4 startColorVariance; // @synthesize startColorVariance=_startColorVariance;
@property(nonatomic) union _GLKVector4 startColor; // @synthesize startColor=_startColor;
@property(nonatomic) float particleLifespanVariance; // @synthesize particleLifespanVariance=_particleLifespanVariance;
@property(nonatomic) float particleLifespan; // @synthesize particleLifespan=_particleLifespan;
@property(nonatomic) union _GLKVector2 gravity; // @synthesize gravity=_gravity;
@property(nonatomic) float tangentialAccelVariance; // @synthesize tangentialAccelVariance=_tangentialAccelVariance;
@property(nonatomic) float radialAccelVariance; // @synthesize radialAccelVariance=_radialAccelVariance;
@property(nonatomic) float tangentialAcceleration; // @synthesize tangentialAcceleration=_tangentialAcceleration;
@property(nonatomic) float radialAcceleration; // @synthesize radialAcceleration=_radialAcceleration;
@property(nonatomic) float speedVariance; // @synthesize speedVariance=_speedVariance;
@property(nonatomic) float speed; // @synthesize speed=_speed;
@property(nonatomic) float angleVariance; // @synthesize angleVariance=_angleVariance;
@property(nonatomic) float angle; // @synthesize angle=_angle;
@property(nonatomic) union _GLKVector2 sourcePositionVariance; // @synthesize sourcePositionVariance=_sourcePositionVariance;
@property(nonatomic) union _GLKVector2 sourcePosition; // @synthesize sourcePosition=_sourcePosition;
@property(retain, nonatomic) GLKTextureInfo *texture; // @synthesize texture=_texture;
@property(nonatomic) int emitterType; // @synthesize emitterType=_emitterType;
- (void).cxx_destruct;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (_Bool)totalFinished;
- (_Bool)u_opacityModifyRGB;
@property(readonly, nonatomic) int particleBlendFuncDestination;
@property(readonly, nonatomic) int particleBlendFuncSource;
- (CDStruct_b8b6eb9d)particleAtIndex:(unsigned long long)arg1;
- (int)activeParticleCount;
- (void)setupArrays;
- (void)parseParticleConfig:(id)arg1;
- (void)initParticle:(CDStruct_b8b6eb9d *)arg1;
- (_Bool)addParticle;
- (void)changeParticleColor:(float)arg1;
- (void)rotateParticle:(float)arg1;
- (void)scaleParticle:(float)arg1;
- (void)reset;
- (void)stopParticleEmitter;
- (void)updateWithDelta:(float)arg1;
- (void)updateWithCurrentTime:(double)arg1;
- (id)initParticleEmitterWithFile:(id)arg1;
- (void)dealloc;

@end
