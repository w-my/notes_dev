//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QSStatedData.h"

@class NSString, QSMatchGuessQuestionExtraInfo;

@interface QSMatchGuessJoinCommitData : QSStatedData
{
    QSMatchGuessQuestionExtraInfo *_extraInfo;
    NSString *_gid;
    NSString *_choiceId;
    NSString *_currencyCnt;
    NSString *_odds;
}

@property(copy, nonatomic) NSString *odds; // @synthesize odds=_odds;
@property(copy, nonatomic) NSString *currencyCnt; // @synthesize currencyCnt=_currencyCnt;
@property(copy, nonatomic) NSString *choiceId; // @synthesize choiceId=_choiceId;
@property(retain, nonatomic) NSString *gid; // @synthesize gid=_gid;
@property(retain, nonatomic) QSMatchGuessQuestionExtraInfo *extraInfo; // @synthesize extraInfo=_extraInfo;
- (void).cxx_destruct;
- (void)resetWithResponseModel:(id)arg1;
- (id)retExtraInfoInError:(id)arg1;
- (id)retOddsInError:(id)arg1;
- (id)httpURLComponents;
- (id)identifier;

@end

