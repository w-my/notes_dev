//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "WAJSEventHandler_BaseEvent.h"

@class NSString;

@interface WAJSEventHandler_launchApplication : WAJSEventHandler_BaseEvent
{
    NSString *_appID;
    NSString *_launchAppID;
    NSString *_messageExt;
    NSString *_parameter;
    NSString *_scheme;
    _Bool _bIsShowLaunchFailToast;
    long long _operateDirectly;
    NSString *_installSchemeUrl;
    unsigned int _installAction;
}

- (void).cxx_destruct;
- (_Bool)launchAppleStoreWithSchemeUrl:(id)arg1 action:(unsigned int)arg2 jumpAppStoreFlag:(int)arg3 getError:(id *)arg4;
- (_Bool)hasPermissionToLaunchWebStore;
- (id)launchAppleStoreErrorWithCode:(long long)arg1 description:(id)arg2;
- (void)sendReqLaunchAppWithShowType:(unsigned long long)arg1 jumpAppStoreFlag:(int)arg2;
- (void)onCheckResponse:(id)arg1;
- (void)onCgiResponse:(id)arg1 forEvent:(unsigned int)arg2;
- (void)handleJSEvent:(id)arg1;
- (void)resetCacheParam;
- (void)dealloc;

@end

