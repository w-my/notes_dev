//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class MMKJumpRemindInfo, MMVoidBoolStringCallback;

@protocol MMKindaJumpRemindManager <NSObject>
- (void)onDestroyJumpRemindManager;
- (void)jumpRemindImpl:(MMKJumpRemindInfo *)arg1 clientScene:(int)arg2 payScene:(int)arg3 interruptCb:(MMVoidBoolStringCallback *)arg4 continueCb:(MMVoidBoolStringCallback *)arg5;
@end

