//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableView.h"

@class LOTAnimationView, QNBaseLabel;

@interface QNLeftSlideSeeNextQATipView : QNThemableView
{
    QNBaseLabel *_answerLabel;
    LOTAnimationView *_aniView;
}

@property(retain, nonatomic) LOTAnimationView *aniView; // @synthesize aniView=_aniView;
@property(retain, nonatomic) QNBaseLabel *answerLabel; // @synthesize answerLabel=_answerLabel;
- (void).cxx_destruct;
- (void)themeChanged:(long long)arg1;
- (void)refreshAnimation;
- (void)layoutSubviews;
- (id)initWithFrame:(struct CGRect)arg1;

@end

