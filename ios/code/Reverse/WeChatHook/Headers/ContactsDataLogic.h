//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMObject.h"

#import "IContactMgrExt.h"
#import "IFTSContactMgrExt.h"
#import "PluginUtilExt.h"

@class FTSContactMgr, MMTimer, NSDictionary, NSMutableArray, NSMutableDictionary, NSString, WCSmartGroupCore;

@interface ContactsDataLogic : MMObject <IFTSContactMgrExt, IContactMgrExt, PluginUtilExt>
{
    id <ContactsDataLogicDelegate> m_delegate;
    NSMutableDictionary *m_dicAllContacts;
    NSMutableArray *m_arrAllKey;
    NSMutableArray *m_arrFilteredContacts;
    NSMutableArray *m_arrChatRooms;
    NSMutableDictionary *m_dicOpenIMContacts;
    NSMutableDictionary *m_dicOpenIMContactClassifys;
    unsigned int m_uiScene;
    unsigned int m_uiNormalContact;
    _Bool m_bSort;
    _Bool m_bNeedReload;
    _Bool m_extendChatRoom;
    unsigned int m_uiContactCount;
    unsigned int m_eFTSDataSource;
    _Bool m_hadOpenIMContact;
    FTSContactMgr *_ftsContactMgr;
    NSString *nsCurrentSearchText;
    NSMutableArray *_arrResultKey;
    NSMutableDictionary *_dicResultTitle;
    NSMutableDictionary *_dicResult;
    WCSmartGroupCore *_recommendLogic;
    NSDictionary *_dicRecommendGroupSelectedContacts;
    unsigned int _smartGroupSeq;
    NSMutableArray *m_arrRecommendContacts;
    NSMutableArray *m_arrRecommendGroups;
    MMTimer *m_ProcessOnModifyContactTimer;
    _Bool m_bNotSearchTopHit;
    _Bool m_bNotifySearchWhenSearchAll;
    _Bool _bMemberMatch;
    int m_enAsyncSearchOption;
    NSMutableArray *_myNormalContactArray;
}

