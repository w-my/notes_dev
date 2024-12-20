//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "WCPayBaseViewController.h"

#import "WCPaySelectVerifyTypeViewV2Delegate.h"

@class GetRealnameWordingRsp, InternalTask, NSString, UIButton, UIImageView, UILabel, UIView, WCPayJumpRemindControlLogic, WCPayJumpRemindInfo, WCPaySelectVerifyTypeViewV2;

@interface WCPaySelectVerifyTypeViewController : WCPayBaseViewController <WCPaySelectVerifyTypeViewV2Delegate>
{
    id <WCPaySelectVerifyTypeViewControllerDelegate> m_delegate;
    NSString *bindCardTitle;
    NSString *bindCardSubTitle;
    NSString *bindIdTitle;
    NSString *bindIdSubTitle;
    NSString *extralWording;
    _Bool questionAnswerSwitch;
    NSString *questionAnswerUrl;
    _Bool isShowBindCard;
    _Bool isShowRealnameVerify;
    _Bool isShowBindCardVerify;
    NSString *bindCardVerifyTitle;
    NSString *bindCardVerifySubTitle;
    _Bool isNeedShowBindCardVerifyAlertView;
    NSString *bindCardVeifyAlertViewRightButtonText;
    NSString *bindCardVeifyAlertViewContent;
    GetRealnameWordingRsp *_wording;
    InternalTask *_m_internalTask;
    WCPayJumpRemindInfo *_jumpRemindInfo;
    WCPayJumpRemindControlLogic *_jumpRemindControlLogic;
    UIImageView *_m_iconForSafeTips;
    UIButton *_m_buttonForSafeTips;
    UIImageView *_m_arrowForSafeTips;
    UIView *_m_safeTipsBase;
    UILabel *_m_titleLabel;
    WCPaySelectVerifyTypeViewV2 *_layoutV2;
}

@property(retain) WCPaySelectVerifyTypeViewV2 *layoutV2; // @synthesize layoutV2=_layoutV2;
@property(retain, nonatomic) UILabel *m_titleLabel; // @synthesize m_titleLabel=_m_titleLabel;
@property(retain, nonatomic) UIView *m_safeTipsBase; // @synthesize m_safeTipsBase=_m_safeTipsBase;
@property(retain, nonatomic) UIImageView *m_arrowForSafeTips; // @synthesize m_arrowForSafeTips=_m_arrowForSafeTips;
@property(retain, nonatomic) UIButton *m_buttonForSafeTips; // @synthesize m_buttonForSafeTips=_m_buttonForSafeTips;
@property(retain, nonatomic) UIImageView *m_iconForSafeTips; // @synthesize m_iconForSafeTips=_m_iconForSafeTips;
@property(retain, nonatomic) WCPayJumpRemindControlLogic *jumpRemindControlLogic; // @synthesize jumpRemindControlLogic=_jumpRemindControlLogic;
@property(retain, nonatomic) WCPayJumpRemindInfo *jumpRemindInfo; // @synthesize jumpRemindInfo=_jumpRemindInfo;
@property(retain, nonatomic) InternalTask *m_internalTask; // @synthesize m_internalTask=_m_internalTask;
@property(retain, nonatomic) GetRealnameWordingRsp *wording; // @synthesize wording=_wording;
- (void).cxx_destruct;
- (id)onWCPaySelectVerifyTypeViewV2TableViewInfo;
- (void)onWCPaySelectVerifyTypeViewV2ClickRealName;
- (void)onWCPaySelectVerifyTypeViewV2ClickSafeTips;
- (id)navigationBarBackgroundColor;
- (void)clickSafeTips;
- (void)adjustBottomTips;
- (void)updateArrowForSafeTips;
- (void)updateButtonForSafeTips;
- (void)updateIconForSafeTips;
- (void)updateSafeTipsBase;
- (void)onWCPayPrivacyViewControllerClickAgree:(_Bool)arg1;
- (void)onRightBarButtonClick;
- (void)populateData:(id)arg1;
- (void)getWording;
- (void)realSelectBindCardVerify;
- (void)onContinueSelectBindCardVerify;
- (void)selectBindCardVerify;
- (void)realSelectRealnameVerify;
- (void)onContinueSelectRealnameVerify;
- (void)selectRealnameVerify;
- (void)realSelectBindCard;
- (void)onContinueSelectBindCard;
- (void)selectBindCard;
- (void)makeSelectBindCardVerifyCell:(id)arg1;
- (void)makeSelectRealnameVerifyCell:(id)arg1;
- (void)makeSelectBindCardCell:(id)arg1;
- (id)createDotLabel;
- (id)headerView;
- (void)setDelegate:(id)arg1;
- (void)OnBack;
- (void)reloadTableView;
- (void)viewWillBePresented:(_Bool)arg1;
- (void)viewWillBePushed:(_Bool)arg1;
- (void)viewDidLayoutSubviews;
- (void)didReceiveMemoryWarning;
- (void)dealloc;
- (void)viewDidDisappear:(_Bool)arg1;
- (void)viewDidLoad;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

