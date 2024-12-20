//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMUIView.h"

#import "EditImageEmotionToolAttrDelegate.h"
#import "EditImageOperationDelegate.h"
#import "EditImagePenToolAttrDelegate.h"
#import "EditVideoBgmViewDelegate.h"
#import "EditVideoCropViewDelegate.h"
#import "EditVideoLogicItemExt.h"
#import "IMMAssetICloudExt.h"
#import "IUiUtilExt.h"
#import "UIGestureRecognizerDelegate.h"
#import "WCStoryEditVideoTextViewControllerDelegate.h"

@class AVAsset, EVVideoPreviewBrowserView, EditImageEmotionToolAttrView, EditImagePenToolAttrView, EditImageScrollView, EditStoryImageAttr, EditVideoBGMView, EditVideoCropView, EditVideoMusicController, MMUIButton, MMUIImageView, NSMutableArray, NSString, UITapGestureRecognizer, UIView, WCStoryMultiModeButton, WCStoryPublishReportObj;

@interface EditVideoInitialView : MMUIView <EditImageEmotionToolAttrDelegate, EditVideoCropViewDelegate, EditVideoLogicItemExt, EditVideoBgmViewDelegate, WCStoryEditVideoTextViewControllerDelegate, UIGestureRecognizerDelegate, EditImageOperationDelegate, EditImagePenToolAttrDelegate, IUiUtilExt, IMMAssetICloudExt>
{
    EVVideoPreviewBrowserView *_videoPreview;
    EditImageScrollView *_eIScrollView;
    MMUIView *_topBarView;
    MMUIImageView *_topBackgroundView;
    MMUIButton *_cancelBtn;
    MMUIButton *_doneBtn;
    MMUIView *_bottomBarView;
    MMUIImageView *_bottomBackgroundView;
    MMUIButton *_penBtn;
    EditImagePenToolAttrView *_penAttrBar;
    MMUIButton *_emotionBtn;
    EditImageEmotionToolAttrView *_emotionAttrView;
    MMUIButton *_textBtn;
    MMUIButton *_cropBtn;
    EditVideoCropView *_cropAttrView;
    WCStoryMultiModeButton *_bgmBtn;
    EditVideoBGMView *_bgmAttrView;
    MMUIButton *_sendBtn;
    WCStoryMultiModeButton *_poiBtn;
    int _lastToolType;
    _Bool _isToolBarOccupy;
    double _lastScale;
    double _lastMinScale;
    double _lastMaxScale;
    struct CGSize _lastContentSize;
    struct CGPoint _lastContentOffset;
    double _previewLastScale;
    double _previewLastMinScale;
    double _previewLastMaxScale;
    struct CGSize _previewLastContentSize;
    struct CGPoint _previewLastContentOffset;
    _Bool _bCropping;
    _Bool _bIsCroped;
    _Bool _hideVideoOriginalSound;
    AVAsset *avAsset;
    id <EditVideoInitialViewDelegate> delegate;
    unsigned long long _entranceType;
    unsigned long long _editImageUIStyle;
    WCStoryPublishReportObj *_publishReportObj;
    EditStoryImageAttr *_storyAttr;
    UITapGestureRecognizer *_BGMTapGesture;
    MMUIButton *_moreActionButton;
    MMUIImageView *_scopeImageView;
    MMUIButton *_textInputTipsView;
    UIView *_lineView;
    NSMutableArray *_currentMusicLyrics;
    EditVideoMusicController *_musicController;
}

