//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableView.h"

@class NSArray, NSMutableArray, UIView;

@interface QNSearchInterestCategoryView : QNThemableView
{
    NSArray *_catList;
    NSMutableArray *_btnList;
    UIView *_catTitleView;
    UIView *_catBtnContentView;
    CDUnknownBlockType _selectCatBlock;
    id <QNSearchInterestingCategoryViewDataSource> _dataSource;
    CDUnknownBlockType _tapGestOnCatTitleViewBlock;
}

@property(copy, nonatomic) CDUnknownBlockType tapGestOnCatTitleViewBlock; // @synthesize tapGestOnCatTitleViewBlock=_tapGestOnCatTitleViewBlock;
@property(nonatomic) __weak id <QNSearchInterestingCategoryViewDataSource> dataSource; // @synthesize dataSource=_dataSource;
@property(copy, nonatomic) CDUnknownBlockType selectCatBlock; // @synthesize selectCatBlock=_selectCatBlock;
- (void).cxx_destruct;
- (void)p_removeAllCatButtons;
- (void)p_tapGestOnCatTitleView:(id)arg1;
- (id)p_createInterestCategoryTitleView;
- (void)qn_layoutCatBtns;
- (void)p_configTitleAndContentView;
- (void)reloadInterestCateogryView;
- (void)themeChanged:(long long)arg1;
- (id)initWithDataSource:(id)arg1;

@end
