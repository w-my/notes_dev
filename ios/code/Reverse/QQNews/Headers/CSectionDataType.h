//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "NSCoding.h"
#import "NSCopying.h"

@class NSArray, NSDate, NSDictionary, NSMutableArray, NSOperationQueue, NSString, QNArticleContentEventTimeLineNode;

@interface CSectionDataType : NSObject <NSCopying, NSCoding>
{
    NSOperationQueue *_opQueue;
    _Bool _isChannel;
    _Bool _isCache;
    NSString *_key;
    NSString *_introduce;
    NSString *_introduceName;
    NSString *_specialName;
    NSDictionary *_thumbnails;
    NSMutableArray *_sectionDataArray;
    NSArray *_keywordList;
    NSDate *_updateDate;
    NSArray *_activityItems;
    NSArray *_topicList;
    QNArticleContentEventTimeLineNode *_timeLineNode;
    NSString *_adList;
}

@property(copy, nonatomic) NSString *adList; // @synthesize adList=_adList;
@property(retain, nonatomic) QNArticleContentEventTimeLineNode *timeLineNode; // @synthesize timeLineNode=_timeLineNode;
@property(nonatomic) _Bool isCache; // @synthesize isCache=_isCache;
@property(retain, nonatomic) NSArray *topicList; // @synthesize topicList=_topicList;
@property(retain, nonatomic) NSArray *activityItems; // @synthesize activityItems=_activityItems;
@property(retain, nonatomic) NSDate *updateDate; // @synthesize updateDate=_updateDate;
@property(nonatomic) _Bool isChannel; // @synthesize isChannel=_isChannel;
@property(retain, nonatomic) NSArray *keywordList; // @synthesize keywordList=_keywordList;
@property(retain, nonatomic) NSMutableArray *sectionDataArray; // @synthesize sectionDataArray=_sectionDataArray;
@property(retain, nonatomic) NSDictionary *thumbnails; // @synthesize thumbnails=_thumbnails;
@property(copy, nonatomic) NSString *specialName; // @synthesize specialName=_specialName;
@property(copy, nonatomic) NSString *introduceName; // @synthesize introduceName=_introduceName;
@property(copy, nonatomic) NSString *introduce; // @synthesize introduce=_introduce;
@property(copy, nonatomic) NSString *key; // @synthesize key=_key;
- (void).cxx_destruct;
- (_Bool)insertAdListItem:(id)arg1 AtIndex:(long long)arg2 inSection:(long long)arg3;
- (id)loadMoreIDsInSection:(long long)arg1 count:(long long)arg2;
- (_Bool)appendListItems:(id)arg1 inSection:(long long)arg2;
- (_Bool)canLoadMoreInSection:(long long)arg1;
- (void)mergeWithSectionDataType:(id)arg1;
- (void)validateWithListItemDict:(id)arg1;
- (id)listItemDictionary;
- (_Bool)loadDataFromDisk:(_Bool)arg1;
- (void)writeDataToDiskAsyn:(_Bool)arg1 offlineData:(_Bool)arg2;
- (id)sectionDataPath:(_Bool)arg1;
- (id)dataPath:(_Bool)arg1;
- (_Bool)checkLastItem:(id)arg1;
- (_Bool)checkValid:(id)arg1;
- (_Bool)checkEmpty;
- (void)cleanup;
- (id)description;
- (_Bool)isVideoDoubleModeSection:(long long)arg1;
- (id)getAllItemsIDs;
- (id)getAllItems;
- (id)getSectionNameWithIndexPath:(long long)arg1;
- (id)getItemDataWithIndexPath:(id)arg1;
- (id)getSectionListWithName:(id)arg1;
- (id)getSectionListWithIndex:(long long)arg1;
- (long long)getSectionCountWithName:(id)arg1;
- (long long)getSectionCountWithIndex:(long long)arg1;
@property(readonly, nonatomic) long long count;
- (void)addSectionItemsFromArray:(id)arg1;
- (void)addSectionItem:(id)arg1 index:(long long)arg2;
- (void)addSectionItem:(id)arg1;
- (void)dealloc;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)initWithKey:(id)arg1;
- (id)init;

@end

