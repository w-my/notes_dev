//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class MMVoidCallback;

@protocol MMKTimerService <NSObject>
- (void)throttleImpl:(float)arg1 handler:(MMVoidCallback *)arg2;
- (double)now;
- (void)dispatchAfterImpl:(float)arg1 handle:(MMVoidCallback *)arg2;
- (void)stopTimeCheck;
- (void)startTimeCheck;
- (void)initIntervalAndCheckedCallbackImpl:(float)arg1 timeCheckCallback:(MMVoidCallback *)arg2;
@end

