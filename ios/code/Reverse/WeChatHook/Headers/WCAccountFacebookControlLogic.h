//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "WCAccountBaseControlLogic.h"

#import "IMMFacebookMgrExt.h"
#import "WCAccountManualAuthControlLogicDelegate.h"

@class NSString, WCAccountManualAuthControlLogic;

@interface WCAccountFacebookControlLogic : WCAccountBaseControlLogic <IMMFacebookMgrExt, WCAccountManualAuthControlLogicDelegate>
{
    WCAccountManualAuthControlLogic *m_manualAuthLogic;
}

- (void).cxx_destruct;
- (_Bool)onManualAuthControlLogicError:(id)arg1;
- (void)onManualAuthControlLogicStop:(unsigned long long)arg1 response:(id)arg2;
- (void)onLoginFacebookBegan:(id)arg1;
- (void)onFBDidNotLogin:(_Bool)arg1;
- (void)loginWithUserName:(id)arg1 token:(id)arg2;
- (void)stopLogic;
- (void)startLogic;
- (void)pause;
- (void)dealloc;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
