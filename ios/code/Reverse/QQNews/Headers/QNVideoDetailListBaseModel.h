//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSArray, NSDictionary, NSMutableArray, NSMutableSet, NSString, QNVideoDetailImmerseListMoreApi, QNVideoDetailItem, TADVideoListReportManager;

@interface QNVideoDetailListBaseModel : NSObject
{
    _Bool _isAlbumDetailModel;
    _Bool _isFirstLoadMore;
    _Bool _requestFinished;
    NSString *_channel;
    NSString *_pageName;
    NSString *_listItemID;
    id <QNVideoDetailListModelDelegate> _delegate;
    NSDictionary *_titleOfSectionMap;
    TADVideoListReportManager *_adManager;
    QNVideoDetailItem *_mVideoDetailItem;
    long long _albumVideoCount;
    long long _modelType;
    long long _from;
    long long _showVideoAlbumNum;
    NSMutableSet *_vidsSet;
    NSMutableArray *_myVDetailList;
    NSMutableArray *_myRecVDetailList;
    NSMutableArray *_myPageVDetailList;
    NSArray *_myFinalVDetailList;
    NSMutableArray *_myShrinkVDetailList;
    QNVideoDetailItem *_mainItem;
    QNVideoDetailImmerseListMoreApi *_requestApi;
}

@property(nonatomic) _Bool requestFinished; // @synthesize requestFinished=_requestFinished;
@property(retain, nonatomic) QNVideoDetailImmerseListMoreApi *requestApi; // @synthesize requestApi=_requestApi;
@property(nonatomic) _Bool isFirstLoadMore; // @synthesize isFirstLoadMore=_isFirstLoadMore;
@property(retain, nonatomic) QNVideoDetailItem *mainItem; // @synthesize mainItem=_mainItem;
@property(retain, nonatomic) NSMutableArray *myShrinkVDetailList; // @synthesize myShrinkVDetailList=_myShrinkVDetailList;
@property(retain, nonatomic) NSArray *myFinalVDetailList; // @synthesize myFinalVDetailList=_myFinalVDetailList;
@property(retain, nonatomic) NSMutableArray *myPageVDetailList; // @synthesize myPageVDetailList=_myPageVDetailList;
@property(retain, nonatomic) NSMutableArray *myRecVDetailList; // @synthesize myRecVDetailList=_myRecVDetailList;
@property(retain, nonatomic) NSMutableArray *myVDetailList; // @synthesize myVDetailList=_myVDetailList;
@property(retain, nonatomic) NSMutableSet *vidsSet; // @synthesize vidsSet=_vidsSet;
@property(nonatomic) long long showVideoAlbumNum; // @synthesize showVideoAlbumNum=_showVideoAlbumNum;
@property(nonatomic) long long from; // @synthesize from=_from;
@property(nonatomic) long long modelType; // @synthesize modelType=_modelType;
@property(nonatomic) _Bool isAlbumDetailModel; // @synthesize isAlbumDetailModel=_isAlbumDetailModel;
@property(nonatomic) long long albumVideoCount; // @synthesize albumVideoCount=_albumVideoCount;
@property(retain, nonatomic) QNVideoDetailItem *mVideoDetailItem; // @synthesize mVideoDetailItem=_mVideoDetailItem;
@property(nonatomic) __weak TADVideoListReportManager *adManager; // @synthesize adManager=_adManager;
@property(copy, nonatomic) NSDictionary *titleOfSectionMap; // @synthesize titleOfSectionMap=_titleOfSectionMap;
@property(nonatomic) __weak id <QNVideoDetailListModelDelegate> delegate; // @synthesize delegate=_delegate;
@property(copy, nonatomic) NSString *listItemID; // @synthesize listItemID=_listItemID;
@property(copy, nonatomic) NSString *pageName; // @synthesize pageName=_pageName;
@property(copy, nonatomic) NSString *channel; // @synthesize channel=_channel;
- (void).cxx_destruct;
- (void)deleteTwoInsertOneDetailItemsFromIndex:(long long)arg1 insertAfterFirstVideoDetailItem:(id)arg2;
- (void)deleteTwoDetailItemsFromIndex:(long long)arg1 replaceFirstVideoDetailItem:(id)arg2;
- (void)insertTwoDetailItems:(id)arg1 fromIndex:(long long)arg2;
- (void)deleteDetailItem:(id)arg1 atIndex:(long long)arg2;
- (void)insertDetailItem:(id)arg1 atIndex:(long long)arg2;
- (long long)getMyListCount;
- (id)getMyPageViewList;
- (id)p_createNewDetailList;
- (id)getMyList;
- (void)insertLastKKExtItems;
- (void)mergeImmerseAds;
- (void)expandShrinkedVideoItemsAtPosition:(unsigned long long)arg1;
- (void)addKKExtItems:(id)arg1 subList:(id)arg2 listItems:(id)arg3 direction:(unsigned long long)arg4;
- (void)p_loadRecVideoNewsWithListItem:(id)arg1;
- (void)p_addRecKKExtItems:(id)arg1 subList:(id)arg2 listItems:(id)arg3;
- (void)setMainVideoDetailItem:(id)arg1;
- (id)init;

@end

