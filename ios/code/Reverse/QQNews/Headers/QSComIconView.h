//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableControl.h"

@class CALayer, QSComWebRoundedRectImageView, UILabel;

@interface QSComIconView : QNThemableControl
{
    QSComWebRoundedRectImageView *_imageView;
    UILabel *_titleLabel;
    CALayer *_maskLayer;
}

@property(retain, nonatomic) CALayer *maskLayer; // @synthesize maskLayer=_maskLayer;
@property(retain, nonatomic) UILabel *titleLabel; // @synthesize titleLabel=_titleLabel;
@property(retain, nonatomic) QSComWebRoundedRectImageView *imageView; // @synthesize imageView=_imageView;
- (void).cxx_destruct;
- (void)highLightIcon:(_Bool)arg1;
- (void)updateWithImageUrl:(id)arg1 deafultImage:(id)arg2 andTitle:(id)arg3;
- (void)updateWithImageUrl:(id)arg1 andTitle:(id)arg2;
- (void)updateHighLightImage:(id)arg1;
- (void)updateWithImage:(id)arg1 andTitle:(id)arg2;
- (void)themeChanged:(long long)arg1;
- (id)initWithFrame:(struct CGRect)arg1;

@end
