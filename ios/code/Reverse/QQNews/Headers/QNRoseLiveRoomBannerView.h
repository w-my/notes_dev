//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableView.h"

@class NSString, QNPlayerCoverView, QNRoseLiveRoomBannerViewModel, UIView;

@interface QNRoseLiveRoomBannerView : QNThemableView
{
    _Bool _isMiniMoivePlayer;
    QNPlayerCoverView *_videoPlayerCoverImageView;
    id <QNRoseLiveRoomSubControllerDelegate> _delegate;
    CDUnknownBlockType _playVideoBlock;
    UIView *_contentView;
    NSString *_headerUrl;
    long long _type;
    QNRoseLiveRoomBannerViewModel *_viewModel;
}

@property(retain, nonatomic) QNRoseLiveRoomBannerViewModel *viewModel; // @synthesize viewModel=_viewModel;
@property(nonatomic) long long type; // @synthesize type=_type;
@property(copy, nonatomic) NSString *headerUrl; // @synthesize headerUrl=_headerUrl;
@property(retain, nonatomic) UIView *contentView; // @synthesize contentView=_contentView;
@property(copy, nonatomic) CDUnknownBlockType playVideoBlock; // @synthesize playVideoBlock=_playVideoBlock;
@property(nonatomic) __weak id <QNRoseLiveRoomSubControllerDelegate> delegate; // @synthesize delegate=_delegate;
@property(retain, nonatomic) QNPlayerCoverView *videoPlayerCoverImageView; // @synthesize videoPlayerCoverImageView=_videoPlayerCoverImageView;
@property(nonatomic) _Bool isMiniMoivePlayer; // @synthesize isMiniMoivePlayer=_isMiniMoivePlayer;
- (void).cxx_destruct;
- (void)themeChanged:(long long)arg1;
- (id)currentPlayVideoInfo;
- (_Bool)isPlayLiveVideo;
- (void)playCurrentVideo;
- (void)updateNormalHeaderView:(id)arg1;
- (void)showRaceHeaderViewWithAnimation:(_Bool)arg1;
- (void)hideRaceHeaderViewWithAnimation:(_Bool)arg1;
- (void)refreshRaceHeaderView:(id)arg1;
- (void)updateHeaderViewToTop;
- (void)updateTopPosition:(double)arg1 maxOffset:(double)arg2;
- (void)p_switchContentViewForType:(long long)arg1;
- (void)layoutWithViewModel:(id)arg1;
- (_Bool)pointInside:(struct CGPoint)arg1 withEvent:(id)arg2;
- (id)initWithFrame:(struct CGRect)arg1;

@end

