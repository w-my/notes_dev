//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MVBaseViewController.h"

#import "UIGestureRecognizerDelegate.h"

@class LKTouchThroughView, MVEditBottomBar, MVEditComponent, MVEditComponentBar, MVEditComponentFactory, MVEditTopBar, MVEditableMediaView, MVGradientView, MVModel, NSMutableArray, NSMutableDictionary, NSString, QZEVContext, UITapGestureRecognizer, UIView;

@interface MVEditViewController : MVBaseViewController <UIGestureRecognizerDelegate>
{
    _Bool _editable;
    _Bool _isReport;
    _Bool _discardsMediaWhenCancelEditing;
    _Bool _hideStatusBar;
    MVModel *_media;
    QZEVContext *_context;
    MVEditComponentFactory *_editComponentFactory;
    MVEditComponent *_currentEditComponent;
    long long _barMask;
    MVEditableMediaView *_mediaView;
    MVEditTopBar *_topBar;
    MVEditBottomBar *_bottomBar;
    UIView *_gestureView;
    LKTouchThroughView *_editingViewContainer;
    CDUnknownBlockType _didFinishEditing;
    CDUnknownBlockType _didCancelEditing;
    CDUnknownBlockType _willDeleteMedia;
    UIView *_contentViewContainer;
    MVEditComponentBar *_componentBar;
    MVGradientView *_topGradientView;
    MVGradientView *_bottomGradientView;
    UITapGestureRecognizer *_releaseFocusGesture;
    UITapGestureRecognizer *_cancelEditingGesture;
    NSMutableArray *_editComponents;
    NSMutableDictionary *_componentEditingViews;
    struct CGSize _mediaSize;
    struct CGSize _mediaDisplayingSize;
    struct CGRect _contentBoundingRect;
}

