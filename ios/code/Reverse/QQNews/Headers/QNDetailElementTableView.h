//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableView.h"

#import "QNDetailContentElementProtocol.h"

@class NSString, QNDetailContentContainer, QNNewsCommentController, TADReportManager, UITableView, UIView;

@interface QNDetailElementTableView : QNThemableView <QNDetailContentElementProtocol>
{
    _Bool _isShowingToScreen;
    _Bool _showWidgetTitleView;
    _Bool _isContentShowed;
    QNDetailContentContainer *_contentContainer;
    UITableView *_tableView;
    UIView *_stateInfoView;
    double _contentAdjust;
    double _tableViewHeightAdjust;
    QNNewsCommentController *_newsCommentController;
    double _heightOfFirstSectionHeader;
    CDUnknownBlockType _inScreenChangeShowedBlock;
    CDUnknownBlockType _contentChangeShowedBlock;
    TADReportManager *_adReportManager;
    UIView *_tableHeaderView;
    double _preContentHeigth;
    UIView *_widgetTitleView;
}

@property(retain, nonatomic) UIView *widgetTitleView; // @synthesize widgetTitleView=_widgetTitleView;
@property(nonatomic) _Bool isContentShowed; // @synthesize isContentShowed=_isContentShowed;
@property(nonatomic) double preContentHeigth; // @synthesize preContentHeigth=_preContentHeigth;
@property(retain, nonatomic) UIView *tableHeaderView; // @synthesize tableHeaderView=_tableHeaderView;
@property(nonatomic) __weak TADReportManager *adReportManager; // @synthesize adReportManager=_adReportManager;
@property(copy, nonatomic) CDUnknownBlockType contentChangeShowedBlock; // @synthesize contentChangeShowedBlock=_contentChangeShowedBlock;
@property(copy, nonatomic) CDUnknownBlockType inScreenChangeShowedBlock; // @synthesize inScreenChangeShowedBlock=_inScreenChangeShowedBlock;
@property(nonatomic) double heightOfFirstSectionHeader; // @synthesize heightOfFirstSectionHeader=_heightOfFirstSectionHeader;
@property(nonatomic) __weak QNNewsCommentController *newsCommentController; // @synthesize newsCommentController=_newsCommentController;
@property(nonatomic) _Bool showWidgetTitleView; // @synthesize showWidgetTitleView=_showWidgetTitleView;
@property(nonatomic) _Bool isShowingToScreen; // @synthesize isShowingToScreen=_isShowingToScreen;
@property(nonatomic) double tableViewHeightAdjust; // @synthesize tableViewHeightAdjust=_tableViewHeightAdjust;
@property(nonatomic) double contentAdjust; // @synthesize contentAdjust=_contentAdjust;
@property(retain, nonatomic) UIView *stateInfoView; // @synthesize stateInfoView=_stateInfoView;
@property(nonatomic) __weak UITableView *tableView; // @synthesize tableView=_tableView;
@property(nonatomic) __weak QNDetailContentContainer *contentContainer; // @synthesize contentContainer=_contentContainer;
- (void).cxx_destruct;
- (void)willRemoveSubview:(id)arg1;
- (void)didAddSubview:(id)arg1;
- (void)p_checkWidgetTitleView;
- (void)contentContainer:(id)arg1 ScrolledToPosition:(struct CGPoint)arg2;
- (id)contentScrollView;
- (double)heightOfElementView;
- (void)layoutSubviews;
- (void)dealloc;
- (id)initWithFrame:(struct CGRect)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
