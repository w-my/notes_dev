//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableView.h"

@class UILabel, UIView;

@interface QNDetailWidgetSeparator : QNThemableView
{
    UILabel *_label;
    UIView *_line;
}

+ (id)seperatorWithText:(id)arg1;
+ (id)bottomSeparatorWithType:(long long)arg1 bgColor:(id)arg2;
+ (id)topSeparatorMultiWithText:(id)arg1 bgColor:(id)arg2;
+ (id)topSeparatorWithText:(id)arg1 textColor:(id)arg2 bgColor:(id)arg3 bottomLineColor:(id)arg4;
+ (id)topSeparatorWithText:(id)arg1 bgColor:(id)arg2 bottomLineColor:(id)arg3;
@property(retain, nonatomic) UIView *line; // @synthesize line=_line;
@property(retain, nonatomic) UILabel *label; // @synthesize label=_label;
- (void).cxx_destruct;
- (void)themeChanged:(long long)arg1;
- (void)setBackgroundColor:(id)arg1;
- (id)initWithFrame:(struct CGRect)arg1;

@end

