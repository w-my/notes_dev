//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "TTImageDetectTaskBase.h"

@class NSObject<OS_dispatch_queue>, NSString;

@interface TTImageDetectTaskBase : NSObject <TTImageDetectTaskBase>
{
    NSObject<OS_dispatch_queue> *_processQueue;
}

+ (id)createDefaultQueue:(char *)arg1;
@property(retain, nonatomic) NSObject<OS_dispatch_queue> *processQueue; // @synthesize processQueue=_processQueue;
- (void).cxx_destruct;
- (void)detectParamsOnProcessQueue:(id)arg1;
- (void)detectImage:(id)arg1;
- (void)runAsyncOnGroup:(id)arg1 block:(CDUnknownBlockType)arg2;
- (void)runAsyncBlock:(_Bool)arg1 block:(CDUnknownBlockType)arg2;
- (void)runAsyncBlock:(CDUnknownBlockType)arg1;
- (void)runSyncBlock:(CDUnknownBlockType)arg1;
- (_Bool)checkThreadSafe;
- (id)initWithQueueLabel:(char *)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
