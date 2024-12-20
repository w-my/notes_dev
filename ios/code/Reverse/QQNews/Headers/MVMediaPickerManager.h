//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class MVMediaNotificationManager, MVMediaPickerContext, NSMutableDictionary;

@interface MVMediaPickerManager : NSObject
{
    MVMediaPickerContext *_context;
    MVMediaNotificationManager *_notificationManager;
    NSMutableDictionary *_currentRequests;
    NSMutableDictionary *_fetchedResults;
}

+ (long long)PHAssetMediaTypeFromMediaType:(long long)arg1;
+ (id)ALAssetPropertyTypeFromMediaType:(long long)arg1;
+ (long long)MVMediaAssetTypeFromPHAssetMediaType:(long long)arg1;
+ (long long)MVMediaAssetTypeFromALAssetPropertyType:(id)arg1;
+ (id)managerWithContext:(id)arg1;
@property(retain, nonatomic) NSMutableDictionary *fetchedResults; // @synthesize fetchedResults=_fetchedResults;
@property(retain, nonatomic) NSMutableDictionary *currentRequests; // @synthesize currentRequests=_currentRequests;
@property(retain, nonatomic) MVMediaNotificationManager *notificationManager; // @synthesize notificationManager=_notificationManager;
@property(nonatomic) __weak MVMediaPickerContext *context; // @synthesize context=_context;
- (void).cxx_destruct;
- (void)loadLatestAssetForMediaType:(long long)arg1 completion:(CDUnknownBlockType)arg2;
- (void)loadAssetWithIdentifier:(id)arg1 completion:(CDUnknownBlockType)arg2;
- (void)loadAssetCountAndLatestAssetForAlbum:(id)arg1;
- (void)loadAssetsWithAlbum:(id)arg1 completion:(CDUnknownBlockType)arg2;
- (void)loadAlbumsWithCompletion:(CDUnknownBlockType)arg1;
- (void)loadALAssetWithURL:(id)arg1 completion:(CDUnknownBlockType)arg2;
- (void)loadAssetsInALAssetsLibraryWithAlbum:(id)arg1 completion:(CDUnknownBlockType)arg2;
- (void)loadAlbumsInALAssetsLibraryWithCompletion:(CDUnknownBlockType)arg1;
- (id)assetsFilterWithMediaType:(long long)arg1;
- (void)loadLatestAssetInPHPhotoLibraryWithMediaType:(long long)arg1 completion:(CDUnknownBlockType)arg2;
- (void)loadAssetCountAndLatestAssetInPHPhotoLibraryForAlbum:(id)arg1;
- (void)loadPHAssetWithIdentifier:(id)arg1 completion:(CDUnknownBlockType)arg2;
- (void)loadKeyAssetInPHPhotoLibraryWithAlbum:(id)arg1 completion:(CDUnknownBlockType)arg2;
- (id)loadAssetsInPHPhotoLibraryWithAlbum:(id)arg1 completion:(CDUnknownBlockType)arg2;
- (void)loadAlbumsInPHPhotoLibraryWithCompletion:(CDUnknownBlockType)arg1;
- (id)albumsWithPHFetchResult:(id)arg1 isSystem:(_Bool)arg2;
- (id)fetchOptionsForAssetsWithMediaType:(long long)arg1;
- (void)savePHFetchResult:(id)arg1 withType:(long long)arg2 associatedAlbum:(id)arg3;
- (_Bool)assetCollection:(id)arg1 isMatchMediaType:(long long)arg2;
- (void)finishLoadingAssets:(id)arg1 error:(id)arg2 forAlbum:(id)arg3 completion:(CDUnknownBlockType)arg4;
- (void)filterAssets:(id)arg1 completion:(CDUnknownBlockType)arg2;
- (void)didCreateAssets:(id)arg1;
- (void)didCreateAlbums:(id)arg1;
- (void)dealloc;
- (void)initNotificationManager;
- (id)initWithContext:(id)arg1;

@end

