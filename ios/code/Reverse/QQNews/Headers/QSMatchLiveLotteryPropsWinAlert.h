//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableView.h"

@class CSimpleImageViewEx, QSLotteryPropsRequestInfo, UIButton, UILabel, UIView;

@interface QSMatchLiveLotteryPropsWinAlert : QNThemableView
{
    id <QSMatchLiveLotteryPropsWinAlertDelegate> _delegate;
    QSLotteryPropsRequestInfo *_requestInfo;
    UIButton *_closeButton;
    CSimpleImageViewEx *_logoView;
    UILabel *_titleLabel;
    UILabel *_descLabel;
    UIView *_line;
    UIButton *_okButton;
}

@property(retain, nonatomic) UIButton *okButton; // @synthesize okButton=_okButton;
@property(retain, nonatomic) UIView *line; // @synthesize line=_line;
@property(retain, nonatomic) UILabel *descLabel; // @synthesize descLabel=_descLabel;
@property(retain, nonatomic) UILabel *titleLabel; // @synthesize titleLabel=_titleLabel;
@property(retain, nonatomic) CSimpleImageViewEx *logoView; // @synthesize logoView=_logoView;
@property(retain, nonatomic) UIButton *closeButton; // @synthesize closeButton=_closeButton;
@property(retain, nonatomic) QSLotteryPropsRequestInfo *requestInfo; // @synthesize requestInfo=_requestInfo;
@property(nonatomic) __weak id <QSMatchLiveLotteryPropsWinAlertDelegate> delegate; // @synthesize delegate=_delegate;
- (void).cxx_destruct;
- (void)okClicked:(id)arg1;
- (void)closeClicked:(id)arg1;
- (void)adjustSubviews;
- (void)setFrame:(struct CGRect)arg1;
- (void)themeChanged:(long long)arg1;
- (id)initWithFrame:(struct CGRect)arg1;

@end
