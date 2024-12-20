//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "FileDetailLogicController.h"

#import "IEnterpriseMsgExt.h"
#import "IMsgExt.h"
#import "IMsgRevokeExt.h"
#import "MMAppAttachFileMgrExt.h"

@class CMessageWrap, NSString, ShareDataToOpenSDKController;

@interface MsgFileDetailLogicController : FileDetailLogicController <IMsgExt, IEnterpriseMsgExt, IMsgRevokeExt, MMAppAttachFileMgrExt>
{
    CMessageWrap *m_wrapMsg;
    NSString *m_nsUsrName;
    _Bool m_bFileExpired;
    _Bool m_bRegister;
    _Bool m_bDownloading;
    _Bool m_bHasRevoke;
    _Bool m_bIsFileExistInSvr;
    ShareDataToOpenSDKController *m_shareOpenSDKController;
    id <AppDetailDelegate> _m_delegate;
}

@property(nonatomic) __weak id <AppDetailDelegate> m_delegate; // @synthesize m_delegate=_m_delegate;
@property(retain, nonatomic) CMessageWrap *m_wrapMsg; // @synthesize m_wrapMsg;
- (void).cxx_destruct;
- (void)presentMinimizeViewController:(id)arg1 key:(id)arg2;
- (id)getLastViewControllerOnLeaveTaskBeforeEnterAnother:(id)arg1;
- (_Bool)isMinimizeEnable;
- (id)getMinimizeTaskData;
- (_Bool)configWithMinimizeData:(id)arg1;
- (void)handleModMsg:(id)arg1 MsgWrap:(id)arg2;
- (void)OnMsgDownloadAppAttachExpiredFail:(id)arg1 MsgWrap:(id)arg2;
- (void)OnModMsg:(id)arg1 MsgWrap:(id)arg2;
- (void)OnModEnterpriseMsg:(id)arg1 Brand:(id)arg2 WrapMsg:(id)arg3;
- (void)OnMsgRevoked:(id)arg1 n64MsgId:(long long)arg2;
- (void)onCheckAppAttachRet:(id)arg1 isExistInSvr:(_Bool)arg2 taskInfo:(id)arg3;
- (int)getFileExpiredDays;
- (void)shareToFriend;
- (unsigned long long)GetTempSize;
- (id)GetTmpFilePath;
- (id)GetFilePath;
- (id)GetFileName;
- (unsigned long long)GetFileSize;
- (id)GetForwardData;
- (unsigned int)GetPreviewType;
- (_Bool)canAddToFavorites;
- (_Bool)performCustomizeAction:(id)arg1;
- (void)customizeActionsForActionSheet:(id)arg1;
- (_Bool)canShowMsgForwardTo3rdApp;
- (_Bool)forbidOperation;
- (_Bool)autoDownload;
- (_Bool)isDownloading;
- (void)onApplyToWebRecommend;
- (void)onApplyToWAS;
- (void)onApplyToFTS;
- (void)OnOpenByOtherAppWithHasOpen:(_Bool)arg1;
- (void)OnOpened;
- (void)OnForwardTo3rdApp:(id)arg1;
- (void)OnAddToFavorites;
- (_Bool)OnPreviewFile:(unsigned int)arg1;
- (void)openInDiskUsageDetailViewController;
- (void)symbolicateAndForward;
- (void)OnForwordWithViewController:(id)arg1;
- (void)checkIsFileExistInSvr;
- (void)stopDownload;
- (void)startDownload;
- (void)tryRegister;
- (void)dealloc;
- (void)commonInitWithMsg:(id)arg1 userName:(id)arg2;
- (id)initWithMsgWrap:(id)arg1 userName:(id)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

