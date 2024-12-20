//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableView.h"

@class QNBarButton, QNBaseLabel, UIView;

@interface QNEventTimeLineNavigationView : QNThemableView
{
    QNBaseLabel *_titleLbl;
    QNBarButton *_backBtn;
    UIView *_bottomLine;
}

+ (double)navigationViewHeight;
@property(retain, nonatomic) UIView *bottomLine; // @synthesize bottomLine=_bottomLine;
@property(retain, nonatomic) QNBarButton *backBtn; // @synthesize backBtn=_backBtn;
@property(retain, nonatomic) QNBaseLabel *titleLbl; // @synthesize titleLbl=_titleLbl;
- (void).cxx_destruct;
- (void)p_layoutSubViews;
- (void)updatebackgroundColorWithAlpha:(double)arg1;
- (void)setNavigationTitleStr:(id)arg1;
- (id)initWithFrame:(struct CGRect)arg1;

@end

