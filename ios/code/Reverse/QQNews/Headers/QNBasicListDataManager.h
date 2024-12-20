//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class KBListItemCollection, NSMutableArray, NSString, QNListItemDBManager<QNListItemDBManagerSubClassProtocol>;

@interface QNBasicListDataManager : NSObject
{
    _Bool _cacheResponseData;
    NSString *_channelID;
    NSString *_specialKeyForStorage;
    long long _indexDBType;
    KBListItemCollection *_itemsCollection;
    CDUnknownBlockType _listItemFilterBlock;
    NSMutableArray *_bottmomNewerNewsList;
    QNListItemDBManager<QNListItemDBManagerSubClassProtocol> *_listItemDBManager;
}

@property(retain, nonatomic) QNListItemDBManager<QNListItemDBManagerSubClassProtocol> *listItemDBManager; // @synthesize listItemDBManager=_listItemDBManager;
@property(retain) NSMutableArray *bottmomNewerNewsList; // @synthesize bottmomNewerNewsList=_bottmomNewerNewsList;
@property(copy, nonatomic) CDUnknownBlockType listItemFilterBlock; // @synthesize listItemFilterBlock=_listItemFilterBlock;
@property(retain, nonatomic) KBListItemCollection *itemsCollection; // @synthesize itemsCollection=_itemsCollection;
@property(readonly, nonatomic) long long indexDBType; // @synthesize indexDBType=_indexDBType;
@property(nonatomic) _Bool cacheResponseData; // @synthesize cacheResponseData=_cacheResponseData;
@property(readonly, copy, nonatomic) NSString *specialKeyForStorage; // @synthesize specialKeyForStorage=_specialKeyForStorage;
@property(readonly, copy, nonatomic) NSString *channelID; // @synthesize channelID=_channelID;
- (void).cxx_destruct;
- (id)getIndexItemWithIdStr:(id)arg1;
- (id)getListIndexData;
- (id)getListNewsItemsForIDS:(id)arg1;
- (id)getListStickedData;
- (id)loadTopListItemsFromDBWithCount:(long long)arg1;
- (id)loadDataFromDBWithDirection:(unsigned long long)arg1;
- (void)clearMemeryCachedItems;
- (void)clearCachedItems;
- (void)loadNewsFromDiskIfNeed;
- (_Bool)haveEffectiveData;
- (id)handleLoaderSuccessResponse:(id)arg1 cachePolicy:(unsigned long long)arg2 direction:(unsigned long long)arg3 loadOption:(long long)arg4;
- (void)setSpecialKeyForStorage:(id)arg1;
- (id)customListItemDBManager;
- (id)initWithChannelID:(id)arg1 storageKey:(id)arg2 indexDBType:(long long)arg3;

@end

