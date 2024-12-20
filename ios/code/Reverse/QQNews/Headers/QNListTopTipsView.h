//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableView.h"

@class NSNumber, QNBaseLabel, QNListTopTipsViewContext, UIButton, UIImageView, UIView;

@interface QNListTopTipsView : QNThemableView
{
    UIView *_contentBackgroundView;
    UIButton *_backgroundButton;
    QNBaseLabel *_contentLabel;
    UIButton *_actionButton;
    QNListTopTipsViewContext *_context;
    long long _timeVersion;
    long long _type;
    UIImageView *_pushArrowImageView;
    _Bool _isShowing;
    NSNumber *_preferredBottomHeight;
    CDUnknownBlockType _clickBlock;
    UIImageView *_arrowDownImageView;
}

@property(retain, nonatomic) UIImageView *arrowDownImageView; // @synthesize arrowDownImageView=_arrowDownImageView;
@property(copy, nonatomic) CDUnknownBlockType clickBlock; // @synthesize clickBlock=_clickBlock;
@property(nonatomic) _Bool isShowing; // @synthesize isShowing=_isShowing;
@property(retain, nonatomic) NSNumber *preferredBottomHeight; // @synthesize preferredBottomHeight=_preferredBottomHeight;
- (void).cxx_destruct;
- (void)themeChanged:(long long)arg1;
- (void)p_notifyTipShow;
- (void)_remoteConfigDidLoadNotification:(id)arg1;
- (_Bool)pointInside:(struct CGPoint)arg1 withEvent:(id)arg2;
- (void)dismissBottomTipsView;
- (void)p_backgroundClicked:(id)arg1;
- (void)p_bottomBlueBtnClicked:(id)arg1;
- (void)p_buttonClicked:(id)arg1;
- (void)dismissTopTipsAnimated:(_Bool)arg1;
- (_Bool)showBottomTipsWithContext:(id)arg1;
- (_Bool)showTopTipsWithContext:(id)arg1;
- (void)dealloc;
- (void)p_clickAction;
- (id)initWithFrame:(struct CGRect)arg1;
- (_Bool)showBottomTopTipsWithContext:(id)arg1;
- (id)initWithType:(long long)arg1;
- (id)init;

@end

