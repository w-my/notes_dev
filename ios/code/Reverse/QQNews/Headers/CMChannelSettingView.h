//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNThemableView.h"

#import "CAAnimationDelegate.h"
#import "QNSubMenuInCurrentCollectionFooterViewDelegate.h"
#import "QNSubMenuNoInCurrentLocalCollectionFooterViewDelegate.h"
#import "UICollectionViewDataSource.h"
#import "UICollectionViewDelegate.h"
#import "UICollectionViewDelegateFlowLayout.h"
#import "UIGestureRecognizerDelegate.h"
#import "UIScrollViewDelegate.h"

@class CMChannelSettingViewModel, CSubMenuItem, CSubMenuList, NSIndexPath, NSMutableArray, NSObject<SubMenuSettingViewDataSourceDelegate>, NSString, QNSubMenuCollectionViewCell, QNSubMenuCollectionViewFlowLayout, QNSubMenuInCurrentCollectionFooterView, QNSubMenuInCurrentCollectionHeaderView, QNSubMenuRecommendCollectionHeaderView, UICollectionView, UILongPressGestureRecognizer, UITapGestureRecognizer;

@interface CMChannelSettingView : QNThemableView <UICollectionViewDelegateFlowLayout, UICollectionViewDelegate, UICollectionViewDataSource, QNSubMenuInCurrentCollectionFooterViewDelegate, QNSubMenuNoInCurrentLocalCollectionFooterViewDelegate, UIGestureRecognizerDelegate, CAAnimationDelegate, UIScrollViewDelegate>
{
    CMChannelSettingViewModel *_viewModel;
    QNSubMenuCollectionViewFlowLayout *_collectionViewLayout;
    QNSubMenuInCurrentCollectionHeaderView *_headerNoticeView;
    QNSubMenuRecommendCollectionHeaderView *_headerNoticeViewSecond;
    QNSubMenuInCurrentCollectionFooterView *_footerSwitchView;
    QNSubMenuCollectionViewCell *_curMovingAnchorCell;
    QNSubMenuCollectionViewCell *_followingCell;
    QNSubMenuCollectionViewCell *_optimateCell;
    unsigned long long _curSwitchIndex;
    NSIndexPath *_preCurIndex;
    struct CGPoint _endCenterOfMoveCell;
    struct CGPoint _moveAnimationEndPoint;
    _Bool _hasClickedLocalSwitch;
    _Bool _enableTapGest;
    long long _currentIndex;
    _Bool _showDelIconInFirstSection;
    NSObject<SubMenuSettingViewDataSourceDelegate> *_dataSource;
    NSMutableArray *_beforeModifiedArray;
    NSMutableArray *_moveArray;
    NSMutableArray *_userAdjustedArray;
    CDUnknownBlockType _selectBlock;
    UITapGestureRecognizer *_tapRecognizer;
    UILongPressGestureRecognizer *_longRecognizer;
    UICollectionView *_collectionView;
    CSubMenuList *_unRemoveList;
    CSubMenuItem *_provinvceItem;
    CSubMenuItem *_cityItem;
    NSString *_currentChannelID;
    long long _channelCountLimit;
}

@property(nonatomic) long long channelCountLimit; // @synthesize channelCountLimit=_channelCountLimit;
@property(retain, nonatomic) NSString *currentChannelID; // @synthesize currentChannelID=_currentChannelID;
@property(retain, nonatomic) CSubMenuItem *cityItem; // @synthesize cityItem=_cityItem;
@property(retain, nonatomic) CSubMenuItem *provinvceItem; // @synthesize provinvceItem=_provinvceItem;
@property(retain, nonatomic) CSubMenuList *unRemoveList; // @synthesize unRemoveList=_unRemoveList;
@property(retain, nonatomic) UICollectionView *collectionView; // @synthesize collectionView=_collectionView;
@property(nonatomic) _Bool showDelIconInFirstSection; // @synthesize showDelIconInFirstSection=_showDelIconInFirstSection;
@property(retain, nonatomic) UILongPressGestureRecognizer *longRecognizer; // @synthesize longRecognizer=_longRecognizer;
@property(retain, nonatomic) UITapGestureRecognizer *tapRecognizer; // @synthesize tapRecognizer=_tapRecognizer;
@property(copy, nonatomic) CDUnknownBlockType selectBlock; // @synthesize selectBlock=_selectBlock;
@property(retain, nonatomic) NSMutableArray *userAdjustedArray; // @synthesize userAdjustedArray=_userAdjustedArray;
@property(retain, nonatomic) NSMutableArray *moveArray; // @synthesize moveArray=_moveArray;
@property(retain, nonatomic) NSMutableArray *beforeModifiedArray; // @synthesize beforeModifiedArray=_beforeModifiedArray;
@property(nonatomic) __weak NSObject<SubMenuSettingViewDataSourceDelegate> *dataSource; // @synthesize dataSource=_dataSource;
- (void).cxx_destruct;
- (_Bool)p_isInBeforeCurrentChannelsItem:(id)arg1;
- (void)p_noticeChangeBaseOnChannelsLimitNum:(long long)arg1;
- (void)animationDidStop:(id)arg1 finished:(_Bool)arg2;
- (void)animationDidStart:(id)arg1;
- (id)duplicate:(id)arg1;
- (id)p_getPositionAnimationWithStartPoint:(struct CGPoint)arg1 endPoint:(struct CGPoint)arg2 animationName:(id)arg3;
- (void)enterToCheckAllLocalChannels;
- (void)didSwitchSelectAtTab:(unsigned long long)arg1;
- (struct CGSize)collectionView:(id)arg1 layout:(id)arg2 referenceSizeForFooterInSection:(long long)arg3;
- (struct CGSize)collectionView:(id)arg1 layout:(id)arg2 referenceSizeForHeaderInSection:(long long)arg3;
- (id)collectionView:(id)arg1 viewForSupplementaryElementOfKind:(id)arg2 atIndexPath:(id)arg3;
- (id)_getSubMenuItemWithIndexPath:(id)arg1;
- (id)collectionView:(id)arg1 cellForItemAtIndexPath:(id)arg2;
- (long long)collectionView:(id)arg1 numberOfItemsInSection:(long long)arg2;
- (long long)numberOfSectionsInCollectionView:(id)arg1;
- (void)longGestureUpdateState:(id)arg1;
- (void)tapGestureHandle:(id)arg1;
- (void)_initGestureRecognizer;
- (void)p_handleChannelListChanged;
- (id)menuCellForItem:(id)arg1;
- (void)resert;
- (_Bool)getIfHasClickLocalSwitch;
- (void)themeChanged:(long long)arg1;
- (void)scroll2Top;
- (void)dealloc;
- (id)initWithFrame:(struct CGRect)arg1 andViewModel:(id)arg2 withCurrentIndex:(long long)arg3;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

