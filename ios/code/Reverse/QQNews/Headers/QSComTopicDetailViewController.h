//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNRootViewController.h"

#import "QNCommentBarDelegate.h"
#import "QNShareActivityControllerDelegate.h"
#import "QSBaseDataDelegate.h"
#import "QSComTopicDetailReplyListDataDelegate.h"
#import "QSComTopicDetailReplyTitleCellDelegate.h"
#import "QSComTopicDetailTitleCellDelegate.h"
#import "QSCombiningDataDelegate.h"
#import "QSTopicDetailZanTableViewCellDelegate.h"
#import "UIGestureRecognizerDelegate.h"
#import "UITableViewDataSource.h"
#import "UITableViewDelegate.h"

@class CWriteCommentView, NSDictionary, NSMutableDictionary, NSString, QNListNewsItem, QNSportsCommunityParam, QSComTopicDetailData, QSComTopicDetailReplyItem, QSComTopicDetailReplyListData, QSComTopicDetailReplyListOptionChooseView, QSCombiningData, QSCommunitySharedNewsNavigator, QSTopicDetailZanTableViewCell, QSTopicReplyHeadView, UITableView;

@interface QSComTopicDetailViewController : QNRootViewController <UIGestureRecognizerDelegate, QSBaseDataDelegate, QSCombiningDataDelegate, UITableViewDelegate, UITableViewDataSource, QSComTopicDetailReplyListDataDelegate, QSComTopicDetailTitleCellDelegate, QSTopicDetailZanTableViewCellDelegate, QSComTopicDetailReplyTitleCellDelegate, QNCommentBarDelegate, QNShareActivityControllerDelegate>
{
    _Bool _scrollToCommentZone;
    _Bool _isSubReply;
    _Bool _isUserReload;
    _Bool _didReportBossInfo;
    NSString *_mid;
    NSString *_tid;
    CDUnknownBlockType _DeleteTopicBlock;
    UITableView *_tableView;
    CWriteCommentView *_inputBar;
    QSCombiningData *_combiningData;
    QSComTopicDetailData *_topicDetailData;
    QSComTopicDetailReplyListData *_replyListData;
    long long _replyListOption;
    QSComTopicDetailReplyListOptionChooseView *_chooseView;
    NSDictionary *_report;
    QSTopicDetailZanTableViewCell *_zanCell;
    QSTopicReplyHeadView *_replyHeadView;
    QNListNewsItem *_listItem;
    QNSportsCommunityParam *_sportsParam;
    QSComTopicDetailReplyItem *_targetReplyItem;
    NSString *_cacheKey;
    QNListNewsItem *_listItemForShareInCMSUse;
    NSMutableDictionary *_userSelectedAllVoteItemDict;
    QSCommunitySharedNewsNavigator *_sharedNewsNavigator;
}

