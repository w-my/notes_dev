//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@class NSArray, UIButton, UIImage, UIImageView, UILabel;

@interface QSMatchGuessOption : UIView
{
    _Bool _questionActive;
    UIImage *_onlistLabel1Background;
    UIImage *_onlistLabel1BackgroundSelected;
    UIImage *_endlistLabel1Background;
    UIImageView *_bgView;
    UILabel *_label1;
    UILabel *_label2;
    UILabel *_label3;
    UIButton *_maskButton;
    long long _index;
    NSArray *_choiceOpts;
    UIImageView *_oddsIndicator;
}

@property(nonatomic) _Bool questionActive; // @synthesize questionActive=_questionActive;
@property(retain, nonatomic) UIImageView *oddsIndicator; // @synthesize oddsIndicator=_oddsIndicator;
@property(retain, nonatomic) NSArray *choiceOpts; // @synthesize choiceOpts=_choiceOpts;
@property(nonatomic) long long index; // @synthesize index=_index;
@property(retain, nonatomic) UIButton *maskButton; // @synthesize maskButton=_maskButton;
@property(retain, nonatomic) UILabel *label3; // @synthesize label3=_label3;
@property(retain, nonatomic) UILabel *label2; // @synthesize label2=_label2;
@property(retain, nonatomic) UILabel *label1; // @synthesize label1=_label1;
@property(retain, nonatomic) UIImageView *bgView; // @synthesize bgView=_bgView;
@property(retain, nonatomic) UIImage *endlistLabel1Background; // @synthesize endlistLabel1Background=_endlistLabel1Background;
@property(retain, nonatomic) UIImage *onlistLabel1BackgroundSelected; // @synthesize onlistLabel1BackgroundSelected=_onlistLabel1BackgroundSelected;
@property(retain, nonatomic) UIImage *onlistLabel1Background; // @synthesize onlistLabel1Background=_onlistLabel1Background;
- (void).cxx_destruct;
- (void)layoutSubviews;
- (void)executeOddsAnimation;
- (void)showAnimationWithOddsChangeRecord:(long long)arg1;
- (void)update;
- (void)dragEnded:(id)arg1 withEvent:(id)arg2;
- (void)dragBegan:(id)arg1 withEvent:(id)arg2;
- (id)initWithFrame:(struct CGRect)arg1;

@end

