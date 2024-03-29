//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNRootViewController.h"

#import "CSinaWeiboLoginDelegate.h"
#import "QNMineHeaderDelegate.h"
#import "UIAlertViewDelegate.h"
#import "WeixinLoginDelegate.h"

@class NSString, QNMineHeaderView, QNMineTableView, QNNewUserTaskActivityHonorMedalView, QNPopBackgroundView, QNUserCenterTableViewInteractor, QNUserItem;

@interface QNMineViewController : QNRootViewController <QNMineHeaderDelegate, UIAlertViewDelegate, CSinaWeiboLoginDelegate, WeixinLoginDelegate>
{
    _Bool _reportedMessageCellExposure;
    _Bool _reportedContentPurchasedCellExposure;
    QNMineHeaderView *_headerView;
    QNUserItem *_userItem;
    double _mineHeaderHeight;
    QNPopBackgroundView *_popBgView;
    CDUnknownBlockType _loginCompleteCallBack;
    QNUserCenterTableViewInteractor *_tableViewInteractor;
    QNMineTableView *_tableView;
    QNNewUserTaskActivityHonorMedalView *_honerMedalView;
}

@property(retain, nonatomic) QNNewUserTaskActivityHonorMedalView *honerMedalView; // @synthesize honerMedalView=_honerMedalView;
@property(retain, nonatomic) QNMineTableView *tableView; // @synthesize tableView=_tableView;
@property(retain, nonatomic) QNUserCenterTableViewInteractor *tableViewInteractor; // @synthesize tableViewInteractor=_tableViewInteractor;
@property(copy, nonatomic) CDUnknownBlockType loginCompleteCallBack; // @synthesize loginCompleteCallBack=_loginCompleteCallBack;
@property(nonatomic) _Bool reportedContentPurchasedCellExposure; // @synthesize reportedContentPurchasedCellExposure=_reportedContentPurchasedCellExposure;
@property(nonatomic) _Bool reportedMessageCellExposure; // @synthesize reportedMessageCellExposure=_reportedMessageCellExposure;
@property(retain, nonatomic) QNPopBackgroundView *popBgView; // @synthesize popBgView=_popBgView;
@property(nonatomic) double mineHeaderHeight; // @synthesize mineHeaderHeight=_mineHeaderHeight;
@property(retain, nonatomic) QNUserItem *userItem; // @synthesize userItem=_userItem;
@property(retain, nonatomic) QNMineHeaderView *headerView; // @synthesize headerView=_headerView;
- (void).cxx_destruct;
- (void)p_refreshHeaderView;
- (void)refreshCurrentChannel;
- (void)loginSinaWeiboFinish:(long long)arg1;
- (void)qnMineUserInfoFooterMyPraiseClicked;
- (void)qnMineUserInfoFooterMyFunsClicked;
- (void)qnMineUserInfoFooterMyConcernClicked;
- (void)qnMineUserInfoFooterMyPublishClicked;
- (void)qnMineHeaderShareCardClicked;
- (void)qnMineHeaderSignReminderBtnClicked;
- (void)qnMineHeaderStarSignClicked;
- (void)qnMineHeaderOfflineBoxClicked;
- (void)p_loginSuccessfully;
- (void)p_loginViewFrom:(id)arg1;
- (void)qnMineHeaderFaceWeChatViewClicked;
- (void)qnMineHeaderFaceQQViewClicked;
- (void)qnMineHeaderFaceViewClicked;
- (void)p_handleMineLogout;
- (void)p_enterSettingPage;
- (void)p_handleMineCityAndStarChanged;
- (void)p_changeMineConfigMenu;
- (void)p_loadMineConfig;
- (void)p_loginStateChanged:(id)arg1;
- (void)p_userInfoItemStateChanged:(id)arg1;
- (void)p_restorageUserItemInfo;
- (void)p_pushSignScoreController;
- (void)p_authSuccessCallback;
- (void)p_getPersonalInfoAndRefreshHeaderView;
- (void)willComeInThisControllWithFromContorller:(id)arg1 changeType:(long long)arg2;
- (void)do_viewWillDestroy;
- (_Bool)shouldReleaseView;
- (void)getPersonInfoWithCompletion:(CDUnknownBlockType)arg1;
- (void)loginWeixinFinish:(_Bool)arg1 withBackType:(int)arg2;
- (void)d_weixinAuthSuccessCallback;
- (void)p_quickWeChatLoginWithCompleteCallBack:(CDUnknownBlockType)arg1;
- (void)p_quickQQLoginWithCompleteCallBack:(CDUnknownBlockType)arg1;
- (void)p_executeBlockAfterLogin:(CDUnknownBlockType)arg1;
- (void)setupHeaderView;
- (void)p_showRemindPointOnMineTabBarIfNeeded;
- (void)dealloc;
- (void)viewDidAppear:(_Bool)arg1;
- (void)viewDidDisappear:(_Bool)arg1;
- (void)viewWillAppear:(_Bool)arg1;
- (void)viewDidLoad;
- (void)p_handleRemindDataNotifications;
- (double)bottomInsetforMiniPlayerView;
- (_Bool)supportAttachMiniPlayerView;
- (id)getContentScrollView;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

