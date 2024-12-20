//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "KBTableViewCell.h"

#import "QNContainVideoViewProtocol.h"
#import "QNListCellAnimationMonitorProtocol.h"
#import "QNListPageCellReportProtocol.h"
#import "QNPageViewDataSource.h"
#import "QNPageViewDelegate.h"
#import "UIScrollViewDelegate.h"

@class CAGradientLayer, CSimpleImageView, KBListItem, KBTableViewCellLayoutContext, LOTAnimationView, NSString, NSTimer, QNBaseLabel, QNBasicMoreFooterView, QNDragCheckMoreView, QNListModuleItem, QNListNewsItem, QNPageView, UIImageView, UIView;

@interface QNHotEventsEntranceCell : KBTableViewCell <QNPageViewDataSource, QNPageViewDelegate, UIScrollViewDelegate, QNListCellAnimationMonitorProtocol, QNContainVideoViewProtocol, QNListPageCellReportProtocol>
{
    _Bool _isAutoScrollOver;
    _Bool _showingGuideView;
    _Bool _showingDayGuideView;
    _Bool _hasScrolled;
    _Bool _isReloadingData;
    _Bool _isLayouting;
    CDUnknownBlockType _singleItemClickBlock;
    CDUnknownBlockType _entranceClickBlock;
    id <QNListPageCellReportDelegate> _reportDelegate;
    QNListModuleItem *_moduleItem;
    KBListItem *_item;
    QNPageView *_containerView;
    CSimpleImageView *_iconImageView;
    QNBaseLabel *_titleLbl;
    QNBasicMoreFooterView *_checkMoreFooterView;
    UIImageView *_bottomLine;
    long long _currentPage;
    long long _clickedPage;
    NSTimer *_timer;
    unsigned long long _animState;
    double _lastStartFireTime;
    KBTableViewCellLayoutContext *_context;
    QNDragCheckMoreView *_dragCheckMoreView;
    LOTAnimationView *_guideView;
    LOTAnimationView *_dayGuideView;
    UIView *_guideBackView;
    UIView *_dayGuideBackView;
    CAGradientLayer *_guideBackViewLayer;
    CAGradientLayer *_dayGuideBackViewLayer;
    CDUnknownBlockType _playVideoBlock;
    NSString *_ownerChannelId;
    QNListNewsItem *_listItemForLastPlay;
    NSString *_rootControllerChannelId;
}

