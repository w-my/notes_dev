//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableView.h"

@class NSArray, NSMutableArray, UIView;

@interface QNHistoryLocationChannelView : QNThemableView
{
    CDUnknownBlockType _selectBlock;
    id <QNHistoryLocationChannelViewDataSource> _dataSource;
    CDUnknownBlockType _tapGestOnCatTitleViewBlock;
    NSArray *_locationSubmenuList;
    NSMutableArray *_btnList;
    UIView *_locationHistoryTitleView;
    UIView *_locationHistoryBtnContentView;
    UIView *_bottomLine;
}

+ (double)getCellHeightInViewFromHistoryData:(id)arg1;
@property(retain, nonatomic) UIView *bottomLine; // @synthesize bottomLine=_bottomLine;
@property(retain, nonatomic) UIView *locationHistoryBtnContentView; // @synthesize locationHistoryBtnContentView=_locationHistoryBtnContentView;
@property(retain, nonatomic) UIView *locationHistoryTitleView; // @synthesize locationHistoryTitleView=_locationHistoryTitleView;
@property(retain, nonatomic) NSMutableArray *btnList; // @synthesize btnList=_btnList;
@property(copy, nonatomic) NSArray *locationSubmenuList; // @synthesize locationSubmenuList=_locationSubmenuList;
@property(copy, nonatomic) CDUnknownBlockType tapGestOnCatTitleViewBlock; // @synthesize tapGestOnCatTitleViewBlock=_tapGestOnCatTitleViewBlock;
@property(nonatomic) __weak id <QNHistoryLocationChannelViewDataSource> dataSource; // @synthesize dataSource=_dataSource;
@property(copy, nonatomic) CDUnknownBlockType selectBlock; // @synthesize selectBlock=_selectBlock;
- (void).cxx_destruct;
- (void)p_removeAllButtons;
- (void)p_tapGestOnCatTitleView:(id)arg1;
- (id)p_createInterestCategoryTitleView;
- (void)qn_layoutBtns;
- (void)p_configTitleAndContentView;
- (void)reloadHistoryLocationChannelView;
- (void)themeChanged:(long long)arg1;
- (id)initWithDataSource:(id)arg1;

@end

