//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "CSubMenuProtocol.h"

@class CSubMenuList, NSString, QNLocalMenuItemRecommendModel;

@interface CSubMenuSettingData : NSObject <CSubMenuProtocol>
{
    _Bool _allSubmenuComeFromServer;
    _Bool _hasUserAdjusted;
    _Bool _subMenuChannelsRecommendShouldUpdate;
    _Bool _isNewUser;
    _Bool _isIgnorePullSubmenu;
    CSubMenuList *_listInCache;
    QNLocalMenuItemRecommendModel *_localMenuItemRecommendModel;
    CSubMenuList *_nowChannelList;
}

+ (_Bool)shouldUpdateChannelsRecommendForExpireTime;
+ (id)userSelectedChannelForHeadline;
+ (id)sharedInstance;
@property(retain, nonatomic) CSubMenuList *nowChannelList; // @synthesize nowChannelList=_nowChannelList;
@property(retain, nonatomic) QNLocalMenuItemRecommendModel *localMenuItemRecommendModel; // @synthesize localMenuItemRecommendModel=_localMenuItemRecommendModel;
@property(retain, nonatomic) CSubMenuList *listInCache; // @synthesize listInCache=_listInCache;
@property(nonatomic) _Bool isIgnorePullSubmenu; // @synthesize isIgnorePullSubmenu=_isIgnorePullSubmenu;
@property(nonatomic) _Bool isNewUser; // @synthesize isNewUser=_isNewUser;
@property(nonatomic) _Bool subMenuChannelsRecommendShouldUpdate; // @synthesize subMenuChannelsRecommendShouldUpdate=_subMenuChannelsRecommendShouldUpdate;
@property(nonatomic) _Bool hasUserAdjusted; // @synthesize hasUserAdjusted=_hasUserAdjusted;
- (void).cxx_destruct;
- (unsigned long long)getIndexOfSubMenuItemWithChannelID:(id)arg1;
- (id)p_reverseArray:(id)arg1;
- (_Bool)isLocalChannel:(id)arg1;
- (unsigned long long)getFirstLocalSubMenuItemIndex;
- (id)getFirstLocalSubMenuItem;
- (void)updateSubmenuInCurrentWithList:(id)arg1;
- (_Bool)removeChannelToCurrentChannelList:(id)arg1 atIndex:(unsigned long long)arg2;
- (_Bool)moveChannelID:(id)arg1 toIndex:(unsigned long long)arg2;
- (_Bool)addChannelToCurrentChannelList:(id)arg1 atIndex:(unsigned long long)arg2 adjustIfNotMatch:(_Bool)arg3;
- (_Bool)addChannelToCurrentChannelList:(id)arg1 atIndex:(unsigned long long)arg2;
- (_Bool)addChannelToCurrentChannelList:(id)arg1;
- (_Bool)isExistChannelInAllChannelList:(id)arg1;
- (long long)getChannelIndexInCurrentChannelList:(id)arg1;
- (_Bool)containChannelInCurrentChannelList:(id)arg1;
- (void)p_reportCurrentChannels;
- (_Bool)p_shouldReportSubMenuChannels;
- (void)p_reportCurrentChannelsWhenInit;
- (void)reportCurrentChannelsForChanged;
- (void)updateCurrentFromAllForNameChanged:(id)arg1 andAll:(id)arg2;
- (void)deleteOutDatedChannelsFromCurrent:(id)arg1 listInAll:(id)arg2;
- (id)getLocationIdForRecommendCity;
- (_Bool)_updateLocalStrongRecommendAdcode;
- (_Bool)_filterLocalStrongRecommendMenuItem:(id)arg1 compareProvinceMenuItem:(id)arg2;
- (void)p_resetPositionForVideoChannelAndFirstLocalChannelInCurrentList:(id)arg1;
- (void)getLocalSubMenuItemInCurrentWithChannelID:(id)arg1;
- (void)resetVideoOrLocalChannelPositionForLongTimeUnused;
- (id)updateSubMenuInCurrent;
- (id)getVideoItemFromCurrent;
- (id)p_getSubmenuInCurrentFromKeychain;
- (id)p_getSubmenuItemListInCurrentFromKeychain;
- (_Bool)p_hasRecoverSubmenuFromKeychain;
- (_Bool)updateVideoChannel:(id)arg1;
- (id)getVideoChannelItem:(id)arg1;
- (_Bool)writeAllChannelsToDisk:(id)arg1;
- (void)storeChannelsToDisk:(id)arg1;
- (void)adjustedByUser;
- (void)p_saveSubmenuInCurrentToKeyChain;
- (id)getAllSubMenu;
- (unsigned long long)getChannelCountInCurrent;
- (void)getMenuItemByChannelID:(id)arg1 handleBlock:(CDUnknownBlockType)arg2;
- (void)getAllSubMenuWithHandleBlock:(CDUnknownBlockType)arg1;
- (id)getInCurrentSubChannels;
- (id)getSubMenuInCurrent;
- (id)getSubMenuList;
- (id)getMenuItemByChannelID:(id)arg1;
- (id)getChannelNameByChannelID:(id)arg1;
- (unsigned long long)getIndexInCurrentByChannelID:(id)arg1;
- (id)getFirstChannelIDInCurrent;
- (id)getChannelIDInCurrentAtIndex:(long long)arg1;
- (id)getFirstSubMenuItem;
- (id)getSubMenuItemAtIndex:(long long)arg1;
- (_Bool)hasNewSubMenu;
- (_Bool)hasChannelsRecommend;
- (void)writeAllSubMenuToDisk:(id)arg1 compareNewMenu:(_Bool)arg2;
- (_Bool)_saveLocalMenuItemRecommendModel;
- (void)_initLocalMenuItemRecommendModel;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
