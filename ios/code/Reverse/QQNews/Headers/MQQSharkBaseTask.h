//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "MQQSharkCenterDelegate.h"

@class MQQSharkNetworkRequest, NSMutableArray, NSString;

@interface MQQSharkBaseTask : NSObject <MQQSharkCenterDelegate>
{
    MQQSharkNetworkRequest *_networkRequest;
    NSMutableArray *_csArray;
}

+ (id)taskQueue;
@property(retain, nonatomic) MQQSharkNetworkRequest *networkRequest; // @synthesize networkRequest=_networkRequest;
- (void)didSharkCenterFail:(id)arg1;
- (void)didSharkCenterFinish:(id)arg1 withResponse:(id)arg2 RSA:(_Bool *)arg3;
- (long long)countOfCS;
- (_Bool)deleteCS:(id)arg1;
- (void)addCS:(id)arg1;
- (void)cancel;
- (void)start;
- (void)startRequest:(id)arg1;
- (void)handleServerSashimi:(struct ServerSashimi *)arg1;
- (id)requestData;
- (void)dealloc;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

