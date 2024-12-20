//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "WCPayBaseViewController.h"

#import "ILinkEventExt.h"

@class NSString, RichTextView, UIButton, UITextField, WCUIAlertView;

@interface WCPayFacingReceiveFixedAmountViewController : WCPayBaseViewController <ILinkEventExt>
{
    id <WCPayFacingReceiveFixedAmountViewControllerDelegate> m_delegate;
    NSString *_remark;
    NSString *_moneyString;
    UITextField *_feeTextField;
    RichTextView *_commentTextView;
    UIButton *_footerBtn;
    WCUIAlertView *_alertView;
}

@property(retain, nonatomic) WCUIAlertView *alertView; // @synthesize alertView=_alertView;
@property(retain, nonatomic) UIButton *footerBtn; // @synthesize footerBtn=_footerBtn;
@property(retain, nonatomic) RichTextView *commentTextView; // @synthesize commentTextView=_commentTextView;
@property(retain, nonatomic) UITextField *feeTextField; // @synthesize feeTextField=_feeTextField;
@property(retain, nonatomic) NSString *moneyString; // @synthesize moneyString=_moneyString;
@property(retain, nonatomic) NSString *remark; // @synthesize remark=_remark;
- (void).cxx_destruct;
- (void)remarkCancel;
- (void)remarkConfirm;
- (void)onLinkClicked:(id)arg1 withRect:(struct CGRect)arg2;
- (void)textFieldDidChange;
- (void)onNext;
- (void)FillSaveMoneyCancel;
- (void)initHeaderView;
- (double)currencyTextFieldFontSize:(id)arg1;
- (double)uintLabelFontSize:(id)arg1;
- (void)reloadTableView;
- (void)initNavigationBar;
- (void)viewDidLoad;
- (void)setDelegate:(id)arg1;
- (void)refreshViewWithData:(id)arg1;
- (void)viewWillDisappear:(_Bool)arg1;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

