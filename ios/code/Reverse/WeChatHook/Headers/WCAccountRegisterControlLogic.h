//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "WCAccountBaseControlLogic.h"

#import "IAddressBookMgrExt.h"
#import "IRsaCertMgrExt.h"
#import "WCAccountGraphicVerifyViewControllerDelegate.h"

@class NSString, WCAccountFindFriendControlLogic;

@interface WCAccountRegisterControlLogic : WCAccountBaseControlLogic <IAddressBookMgrExt, WCAccountGraphicVerifyViewControllerDelegate, IRsaCertMgrExt>
{
    _Bool m_bCanSyncAddressBook;
    unsigned int m_idc_redirect_count;
    unsigned int m_mmtls_set_count;
    unsigned long long m_ui64BeginTime;
    unsigned int m_uiABtest;
    unsigned int m_uiCCType;
    WCAccountFindFriendControlLogic *m_findFriendLogic;
}

- (void).cxx_destruct;
- (void)resume;
- (void)pause;
- (void)RSAProtobufMessageReturn:(id)arg1 Event:(unsigned int)arg2;
- (void)handleNewRegResponse:(id)arg1;
- (void)onEnableAddressBookTip;
- (void)showDeniedTip;
- (void)showEnableTip;
- (void)enableAddressBook;
- (void)jumpToMainFrame;
- (void)OnConfirmAddressBookStatus:(unsigned int)arg1;
- (void)onGraphicVerifyChangeImage;
- (void)onGraphicVerifyBack;
- (void)onGraphicVerifyWithVerifyCode:(id)arg1;
- (_Bool)regAccount;
- (id)genNewRegRequest;
- (void)startLogic;
- (void)dealloc;
- (void)reportABTestStatus:(unsigned int)arg1;
- (void)setABTest:(unsigned int)arg1 CCType:(unsigned int)arg2;
- (id)initWithData:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
