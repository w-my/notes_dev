//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "WCPayBaseViewController.h"

#import "ILinkEventExt.h"
#import "IdleTimerUtilExt.h"
#import "MMKernelExt.h"
#import "MMTipsViewControllerDelegate.h"
#import "UIAlertViewDelegate.h"
#import "UIGestureRecognizerDelegate.h"
#import "WCActionSheetDelegate.h"
#import "WCPayLogicMgrExt.h"
#import "WCPayNoticeBannerDelegate.h"
#import "WCPayOfflineAddNewCardTipsViewDelegate.h"
#import "WCPayOfflinePayCodeViewDelegate.h"
#import "WCPayOfflinePayCreateOffinePayTipsViewDelegate.h"
#import "WCPayOfflinePayInvalidCheckTipsViewDelegate.h"
#import "WCPayOfflinePayNoCodeTipsViewDelegate.h"
#import "WCPayOfflinePaySelectPayCardViewDelegate.h"
#import "WCPayPickerViewDelegate.h"
#import "WCPayWalletLockSettingLogicDelegate.h"
#import "WCPayWalletLockVerifyLogicDelegate.h"

@class MMUILabel, MMUIView, NSDictionary, NSObject<OS_dispatch_queue>, NSString, RichTextView, UIAttachmentBehavior, UIButton, UIDynamicAnimator, WCPayOfflinePayAddNewCardTipsView, WCPayOfflinePayBottomButton, WCPayOfflinePayCodeView, WCPayOfflinePayCreateOfflinePayTipsView, WCPayOfflinePayInvalidCheckTipsView, WCPayOfflinePayNoCodeTipsView, WCPayOfflinePaySelectPayCardView, WCPayPickerView, WCPayWebImageView, WCUIAlertView;

@interface WCPayOfflinePayViewController : WCPayBaseViewController <MMTipsViewControllerDelegate, WCPayOfflinePayCodeViewDelegate, UIGestureRecognizerDelegate, MMKernelExt, IdleTimerUtilExt, WCPayNoticeBannerDelegate, WCPayOfflinePayInvalidCheckTipsViewDelegate, WCPayOfflinePaySelectPayCardViewDelegate, WCPayOfflineAddNewCardTipsViewDelegate, WCPayOfflinePayCreateOffinePayTipsViewDelegate, WCPayOfflinePayNoCodeTipsViewDelegate, WCPayWalletLockVerifyLogicDelegate, WCPayWalletLockSettingLogicDelegate, WCActionSheetDelegate, ILinkEventExt, UIAlertViewDelegate, WCPayPickerViewDelegate, WCPayLogicMgrExt>
{
    id <WCPayOfflinePayViewControllerDelegate> m_delegate;
    _Bool m_bFreezeAlertShowed;
    _Bool m_bReadAgreement;
    UIButton *footerButton;
    RichTextView *m_cardInfoLabel;
    WCPayOfflinePayCodeView *m_PayOfflinePayCodeView;
    int m_enCurrentOfflinePayCodeDisplayScene;
    double _oldBrightness;
    WCPayPickerView *m_pickerView;
    WCPayWebImageView *_bankIcon;
    WCPayOfflinePayBottomButton *_changeCardBtn;
    NSString *_cacheCode;
    NSObject<OS_dispatch_queue> *_cacheQueue;
    _Bool _isRefreshing;
    _Bool _triggeredGetToken;
    UIAttachmentBehavior *_attachment;
    MMUIView *_cardInfoView;
    NSDictionary *m_dicBanners;
    double bannerHeight;
    _Bool _isViewDidAppear;
    _Bool _bNeedUpdateCodeView;
    _Bool _bRefreshFromCreateOfflinePay;
    _Bool _isPatternLockShowing;
    _Bool _bHasCheckFirstTips;
    _Bool _bIsAllCardNotSupportOfflinePay;
    _Bool _bIsShowingAddNewCardTipsView;
    _Bool _bNeedShowNoCodeTipsView;
    _Bool _bIsNavigateToReceiveLogic;
    _Bool _bNeedShowReCreateOfflinePayTipsView;
    _Bool _bIsFirstRefresh;
    int _entryScene;
    unsigned int _patternLockLogicTag;
    UIDynamicAnimator *_animator;
    WCUIAlertView *_snapshotAlertView;
    WCPayOfflinePayInvalidCheckTipsView *_invalidTipsView;
    WCPayOfflinePaySelectPayCardView *_selectCardView;
    WCPayOfflinePayAddNewCardTipsView *_addNewCardTipsView;
    WCPayOfflinePayCreateOfflinePayTipsView *_createOfflinePayTipsView;
    WCPayOfflinePayNoCodeTipsView *_noCodeTipsView;
    MMUIView *_actionBarView;
    MMUILabel *_bankNameLabel;
    MMUILabel *_bankDescLabel;
    MMUILabel *_bankForbidWordLabel;
    MMUIView *_headerContentView;
}

