//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSObject<OS_dispatch_queue>;

@interface ODKVBOSSReport : NSObject
{
    NSObject<OS_dispatch_queue> *_taskQueue;
}

+ (id)sharedInstance;
@property(retain, nonatomic) NSObject<OS_dispatch_queue> *taskQueue; // @synthesize taskQueue=_taskQueue;
- (void).cxx_destruct;
- (void)report:(id)arg1 withBossid:(unsigned int)arg2 withPassword:(unsigned int)arg3;
- (id)initUniqueInstance;

@end
