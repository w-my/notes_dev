//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MyCamGPUFilter.h"

#import "TTMicBaseFaceInputFaceProtocol.h"

@class NSArray, NSString;

@interface TTMicBaseFaceFilter : MyCamGPUFilter <TTMicBaseFaceInputFaceProtocol>
{
    int _expectFace;
    NSArray *_faceFeatures;
}

+ (struct CGImage *)newRedrawCopyCGImage:(struct CGImage *)arg1;
+ (id)resourceOfPath:(id)arg1;
@property(retain, nonatomic) NSArray *faceFeatures; // @synthesize faceFeatures=_faceFeatures;
@property(nonatomic) int expectFace; // @synthesize expectFace=_expectFace;
- (void).cxx_destruct;
- (void)customWithBaseFilterParams:(id)arg1 bundlePath:(id)arg2;
- (void)customWithBaseFilterParam:(id)arg1 bundlePath:(id)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

