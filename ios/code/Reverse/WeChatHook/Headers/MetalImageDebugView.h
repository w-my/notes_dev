//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIImageView.h"

#import "MetalImageInput.h"

@class MetalImageTexture, NSString;

@interface MetalImageDebugView : UIImageView <MetalImageInput>
{
    MetalImageTexture *firstInputTexture;
    unsigned long long inputRotationMode;
}

- (void).cxx_destruct;
- (void)newTextureReadyAtTime:(CDStruct_1b6d18a9)arg1 atIndex:(long long)arg2;
- (void)setInputTexture:(id)arg1 atIndex:(long long)arg2;
- (void)setInputRotation:(unsigned long long)arg1 atIndex:(long long)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

