//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "TADEvaluateJSFunc.h"

#import "TADScanQRCodeViewControllerDelegate.h"
#import "UIActionSheetDelegate.h"

@class NSString;

@interface TADScanQRFunc : TADEvaluateJSFunc <UIActionSheetDelegate, TADScanQRCodeViewControllerDelegate>
{
    _Bool _longPressed;
    id <TADScanQRFuncDelegate> _scanQRDelegate;
    long long _scanQRCodeHandle;
    NSString *_webCallback;
    id <TADLandingControlDelegate> _scanControlDelegate;
    NSString *_decodeQRCodeURL;
    NSString *_selectedImageURL;
}

@property(nonatomic) _Bool longPressed; // @synthesize longPressed=_longPressed;
@property(copy, nonatomic) NSString *selectedImageURL; // @synthesize selectedImageURL=_selectedImageURL;
@property(copy, nonatomic) NSString *decodeQRCodeURL; // @synthesize decodeQRCodeURL=_decodeQRCodeURL;
@property(nonatomic) __weak id <TADLandingControlDelegate> scanControlDelegate; // @synthesize scanControlDelegate=_scanControlDelegate;
@property(copy, nonatomic) NSString *webCallback; // @synthesize webCallback=_webCallback;
@property(nonatomic) long long scanQRCodeHandle; // @synthesize scanQRCodeHandle=_scanQRCodeHandle;
@property(nonatomic) __weak id <TADScanQRFuncDelegate> scanQRDelegate; // @synthesize scanQRDelegate=_scanQRDelegate;
- (void).cxx_destruct;
- (void)tadUserHasClosedScanController;
- (void)tadQRcodeScanResult:(id)arg1;
- (void)tadQRcodeHandleWithResult:(id)arg1;
- (id)imageFromView:(id)arg1;
- (id)decodeImgWith:(id)arg1;
- (void)tadImage:(id)arg1 didFinishSavingWithError:(id)arg2 contextInfo:(void *)arg3;
- (void)saveImageWithUrlToPhotosAlbum:(id)arg1;
- (void)actionSheet:(id)arg1 clickedButtonAtIndex:(long long)arg2;
- (void)showActionSheetWithWebTags:(id)arg1 tagSrc:(id)arg2 inContainView:(id)arg3;
- (void)openContextualMenuAt:(struct CGPoint)arg1;
- (void)scanQRCode;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

