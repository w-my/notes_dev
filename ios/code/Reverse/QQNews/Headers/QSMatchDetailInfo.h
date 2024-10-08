//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QSModel.h"

@class NSArray, NSString, QSMatchDetailAdvertiseLinkModel, QSMatchDetailAfterVideosItem, QSMatchDetailBbsItem, QSMatchDetailMoreItem, QSMatchDetailNewsList, QSMatchDetailRelatedDataItem, QSMatchDetailRoseShareItem, QSMatchDetailShareItem, QSMatchDetailStartListModel, QSMatchDetailVersusHistoryItem;

@interface QSMatchDetailInfo : QSModel
{
    QSMatchDetailMoreItem *_detail;
    QSMatchDetailShareItem *_share;
    QSMatchDetailNewsList *_matchNewsList;
    QSMatchDetailRoseShareItem *_roseShareItem;
    QSMatchDetailStartListModel *_startList;
    NSArray *_guessData;
    NSArray *_payArticleList;
    NSArray *_latestResult;
    QSMatchDetailVersusHistoryItem *_vsHistory;
    NSArray *_futureMatches;
    QSMatchDetailAfterVideosItem *_afterVideos;
    QSMatchDetailAfterVideosItem *_afterRecord;
    QSMatchDetailAdvertiseLinkModel *_advertiseLink;
    QSMatchDetailRelatedDataItem *_stat;
    QSMatchDetailBbsItem *_bbs;
    NSString *_gameDataTitle;
    NSString *_gameDataWebViewUrl;
    NSString *_button;
}

+ (id)classNameForObjectInArrayProperty:(id)arg1;
@property(copy, nonatomic) NSString *button; // @synthesize button=_button;
@property(copy, nonatomic) NSString *gameDataWebViewUrl; // @synthesize gameDataWebViewUrl=_gameDataWebViewUrl;
@property(copy, nonatomic) NSString *gameDataTitle; // @synthesize gameDataTitle=_gameDataTitle;
@property(retain, nonatomic) QSMatchDetailBbsItem *bbs; // @synthesize bbs=_bbs;
@property(retain, nonatomic) QSMatchDetailRelatedDataItem *stat; // @synthesize stat=_stat;
@property(retain, nonatomic) QSMatchDetailAdvertiseLinkModel *advertiseLink; // @synthesize advertiseLink=_advertiseLink;
@property(retain, nonatomic) QSMatchDetailAfterVideosItem *afterRecord; // @synthesize afterRecord=_afterRecord;
@property(retain, nonatomic) QSMatchDetailAfterVideosItem *afterVideos; // @synthesize afterVideos=_afterVideos;
@property(retain, nonatomic) NSArray *futureMatches; // @synthesize futureMatches=_futureMatches;
@property(retain, nonatomic) QSMatchDetailVersusHistoryItem *vsHistory; // @synthesize vsHistory=_vsHistory;
@property(retain, nonatomic) NSArray *latestResult; // @synthesize latestResult=_latestResult;
@property(retain, nonatomic) NSArray *payArticleList; // @synthesize payArticleList=_payArticleList;
@property(retain, nonatomic) NSArray *guessData; // @synthesize guessData=_guessData;
@property(retain, nonatomic) QSMatchDetailStartListModel *startList; // @synthesize startList=_startList;
@property(retain, nonatomic) QSMatchDetailRoseShareItem *roseShareItem; // @synthesize roseShareItem=_roseShareItem;
@property(retain, nonatomic) QSMatchDetailNewsList *matchNewsList; // @synthesize matchNewsList=_matchNewsList;
@property(retain, nonatomic) QSMatchDetailShareItem *share; // @synthesize share=_share;
@property(retain, nonatomic) QSMatchDetailMoreItem *detail; // @synthesize detail=_detail;
- (void).cxx_destruct;
- (_Bool)manualSetValue:(id)arg1 forKey:(id)arg2;

@end

