//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableView.h"

#import "QNDetailContentElementProtocol.h"

@class CALayer, NSString, QNAdIcon, QNBarButton, QNCommentTitleView, QNDetailContentContainer, QNExclusiveCoverHeaderView, UIImageView, UIView;

@interface QNDetailHeaderView : QNThemableView <QNDetailContentElementProtocol>
{
    _Bool _showAdIcon;
    _Bool _isFromSensitiveNews;
    QNDetailContentContainer *_contentContainer;
    long long _type;
    CDUnknownBlockType _onBackBlock;
    CDUnknownBlockType _onActionBlock;
    CDUnknownBlockType _subNodeButtonBlock;
    unsigned long long _from;
    QNCommentTitleView *_commentTitle;
    QNExclusiveCoverHeaderView *_exclusiveCoverHeaderView;
    UIImageView *_bgImageView;
    UIView *_imageCoverView;
    QNBarButton *_backButton;
    QNBarButton *_actionButton;
    CALayer *_grandientLayer;
    UIView *_bgView;
    UIView *_blackView;
    QNAdIcon *_adIcon;
}

@property(retain, nonatomic) QNAdIcon *adIcon; // @synthesize adIcon=_adIcon;
@property(retain, nonatomic) UIView *blackView; // @synthesize blackView=_blackView;
@property(retain, nonatomic) UIView *bgView; // @synthesize bgView=_bgView;
@property(retain, nonatomic) CALayer *grandientLayer; // @synthesize grandientLayer=_grandientLayer;
@property(retain, nonatomic) QNBarButton *actionButton; // @synthesize actionButton=_actionButton;
@property(retain, nonatomic) QNBarButton *backButton; // @synthesize backButton=_backButton;
@property(retain, nonatomic) UIView *imageCoverView; // @synthesize imageCoverView=_imageCoverView;
@property(retain, nonatomic) UIImageView *bgImageView; // @synthesize bgImageView=_bgImageView;
@property(retain, nonatomic) QNExclusiveCoverHeaderView *exclusiveCoverHeaderView; // @synthesize exclusiveCoverHeaderView=_exclusiveCoverHeaderView;
@property(retain, nonatomic) QNCommentTitleView *commentTitle; // @synthesize commentTitle=_commentTitle;
@property(nonatomic) _Bool isFromSensitiveNews; // @synthesize isFromSensitiveNews=_isFromSensitiveNews;
@property(nonatomic) unsigned long long from; // @synthesize from=_from;
@property(nonatomic) _Bool showAdIcon; // @synthesize showAdIcon=_showAdIcon;
@property(copy, nonatomic) CDUnknownBlockType subNodeButtonBlock; // @synthesize subNodeButtonBlock=_subNodeButtonBlock;
@property(copy, nonatomic) CDUnknownBlockType onActionBlock; // @synthesize onActionBlock=_onActionBlock;
@property(copy, nonatomic) CDUnknownBlockType onBackBlock; // @synthesize onBackBlock=_onBackBlock;
@property(nonatomic) long long type; // @synthesize type=_type;
@property(nonatomic) __weak QNDetailContentContainer *contentContainer; // @synthesize contentContainer=_contentContainer;
- (void).cxx_destruct;
- (void)themeChanged:(long long)arg1;
- (double)heightOfElementView;
- (void)p_onAction;
- (void)p_onBack;
- (double)showNavigationBarThreshold;
- (void)showCustomBarButtons:(_Bool)arg1;
- (void)updateCommonTitleSubButton;
- (void)updateWithContentOffsetY:(double)arg1 threshold:(double)arg2;
- (void)layoutWithListItem:(id)arg1 cardNode:(id)arg2 topPicUrl:(id)arg3;
- (id)initWithFrame:(struct CGRect)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

