//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableView.h"

@class NSArray, NSString, QNSubscribeButton, UIButton, UIImage;

@interface QNTitleView : QNThemableView
{
    _Bool _isCustomColor;
    _Bool _isSpecialCase;
    NSString *_iconURL;
    UIImage *_iconImage;
    QNSubscribeButton *_attentionBtn;
    UIButton *_titleButton;
    unsigned long long _barStyle;
}

@property(nonatomic) unsigned long long barStyle; // @synthesize barStyle=_barStyle;
@property(retain, nonatomic) UIButton *titleButton; // @synthesize titleButton=_titleButton;
@property(nonatomic) _Bool isSpecialCase; // @synthesize isSpecialCase=_isSpecialCase;
@property(retain, nonatomic) QNSubscribeButton *attentionBtn; // @synthesize attentionBtn=_attentionBtn;
@property(nonatomic) _Bool isCustomColor; // @synthesize isCustomColor=_isCustomColor;
@property(retain, nonatomic) UIImage *iconImage; // @synthesize iconImage=_iconImage;
@property(copy, nonatomic) NSString *iconURL; // @synthesize iconURL=_iconURL;
- (void).cxx_destruct;
@property(copy, nonatomic) NSString *text; // @dynamic text;
- (void)setFont:(id)arg1;
- (void)setFrame:(struct CGRect)arg1;
- (_Bool)subscribeButtonIsHidden;
- (void)hideSubscribeButton;
- (void)showSubscribeButton;
- (void)configSubscribeButton:(id)arg1 cardNode:(id)arg2;
- (void)hideTitleView;
- (void)setTitleColorByNavBarStyle:(unsigned long long)arg1;
- (void)layoutSubviews;
- (id)init;
- (void)configureDetailTitleViewWithTab:(long long)arg1 listItem:(id)arg2 cardNode:(id)arg3;
- (_Bool)p_isValidState:(long long)arg1;
- (id)titleIconURLForState:(long long)arg1;
- (void)setTitleIcon:(id)arg1 forState:(long long)arg2;
- (id)titleTextForState:(long long)arg1;
- (void)setTitleText:(id)arg1 forState:(long long)arg2;
- (void)switchState;
@property(copy, nonatomic) NSArray *avaibleStates;
@property(nonatomic) long long state;

@end
