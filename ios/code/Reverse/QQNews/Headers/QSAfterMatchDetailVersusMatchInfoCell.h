//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QSMatchDetailMatchInfoBaseCell.h"

@class CSimpleImageView, UIControl, UIImageView, UILabel;

@interface QSAfterMatchDetailVersusMatchInfoCell : QSMatchDetailMatchInfoBaseCell
{
    CSimpleImageView *_leftTeamIcon;
    UILabel *_leftTeamNameLabel;
    UIControl *_leftIconControl;
    CSimpleImageView *_rightTeamIcon;
    UIControl *_rightIconControl;
    UILabel *_rightTeamNameLabel;
    UILabel *_matchNameLabel;
    UILabel *_leftScoreLabel;
    UILabel *_rightScoreLabel;
    UILabel *_liveStatusLabel;
    UIImageView *_afterMatchScoreLine;
    UILabel *_centerShootOutLabel;
}

+ (id)lossColor;
+ (id)createScoreLabel;
@property(retain, nonatomic) UILabel *centerShootOutLabel; // @synthesize centerShootOutLabel=_centerShootOutLabel;
@property(retain, nonatomic) UIImageView *afterMatchScoreLine; // @synthesize afterMatchScoreLine=_afterMatchScoreLine;
@property(retain, nonatomic) UILabel *liveStatusLabel; // @synthesize liveStatusLabel=_liveStatusLabel;
@property(retain, nonatomic) UILabel *rightScoreLabel; // @synthesize rightScoreLabel=_rightScoreLabel;
@property(retain, nonatomic) UILabel *leftScoreLabel; // @synthesize leftScoreLabel=_leftScoreLabel;
@property(retain, nonatomic) UILabel *matchNameLabel; // @synthesize matchNameLabel=_matchNameLabel;
@property(retain, nonatomic) UILabel *rightTeamNameLabel; // @synthesize rightTeamNameLabel=_rightTeamNameLabel;
@property(retain, nonatomic) UIControl *rightIconControl; // @synthesize rightIconControl=_rightIconControl;
@property(retain, nonatomic) CSimpleImageView *rightTeamIcon; // @synthesize rightTeamIcon=_rightTeamIcon;
@property(retain, nonatomic) UIControl *leftIconControl; // @synthesize leftIconControl=_leftIconControl;
@property(retain, nonatomic) UILabel *leftTeamNameLabel; // @synthesize leftTeamNameLabel=_leftTeamNameLabel;
@property(retain, nonatomic) CSimpleImageView *leftTeamIcon; // @synthesize leftTeamIcon=_leftTeamIcon;
- (void).cxx_destruct;
- (void)teamIconClicked:(id)arg1;
- (void)themeChanged:(long long)arg1;
- (void)refreshWithMoreItem:(id)arg1 showSeperatorLine:(_Bool)arg2;
- (id)initWithStyle:(long long)arg1 reuseIdentifier:(id)arg2;

@end
