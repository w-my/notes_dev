//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMTableViewCell.h"

#import "WSVideoPlayerViewDelegate.h"

@class MMUILabel, NSMutableArray, NSString, UIView, WSStreamPlayerView, WSVideoModel, WSVideoOperateButton, WSVideoSourceView;

@interface WSVideoFlowTableViewCell : MMTableViewCell <WSVideoPlayerViewDelegate>
{
    WSVideoSourceView *_sourceView;
    MMUILabel *_titleLabel;
    MMUILabel *_countLabel;
    WSVideoOperateButton *_goodLookButton;
    WSVideoOperateButton *_shareButton;
    WSVideoOperateButton *_feedBackOpButton;
    NSMutableArray *_arrTagButton;
    UIView *_divLine;
    UIView *_videoMaskView;
    UIView *_videoTopMaskView;
    UIView *_videoBottomMaskView;
    MMUILabel *_infoTipView;
    _Bool _isNeedResumeWXMusic;
    _Bool _needIPhoneXLayout;
    _Bool _bForbidVideoInsert;
    _Bool _isMiniVideoLayout;
    _Bool _needShowNetLayer;
    id <WSVideoFlowTableViewCellDelegate> _delegate;
    WSStreamPlayerView *_videoPlayerView;
    WSVideoModel *_videoModel;
    long long _rowIndex;
}

+ (double)HeightForVideoModel:(id)arg1 maxWidth:(double)arg2;
+ (double)EstimatedCellHeight:(_Bool)arg1;
+ (_Bool)IsOperatePanelDisplay:(id)arg1;
+ (double)HeightForBottomArea:(id)arg1;
+ (double)HeightForMiniVideoPlayerView;
+ (double)HeightForVideoPlayerView;
+ (double)HeightForCountLabel:(id)arg1;
+ (double)OffsetYForVideoPlayerView:(id)arg1;
+ (double)HeightForDescLabel:(id)arg1 maxWidth:(double)arg2;
@property(nonatomic) _Bool needShowNetLayer; // @synthesize needShowNetLayer=_needShowNetLayer;
@property(nonatomic) _Bool isMiniVideoLayout; // @synthesize isMiniVideoLayout=_isMiniVideoLayout;
@property(nonatomic) _Bool bForbidVideoInsert; // @synthesize bForbidVideoInsert=_bForbidVideoInsert;
@property(nonatomic) long long rowIndex; // @synthesize rowIndex=_rowIndex;
@property(nonatomic) _Bool needIPhoneXLayout; // @synthesize needIPhoneXLayout=_needIPhoneXLayout;
@property(retain, nonatomic) WSVideoModel *videoModel; // @synthesize videoModel=_videoModel;
@property(readonly, nonatomic) WSStreamPlayerView *videoPlayerView; // @synthesize videoPlayerView=_videoPlayerView;
@property(nonatomic) __weak id <WSVideoFlowTableViewCellDelegate> delegate; // @synthesize delegate=_delegate;
- (void).cxx_destruct;
- (struct CGPoint)centerForVideoPlayViewForCellCoordinate;
- (void)weakenCell:(_Bool)arg1 animated:(_Bool)arg2;
- (void)resetSurroundMask;
- (void)weakenTopMask:(_Bool)arg1;
- (void)weakenSurrounds:(_Bool)arg1;
- (void)onRecordNetPauseAndPlay;
- (void)onCdnVideoDownLoadFinishForVideoModel:(id)arg1 retCode:(int)arg2 cdnTaskInfo:(id)arg3;
- (_Bool)onPlayerViewUpdateVideoUrl:(id)arg1;
- (void)onRecommendInsertVideo:(id)arg1;
- (_Bool)onVideoHasRecommend:(id)arg1;
- (_Bool)isWSVideoPlayAsFirstVideo:(id)arg1;
- (void)onMaskPlayButtonClick:(id)arg1;
- (void)onDelayToHideControlViews;
- (void)onShowControlViews;
- (_Bool)hasPlayAnyVideo;
- (_Bool)isInteractiveVideo;
- (id)onPlayNextVideo:(_Bool)arg1 currentVideo:(id)arg2;
- (_Bool)canPlayNextVideo:(id)arg1;
- (void)onOperateShare:(id)arg1;
- (void)onDelayPlayVideo;
- (_Bool)onVideoPlayEnd;
- (void)onVideoStateChange:(long long)arg1;
- (void)enableFullScreen:(_Bool)arg1 orientation:(long long)arg2 video:(id)arg3;
- (void)resumePlayerView:(id)arg1;
- (void)removePlayerView;
- (void)layoutDivLine;
- (void)layoutMaskView;
- (void)layoutTag;
- (void)layoutVideoPlayerView;
- (void)layoutOperateButton;
- (void)layoutCountLabel;
- (void)layoutTitle;
- (void)layoutSource;
- (void)layoutViews;
- (void)layoutSubviews;
- (_Bool)isOnDawangEnv;
- (void)onClickGoodLook:(id)arg1;
- (void)onLongPressCell:(id)arg1;
- (_Bool)isForbidDisplayFeedBack;
- (void)onClickFeedBack:(id)arg1;
- (void)onTapSurroundings:(id)arg1;
- (void)onTapMaskView:(id)arg1;
- (void)delayTapTag:(id)arg1;
- (void)onTapTag:(id)arg1;
- (void)onTapTitle:(id)arg1;
- (void)onTapSource:(id)arg1;
- (void)onLike:(id)arg1;
- (void)onShare:(id)arg1;
- (void)playVideoForce:(_Bool)arg1;
- (void)forcePlayVideo;
- (void)playVideo;
- (void)hideInfoTipView;
- (void)showTipInfoToastWithText:(id)arg1;
- (void)showAsPreparePlay;
- (void)updateVideoThumb;
- (void)setVideoInfo:(id)arg1;
- (void)reset;
- (void)initLongPressGesture;
- (void)initDivLine;
- (void)initMaskView;
- (void)initTagButton;
- (id)genTagButton;
- (void)initOperateButton;
- (void)initCountLabel;
- (void)initTitle;
- (void)initSource;
- (void)initView;
- (double)getVideoPlayerHeight;
- (void)dealloc;
- (id)initWithStyle:(long long)arg1 reuseIdentifier:(id)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

