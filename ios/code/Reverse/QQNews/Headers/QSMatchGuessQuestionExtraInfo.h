//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QSModel.h"

@class NSString;

@interface QSMatchGuessQuestionExtraInfo : QSModel
{
    NSString *_tcId;
    NSString *_bets;
    NSString *_liveScore;
    NSString *_lotteryName;
}

@property(retain, nonatomic) NSString *lotteryName; // @synthesize lotteryName=_lotteryName;
@property(retain, nonatomic) NSString *liveScore; // @synthesize liveScore=_liveScore;
@property(retain, nonatomic) NSString *bets; // @synthesize bets=_bets;
@property(retain, nonatomic) NSString *tcId; // @synthesize tcId=_tcId;
- (void).cxx_destruct;

@end
