//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QSSportsMatchScheduleBaseView.h"

@class UIImageView, UILabel;

@interface QSSportsNonVersusMatchScheduleView : QSSportsMatchScheduleBaseView
{
    UILabel *_matchNameLabel;
    UILabel *_matchTitleLabel;
    UILabel *_matchStatusLabel;
    UIImageView *_liveTypeIcon;
    UIImageView *_vipLogo;
}

@property(retain, nonatomic) UIImageView *vipLogo; // @synthesize vipLogo=_vipLogo;
@property(retain, nonatomic) UIImageView *liveTypeIcon; // @synthesize liveTypeIcon=_liveTypeIcon;
@property(retain, nonatomic) UILabel *matchStatusLabel; // @synthesize matchStatusLabel=_matchStatusLabel;
@property(retain, nonatomic) UILabel *matchTitleLabel; // @synthesize matchTitleLabel=_matchTitleLabel;
@property(retain, nonatomic) UILabel *matchNameLabel; // @synthesize matchNameLabel=_matchNameLabel;
- (void).cxx_destruct;
- (void)themeChanged:(long long)arg1;
- (void)refreshWithScheduleItem:(id)arg1 showDetailDate:(_Bool)arg2;
- (id)initWithFrame:(struct CGRect)arg1;

@end
