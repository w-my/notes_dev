//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSError, QNNetworkResponse, QNNetworkTransport;

@protocol QNNetworkTransportDelegate <NSObject>
- (void)onTransportFail:(QNNetworkTransport *)arg1 error:(NSError *)arg2;
- (void)onTransportCompletion:(QNNetworkTransport *)arg1 response:(QNNetworkResponse *)arg2;
@end
