//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

#import "TLNPlayerControlViewDelegate.h"
#import "UIGestureRecognizerDelegate.h"

@class AVAssetImageGenerator, AVPlayer, AVPlayerItem, AVPlayerLayer, AVURLAsset, NSString, NSURL, TLNLoadingView, TLNVideoInfo, UIScrollView, UISlider, UIView<TLNPlayerControlViewProtocol>;

@interface TLNPlayerView : UIView <TLNPlayerControlViewDelegate, UIGestureRecognizerDelegate>
{
    _Bool _isPauseByUser;
    _Bool _muted;
    _Bool _isCovered;
    _Bool _isLocalVideo;
    _Bool _isReady;
    id <TLNPlayerViewDelegate> _delegate;
    UIView<TLNPlayerControlViewProtocol> *_controlView;
    unsigned long long _state;
    double _volume;
    AVPlayer *_player;
    AVPlayerItem *_playerItem;
    AVURLAsset *_urlAsset;
    AVAssetImageGenerator *_imageGenerator;
    AVPlayerLayer *_playerLayer;
    id _timeObserve;
    UISlider *_volumeViewSlider;
    long long _seekTime;
    long long _duration;
    NSURL *_videoURL;
    TLNVideoInfo *_videoInfo;
    UIScrollView *_scrollView;
    TLNLoadingView *_loadingView;
}

@property(nonatomic) _Bool isReady; // @synthesize isReady=_isReady;
@property(retain, nonatomic) TLNLoadingView *loadingView; // @synthesize loadingView=_loadingView;
@property(nonatomic) __weak UIScrollView *scrollView; // @synthesize scrollView=_scrollView;
@property(nonatomic) _Bool isLocalVideo; // @synthesize isLocalVideo=_isLocalVideo;
@property(retain, nonatomic) TLNVideoInfo *videoInfo; // @synthesize videoInfo=_videoInfo;
@property(retain, nonatomic) NSURL *videoURL; // @synthesize videoURL=_videoURL;
@property(nonatomic) long long duration; // @synthesize duration=_duration;
@property(nonatomic) long long seekTime; // @synthesize seekTime=_seekTime;
@property(retain, nonatomic) UISlider *volumeViewSlider; // @synthesize volumeViewSlider=_volumeViewSlider;
@property(retain, nonatomic) id timeObserve; // @synthesize timeObserve=_timeObserve;
@property(retain, nonatomic) AVPlayerLayer *playerLayer; // @synthesize playerLayer=_playerLayer;
@property(retain, nonatomic) AVAssetImageGenerator *imageGenerator; // @synthesize imageGenerator=_imageGenerator;
@property(retain, nonatomic) AVURLAsset *urlAsset; // @synthesize urlAsset=_urlAsset;
@property(retain, nonatomic) AVPlayerItem *playerItem; // @synthesize playerItem=_playerItem;
@property(retain, nonatomic) AVPlayer *player; // @synthesize player=_player;
@property(nonatomic) _Bool isCovered; // @synthesize isCovered=_isCovered;
@property(nonatomic) _Bool muted; // @synthesize muted=_muted;
@property(nonatomic) double volume; // @synthesize volume=_volume;
@property(nonatomic) unsigned long long state; // @synthesize state=_state;
@property(readonly, nonatomic) _Bool isPauseByUser; // @synthesize isPauseByUser=_isPauseByUser;
@property(retain, nonatomic) UIView<TLNPlayerControlViewProtocol> *controlView; // @synthesize controlView=_controlView;
@property(nonatomic) __weak id <TLNPlayerViewDelegate> delegate; // @synthesize delegate=_delegate;
- (void).cxx_destruct;
- (void)stopLoadingView;
- (void)showLoadingView;
- (void)tln_scrollViewEnabled:(_Bool)arg1;
- (void)tln_controlView:(id)arg1 progress:(double)arg2;
- (void)tln_controlView:(id)arg1 mute:(_Bool)arg2;
- (void)tln_controlView:(id)arg1 playOrPause:(_Bool)arg2;
- (void)scrollViewEnabled:(_Bool)arg1;
- (_Bool)pointInside:(struct CGPoint)arg1 withEvent:(id)arg2;
- (void)playOrPause;
- (void)doubleTapAction:(id)arg1;
- (void)singleTapAction:(id)arg1;
- (void)resetPlayer;
- (void)hideControlView;
- (void)showControlView;
- (void)moviePlayDidEnd:(id)arg1;
- (void)seekToTime:(long long)arg1;
- (void)cancelPlay;
- (void)pauseByNetwork;
- (void)pause;
- (void)play;
- (void)configureVolume;
- (void)createTimer;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
- (void)loadPlayer;
- (void)layoutSubviews;
- (void)dealloc;
- (id)initWithVideoInfo:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
