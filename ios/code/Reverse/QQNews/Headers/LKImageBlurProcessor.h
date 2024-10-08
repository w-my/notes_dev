//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "LKImageProcessor.h"

@class UIColor;

@interface LKImageBlurProcessor : LKImageProcessor
{
    double _blurRadius;
    UIColor *_blurTintColor;
}

@property(retain, nonatomic) UIColor *blurTintColor; // @synthesize blurTintColor=_blurTintColor;
@property(nonatomic) double blurRadius; // @synthesize blurRadius=_blurRadius;
- (void).cxx_destruct;
- (id)imageByApplyingBlurToImage:(id)arg1 withRadius:(double)arg2 tintColor:(id)arg3 saturationDeltaFactor:(double)arg4 maskImage:(id)arg5;
- (void)process:(id)arg1 request:(id)arg2 complete:(CDUnknownBlockType)arg3;

@end

