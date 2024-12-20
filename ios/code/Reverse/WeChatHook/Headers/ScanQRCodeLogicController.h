//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "BaseScanLogicController.h"

#import "CameraScannerStatusExt.h"
#import "GetA8KeyLogicDelegate.h"
#import "NewQRCodeScannerDelegate.h"
#import "ScanBarcodeExt.h"
#import "ScanQRCodeUrlPrefixHandlerDelegate.h"
#import "UIAlertViewDelegate.h"
#import "UIImagePickerControllerDelegate.h"
#import "UINavigationControllerDelegate.h"

@class GetA8KeyLogic, MMUIViewController, NSDictionary, NSObject<OS_dispatch_semaphore>, NSOperationQueue, NSString, NewQRCodeScanner, ScanQRCodeResultInfo, ScanQRCodeUrlPrefixRule, ScanWXCodeUrlPrefixRule;

@interface ScanQRCodeLogicController : BaseScanLogicController <ScanQRCodeUrlPrefixHandlerDelegate, CameraScannerStatusExt, NewQRCodeScannerDelegate, UIImagePickerControllerDelegate, UINavigationControllerDelegate, UIAlertViewDelegate, GetA8KeyLogicDelegate, ScanBarcodeExt>
{
    NewQRCodeScanner *_scanner;
    _Bool _hasCamera;
    GetA8KeyLogic *_logic;
    NSString *_desc;
    _Bool _hasFoundCode;
    NSString *_loadingText;
    NSString *_alertText;
    _Bool _showingMyQRCode;
    _Bool _scanOnePictureMode;
    NSOperationQueue *_scanPicOperationQueue;
    NSObject<OS_dispatch_semaphore> *_semaphore;
    _Bool _bIsScanFromAlbumImage;
    _Bool _hasReported;
    float _maxZoomFactor;
    _Bool _bNeedCameraScan;
    unsigned int fromScene;
    unsigned int _m_sourceType;
    NSString *_picUrl4Stat;
    NSString *_picEncKey4Stat;
    NSDictionary *_tryScanExtraInfo;
    NSString *_sourceWeAppAppid;
    NSString *_m_sourceInfo;
    NSString *_m_weappSourceInfo;
    ScanQRCodeUrlPrefixRule *_m_urlPrefixRule;
    MMUIViewController *_m_viewController;
    ScanWXCodeUrlPrefixRule *_m_wxCodeUrlPrefixRule;
    ScanQRCodeResultInfo *_offlineScanResult;
}

