//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMObject.h"

#import "NSCopying.h"

@class RTEAttributeNode, RTELinkedListNode;

@interface RTELinkedList : MMObject <NSCopying>
{
    RTELinkedListNode *_headNode;
    RTELinkedListNode *_cacheNode;
    unsigned long long _cacheLocation;
    unsigned long long _totalLength;
}

+ (id)creatEmptyList:(unsigned int)arg1 Length:(unsigned long long)arg2;
+ (_Bool)updateListIndexSinceHeadNode:(id)arg1 withLocation:(unsigned long long)arg2 withTotalLength:(unsigned long long)arg3 forceToEnd:(_Bool)arg4;
+ (_Bool)updateListIndexSinceHeadNode:(id)arg1 withLocation:(unsigned long long)arg2 withTotalLength:(unsigned long long)arg3;
@property(nonatomic) unsigned long long totalLength; // @synthesize totalLength=_totalLength;
@property(nonatomic) unsigned long long cacheLocation; // @synthesize cacheLocation=_cacheLocation;
@property(nonatomic) __weak RTELinkedListNode *cacheNode; // @synthesize cacheNode=_cacheNode;
@property(retain, nonatomic) RTELinkedListNode *headNode; // @synthesize headNode=_headNode;
- (void).cxx_destruct;
- (void)mergeNodesStartFrom:(id)arg1 isForward:(_Bool)arg2;
- (id)copyListInRange:(struct _NSRange)arg1;
- (void)appendNodes:(id)arg1 ofLength:(unsigned long long)arg2;
- (void)insertNodes:(id)arg1 ofLength:(unsigned long long)arg2 atIndex:(unsigned long long)arg3;
- (void)deleteNodesAtRange:(struct _NSRange)arg1;
- (void)updateCacheToIndex:(unsigned long long)arg1;
- (struct _NSRange)rangeOfNode:(id)arg1;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)dealloc;
- (id)description;
@property(nonatomic) unsigned int type;
@property(nonatomic) __weak RTEAttributeNode *cacheAttributeNode;
@property(retain, nonatomic) RTEAttributeNode *headAttributeNode;
- (_Bool)containListPrefixInRange:(struct _NSRange)arg1;

@end

