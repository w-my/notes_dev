//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@class UIButton, UILabel;

@interface MPLandingVideoOversizeTipsView : UIView
{
    UIView *_containerView;
    UILabel *_tipsLabel;
    UIButton *_playBtn;
    CDUnknownBlockType _comfirmHanlder;
}

@property(copy, nonatomic) CDUnknownBlockType comfirmHanlder; // @synthesize comfirmHanlder=_comfirmHanlder;
@property(retain, nonatomic) UIButton *playBtn; // @synthesize playBtn=_playBtn;
@property(retain, nonatomic) UILabel *tipsLabel; // @synthesize tipsLabel=_tipsLabel;
@property(retain, nonatomic) UIView *containerView; // @synthesize containerView=_containerView;
- (void).cxx_destruct;
- (void)onClickPlayBtn;
- (void)layoutSubviews;
- (void)initSubviews;
- (void)setTips:(id)arg1 confirmTips:(id)arg2 comfirmHandler:(CDUnknownBlockType)arg3;
- (id)initWithFrame:(struct CGRect)arg1;

@end
