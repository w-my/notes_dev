//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNViewController.h"

#import "NSCoding.h"
#import "UITableViewDataSource.h"
#import "UITableViewDelegate.h"

@class CLoadingAnimationView, NSMutableArray, NSString, QNBanner, QNBoutiqueRecommendApi, UIImageView, UITableView, UIView;

@interface QNBoutiqueRecommendController : QNViewController <NSCoding, UITableViewDelegate, UITableViewDataSource>
{
    NSMutableArray *_tempBoutiques;
    int _remainPage;
    int _pageCounts;
    int _currPage;
    _Bool _getMore;
    _Bool _isDownloading;
    UIView *_loadingView;
    CLoadingAnimationView *_loadingBackView;
    UITableView *_contentTableView;
    UIImageView *_backImageView;
    QNBanner *_banner;
    NSMutableArray *_boutiques;
    NSString *_version;
    QNBoutiqueRecommendApi *_mRequest;
}

@property(retain, nonatomic) QNBoutiqueRecommendApi *mRequest; // @synthesize mRequest=_mRequest;
@property(copy, nonatomic) NSString *version; // @synthesize version=_version;
@property(retain, nonatomic) NSMutableArray *boutiques; // @synthesize boutiques=_boutiques;
@property(retain, nonatomic) QNBanner *banner; // @synthesize banner=_banner;
@property(retain, nonatomic) UIImageView *backImageView; // @synthesize backImageView=_backImageView;
@property(retain, nonatomic) UITableView *contentTableView; // @synthesize contentTableView=_contentTableView;
- (void).cxx_destruct;
- (_Bool)shouldAutorotate;
- (void)handleBannerClicked:(id)arg1;
- (void)handleDownloadApp:(id)arg1;
- (void)p_mergeBoutique;
- (void)loadMoreBoutique;
- (void)loadBoutique;
- (void)p_downloadAppListWithPage:(long long)arg1 andCnt:(long long)arg2;
- (void)p_handleSingleTapGesture:(id)arg1;
- (void)handleFailedRequest:(id)arg1 error:(id)arg2;
- (void)handleRequest:(id)arg1 response:(id)arg2;
- (void)onVersionChangedNotification:(id)arg1;
- (void)getBoutiqueFromNet;
- (void)getBoutiqueFromLocal;
- (void)onCancel:(id)arg1;
- (void)hide;
- (void)show:(id)arg1;
- (void)p_resetLoad;
- (double)tableView:(id)arg1 heightForRowAtIndexPath:(id)arg2;
- (void)tableView:(id)arg1 didSelectRowAtIndexPath:(id)arg2;
- (id)tableView:(id)arg1 cellForRowAtIndexPath:(id)arg2;
- (long long)tableView:(id)arg1 numberOfRowsInSection:(long long)arg2;
- (long long)numberOfSectionsInTableView:(id)arg1;
- (void)didReceiveMemoryWarning;
- (void)viewWillAppear:(_Bool)arg1;
- (void)insertRowAtBottom;
- (void)insertRowAtTop;
- (void)viewDidLoad;
- (void)p_requestCancel;
- (void)scroll2Top;
- (void)themeChanged:(long long)arg1;
- (void)dealloc;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

