//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableView.h"

@class QNBarButton, QNBaseLabel, QNSubscribeButton, QNTopicItem, UIView;

@interface QNTopicNavigationView : QNThemableView
{
    _Bool _subBtnHiddenWhenNeeded;
    _Bool _darkStyle;
    _Bool _open;
    long long _currentNavigationStyle;
    CDUnknownBlockType _clickBlock;
    QNSubscribeButton *_subButton;
    QNBaseLabel *_titleLabel;
    QNBarButton *_backButton;
    QNBarButton *_shareButton;
    double _currentNavigationAlpha;
    UIView *_seperatorLine;
    QNTopicItem *_topicItem;
}

@property(retain, nonatomic) QNTopicItem *topicItem; // @synthesize topicItem=_topicItem;
@property(nonatomic) _Bool open; // @synthesize open=_open;
@property(retain, nonatomic) UIView *seperatorLine; // @synthesize seperatorLine=_seperatorLine;
@property(nonatomic) double currentNavigationAlpha; // @synthesize currentNavigationAlpha=_currentNavigationAlpha;
@property(retain, nonatomic) QNBarButton *shareButton; // @synthesize shareButton=_shareButton;
@property(retain, nonatomic) QNBarButton *backButton; // @synthesize backButton=_backButton;
@property(nonatomic) _Bool darkStyle; // @synthesize darkStyle=_darkStyle;
@property(retain, nonatomic) QNBaseLabel *titleLabel; // @synthesize titleLabel=_titleLabel;
@property(nonatomic) _Bool subBtnHiddenWhenNeeded; // @synthesize subBtnHiddenWhenNeeded=_subBtnHiddenWhenNeeded;
@property(retain, nonatomic) QNSubscribeButton *subButton; // @synthesize subButton=_subButton;
@property(copy, nonatomic) CDUnknownBlockType clickBlock; // @synthesize clickBlock=_clickBlock;
@property(nonatomic) long long currentNavigationStyle; // @synthesize currentNavigationStyle=_currentNavigationStyle;
- (void).cxx_destruct;
- (void)p_updateSubViewsStyle;
- (void)themeChanged:(long long)arg1;
- (void)updateNavigationStyle:(long long)arg1 alpha:(double)arg2;
- (void)p_handleClickNavigationButton:(id)arg1;
- (void)p_showTitle;
- (void)setSeperatorLineVisible:(_Bool)arg1;
- (void)showTitleWithSubButtonState:(_Bool)arg1;
- (void)layoutHiddenSubBtnWithTopicInfo:(id)arg1;
- (void)layoutWithTopicInfo:(id)arg1 finishLoad:(_Bool)arg2;
- (void)layoutWithTopicInfo:(id)arg1;
- (id)initWithFrame:(struct CGRect)arg1;

@end