@property(retain, nonatomic) MMUIView *headerContentView; // @synthesize headerContentView=_headerContentView;
@property(retain, nonatomic) MMUILabel *bankForbidWordLabel; // @synthesize bankForbidWordLabel=_bankForbidWordLabel;
@property(retain, nonatomic) MMUILabel *bankDescLabel; // @synthesize bankDescLabel=_bankDescLabel;
@property(retain, nonatomic) MMUILabel *bankNameLabel; // @synthesize bankNameLabel=_bankNameLabel;
@property(nonatomic) _Bool bIsFirstRefresh; // @synthesize bIsFirstRefresh=_bIsFirstRefresh;
@property(retain, nonatomic) MMUIView *actionBarView; // @synthesize actionBarView=_actionBarView;
@property(nonatomic) _Bool bNeedShowReCreateOfflinePayTipsView; // @synthesize bNeedShowReCreateOfflinePayTipsView=_bNeedShowReCreateOfflinePayTipsView;
@property(nonatomic) _Bool bIsNavigateToReceiveLogic; // @synthesize bIsNavigateToReceiveLogic=_bIsNavigateToReceiveLogic;
@property(nonatomic) _Bool bNeedShowNoCodeTipsView; // @synthesize bNeedShowNoCodeTipsView=_bNeedShowNoCodeTipsView;
@property(retain, nonatomic) WCPayOfflinePayNoCodeTipsView *noCodeTipsView; // @synthesize noCodeTipsView=_noCodeTipsView;
@property(retain, nonatomic) WCPayOfflinePayCreateOfflinePayTipsView *createOfflinePayTipsView; // @synthesize createOfflinePayTipsView=_createOfflinePayTipsView;
@property(nonatomic) _Bool bIsShowingAddNewCardTipsView; // @synthesize bIsShowingAddNewCardTipsView=_bIsShowingAddNewCardTipsView;
@property(retain, nonatomic) WCPayOfflinePayAddNewCardTipsView *addNewCardTipsView; // @synthesize addNewCardTipsView=_addNewCardTipsView;
@property(nonatomic) _Bool bIsAllCardNotSupportOfflinePay; // @synthesize bIsAllCardNotSupportOfflinePay=_bIsAllCardNotSupportOfflinePay;
@property(retain, nonatomic) WCPayOfflinePaySelectPayCardView *selectCardView; // @synthesize selectCardView=_selectCardView;
@property(retain, nonatomic) WCPayOfflinePayInvalidCheckTipsView *invalidTipsView; // @synthesize invalidTipsView=_invalidTipsView;
@property(nonatomic) _Bool bHasCheckFirstTips; // @synthesize bHasCheckFirstTips=_bHasCheckFirstTips;
@property(retain, nonatomic) WCUIAlertView *snapshotAlertView; // @synthesize snapshotAlertView=_snapshotAlertView;
@property(nonatomic) _Bool isPatternLockShowing; // @synthesize isPatternLockShowing=_isPatternLockShowing;
@property(nonatomic) unsigned int patternLockLogicTag; // @synthesize patternLockLogicTag=_patternLockLogicTag;
@property(retain, nonatomic) UIDynamicAnimator *animator; // @synthesize animator=_animator;
@property(nonatomic) _Bool bRefreshFromCreateOfflinePay; // @synthesize bRefreshFromCreateOfflinePay=_bRefreshFromCreateOfflinePay;
@property(nonatomic) _Bool bNeedUpdateCodeView; // @synthesize bNeedUpdateCodeView=_bNeedUpdateCodeView;
@property(nonatomic) _Bool isViewDidAppear; // @synthesize isViewDidAppear=_isViewDidAppear;
@property(nonatomic) int entryScene; // @synthesize entryScene=_entryScene;
- (void).cxx_destruct;
- (void)onClickTipsBtn:(id)arg1 Index:(long long)arg2;
- (void)viewCotnrollerDidBecomeActive:(id)arg1;
- (void)OnGetT2BCEntryMsg;
- (void)wcPayOfflinePayNoCodeTipsViewClickRefreshBtn;
- (void)hideNoCodeTipsView;
- (void)showNoCodeTipsView:(id)arg1;
- (void)showNoCodeTipsView;
- (void)wcPayOfflinePayCreateOffinePayViewClickSafeTips;
- (void)wcPayOfflinePayCreateOffinePayViewClickConfirmBtn;
- (void)showReCreateOfflinePayTipsView;
- (void)showCreateOfflinePayTipsView;
- (void)wcPayOfflineAddNewCardTipsViewClickViewPayCardBtn;
- (void)wcPayOfflineAddNewCardTipsViewClickAddCardBtn;
- (id)wcPayOfflineAddNewCardTipsViewGetTipsTitleContent;
- (void)hideAddNewCardTipsView;
- (void)showAddNewCardTipsView;
- (void)onSelectPayCardViewClickForbidUrl:(id)arg1;
- (void)onSelectPayCardViewReturnWithNewSelectCardBindSerial:(id)arg1;
- (void)onSelectPayCardViewCancel;
- (void)wcPayOfflinePayInvalidCheckViewClickViewDetailLink;
- (void)wcPayOfflinePayInvalidCheckViewClickConfirmBtn;
- (void)initInvalidTipsView;
- (void)hideInvalidTipsView;
- (void)showInvalidTipsView;
- (void)checkAndShowFirstTips;
- (void)userDidTakeScreenshot:(id)arg1;
- (id)getNoticeBanner;
- (void)banner:(id)arg1 clickWithUrl:(id)arg2;
- (float)tipsViewContentHeight;
- (float)cardInfoContentHeight;
- (float)topMarginOfTipView;
- (void)onIdleTimerUtilVoipQuit;
- (void)patternLockDidSetup:(id)arg1;
- (void)touchLockDidSetup:(id)arg1;
- (void)walletLockDidClose:(id)arg1;
- (_Bool)walletLockVerifyLogicNeedBlock:(id)arg1;
- (void)walletLockVerifySuccess:(id)arg1;
- (void)onApplicationWillEnterForeground:(id)arg1;
- (void)motionEnded:(long long)arg1 withEvent:(id)arg2;
- (void)wcPayOfflinePayCodeViewClickViewBarCodeBtn;
- (void)wcPayOfflinePayCodeViewAutoRefreshCountingFinished:(id)arg1;
- (void)wcPayOfflinePayCodeViewExitFullScreenAnimationFinished:(id)arg1;
- (void)onKickQuit;
- (void)OnGetReceiveOrPayReddotData;
- (void)OnOfflinePayTokenInfoUpdated:(_Bool)arg1;
- (void)OnShouldChangePayCardError:(id)arg1 ErrorType:(unsigned int)arg2;
- (void)onOffPayPauseAlertViewBtnClick;
- (void)OnQueryOfflinePayLimit:(id)arg1 fromCache:(_Bool)arg2 Error:(id)arg3;
- (void)OnGetBarCodeFromQRCodeResponse:(id)arg1 Error:(id)arg2;
- (void)onUserChooseCardForOfflinePay:(id)arg1;
- (void)onChooseCardIndex:(long long)arg1;
- (void)onCloseOfflinePay;
- (void)clearOfflinePayAndPopWithoutAlert;
- (void)increaseBrightnessIfNeed;
- (id)bankLogoUrlStrFromType:(id)arg1;
- (id)currentCardInfoShouldUse;
- (void)WCPayPickerViewDidChooseRowTitle:(id)arg1 atSessionTitle:(id)arg2;
- (void)WCPayPickerViewDidChooseRow:(long long)arg1 atSession:(long long)arg2;
- (void)OnShouldChangeCard:(id)arg1;
- (void)onLinkClicked:(id)arg1 withRect:(struct CGRect)arg2;
- (_Bool)needShowBottomBusinessEntry;
- (id)getOfflinePayHelpUrl;
- (_Bool)checkIfAllCardCannotUseForOfflinePay;
- (void)preLoadTokensIfNeed;
- (void)scrollContentToBottom;
- (void)removeButtonRedDot:(id)arg1;
- (void)transferToBankCardBtnPress:(id)arg1;
- (void)qrcoderewardBtnPress:(id)arg1;
- (void)f2fHongBaoBtnPress:(id)arg1;
- (void)grouppayBtnPress:(id)arg1;
- (void)receiveMoneyBtnPress:(id)arg1;
- (void)updateCodeImageAndStartAutomaticUpdate;
- (void)exitFullScreenIfNeedAnimation:(_Bool)arg1;
- (void)onClickedReadSupportBanks;
- (void)setDelegate:(id)arg1;
- (void)alertView:(id)arg1 didDismissWithButtonIndex:(long long)arg2;
- (void)alertView:(id)arg1 clickedButtonAtIndex:(long long)arg2;
- (void)actionSheet:(id)arg1 clickedButtonAtIndex:(long long)arg2;
- (_Bool)preViewControllerIsKindOf:(Class)arg1;
- (void)onReadAgreement:(id)arg1;
- (void)onMoreAction:(id)arg1;
- (void)onSettingAction:(id)arg1;
- (void)Operate;
- (void)changeCodeScene;
- (void)updateCodeInNewWayWithTips:(_Bool)arg1;
- (void)updateCodeInNewWay;
- (void)updateCodeImage;
- (void)UpdateQRCodeImage;
- (void)UpdateBarCodeImage;
- (void)reloadTableView;
- (void)refreshViewWithData:(id)arg1;
- (void)setupWCPayLogo;
- (void)setupChangeCardViewWithShouldChangeHeaderViewHeight:(_Bool)arg1;
- (id)createPayCodeView;
- (id)genBottomButtonWithTitle:(id)arg1 actionSelector:(SEL)arg2 logoImg:(id)arg3 buttonSize:(struct CGSize)arg4 bIsFirstBtn:(_Bool)arg5 bIsLastBtn:(_Bool)arg6 bNeedShowRedDot:(_Bool)arg7 reddotshowWording:(id)arg8;
- (void)setupBottomButtonView;
- (id)getActionBarView;
- (void)setupHeaderContentView;
- (void)OnOfflinePayCancelPosNotification:(id)arg1;
- (void)viewDidTransitionToNewSize;
- (void)viewDidDisappear:(_Bool)arg1;
- (void)willDisappear;
- (void)willAppear;
- (void)viewWillDisappear:(_Bool)arg1;
- (void)doBackForTimeout;
- (void)viewDidAppear:(_Bool)arg1;
- (void)adjustSubviewRects;
- (void)viewDidBePoped:(_Bool)arg1;
- (void)viewDidLoad;
- (void)onClickLeftBarButton;
- (id)navigationBarBackgroundColor;
- (id)init;
- (void)dealloc;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
