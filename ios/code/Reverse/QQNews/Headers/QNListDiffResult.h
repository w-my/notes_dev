//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSArray, NSIndexSet, NSSet;

@interface QNListDiffResult : NSObject
{
    NSSet *_inserts;
    NSSet *_deletes;
    NSSet *_updates;
    NSArray *_moves;
    NSIndexSet *_insertSections;
    NSIndexSet *_deleteSections;
}

@property(copy, nonatomic) NSIndexSet *deleteSections; // @synthesize deleteSections=_deleteSections;
@property(copy, nonatomic) NSIndexSet *insertSections; // @synthesize insertSections=_insertSections;
@property(copy, nonatomic) NSArray *moves; // @synthesize moves=_moves;
@property(copy, nonatomic) NSSet *updates; // @synthesize updates=_updates;
@property(copy, nonatomic) NSSet *deletes; // @synthesize deletes=_deletes;
@property(copy, nonatomic) NSSet *inserts; // @synthesize inserts=_inserts;
- (void).cxx_destruct;
- (id)description;
- (_Bool)hasChanges;
- (void)reset;
- (id)initWithInserts:(id)arg1 deletes:(id)arg2 updates:(id)arg3 moves:(id)arg4 insertSections:(id)arg5 deleteSections:(id)arg6;
- (id)initWithInserts:(id)arg1 deletes:(id)arg2 updates:(id)arg3 moves:(id)arg4;

@end
