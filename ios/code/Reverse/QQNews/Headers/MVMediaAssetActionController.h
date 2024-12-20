//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class MVMediaPickerContext, NSMutableArray, UIViewController;

@interface MVMediaAssetActionController : NSObject
{
    _Bool _isFilteringAssets;
    UIViewController *_viewController;
    MVMediaPickerContext *_context;
    NSMutableArray *_selectedAssets;
    NSMutableArray *_selectedIndexPaths;
}

+ (id)instantiateWithContext:(id)arg1;
@property(retain, nonatomic) NSMutableArray *selectedIndexPaths; // @synthesize selectedIndexPaths=_selectedIndexPaths;
@property(retain, nonatomic) NSMutableArray *selectedAssets; // @synthesize selectedAssets=_selectedAssets;
@property(nonatomic) __weak MVMediaPickerContext *context; // @synthesize context=_context;
@property(nonatomic) __weak UIViewController *viewController; // @synthesize viewController=_viewController;
@property(nonatomic) _Bool isFilteringAssets; // @synthesize isFilteringAssets=_isFilteringAssets;
- (void).cxx_destruct;
- (void)finishPickingIfNeeded;
- (void)filterAssets:(id)arg1 withSection:(long long)arg2 rowRange:(struct _NSRange)arg3 completion:(CDUnknownBlockType)arg4;
- (void)filterAsset:(id)arg1 withIndexPath:(id)arg2 completion:(CDUnknownBlockType)arg3;
- (void)filterAssets:(id)arg1 withIndexPaths:(id)arg2 completion:(CDUnknownBlockType)arg3;
- (void)filterSelectedAssetsByImageSize;
- (void)filterSelectedAssetsByDelegateWithCompletion:(CDUnknownBlockType)arg1;
- (void)filterSelectedAssetsBySelectionCount;
- (void)showTipWithMessage:(id)arg1;
- (id)pickerController;

@end

