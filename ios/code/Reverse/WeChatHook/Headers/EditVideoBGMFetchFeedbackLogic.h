//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSMutableArray, RecommendedMusicFeedback, WCStatTimerHelper;

@interface EditVideoBGMFetchFeedbackLogic : NSObject
{
    NSMutableArray *_recommendedMusicFeedbacks;
    RecommendedMusicFeedback *_currentRecommendedMusicFeedback;
    WCStatTimerHelper *_statTimeHelper;
}

@property(retain, nonatomic) WCStatTimerHelper *statTimeHelper; // @synthesize statTimeHelper=_statTimeHelper;
@property(retain, nonatomic) RecommendedMusicFeedback *currentRecommendedMusicFeedback; // @synthesize currentRecommendedMusicFeedback=_currentRecommendedMusicFeedback;
@property(retain, nonatomic) NSMutableArray *recommendedMusicFeedbacks; // @synthesize recommendedMusicFeedbacks=_recommendedMusicFeedbacks;
- (void).cxx_destruct;
- (void)addNewFeedbackInfo:(id)arg1 withBehaviorType:(unsigned char)arg2;
- (void)endLastFeedbackInfo;
- (void)reportFetchBgmFeedback:(_Bool)arg1 withSelected:(id)arg2 andRequestId:(unsigned long long)arg3 andIsmusicOn:(_Bool)arg4 isSearchMusic:(_Bool)arg5;
- (void)reportForSearch:(unsigned long long)arg1 recommentId:(unsigned long long)arg2 queryStr:(id)arg3 reportType:(unsigned long long)arg4 maxIndex:(unsigned long long)arg5;
- (id)init;

@end

