//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSArray, NSNumber, QNNetworkRecommendHotCategoryApi;

@interface QNNetworkRecommendHotCategoryManager : NSObject
{
    QNNetworkRecommendHotCategoryApi *_requestApi;
    NSArray *_recommendHotCategory;
    NSNumber *_updateTime;
}

+ (id)pathOfRecommendHotCategoryCache;
@property(retain, nonatomic) NSNumber *updateTime; // @synthesize updateTime=_updateTime;
@property(copy, nonatomic) NSArray *recommendHotCategory; // @synthesize recommendHotCategory=_recommendHotCategory;
@property(retain, nonatomic) QNNetworkRecommendHotCategoryApi *requestApi; // @synthesize requestApi=_requestApi;
- (void).cxx_destruct;
- (void)updateRecommendHotCategoryList:(_Bool)arg1;
- (_Bool)shouldUpdateRecommendHotCategory;

@end
