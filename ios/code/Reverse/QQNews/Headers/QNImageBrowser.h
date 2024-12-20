//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIViewController.h"

#import "CAAnimationDelegate.h"
#import "CActionSheetDelegate.h"
#import "QNDetailImageProgressUnitViewDelegate.h"
#import "QNScaleImageViewDelegate.h"
#import "QNShareActivityControllerDelegate.h"
#import "UIGestureRecognizerDelegate.h"
#import "UIScrollViewDelegate.h"

@class CAAnimationGroup, CActionSheet, CHitExtendButton, MiniQQMusicPlayEngine, NSIndexPath, NSMutableArray, NSMutableDictionary, NSString, QNDownloadUnitView, QNEnlargeHitTestButton, QNImageBrowserStatement, QNScaleImageView, UILabel, UIPanGestureRecognizer, UIScrollView, UIView;

@interface QNImageBrowser : UIViewController <QNDetailImageProgressUnitViewDelegate, UIGestureRecognizerDelegate, CAAnimationDelegate, UIScrollViewDelegate, CActionSheetDelegate, QNScaleImageViewDelegate, QNShareActivityControllerDelegate>
{
    struct {
        long long index;
        double boundsMaxX;
    } _pageViewUserScrollState;
    _Bool _enableRotation;
    _Bool _enableVerticalSwipe;
    _Bool _firstUserTriggerd;
    int _extendCountOfPageViewCahche;
    UIView *_presentingView;
    UIView *_contentView;
    UIScrollView *_scrollView;
    UIView *_navBar;
    QNImageBrowserStatement *_descriptionView;
    NSMutableArray *_imageItems;
    NSMutableDictionary *_pageCache;
    UILabel *_lastTintLabel;
    CActionSheet *_actionSheet;
    id <QNImageBrowserDelegate> _delegate;
    long long _currentOrientation;
    long long _imageScaleMode;
    long long _animatedImageContentMode;
    UIView *_actionSheetOrientationView;
    CDUnknownBlockType _isEventSupported;
    CDUnknownBlockType _onEventTriggered;
    double _beginTimeStamp;
    UIView *_playNextPicsTipsView;
    NSIndexPath *_indexPath;
    MiniQQMusicPlayEngine *_playEngine;
    CHitExtendButton *_musicControllButton;
    NSMutableArray *_backMusic;
    long long _musicNow;
    long long _initialOrientation;
    long long _animationImageScaleMode;
    UIPanGestureRecognizer *_panGesture;
    QNScaleImageView *_simgeImageView;
    CAAnimationGroup *_animationGroup2;
    QNEnlargeHitTestButton *_downloadBtn;
    QNDownloadUnitView *_downloadUnitView;
    double _limitedAnimationHeight;
    struct CGPoint _moveImageViewOriginalPosition;
}

