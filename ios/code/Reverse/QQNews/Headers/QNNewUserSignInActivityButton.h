//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableButton.h"

@class CAGradientLayer, CAShapeLayer;

@interface QNNewUserSignInActivityButton : QNThemableButton
{
    CAShapeLayer *_maskLayer;
    CAGradientLayer *_gradientLayer;
}

@property(nonatomic) __weak CAGradientLayer *gradientLayer; // @synthesize gradientLayer=_gradientLayer;
@property(nonatomic) __weak CAShapeLayer *maskLayer; // @synthesize maskLayer=_maskLayer;
- (void).cxx_destruct;
- (void)layoutSubviews;
- (id)initWithFrame:(struct CGRect)arg1;

@end

