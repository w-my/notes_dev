//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "KBTableViewCell.h"

#import "QNListCellAnimationMonitorProtocol.h"
#import "QNListPageCellReportProtocol.h"
#import "QNPageViewDataSource.h"
#import "QNPageViewDelegate.h"
#import "UIScrollViewDelegate.h"

@class CSimpleImageView, KBListItem, NSString, NSTimer, QNBaseLabel, QNBasicMoreFooterView, QNDragCheckMoreView, QNEnlargeHitTestButton, QNListModuleItem, QNPageView, UIImageView;

@interface QNCategorySelectionEntranceCell : KBTableViewCell <QNPageViewDataSource, QNPageViewDelegate, UIScrollViewDelegate, QNListCellAnimationMonitorProtocol, QNListPageCellReportProtocol>
{
    _Bool _isAutoScrollOver;
    _Bool _isDragged;
    CDUnknownBlockType _singleItemClickBlock;
    CDUnknownBlockType _entranceClickBlock;
    CDUnknownBlockType _dislikeBlock;
    id <QNListPageCellReportDelegate> _reportDelegate;
    QNListModuleItem *_moduleItem;
    QNPageView *_containerView;
    CSimpleImageView *_titlePreView;
    QNBaseLabel *_titleLbl;
    UIImageView *_pointView;
    QNBaseLabel *_subTitleLbl;
    CSimpleImageView *_titleBgView;
    CSimpleImageView *_bottomBgView;
    QNBasicMoreFooterView *_checkMoreFooterView;
    UIImageView *_bottomLine;
    long long _currentPage;
    NSTimer *_timer;
    unsigned long long _animState;
    double _lastStartFireTime;
    QNDragCheckMoreView *_dragCheckMoreView;
    QNEnlargeHitTestButton *_dislikeBtn;
    KBListItem *_item;
    NSString *_channelId;
}

+ (double)heightForData:(id)arg1 width:(double)arg2 context:(id)arg3;
@property(copy, nonatomic) NSString *channelId; // @synthesize channelId=_channelId;
@property(nonatomic) _Bool isDragged; // @synthesize isDragged=_isDragged;
@property(retain, nonatomic) KBListItem *item; // @synthesize item=_item;
@property(nonatomic) _Bool isAutoScrollOver; // @synthesize isAutoScrollOver=_isAutoScrollOver;
@property(retain, nonatomic) QNEnlargeHitTestButton *dislikeBtn; // @synthesize dislikeBtn=_dislikeBtn;
@property(retain, nonatomic) QNDragCheckMoreView *dragCheckMoreView; // @synthesize dragCheckMoreView=_dragCheckMoreView;
@property(nonatomic) double lastStartFireTime; // @synthesize lastStartFireTime=_lastStartFireTime;
@property(nonatomic) unsigned long long animState; // @synthesize animState=_animState;
@property(retain, nonatomic) NSTimer *timer; // @synthesize timer=_timer;
@property(nonatomic) long long currentPage; // @synthesize currentPage=_currentPage;
@property(retain, nonatomic) UIImageView *bottomLine; // @synthesize bottomLine=_bottomLine;
@property(retain, nonatomic) QNBasicMoreFooterView *checkMoreFooterView; // @synthesize checkMoreFooterView=_checkMoreFooterView;
@property(retain, nonatomic) CSimpleImageView *bottomBgView; // @synthesize bottomBgView=_bottomBgView;
@property(retain, nonatomic) CSimpleImageView *titleBgView; // @synthesize titleBgView=_titleBgView;
@property(retain, nonatomic) QNBaseLabel *subTitleLbl; // @synthesize subTitleLbl=_subTitleLbl;
@property(retain, nonatomic) UIImageView *pointView; // @synthesize pointView=_pointView;
@property(retain, nonatomic) QNBaseLabel *titleLbl; // @synthesize titleLbl=_titleLbl;
@property(retain, nonatomic) CSimpleImageView *titlePreView; // @synthesize titlePreView=_titlePreView;
@property(retain, nonatomic) QNPageView *containerView; // @synthesize containerView=_containerView;
@property(retain, nonatomic) QNListModuleItem *moduleItem; // @synthesize moduleItem=_moduleItem;
@property(nonatomic) __weak id <QNListPageCellReportDelegate> reportDelegate; // @synthesize reportDelegate=_reportDelegate;
@property(copy, nonatomic) CDUnknownBlockType dislikeBlock; // @synthesize dislikeBlock=_dislikeBlock;
@property(copy, nonatomic) CDUnknownBlockType entranceClickBlock; // @synthesize entranceClickBlock=_entranceClickBlock;
@property(copy, nonatomic) CDUnknownBlockType singleItemClickBlock; // @synthesize singleItemClickBlock=_singleItemClickBlock;
- (void).cxx_destruct;
- (void)p_updatePageDic;
- (void)dislikeNewsWithListItem:(id)arg1 context:(id)arg2;
- (void)p_dislikeButtonClicked:(id)arg1;
- (void)p_slideNextImage;
- (void)p_onSingleItemClick:(id)arg1;
- (void)hiddenDislikeBtn;
- (void)layoutWithData:(id)arg1 context:(id)arg2;
- (void)p_dataReportForContentForPage:(unsigned long long)arg1;
- (id)exposureItems;
- (void)resetCellAnimation;
- (void)stopCellAnimation;
- (void)startCellAnimation;
- (void)scrollViewDidEndDragging:(id)arg1 willDecelerate:(_Bool)arg2;
- (void)scrollViewDidScroll:(id)arg1;
- (void)pageView:(id)arg1 didScrollToPage:(unsigned long long)arg2 animation:(_Bool)arg3;
- (void)pageView:(id)arg1 didSelectedContentView:(id)arg2 atPage:(unsigned long long)arg3;
- (id)pageView:(id)arg1 contentForPage:(unsigned long long)arg2;
- (unsigned long long)numberOfRowsInPageView:(id)arg1;
- (_Bool)canReuseCellWithListItem:(id)arg1;
- (void)themeChanged:(long long)arg1;
- (void)layoutSubviews;
- (id)initWithStyle:(long long)arg1 reuseIdentifier:(id)arg2;
- (void)dealloc;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
