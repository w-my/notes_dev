//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMUIViewController.h"

#import "ContactInfoAssistDelegate.h"
#import "FavClickStreamHelperDelegete.h"
#import "ForwardMessageLogicDelegate.h"
#import "ICertInfoMgrExt.h"
#import "IContactMgrExt.h"
#import "IExtraDeviceLoginMgrExt.h"
#import "IHDHeadImageViewExt.h"
#import "IStrangerContactMgrExt.h"
#import "IUpdateProfileMgrExt.h"
#import "MMSayHelloViewControllerDelegate.h"
#import "PBMessageObserverDelegate.h"
#import "UIAlertViewDelegate.h"
#import "VerifyPhoneDelegate.h"
#import "WCFacadeExt.h"
#import "WCStoryFacadeExt.h"
#import "WCStorysPreviewViewControllerDelegate.h"

@class BrandProfileEnterInfo, CBaseContactInfoAssist, CContact, CContactVerifyLogic, CMessageWrap, FavClickStreamHelper, ForwardMessageLogicController, MMUIButton, MMUILabel, MMUIView, NSMutableDictionary, NSString, SendVerifyMsgLogicController, UIButton, UITableView, WCStoryDataItem, WCStoryDragAnimationUtil, WCStorysPreviewViewController;

@interface ContactInfoViewController : MMUIViewController <ForwardMessageLogicDelegate, WCStorysPreviewViewControllerDelegate, WCStoryFacadeExt, IExtraDeviceLoginMgrExt, UIAlertViewDelegate, PBMessageObserverDelegate, ContactInfoAssistDelegate, IContactMgrExt, VerifyPhoneDelegate, MMSayHelloViewControllerDelegate, ICertInfoMgrExt, WCFacadeExt, IStrangerContactMgrExt, IUpdateProfileMgrExt, IHDHeadImageViewExt, FavClickStreamHelperDelegete>
{
    unsigned int m_uiVerify;
    CContact *m_contact;
    CContact *m_chatContact;
    id <contactInfoDelegate> m_delegate;
    id <ContactInfoViewControllerDelegate> m_InfoDelegate;
    CBaseContactInfoAssist *m_oContactInfoAssist;
    CContactVerifyLogic *m_contactVerifyLogic;
    NSString *m_nsLocation;
    _Bool m_bPopToRootWhenDelete;
    unsigned int m_uiFromScene;
    int m_wcOperateMode;
    Class m_popToViewControllerClassWhenDelete;
    int m_searchScene;
    id m_userData;
    FavClickStreamHelper *m_clickHelper;
    double m_CurrentWidth;
    ForwardMessageLogicController *m_forwardLogic;
    unsigned int _startTime;
    SendVerifyMsgLogicController *m_sendVerifylogicVC;
    _Bool _isFullScreenShowStory;
    _Bool _hasStoryData;
    _Bool _canShowStoryView;
    _Bool _isShowingStoryPreview;
    int m_uiAddFriendStatScene;
    int _m_qrCodeAddFriendScene;
    unsigned int _searchFromIndex;
    unsigned int _favId;
    NSMutableDictionary *_verifyUserInfoList;
    NSString *_searchId;
    NSString *_searchKeyword;
    NSString *_searchExtraParamsString;
    CMessageWrap *_sourceMsg;
    NSString *_reportInfo;
    BrandProfileEnterInfo *_bpeInfo;
    WCStorysPreviewViewController *_storyPreviewVC;
    UIButton *_preiviewMaskView;
    MMUIButton *_contactFrontView;
    WCStoryDragAnimationUtil *_storyAnimationUtil;
    MMUIView *_frontTableViewBackGroundView;
    UITableView *_frontTableView;
    double _lastMovement;
    double _previewPositionY;
    WCStoryDataItem *_lastDataItem;
    MMUILabel *_firstDragDownTipLabel;
}