+ (id)shareScanOnePicSerialQueue;
@property(retain, nonatomic) ScanQRCodeResultInfo *offlineScanResult; // @synthesize offlineScanResult=_offlineScanResult;
@property(retain, nonatomic) ScanWXCodeUrlPrefixRule *m_wxCodeUrlPrefixRule; // @synthesize m_wxCodeUrlPrefixRule=_m_wxCodeUrlPrefixRule;
@property(nonatomic) __weak MMUIViewController *m_viewController; // @synthesize m_viewController=_m_viewController;
@property(retain, nonatomic) ScanQRCodeUrlPrefixRule *m_urlPrefixRule; // @synthesize m_urlPrefixRule=_m_urlPrefixRule;
@property(retain, nonatomic) NSString *m_weappSourceInfo; // @synthesize m_weappSourceInfo=_m_weappSourceInfo;
@property(retain, nonatomic) NSString *m_sourceInfo; // @synthesize m_sourceInfo=_m_sourceInfo;
@property(nonatomic) unsigned int m_sourceType; // @synthesize m_sourceType=_m_sourceType;
@property(retain, nonatomic) NSString *sourceWeAppAppid; // @synthesize sourceWeAppAppid=_sourceWeAppAppid;
@property(readonly, nonatomic) NSDictionary *tryScanExtraInfo; // @synthesize tryScanExtraInfo=_tryScanExtraInfo;
@property(retain, nonatomic) NSString *picEncKey4Stat; // @synthesize picEncKey4Stat=_picEncKey4Stat;
@property(retain, nonatomic) NSString *picUrl4Stat; // @synthesize picUrl4Stat=_picUrl4Stat;
@property(nonatomic) unsigned int fromScene; // @synthesize fromScene;
@property(nonatomic) _Bool hasFoundCode; // @synthesize hasFoundCode=_hasFoundCode;
@property(retain, nonatomic) NSString *desc; // @synthesize desc=_desc;
- (void).cxx_destruct;
- (void)p_appendResultInfoWithCurrentNetworkScene:(int)arg1;
- (id)getScanQRCodeSourceWebViewControllerUrl;
- (void)onScanQRCodeUrlPrefixHandlerScanFinish;
- (void)reportPrefixHandlerFailedCount;
- (void)onClickErrorAlertConfirm;
- (void)onScanQRCodeUrlPrefixHandlerWithErrorMsg:(id)arg1;
- (void)onScanQRCodeUrlPrefixHandlerEnd;
- (void)onScanQRCodeUrlPrefixHandlerStart;
- (id)onScanQRCodeUrlPrefixHandlerRequestViewController;
- (unsigned long long)getSourceType;
- (void)onNeedStartScan;
- (void)onGetProductInfoHandleEnd;
- (void)onGetProductInfoEnd;
- (void)onGetProductInfoStart;
- (void)onSearchContactGetResult;
- (void)onSearchContactFail;
- (void)onSearchContactHandleEnd;
- (void)onSearchContactEnd;
- (void)onSearchContactStart;
- (void)onGetA8KeyFail;
- (void)onGetA8KeyEnd;
- (void)onGetA8KeyResultType:(unsigned int)arg1;
- (void)onGetA8KeyStart;
- (void)OnSendBarcode:(id)arg1 Err:(int)arg2;
- (void)onDetectQRCode:(_Bool)arg1 zoomFactor:(float)arg2;
- (void)onGotBarcode:(id)arg1 Type:(id)arg2 rawData:(id)arg3;
- (void)NewQRCodeScanner:(id)arg1 didScanResult:(id)arg2 type:(id)arg3 version:(int)arg4 rawData:(id)arg5;
- (_Bool)shouldSendOfflineScanResultMessage;
- (void)tryScanHistoryResult:(id)arg1 type:(id)arg2 version:(int)arg3;
- (void)reportEngineStatWithScene:(unsigned int)arg1;
- (void)reportAfterCameraViewControlelrExit;
- (_Bool)isFoundBarCode;
- (id)fileScanDebugInfoString;
- (_Bool)isFoundBrandQRCode;
- (_Bool)isFoundWeAppWXCode;
- (id)getResultType;
- (id)getResultData;
- (void)showScanResult;
- (_Bool)getScanResult:(double)arg1;
- (void)doScanQRCode:(id)arg1;
- (void)tryScanOnePicture:(id)arg1 imgData:(id)arg2 extraInfo:(id)arg3;
- (void)tryScanOnePicture:(id)arg1 extraInfo:(id)arg2;
- (void)tryScanOnePicture:(id)arg1;
- (void)onRotate;
- (_Bool)shouldPopFromStack;
- (_Bool)shouldDoAnimationWhenDismiss;
- (void)scanOnePicture:(id)arg1;
- (void)startLoadingCheck;
- (void)startLoadingSearch;
- (void)onIntroButtonClicked;
- (id)getIntroDesctiption;
- (id)getIntroTitle;
- (float)getIntroButtonTopPadding;
- (id)getIntroButtonTitle;
- (_Bool)shouldShowIntroButton;
- (float)getPreviewScale;
- (id)getAlertText;
- (id)getLoadingText;
- (id)getInfoText;
- (struct CGRect)getDrawCropRect;
- (double)getDeviceScreenRatio;
- (void)setCropRect;
- (void)stopScan;
- (void)startScan;
- (void)releaseSemaphore;
@property(readonly, nonatomic) int scanCodeType;
- (void)dealloc;
- (void)setIsFromAlbum:(_Bool)arg1;
- (void)setViewController:(id)arg1;
- (void)onCameraScannerViewDidInit;
- (id)initWithViewController:(id)arg1 CodeType:(int)arg2 needCameraScan:(_Bool)arg3;
- (id)initWithViewController:(id)arg1 CodeType:(int)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

