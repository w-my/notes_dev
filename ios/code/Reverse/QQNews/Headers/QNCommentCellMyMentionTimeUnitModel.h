//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNCommentCellBaseUnitModel.h"

@class NSAttributedString, NSString, QNBaseViewModel;

@interface QNCommentCellMyMentionTimeUnitModel : QNCommentCellBaseUnitModel
{
    NSAttributedString *_time;
    QNBaseViewModel *_timeUnit;
    NSString *_answerStr;
    QNBaseViewModel *_answerUnit;
}

@property(retain, nonatomic) QNBaseViewModel *answerUnit; // @synthesize answerUnit=_answerUnit;
@property(copy, nonatomic) NSString *answerStr; // @synthesize answerStr=_answerStr;
@property(retain, nonatomic) QNBaseViewModel *timeUnit; // @synthesize timeUnit=_timeUnit;
@property(copy, nonatomic) NSAttributedString *time; // @synthesize time=_time;
- (void).cxx_destruct;
- (void)setBgColor:(id)arg1;
- (void)calculateWithData:(id)arg1 referRect:(struct CGRect)arg2 context:(id)arg3;

@end
