//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UINavigationBar.h"

@class CALayer, UIImage;

@interface CustomNavigationBar : UINavigationBar
{
    CALayer *_colorLayer;
    double _layerAlpha;
    UIImage *_emptyImage;
}

+ (double)preferredBlurAlpha;
@property(retain, nonatomic) UIImage *emptyImage; // @synthesize emptyImage=_emptyImage;
@property(nonatomic) double layerAlpha; // @synthesize layerAlpha=_layerAlpha;
@property(retain, nonatomic) CALayer *colorLayer; // @synthesize colorLayer=_colorLayer;
- (void).cxx_destruct;
- (void)layoutSubviews;
- (void)setBarTintColor:(id)arg1;
- (void)setBlurColor:(id)arg1 blurAlpha:(double)arg2 enableBlur:(_Bool)arg3;
- (void)applyBlurSettingsForBarStyle:(unsigned long long)arg1 customBlurAlpha:(double)arg2;
- (void)applyBlurSettingsForBarStyle:(unsigned long long)arg1;
- (struct CGSize)sizeThatFits:(struct CGSize)arg1;
- (id)initWithFrame:(struct CGRect)arg1;
- (id)initWithCoder:(id)arg1;
- (id)init;
- (void)p_init;

@end