+ (void)initialize;
@property(nonatomic) struct CGSize mediaDisplayingSize; // @synthesize mediaDisplayingSize=_mediaDisplayingSize;
@property(nonatomic) _Bool hideStatusBar; // @synthesize hideStatusBar=_hideStatusBar;
@property(retain, nonatomic) NSMutableDictionary *componentEditingViews; // @synthesize componentEditingViews=_componentEditingViews;
@property(retain, nonatomic) NSMutableArray *editComponents; // @synthesize editComponents=_editComponents;
@property(nonatomic) __weak UITapGestureRecognizer *cancelEditingGesture; // @synthesize cancelEditingGesture=_cancelEditingGesture;
@property(nonatomic) __weak UITapGestureRecognizer *releaseFocusGesture; // @synthesize releaseFocusGesture=_releaseFocusGesture;
@property(nonatomic) __weak MVGradientView *bottomGradientView; // @synthesize bottomGradientView=_bottomGradientView;
@property(nonatomic) __weak MVGradientView *topGradientView; // @synthesize topGradientView=_topGradientView;
@property(nonatomic) __weak MVEditComponentBar *componentBar; // @synthesize componentBar=_componentBar;
@property(nonatomic) __weak UIView *contentViewContainer; // @synthesize contentViewContainer=_contentViewContainer;
@property(copy, nonatomic) CDUnknownBlockType willDeleteMedia; // @synthesize willDeleteMedia=_willDeleteMedia;
@property(copy, nonatomic) CDUnknownBlockType didCancelEditing; // @synthesize didCancelEditing=_didCancelEditing;
@property(copy, nonatomic) CDUnknownBlockType didFinishEditing; // @synthesize didFinishEditing=_didFinishEditing;
@property(nonatomic) _Bool discardsMediaWhenCancelEditing; // @synthesize discardsMediaWhenCancelEditing=_discardsMediaWhenCancelEditing;
@property(readonly, nonatomic) __weak LKTouchThroughView *editingViewContainer; // @synthesize editingViewContainer=_editingViewContainer;
@property(readonly, nonatomic) __weak UIView *gestureView; // @synthesize gestureView=_gestureView;
@property(readonly, nonatomic) __weak MVEditBottomBar *bottomBar; // @synthesize bottomBar=_bottomBar;
@property(readonly, nonatomic) __weak MVEditTopBar *topBar; // @synthesize topBar=_topBar;
@property(retain, nonatomic) MVEditableMediaView *mediaView; // @synthesize mediaView=_mediaView;
@property(nonatomic) struct CGRect contentBoundingRect; // @synthesize contentBoundingRect=_contentBoundingRect;
@property(nonatomic) struct CGSize mediaSize; // @synthesize mediaSize=_mediaSize;
@property(nonatomic) long long barMask; // @synthesize barMask=_barMask;
@property(nonatomic) _Bool isReport; // @synthesize isReport=_isReport;
@property(nonatomic) _Bool editable; // @synthesize editable=_editable;
@property(retain, nonatomic) MVEditComponent *currentEditComponent; // @synthesize currentEditComponent=_currentEditComponent;
@property(retain, nonatomic) MVEditComponentFactory *editComponentFactory; // @synthesize editComponentFactory=_editComponentFactory;
@property(retain, nonatomic) QZEVContext *context; // @synthesize context=_context;
@property(retain, nonatomic) MVModel *media; // @synthesize media=_media;
- (void).cxx_destruct;
- (void)stopPreview;
- (void)pausePreview;
- (void)startPreview;
- (_Bool)gestureRecognizer:(id)arg1 shouldRecognizeSimultaneouslyWithGestureRecognizer:(id)arg2;
- (void)handleGesture:(id)arg1;
- (void)editComponent:(id)arg1 sendEnvent:(id)arg2;
- (void)editComponent:(id)arg1 willSetMediaDisplayingRect:(struct CGRect)arg2;
- (void)editComponent:(id)arg1 willSetEditMode:(long long)arg2 animated:(_Bool)arg3;
- (void)editComponent:(id)arg1 willSetEditing:(_Bool)arg2 animated:(_Bool)arg3;
- (void)performAnimated:(_Bool)arg1 animations:(CDUnknownBlockType)arg2 completion:(CDUnknownBlockType)arg3;
- (void)releaseFocusOfAllEditComponents;
- (void)releaseFocusOfEditComponentsWithExcept:(id)arg1;
- (void)setEditMode:(long long)arg1 forComponent:(id)arg2 animated:(_Bool)arg3;
- (void)resignEditingViewsWithExceptComponent:(id)arg1;
- (id)resignEditingViewOfComponent:(id)arg1;
- (void)activateEditingViewsForComponentsIfNeeded;
- (id)activateEditingViewOfComponent:(id)arg1;
- (void)resignEditComponent:(id)arg1 forFinishingEditing:(_Bool)arg2 animated:(_Bool)arg3;
- (void)activateEditComponent:(id)arg1 animated:(_Bool)arg2;
- (void)setCurrentEditComponent:(id)arg1 animated:(_Bool)arg2;
- (void)selectEditComponent:(id)arg1 animated:(_Bool)arg2;
- (_Bool)shouldExit;
- (void)queryCancelEditing;
- (id)currentMediaMakerController;
- (void)publish;
- (void)deleteMedia;
- (_Bool)shouldDeleteMedia;
- (void)cancelEditing;
- (_Bool)shouldCancelEditing;
- (void)finishEditingWithAction:(long long)arg1;
- (void)discardEditingContents;
- (void)resignEditingForFinishing:(_Bool)arg1;
- (void)setContentDisplayingFrame:(struct CGRect)arg1;
- (void)updateByCurrentEditableState;
- (void)initGestures;
- (void)initComponentViewContainer;
- (void)initGradientViews;
- (void)initVideoProgressView;
- (void)initMediaView;
- (void)initComponentsBar;
- (void)initBottomBar;
- (void)initTopBar;
- (void)onShouldHideStatusBar;
- (void)onShouldShowStatusBar;
- (long long)preferredStatusBarStyle;
- (_Bool)prefersStatusBarHidden;
- (void)viewDidDisappear:(_Bool)arg1;
- (void)viewDidAppear:(_Bool)arg1;
- (void)viewDidLoad;
- (void)dealloc;
- (id)init;
- (void)publish;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
