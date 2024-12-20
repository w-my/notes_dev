//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "WCPayControlLogic.h"

#import "MMUseCaseCallback.h"
#import "MMWebViewDelegate.h"
#import "WAAppTaskMgrExt.h"
#import "WCBaseControlLogicDeleagte.h"
#import "WCPayBizF2FActQryCgiDelegate.h"
#import "WCPayBizF2FPaidSuccViewControllerDelegate.h"
#import "WCPayBizF2FPayCheckCgiDelegate.h"
#import "WCPayBizF2FPlaceOrderCgiDelegate.h"
#import "WCPayBizF2FTransferMoneyViewControllerDelegate.h"
#import "WCPayBizF2FZeroPayConfirmViewDelegate.h"
#import "WCPayBusiF2FSucPageCgiDelegate.h"
#import "WCPayBusiF2FUnlockFavorCgiDelegate.h"
#import "WCPayBusiF2FZeroCallBackCgiDelegate.h"
#import "WCPayF2FDrawLotteryCgiDelegate.h"
#import "WCPayF2FGetLotteryCgiDelegate.h"
#import "WCPayF2FMiddleViewControllerDelegate.h"
#import "WCPayF2FModifyExposureCgiDelegate.h"
#import "WCPayGetZeroPayTokenCgiDelegate.h"
#import "WCPayPayMoneyLogicDelegate.h"
#import "WCPaySubLogicDelegate.h"

@class BusiF2FPlaceOrderResp, DrawLotteryResponse, ExposureInfo, ExposureInfoModifyResponse, GetLotteryResponse, MMWebViewController, NSString, WCPayBizF2FActQryCgi, WCPayBizF2FPayCheckCgi, WCPayBizF2FPlaceOrderCgi, WCPayBizF2FZeroCallBackAutoRetryCgi, WCPayBizF2FZeroPayConfirmView, WCPayBusiF2FSucPageCgiWithRetry, WCPayBusiF2FUnlockFavorCgi, WCPayF2FDrawLotteryCgi, WCPayF2FGetLotteryCgi, WCPayF2FMiddlePageSubLogic, WCPayF2FModifyExposureCgi, WCPayGetZeroPayTokenCgi, WCPayPayMoneyLogic;

@interface WCPayBizF2FTransferControlLogic : WCPayControlLogic <WCPaySubLogicDelegate, WCPayF2FMiddleViewControllerDelegate, WCPayBusiF2FZeroCallBackCgiDelegate, WCPayGetZeroPayTokenCgiDelegate, WCPayBizF2FZeroPayConfirmViewDelegate, WCPayBusiF2FSucPageCgiDelegate, WCPayBusiF2FUnlockFavorCgiDelegate, WCPayBizF2FTransferMoneyViewControllerDelegate, WCPayBizF2FPaidSuccViewControllerDelegate, WCPayPayMoneyLogicDelegate, WCPayBizF2FPlaceOrderCgiDelegate, WCPayBizF2FActQryCgiDelegate, WCPayBizF2FPayCheckCgiDelegate, WCBaseControlLogicDeleagte, WCPayF2FDrawLotteryCgiDelegate, WCPayF2FModifyExposureCgiDelegate, WCPayF2FGetLotteryCgiDelegate, WAAppTaskMgrExt, MMWebViewDelegate, MMUseCaseCallback>
{
    _Bool _bHasPaySucc;
    _Bool _isModifyExposureInfo;
    unsigned int _lastTotalAmount;
    id <WCPayBizF2FTransferControlLogicDelegate> _bizF2FLogicDelagte;
    WCPayBizF2FPlaceOrderCgi *_placeOrderCgi;
    WCPayBizF2FPayCheckCgi *_payCheckCgi;
    WCPayBizF2FActQryCgi *_actQryCgi;
    WCPayPayMoneyLogic *_payMoneyLogic;
    WCPayBusiF2FUnlockFavorCgi *_unLockFavorCgi;
    WCPayBusiF2FSucPageCgiWithRetry *_paySuccessCgi;
    WCPayGetZeroPayTokenCgi *_getZeroPayTokenCgi;
    WCPayBizF2FZeroCallBackAutoRetryCgi *_m_zeroPayCgi;
    WCPayF2FGetLotteryCgi *_f2fGetLotteryCgi;
    GetLotteryResponse *_getLotteryReponse;
    WCPayF2FModifyExposureCgi *_f2fModifyExposureCgi;
    ExposureInfoModifyResponse *_exposureInfoModifyResponse;
    WCPayF2FDrawLotteryCgi *_f2fDrawLotteryCgi;
    DrawLotteryResponse *_drawLotteryResponse;
    ExposureInfo *_prevExposureInfo;
    MMWebViewController *_getLotteryViewController;
    WCPayBizF2FZeroPayConfirmView *_m_zeroPayConfirmView;
    NSString *_m_fingerdata;
    WCPayF2FMiddlePageSubLogic *_m_middlePageSubLogic;
    BusiF2FPlaceOrderResp *_lastReqKeyStruct;
    NSString *_lastPayRequestKey;
    NSString *_lastRemarkWording;
    long long _lastUnpayReason;
}

