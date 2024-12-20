//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@class QSMatchDetailGuessChoiceItem, UIButton, UIImageView, UILabel;

@interface QSMatchDetailGuessChoiceView : UIView
{
    UIButton *_bgBtn;
    UILabel *_titleLabel;
    UILabel *_infoLabel;
    QSMatchDetailGuessChoiceItem *_choiceItem;
    id <QSMatchDetailGuessChoiceViewDelegate> _delegate;
    UIImageView *_oddsIndicator;
}

+ (double)fixedHeight;
@property(retain, nonatomic) UIImageView *oddsIndicator; // @synthesize oddsIndicator=_oddsIndicator;
@property(nonatomic) __weak id <QSMatchDetailGuessChoiceViewDelegate> delegate; // @synthesize delegate=_delegate;
@property(retain, nonatomic) QSMatchDetailGuessChoiceItem *choiceItem; // @synthesize choiceItem=_choiceItem;
@property(retain, nonatomic) UILabel *infoLabel; // @synthesize infoLabel=_infoLabel;
@property(retain, nonatomic) UILabel *titleLabel; // @synthesize titleLabel=_titleLabel;
@property(retain, nonatomic) UIButton *bgBtn; // @synthesize bgBtn=_bgBtn;
- (void).cxx_destruct;
- (void)bgControlClicked:(id)arg1;
- (void)executeOddsAnimation;
- (void)showAnimationWithOddsChangeRecord:(long long)arg1;
- (void)refreshWithChoiceItem:(id)arg1;
- (id)initWithFrame:(struct CGRect)arg1;

@end

