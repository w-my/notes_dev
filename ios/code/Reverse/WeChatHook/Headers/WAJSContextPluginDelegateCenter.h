//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSMutableArray, NSRecursiveLock, Protocol;

@interface WAJSContextPluginDelegateCenter : NSObject
{
    Protocol *m_protocolKey;
    NSRecursiveLock *m_delegateLock;
    NSMutableArray *m_delegates;
    _Bool m_needCleanUp;
}

- (void).cxx_destruct;
- (void)dealloc;
- (void)cleanUp;
- (void)__cleanUp;
- (void)releaseDelegates;
- (void)__delegate:(SEL)arg1 block:(CDUnknownBlockType)arg2;
- (void)removeDelegate:(id)arg1;
- (_Bool)addDelegate:(id)arg1;
- (id)initWithKey:(id)arg1;

@end