@property(retain, nonatomic) MMUILabel *firstDragDownTipLabel; // @synthesize firstDragDownTipLabel=_firstDragDownTipLabel;
@property(retain, nonatomic) WCStoryDataItem *lastDataItem; // @synthesize lastDataItem=_lastDataItem;
@property(nonatomic) _Bool isShowingStoryPreview; // @synthesize isShowingStoryPreview=_isShowingStoryPreview;
@property(nonatomic) double previewPositionY; // @synthesize previewPositionY=_previewPositionY;
@property(nonatomic) double lastMovement; // @synthesize lastMovement=_lastMovement;
@property(nonatomic) __weak UITableView *frontTableView; // @synthesize frontTableView=_frontTableView;
@property(retain, nonatomic) MMUIView *frontTableViewBackGroundView; // @synthesize frontTableViewBackGroundView=_frontTableViewBackGroundView;
@property(nonatomic) _Bool canShowStoryView; // @synthesize canShowStoryView=_canShowStoryView;
@property(nonatomic) _Bool hasStoryData; // @synthesize hasStoryData=_hasStoryData;
@property(nonatomic) _Bool isFullScreenShowStory; // @synthesize isFullScreenShowStory=_isFullScreenShowStory;
@property(retain, nonatomic) WCStoryDragAnimationUtil *storyAnimationUtil; // @synthesize storyAnimationUtil=_storyAnimationUtil;
@property(retain, nonatomic) MMUIButton *contactFrontView; // @synthesize contactFrontView=_contactFrontView;
@property(retain, nonatomic) UIButton *preiviewMaskView; // @synthesize preiviewMaskView=_preiviewMaskView;
@property(retain, nonatomic) WCStorysPreviewViewController *storyPreviewVC; // @synthesize storyPreviewVC=_storyPreviewVC;
@property(retain, nonatomic) BrandProfileEnterInfo *bpeInfo; // @synthesize bpeInfo=_bpeInfo;
@property(nonatomic) unsigned int favId; // @synthesize favId=_favId;
@property(retain, nonatomic) NSString *reportInfo; // @synthesize reportInfo=_reportInfo;
@property(retain, nonatomic) CMessageWrap *sourceMsg; // @synthesize sourceMsg=_sourceMsg;
@property(retain, nonatomic) NSString *searchExtraParamsString; // @synthesize searchExtraParamsString=_searchExtraParamsString;
@property(nonatomic) unsigned int searchFromIndex; // @synthesize searchFromIndex=_searchFromIndex;
@property(retain, nonatomic) NSString *searchKeyword; // @synthesize searchKeyword=_searchKeyword;
@property(retain, nonatomic) NSString *searchId; // @synthesize searchId=_searchId;
@property(retain, nonatomic) NSMutableDictionary *verifyUserInfoList; // @synthesize verifyUserInfoList=_verifyUserInfoList;
@property(nonatomic) int m_qrCodeAddFriendScene; // @synthesize m_qrCodeAddFriendScene=_m_qrCodeAddFriendScene;
@property(nonatomic) int m_uiAddFriendStatScene; // @synthesize m_uiAddFriendStatScene;
@property(retain, nonatomic) id m_userData; // @synthesize m_userData;
@property(nonatomic) int m_searchScene; // @synthesize m_searchScene;
@property(nonatomic) Class m_popToViewControllerClassWhenDelete; // @synthesize m_popToViewControllerClassWhenDelete;
@property(nonatomic) unsigned int m_uiFromScene; // @synthesize m_uiFromScene;
@property(nonatomic) _Bool m_bPopToRootWhenDelete; // @synthesize m_bPopToRootWhenDelete;
@property(retain, nonatomic) NSString *m_nsLocation; // @synthesize m_nsLocation;
@property(nonatomic) unsigned int m_uiVerify; // @synthesize m_uiVerify;
@property(nonatomic) __weak id <ContactInfoViewControllerDelegate> m_InfoDelegate; // @synthesize m_InfoDelegate;
@property(nonatomic) __weak id <contactInfoDelegate> m_delegate; // @synthesize m_delegate;
@property(retain, nonatomic) CContact *m_chatContact; // @synthesize m_chatContact;
@property(retain, nonatomic) CContact *m_contact; // @synthesize m_contact;
- (void).cxx_destruct;
- (void)onExtraDeviceLoginClose;
- (void)onAssistTableViewIntroViewClick;
- (void)scrollViewDidScroll:(id)arg1;
- (void)tapTopCoverArea;
- (void)layoutStoryViewWithStoryDataItem:(id)arg1;
- (id)sessionId;
- (void)WCStorysPreviewViewControllerDeleteAllDataItem:(id)arg1;
- (void)WCStorysPreviewViewControllerShowFrontViewWithAnimated:(_Bool)arg1;
- (void)WCStorysPreviewViewControllerDidPanInVerticalWithTouchPoint:(struct CGPoint)arg1 andState:(long long)arg2;
- (id)navigationBarBackgroundColor;
- (void)reportEnter;
- (_Bool)shouldInteractivePop;
- (_Bool)isSeachActive;
- (void)onHDHeadImageWillDisappear;
- (void)onHDHeadImageWillAppear;
- (void)MessageReturn:(id)arg1 Event:(unsigned int)arg2;
- (void)onExpose;
- (void)confirmExpose:(unsigned int)arg1;
- (void)onSayHelloViewSendSayHello:(id)arg1;
- (void)statBanner;
- (void)onVerifyOK;
- (void)onAddToContact;
- (void)onSendVerifyMsg;
- (void)onSayHello;
- (void)bindPhoneReturn;
- (void)onDeleteContact:(id)arg1;
- (void)delAllMsg;
- (void)onVerifyOKWithContact:(id)arg1;
- (void)onModifyContact:(id)arg1;
- (void)onStrangerContactUpdated:(id)arg1 Contact:(id)arg2;
- (void)copyContactField:(id)arg1 toContact:(id)arg2;
- (void)onProfileChange;
- (void)dealloc;
- (void)onWCGroupRemoveMemberReturn:(_Bool)arg1 group:(id)arg2;
- (void)onWCGroupAddMemberReturn:(_Bool)arg1 group:(id)arg2;
- (void)onWCGroupModMemberReturn:(_Bool)arg1 group:(id)arg2;
- (id)getSearchId;
- (id)getContactVerifyLogic;
- (void)onRemoveContact;
- (void)onPopViewController:(_Bool)arg1;
- (void)onTalk:(id)arg1;
- (_Bool)onFilterSendReceiver:(id)arg1;
- (id)getCurrentViewController;
- (void)onShareMyFriend;
- (void)storyDataItemsChanged:(_Bool)arg1;
- (void)onTableViewReload;
- (id)getViewController;
- (void)stopLoadingWithFailText:(id)arg1;
- (void)stopLoadingWithOKText:(id)arg1;
- (void)startLoadingWithText:(id)arg1;
- (void)onNewMessageWithPushOnTop:(id)arg1;
- (void)onNewMessage:(id)arg1;
- (void)jumpToContentViewController:(id)arg1;
- (void)doReset:(id)arg1;
- (void)contactVerifyOk:(id)arg1;
- (void)onFriendRequestSend;
- (int)sourceSceneForReport;
- (void)reportPageStayTimeWithPluginType:(int)arg1;
- (void)checkNeedForcedUpdateForMemberDetail;
- (void)viewDidBePushed:(_Bool)arg1;
- (void)viewWillBePoped:(_Bool)arg1;
- (void)showFrontViewInNoStoryState;
- (void)processFrontViewGestureInNoStoryState:(id)arg1;
- (void)panGestureRecognize:(id)arg1;
- (_Bool)gestureRecognizer:(id)arg1 shouldReceiveTouch:(id)arg2;
- (void)wrapFrontView;
- (void)setupStoryView;
- (void)setupTouchSpringAnimation;
- (void)setupNoStoryView;
- (void)viewDidLoad;
- (void)viewDidLayoutSubviews;
- (void)viewWillLayoutSubviews;
- (void)updateContactFromServer;
- (void)reloadContactAssist;
- (id)tagForCurrentPage;
- (id)tagForActivePage;
- (void)viewWillDisappear:(_Bool)arg1;
- (void)viewDidDisappear:(_Bool)arg1;
- (void)viewWillAppear:(_Bool)arg1;
- (void)viewDidAppear:(_Bool)arg1;
- (void)reloadView;
- (void)reloadFloatView;
- (_Bool)getHasStoryDataFlag;
- (id)getUserData;
- (void)reloadData;
- (void)initSystemPluginData:(int)arg1;
- (_Bool)isInMyContactList;
- (_Bool)useBlackStatusbar;
- (id)initWithTitle:(id)arg1;
- (id)init;
- (unsigned int)GetFromScene;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

