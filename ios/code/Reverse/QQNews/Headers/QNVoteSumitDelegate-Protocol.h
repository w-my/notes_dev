//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class QNVoteBarOptionView, QNVoteQuestionView;

@protocol QNVoteSumitDelegate <NSObject>
- (void)submitVote:(void (^)(void))arg1;
- (void)didQNVoteOptionViewSelected:(QNVoteQuestionView *)arg1 optionView:(QNVoteBarOptionView *)arg2;
@end

