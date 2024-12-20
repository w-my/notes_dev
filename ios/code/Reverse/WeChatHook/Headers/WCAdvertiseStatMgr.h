//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMService.h"

#import "MMService.h"
#import "PBMessageObserverDelegate.h"
#import "WAAppTaskMgrExt.h"

@class NSMutableArray, NSMutableDictionary, NSMutableSet, NSString;

@interface WCAdvertiseStatMgr : MMService <WAAppTaskMgrExt, MMService, PBMessageObserverDelegate>
{
    NSMutableDictionary *_adID2BodyMap;
    NSMutableDictionary *_adID2CommentMap;
    NSMutableArray *_pictureWrapList;
    unsigned int _clickMinuteFrequency;
    unsigned int _clickMinuteReportCount;
    unsigned int _clickMinuteTimestamp;
    unsigned int _exposureMinuteFrequency;
    unsigned int _exposureMinuteReportCount;
    unsigned int _exposureMinuteTimestamp;
    NSMutableSet *_forbidReportTimelineExposureFeedIdSet;
    _Bool _startRecordAdPageChange;
    NSString *_adInfo;
    NSString *_currUrl;
    NSString *_sessionId;
    NSMutableDictionary *_appId2WAPageInfo;
}

+ (_Bool)isSameMinuteTimestampA:(unsigned int)arg1 andTimestampB:(unsigned int)arg2;
@property(retain, nonatomic) NSMutableSet *forbidReportTimelineExposureFeedIdSet; // @synthesize forbidReportTimelineExposureFeedIdSet=_forbidReportTimelineExposureFeedIdSet;
- (void).cxx_destruct;
- (void)adGestureInfoReport:(unsigned int)arg1 logExt:(id)arg2 source:(unsigned int)arg3;
- (void)onAppTaskDidEnterBackground:(id)arg1 mode:(long long)arg2;
- (void)endRecordAdWeAppPage:(id)arg1 closeType:(unsigned long long)arg2;
- (void)startRecordAdWeAppPage:(id)arg1 appid:(id)arg2 pagePath:(id)arg3 scene:(unsigned long long)arg4 sceneNote:(id)arg5;
- (void)setRemindFriendsInfoForADExposureRequest:(id)arg1 AndItem:(id)arg2;
- (void)setRemindFriendsInfoForAdClickRequest:(id)arg1 AndItem:(id)arg2;
- (void)setRemindFriendsInfoForAdClickRequest:(id)arg1 AndItemID:(id)arg2;
- (id)getAdvertiseInfoForItem:(id)arg1;
- (void)adDataReport:(unsigned int)arg1 logExts:(id)arg2;
- (void)adDataReport:(unsigned int)arg1 logExt:(id)arg2;
- (void)handleAddataReport:(id)arg1;
- (void)endRecordAdPageChange;
- (void)webviewPageChange:(unsigned long long)arg1 currUrl:(id)arg2 referUrl:(id)arg3 errCode:(int)arg4;
- (void)initWebViewSessionId:(id)arg1;
- (void)didEnterBackground;
- (void)willEnterForeground;
- (void)startRecordAdPageChange:(id)arg1 currWebView:(id)arg2 currUrl:(id)arg3;
- (void)handleADExposureResponse:(id)arg1;
- (void)handleADClickResponse:(id)arg1;
- (void)MessageReturn:(id)arg1 Event:(unsigned int)arg2;
- (_Bool)reportADExposureForRequest:(id)arg1;
- (void)reportADClickForRequest:(id)arg1;
- (id)logAdCanvasClickPost:(id)arg1 exposureScene:(int)arg2;
- (id)logAdExpandLogoClickPos:(id)arg1 exposureScene:(int)arg2;
- (id)logAdPoiClickPos:(id)arg1 exposureScene:(int)arg2;
- (void)eventADPage:(id)arg1;
- (void)exposureADDetail:(id)arg1 dataItem:(id)arg2;
- (void)exposureADFeed:(id)arg1 dataItem:(id)arg2;
- (void)startAdResumeAppear:(id)arg1 adCell:(id)arg2;
- (void)startAdDisappear:(id)arg1 adCell:(id)arg2;
- (void)endViewStreamVideo:(id)arg1;
- (void)startViewStreamVideo:(id)arg1;
- (void)endViewVideo:(id)arg1;
- (void)startViewVideo:(id)arg1;
- (void)endPicture:(id)arg1 adType:(unsigned int)arg2;
- (void)changePictureFromIndex:(id)arg1 fromIndex:(unsigned int)arg2 toIndex:(unsigned int)arg3;
- (void)startPicture:(id)arg1 startIndex:(unsigned int)arg2 totalNum:(unsigned int)arg3;
- (void)logSphereViewWithSphereReportInfo:(id)arg1 dataItem:(id)arg2 scene:(unsigned int)arg3;
- (void)logSphereViewInDetailWithWrapInfo:(id)arg1 dataItem:(id)arg2;
- (void)logSphereViewInTimeLineWithWrapInfo:(id)arg1 dataItem:(id)arg2;
- (void)logABTest:(id)arg1;
- (void)logHeadImageH5:(id)arg1;
- (void)logADBrandProfile:(id)arg1;
- (void)logADFloatView:(id)arg1;
- (void)logADPoiH5:(id)arg1;
- (void)logADH5:(id)arg1 withUserInfo:(id)arg2 reportType:(unsigned long long)arg3;
- (void)logADH5:(id)arg1;
- (void)logADDetail:(id)arg1 dataItem:(id)arg2;
- (void)logADCommentLog:(id)arg1;
- (void)logADBodyLog:(id)arg1;
- (void)reportAllFeedsADLog;
- (void)endDisplayADComment:(id)arg1;
- (void)willDisplayADComment:(id)arg1;
- (void)endDisplayADBody:(id)arg1 dataItem:(id)arg2;
- (void)willDisplayADBody:(id)arg1;
- (void)dealloc;
- (_Bool)onServiceMemoryWarning;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

