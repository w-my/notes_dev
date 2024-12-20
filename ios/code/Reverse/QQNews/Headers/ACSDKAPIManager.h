//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "ACAPIBaseManager.h"

#import "ACAPIManager.h"
#import "ACAPIManagerValidator.h"

@class NSString;

@interface ACSDKAPIManager : ACAPIBaseManager <ACAPIManagerValidator, ACAPIManager>
{
}

- (_Bool)manager:(id)arg1 isCorrectWithCallBackData:(id)arg2;
- (_Bool)manager:(id)arg1 isCorrectWithParamsData:(id)arg2;
- (long long)nativeCacheTimeInSeconds;
- (_Bool)shouldCache;
- (unsigned long long)requestType;
- (id)serviceType;
- (id)methodName;
- (id)reformParams:(id)arg1;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

