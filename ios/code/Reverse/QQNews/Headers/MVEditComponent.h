//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "MVMediaContentComponent.h"

@class MVEditComponentTabItem, MVEditEngine, MVEditionManager, MVModel, NSString, UIView, UIViewController<MVEditComponentDelegate>;

@interface MVEditComponent : NSObject <MVMediaContentComponent>
{
    _Bool _active;
    _Bool _editable;
    _Bool _hidesBottomBarWhenActive;
    UIViewController<MVEditComponentDelegate> *_parentViewController;
    MVModel *_model;
    MVEditComponentTabItem *_tabItem;
    MVEditEngine *_editEngine;
    id <MVPlayControl> _playControl;
    UIView *_gestureView;
    double _rotateRadian;
    double _contentScale;
    double _edgeScale;
    NSString *_cid;
    long long _editingViewDisplayMode;
    MVEditionManager *_editionManager;
    struct CGSize _mediaSize;
    struct CGRect _bounds;
    struct CGRect _contentBoundingRect;
    struct CGRect _contentDisplayingFrame;
}

@property(retain, nonatomic) MVEditionManager *editionManager; // @synthesize editionManager=_editionManager;
@property(nonatomic) long long editingViewDisplayMode; // @synthesize editingViewDisplayMode=_editingViewDisplayMode;
@property(nonatomic) _Bool hidesBottomBarWhenActive; // @synthesize hidesBottomBarWhenActive=_hidesBottomBarWhenActive;
@property(copy, nonatomic) NSString *cid; // @synthesize cid=_cid;
@property(readonly, nonatomic) double edgeScale; // @synthesize edgeScale=_edgeScale;
@property(readonly, nonatomic) double contentScale; // @synthesize contentScale=_contentScale;
@property(readonly, nonatomic) double rotateRadian; // @synthesize rotateRadian=_rotateRadian;
@property(nonatomic) __weak UIView *gestureView; // @synthesize gestureView=_gestureView;
@property(readonly, nonatomic) __weak id <MVPlayControl> playControl; // @synthesize playControl=_playControl;
@property(readonly, nonatomic) __weak MVEditEngine *editEngine; // @synthesize editEngine=_editEngine;
@property(readonly, nonatomic) struct CGRect contentDisplayingFrame; // @synthesize contentDisplayingFrame=_contentDisplayingFrame;
@property(readonly, nonatomic) struct CGRect contentBoundingRect; // @synthesize contentBoundingRect=_contentBoundingRect;
@property(readonly, nonatomic) struct CGRect bounds; // @synthesize bounds=_bounds;
@property(readonly, nonatomic) struct CGSize mediaSize; // @synthesize mediaSize=_mediaSize;
@property(readonly, nonatomic) _Bool editable; // @synthesize editable=_editable;
@property(readonly, nonatomic) _Bool active; // @synthesize active=_active;
@property(readonly, nonatomic) MVEditComponentTabItem *tabItem; // @synthesize tabItem=_tabItem;
@property(retain, nonatomic) MVModel *model; // @synthesize model=_model;
@property(nonatomic) __weak UIViewController<MVEditComponentDelegate> *parentViewController; // @synthesize parentViewController=_parentViewController;
- (void).cxx_destruct;
- (void)saveDraft;
- (void)didCropToRect:(struct CGRect)arg1 andAngle:(long long)arg2;
- (void)presentViewController:(id)arg1 animated:(_Bool)arg2 completion:(CDUnknownBlockType)arg3;
- (void)sendEvent:(id)arg1;
- (void)setMediaDisplayingRect:(struct CGRect)arg1;
- (void)setEditMode:(long long)arg1 animated:(_Bool)arg2;
- (void)setEditing:(_Bool)arg1 animated:(_Bool)arg2;
- (void)updateRotateRadian:(double)arg1 contentScale:(double)arg2 edgeScale:(double)arg3;
- (void)didReceiveEvent:(id)arg1;
- (_Bool)handleGesture:(id)arg1;
- (void)resignActiveAnimated:(_Bool)arg1;
- (void)becomeActiveAnimated:(_Bool)arg1;
- (void)select;
- (void)didChangeContentDisplayingFrame:(struct CGRect)arg1;
- (void)didChangeContentBoundingRect:(struct CGRect)arg1;
- (void)didChangeToEditable:(_Bool)arg1;
- (void)lostFocus;
- (struct CGRect)rectForDisplayingMediaInBounds:(struct CGRect)arg1;
- (id)editingViewWithBoundingRect:(struct CGRect)arg1;
- (id)contentViewWithFrame:(struct CGRect)arg1;
- (void)willUnload;
- (void)didLoad;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