@property(retain, nonatomic) EditVideoMusicController *musicController; // @synthesize musicController=_musicController;
@property(retain, nonatomic) NSMutableArray *currentMusicLyrics; // @synthesize currentMusicLyrics=_currentMusicLyrics;
@property(retain, nonatomic) UIView *lineView; // @synthesize lineView=_lineView;
@property(retain, nonatomic) MMUIButton *textInputTipsView; // @synthesize textInputTipsView=_textInputTipsView;
@property(retain, nonatomic) MMUIImageView *scopeImageView; // @synthesize scopeImageView=_scopeImageView;
@property(retain, nonatomic) MMUIButton *moreActionButton; // @synthesize moreActionButton=_moreActionButton;
@property(retain, nonatomic) EVVideoPreviewBrowserView *videoPreview; // @synthesize videoPreview=_videoPreview;
@property(retain, nonatomic) UITapGestureRecognizer *BGMTapGesture; // @synthesize BGMTapGesture=_BGMTapGesture;
@property(retain, nonatomic) EditStoryImageAttr *storyAttr; // @synthesize storyAttr=_storyAttr;
@property(nonatomic) _Bool hideVideoOriginalSound; // @synthesize hideVideoOriginalSound=_hideVideoOriginalSound;
@property(retain, nonatomic) WCStoryPublishReportObj *publishReportObj; // @synthesize publishReportObj=_publishReportObj;
@property(nonatomic) unsigned long long editImageUIStyle; // @synthesize editImageUIStyle=_editImageUIStyle;
@property(nonatomic) unsigned long long entranceType; // @synthesize entranceType=_entranceType;
@property(nonatomic) __weak id <EditVideoInitialViewDelegate> delegate; // @synthesize delegate;
@property(retain, nonatomic) AVAsset *avAsset; // @synthesize avAsset;
- (void).cxx_destruct;
- (void)storyEditVideoTextViewControllerDidCommit:(id)arg1 textView:(id)arg2 textString:(id)arg3;
- (void)storyEditVideoTextViewControllerCancelEdit:(id)arg1;
- (void)onRestartVideoPlayAt:(double)arg1;
- (void)EditVideoBGMViewLyricUpdate:(id)arg1;
- (void)EditVideoBGMViewMusicOnOffStateChange:(_Bool)arg1;
- (void)EditVideoBGMViewLyricOnOffStateChange:(_Bool)arg1;
- (void)EditVideoBGMViewDidClickTurnOffMusicButton:(_Bool)arg1;
- (void)EditVideoBGMDone:(id)arg1;
- (void)onCropTimeChange:(CDStruct_e83c9415)arg1;
- (void)seekToTime:(double)arg1;
- (void)onEditSuccess:(_Bool)arg1 withTimeRange:(CDStruct_e83c9415)arg2;
- (void)onAddNewPOIWidget;
- (void)onTapGesture;
- (void)onAddRealNewMainTextWidget;
- (void)dragaAndDropWidget;
- (_Bool)scrollViewDidEndZooming:(id)arg1 withView:(id)arg2 atScale:(double)arg3;
- (_Bool)scrollViewDidZoom:(id)arg1;
- (void)editImageViewPOIWidgetHiddenStateChange:(_Bool)arg1;
- (void)editImageViewLyricsWidgetHadBeenDoubleTap;
- (void)editImageViewLyricsWidgetHadBeenDeleted;
- (void)editImageViewdidEndDraw;
- (void)editImageViewDidStartDraw;
- (void)didSelectEmotion:(id)arg1 withMd5:(id)arg2;
- (void)onEmotionToolBarDoneBtnClicked;
- (void)setSelectedLineStyle:(unsigned long long)arg1;
- (void)undoPenEditImage;
- (void)setSelectedColorFromGradientBar:(id)arg1;
- (void)clearEmotionToolOperation;
- (void)onEmotionToolBarDoneBtnClicked:(_Bool)arg1;
- (void)startEmotionTool;
- (void)selectLastToolType;
- (void)updateToolBtns;
- (void)updateBtns;
- (void)showEditVideoTextViewControllerWithText:(id)arg1;
- (void)onClickMainTextBtn;
- (void)onClickPoiBtn;
- (void)onClickBGMEdit:(id)arg1;
- (void)onClickCropEdit:(id)arg1;
- (void)onClickTextEdit:(id)arg1;
- (void)onClickEmotionEdit:(id)arg1;
- (void)onClickPenEdit:(id)arg1;
- (void)onClickDone;
- (void)onClickCancel;
- (void)firstShowCrop;
- (void)layoutScrollView:(double)arg1;
- (void)showCropVideo:(_Bool)arg1;
- (void)easeInOutTopAndBottomBar:(_Bool)arg1;
- (void)setBGMToolAttrViewHidden:(_Bool)arg1;
- (void)setEmotionToolAttrViewHidden:(_Bool)arg1;
- (void)setEditImageToolBarHiddenWithAnimationWithoutCompletionHandlerWithoutOccupy:(_Bool)arg1;
- (void)setEditImageToolBarHiddenWithAnimationWithoutCompletionHandler:(_Bool)arg1;
- (void)setEditButtonStoryTypeWithButton:(id)arg1 buttonWidth:(double)arg2 margin:(double)arg3;
- (_Bool)gestureRecognizer:(id)arg1 shouldReceiveTouch:(id)arg2;
- (_Bool)highlightWidgetToolIsSelected;
- (void)handlePanGesture:(id)arg1;
- (void)reloadBottomEditVideoBar;
- (void)reloadTopEditVideoBar;
- (void)reloadCropToolAttrBar;
- (void)reloadEmotionToolAttrBar;
- (void)reloadPenToolAttrBar;
- (void)initDefaultTextInputTipsView;
- (void)clickMoreAction;
- (void)initMoreActionButton;
- (void)initEditImageView;
- (void)initVideoPreview;
- (void)initCropToolAttrBar;
- (void)initCropBtn;
- (void)initSendBtn;
- (void)initPoiBtn;
- (void)initBGMBtn;
- (void)playMusic;
- (void)initBgmLogic;
- (void)initBGMLogicAndBtn;
- (void)initTextToolAttrBar;
- (void)initBGMToolAttrBar;
- (void)initEmotionToolAttrBar;
- (void)initEmotionBtn;
- (void)initPenToolAttrBar;
- (void)initBottomBar;
- (void)initTopBar;
- (void)initView;
- (id)getEditImageAttr;
- (id)getStoryAttr;
- (void)onClickBGMBtn;
- (void)onClickDoneBtn:(CDUnknownBlockType)arg1;
- (void)onEditVideo;
- (void)dealloc;
- (id)initWithFrame:(struct CGRect)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

