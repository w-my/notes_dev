//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMUIView.h"

#import "EmoticonCameraDynamiFlowLayoutDelegate.h"
#import "UICollectionViewDataSource.h"
#import "UICollectionViewDelegate.h"
#import "UICollectionViewDelegateFlowLayout.h"

@class EmoticonCameraDynamiFlowLayout, NSArray, NSString, UICollectionView, UIView;

@interface EmoticonLensDynamicToolView : MMUIView <UICollectionViewDelegate, UICollectionViewDataSource, UICollectionViewDelegateFlowLayout, EmoticonCameraDynamiFlowLayoutDelegate>
{
    UIView *m_selectedMaterialBox;
    NSArray *m_emoticonLensList;
    unsigned long long m_scenes;
    id <EmoticonLensDynamicToolViewDelegate> _delegate;
    NSString *_selectedEmoticonLensId;
    unsigned long long _selectedEmoticonLensIndex;
    UICollectionView *_dynamicCollectionView;
    EmoticonCameraDynamiFlowLayout *_dynamicLayout;
}

+ (double)getHeight;
@property(retain, nonatomic) EmoticonCameraDynamiFlowLayout *dynamicLayout; // @synthesize dynamicLayout=_dynamicLayout;
@property(retain, nonatomic) UICollectionView *dynamicCollectionView; // @synthesize dynamicCollectionView=_dynamicCollectionView;
@property(nonatomic) unsigned long long selectedEmoticonLensIndex; // @synthesize selectedEmoticonLensIndex=_selectedEmoticonLensIndex;
@property(copy, nonatomic) NSString *selectedEmoticonLensId; // @synthesize selectedEmoticonLensId=_selectedEmoticonLensId;
@property(nonatomic) __weak id <EmoticonLensDynamicToolViewDelegate> delegate; // @synthesize delegate=_delegate;
- (void).cxx_destruct;
- (void)motionTmplSelectedItemAtIndexPath:(id)arg1;
- (void)selectEmoticonLensAtIndex:(unsigned long long)arg1;
- (void)selectEmoticonLensWithId:(id)arg1;
- (struct UIEdgeInsets)collectionView:(id)arg1 layout:(id)arg2 insetForSectionAtIndex:(long long)arg3;
- (struct CGSize)collectionView:(id)arg1 layout:(id)arg2 sizeForItemAtIndexPath:(id)arg3;
- (void)p_selectItemWithEmoticonLensItem:(id)arg1;
- (void)p_selectItemAtIndexPath:(id)arg1;
- (void)collectionView:(id)arg1 didSelectItemAtIndexPath:(id)arg2;
- (id)collectionView:(id)arg1 cellForItemAtIndexPath:(id)arg2;
- (long long)collectionView:(id)arg1 numberOfItemsInSection:(long long)arg2;
- (long long)numberOfSectionsInCollectionView:(id)arg1;
- (id)hitTest:(struct CGPoint)arg1 withEvent:(id)arg2;
- (id)initWithFrame:(struct CGRect)arg1 andScenes:(unsigned int)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

