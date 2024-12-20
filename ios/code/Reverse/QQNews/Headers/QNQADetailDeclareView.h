//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableView.h"

@class QNBaseLabel, UIButton;

@interface QNQADetailDeclareView : QNThemableView
{
    _Bool _selected;
    _Bool _isPress;
    CDUnknownBlockType _declareBlock;
    UIButton *_declareButton;
    QNBaseLabel *_countLabel;
    unsigned long long _viewType;
}

@property(nonatomic) _Bool isPress; // @synthesize isPress=_isPress;
@property(nonatomic) unsigned long long viewType; // @synthesize viewType=_viewType;
@property(retain, nonatomic) QNBaseLabel *countLabel; // @synthesize countLabel=_countLabel;
@property(retain, nonatomic) UIButton *declareButton; // @synthesize declareButton=_declareButton;
@property(nonatomic) _Bool selected; // @synthesize selected=_selected;
@property(copy, nonatomic) CDUnknownBlockType declareBlock; // @synthesize declareBlock=_declareBlock;
- (void).cxx_destruct;
- (void)setBackgroundColor:(id)arg1;
- (void)p_doPlus1Animation;
- (void)p_doDislikeAnimation;
- (void)p_doLikeAnimation;
- (void)p_disDeclareUnSelectesButton;
- (void)p_disDeclareSelectesButton;
- (void)p_declareSelectesButton;
- (void)p_dealWithQADetailNOTDeclare;
- (void)p_dealWithQADetailDeclare;
- (void)didClickDeclareButton;
- (void)updateViewsWithCount:(long long)arg1 selected:(_Bool)arg2 isPress:(_Bool)arg3;
- (void)layoutSubviews;
- (id)initWithFrame:(struct CGRect)arg1 viewType:(unsigned long long)arg2;

@end

