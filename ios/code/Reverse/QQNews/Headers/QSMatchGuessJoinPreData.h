//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QSStatedData.h"

@class NSString, QSMatchGuessJoinPreInfo, QSMatchGuessQuestionExtraInfo;

@interface QSMatchGuessJoinPreData : QSStatedData
{
    QSMatchGuessQuestionExtraInfo *_extraInfo;
    NSString *_tcId;
    NSString *_lotteryName;
    NSString *_gid;
    NSString *_choiceId;
}

+ (id)toWan0String:(id)arg1;
+ (id)toWanString:(id)arg1;
+ (_Bool)cleanCacheWhenUserChanged;
@property(copy, nonatomic) NSString *choiceId; // @synthesize choiceId=_choiceId;
@property(retain, nonatomic) NSString *gid; // @synthesize gid=_gid;
@property(retain, nonatomic) NSString *lotteryName; // @synthesize lotteryName=_lotteryName;
@property(retain, nonatomic) NSString *tcId; // @synthesize tcId=_tcId;
@property(retain, nonatomic) QSMatchGuessQuestionExtraInfo *extraInfo; // @synthesize extraInfo=_extraInfo;
- (void).cxx_destruct;
- (void)resetWithResponseModel:(id)arg1;
- (id)httpURLComponents;
- (id)identifier;
@property(nonatomic) __weak QSMatchGuessJoinPreInfo *joinInfo; // @dynamic joinInfo;

@end
