//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "LKImageLoaderProtocol.h"

@class NSObject<OS_dispatch_queue>, NSObject<OS_dispatch_semaphore>, NSOperationQueue, NSString;

@interface LKImageLoader : NSObject <LKImageLoaderProtocol>
{
    NSObject<OS_dispatch_queue> *_gcd_queue;
    NSOperationQueue *_queue;
    NSObject<OS_dispatch_semaphore> *_semaphore;
}

@property(retain, nonatomic) NSObject<OS_dispatch_semaphore> *semaphore; // @synthesize semaphore=_semaphore;
@property(retain, nonatomic) NSOperationQueue *queue; // @synthesize queue=_queue;
@property(retain, nonatomic) NSObject<OS_dispatch_queue> *gcd_queue; // @synthesize gcd_queue=_gcd_queue;
- (void).cxx_destruct;
- (void)didBeUnregistered;
- (void)willBeRegistered;
- (unsigned long long)cancelRequest:(id)arg1;
- (_Bool)isValidRequest:(id)arg1;
@property(nonatomic) unsigned long long maxConcurrentOperationCount;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
