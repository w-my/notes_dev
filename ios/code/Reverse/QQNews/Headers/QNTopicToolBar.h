//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableView.h"

#import "UIGestureRecognizerDelegate.h"

@class LOTAnimationView, NSString, QNBaseLabel, QNEnlargeHitTestButton, QNListNewsItem, QNReportParam, UIImageView, UILabel, UIView;

@interface QNTopicToolBar : QNThemableView <UIGestureRecognizerDelegate>
{
    _Bool _praiseDisabled;
    _Bool _commentDisabled;
    _Bool _shareDisabled;
    CDUnknownBlockType _onShareBlock;
    CDUnknownBlockType _onCommentBlock;
    CDUnknownBlockType _onPriseBlock;
    CDUnknownBlockType _resendBlock;
    UIView *_praiseAnimationView;
    QNReportParam *_reportParam;
    QNListNewsItem *_listItem;
    LOTAnimationView *_praiseIcon;
    UILabel *_praiseLabel;
    UIImageView *_commentIcon;
    UILabel *_commentLabel;
    UIImageView *_shareIcon;
    UILabel *_shareLabel;
    UILabel *_readCountLabel;
    QNEnlargeHitTestButton *_sendStatusButton;
    QNBaseLabel *_recInfoLabel;
}

@property(nonatomic) _Bool shareDisabled; // @synthesize shareDisabled=_shareDisabled;
@property(nonatomic) _Bool commentDisabled; // @synthesize commentDisabled=_commentDisabled;
@property(nonatomic) _Bool praiseDisabled; // @synthesize praiseDisabled=_praiseDisabled;
@property(retain, nonatomic) QNBaseLabel *recInfoLabel; // @synthesize recInfoLabel=_recInfoLabel;
@property(retain, nonatomic) QNEnlargeHitTestButton *sendStatusButton; // @synthesize sendStatusButton=_sendStatusButton;
@property(retain, nonatomic) UILabel *readCountLabel; // @synthesize readCountLabel=_readCountLabel;
@property(retain, nonatomic) UILabel *shareLabel; // @synthesize shareLabel=_shareLabel;
@property(retain, nonatomic) UIImageView *shareIcon; // @synthesize shareIcon=_shareIcon;
@property(retain, nonatomic) UILabel *commentLabel; // @synthesize commentLabel=_commentLabel;
@property(retain, nonatomic) UIImageView *commentIcon; // @synthesize commentIcon=_commentIcon;
@property(retain, nonatomic) UILabel *praiseLabel; // @synthesize praiseLabel=_praiseLabel;
@property(retain, nonatomic) LOTAnimationView *praiseIcon; // @synthesize praiseIcon=_praiseIcon;
@property(retain, nonatomic) QNListNewsItem *listItem; // @synthesize listItem=_listItem;
@property(retain, nonatomic) QNReportParam *reportParam; // @synthesize reportParam=_reportParam;
@property(nonatomic) __weak UIView *praiseAnimationView; // @synthesize praiseAnimationView=_praiseAnimationView;
@property(copy, nonatomic) CDUnknownBlockType resendBlock; // @synthesize resendBlock=_resendBlock;
@property(copy, nonatomic) CDUnknownBlockType onPriseBlock; // @synthesize onPriseBlock=_onPriseBlock;
@property(copy, nonatomic) CDUnknownBlockType onCommentBlock; // @synthesize onCommentBlock=_onCommentBlock;
@property(copy, nonatomic) CDUnknownBlockType onShareBlock; // @synthesize onShareBlock=_onShareBlock;
- (void).cxx_destruct;
- (void)p_shareSuccessEvent:(id)arg1;
- (void)p_updateShareIconImage;
- (void)p_updateCommentIconImage;
- (void)p_updatePraiseIconChangeColors;
- (void)p_doLikeAnimation;
- (void)p_doLargeHandLikeAnimation;
- (void)p_doLittleHandLikeAnimation;
- (_Bool)p_hasPraisedListItem:(id)arg1;
- (void)p_resend;
- (void)p_share;
- (void)p_realLike:(_Bool)arg1;
- (void)p_like;
- (void)p_viewComment;
- (void)p_handleTapGesture:(id)arg1;
- (_Bool)gestureRecognizerShouldBegin:(id)arg1;
- (id)hitTest:(struct CGPoint)arg1 withEvent:(id)arg2;
- (void)p_refreshPraiseIconProgress:(double)arg1;
- (void)p_reloadSubViews;
- (void)reloadWithListItem:(id)arg1;
- (void)layoutSubviews;
- (void)themeChanged:(long long)arg1;
- (id)initWithFrame:(struct CGRect)arg1 listItem:(id)arg2;
- (id)init;
- (id)p_praiseLottieColorDict:(_Bool)arg1;
- (void)dealloc;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
