//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QSIndexedData.h"

@class NSArray, NSMutableArray, NSString, QSTextLiveMatchAdItem, QSTextLiveMatchItem;

@interface QSTextLiveListData : QSIndexedData
{
    NSString *_mid;
    QSTextLiveMatchAdItem *_adInfo;
    NSArray *_liveSourceList;
    NSMutableArray *_customQuarters;
    QSTextLiveMatchItem *_textLiveMatchItem;
}

+ (id)modelFormResponseValues:(id)arg1 extraInfo:(id)arg2 error:(id *)arg3;
@property(retain, nonatomic) QSTextLiveMatchItem *textLiveMatchItem; // @synthesize textLiveMatchItem=_textLiveMatchItem;
@property(retain, nonatomic) NSMutableArray *customQuarters; // @synthesize customQuarters=_customQuarters;
@property(retain, nonatomic) NSArray *liveSourceList; // @synthesize liveSourceList=_liveSourceList;
@property(retain, nonatomic) QSTextLiveMatchAdItem *adInfo; // @synthesize adInfo=_adInfo;
@property(retain, nonatomic) NSString *mid; // @synthesize mid=_mid;
- (void).cxx_destruct;
- (void)onAutoUpdate;
- (double)updateTimeInterval;
- (id)identifier;
- (void)resetCurrentCustomQuarters;
- (void)resetAllDataWithResponseData:(id)arg1;
- (void)resetWithResponseModel:(id)arg1;
- (void)calWhetherAnimateFirstPlusScoreWithOriginFirstTextLiveItem:(id)arg1;
- (id)calCurrentFirstTextLiveItem;
- (id)indexesFromResponseData:(id)arg1;
- (id)syncContentHttpURLComponentsWithIndexes:(id)arg1;
- (id)indexHttpURLComponents;
- (id)textLiveItemAtIndexPath:(id)arg1;
- (void)emptyMemoryCache;
- (void)resetFromCacheObject:(id)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;

@end

