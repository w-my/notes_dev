//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "WXVideoPlayerView.h"

#import "FullScreenGestureDelegate.h"
#import "IVideoExt.h"
#import "UIAlertViewDelegate.h"
#import "WCC2CPlayerControlViewDelegate.h"
#import "WCPlayerDownloaderExt.h"

@class CMessageWrap, NSString, WCC2CPlayerControlView, WCPlayerPlayArgs, WCPlayerView, WXFullScreenGestureRecognizer;

@interface WCC2CVideoPlayerView : WXVideoPlayerView <UIAlertViewDelegate, IVideoExt, FullScreenGestureDelegate, WCC2CPlayerControlViewDelegate, WCPlayerDownloaderExt>
{
    _Bool _bPreViewMode;
    _Bool _shouldRestartPlay;
    CMessageWrap *_msgWrap;
    WCPlayerPlayArgs *_playerInfo;
    WCPlayerView *_playerView;
    WCC2CPlayerControlView *_controlView;
    WXFullScreenGestureRecognizer *_fullScreenGestureRecognizer;
}

@property(retain, nonatomic) WXFullScreenGestureRecognizer *fullScreenGestureRecognizer; // @synthesize fullScreenGestureRecognizer=_fullScreenGestureRecognizer;
@property(nonatomic) _Bool shouldRestartPlay; // @synthesize shouldRestartPlay=_shouldRestartPlay;
@property(nonatomic) _Bool bPreViewMode; // @synthesize bPreViewMode=_bPreViewMode;
@property(retain, nonatomic) WCC2CPlayerControlView *controlView; // @synthesize controlView=_controlView;
@property(retain, nonatomic) WCPlayerView *playerView; // @synthesize playerView=_playerView;
@property(retain, nonatomic) WCPlayerPlayArgs *playerInfo; // @synthesize playerInfo=_playerInfo;
@property(retain, nonatomic) CMessageWrap *msgWrap; // @synthesize msgWrap=_msgWrap;
- (void).cxx_destruct;
- (void)OnMsgDownloadVideoCommonFail:(id)arg1 MsgWrap:(id)arg2;
- (void)OnMsgDownloadVideoExpiredFail:(id)arg1 MsgWrap:(id)arg2;
- (void)OnCdnDownloadError:(id)arg1;
- (void)OnCdnDownloadProgress:(id)arg1;
- (void)OnCdnDownloadSuccess:(id)arg1;
- (void)onSightProgressBarHidden;
- (void)onClickPlayAttachVideoBtn;
- (void)onClickDetailButton;
- (void)onCloseVideoPlay;
- (void)onStartPlayIconClick;
- (void)onPlayToEnd;
- (void)onFullScreenDragEnd;
- (void)onFullScreenDragCancel;
- (void)onFullScreenDragBegin;
- (void)onFullScreenSingleTap;
- (void)onFullScreenBackgroundColorAlphaChange:(double)arg1;
- (void)onFullScreenLongPressEnd;
- (void)onFullScreenDragToRect:(struct CGRect)arg1;
- (void)exitVideoPlay;
- (void)onFullScreenClose;
- (void)handleDownloadExpired;
- (void)handleDownloadFail;
- (void)setStatusViewsHidden:(_Bool)arg1;
- (void)setToolViewsHidden:(_Bool)arg1;
- (void)switchToDownloadFirstWithMode:(unsigned long long)arg1;
- (void)startVideoStreamDownload;
- (_Bool)isNeedPlayFromEveryDisplay;
- (void)getReadyForPlay;
- (void)resetViewPosition;
- (unsigned long long)totalTime;
- (void)pause;
- (void)removeFromSuperview;
- (void)stopPlay:(id)arg1;
- (void)stopPlay;
- (_Bool)startPlay;
- (void)setPlayerInfoMode;
- (void)initPlayerView;
- (void)initView;
- (void)dealloc;
- (id)initWithFrame:(struct CGRect)arg1 MsgWrap:(id)arg2 VideoPath:(id)arg3 Soundable:(_Bool)arg4;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

