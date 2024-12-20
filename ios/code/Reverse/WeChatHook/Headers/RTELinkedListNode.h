//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMObject.h"

#import "NSCopying.h"

@interface RTELinkedListNode : MMObject <NSCopying>
{
    unsigned long long _length;
    RTELinkedListNode *_nextNode;
    RTELinkedListNode *_preNode;
}

@property(retain, nonatomic) RTELinkedListNode *preNode; // @synthesize preNode=_preNode;
@property(retain, nonatomic) RTELinkedListNode *nextNode; // @synthesize nextNode=_nextNode;
@property(nonatomic) unsigned long long length; // @synthesize length=_length;
- (void).cxx_destruct;
- (_Bool)canBeMergedInto:(id)arg1;
- (void)clearNode;
- (id)copyWithZone:(struct _NSZone *)arg1;

@end

