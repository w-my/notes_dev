//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNRootViewController.h"

#import "UITableViewDataSource.h"
#import "UITableViewDelegate.h"

@class CEmptyView, CPushManager, NSArray, NSDate, NSString, QNLayoutTableView, QNSystemMsgListApi;

@interface QNPersonNotiViewController : QNRootViewController <UITableViewDelegate, UITableViewDataSource>
{
    QNLayoutTableView *_tableView;
    QNSystemMsgListApi *_msgListRequest;
    NSArray *_notiItems;
    NSDate *_lastDate;
    CPushManager *_pushManager;
    CEmptyView *_emptyView;
    double _lastNewestTime;
}

@property(nonatomic) double lastNewestTime; // @synthesize lastNewestTime=_lastNewestTime;
@property(retain, nonatomic) CEmptyView *emptyView; // @synthesize emptyView=_emptyView;
@property(retain, nonatomic) CPushManager *pushManager; // @synthesize pushManager=_pushManager;
@property(retain, nonatomic) NSDate *lastDate; // @synthesize lastDate=_lastDate;
@property(copy, nonatomic) NSArray *notiItems; // @synthesize notiItems=_notiItems;
@property(retain, nonatomic) QNSystemMsgListApi *msgListRequest; // @synthesize msgListRequest=_msgListRequest;
@property(retain, nonatomic) QNLayoutTableView *tableView; // @synthesize tableView=_tableView;
- (void).cxx_destruct;
- (void)p_enterToCommentDetailWithNotiItem:(id)arg1;
- (void)p_enterToAnswerDetailWithNotiItem:(id)arg1;
- (void)tableView:(id)arg1 didSelectRowAtIndexPath:(id)arg2;
- (void)tableView:(id)arg1 willDisplayCell:(id)arg2 forRowAtIndexPath:(id)arg3;
- (double)tableView:(id)arg1 heightForRowAtIndexPath:(id)arg2;
- (id)tableView:(id)arg1 cellForRowAtIndexPath:(id)arg2;
- (long long)tableView:(id)arg1 numberOfRowsInSection:(long long)arg2;
- (void)configTitleView;
- (void)configBarButtons;
- (void)p_hideEmptyView;
- (void)p_showEmptyView;
- (void)p_stopLoadingAnimation;
- (_Bool)p_isNewOfNotiItem:(id)arg1;
- (void)p_updateLastNewestTime;
- (void)p_updateLastStoreNewestTime;
- (void)p_loadMsgList;
- (void)p_initTableView;
- (void)viewDidLoad;
- (id)initWithParam:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
