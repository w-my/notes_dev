//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSMapTable, NSRecursiveLock;

@interface QSMatchItemPool : NSObject
{
    NSRecursiveLock *_lock;
    NSMapTable *_allMatchItems;
}

+ (id)sharedInstance;
@property(retain, nonatomic) NSMapTable *allMatchItems; // @synthesize allMatchItems=_allMatchItems;
@property(retain, nonatomic) NSRecursiveLock *lock; // @synthesize lock=_lock;
- (void).cxx_destruct;
- (void)refreshAllMatchesAttentions;
- (id)currentMatchItemWithMid:(id)arg1;
- (id)matchItemWithItemWithOutResetting:(id)arg1;
- (id)matchItemWithInfo:(id)arg1 newItem:(_Bool *)arg2;
- (id)matchItemWithItem:(id)arg1;
- (id)matchItemWithMatchID:(id)arg1 newItem:(_Bool *)arg2 newItemBlock:(CDUnknownBlockType)arg3;
- (id)init;

@end
