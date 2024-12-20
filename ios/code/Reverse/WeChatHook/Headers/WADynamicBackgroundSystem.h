//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "WADynamicBackgroundGLObject.h"

@class DynamicBackgroundSystemConfig, NSMutableArray;

@interface WADynamicBackgroundSystem : WADynamicBackgroundGLObject
{
    unsigned int colorStep;
    float colorRatio;
    unsigned int _framePerSecond;
    DynamicBackgroundSystemConfig *_config;
    NSMutableArray *_activeParticles;
    double _backgroundDuration;
    id <DynamicBackgroundSystemDelegate> _delegate;
}

+ (union _GLKVector4)getVector4ColorFromHex:(int)arg1 alpha:(double)arg2;
+ (id)getDefaultDynamicSystemConfigForWidth:(double)arg1 height:(double)arg2;
@property(nonatomic) __weak id <DynamicBackgroundSystemDelegate> delegate; // @synthesize delegate=_delegate;
@property(nonatomic) double backgroundDuration; // @synthesize backgroundDuration=_backgroundDuration;
@property(nonatomic) unsigned int framePerSecond; // @synthesize framePerSecond=_framePerSecond;
@property(retain, nonatomic) NSMutableArray *activeParticles; // @synthesize activeParticles=_activeParticles;
@property(retain, nonatomic) DynamicBackgroundSystemConfig *config; // @synthesize config=_config;
- (void).cxx_destruct;
- (union _GLKVector3)randInBox:(union _GLKVector3)arg1 center:(union _GLKVector3)arg2;
- (double)uniform2NormalDistribution;
- (double)getNumberInNormalDistributionWithMean:(double)arg1 stdDev:(double)arg2;
- (union _GLKVector3)randVector3:(union _GLKVector3)arg1 end:(union _GLKVector3)arg2;
- (float)randFloat:(float)arg1 end:(float)arg2;
- (void)draw:(id)arg1;
- (union _GLKVector4)mixColorWithA:(union _GLKVector4)arg1 b:(union _GLKVector4)arg2 portion:(double)arg3;
- (union _GLKVector4)getBGColorFromStartConfig:(id)arg1 endConfig:(id)arg2 bgIndex:(unsigned int)arg3 portion:(double)arg4;
- (union _GLKVector4)getColorFromStartConfig:(id)arg1 endConfig:(id)arg2 index:(unsigned int)arg3 portion:(double)arg4;
- (void)update:(double)arg1;
- (void)resetParticle:(id)arg1;
- (void)newParticle;
- (void)fillParticles;
- (id)initWithGLContext:(id)arg1 config:(id)arg2;

@end

