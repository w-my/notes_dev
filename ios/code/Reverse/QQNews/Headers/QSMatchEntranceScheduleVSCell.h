//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QSMatchEntranceScheduleCell.h"

@class CSimpleImageView, QSMatchEntranceScheduleVSInMatchTipView, QSScoreAnimationView, UIImageView, UILabel;

@interface QSMatchEntranceScheduleVSCell : QSMatchEntranceScheduleCell
{
    CSimpleImageView *_leftTeamIcon;
    UILabel *_leftTeamNameLabel;
    CSimpleImageView *_rightTeamIcon;
    UILabel *_rightTeamNameLabel;
    UILabel *_matchNameLabel;
    UILabel *_matchStatusLabel;
    UIImageView *_leftImageView;
    UIImageView *_rightImageView;
    QSScoreAnimationView *_leftScoreView;
    QSScoreAnimationView *_rightScoreView;
    UILabel *_leftScoreLabel;
    UILabel *_rightScoreLabel;
    UIImageView *_afterMatchScoreLine;
    UILabel *_afterMatchShootOutScoreLabel;
    QSMatchEntranceScheduleVSInMatchTipView *_inMatchTipView;
    UIImageView *_vipLogo;
    UILabel *_liveTypeLabel;
    UIImageView *_liveTypeIcon;
}

+ (id)lossColor;
+ (id)createScoreLabel;
@property(retain, nonatomic) UIImageView *liveTypeIcon; // @synthesize liveTypeIcon=_liveTypeIcon;
@property(retain, nonatomic) UILabel *liveTypeLabel; // @synthesize liveTypeLabel=_liveTypeLabel;
@property(retain, nonatomic) UIImageView *vipLogo; // @synthesize vipLogo=_vipLogo;
@property(retain, nonatomic) QSMatchEntranceScheduleVSInMatchTipView *inMatchTipView; // @synthesize inMatchTipView=_inMatchTipView;
@property(retain, nonatomic) UILabel *afterMatchShootOutScoreLabel; // @synthesize afterMatchShootOutScoreLabel=_afterMatchShootOutScoreLabel;
@property(retain, nonatomic) UIImageView *afterMatchScoreLine; // @synthesize afterMatchScoreLine=_afterMatchScoreLine;
@property(retain, nonatomic) UILabel *rightScoreLabel; // @synthesize rightScoreLabel=_rightScoreLabel;
@property(retain, nonatomic) UILabel *leftScoreLabel; // @synthesize leftScoreLabel=_leftScoreLabel;
@property(retain, nonatomic) QSScoreAnimationView *rightScoreView; // @synthesize rightScoreView=_rightScoreView;
@property(retain, nonatomic) QSScoreAnimationView *leftScoreView; // @synthesize leftScoreView=_leftScoreView;
@property(retain, nonatomic) UIImageView *rightImageView; // @synthesize rightImageView=_rightImageView;
@property(retain, nonatomic) UIImageView *leftImageView; // @synthesize leftImageView=_leftImageView;
@property(retain, nonatomic) UILabel *matchStatusLabel; // @synthesize matchStatusLabel=_matchStatusLabel;
@property(retain, nonatomic) UILabel *matchNameLabel; // @synthesize matchNameLabel=_matchNameLabel;
@property(retain, nonatomic) UILabel *rightTeamNameLabel; // @synthesize rightTeamNameLabel=_rightTeamNameLabel;
@property(retain, nonatomic) CSimpleImageView *rightTeamIcon; // @synthesize rightTeamIcon=_rightTeamIcon;
@property(retain, nonatomic) UILabel *leftTeamNameLabel; // @synthesize leftTeamNameLabel=_leftTeamNameLabel;
@property(retain, nonatomic) CSimpleImageView *leftTeamIcon; // @synthesize leftTeamIcon=_leftTeamIcon;
- (void).cxx_destruct;
- (void)refreshUI;
- (void)themeDidChange:(id)arg1;
- (void)updateWithEntranceMatchItem:(id)arg1 scoreAnimated:(_Bool)arg2;
- (void)updateWithEntranceMatchItem:(id)arg1;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
- (void)setEntranceMatchItem:(id)arg1;
- (void)dealloc;
- (id)initWithFrame:(struct CGRect)arg1 reuseIdentifier:(id)arg2;

@end
