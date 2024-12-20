//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNPlayerControlViewBase.h"

#import "QNTVKPlayerSharePickViewDelegate.h"
#import "QNTVKProgressControlDelegate.h"
#import "UITextFieldDelegate.h"

@class NSString, QNKVOInfo, QNTVKPlayerBottomProgressControl, QNTVKPlayerSharePickView, UIImageView, UIView;

@interface QNPlayerControlViewFullScreenBase : QNPlayerControlViewBase <UITextFieldDelegate, QNTVKPlayerSharePickViewDelegate, QNTVKProgressControlDelegate>
{
    _Bool _isShowedGudie;
    UIView *_videoTitleView;
    QNTVKPlayerBottomProgressControl *_bottomView;
    QNKVOInfo *_progressBarDraggingKVO;
    QNTVKPlayerSharePickView *_shareHorizonPickView;
    UIImageView *_coverWithTwoEyesView;
}

@property(retain, nonatomic) UIImageView *coverWithTwoEyesView; // @synthesize coverWithTwoEyesView=_coverWithTwoEyesView;
@property(nonatomic) _Bool isShowedGudie; // @synthesize isShowedGudie=_isShowedGudie;
@property(retain, nonatomic) QNTVKPlayerSharePickView *shareHorizonPickView; // @synthesize shareHorizonPickView=_shareHorizonPickView;
@property(retain, nonatomic) QNKVOInfo *progressBarDraggingKVO; // @synthesize progressBarDraggingKVO=_progressBarDraggingKVO;
@property(retain, nonatomic) QNTVKPlayerBottomProgressControl *bottomView; // @synthesize bottomView=_bottomView;
@property(retain, nonatomic) UIView *videoTitleView; // @synthesize videoTitleView=_videoTitleView;
- (void).cxx_destruct;
- (void)enterStretchState;
- (void)enterVRTwoEyesState:(_Bool)arg1;
- (void)setTowEyesState:(_Bool)arg1;
- (void)progressControlProgress:(double)arg1;
- (void)progressControlPause;
- (void)progressControlPlay;
- (void)showHorizonShareView;
- (void)onShareAction:(id)arg1;
- (void)didTapSharePickview;
- (void)p_multiStreamClick;
- (void)p_exitFullScreenClick;
- (void)mediaFormatBtnClicked;
- (void)hideControls;
- (void)showControls;
- (_Bool)isTowEyeState;
- (void)updateSubViews;
- (void)updatePlayState:(_Bool)arg1;
- (void)updateProgress:(double)arg1 bufferTime:(double)arg2 duration:(double)arg3;
- (void)willLeave;
- (void)panMoveDistance:(double)arg1 distancY:(double)arg2;
- (_Bool)isSupportVRForCurrentVideo;
- (unsigned long long)getCurrentPlayerType;
- (void)refreshGesture;
- (void)addGesture;
- (void)willShow;
- (void)addGuidView;
- (void)p_onProgressbarDraggingStateChanged:(_Bool)arg1;
- (void)layoutSubviews;
- (void)dealloc;
- (void)playerStateChangeTo:(long long)arg1;
- (void)createSubViews;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

