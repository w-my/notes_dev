//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class MetalImageTexture;

@protocol MetalImageInput <NSObject>
- (void)setInputRotation:(unsigned long long)arg1 atIndex:(long long)arg2;
- (void)setInputTexture:(MetalImageTexture *)arg1 atIndex:(long long)arg2;
- (void)newTextureReadyAtTime:(CDStruct_1b6d18a9)arg1 atIndex:(long long)arg2;

@optional
- (void)setCurrentlyReceivingMonochromeInput:(_Bool)arg1;
- (_Bool)wantsMonochromeInput;
- (_Bool)enabled;
- (_Bool)shouldIgnoreUpdatesToThisTarget;
- (void)endProcessing;
- (struct CGSize)maximumOutputSize;
- (void)releaseTextureIndex:(long long)arg1;
- (void)reserveTextureIndex:(long long)arg1;
- (long long)nextAvailableTextureIndex;
@end

