//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@class QNAlphaButton, QNBaseLabel;

@interface QNRecommendFollowHeaderView : UIView
{
    CDUnknownBlockType _loginBlock;
    unsigned long long _viewType;
    QNBaseLabel *_titleLabel;
    QNBaseLabel *_descLabel;
    QNAlphaButton *_loginButton;
}

@property(retain, nonatomic) QNAlphaButton *loginButton; // @synthesize loginButton=_loginButton;
@property(retain, nonatomic) QNBaseLabel *descLabel; // @synthesize descLabel=_descLabel;
@property(retain, nonatomic) QNBaseLabel *titleLabel; // @synthesize titleLabel=_titleLabel;
@property(nonatomic) unsigned long long viewType; // @synthesize viewType=_viewType;
@property(copy, nonatomic) CDUnknownBlockType loginBlock; // @synthesize loginBlock=_loginBlock;
- (void).cxx_destruct;
- (void)p_loginButtonClick;
- (void)layoutSubviews;
- (void)updateWithType:(unsigned long long)arg1;
- (void)p_setupSubviews;
- (id)initWithFrame:(struct CGRect)arg1 type:(unsigned long long)arg2;

@end

