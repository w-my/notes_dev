//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "QNAppDelegateService.h"

@class NSString, UIWindow;

@interface QNLocationService : NSObject <QNAppDelegateService>
{
    int _currentLocationAuth;
}

@property(nonatomic) int currentLocationAuth; // @synthesize currentLocationAuth=_currentLocationAuth;
- (void)requestLocationAuthorize;
- (void)applicationDidBecomeActive:(id)arg1;
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
