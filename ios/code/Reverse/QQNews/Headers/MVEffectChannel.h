//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MVMediaChannel.h"

@class NSMutableDictionary;

@interface MVEffectChannel : MVMediaChannel
{
    _Bool _isReady;
    long long _mediaContentMode;
    long long _order;
    NSMutableDictionary *_internalActionMap;
}

@property(retain, nonatomic) NSMutableDictionary *internalActionMap; // @synthesize internalActionMap=_internalActionMap;
@property(nonatomic) long long order; // @synthesize order=_order;
@property(nonatomic) _Bool isReady; // @synthesize isReady=_isReady;
@property(nonatomic) long long mediaContentMode; // @synthesize mediaContentMode=_mediaContentMode;
- (void).cxx_destruct;
- (void)recurseActionsToArray:(id)arg1 fromComposition:(id)arg2;
- (id)reloadActionForKey:(id)arg1;
- (void)removeActionsForKeyWithPrefix:(id)arg1;
- (id)removeActionForKey:(id)arg1;
- (id)addActionForKey:(id)arg1 createIfNeeded:(CDUnknownBlockType)arg2;
- (void)addAction:(id)arg1 forKey:(id)arg2;
- (id)actionsWithFilter:(CDUnknownBlockType)arg1;
- (id)actionForKey:(id)arg1;
- (id)keysOfActions;

@end
