//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMUIView.h"

#import "IContactMgrExt.h"
#import "IEnterpriseContactMgrExt.h"
#import "IHeadImageExt.h"
#import "IKFContactExt.h"
#import "IMsgExt.h"
#import "IStrangerContactMgrExt.h"
#import "IWCMyStoryUserStateUtilExt.h"
#import "LongPressImageViewDelegate.h"
#import "MMImageLoaderObserver.h"

@class CAShapeLayer, MMUIImageView, MMUILongPressImageView, NSString, UIImage, UIImageView;

@interface MMHeadImageView : MMUIView <IKFContactExt, IEnterpriseContactMgrExt, LongPressImageViewDelegate, IWCMyStoryUserStateUtilExt, MMImageLoaderObserver, IMsgExt, IHeadImageExt, IContactMgrExt, IStrangerContactMgrExt>
{
    MMUILongPressImageView *_headImageView;
    UIImageView *_borderImageView;
    NSString *_nsHeadImgUrl;
    NSString *_nsUsrName;
    _Bool _bAutoUpdate;
    struct CGSize _imageSize;
    UIImage *_borderImage;
    UIImage *_borderImageHL;
    _Bool _addBorder;
    _Bool _bRoundedCorner;
    id _oTarget;
    SEL _selAction;
    id _object;
    id _oLongPressTarget;
    SEL _selLongPressAction;
    id _oDoubleClickTarget;
    SEL _selDoubleClickAction;
    UIImageView *_sceneImageView;
    unsigned int _conerSize;
    UIImage *_defaultImage;
    unsigned char _headUseScene;
    unsigned char _headCategory;
    _Bool _isHeadImgExistedLocal;
    MMUIImageView *_storyMaskImageView;
    _Bool _shouldShowStoryMask;
    _Bool _showUnreadStoryMask;
    _Bool _addStoryMaskAction;
    _Bool _useWhiteBackGroundStoryIcon;
    CAShapeLayer *_unreadStoryShapeLayer;
}

@property(retain, nonatomic) CAShapeLayer *unreadStoryShapeLayer; // @synthesize unreadStoryShapeLayer=_unreadStoryShapeLayer;
@property(nonatomic) _Bool useWhiteBackGroundStoryIcon; // @synthesize useWhiteBackGroundStoryIcon=_useWhiteBackGroundStoryIcon;
@property(nonatomic) _Bool addStoryMaskAction; // @synthesize addStoryMaskAction=_addStoryMaskAction;
@property(nonatomic) _Bool showUnreadStoryMask; // @synthesize showUnreadStoryMask=_showUnreadStoryMask;
@property(nonatomic) _Bool shouldShowStoryMask; // @synthesize shouldShowStoryMask=_shouldShowStoryMask;
@property(nonatomic) unsigned char headCategory; // @synthesize headCategory=_headCategory;
@property(nonatomic) unsigned char headUseScene; // @synthesize headUseScene=_headUseScene;
@property(retain, nonatomic) UIImage *defaultImage; // @synthesize defaultImage=_defaultImage;
@property(nonatomic) unsigned int conerSize; // @synthesize conerSize=_conerSize;
@property(readonly, nonatomic) NSString *nsUsrName; // @synthesize nsUsrName=_nsUsrName;
@property(nonatomic) _Bool addBorder; // @synthesize addBorder=_addBorder;
@property(retain, nonatomic) UIImage *borderImageHL; // @synthesize borderImageHL=_borderImageHL;
@property(retain, nonatomic) UIImage *borderImage; // @synthesize borderImage=_borderImage;
@property(nonatomic) struct CGSize imageSize; // @synthesize imageSize=_imageSize;
- (void).cxx_destruct;
- (void)OnImageDoubleClick:(id)arg1;
- (void)OnLongPress:(id)arg1;
- (void)OnPress:(id)arg1;
- (void)onModifyEnterpriseContact:(id)arg1;
- (void)onStrangerContactUpdated:(id)arg1;
- (void)onModifyContact:(id)arg1;
- (void)setHeadImageViewBorderColor:(id)arg1 borderWidth:(double)arg2;
- (void)addSceneImageView:(long long)arg1;
- (void)ImageDidFail:(id)arg1;
- (void)ImageDidLoad:(id)arg1 Url:(id)arg2;
- (void)updateHeadImageUrl:(id)arg1;
- (void)updateHeadImage:(id)arg1;
- (void)setTargetForDoubleClick:(id)arg1 action:(SEL)arg2 inCell:(_Bool)arg3;
- (void)setTargetForDoubleClick:(id)arg1 action:(SEL)arg2;
- (void)setTargetForLongPress:(id)arg1 action:(SEL)arg2;
- (void)setTarget:(id)arg1 action:(SEL)arg2 withObject:(id)arg3;
- (void)setTarget:(id)arg1 action:(SEL)arg2;
- (void)onKFContactHeadImgUpdate:(id)arg1;
- (void)onHeadImageChange:(id)arg1;
- (void)onClearUnreadStoryMarkWithUserName:(id)arg1;
- (void)onSetUnreadStoryMarkWithUserName:(id)arg1;
- (void)updateExtensionRegister;
- (void)updateUsrName:(id)arg1 withHeadImgUrl:(id)arg2;
- (id)getRealUserName:(id)arg1;
- (void)doUpdateHeadImg:(_Bool)arg1;
- (void)checkAndUpdateImage;
- (_Bool)hasSetupUnreadStyle;
- (void)unSetupUnreadStyle;
- (void)setupUnReadStyle;
- (void)showUnreadStyle:(_Bool)arg1;
- (void)setHeadImageByName:(id)arg1;
- (void)layoutSubviews;
- (struct CGSize)intrinsicContentSize;
- (void)dealloc;
- (id)initWithUsrName:(id)arg1 headImgUrl:(id)arg2 bAutoUpdate:(_Bool)arg3 bRoundCorner:(_Bool)arg4;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

