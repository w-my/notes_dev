//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSString;

@interface QNKVOInfo : NSObject
{
    NSObject *_observedObject;
    NSObject *_observer;
    NSString *_keyPath;
    CDUnknownBlockType _callback;
}

@property(readonly, copy, nonatomic) CDUnknownBlockType callback; // @synthesize callback=_callback;
@property(readonly, copy, nonatomic) NSString *keyPath; // @synthesize keyPath=_keyPath;
@property(readonly, nonatomic) __weak NSObject *observer; // @synthesize observer=_observer;
@property(readonly, nonatomic) __weak NSObject *observedObject; // @synthesize observedObject=_observedObject;
- (void).cxx_destruct;
- (void)unbind;
- (void)invokeWithOldValue:(id)arg1 newValue:(id)arg2;
- (id)initWithObserved:(id)arg1 observer:(id)arg2 keyPath:(id)arg3 callback:(CDUnknownBlockType)arg4;

@end

