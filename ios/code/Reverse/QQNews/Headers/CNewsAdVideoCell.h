//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CNewsAdBaseCell.h"

#import "TADTKVPlayerDelegate.h"

@class CSelectButton, CSimpleImageView, NSString, TADTKVPlayer, UIButton;

@interface CNewsAdVideoCell : CNewsAdBaseCell <TADTKVPlayerDelegate>
{
    _Bool _isNoPicMode;
    _Bool _defaultMuted;
    _Bool _onScreen;
    _Bool _inLandingView;
    CDUnknownBlockType _playerLeaveLandingViewCallback;
    CDUnknownBlockType _playerGotoAdViewCallback;
    CDUnknownBlockType _playerGotoImmerseViewCallback;
    id <TADTKVPlayerDelegate> _playerDelegate;
    UIButton *_bgBtn;
    CSimpleImageView *_videoBgImageView;
    TADTKVPlayer *_player;
    UIButton *_playerContentView;
    CSelectButton *_playButton;
    UIButton *_detailBtn;
}

+ (double)_imageWidth:(id)arg1;
+ (double)_imageRatio:(id)arg1;
+ (double)getCellHeight:(id)arg1 row:(long long)arg2 isNoPicMode:(_Bool)arg3 Style:(unsigned long long)arg4;
+ (double)getCellHeight:(id)arg1 row:(long long)arg2 isNoPicMode:(_Bool)arg3;
@property(retain, nonatomic) UIButton *detailBtn; // @synthesize detailBtn=_detailBtn;
@property(retain, nonatomic) CSelectButton *playButton; // @synthesize playButton=_playButton;
@property(retain, nonatomic) UIButton *playerContentView; // @synthesize playerContentView=_playerContentView;
@property(retain, nonatomic) TADTKVPlayer *player; // @synthesize player=_player;
@property(retain, nonatomic) CSimpleImageView *videoBgImageView; // @synthesize videoBgImageView=_videoBgImageView;
@property(retain, nonatomic) UIButton *bgBtn; // @synthesize bgBtn=_bgBtn;
@property(nonatomic) __weak id <TADTKVPlayerDelegate> playerDelegate; // @synthesize playerDelegate=_playerDelegate;
@property(copy, nonatomic) CDUnknownBlockType playerGotoImmerseViewCallback; // @synthesize playerGotoImmerseViewCallback=_playerGotoImmerseViewCallback;
@property(copy, nonatomic) CDUnknownBlockType playerGotoAdViewCallback; // @synthesize playerGotoAdViewCallback=_playerGotoAdViewCallback;
@property(copy, nonatomic) CDUnknownBlockType playerLeaveLandingViewCallback; // @synthesize playerLeaveLandingViewCallback=_playerLeaveLandingViewCallback;
@property(nonatomic) _Bool inLandingView; // @synthesize inLandingView=_inLandingView;
@property(nonatomic) _Bool onScreen; // @synthesize onScreen=_onScreen;
@property(nonatomic) _Bool defaultMuted; // @synthesize defaultMuted=_defaultMuted;
@property(nonatomic) _Bool isNoPicMode; // @synthesize isNoPicMode=_isNoPicMode;
- (void).cxx_destruct;
- (void)playerDidStop:(id)arg1;
- (void)showPlayer;
- (void)hidePlayer;
- (void)playerDidPlay;
- (void)playerWillPlay;
- (void)playerWillPause;
- (void)gotoLandingView;
- (void)bgBtnClicked;
- (void)playerGotoAdView:(_Bool)arg1;
- (void)setTitleAsRead;
- (void)playerGotoImmerseView;
- (void)playerGotoLandingView;
@property(readonly, nonatomic) _Bool isDragging;
@property(readonly, nonatomic) _Bool paused;
@property(readonly, nonatomic) _Bool playing;
- (void)removeAd;
- (void)pauseAd;
- (void)playAdManually:(_Bool)arg1;
- (void)prepareForPause;
- (void)prepareForPlay:(id)arg1;
- (void)p_setDetailBtnHidden:(_Bool)arg1;
- (void)p_reloadVideoImageView:(id)arg1;
- (void)layoutCell:(id)arg1 row:(long long)arg2 isLastRow:(_Bool)arg3 isNoPicMode:(_Bool)arg4 context:(id)arg5;
- (void)dealloc;
- (void)hideDefaultControl;
- (void)showDefaultControl;
- (void)playButtonDown:(id)arg1;
- (void)detailBtnDown:(id)arg1;
- (void)fullPlayerClickBtnClicked;
- (id)initWithStyle:(long long)arg1 reuseIdentifier:(id)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

