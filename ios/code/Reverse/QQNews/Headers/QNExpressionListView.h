//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

#import "QNSearchBarControlDelegate.h"
#import "UICollectionViewDataSource.h"
#import "UICollectionViewDelegateFlowLayout.h"

@class CALayer, NSString, QNExpressionSearchSuggestView, QNExpressionViewModel, QNListNewsItem, QNLoadingCircleLayer, QNSearchBarControl, UIButton, UICollectionView, UILabel;

@interface QNExpressionListView : UIView <UICollectionViewDelegateFlowLayout, UICollectionViewDataSource, QNSearchBarControlDelegate>
{
    _Bool _isDarkMode;
    _Bool _hasReportSlide;
    UICollectionView *_collectionView;
    NSString *_currentSearchWord;
    CDUnknownBlockType _searchCancelBlock;
    CDUnknownBlockType _selectedBlock;
    CDUnknownBlockType _scrollBlock;
    CDUnknownBlockType _searchCompleteAndReLayoutBlock;
    QNListNewsItem *_listItem;
    long long _currentType;
    QNExpressionViewModel *_viewModel;
    UIButton *_refreshButton;
    QNLoadingCircleLayer *_loadingLayer;
    QNSearchBarControl *_searchBar;
    QNExpressionSearchSuggestView *_searchSuggestView;
    CALayer *_sepLine;
    UILabel *_titleView;
}

@property(nonatomic) _Bool hasReportSlide; // @synthesize hasReportSlide=_hasReportSlide;
@property(retain, nonatomic) UILabel *titleView; // @synthesize titleView=_titleView;
@property(retain, nonatomic) CALayer *sepLine; // @synthesize sepLine=_sepLine;
@property(retain, nonatomic) QNExpressionSearchSuggestView *searchSuggestView; // @synthesize searchSuggestView=_searchSuggestView;
@property(retain, nonatomic) QNSearchBarControl *searchBar; // @synthesize searchBar=_searchBar;
@property(retain, nonatomic) QNLoadingCircleLayer *loadingLayer; // @synthesize loadingLayer=_loadingLayer;
@property(retain, nonatomic) UIButton *refreshButton; // @synthesize refreshButton=_refreshButton;
@property(retain, nonatomic) QNExpressionViewModel *viewModel; // @synthesize viewModel=_viewModel;
@property(nonatomic) long long currentType; // @synthesize currentType=_currentType;
@property(nonatomic) _Bool isDarkMode; // @synthesize isDarkMode=_isDarkMode;
@property(retain, nonatomic) QNListNewsItem *listItem; // @synthesize listItem=_listItem;
@property(copy, nonatomic) CDUnknownBlockType searchCompleteAndReLayoutBlock; // @synthesize searchCompleteAndReLayoutBlock=_searchCompleteAndReLayoutBlock;
@property(copy, nonatomic) CDUnknownBlockType scrollBlock; // @synthesize scrollBlock=_scrollBlock;
@property(copy, nonatomic) CDUnknownBlockType selectedBlock; // @synthesize selectedBlock=_selectedBlock;
@property(copy, nonatomic) CDUnknownBlockType searchCancelBlock; // @synthesize searchCancelBlock=_searchCancelBlock;
@property(copy, nonatomic) NSString *currentSearchWord; // @synthesize currentSearchWord=_currentSearchWord;
@property(retain, nonatomic) UICollectionView *collectionView; // @synthesize collectionView=_collectionView;
- (void).cxx_destruct;
- (void)p_search;
- (void)p_searchWordDidChange:(id)arg1;
- (void)p_layoutSearchSuggestMode;
- (void)searchBarCleanBtnAction:(id)arg1;
- (_Bool)searchBarShouldReturn:(id)arg1;
- (void)searchEndEditing:(id)arg1;
- (void)searchCancel:(id)arg1;
- (void)scrollViewDidScroll:(id)arg1;
- (void)collectionView:(id)arg1 didSelectItemAtIndexPath:(id)arg2;
- (id)collectionView:(id)arg1 cellForItemAtIndexPath:(id)arg2;
- (long long)collectionView:(id)arg1 numberOfItemsInSection:(long long)arg2;
- (void)_layoutWithSearchType;
- (void)_layoutWithSuggestType;
- (void)_layoutWithPanelType;
- (id)_collectionViewLayoutWithType:(long long)arg1;
- (void)searchBarBecomeFirstResponder;
- (void)updateUI:(_Bool)arg1;
- (void)searchExpressionWithWord:(id)arg1;
- (unsigned long long)expressionListTotalPage;
- (void)dealloc;
- (id)initWithType:(long long)arg1 listItem:(id)arg2 isDarkMode:(_Bool)arg3;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
