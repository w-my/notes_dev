//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableView.h"

#import "QNDetailContentElementProtocol.h"
#import "UIScrollViewDelegate.h"
#import "UITableViewDelegate.h"

@class NSArray, NSMutableDictionary, NSString, QNArticleContentAppPromotionNodeType, QNDetailContentContainer, QNDetailRelateNewsDataSource, QNLayoutTableView, QNListNewsItem, QNReportParam, QNRootViewController, TADReportManager;

@interface QNDetailRelateNewsView : QNThemableView <UITableViewDelegate, UIScrollViewDelegate, QNDetailContentElementProtocol>
{
    _Bool _isOfflineMode;
    _Bool _hasExposurePromotion;
    _Bool _hasReportedCellExposure;
    _Bool _topicExposured;
    _Bool _specialExposured;
    _Bool _relateExposured;
    _Bool _isReportNum;
    _Bool _hasReportedFoldViewExposure;
    CDUnknownBlockType _expandBlock;
    NSString *_channelId;
    QNListNewsItem *_listItem;
    QNDetailContentContainer *_contentContainer;
    QNArticleContentAppPromotionNodeType *_promotionNodeType;
    QNArticleContentAppPromotionNodeType *_promotionNodeTypeWifiManager;
    NSArray *_relateNews;
    CDUnknownBlockType _relateNewsSelectedBlock;
    TADReportManager *_adManager;
    CDUnknownBlockType _promotionBlock;
    long long _type;
    unsigned long long _from;
    QNRootViewController *_rootViewController;
    QNReportParam *_reportParam;
    QNLayoutTableView *_tableView;
    QNDetailRelateNewsDataSource *_dataSource;
    NSMutableDictionary *_cellOffSetDic;
}

+ (id)_dateFormatter;
@property(nonatomic) _Bool hasReportedFoldViewExposure; // @synthesize hasReportedFoldViewExposure=_hasReportedFoldViewExposure;
@property(nonatomic) _Bool isReportNum; // @synthesize isReportNum=_isReportNum;
@property(nonatomic) _Bool relateExposured; // @synthesize relateExposured=_relateExposured;
@property(nonatomic) _Bool specialExposured; // @synthesize specialExposured=_specialExposured;
@property(nonatomic) _Bool topicExposured; // @synthesize topicExposured=_topicExposured;
@property(retain, nonatomic) NSMutableDictionary *cellOffSetDic; // @synthesize cellOffSetDic=_cellOffSetDic;
@property(nonatomic) _Bool hasReportedCellExposure; // @synthesize hasReportedCellExposure=_hasReportedCellExposure;
@property(retain, nonatomic) QNDetailRelateNewsDataSource *dataSource; // @synthesize dataSource=_dataSource;
@property _Bool hasExposurePromotion; // @synthesize hasExposurePromotion=_hasExposurePromotion;
@property(retain, nonatomic) QNLayoutTableView *tableView; // @synthesize tableView=_tableView;
@property(retain, nonatomic) QNReportParam *reportParam; // @synthesize reportParam=_reportParam;
@property(nonatomic) __weak QNRootViewController *rootViewController; // @synthesize rootViewController=_rootViewController;
@property(nonatomic) unsigned long long from; // @synthesize from=_from;
@property(nonatomic) long long type; // @synthesize type=_type;
@property(copy, nonatomic) CDUnknownBlockType promotionBlock; // @synthesize promotionBlock=_promotionBlock;
@property(nonatomic) _Bool isOfflineMode; // @synthesize isOfflineMode=_isOfflineMode;
@property(retain, nonatomic) TADReportManager *adManager; // @synthesize adManager=_adManager;
@property(copy, nonatomic) CDUnknownBlockType relateNewsSelectedBlock; // @synthesize relateNewsSelectedBlock=_relateNewsSelectedBlock;
@property(retain, nonatomic) NSArray *relateNews; // @synthesize relateNews=_relateNews;
@property(retain, nonatomic) QNArticleContentAppPromotionNodeType *promotionNodeTypeWifiManager; // @synthesize promotionNodeTypeWifiManager=_promotionNodeTypeWifiManager;
@property(retain, nonatomic) QNArticleContentAppPromotionNodeType *promotionNodeType; // @synthesize promotionNodeType=_promotionNodeType;
@property(nonatomic) __weak QNDetailContentContainer *contentContainer; // @synthesize contentContainer=_contentContainer;
@property(retain, nonatomic) QNListNewsItem *listItem; // @synthesize listItem=_listItem;
@property(copy, nonatomic) NSString *channelId; // @synthesize channelId=_channelId;
@property(copy, nonatomic) CDUnknownBlockType expandBlock; // @synthesize expandBlock=_expandBlock;
- (void).cxx_destruct;
- (void)themeChanged:(long long)arg1;
- (void)resetDataSourceNeedShowNum;
- (void)setDataSourceSubBlock:(CDUnknownBlockType)arg1;
- (_Bool)hasExpandAll;
- (void)checkReportCellExposureWithOffSpan:(double)arg1;
- (void)updateRelateNews:(id)arg1 topicItems:(id)arg2 specialItems:(id)arg3 qaListItems:(id)arg4 guesslikeList:(id)arg5 ignoreFold:(_Bool)arg6 showRelateNewsNum:(unsigned long long)arg7;
- (void)updateRelateNews:(id)arg1 topicItems:(id)arg2 specialItems:(id)arg3 qaListItems:(id)arg4 guesslikeList:(id)arg5;
- (void)updateRelateNews:(id)arg1 topicItems:(id)arg2 specialItems:(id)arg3 qaListItems:(id)arg4 ignoreFold:(_Bool)arg5;
- (void)updateRelateNews:(id)arg1 topicItems:(id)arg2 specialItems:(id)arg3 qaListItems:(id)arg4;
- (void)reloadRelateNewsViewForUnfoldView;
- (void)reloadRelateNewsView;
- (void)_exposurePromotionInChannel:(id)arg1;
- (unsigned long long)_exposureTimesInChannel:(id)arg1;
- (id)_keyForChannelPromotion:(id)arg1;
- (void)showNoAdTip:(id)arg1;
- (void)mergeAds;
- (void)initAdWithListItem:(id)arg1 adList:(id)arg2;
- (void)tableView:(id)arg1 didSelectRowAtIndexPath:(id)arg2;
- (double)tableView:(id)arg1 heightForFooterInSection:(long long)arg2;
- (id)tableView:(id)arg1 viewForFooterInSection:(long long)arg2;
- (double)tableView:(id)arg1 heightForRowAtIndexPath:(id)arg2;
- (_Bool)p_openCategorySelectionWithModuleItem:(id)arg1 type:(id)arg2 position:(long long)arg3;
- (void)tableView:(id)arg1 willDisplayCell:(id)arg2 forRowAtIndexPath:(id)arg3;
- (void)contentContainerWillDisappear;
- (_Bool)p_checkExposureForCellAtIndex:(long long)arg1;
- (void)contentContainer:(id)arg1 ScrolledToPosition:(struct CGPoint)arg2;
- (id)contentScrollView;
- (double)heightOfElementView;
- (id)_fakeListItemFromPromNode:(id)arg1;
- (void)dealloc;
- (id)initWithFrame:(struct CGRect)arg1 type:(long long)arg2;
- (id)initWithFrame:(struct CGRect)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

