//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class CPParticleEmitter, NSArray, NSLock, NSMutableArray;

@interface CPParticleEmitterManager : NSObject
{
    NSArray *constEmitterArray;
    NSMutableArray *emitterArray;
    NSLock *emitterArrayLock;
    NSMutableArray *activeEmitterArray;
    NSMutableArray *unActiveEmitterArray;
    unsigned long long *emitterArrayLength;
    CPParticleEmitter *originEmitter;
    NSArray *pexArray;
    long long currentPexIndex;
}

+ (id)topMostController;
+ (id)sharedManager;
- (void).cxx_destruct;
- (void)handleGesture:(id)arg1;
- (void)cleanEmitters;
- (unsigned long long)emitterCount;
- (void)removeUnactiveEmitter;
- (void)updateActiveArray;
- (id)emitter:(unsigned long long)arg1;
- (void)update:(int)arg1 withPosition:(struct CGPoint)arg2;
- (void)updateActiveEmitter;
- (_Bool)activeEmitterAtPosition:(struct CGPoint)arg1;
- (_Bool)setupEmitter:(id)arg1;
- (_Bool)setupBasicEmitterWithFile:(id)arg1;
- (id)init;

@end

