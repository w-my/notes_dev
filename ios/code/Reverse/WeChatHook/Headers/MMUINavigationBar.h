//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UINavigationBar.h"

@class UIView;

@interface MMUINavigationBar : UINavigationBar
{
    UIView *_effectSubview;
}

@property(retain, nonatomic) UIView *effectSubview; // @synthesize effectSubview=_effectSubview;
- (void).cxx_destruct;
- (id)hitTest:(struct CGPoint)arg1 withEvent:(id)arg2;
- (void)setAlpha:(double)arg1;
- (void)setBarStyle:(long long)arg1;
- (void)setTranslucent:(_Bool)arg1;
- (id)findBlurEffectView:(id)arg1;
- (id)findHiddenView:(id)arg1;
- (void)adjustShadowView;
- (void)layoutSubviews;

@end

