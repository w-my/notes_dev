//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "WCCanvasComponent.h"

#import "UIScrollViewDelegate.h"
#import "UITableViewDataSource.h"
#import "UITableViewDelegate.h"
#import "WCCanvasComponentDelegate.h"
#import "scrollViewDelegate.h"
#import "tableViewDelegate.h"

@class MMScrollView, NSMutableArray, NSString, UILabel, UIPageControl, UIView, WCCanvasArrowRightIcon;

@interface WCCanvasGroupListComponent : WCCanvasComponent <UIScrollViewDelegate, scrollViewDelegate, UITableViewDelegate, UITableViewDataSource, tableViewDelegate, WCCanvasComponentDelegate>
{
    _Bool _needRelayout;
    _Bool _shouldFixSearchCanvas;
    unsigned int _m_iCurIndex;
    UIView *_m_blackMask;
    MMScrollView *_m_scrollView;
    UIPageControl *_m_pageCtrl;
    NSMutableArray *_m_arrTable;
    UILabel *_m_pageLabel;
    WCCanvasArrowRightIcon *_arrowRightIcon;
}

+ (double)calcHeightForTableViewWithGroup:(id)arg1 maxWidth:(double)arg2 dataItem:(id)arg3 orientation:(long long)arg4;
+ (struct CGSize)calcSizeForCanvasItem:(id)arg1 dataItem:(id)arg2 orientation:(long long)arg3;
@property(nonatomic) _Bool shouldFixSearchCanvas; // @synthesize shouldFixSearchCanvas=_shouldFixSearchCanvas;
@property(nonatomic) _Bool needRelayout; // @synthesize needRelayout=_needRelayout;
@property(retain, nonatomic) WCCanvasArrowRightIcon *arrowRightIcon; // @synthesize arrowRightIcon=_arrowRightIcon;
@property(retain, nonatomic) UILabel *m_pageLabel; // @synthesize m_pageLabel=_m_pageLabel;
@property(retain, nonatomic) NSMutableArray *m_arrTable; // @synthesize m_arrTable=_m_arrTable;
@property(nonatomic) unsigned int m_iCurIndex; // @synthesize m_iCurIndex=_m_iCurIndex;
@property(retain, nonatomic) UIPageControl *m_pageCtrl; // @synthesize m_pageCtrl=_m_pageCtrl;
@property(retain, nonatomic) MMScrollView *m_scrollView; // @synthesize m_scrollView=_m_scrollView;
@property(retain, nonatomic) UIView *m_blackMask; // @synthesize m_blackMask=_m_blackMask;
- (void).cxx_destruct;
- (_Bool)hasPreloadWebViewInScrollGroupComponent;
- (double)getPreloadWebViewBottomInScrollGroupComponent;
- (id)hitTest:(struct CGPoint)arg1 withEvent:(id)arg2;
- (void)onFavProductReturn:(unsigned int)arg1 errMsg:(id)arg2;
- (_Bool)getUseSnsCdnDownloadMode:(id)arg1;
- (_Bool)isSearchCanvas;
- (id)getReportMgr;
- (id)tryAppendAdParamsForWeappPath:(id)arg1;
- (id)getWeAppSceneNoteForComponent:(id)arg1;
- (id)getAdUxInfo;
- (void)jumpToWeAppBizTempSessionWithInfo:(id)arg1;
- (void)hideActionSheet;
- (void)showActionSheet:(id)arg1 body:(id)arg2 withIcon:(id)arg3 hideHeader:(_Bool)arg4 showCancelAction:(_Bool)arg5;
- (void)jumpToLocationPage:(id)arg1;
- (void)jumpToPhonePage:(id)arg1;
- (void)onBtnComponentClick:(long long)arg1;
- (_Bool)shouldVideoLayerRasterize;
- (_Bool)isCurSectionBlackMoreThanWhite:(long long)arg1;
- (void)setLoading:(_Bool)arg1;
- (void)canvasComponent:(id)arg1 willJumpToCanvas:(id)arg2 canvasId:(id)arg3;
- (void)canvasComponent:(id)arg1 willShowViewController:(id)arg2;
- (void)canvasComponent:(id)arg1 willAddViewController:(id)arg2;
- (void)canvasComponent:(id)arg1 willExistAndJumpUrl:(id)arg2;
- (void)onComponentBeClicked:(id)arg1;
- (void)updateVoteAdInfo:(id)arg1 rightVoteInfo:(id)arg2;
- (void)componentWillEnterForeground;
- (void)componentDidEnterBackground;
- (void)notifyDisappearPage:(long long)arg1;
- (void)notifyFullyAppearPage:(long long)arg1;
- (void)notifyWillAppearPage:(long long)arg1;
- (void)tableView:(id)arg1 didEndDisplayingCell:(id)arg2 forRowAtIndexPath:(id)arg3;
- (void)tableView:(id)arg1 willDisplayCell:(id)arg2 forRowAtIndexPath:(id)arg3;
- (double)tableView:(id)arg1 heightForRowAtIndexPath:(id)arg2;
- (id)tableView:(id)arg1 cellForRowAtIndexPath:(id)arg2;
- (long long)tableView:(id)arg1 numberOfRowsInSection:(long long)arg2;
- (long long)numberOfSectionsInTableView:(id)arg1;
- (void)scrollViewDidEndScrollingAnimation:(id)arg1;
- (void)initArrowRightIcon;
- (void)scrollViewDidEndDecelerating:(id)arg1;
- (void)scrollViewWillBeginDragging:(id)arg1;
- (void)setPageCtrlColorFor:(unsigned int)arg1;
- (void)setPageCtrlTo:(unsigned int)arg1;
- (void)scrollViewDidScroll:(id)arg1;
- (void)componentWillDisappearInMainScreen:(_Bool)arg1;
- (void)componentAppearFactorChagneInMainScreen;
- (void)componentDidFullyApperaInMainScreen:(_Bool)arg1;
- (void)componentWillApperaInMainScreen:(_Bool)arg1;
- (void)configureWithCanvasItem:(id)arg1 dataItem:(id)arg2 orientation:(long long)arg3;
- (_Bool)shouldShowDownDirectionIcon;
- (_Bool)shouldForbidDelegateShowArrowDown;
- (_Bool)shouldShowRightDirectionIcon:(int)arg1;
- (void)animationShowWithIndex:(unsigned long long)arg1;
- (void)resetScrollView;
- (void)clearStatus;
- (void)layoutSubviews;
- (void)dealloc;
- (id)initWithFrame:(struct CGRect)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