+ (double)heightForData:(id)arg1 width:(double)arg2 context:(id)arg3;
@property(copy, nonatomic) NSString *rootControllerChannelId; // @synthesize rootControllerChannelId=_rootControllerChannelId;
@property(nonatomic) _Bool isLayouting; // @synthesize isLayouting=_isLayouting;
@property(retain, nonatomic) QNListNewsItem *listItemForLastPlay; // @synthesize listItemForLastPlay=_listItemForLastPlay;
@property(retain, nonatomic) NSString *ownerChannelId; // @synthesize ownerChannelId=_ownerChannelId;
@property(nonatomic) _Bool isReloadingData; // @synthesize isReloadingData=_isReloadingData;
@property(copy, nonatomic) CDUnknownBlockType playVideoBlock; // @synthesize playVideoBlock=_playVideoBlock;
@property(nonatomic) _Bool hasScrolled; // @synthesize hasScrolled=_hasScrolled;
@property(retain, nonatomic) CAGradientLayer *dayGuideBackViewLayer; // @synthesize dayGuideBackViewLayer=_dayGuideBackViewLayer;
@property(retain, nonatomic) CAGradientLayer *guideBackViewLayer; // @synthesize guideBackViewLayer=_guideBackViewLayer;
@property(retain, nonatomic) UIView *dayGuideBackView; // @synthesize dayGuideBackView=_dayGuideBackView;
@property(retain, nonatomic) UIView *guideBackView; // @synthesize guideBackView=_guideBackView;
@property(retain, nonatomic) LOTAnimationView *dayGuideView; // @synthesize dayGuideView=_dayGuideView;
@property(retain, nonatomic) LOTAnimationView *guideView; // @synthesize guideView=_guideView;
@property(nonatomic) _Bool showingDayGuideView; // @synthesize showingDayGuideView=_showingDayGuideView;
@property(nonatomic) _Bool showingGuideView; // @synthesize showingGuideView=_showingGuideView;
@property(nonatomic) _Bool isAutoScrollOver; // @synthesize isAutoScrollOver=_isAutoScrollOver;
@property(retain, nonatomic) QNDragCheckMoreView *dragCheckMoreView; // @synthesize dragCheckMoreView=_dragCheckMoreView;
@property(retain, nonatomic) KBTableViewCellLayoutContext *context; // @synthesize context=_context;
@property(nonatomic) double lastStartFireTime; // @synthesize lastStartFireTime=_lastStartFireTime;
@property(nonatomic) unsigned long long animState; // @synthesize animState=_animState;
@property(retain, nonatomic) NSTimer *timer; // @synthesize timer=_timer;
@property(nonatomic) long long clickedPage; // @synthesize clickedPage=_clickedPage;
@property(nonatomic) long long currentPage; // @synthesize currentPage=_currentPage;
@property(retain, nonatomic) UIImageView *bottomLine; // @synthesize bottomLine=_bottomLine;
@property(retain, nonatomic) QNBasicMoreFooterView *checkMoreFooterView; // @synthesize checkMoreFooterView=_checkMoreFooterView;
@property(retain, nonatomic) QNBaseLabel *titleLbl; // @synthesize titleLbl=_titleLbl;
@property(retain, nonatomic) CSimpleImageView *iconImageView; // @synthesize iconImageView=_iconImageView;
@property(retain, nonatomic) QNPageView *containerView; // @synthesize containerView=_containerView;
@property(retain, nonatomic) KBListItem *item; // @synthesize item=_item;
@property(retain, nonatomic) QNListModuleItem *moduleItem; // @synthesize moduleItem=_moduleItem;
@property(nonatomic) __weak id <QNListPageCellReportDelegate> reportDelegate; // @synthesize reportDelegate=_reportDelegate;
@property(copy, nonatomic) CDUnknownBlockType entranceClickBlock; // @synthesize entranceClickBlock=_entranceClickBlock;
@property(copy, nonatomic) CDUnknownBlockType singleItemClickBlock; // @synthesize singleItemClickBlock=_singleItemClickBlock;
- (void).cxx_destruct;
- (void)themeChanged:(long long)arg1;
- (_Bool)p_isPlayOnMine;
- (void)p_updatePageDic;
- (void)p_slideNextImage;
- (void)p_onSingleItemClick:(id)arg1;
- (void)p_hideGuideViewClicked:(_Bool)arg1;
- (void)p_checkAutoPlayVideo;
- (void)p_handleVideoStateChanged;
- (id)p_getChannelId;
- (id)p_getVideoAssistor;
- (void)layoutWithData:(id)arg1 context:(id)arg2;
- (void)refreshCell;
- (void)p_dataReportForContentForPage:(unsigned long long)arg1;
- (id)exposureItems;
- (void)scrollViewDidEndDragging:(id)arg1 willDecelerate:(_Bool)arg2;
- (void)scrollViewDidScroll:(id)arg1;
- (void)pageView:(id)arg1 didRemoveContentView:(id)arg2 atPage:(unsigned long long)arg3;
- (void)pageView:(id)arg1 didScrollToPage:(unsigned long long)arg2 animation:(_Bool)arg3;
- (void)pageView:(id)arg1 didSelectedContentView:(id)arg2 atPage:(unsigned long long)arg3;
- (void)setChannelId:(id)arg1;
- (id)getCurrentVideoView;
- (void)showDayGuideView:(_Bool)arg1;
- (void)showGuideView:(_Bool)arg1;
- (id)pageView:(id)arg1 contentForPage:(unsigned long long)arg2;
- (unsigned long long)numberOfRowsInPageView:(id)arg1;
- (_Bool)canReuseCellWithListItem:(id)arg1;
- (void)resetCellAnimation;
- (void)stopCellAnimation;
- (void)startCellAnimation;
- (void)p_handleEnterBackgroundNotification;
- (void)layoutSubviews;
- (id)initWithStyle:(long long)arg1 reuseIdentifier:(id)arg2;
- (void)dealloc;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

