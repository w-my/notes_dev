//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNTVKVideoMaskView.h"

@class CAGradientLayer, CSelectButton, QNColorButton, QNPlayer, QNTVKPlayerProgressBar, UIImageView;

@interface QNTVKPlayerProgressControl : QNTVKVideoMaskView
{
    _Bool _liveVideoType;
    CSelectButton *_playBtn;
    CSelectButton *_zoomBtn;
    CSelectButton *_change2SmartViewBtn;
    QNTVKPlayerProgressBar *_progressBar;
    QNColorButton *_mediaFormatBtn;
    UIImageView *_broadcastView;
    id <QNTVKProgressControlDelegate> _delegate;
    id <QNTVKProgressControlRoseLiveDelegate> _roseLiveDelegate;
    unsigned long long _currentPlayType;
    CDUnknownBlockType _formatButtonClick;
    QNPlayer *_player;
    CAGradientLayer *_gradientLayer;
}

@property(retain, nonatomic) CAGradientLayer *gradientLayer; // @synthesize gradientLayer=_gradientLayer;
@property(nonatomic) __weak QNPlayer *player; // @synthesize player=_player;
@property(copy, nonatomic) CDUnknownBlockType formatButtonClick; // @synthesize formatButtonClick=_formatButtonClick;
@property(nonatomic) unsigned long long currentPlayType; // @synthesize currentPlayType=_currentPlayType;
@property(nonatomic) _Bool liveVideoType; // @synthesize liveVideoType=_liveVideoType;
@property(nonatomic) __weak id <QNTVKProgressControlRoseLiveDelegate> roseLiveDelegate; // @synthesize roseLiveDelegate=_roseLiveDelegate;
@property(nonatomic) __weak id <QNTVKProgressControlDelegate> delegate; // @synthesize delegate=_delegate;
@property(retain, nonatomic) UIImageView *broadcastView; // @synthesize broadcastView=_broadcastView;
@property(retain, nonatomic) QNColorButton *mediaFormatBtn; // @synthesize mediaFormatBtn=_mediaFormatBtn;
@property(retain, nonatomic) QNTVKPlayerProgressBar *progressBar; // @synthesize progressBar=_progressBar;
@property(retain, nonatomic) CSelectButton *change2SmartViewBtn; // @synthesize change2SmartViewBtn=_change2SmartViewBtn;
@property(retain, nonatomic) CSelectButton *zoomBtn; // @synthesize zoomBtn=_zoomBtn;
@property(retain, nonatomic) CSelectButton *playBtn; // @synthesize playBtn=_playBtn;
- (void).cxx_destruct;
- (void)p_handleTapGesture;
- (void)clickPlayButton;
- (void)enableClickEventForBuffer:(_Bool)arg1;
- (_Bool)canHide;
- (void)updateProgress:(double)arg1 bufferTime:(double)arg2 duration:(double)arg3;
- (void)layoutSubviews;
- (void)fitRect:(struct CGRect)arg1;
- (void)updatePlayingMediaFormatName:(id)arg1 hasMoreFormats:(_Bool)arg2;
- (void)updateZoomState:(_Bool)arg1;
- (void)updatePlayState:(_Bool)arg1;
- (void)changeToSmartView:(id)arg1;
- (void)mediaFormatBtnClicked:(id)arg1;
- (void)p_zoomBtnDown:(id)arg1;
- (void)playBtnDown:(id)arg1;
- (id)initWithFrame:(struct CGRect)arg1;

@end

