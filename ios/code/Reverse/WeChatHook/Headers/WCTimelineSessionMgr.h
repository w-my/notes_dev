//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMService.h"

#import "MMService.h"
#import "TimelineSessionSwizzleExt.h"

@class MMTableView, NSObject<OS_dispatch_queue>, NSString, UIWindow, WCTimelineSessionStatItem;

@interface WCTimelineSessionMgr : MMService <MMService, TimelineSessionSwizzleExt>
{
    MMTableView *m_tableView;
    WCTimelineSessionStatItem *sessionStatItem;
    unsigned int pId;
    NSString *pName;
    unsigned int seq;
    NSObject<OS_dispatch_queue> *queue;
    double screenHeight;
    struct CGRect statusRect;
    UIWindow *uiWindow;
    double statusNavHeight;
    double realScreenHeight;
    unsigned long long lastEnterBackgroundTime;
    _Bool isNowInTimelinePage;
}

- (void).cxx_destruct;
- (void)reportTimelinePerformanceDataByIDKey:(unsigned long long)arg1 withTotalCostTime:(unsigned long long)arg2 withCallNum:(unsigned long long)arg3;
- (id)findTableView:(id)arg1;
- (id)getNowViewController;
- (long long)tsTableView:(id)arg1 calcDataItemIndex:(long long)arg2;
- (long long)tsTableView:(id)arg1 numberOfRowsInSection:(long long)arg2;
- (double)tsTableView:(id)arg1 heightForRowAtIndexPath:(id)arg2;
- (void)calcFeedExposureSizeAndTime:(id)arg1 withTime:(unsigned long long)arg2;
- (void)calcFeedExposureSizeAndTime:(id)arg1 withEntered:(_Bool)arg2 withTime:(unsigned long long)arg3;
- (void)calcFeedExposureSizeAndTime:(id)arg1 withStayed:(_Bool)arg2 withTime:(unsigned long long)arg3;
- (id)getTimelineExposureFeedId:(id)arg1;
- (id)getTimelineSessionStatItem;
- (id)getTableView;
- (void)initTableViewAndHeight:(id)arg1;
- (void)onScrollViewDidScroll:(id)arg1 withOriginalCostTime:(unsigned long long)arg2;
- (void)onScrollViewDidEndDragging:(id)arg1 willDecelerate:(_Bool)arg2;
- (void)onScrollViewDidEndDecelerating:(id)arg1;
- (id)getFeedExposureDataAttr:(id)arg1;
- (id)getTimelineSessionStatItemAttr:(id)arg1 withDataArrays:(id)arg2 withSubSeq:(unsigned long long)arg3 withSubSeqSum:(unsigned long long)arg4;
- (id)getTimelineSessionStatItemAttrStr:(id)arg1;
- (id)formatJsonStr:(id)arg1;
- (void)reportSessionStatItem:(unsigned long long)arg1;
- (void)reconstructSessionStatItem:(unsigned long long)arg1;
- (void)exitTimelinePage;
- (void)enterTimelinePage;
- (void)onViewDidDisappear:(_Bool)arg1;
- (void)onViewDidAppear:(_Bool)arg1 withVC:(id)arg2;
- (void)onReloadDataWrap;
- (void)onEnterForeground;
- (void)onEnterBackground;
- (void)onSessionEnd;
- (void)onSessionStart;
- (void)onViewWillBePushed:(_Bool)arg1;
- (void)onViewWillBePoped:(_Bool)arg1;
- (void)dealloc;
- (void)onServiceInit;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