+ (id)cachedImageWithURL:(id)arg1;
+ (id)defaultBrowser;
@property(nonatomic) double limitedAnimationHeight; // @synthesize limitedAnimationHeight=_limitedAnimationHeight;
@property(retain, nonatomic) QNDownloadUnitView *downloadUnitView; // @synthesize downloadUnitView=_downloadUnitView;
@property(retain, nonatomic) QNEnlargeHitTestButton *downloadBtn; // @synthesize downloadBtn=_downloadBtn;
@property(retain, nonatomic) CAAnimationGroup *animationGroup2; // @synthesize animationGroup2=_animationGroup2;
@property(retain, nonatomic) QNScaleImageView *simgeImageView; // @synthesize simgeImageView=_simgeImageView;
@property(nonatomic) struct CGPoint moveImageViewOriginalPosition; // @synthesize moveImageViewOriginalPosition=_moveImageViewOriginalPosition;
@property(retain, nonatomic) UIPanGestureRecognizer *panGesture; // @synthesize panGesture=_panGesture;
@property(nonatomic) long long animationImageScaleMode; // @synthesize animationImageScaleMode=_animationImageScaleMode;
@property(nonatomic) long long initialOrientation; // @synthesize initialOrientation=_initialOrientation;
@property(nonatomic) long long musicNow; // @synthesize musicNow=_musicNow;
@property(retain, nonatomic) NSMutableArray *backMusic; // @synthesize backMusic=_backMusic;
@property(retain, nonatomic) CHitExtendButton *musicControllButton; // @synthesize musicControllButton=_musicControllButton;
@property(retain, nonatomic) MiniQQMusicPlayEngine *playEngine; // @synthesize playEngine=_playEngine;
@property(nonatomic) _Bool firstUserTriggerd; // @synthesize firstUserTriggerd=_firstUserTriggerd;
@property(retain, nonatomic) NSIndexPath *indexPath; // @synthesize indexPath=_indexPath;
@property(retain, nonatomic) UIView *playNextPicsTipsView; // @synthesize playNextPicsTipsView=_playNextPicsTipsView;
@property(nonatomic) double beginTimeStamp; // @synthesize beginTimeStamp=_beginTimeStamp;
@property(copy, nonatomic) CDUnknownBlockType onEventTriggered; // @synthesize onEventTriggered=_onEventTriggered;
@property(copy, nonatomic) CDUnknownBlockType isEventSupported; // @synthesize isEventSupported=_isEventSupported;
@property(retain, nonatomic) UIView *actionSheetOrientationView; // @synthesize actionSheetOrientationView=_actionSheetOrientationView;
@property(nonatomic) long long animatedImageContentMode; // @synthesize animatedImageContentMode=_animatedImageContentMode;
@property(nonatomic) long long imageScaleMode; // @synthesize imageScaleMode=_imageScaleMode;
@property(nonatomic) long long currentOrientation; // @synthesize currentOrientation=_currentOrientation;
@property(nonatomic) __weak id <QNImageBrowserDelegate> delegate; // @synthesize delegate=_delegate;
@property(retain, nonatomic) CActionSheet *actionSheet; // @synthesize actionSheet=_actionSheet;
@property(retain, nonatomic) UILabel *lastTintLabel; // @synthesize lastTintLabel=_lastTintLabel;
@property(retain, nonatomic) NSMutableDictionary *pageCache; // @synthesize pageCache=_pageCache;
@property(retain, nonatomic) NSMutableArray *imageItems; // @synthesize imageItems=_imageItems;
@property(retain, nonatomic) QNImageBrowserStatement *descriptionView; // @synthesize descriptionView=_descriptionView;
@property(retain, nonatomic) UIView *navBar; // @synthesize navBar=_navBar;
@property(retain, nonatomic) UIScrollView *scrollView; // @synthesize scrollView=_scrollView;
@property(retain, nonatomic) UIView *contentView; // @synthesize contentView=_contentView;
@property(nonatomic) __weak UIView *presentingView; // @synthesize presentingView=_presentingView;
@property(nonatomic) _Bool enableVerticalSwipe; // @synthesize enableVerticalSwipe=_enableVerticalSwipe;
@property(nonatomic) _Bool enableRotation; // @synthesize enableRotation=_enableRotation;
@property(nonatomic) int extendCountOfPageViewCahche; // @synthesize extendCountOfPageViewCahche=_extendCountOfPageViewCahche;
- (void).cxx_destruct;
- (void)p_detatchFromPresentingView;
- (void)onCancelButtonTaped:(id)arg1;
- (void)scaleImageViewFailDownload:(id)arg1 forURL:(id)arg2;
- (void)scaleImageViewSuccessLoadFromMemory:(id)arg1 forURL:(id)arg2;
- (void)scaleImageViewSuccessDownload:(id)arg1 forURL:(id)arg2;
- (void)scaleImageView:(id)arg1 receiveDataSize:(unsigned long long)arg2 inTotalSize:(unsigned long long)arg3;
- (void)addProgressViewInPageView:(id)arg1 cancelDisabled:(_Bool)arg2;
- (void)viewOriginalImage;
- (void)image:(id)arg1 didFinishSavingWithError:(id)arg2 contextInfo:(void *)arg3;
- (void)imageDidFinishSavingWithError:(id)arg1;
- (void)saveToPhotosAlbum;
- (id)p_getCurrentPageImageData;
- (id)p_getCurrentPageImage;
- (void)actionDidDisappear;
- (void)actionSheet:(id)arg1 buttonClickedWithTitle:(id)arg2 andObject:(id)arg3;
- (void)showActionSheet;
- (void)scrollViewDidZoom:(id)arg1;
- (id)viewForZoomingInScrollView:(id)arg1;
- (void)scrollViewDidScroll:(id)arg1;
- (void)scrollViewDidEndDecelerating:(id)arg1;
- (void)scrollViewDidEndScrollingAnimation:(id)arg1;
- (void)scrollViewDidEndDragging:(id)arg1 willDecelerate:(_Bool)arg2;
- (void)scrollViewWillBeginDragging:(id)arg1;
- (void)_delayDealDownloadUnitViewType:(id)arg1;
- (void)removeAccessoryViewInPageView:(id)arg1;
- (void)handleLongPressImage:(id)arg1;
- (id)pageViewWithIndex:(long long)arg1;
- (void)loadPagesAtIndex:(long long)arg1;
- (void)loadPagesForCurrentPage;
- (long long)currentPageIndex;
- (long long)totalPages;
- (void)animationDidStop:(id)arg1 finished:(_Bool)arg2;
- (void)p_doDisappearFrameAnimation:(struct CGRect)arg1 animationDuration:(double)arg2 simgeImageView:(id)arg3;
- (void)doFinishScaleAnimation;
- (void)doStartScaleAnimationWithItem:(id)arg1;
- (void)rotateToPortraitAndScaleHide;
- (void)rotateToCurrentOrientation;
- (void)configContentForOrientation:(long long)arg1;
- (void)p_resetDescriptionView:(struct CGRect)arg1 transform:(struct CGAffineTransform)arg2;
- (void)p_forceResetDescriptionView;
- (struct CGAffineTransform)p_transform;
- (struct CGAffineTransform)p_transformFrom:(long long)arg1 to:(long long)arg2;
- (struct CGRect)p_screenBounds;
- (void)rotateToOrientation:(long long)arg1 animated:(_Bool)arg2;
- (void)handleOrientationChanged:(id)arg1;
- (void)handleDoubleTapImage:(id)arg1;
- (void)handleTapBackground:(id)arg1;
- (_Bool)gestureRecognizerShouldBegin:(id)arg1;
- (_Bool)p_shuoldLongImageEnableSwpie:(id)arg1;
- (_Bool)p_isUIDeviceOrientationPortrait;
- (void)swipe:(long long)arg1 translatedPoint:(struct CGPoint)arg2 isLongImage:(_Bool)arg3 completion:(CDUnknownBlockType)arg4;
- (void)panGestureRecognized:(id)arg1;
- (void)initPositionStatusInTheVerticalSwipe;
- (void)prepareVerticalSwipe;
- (void)resetBrowser;
- (void)dismissBrowserAnimated:(_Bool)arg1;
- (void)hideBrowser;
- (id)p_currentSingleImageScrollView;
- (id)p_singleImageScrollViewAtIndex:(long long)arg1;
- (void)resetBrowserWithImageItems:(id)arg1;
- (void)showBrowserWithImageItems:(id)arg1 defaultIndex:(long long)arg2 optionalConfig:(id)arg3;
- (void)reloadWithImageItems:(id)arg1;
- (void)showBrowserWithImageItems:(id)arg1 defaultIndex:(long long)arg2 delegate:(id)arg3 imageScaleMode:(long long)arg4 animatedImageContentMode:(long long)arg5;
- (void)showBrowserWithImageItems:(id)arg1 defaultIndex:(long long)arg2 delegate:(id)arg3;
- (void)showBrowserWithImageItems:(id)arg1 defaultIndex:(long long)arg2;
- (void)restoreStatusBar;
- (void)configStatusBar;
- (void)lastTintLabelEnabled:(_Bool)arg1;
- (void)p_handleShare;
- (void)configDescriptionForCurrentPage;
- (void)handleNotificationForMusic:(id)arg1;
- (void)playNextMusic;
- (void)sendMediaPlayWillStartNotify;
- (void)p_musicControl:(id)arg1;
- (void)viewDidLoad;
- (void)handleNotificationForPushNews;
- (void)dealloc;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

