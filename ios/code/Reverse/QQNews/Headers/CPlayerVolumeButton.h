//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CSelectButton.h"

@class LOTAnimationView, NSString;

@interface CPlayerVolumeButton : CSelectButton
{
    LOTAnimationView *_volumeAnimationView;
    LOTAnimationView *_muteStateView;
    LOTAnimationView *_volumeStateView;
    CDUnknownBlockType _clickBlock;
    NSString *_animationName;
}

@property(copy, nonatomic) NSString *animationName; // @synthesize animationName=_animationName;
@property(copy, nonatomic) CDUnknownBlockType clickBlock; // @synthesize clickBlock=_clickBlock;
@property(retain, nonatomic) LOTAnimationView *volumeStateView; // @synthesize volumeStateView=_volumeStateView;
@property(retain, nonatomic) LOTAnimationView *muteStateView; // @synthesize muteStateView=_muteStateView;
@property(retain, nonatomic) LOTAnimationView *volumeAnimationView; // @synthesize volumeAnimationView=_volumeAnimationView;
- (void).cxx_destruct;
- (void)changeLottiColors:(id)arg1;
- (id)volumeAnimationJsonMap;
- (void)setSelected:(_Bool)arg1;
- (void)initSelected:(_Bool)arg1;
- (void)layoutWithSelected:(_Bool)arg1;
- (void)animationWithSelected:(_Bool)arg1;
- (void)layoutSubviews;
- (void)dealloc;
- (id)initWithFrame:(struct CGRect)arg1;
- (id)initWithFrame:(struct CGRect)arg1 animationName:(id)arg2;

@end
