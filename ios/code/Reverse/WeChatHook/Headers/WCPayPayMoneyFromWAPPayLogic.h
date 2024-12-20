//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "WCPayControlLogic.h"

#import "WCBaseControlMgrExt.h"
#import "WCPayPayMoneyFromOverseaH5WalletLogicDelegate.h"

@class NSDictionary, NSString, WCPayBaseViewController, WCPayPayMoneyFromOverseaH5WalletLogic, WCPayPayMoneyLogic;

@interface WCPayPayMoneyFromWAPPayLogic : WCPayControlLogic <WCBaseControlMgrExt, WCPayPayMoneyFromOverseaH5WalletLogicDelegate>
{
    NSDictionary *m_payInfo;
    NSString *m_bundleId;
    WCPayPayMoneyLogic *m_payLogic;
    WCPayBaseViewController *rootViewController;
    WCPayPayMoneyFromOverseaH5WalletLogic *m_payMoneyFromOverseaH5WalletLogic;
}

- (void).cxx_destruct;
- (void)cancelPayMoneyFromOverseaH5WalletLogic:(id)arg1;
- (void)failToPayMoneyFromOverseaH5WalletLogic:(id)arg1;
- (void)succToPayMoneyFromOverseaH5WalletLogic:(id)arg1;
- (void)OnGetAppAuthUrlErrorRequest:(id)arg1;
- (void)OnGetAppAuthUrlRequest:(id)arg1 AppSource:(id)arg2 PrepayId:(id)arg3 CallBackUrl:(id)arg4 WalletMixSpGenprepayResp:(id)arg5 Error:(id)arg6;
- (void)onWCBaseLogicDidStop:(unsigned int)arg1;
- (void)OnRootViewBack;
- (_Bool)gotoViewController:(id)arg1;
- (void)stopLogic;
- (void)startLogic;
- (void)dealloc;
- (id)initWithInfo:(id)arg1 BundleID:(id)arg2;
- (void)markCancelByOpenApi;
- (_Bool)cancelByOpenApi;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

