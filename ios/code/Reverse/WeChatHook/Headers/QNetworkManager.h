//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSIndexSet, NSURLSession;

@interface QNetworkManager : NSObject
{
    NSURLSession *_urlSession;
    NSIndexSet *_acceptableStatusCodes;
}

+ (id)manager;
@property(copy, nonatomic) NSIndexSet *acceptableStatusCodes; // @synthesize acceptableStatusCodes=_acceptableStatusCodes;
@property(retain, nonatomic) NSURLSession *urlSession; // @synthesize urlSession=_urlSession;
- (void).cxx_destruct;
- (void)sendRequest:(id)arg1 suceess:(CDUnknownBlockType)arg2 failure:(CDUnknownBlockType)arg3;
- (void)POSTRequest:(id)arg1 suceess:(CDUnknownBlockType)arg2 failure:(CDUnknownBlockType)arg3;
- (void)GETRequest:(id)arg1 suceess:(CDUnknownBlockType)arg2 failure:(CDUnknownBlockType)arg3;
- (void)GET:(id)arg1 suceess:(CDUnknownBlockType)arg2 failure:(CDUnknownBlockType)arg3;
- (void)dealloc;
- (id)init;

@end
