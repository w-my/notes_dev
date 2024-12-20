//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "NSCopying.h"

@class NSMapTable, NSObject<OS_dispatch_semaphore>;

@interface QNSyncHashMap : NSObject <NSCopying>
{
    NSObject<OS_dispatch_semaphore> *_lock;
    NSMapTable *_mapTable;
}

@property(retain, nonatomic) NSMapTable *mapTable; // @synthesize mapTable=_mapTable;
- (void).cxx_destruct;
- (void)removeAllObjects;
- (void)setObject:(id)arg1 forKeyedSubscript:(id)arg2;
- (id)objectForKeyedSubscript:(id)arg1;
- (id)toDictionary;
@property(readonly, nonatomic) unsigned long long count;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (id)initWithKeyPointerFunctions:(id)arg1 valuePointerFunctions:(id)arg2 capacity:(unsigned long long)arg3;
- (id)initWithKeyOptions:(unsigned long long)arg1 valueOptions:(unsigned long long)arg2 capacity:(unsigned long long)arg3;
- (id)init;

@end

