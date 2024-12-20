//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class CBaseContact, CContact, CMessageWrap, LinkWeAppJumpWrap, MMUIViewController, NSArray, NSMutableArray, NSString, PushMailWrap, TranslateInfo;

@protocol MessageNodeViewDelegate <NSObject>

@optional
- (void)onVerifyFTSIndexForMsg:(CMessageWrap *)arg1;
- (void)onClickSourceView:(CMessageWrap *)arg1;
- (void)onClickMessageWrapOpenedWebViewUseFastLoad:(CMessageWrap *)arg1;
- (_Bool)isUseDefaultChatBkgImage;
- (void)onClickPlayMusicBtn:(CMessageWrap *)arg1 isPlay:(_Bool)arg2;
- (void)onClickFavMenu:(CMessageWrap *)arg1;
- (void)onClickVoiceTranslate:(CMessageWrap *)arg1;
- (void)onClickTextFloatPreView:(CMessageWrap *)arg1;
- (void)onClickTranslateMsg:(CMessageWrap *)arg1 translateInfo:(TranslateInfo *)arg2;
- (void)hideToolViewAnimated:(_Bool)arg1;
- (void)onEmoticonSourceTipClick;
- (void)hadShowNewXmlSystemMessage:(CMessageWrap *)arg1;
- (void)scheduleOnMsg:(CMessageWrap *)arg1;
- (void)clickNewAASysMsg:(NSString *)arg1 withMsgLocalID:(unsigned int)arg2;
- (void)shareMsgToOpenSDKByNodeView:(CMessageWrap *)arg1;
- (void)clickWeAppReceiveSessionMsg;
- (void)clickReceiveBrandMsg;
- (void)clickShieldBrandMsg;
- (void)clickLinkToDealWithSysXml:(CMessageWrap *)arg1 fromScene:(NSString *)arg2;
- (void)clickLinkToExpose;
- (void)onFullScreenWindowWillHide;
- (void)willShowMenuController:(id)arg1;
- (void)filterShowMenuItem:(NSMutableArray *)arg1 sender:(id)arg2;
- (_Bool)isMsgLastSend:(CMessageWrap *)arg1;
- (_Bool)isMsgCanRevoke:(CMessageWrap *)arg1;
- (void)revokeMsgByNodeView:(CMessageWrap *)arg1;
- (void)SetMsgPlayed:(CMessageWrap *)arg1;
- (void)switchEarMode;
- (void)jumpToUserProfile:(NSString *)arg1 Displayname:(NSString *)arg2 Scence:(unsigned int)arg3;
- (void)onHideKeyboard;
- (void)onMoreOperateWithMsgId:(NSString *)arg1;
- (void)onForwardMessageOK;
- (void)onMassSendSendAgain:(NSArray *)arg1;
- (void)onScrollToBottom;
- (void)tagWeAppLink:(LinkWeAppJumpWrap *)arg1 messageWrap:(CMessageWrap *)arg2;
- (void)tagLink:(NSString *)arg1 messageWrap:(CMessageWrap *)arg2;
- (MMUIViewController *)getViewController;
- (void)hasTapReaderNodeView;
- (void)longPressOnHeadImageForDebug:(CMessageWrap *)arg1;
- (_Bool)isMsgSelected:(CMessageWrap *)arg1;
- (void)longPressOnHeadImage:(CBaseContact *)arg1;
- (_Bool)canLongPressOnHeadImage:(CBaseContact *)arg1;
- (void)deleteNode:(CMessageWrap *)arg1;
- (void)StartDownloadVideo:(CMessageWrap *)arg1 DownloadMode:(unsigned long long)arg2;
- (void)StartDownloadVideo:(CMessageWrap *)arg1;
- (void)StartUploadVideo:(CMessageWrap *)arg1;
- (void)StopDownloadVideo:(CMessageWrap *)arg1;
- (void)StopUploadVideo:(CMessageWrap *)arg1;
- (void)onExposeTemplateMsg:(CMessageWrap *)arg1;
- (void)readerViewClickedWithMsg:(CMessageWrap *)arg1;
- (void)headerImageClickedWithMsg:(CMessageWrap *)arg1;
- (void)headerImageClicked:(CBaseContact *)arg1;
- (void)OnEndPlaying:(CMessageWrap *)arg1;
- (void)EndPlaying:(CMessageWrap *)arg1;
- (void)BeginPlaying:(CMessageWrap *)arg1 FromTouch:(_Bool)arg2;
- (void)PlayVideo:(CMessageWrap *)arg1 soundable:(_Bool)arg2;
- (void)tapAppNodeView:(id)arg1;
- (void)tapFriendCard_NodeView:(id)arg1 WithContact:(CContact *)arg2 WithMsg:(CMessageWrap *)arg3;
- (void)tapVideoStatus_NodeView:(id)arg1 DownloadMode:(unsigned long long)arg2;
- (void)tapPushMail_NodeView:(id)arg1 withPushMailWrap:(PushMailWrap *)arg2;
- (void)tapVideoStatus_NodeView:(id)arg1;
- (void)tapStatus_NodeView:(id)arg1;
- (void)tapLocation_NodeView:(id)arg1;
- (void)tapImage_NodeView:(id)arg1 needEditImage:(_Bool)arg2;
- (void)tapImage_NodeView:(id)arg1;
@end

