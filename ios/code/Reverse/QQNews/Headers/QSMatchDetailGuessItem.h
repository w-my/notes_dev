//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QSModel.h"

@class NSArray, NSString, QSMatchGuessQuestionExtraInfo;

@interface QSMatchDetailGuessItem : QSModel
{
    _Bool _active;
    NSString *_gid;
    NSString *_mid;
    long long _choiceType;
    NSArray *_choiceOpts;
    NSString *_participatorCnt;
    NSString *_vsLogo;
    NSString *_title;
    QSMatchGuessQuestionExtraInfo *_extraInfo;
    long long _drawStateNo;
    NSString *_userChoiceText;
    NSString *_odds;
    NSString *_currencyCnt;
    NSString *_joinTime;
    NSString *_winCurrencyCnt;
    NSString *_choiceAns;
}

+ (id)classNameForObjectInArrayProperty:(id)arg1;
@property(retain, nonatomic) NSString *choiceAns; // @synthesize choiceAns=_choiceAns;
@property(retain, nonatomic) NSString *winCurrencyCnt; // @synthesize winCurrencyCnt=_winCurrencyCnt;
@property(retain, nonatomic) NSString *joinTime; // @synthesize joinTime=_joinTime;
@property(retain, nonatomic) NSString *currencyCnt; // @synthesize currencyCnt=_currencyCnt;
@property(retain, nonatomic) NSString *odds; // @synthesize odds=_odds;
@property(retain, nonatomic) NSString *userChoiceText; // @synthesize userChoiceText=_userChoiceText;
@property(nonatomic) long long drawStateNo; // @synthesize drawStateNo=_drawStateNo;
@property(retain, nonatomic) QSMatchGuessQuestionExtraInfo *extraInfo; // @synthesize extraInfo=_extraInfo;
@property(nonatomic) _Bool active; // @synthesize active=_active;
@property(copy, nonatomic) NSString *title; // @synthesize title=_title;
@property(copy, nonatomic) NSString *vsLogo; // @synthesize vsLogo=_vsLogo;
@property(copy, nonatomic) NSString *participatorCnt; // @synthesize participatorCnt=_participatorCnt;
@property(retain, nonatomic) NSArray *choiceOpts; // @synthesize choiceOpts=_choiceOpts;
@property(nonatomic) long long choiceType; // @synthesize choiceType=_choiceType;
@property(copy, nonatomic) NSString *mid; // @synthesize mid=_mid;
@property(copy, nonatomic) NSString *gid; // @synthesize gid=_gid;
- (void).cxx_destruct;

@end

