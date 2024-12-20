//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSTimer;

@interface CTimerTask : NSObject
{
    SEL _taskSelector;
    id _weakTarget;
    double _timeInterval;
    NSTimer *_timer;
}

- (void).cxx_destruct;
- (void)stopTask;
- (void)startTaskDelay:(double)arg1 repeats:(_Bool)arg2;
- (void)startTask;
- (void)dealloc;
- (id)initWithTask:(SEL)arg1 targetDel:(id)arg2 timeInterval:(double)arg3;

@end

