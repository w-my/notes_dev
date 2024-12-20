//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMUIButton.h"

@class UIColor;

@interface MMVoiceOperateButton : MMUIButton
{
    _Bool _isAnimating;
    UIColor *_normalColor;
    UIColor *_highlightedColor;
}

@property(nonatomic) _Bool isAnimating; // @synthesize isAnimating=_isAnimating;
@property(retain, nonatomic) UIColor *highlightedColor; // @synthesize highlightedColor=_highlightedColor;
@property(retain, nonatomic) UIColor *normalColor; // @synthesize normalColor=_normalColor;
- (void).cxx_destruct;
- (void)layoutButtonWithImageTitleSpace:(double)arg1;
- (void)animateWithScale:(struct CGAffineTransform)arg1;
- (void)animateToHighlighted:(_Bool)arg1;
- (void)setHighlighted:(_Bool)arg1;

@end