+ (id)handleUploadImage:(id)arg1;
+ (void)navigateToTopicDetailViewControllerWithTopicId:(id)arg1 h5Info:(id)arg2 completion:(CDUnknownBlockType)arg3;
@property(retain, nonatomic) QSCommunitySharedNewsNavigator *sharedNewsNavigator; // @synthesize sharedNewsNavigator=_sharedNewsNavigator;
@property(retain, nonatomic) NSMutableDictionary *userSelectedAllVoteItemDict; // @synthesize userSelectedAllVoteItemDict=_userSelectedAllVoteItemDict;
@property(retain, nonatomic) QNListNewsItem *listItemForShareInCMSUse; // @synthesize listItemForShareInCMSUse=_listItemForShareInCMSUse;
@property(nonatomic) _Bool didReportBossInfo; // @synthesize didReportBossInfo=_didReportBossInfo;
@property(copy, nonatomic) NSString *cacheKey; // @synthesize cacheKey=_cacheKey;
@property(nonatomic) _Bool isUserReload; // @synthesize isUserReload=_isUserReload;
@property(nonatomic) _Bool isSubReply; // @synthesize isSubReply=_isSubReply;
@property(retain, nonatomic) QSComTopicDetailReplyItem *targetReplyItem; // @synthesize targetReplyItem=_targetReplyItem;
@property(retain, nonatomic) QNSportsCommunityParam *sportsParam; // @synthesize sportsParam=_sportsParam;
@property(retain, nonatomic) QNListNewsItem *listItem; // @synthesize listItem=_listItem;
@property(retain, nonatomic) QSTopicReplyHeadView *replyHeadView; // @synthesize replyHeadView=_replyHeadView;
@property(retain, nonatomic) QSTopicDetailZanTableViewCell *zanCell; // @synthesize zanCell=_zanCell;
@property(retain, nonatomic) NSDictionary *report; // @synthesize report=_report;
@property(retain, nonatomic) QSComTopicDetailReplyListOptionChooseView *chooseView; // @synthesize chooseView=_chooseView;
@property(nonatomic) long long replyListOption; // @synthesize replyListOption=_replyListOption;
@property(retain, nonatomic) QSComTopicDetailReplyListData *replyListData; // @synthesize replyListData=_replyListData;
@property(retain, nonatomic) QSComTopicDetailData *topicDetailData; // @synthesize topicDetailData=_topicDetailData;
@property(retain, nonatomic) QSCombiningData *combiningData; // @synthesize combiningData=_combiningData;
@property(retain, nonatomic) CWriteCommentView *inputBar; // @synthesize inputBar=_inputBar;
@property(retain, nonatomic) UITableView *tableView; // @synthesize tableView=_tableView;
@property(nonatomic) _Bool scrollToCommentZone; // @synthesize scrollToCommentZone=_scrollToCommentZone;
@property(copy, nonatomic) CDUnknownBlockType DeleteTopicBlock; // @synthesize DeleteTopicBlock=_DeleteTopicBlock;
@property(copy, nonatomic) NSString *tid; // @synthesize tid=_tid;
@property(copy, nonatomic) NSString *mid; // @synthesize mid=_mid;
- (void).cxx_destruct;
- (void)syncUserSelectedAllVoteItemDictWhenModelDataRefreshed;
- (void)startReplyWithContent:(id)arg1 imageData:(id)arg2;
- (void)reloadReplyListsWithOptions:(long long)arg1 forceReload:(_Bool)arg2;
- (void)topicTipViewDidReportAction;
- (void)topicTipViewDidReplyAction;
- (void)showTopicImageContents:(id)arg1 atIndex:(unsigned long long)arg2 rect:(struct CGRect)arg3;
- (void)tableView:(id)arg1 didSelectRowAtIndexPath:(id)arg2;
- (double)tableView:(id)arg1 normalReplyHeightForRowAtIndexPath:(id)arg2;
- (double)tableView:(id)arg1 mainTopicHeightForRowAtIndexPath:(id)arg2;
- (double)tableView:(id)arg1 heightForRowAtIndexPath:(id)arg2;
- (double)tableView:(id)arg1 heightForHeaderInSection:(long long)arg2;
- (id)tableView:(id)arg1 viewForHeaderInSection:(long long)arg2;
- (void)tableView:(id)arg1 didEndDisplayingCell:(id)arg2 forRowAtIndexPath:(id)arg3;
- (id)tableView:(id)arg1 normalReplyCellForRowAtIndexPath:(id)arg2;
- (id)tableView:(id)arg1 mainTopicCellForRowAtIndexPath:(id)arg2;
- (id)tableView:(id)arg1 cellForRowAtIndexPath:(id)arg2;
- (long long)tableView:(id)arg1 numberOfRowsInSection:(long long)arg2;
- (long long)numberOfSectionsInTableView:(id)arg1;
- (void)commentBarDidClickWriteCommentButton;
- (void)replyTitleCell:(id)arg1 didTapSupportButton:(id)arg2;
- (void)replyTitleCell:(id)arg1 didTapUser:(id)arg2;
- (void)supportTableViewCell:(id)arg1 didTapUser:(id)arg2;
- (void)zanCellDidOperationFinished:(id)arg1;
- (void)comTopicDetailTitleCell:(id)arg1 didTapAvatarButton:(id)arg2;
- (void)comTopicDetailReplyListData:(id)arg1 didGetReplyListFinishAtIndex:(unsigned long long)arg2 error:(id)arg3;
- (void)combiningData:(id)arg1 didFinishLoadWithData:(id)arg2 error:(id)arg3;
- (void)combiningDataDidReadCacheSucceed:(id)arg1;
- (void)combiningData:(id)arg1 willStartLoadWithData:(id)arg2;
- (void)getMore;
- (void)refresh;
- (_Bool)isEmpty;
- (void)continueGettingData;
- (id)h5ShareURL;
- (void)data:(id)arg1 didFinishFinallyWithError:(id)arg2;
- (void)data:(id)arg1 didFinishLoadWithError:(id)arg2;
- (void)dataWillStartLoad:(id)arg1;
- (void)scrollViewDidScroll:(id)arg1;
- (void)tapGestureAction:(id)arg1;
- (_Bool)gestureRecognizerShouldBegin:(id)arg1;
- (id)getCustomShareInfo;
- (void)onAction:(id)arg1;
- (void)userAttendStatusChanged:(id)arg1;
- (void)userLoginStateChanged;
- (void)hideContent;
- (void)showContent;
- (void)dealloc;
- (void)viewWillDisappear:(_Bool)arg1;
- (void)viewWillAppear:(_Bool)arg1;
- (void)viewDidLoad;
- (void)initSettings;
- (id)initWithParam:(id)arg1;
- (id)initWithNibName:(id)arg1 bundle:(id)arg2;
- (void)themeChanged:(long long)arg1;
- (void)do_loadingFailed;
- (void)refreshContentData;
- (void)do_reloadData;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
