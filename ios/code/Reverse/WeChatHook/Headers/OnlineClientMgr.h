//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMService.h"

#import "IMMFontMgrExt.h"
#import "IMMLanguageMgrExt.h"
#import "IMMNewSessionMgrExt.h"
#import "INewSyncExt.h"
#import "MMKernelExt.h"
#import "MMService.h"
#import "PBMessageObserverDelegate.h"

@class MMOnlineSilentDownloadLogicController, NSArray, NSMutableArray, NSMutableSet, NSString, SendActiveCGI;

@interface OnlineClientMgr : MMService <IMMLanguageMgrExt, PBMessageObserverDelegate, IMMNewSessionMgrExt, MMKernelExt, IMMFontMgrExt, INewSyncExt, MMService>
{
    _Bool m_isRunningAsBakDevice;
    _Bool m_hasGetChatList;
    _Bool m_needHeartBeat;
    _Bool m_shouldVibrateOrSound;
    _Bool m_isLoginWebWX;
    _Bool m_isGettingOnlineInfo;
    _Bool m_shouldIgnorePushOpen;
    unsigned int m_curOnlineVersion;
    unsigned int m_iconType;
    NSString *m_summaryXml;
    NSArray *m_arrOnlineInfo;
    NSMutableSet *m_markingMsgRead;
    NSMutableSet *m_pendingMarkMsgRead;
    NSMutableArray *m_lastDeviceActiveMsg;
    SendActiveCGI *m_sendActiveCGI;
    unsigned long long m_lastReadItemCreateTime;
    unsigned int m_markVoiceAsReadEventID;
    unsigned long long m_extDeviceControls;
    CDUnknownBlockType m_logoutCallBackBlock;
    _Bool m_isNeedCallLoginWeb;
    unsigned int m_lastOnelineInfoFlag;
    MMOnlineSilentDownloadLogicController *_silentDownloadLogic;
}

@property(retain, nonatomic) MMOnlineSilentDownloadLogicController *silentDownloadLogic; // @synthesize silentDownloadLogic=_silentDownloadLogic;
- (void).cxx_destruct;
- (void)handleSilentDownloadFileList:(id)arg1;
- (id)GetBannerIcon;
- (void)markVoiceMsgAsReadWithMessage:(id)arg1;
- (void)handleMarkEnterpriseChatRead:(id)arg1;
- (void)handleQuitEnterpriseChat:(id)arg1;
- (void)handleEnterEnterpriseChat:(id)arg1;
- (void)handleMarkPatternLockUpdate:(id)arg1;
- (void)markPatternLockUpdate;
- (void)onManulLogOut;
- (void)onFontSizeChange;
- (void)onLanguageChange;
- (void)onKickQuit;
- (void)DidEnterForeground:(id)arg1;
- (void)DidEnterBackground:(id)arg1;
- (void)sendUnActiveRequest;
- (void)sendActiveRequest;
- (id)getSendActiveCGI;
- (_Bool)shoudlSendActiveCGI;
- (void)MessageReturn:(id)arg1 Event:(unsigned int)arg2;
- (_Bool)isNeedSyncChatname:(id)arg1;
- (void)onRemoteDeviceEnterSession:(id)arg1;
- (void)onRemoteDeviceQuitSession:(id)arg1;
- (void)onGetChatListResponsed:(id)arg1;
- (void)onGetEnterFunction:(id)arg1;
- (void)onGetQuitFunction:(id)arg1;
- (void)onGetMarkFunction:(id)arg1;
- (void)onGetNotifyUnlockFunction:(id)arg1;
- (void)onGetSendCommandFunction:(id)arg1;
- (void)onGetSyncEnd;
- (void)onNewSyncEnd;
- (void)onNewSyncSendCommand:(id)arg1;
- (void)onNewSyncNotifyUnlock:(id)arg1;
- (void)onNewSyncMarkFunction:(id)arg1;
- (void)onNewSyncQuitFunction:(id)arg1;
- (void)onNewSyncEnterFunction:(id)arg1;
- (void)onNewSyncChatListSession:(id)arg1;
- (void)onNewSyncOnlineStatus:(unsigned int)arg1 withVersion:(unsigned int)arg2;
- (void)onNewSyncQuitSession:(id)arg1;
- (void)onNewSyncEnterSession:(id)arg1;
- (void)onNewSyncGetAllChat;
- (void)getAllChat;
- (id)GetExtDeviceOnlineInfo;
- (_Bool)isExtDeviceLocked;
- (unsigned long long)GetExtDeviceControls;
- (id)GetOnlineClient;
- (id)GetSelfOnlineInfo;
- (id)GetOnlineSummaryForKey:(id)arg1;
- (id)GetOnlineSummary;
- (unsigned int)GetOnlineIconType;
- (void)statusNotifyGetChatListRequest;
- (void)checkExtdeviceControlsWithFlag:(unsigned int)arg1;
- (void)checkShouldIgnorePushOpenWithFlag:(unsigned int)arg1;
- (void)checkShouldAddFileHelperToTopWithFlag:(unsigned int)arg1;
- (void)checkShouldHideOnelineInfoBarWithFlag:(unsigned int)arg1;
- (void)checkExtDeviceOnlineStatusWithOnlineList:(id)arg1;
- (void)onGetOnlineInfoResponse:(id)arg1 newOnlineVersion:(unsigned int)arg2;
- (_Bool)createGetOnlineInfoEventWithNewOnlineVersion:(unsigned int)arg1;
- (void)GetOnlineInfoFromServerWithNewOnlineVersion:(unsigned int)arg1;
- (void)GetOnlineInfoFromServer;
- (void)handleMarkTimelineListRead:(id)arg1;
- (void)markTimelineListReadWithLastItemId:(id)arg1 itemCreateTime:(unsigned long long)arg2;
- (void)handleEnterWCMsgList:(id)arg1;
- (void)enterWCMsgListWithLastItemCreateTime:(unsigned long long)arg1;
- (void)setLastDeviceActiveMsg:(id)arg1;
- (void)onMarkMsgReadReturn:(id)arg1 withResponse:(id)arg2;
- (void)MarkChatRead:(id)arg1;
- (void)QuitChat:(id)arg1;
- (void)EnterChat:(id)arg1;
- (void)resetNeedCallLoginWeb;
- (_Bool)isNeedCallLoginWeb;
- (void)reloadBanner;
- (_Bool)isRunningAsBakDevice;
- (void)setIsNeedShowPush:(_Bool)arg1;
- (_Bool)isNeedShowPush;
- (void)logoutWeb:(_Bool)arg1 withCompletion:(CDUnknownBlockType)arg2;
- (_Bool)isLoginWebWX;
- (void)forceCheckIsLoginWebWX;
- (void)setAuthFlag:(unsigned long long)arg1;
- (unsigned int)genRandomClienMsgId;
- (void)dealloc;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

