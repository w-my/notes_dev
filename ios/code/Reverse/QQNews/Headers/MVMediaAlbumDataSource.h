//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class MVMediaAlbum, MVMediaPickerContext, NSArray, NSError, NSMutableArray, NSMutableDictionary;

@interface MVMediaAlbumDataSource : NSObject
{
    _Bool _isLoadingData;
    _Bool _reloadDataWhenMediaTypeChanged;
    MVMediaPickerContext *_context;
    NSArray *_albums;
    NSError *_lastError;
    MVMediaAlbum *_currentAlbum;
    CDUnknownBlockType _dataWillChange;
    CDUnknownBlockType _dataDidChange;
    long long _nextAlbumIndex;
    NSMutableArray *_allAlbums;
    NSMutableDictionary *_allAssetDataSources;
}

+ (id)dataSourceWithContext:(id)arg1;
@property(retain, nonatomic) NSMutableDictionary *allAssetDataSources; // @synthesize allAssetDataSources=_allAssetDataSources;
@property(retain, nonatomic) NSMutableArray *allAlbums; // @synthesize allAlbums=_allAlbums;
@property(nonatomic) long long nextAlbumIndex; // @synthesize nextAlbumIndex=_nextAlbumIndex;
@property(copy, nonatomic) CDUnknownBlockType dataDidChange; // @synthesize dataDidChange=_dataDidChange;
@property(copy, nonatomic) CDUnknownBlockType dataWillChange; // @synthesize dataWillChange=_dataWillChange;
@property(nonatomic) _Bool reloadDataWhenMediaTypeChanged; // @synthesize reloadDataWhenMediaTypeChanged=_reloadDataWhenMediaTypeChanged;
@property(retain, nonatomic) MVMediaAlbum *currentAlbum; // @synthesize currentAlbum=_currentAlbum;
@property(nonatomic) _Bool isLoadingData; // @synthesize isLoadingData=_isLoadingData;
@property(retain, nonatomic) NSError *lastError; // @synthesize lastError=_lastError;
@property(retain, nonatomic) NSArray *albums; // @synthesize albums=_albums;
@property(nonatomic) __weak MVMediaPickerContext *context; // @synthesize context=_context;
- (void).cxx_destruct;
- (void)clearSelection;
- (void)clearData;
- (void)prepareData;
- (void)reloadData;
- (id)assetDataSourceWithAlbum:(id)arg1;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
- (void)albumsDidChangedWithNotification:(id)arg1;
- (void)traceAssetDataSource:(id)arg1;
- (void)reloadCameraAlbumCompulsive:(_Bool)arg1;
- (void)updateAlbums:(id)arg1 error:(id)arg2;
- (id)albumsWithContents;
- (void)sortAllAlbums;
- (id)createAssetDataSourceWithAlbum:(id)arg1;
- (void)dealloc;
- (id)initWithContext:(id)arg1;

@end
