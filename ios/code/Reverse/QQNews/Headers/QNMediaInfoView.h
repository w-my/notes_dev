//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableView.h"

#import "CSimpleImageViewDelegate.h"

@class CSimpleImageViewEx, CSubscribeListItemNode, NSString, QNAttributedLabel, QNBaseLabel, QNEnlargeHitTestButton, QNHeaderFooterFuncView, QNPushRemindAlertView, QNSubscribeButton, UIImageView, UITapGestureRecognizer, UIView;

@interface QNMediaInfoView : QNThemableView <CSimpleImageViewDelegate>
{
    _Bool _isOpenDescLabel;
    _Bool _open;
    _Bool _needAdjustFrame;
    QNSubscribeButton *_focusButton;
    id <QNMediaInfoViewProtocol> _mediaInfoViewDelegate;
    CDUnknownBlockType _openBlock;
    CDUnknownBlockType _changeBlock;
    CDUnknownBlockType _clickBlock;
    QNPushRemindAlertView *_remindAlertView;
    double _headerViewHeight;
    CSimpleImageViewEx *_logoView;
    QNEnlargeHitTestButton *_mediaFlagIcon;
    QNBaseLabel *_nameLabel;
    QNBaseLabel *_descLabel;
    UITapGestureRecognizer *_tapGesture;
    QNBaseLabel *_subCountLabel;
    QNBaseLabel *_subLabel;
    QNBaseLabel *_pubCountLabel;
    QNBaseLabel *_pubLabel;
    QNAttributedLabel *_vipDescLabel;
    CSubscribeListItemNode *_listItemNode;
    UIView *_descBgView;
    NSString *_vipDesc;
    UIImageView *_bgView;
    long long _realLineNumber;
    long long _currentLineNumber;
    UIImageView *_moreImageView;
    UIView *_mainBgView;
    QNHeaderFooterFuncView *_footerFuncView;
    UIView *_animationMaskView;
}

+ (id)titleAttributedString:(id)arg1;
@property(retain, nonatomic) UIView *animationMaskView; // @synthesize animationMaskView=_animationMaskView;
@property(nonatomic) _Bool needAdjustFrame; // @synthesize needAdjustFrame=_needAdjustFrame;
@property(nonatomic) _Bool open; // @synthesize open=_open;
@property(retain, nonatomic) QNHeaderFooterFuncView *footerFuncView; // @synthesize footerFuncView=_footerFuncView;
@property(retain, nonatomic) UIView *mainBgView; // @synthesize mainBgView=_mainBgView;
@property(retain, nonatomic) UIImageView *moreImageView; // @synthesize moreImageView=_moreImageView;
@property(nonatomic) _Bool isOpenDescLabel; // @synthesize isOpenDescLabel=_isOpenDescLabel;
@property(nonatomic) long long currentLineNumber; // @synthesize currentLineNumber=_currentLineNumber;
@property(nonatomic) long long realLineNumber; // @synthesize realLineNumber=_realLineNumber;
@property(retain, nonatomic) UIImageView *bgView; // @synthesize bgView=_bgView;
@property(copy, nonatomic) NSString *vipDesc; // @synthesize vipDesc=_vipDesc;
@property(retain, nonatomic) UIView *descBgView; // @synthesize descBgView=_descBgView;
@property(retain, nonatomic) CSubscribeListItemNode *listItemNode; // @synthesize listItemNode=_listItemNode;
@property(retain, nonatomic) QNAttributedLabel *vipDescLabel; // @synthesize vipDescLabel=_vipDescLabel;
@property(retain, nonatomic) QNBaseLabel *pubLabel; // @synthesize pubLabel=_pubLabel;
@property(retain, nonatomic) QNBaseLabel *pubCountLabel; // @synthesize pubCountLabel=_pubCountLabel;
@property(retain, nonatomic) QNBaseLabel *subLabel; // @synthesize subLabel=_subLabel;
@property(retain, nonatomic) QNBaseLabel *subCountLabel; // @synthesize subCountLabel=_subCountLabel;
@property(retain, nonatomic) UITapGestureRecognizer *tapGesture; // @synthesize tapGesture=_tapGesture;
@property(retain, nonatomic) QNBaseLabel *descLabel; // @synthesize descLabel=_descLabel;
@property(retain, nonatomic) QNBaseLabel *nameLabel; // @synthesize nameLabel=_nameLabel;
@property(retain, nonatomic) QNEnlargeHitTestButton *mediaFlagIcon; // @synthesize mediaFlagIcon=_mediaFlagIcon;
@property(retain, nonatomic) CSimpleImageViewEx *logoView; // @synthesize logoView=_logoView;
@property(nonatomic) double headerViewHeight; // @synthesize headerViewHeight=_headerViewHeight;
@property(retain, nonatomic) QNPushRemindAlertView *remindAlertView; // @synthesize remindAlertView=_remindAlertView;
@property(copy, nonatomic) CDUnknownBlockType clickBlock; // @synthesize clickBlock=_clickBlock;
@property(copy, nonatomic) CDUnknownBlockType changeBlock; // @synthesize changeBlock=_changeBlock;
@property(copy, nonatomic) CDUnknownBlockType openBlock; // @synthesize openBlock=_openBlock;
@property(nonatomic) __weak id <QNMediaInfoViewProtocol> mediaInfoViewDelegate; // @synthesize mediaInfoViewDelegate=_mediaInfoViewDelegate;
@property(retain, nonatomic) QNSubscribeButton *focusButton; // @synthesize focusButton=_focusButton;
- (void).cxx_destruct;
- (void)_onVipIconClick;
- (id)hitTest:(struct CGPoint)arg1 withEvent:(id)arg2;
- (void)setImageCompletedWithImageView:(id)arg1 image:(id)arg2;
- (void)showDetailDescription;
- (void)p_showRemindViewWithShow:(_Bool)arg1 animation:(_Bool)arg2;
- (void)p_boosReportAlertViewShow;
- (void)p_updateRemindViewWithSubNode:(id)arg1 animation:(_Bool)arg2;
- (double)subscribeButtonTopSpacing;
- (void)updateWithContentOffsetY:(double)arg1 threshold:(double)arg2;
- (void)updateWithMediaInfo:(id)arg1;
- (double)logoViewTop;
- (void)themeChanged:(long long)arg1;
- (void)p_setupBackgroundImage;
- (void)layoutWithTagName:(id)arg1;
- (void)tryAdjustTableView;
- (void)tryAdjustTableViewFrame;
- (void)tryLayout;
- (void)layoutWithMediaInfo:(id)arg1;
- (void)setHiddenTitleView:(double)arg1;
- (void)adjustSubviewFrameWithDeltaOffset:(double)arg1 dragToPull:(_Bool)arg2 percentage:(double)arg3;
- (id)initWithFrame:(struct CGRect)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
