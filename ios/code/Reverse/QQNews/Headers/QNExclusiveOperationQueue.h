//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSOperationQueue.h"

@class NSMutableDictionary, NSObject;

@interface QNExclusiveOperationQueue : NSOperationQueue
{
    NSObject *_lock;
    NSMutableDictionary *_enqueuedOperations;
    NSMutableDictionary *_waitOperations;
}

- (void).cxx_destruct;
- (void)_onOperationFinishedStateChange:(id)arg1;
- (void)p_enqueueOperation:(id)arg1 forKey:(id)arg2;
- (void)cancelAllOperations;
- (void)addOperation:(id)arg1;
- (id)init;

@end