@property(retain, nonatomic) NSMutableArray *myNormalContactArray; // @synthesize myNormalContactArray=_myNormalContactArray;
@property(nonatomic) _Bool bMemberMatch; // @synthesize bMemberMatch=_bMemberMatch;
@property(nonatomic) int m_enAsyncSearchOption; // @synthesize m_enAsyncSearchOption;
@property(nonatomic) _Bool m_bNotifySearchWhenSearchAll; // @synthesize m_bNotifySearchWhenSearchAll;
@property(nonatomic) _Bool m_bNotSearchTopHit; // @synthesize m_bNotSearchTopHit;
@property(nonatomic) _Bool m_hadOpenIMContact; // @synthesize m_hadOpenIMContact;
@property(nonatomic) unsigned int m_eFTSDataSource; // @synthesize m_eFTSDataSource;
@property(nonatomic) _Bool m_extendChatRoom; // @synthesize m_extendChatRoom;
@property(nonatomic) _Bool m_bSort; // @synthesize m_bSort;
@property(readonly, nonatomic) unsigned int m_uiNormalContact; // @synthesize m_uiNormalContact;
@property(nonatomic) unsigned int m_uiScene; // @synthesize m_uiScene;
@property(nonatomic) __weak id <ContactsDataLogicDelegate> m_delegate; // @synthesize m_delegate;
- (void).cxx_destruct;
- (unsigned int)genSeq;
- (void)finishTask:(id)arg1;
- (_Bool)asyncSearchRecommendsBy:(id)arg1 onlyGroups:(_Bool)arg2;
- (void)asyncCalRecommendGroups:(id)arg1;
- (_Bool)isRecommendGroups:(id)arg1;
- (void)updateRecommendGroups:(id)arg1;
- (id)getRecommendGroups;
- (_Bool)isRecommendContact:(id)arg1;
- (void)updateRecommendContacts:(id)arg1;
- (id)getRecommendContacts;
- (void)FilterSearchResultOfNormalContacts:(id)arg1;
- (_Bool)fillSectionResultForOption:(int)arg1 arrSectionKey:(id)arg2 dicSectionTitle:(id)arg3 dicSearchResult:(id)arg4;
- (id)filterByGroupSelectedContacts:(id)arg1;
- (void)onFTSContactSearchResultChanged:(_Bool)arg1;
- (unsigned int)topHitTypeForRandomSearchOption:(int)arg1;
- (unsigned int)currentTopHitType;
- (void)onUnInstallPlugin:(int)arg1;
- (void)onInstallPlugin:(int)arg1;
- (void)onContactListUpdate:(unsigned int)arg1;
- (void)onRemoveContactFromAddressBook:(id)arg1;
- (void)onDeleteContact:(id)arg1;
- (void)onModifyContact:(id)arg1;
- (void)processOnModifyContactTimer;
- (void)stopLockerTimesup;
- (void)multiSelectWithSearchResult:(id)arg1;
- (id)getMatchTipForUsername:(id)arg1;
- (id)getFilteredContacts;
- (id)getAllContacts;
- (id)getAllContactsDictionary;
- (id)getContactsArrayWith:(id)arg1;
- (id)getEnterpriseBrandContactsArray;
- (id)getKeysArray;
- (void)doSearch:(id)arg1 Pre:(_Bool)arg2;
- (void)delaySearch:(id)arg1 slowMode:(_Bool)arg2;
- (void)delaySearchImp:(id)arg1;
- (void)doAsynSearch:(id)arg1;
- (void)clearAsynSearchLastQueryText;
- (void)updateSelectedContacts:(id)arg1;
- (void)updateAsynSearchQueryText:(id)arg1;
- (void)doAsynInit;
- (void)dealloc;
- (id)initWithScene:(unsigned int)arg1 delegate:(id)arg2;
- (id)initWithScene:(unsigned int)arg1 delegate:(id)arg2 sort:(_Bool)arg3 extendChatRoom:(_Bool)arg4;
- (id)initWithScene:(unsigned int)arg1 delegate:(id)arg2 sort:(_Bool)arg3;
- (_Bool)reloadContacts;
- (void)onlyReloadOpemIMContacts;
- (void)filtInContacts:(id)arg1;
- (void)filterForSearchContact:(id)arg1;
- (void)filterOnlyBrandContactContact:(id)arg1;
- (void)filterSingleSelectSession:(id)arg1;
- (void)filterTransferMoneySimpleSessionContacts:(id)arg1;
- (void)filterTransferMoneyContacts:(id)arg1;
- (void)filterOnlyWeixinContact:(id)arg1;
- (void)filterVoiceContact:(id)arg1;
- (void)filterVideoContact:(id)arg1;
- (void)filterMutilSelectWithBakChatFilter:(id)arg1;
- (void)filterSelectWithVerifyedContacts:(id)arg1;
- (void)filterHistoryGroupContacts:(id)arg1 IgnoreOpenim:(_Bool)arg2;
- (_Bool)hasHistoryGroupContacts;
- (_Bool)hasGroupContacts;
- (void)filterGroupContacts:(id)arg1 IgnoreOpenim:(_Bool)arg2;
- (void)filterMultiSelectContacts:(id)arg1 IgnoreOpenim:(_Bool)arg2;
- (void)filterSelectOpenIMContacts:(id)arg1;
- (void)filterSelectWithBrandContacts:(id)arg1 IgnoreOpenim:(_Bool)arg2;
- (void)filterSelectContacts:(id)arg1;
- (void)filterOpenImContactViewContacts:(id)arg1;
- (void)filterContactsViewContacts:(id)arg1;
- (id)getDicOpenIMContactClassifys;
- (id)getDicOpenIMContacts;
- (id)getChatRoomContacts;
- (void)addContact:(id)arg1;
- (void)sort;
- (id)addSectionKey:(id)arg1;
- (id)addHiddenSectionKey:(id)arg1;
- (void)pluginsChanged;
- (_Bool)hasShowOpenIMEntrance;
- (_Bool)hasChatRoom;
- (void)deleteContact:(id)arg1 deleteInDB:(_Bool)arg2;
- (void)unInstallPlugin:(id)arg1;
- (id)getAllNormalContact;
- (id)getFavourContactArray;
- (unsigned int)getContactCount;
- (unsigned int)getOpenIMAcctTypeCount;
- (unsigned int)getEnterpriseBrandCount;
- (_Bool)shouldShowBrandGroup;
- (void)processOnModifyContact;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

