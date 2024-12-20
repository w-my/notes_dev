//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMUIView.h"

#import "MMAssetPickerControllerExt.h"
#import "WCForceTouchPreviewProtocol.h"

@class MMAssetSelectCheckButton, MMNearbyAssetInfo, MMNearbyAssetPickerViewController, NSString, UIImageView, UILabel, UIView;

@interface MMNearbyAssetView : MMUIView <MMAssetPickerControllerExt, WCForceTouchPreviewProtocol>
{
    _Bool m_isSelected;
    _Bool m_isPreviewStyle;
    UIView *m_disabledMaskView;
    UIView *m_tagBackgroundView;
    UILabel *m_lengthLabel;
    UIView *m_videoLogoView;
    UILabel *m_gifLogoView;
    UIView *m_editImageView;
    MMAssetSelectCheckButton *m_selectCheckButton;
    _Bool _enabled;
    MMNearbyAssetInfo *_assetInfo;
    id <MMImagePickerControlCenter> _controlCenter;
    id <MMNearbyAssetViewDelegate> _delegate;
    id <MMNearbyAssetViewDataSource> _datasource;
    MMNearbyAssetPickerViewController *_parent;
    UIImageView *_m_assetImageView;
}

@property(retain, nonatomic) UIImageView *m_assetImageView; // @synthesize m_assetImageView=_m_assetImageView;
@property(nonatomic) _Bool enabled; // @synthesize enabled=_enabled;
@property(nonatomic) __weak MMNearbyAssetPickerViewController *parent; // @synthesize parent=_parent;
@property(nonatomic) __weak id <MMNearbyAssetViewDataSource> datasource; // @synthesize datasource=_datasource;
@property(nonatomic) __weak id <MMNearbyAssetViewDelegate> delegate; // @synthesize delegate=_delegate;
@property(nonatomic) __weak id <MMImagePickerControlCenter> controlCenter; // @synthesize controlCenter=_controlCenter;
@property(retain, nonatomic) MMNearbyAssetInfo *assetInfo; // @synthesize assetInfo=_assetInfo;
- (void).cxx_destruct;
- (void)onAssetPickerControllerFinishEditAssetInfo:(id)arg1;
- (void)onAssetPickerControllerChangeSelectInfosOrder;
- (void)onAssetPickerControllerChangeSelectInfo:(id)arg1 index:(long long)arg2;
- (struct CGRect)previewingSourceRectForLocation:(struct CGPoint)arg1 inCoordinateView:(id)arg2;
- (id)viewControllerToPreviewWithFromController:(id)arg1 forLocation:(struct CGPoint)arg2 inCoordinateView:(id)arg3;
- (_Bool)canPeek;
- (id)timeStringBySeconds:(double)arg1;
- (_Bool)checkThumbImage;
- (void)doSelect;
- (void)doSelectWithStateInfo:(id)arg1;
- (void)tryToSelectGifWithImage:(id)arg1 imageData:(id)arg2;
- (void)tryToSelectVideoWithAvAsset:(id)arg1 videoUrl:(id)arg2;
- (void)tryToSelectAsset;
- (void)tagAseetToPreview;
- (void)toggleSelection;
- (void)showedSelectedMarkWithIndex:(long long)arg1 animated:(_Bool)arg2;
- (struct CGPoint)accessibilityActivationPoint;
- (id)accessibilityLabel;
- (_Bool)isAccessibilityElement;
- (unsigned long long)accessibilityTraits;
- (id)accessibilityHint;
- (_Bool)accessibilityPerformMagicTap;
- (void)updateEnabledState;
- (void)showEditedLogoView;
- (void)showGifLogoView;
- (void)showVideoLogoViewWithTime:(id)arg1;
- (void)showTagBGView;
- (double)tagLogoLBMargin;
- (void)changeToSmallPreviewStyle;
- (void)updateAssetInfo;
- (id)initWithFrame:(struct CGRect)arg1;
- (void)dealloc;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

