//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSData, NSDictionary, NSString, NSURLRequest;

@interface ACURLResponse : NSObject
{
    _Bool _isCache;
    unsigned long long _status;
    NSString *_contentString;
    id _content;
    long long _requestId;
    NSURLRequest *_request;
    NSData *_responseData;
    NSDictionary *_requestParams;
}

@property(nonatomic) _Bool isCache; // @synthesize isCache=_isCache;
@property(copy, nonatomic) NSDictionary *requestParams; // @synthesize requestParams=_requestParams;
@property(copy, nonatomic) NSData *responseData; // @synthesize responseData=_responseData;
@property(copy, nonatomic) NSURLRequest *request; // @synthesize request=_request;
@property(nonatomic) long long requestId; // @synthesize requestId=_requestId;
@property(copy, nonatomic) id content; // @synthesize content=_content;
@property(copy, nonatomic) NSString *contentString; // @synthesize contentString=_contentString;
@property(nonatomic) unsigned long long status; // @synthesize status=_status;
- (void).cxx_destruct;
- (unsigned long long)responseStatusWithError:(id)arg1;
- (id)initWithData:(id)arg1;
- (id)initWithNoNetworkResponse:(id)arg1;
- (id)initWithResponseString:(id)arg1 requestId:(id)arg2 request:(id)arg3 responseData:(id)arg4 error:(id)arg5;
- (id)initWithResponseString:(id)arg1 requestId:(id)arg2 request:(id)arg3 responseData:(id)arg4 status:(unsigned long long)arg5;

@end
