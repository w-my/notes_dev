//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@class AVPlayer, TVKQLPlayerLayerView;

@interface TVKQLVideoView : UIView
{
    TVKQLPlayerLayerView *playLayerView0;
    TVKQLPlayerLayerView *playLayerView1;
    long long _playerIndex;
    AVPlayer *_layer0Player;
    AVPlayer *_layer1Player;
}

@property(retain, nonatomic) AVPlayer *layer1Player; // @synthesize layer1Player=_layer1Player;
@property(retain, nonatomic) AVPlayer *layer0Player; // @synthesize layer0Player=_layer0Player;
@property long long playerIndex; // @synthesize playerIndex=_playerIndex;
@property(retain, nonatomic) TVKQLPlayerLayerView *playLayerView1; // @synthesize playLayerView1;
@property(retain, nonatomic) TVKQLPlayerLayerView *playLayerView0; // @synthesize playLayerView0;
- (void).cxx_destruct;
- (id)playerLayer;
- (void)switchPlayerViewWithPlayer:(long long)arg1 withPlayer:(id)arg2;
- (void)switchPlayer1WithPlayer:(id)arg1;
- (void)switchPlayer0WithPlayer:(id)arg1;
- (void)resetPlayerOfPlayerView;
- (_Bool)changePlayerWithIndex:(long long)arg1 withSysVersionIs43Later:(_Bool)arg2 withPlayer:(id)arg3 withAirplayEffect:(_Bool)arg4;
- (void)changePlayerviewPlayer:(id)arg1;
- (void)changePlayerViewFitStyle:(_Bool)arg1;
- (void)enterForeground;
- (void)enterBackground;
- (void)setFrame:(struct CGRect)arg1;
- (id)initWithFrame:(struct CGRect)arg1;
- (Class)layerClass;
- (id)getVideoGravity;
- (void)setVideoGravity:(id)arg1;
- (void)resetPlayerViewSizeStyle;

@end

