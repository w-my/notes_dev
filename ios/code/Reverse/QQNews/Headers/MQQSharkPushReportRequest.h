//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MQQSharkBaseRequest.h"

@interface MQQSharkPushReportRequest : MQQSharkBaseRequest
{
    int _cmdId;
    long long _pushId;
}

- (_Bool)getCmdId:(int *)arg1 requestData:(vector_aa1d262e *)arg2;
- (void)prepareSharkData;
- (void)reportWithServerSashimi:(struct ServerSashimi *)arg1;

@end

