//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSArray, NSNumber, QNNetworkSearchHotCatApi;

@interface QNSearchHotCateRecommendManager : NSObject
{
    QNNetworkSearchHotCatApi *_requestApi;
    NSArray *_hotCateRecommList;
    NSNumber *_updateTime;
}

+ (id)pathOfInterestingCategoryCCW;
+ (id)pathOfInterestingCategoryCache;
+ (id)pathOfInterestingCategoryCacheUpdateTime;
@property(retain, nonatomic) NSNumber *updateTime; // @synthesize updateTime=_updateTime;
@property(copy, nonatomic) NSArray *hotCateRecommList; // @synthesize hotCateRecommList=_hotCateRecommList;
@property(retain, nonatomic) QNNetworkSearchHotCatApi *requestApi; // @synthesize requestApi=_requestApi;
- (void).cxx_destruct;
- (void)updateInterestingCategoryList:(_Bool)arg1;
- (_Bool)shouldUpdateInterestingCategory;

@end
