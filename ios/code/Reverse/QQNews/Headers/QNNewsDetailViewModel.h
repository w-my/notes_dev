//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class CArticleContentType, QNCommonParam, QNHotEventsListParam, QNListNewsItem, TADDP3ReportItem, TADNewsArticleAsyncLoader;

@interface QNNewsDetailViewModel : NSObject
{
    _Bool _hideRelateNews;
    _Bool _showMediaCard;
    _Bool _showGuessLike;
    _Bool _picAdDisabled;
    _Bool _relAdDisabled;
    QNListNewsItem *_listItem;
    QNCommonParam *_commonParam;
    CArticleContentType *_articleContent;
    CArticleContentType *_articleRelateContent;
    QNHotEventsListParam *_hotEventParam;
    TADNewsArticleAsyncLoader *_newsArticleAdLoader;
    TADDP3ReportItem *_dp3Item;
    CDUnknownBlockType _adLoadFinishBlock;
}

+ (id)viewModelWithListItem:(id)arg1 commonParam:(id)arg2;
@property(copy, nonatomic) CDUnknownBlockType adLoadFinishBlock; // @synthesize adLoadFinishBlock=_adLoadFinishBlock;
@property(nonatomic) _Bool relAdDisabled; // @synthesize relAdDisabled=_relAdDisabled;
@property(nonatomic) _Bool picAdDisabled; // @synthesize picAdDisabled=_picAdDisabled;
@property(retain, nonatomic) TADDP3ReportItem *dp3Item; // @synthesize dp3Item=_dp3Item;
@property(retain, nonatomic) TADNewsArticleAsyncLoader *newsArticleAdLoader; // @synthesize newsArticleAdLoader=_newsArticleAdLoader;
@property(nonatomic) _Bool showGuessLike; // @synthesize showGuessLike=_showGuessLike;
@property(nonatomic) _Bool showMediaCard; // @synthesize showMediaCard=_showMediaCard;
@property(nonatomic) _Bool hideRelateNews; // @synthesize hideRelateNews=_hideRelateNews;
@property(retain, nonatomic) QNHotEventsListParam *hotEventParam; // @synthesize hotEventParam=_hotEventParam;
@property(retain, nonatomic) CArticleContentType *articleRelateContent; // @synthesize articleRelateContent=_articleRelateContent;
@property(retain, nonatomic) CArticleContentType *articleContent; // @synthesize articleContent=_articleContent;
@property(retain, nonatomic) QNCommonParam *commonParam; // @synthesize commonParam=_commonParam;
@property(retain, nonatomic) QNListNewsItem *listItem; // @synthesize listItem=_listItem;
- (void).cxx_destruct;
- (void)reportAsyncAdStatus;
- (void)loadAdWithFinishBlock:(CDUnknownBlockType)arg1;
- (void)increaseUnfoldTimes;
- (_Bool)enableFoldContent;
- (id)cardNode;
- (void)updateBroadcastVideoWithFinishBlock:(CDUnknownBlockType)arg1;
- (void)p_updateOnelinkCommentCount:(id)arg1 commentCount:(long long)arg2;
- (void)p_flushCommentCountWithDictionary:(id)arg1;
- (void)updateElementCommentCount;
- (id)init;

@end
