//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSMutableDictionary;

@interface QNKVODispatcher : NSObject
{
    NSMutableDictionary *_bindings;
    id _unsafeObservedObject;
}

@property(readonly, nonatomic) id unsafeObservedObject; // @synthesize unsafeObservedObject=_unsafeObservedObject;
- (void).cxx_destruct;
- (void)_unobserve:(id)arg1;
- (void)unbindObserver:(id)arg1;
- (void)unbindObserver:(id)arg1 keyPath:(id)arg2;
- (id)bindObserver:(id)arg1 keyPath:(id)arg2 callback:(CDUnknownBlockType)arg3;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
- (void)dealloc;
- (id)initWithObservedObject:(id)arg1;

@end

