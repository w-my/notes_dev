//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableView.h"

#import "UICollectionViewDataSource.h"
#import "UICollectionViewDelegateFlowLayout.h"

@class NSArray, NSMutableDictionary, NSString, UICollectionView, UIImageView;

@interface QSWorldCupNewsEntranceView : QNThemableView <UICollectionViewDelegateFlowLayout, UICollectionViewDataSource>
{
    double _leftMargin;
    double _rightMargin;
    NSArray *_tabInfos;
    UIImageView *_backgroundImageView;
    UICollectionView *_collectionView;
    NSMutableDictionary *_imageLoaderDictionary;
}

@property(retain, nonatomic) NSMutableDictionary *imageLoaderDictionary; // @synthesize imageLoaderDictionary=_imageLoaderDictionary;
@property(retain, nonatomic) UICollectionView *collectionView; // @synthesize collectionView=_collectionView;
@property(retain, nonatomic) UIImageView *backgroundImageView; // @synthesize backgroundImageView=_backgroundImageView;
@property(retain, nonatomic) NSArray *tabInfos; // @synthesize tabInfos=_tabInfos;
@property(nonatomic) double rightMargin; // @synthesize rightMargin=_rightMargin;
@property(nonatomic) double leftMargin; // @synthesize leftMargin=_leftMargin;
- (void).cxx_destruct;
- (void)makeBossReport;
- (struct CGSize)collectionView:(id)arg1 layout:(id)arg2 sizeForItemAtIndexPath:(id)arg3;
- (id)collectionView:(id)arg1 cellForItemAtIndexPath:(id)arg2;
- (long long)collectionView:(id)arg1 numberOfItemsInSection:(long long)arg2;
- (void)collectionView:(id)arg1 didSelectItemAtIndexPath:(id)arg2;
- (void)scrollViewDidEndDecelerating:(id)arg1;
- (void)scrollViewDidEndDragging:(id)arg1 willDecelerate:(_Bool)arg2;
- (void)dealloc;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
- (void)updateCollectionViewContentInset;
- (void)imageDidFinishLoad;
- (void)downloadAdLogos;
- (void)themeChanged:(long long)arg1;
- (id)initWithFrame:(struct CGRect)arg1;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
