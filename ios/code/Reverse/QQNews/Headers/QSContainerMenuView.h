//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNNewsSubMenuView.h"

@class QSGradientView, UIButton;

@interface QSContainerMenuView : QNNewsSubMenuView
{
    UIButton *_backBtn;
    QSGradientView *_leftGradient;
}

@property(retain, nonatomic) QSGradientView *leftGradient; // @synthesize leftGradient=_leftGradient;
@property(retain, nonatomic) UIButton *backBtn; // @synthesize backBtn=_backBtn;
- (void).cxx_destruct;
- (void)themeChanged:(long long)arg1;
- (void)do_reLoadImage;
- (void)clickBackButton:(id)arg1;
- (id)initWithFrame:(struct CGRect)arg1;

// Remaining properties
@property __weak id <QSContainerMenuViewDelegate> delegate; // @dynamic delegate;

@end
