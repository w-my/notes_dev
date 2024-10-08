//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "QNAppDelegateService.h"
#import "QNPushNotificationAlertViewDelegate.h"
#import "UNUserNotificationCenterDelegate.h"

@class NSDictionary, NSString, QNPushNotificationAlertView, UIWindow;

@interface QNPushService : NSObject <UNUserNotificationCenterDelegate, QNPushNotificationAlertViewDelegate, QNAppDelegateService>
{
    NSDictionary *_startOptions;
    QNPushNotificationAlertView *_pushAlertView;
    NSString *_sence;
    NSString *_authPath;
}

@property(copy, nonatomic) NSString *authPath; // @synthesize authPath=_authPath;
@property(copy, nonatomic) NSString *sence; // @synthesize sence=_sence;
@property(retain, nonatomic) QNPushNotificationAlertView *pushAlertView; // @synthesize pushAlertView=_pushAlertView;
@property(copy, nonatomic) NSDictionary *startOptions; // @synthesize startOptions=_startOptions;
- (void).cxx_destruct;
- (void)pushAlertViewClicked:(id)arg1;
- (void)pushAlertViewDisappear:(id)arg1;
- (void)reportApplicationPushState:(id)arg1;
- (void)clearApplicationBadgeNumber;
- (void)requestPushAuthorize;
- (void)_reportUserPushAuthSelectionIfNeeded;
- (void)_handleLoginStatusChangedNotification;
- (void)_receivedAPushNotification:(id)arg1;
- (void)_reportPushSwitchEnabled:(_Bool)arg1 token:(id)arg2;
- (void)_reportNotificationAuthStatus:(id)arg1 token:(id)arg2;
- (void)_handleDidReceiveNotification:(id)arg1;
- (void)_showPushAlertViewInForeground:(id)arg1;
- (void)userNotificationCenter:(id)arg1 didReceiveNotificationResponse:(id)arg2 withCompletionHandler:(CDUnknownBlockType)arg3;
- (void)userNotificationCenter:(id)arg1 willPresentNotification:(id)arg2 withCompletionHandler:(CDUnknownBlockType)arg3;
- (void)application:(id)arg1 didReceiveRemoteNotification:(id)arg2 fetchCompletionHandler:(CDUnknownBlockType)arg3;
- (void)application:(id)arg1 didReceiveRemoteNotification:(id)arg2;
- (void)application:(id)arg1 didReceiveLocalNotification:(id)arg2;
- (void)application:(id)arg1 didFailToRegisterForRemoteNotificationsWithError:(id)arg2;
- (void)application:(id)arg1 didRegisterForRemoteNotificationsWithDeviceToken:(id)arg2;
- (void)application:(id)arg1 didRegisterUserNotificationSettings:(id)arg2;
- (_Bool)application:(id)arg1 didFinishLaunchingWithOptions:(id)arg2;
- (void)dealloc;
- (id)init;
- (id)serviceName;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;
@property(retain, nonatomic) UIWindow *window;

@end

