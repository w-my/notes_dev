//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableView.h"

@class CSimpleImageView, QNAudioBadgeView, QNAudioPlayWaveView, QNAudioProgressView, UIButton, UILabel;

@interface QNAudioBannerItemView : QNThemableView
{
    UIButton *_bgBtn;
    CSimpleImageView *_iconView;
    UILabel *_textLabel;
    long long _bannerType;
    QNAudioBadgeView *_badgeView;
    QNAudioProgressView *_progressView;
    QNAudioPlayWaveView *_playWaveView;
}

@property(retain, nonatomic) QNAudioPlayWaveView *playWaveView; // @synthesize playWaveView=_playWaveView;
@property(retain, nonatomic) QNAudioProgressView *progressView; // @synthesize progressView=_progressView;
@property(retain, nonatomic) QNAudioBadgeView *badgeView; // @synthesize badgeView=_badgeView;
@property(nonatomic) long long bannerType; // @synthesize bannerType=_bannerType;
@property(retain, nonatomic) UILabel *textLabel; // @synthesize textLabel=_textLabel;
@property(retain, nonatomic) CSimpleImageView *iconView; // @synthesize iconView=_iconView;
@property(retain, nonatomic) UIButton *bgBtn; // @synthesize bgBtn=_bgBtn;
- (void).cxx_destruct;
- (void)playListChanged:(id)arg1;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
- (id)imageWithColor:(id)arg1;
- (void)themeChanged:(long long)arg1;
- (void)pauseWave;
- (void)playWave;
- (void)showDownloadPauseBtn:(_Bool)arg1;
- (void)showPlayingDownloadListWave:(_Bool)arg1;
- (void)setBtnshouldShowProgress:(_Bool)arg1;
- (void)setBtnDisabled:(_Bool)arg1;
- (void)updateAutoPlayBtn:(_Bool)arg1;
- (void)updateBadgeValue:(long long)arg1;
- (void)initViewForPlaySetting;
- (void)initViewForDownloadNew;
- (void)initViewForDownloadManagement;
- (void)_resetIconViewImageWithState;
- (void)_resetIconViewImage;
- (void)initViews;
- (void)dealloc;
- (id)initWithFrame:(struct CGRect)arg1 andType:(long long)arg2;

@end

