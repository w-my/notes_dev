//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSThread;

@interface NativeTask : NSObject
{
    struct IMBNativeInterface *_interface;
    NSThread *_thread;
}

@property(retain, nonatomic) NSThread *thread; // @synthesize thread=_thread;
@property(nonatomic) struct IMBNativeInterface *interface; // @synthesize interface=_interface;
- (void).cxx_destruct;
- (void)update;
- (void)run;

@end

