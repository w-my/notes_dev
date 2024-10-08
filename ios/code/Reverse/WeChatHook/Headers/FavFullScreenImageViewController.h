//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "FullScreenViewController.h"

#import "BaseScanLogicDelegate.h"
#import "EditImageForwardAndEditLogicDelegate.h"
#import "FavForwardLogicDelegate.h"
#import "FavImageFullScreenViewContainerDelegate.h"
#import "UIScrollViewDelegate.h"
#import "WCActionSheetDelegate.h"
#import "WCCommitViewResultDelegate.h"
#import "scrollViewDelegate.h"

@class EditImageForwardAndEditLogicController, FavClickStreamHelper, MMScrollView, NSMutableArray, NSString, ScanQRCodeLogicController, SimpleImgInfo, UIView, WCActionSheetWithScanWXCode;

@interface FavFullScreenImageViewController : FullScreenViewController <FavForwardLogicDelegate, EditImageForwardAndEditLogicDelegate, UIScrollViewDelegate, scrollViewDelegate, FavImageFullScreenViewContainerDelegate, WCCommitViewResultDelegate, WCActionSheetDelegate, BaseScanLogicDelegate>
{
    UIView *m_fakeScreenView;
    struct CGRect m_originImageRectInScreen;
    _Bool m_isAnimating;
    MMScrollView *m_scrollView;
    UIView *m_blackMask;
    NSMutableArray *m_arrFavData;
    NSMutableArray *m_arrImage;
    unsigned int m_iCurIndex;
    unsigned int m_firstIndex;
    _Bool m_isRotating;
    _Bool m_isAnimationShowing;
    ScanQRCodeLogicController *_scanQRCodeLogic;
    int m_qrcodeActionSheetIndex;
    WCActionSheetWithScanWXCode *m_actionSheet;
    SimpleImgInfo *m_forwardDataSrc;
    SimpleImgInfo *m_editImageInfo;
    EditImageForwardAndEditLogicController *m_editImageLogicController;
    _Bool m_allowRotate;
    FavClickStreamHelper *m_clickHelper;
    _Bool _m_canSelect;
    _Bool _m_needEditImage;
    _Bool _m_canEditImage;
    id <FavFullScreenImageViewControllerDelegate> _m_delegate;
}

+ (id)animationShowWithRecordData:(id)arg1 originView:(id)arg2 index:(unsigned int)arg3 needEdit:(_Bool)arg4 canEdit:(_Bool)arg5;
+ (id)animationShowWithRecordData:(id)arg1 originView:(id)arg2 index:(unsigned int)arg3;
+ (id)animationShowWithRecordData:(id)arg1 originRect:(struct CGRect)arg2 index:(unsigned int)arg3;
@property(nonatomic) __weak id <FavFullScreenImageViewControllerDelegate> m_delegate; // @synthesize m_delegate=_m_delegate;
@property(nonatomic) _Bool m_canEditImage; // @synthesize m_canEditImage=_m_canEditImage;
@property(nonatomic) _Bool m_needEditImage; // @synthesize m_needEditImage=_m_needEditImage;
@property(nonatomic) _Bool m_canSelect; // @synthesize m_canSelect=_m_canSelect;
@property(nonatomic) unsigned int m_iCurIndex; // @synthesize m_iCurIndex;
- (void).cxx_destruct;
- (void)onGetA8KeyResultType:(unsigned int)arg1;
- (_Bool)shouldAutorotate;
- (void)onScanCodeFinish;
- (void)onScanEnds;
- (void)onStopLoading;
- (void)OnForwardMessageCancel:(id)arg1;
- (void)OnForwardDone;
- (id)getFavForawrdViewController;
- (void)onDoneForwardForForwardView:(id)arg1;
- (void)onCancelForwardForForwardView:(id)arg1;
- (unsigned long long)preferredScreenEdgesDeferringSystemGestures;
- (void)onEditImageForwardAndEditResult:(id)arg1;
- (void)onDismissEditView;
- (void)onShowingEditView;
- (void)editImage;
- (void)captureScreen;
- (void)onForward2WCRecordData;
- (void)onForward2MsgRecordData;
- (void)dismissMySelfAndShowContext:(id)arg1 dataItem:(id)arg2;
- (void)onTranslateWordInImage;
- (void)actionSheet:(id)arg1 clickedButtonAtIndex:(long long)arg2;
- (id)imageForScanQRCodeAtPage:(id)arg1 isClipImage:(_Bool *)arg2;
- (void)onWillLongPress:(id)arg1 touchPoint:(struct CGPoint)arg2 onImage:(id)arg3;
- (void)detectWordInImage:(id)arg1;
- (void)onLongPressEvent:(id)arg1 onImage:(id)arg2;
- (void)onFullScreenItemChangeAlpha:(double)arg1;
- (void)animationHideWithRotate;
- (_Bool)useAlphaAnimation;
- (_Bool)shouldAnimationWhenHide;
- (void)onAnimateFadeOut;
- (void)onContainerAnimationHideStart;
- (void)onContainerAnimationShowStop;
- (void)onContainerAnimationShowStart;
- (void)animationHideStop;
- (void)onContainerAnimationHideStop;
- (id)getVisibleViewController;
- (void)scrollViewDidEndScrollingAnimation:(id)arg1;
- (void)scrollViewDidScroll:(id)arg1;
- (void)scrollViewDidEndDecelerating:(id)arg1;
- (void)downloadImage;
- (void)animationShowWithRecordData:(id)arg1 originRect:(struct CGRect)arg2 index:(unsigned int)arg3;
- (void)showVCAnimation;
- (void)reloadContainerImgInfo:(id)arg1 originRect:(struct CGRect)arg2 index:(unsigned int)arg3;
- (void)setRecordData:(id)arg1 originRect:(struct CGRect)arg2 index:(unsigned int)arg3;
- (void)resetScrollView;
- (void)clearStatus;
- (void)viewDidLayoutSubviews;
- (unsigned long long)supportedInterfaceOrientations;
- (void)adjustViewAndNavBarRect;
- (void)onMemoryWarning;
- (void)dealloc;
- (void)viewWillDisappear:(_Bool)arg1;
- (void)viewDidAppear:(_Bool)arg1;
- (void)viewWillAppear:(_Bool)arg1;
- (void)viewDidLoad;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