@property(nonatomic) long long lastUnpayReason; // @synthesize lastUnpayReason=_lastUnpayReason;
@property(retain, nonatomic) NSString *lastRemarkWording; // @synthesize lastRemarkWording=_lastRemarkWording;
@property(nonatomic) unsigned int lastTotalAmount; // @synthesize lastTotalAmount=_lastTotalAmount;
@property(retain, nonatomic) NSString *lastPayRequestKey; // @synthesize lastPayRequestKey=_lastPayRequestKey;
@property(retain, nonatomic) BusiF2FPlaceOrderResp *lastReqKeyStruct; // @synthesize lastReqKeyStruct=_lastReqKeyStruct;
@property(retain, nonatomic) WCPayF2FMiddlePageSubLogic *m_middlePageSubLogic; // @synthesize m_middlePageSubLogic=_m_middlePageSubLogic;
@property(nonatomic) _Bool isModifyExposureInfo; // @synthesize isModifyExposureInfo=_isModifyExposureInfo;
@property(nonatomic) _Bool bHasPaySucc; // @synthesize bHasPaySucc=_bHasPaySucc;
@property(retain, nonatomic) NSString *m_fingerdata; // @synthesize m_fingerdata=_m_fingerdata;
@property(retain, nonatomic) WCPayBizF2FZeroPayConfirmView *m_zeroPayConfirmView; // @synthesize m_zeroPayConfirmView=_m_zeroPayConfirmView;
@property(retain, nonatomic) MMWebViewController *getLotteryViewController; // @synthesize getLotteryViewController=_getLotteryViewController;
@property(retain, nonatomic) ExposureInfo *prevExposureInfo; // @synthesize prevExposureInfo=_prevExposureInfo;
@property(retain, nonatomic) DrawLotteryResponse *drawLotteryResponse; // @synthesize drawLotteryResponse=_drawLotteryResponse;
@property(retain, nonatomic) WCPayF2FDrawLotteryCgi *f2fDrawLotteryCgi; // @synthesize f2fDrawLotteryCgi=_f2fDrawLotteryCgi;
@property(retain, nonatomic) ExposureInfoModifyResponse *exposureInfoModifyResponse; // @synthesize exposureInfoModifyResponse=_exposureInfoModifyResponse;
@property(retain, nonatomic) WCPayF2FModifyExposureCgi *f2fModifyExposureCgi; // @synthesize f2fModifyExposureCgi=_f2fModifyExposureCgi;
@property(retain, nonatomic) GetLotteryResponse *getLotteryReponse; // @synthesize getLotteryReponse=_getLotteryReponse;
@property(retain, nonatomic) WCPayF2FGetLotteryCgi *f2fGetLotteryCgi; // @synthesize f2fGetLotteryCgi=_f2fGetLotteryCgi;
@property(retain, nonatomic) WCPayBizF2FZeroCallBackAutoRetryCgi *m_zeroPayCgi; // @synthesize m_zeroPayCgi=_m_zeroPayCgi;
@property(retain, nonatomic) WCPayGetZeroPayTokenCgi *getZeroPayTokenCgi; // @synthesize getZeroPayTokenCgi=_getZeroPayTokenCgi;
@property(retain, nonatomic) WCPayBusiF2FSucPageCgiWithRetry *paySuccessCgi; // @synthesize paySuccessCgi=_paySuccessCgi;
@property(retain, nonatomic) WCPayBusiF2FUnlockFavorCgi *unLockFavorCgi; // @synthesize unLockFavorCgi=_unLockFavorCgi;
@property(retain, nonatomic) WCPayPayMoneyLogic *payMoneyLogic; // @synthesize payMoneyLogic=_payMoneyLogic;
@property(retain, nonatomic) WCPayBizF2FActQryCgi *actQryCgi; // @synthesize actQryCgi=_actQryCgi;
@property(retain, nonatomic) WCPayBizF2FPayCheckCgi *payCheckCgi; // @synthesize payCheckCgi=_payCheckCgi;
@property(retain, nonatomic) WCPayBizF2FPlaceOrderCgi *placeOrderCgi; // @synthesize placeOrderCgi=_placeOrderCgi;
@property(nonatomic) __weak id <WCPayBizF2FTransferControlLogicDelegate> bizF2FLogicDelagte; // @synthesize bizF2FLogicDelagte=_bizF2FLogicDelagte;
- (void).cxx_destruct;
- (void)call:(id)arg1;
- (void)reportWithAction:(unsigned long long)arg1;
- (void)onWCPayF2FMiddleViewControllerClickTransfer:(unsigned int)arg1;
- (void)onWCPayF2FMiddleViewControllerBack;
- (void)onWCPayBusiF2FZeroCallBackCgiError:(id)arg1;
- (void)onWCPayBusiF2FZeroCallBackCgiResp:(id)arg1;
- (void)onResetPwdConfirm:(id)arg1;
- (void)onResetPwdRetry:(id)arg1;
- (void)onWCPayGetZeroPayTokenCgi:(id)arg1 didFailWithTenpayResponse:(id)arg2 error:(id)arg3;
- (void)onWCPayGetZeroPayTokenCgi:(id)arg1 didFailWithError:(id)arg2;
- (void)onWCPayGetZeroPayTokenCgi:(id)arg1 didGetResponse:(id)arg2;
- (void)onWCPayBizF2FZeroPayConfirmViewCancel;
- (void)onWCPayBizF2FZeroPayConfirmViewConfirmWithFingerData:(id)arg1;
- (void)onWCPayBizF2FZeroPayConfirmViewConfirmWithPassword:(id)arg1;
- (void)onRealnameVerifyCancelNotification:(id)arg1;
- (void)onRealnameVerifySuccessNotification:(id)arg1;
- (void)webViewReturn:(id)arg1;
- (void)onAppTaskDidEnterBackground:(id)arg1 mode:(long long)arg2;
- (void)OnWCPayBaseRequestNoKnownError:(id)arg1 TenPayCmdType:(int)arg2;
- (void)OnF2FModifyExposureRepsonseError:(id)arg1 errorCode:(unsigned int)arg2;
- (void)OnF2FModifyExposureRepsonseOK:(id)arg1;
- (void)OnF2FDrawLotteryRepsonseError:(id)arg1 errorCode:(unsigned int)arg2;
- (void)OnF2FDrawLotteryRepsonseOK:(id)arg1;
- (void)OnGetF2FGetLotteryRepsonseError:(id)arg1 errorCode:(unsigned int)arg2;
- (void)OnGetF2FGetLotteryRepsonseOK:(id)arg1;
- (void)onBizF2FPaidSuccViewControllerReturnWithoutDrawLottery;
- (void)onBizF2FPaidSuccViewControllerStartDrawLottery:(unsigned int)arg1;
- (void)onBizF2FPaidSuccViewControllerClickLotteryBtn:(id)arg1;
- (void)onWCPayBusiF2FSucPageCgiError:(id)arg1;
- (void)onWCPayBusiF2FSucPageCgiResp:(id)arg1;
- (void)onWCPayBusiF2FUnlockFavorCgiError:(id)arg1;
- (void)onWCPayBusiF2FUnlockFavorCgiResp:(id)arg1;
- (void)startUnlockFavorCgi;
- (void)startPaySuccessCgi;
- (void)onPayMoneyLogicDidStop;
- (void)onGetF2FPayCheckCgiResp:(id)arg1;
- (void)onPayMoneyLogicSuccess;
- (_Bool)gotoViewController:(id)arg1;
- (void)placeOrderAlertRightBtnClick;
- (void)cancelTransferMoney:(id)arg1;
- (void)continueToTransfer:(_Bool)arg1;
- (void)continueTransfer:(id)arg1;
- (double)zeroPayMoneyDouble;
- (id)zeroPayMoney;
- (id)zeroPayTitle;
- (_Bool)canUseBioAuth;
- (_Bool)zeroPay:(id)arg1;
- (void)placeOrderErrorSceneClickIKnow;
- (void)onGetBizF2FPlaceOrderResp:(id)arg1;
- (void)onGetBizF2FActQryResp:(id)arg1;
- (void)onBizF2FPaidSuccViewControllerQueryActivity;
- (void)onBizF2FPaidSuccViewControllerClickActivityBtn;
- (void)onBizF2FPaidSuccViewControllerDoneBtnClick;
- (void)resendPlaceOrderCgi;
- (void)onBizTransferMoneyTransferBtnClickWithAmount:(unsigned int)arg1 payerComment:(id)arg2 composeInfo:(id)arg3;
- (void)onBizTransferMoneyViewControllerBack;
- (void)startLogic;
- (id)initWithData:(id)arg1;
- (void)stopLogic;
- (void)dealloc;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

