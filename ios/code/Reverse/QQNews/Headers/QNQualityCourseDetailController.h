//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNRootViewController.h"

#import "QNDeDaoPlayerViewProtocol.h"
#import "QNImageBrowserDelegate.h"
#import "QNQualityCourseLessonListViewDelegate.h"
#import "QNQualityCourseMoreListViewDelegate.h"
#import "UIScrollViewDelegate.h"

@class NSMutableArray, NSString, QNBarButton, QNDetailContentContainer, QNListNewsItem, QNLoadingShimmerView, QNQualityCourseBottomBar, QNQualityCourseBuyNoticeView, QNQualityCourseDescriptionView, QNQualityCourseDetailViewModel, QNQualityCourseHeaderView, QNQualityCourseLessonListView, QNQualityCourseMoreListView, QNQualityCoursePayChannelEntrance, QNQualityCourseProgramView, QNQualityCourseTargetingGroupView;

@interface QNQualityCourseDetailController : QNRootViewController <UIScrollViewDelegate, QNQualityCourseLessonListViewDelegate, QNDeDaoPlayerViewProtocol, QNImageBrowserDelegate, QNQualityCourseMoreListViewDelegate>
{
    _Bool _preventChangeNavBarAlpha;
    NSString *_from;
    QNListNewsItem *_listItem;
    QNQualityCourseDetailViewModel *_viewModel;
    QNDetailContentContainer *_contentContainer;
    QNQualityCourseHeaderView *_headerView;
    QNQualityCourseLessonListView *_contentList;
    QNQualityCourseDescriptionView *_descView;
    QNQualityCourseProgramView *_programView;
    QNQualityCourseTargetingGroupView *_targetingGroupView;
    QNQualityCourseBuyNoticeView *_buyNoticeView;
    QNQualityCourseMoreListView *_moreListView;
    QNQualityCoursePayChannelEntrance *_entranceView;
    QNQualityCourseBottomBar *_bottomBar;
    QNBarButton *_backButton;
    QNBarButton *_complaintButton;
    QNLoadingShimmerView *_loadingShimmerView;
    NSMutableArray *_reportedItem;
}

@property(retain, nonatomic) NSMutableArray *reportedItem; // @synthesize reportedItem=_reportedItem;
@property(retain, nonatomic) QNLoadingShimmerView *loadingShimmerView; // @synthesize loadingShimmerView=_loadingShimmerView;
@property(nonatomic) _Bool preventChangeNavBarAlpha; // @synthesize preventChangeNavBarAlpha=_preventChangeNavBarAlpha;
@property(retain, nonatomic) QNBarButton *complaintButton; // @synthesize complaintButton=_complaintButton;
@property(retain, nonatomic) QNBarButton *backButton; // @synthesize backButton=_backButton;
@property(retain, nonatomic) QNQualityCourseBottomBar *bottomBar; // @synthesize bottomBar=_bottomBar;
@property(retain, nonatomic) QNQualityCoursePayChannelEntrance *entranceView; // @synthesize entranceView=_entranceView;
@property(retain, nonatomic) QNQualityCourseMoreListView *moreListView; // @synthesize moreListView=_moreListView;
@property(retain, nonatomic) QNQualityCourseBuyNoticeView *buyNoticeView; // @synthesize buyNoticeView=_buyNoticeView;
@property(retain, nonatomic) QNQualityCourseTargetingGroupView *targetingGroupView; // @synthesize targetingGroupView=_targetingGroupView;
@property(retain, nonatomic) QNQualityCourseProgramView *programView; // @synthesize programView=_programView;
@property(retain, nonatomic) QNQualityCourseDescriptionView *descView; // @synthesize descView=_descView;
@property(retain, nonatomic) QNQualityCourseLessonListView *contentList; // @synthesize contentList=_contentList;
@property(retain, nonatomic) QNQualityCourseHeaderView *headerView; // @synthesize headerView=_headerView;
@property(retain, nonatomic) QNDetailContentContainer *contentContainer; // @synthesize contentContainer=_contentContainer;
@property(retain, nonatomic) QNQualityCourseDetailViewModel *viewModel; // @synthesize viewModel=_viewModel;
@property(retain, nonatomic) QNListNewsItem *listItem; // @synthesize listItem=_listItem;
@property(copy, nonatomic) NSString *from; // @synthesize from=_from;
- (void).cxx_destruct;
- (void)scrollViewDidScroll:(id)arg1;
- (void)scrollViewDidEndDecelerating:(id)arg1;
- (void)scrollViewDidEndDragging:(id)arg1 willDecelerate:(_Bool)arg2;
- (void)playerStatusDidChange:(unsigned long long)arg1;
- (void)updateWithLesson:(id)arg1 status:(unsigned long long)arg2;
- (void)p_showBuyCourseAlert;
- (void)p_viewDocumentWithLesson:(id)arg1;
- (void)p_playAtIndex:(long long)arg1;
- (void)p_checkAndPerfromActionWithLesson:(id)arg1 block:(CDUnknownBlockType)arg2;
- (void)lessonListView:(id)arg1 didClickArticle:(id)arg2;
- (void)lessonListView:(id)arg1 didSelectedLessonAtIndex:(long long)arg2;
- (void)moreCourseListView:(id)arg1 didSelectedCourse:(id)arg2;
- (void)p_updateWithLesson:(id)arg1 status:(unsigned long long)arg2;
- (void)p_enterNewsChannel:(id)arg1;
- (void)p_exposureReport;
- (void)p_loginAndReload;
- (void)p_loadingFailed;
- (void)p_updatePlayerData;
- (void)p_requestContentData;
- (void)p_layoutElementViews;
- (id)currentCourseId;
- (double)bottomInsetforMiniPlayerView;
- (id)getContentScrollView;
- (void)viewDidAppear:(_Bool)arg1;
- (void)viewDidLoad;
- (void)configBarButtons;
- (void)loadComplaintPage;
- (void)onComplaint:(id)arg1;
- (void)onBack:(id)arg1;
- (id)initWithParam:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
