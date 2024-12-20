//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMUIViewController.h"

@class MMBubbleLayer, MMScrollView, MMUILabel, NSMutableArray, UIView, WSFBButton, WSVideoFlowTableViewCell, WSVideoModel;

@interface WSVideoFlowFeedBackViewController : MMUIViewController
{
    UIView *_coverView;
    MMScrollView *_contentFloatView;
    WSFBButton *_mainButton;
    MMUILabel *_tipsTitleLabel;
    MMUILabel *_tipsDescLabel;
    NSMutableArray *_arrReasonButton;
    UIView *_lineView;
    unsigned int _linesOfReasonButton;
    unsigned long long _selectingBitSet;
    MMBubbleLayer *_contentFloatViewMask;
    id <WSVideoFlowFeedBackDelegate> _delegate;
    WSVideoModel *_videoModel;
    WSVideoFlowTableViewCell *_cell;
}

@property(nonatomic) __weak WSVideoFlowTableViewCell *cell; // @synthesize cell=_cell;
@property(retain, nonatomic) WSVideoModel *videoModel; // @synthesize videoModel=_videoModel;
@property(nonatomic) __weak id <WSVideoFlowFeedBackDelegate> delegate; // @synthesize delegate=_delegate;
- (void).cxx_destruct;
- (void)smartSetAnchorPoint:(struct CGPoint)arg1 forView:(id)arg2;
- (void)animateHideWithCompleteBlock:(CDUnknownBlockType)arg1;
- (void)animatShowOnView:(id)arg1 refFrame:(struct CGRect)arg2;
- (void)pop;
- (void)layoutReasonButton;
- (void)internalLayout;
- (double)heightForReasonArea;
- (void)onClickReasonButton:(id)arg1;
- (void)onConfirm:(id)arg1;
- (void)setMainButtonSelect:(_Bool)arg1;
- (id)generateButtonForTitle:(id)arg1;
- (id)generateButtonForTitle:(id)arg1 cornerRadius:(double)arg2 circleRadius:(_Bool)arg3;
- (id)generateReasonButtonForTitle:(id)arg1;
- (void)initReasonButton;
- (void)initTipsLabel;
- (void)initMainButton;
- (void)onTapCancel:(id)arg1;
- (void)initView;
- (void)viewDidLoad;

@end

