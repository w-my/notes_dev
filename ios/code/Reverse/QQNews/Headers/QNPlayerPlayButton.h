//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CSelectButton.h"

@class LOTAnimationView;

@interface QNPlayerPlayButton : CSelectButton
{
    LOTAnimationView *_bgView;
    LOTAnimationView *_pauseAnimationView;
}

@property(retain, nonatomic) LOTAnimationView *pauseAnimationView; // @synthesize pauseAnimationView=_pauseAnimationView;
@property(retain, nonatomic) LOTAnimationView *bgView; // @synthesize bgView=_bgView;
- (void).cxx_destruct;
- (id)pauseAnimationJsonMap;
- (void)layoutSubviews;
- (void)setSelected:(_Bool)arg1;
- (void)setSelected:(_Bool)arg1 animationed:(_Bool)arg2;
- (id)initWithFrame:(struct CGRect)arg1;

@end
