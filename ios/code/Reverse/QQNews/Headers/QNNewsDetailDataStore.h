//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNAbstractLevelDBDataStore.h"

@interface QNNewsDetailDataStore : QNAbstractLevelDBDataStore
{
    double _lastCheckDBTime;
}

+ (id)nameOfDB;
@property(nonatomic) double lastCheckDBTime; // @synthesize lastCheckDBTime=_lastCheckDBTime;
- (void)p_removeOutdateDataIfNeed;
- (double)p_newsDBTimeWithNewsItemKey:(id)arg1;
- (void)p_createNewsDBTimeWithNewsItemKey:(id)arg1;
- (id)p_ketForNewsDBTimeWithKey:(id)arg1;
- (void)p_updateLastCheckValidTime;
- (double)p_lastCheckValidTime;
- (_Bool)removeNewsContentWithKey:(id)arg1;
- (id)loadNewsItemWithKey:(id)arg1;
- (_Bool)saveNewsItem:(id)arg1 forKey:(id)arg2;
- (id)p_saveFilePathWithNewsItem:(id)arg1;
- (id)initWithDB:(id)arg1;

@end
