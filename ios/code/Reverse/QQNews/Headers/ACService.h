//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSString;

@interface ACService : NSObject
{
    NSString *_publicKey;
    NSString *_privateKey;
    NSString *_host;
    id <ACServiceProtocol> _child;
}

@property(nonatomic) __weak id <ACServiceProtocol> child; // @synthesize child=_child;
@property(readonly, nonatomic) NSString *host; // @synthesize host=_host;
@property(readonly, nonatomic) NSString *privateKey; // @synthesize privateKey=_privateKey;
@property(readonly, nonatomic) NSString *publicKey; // @synthesize publicKey=_publicKey;
- (void).cxx_destruct;
@property(readonly, nonatomic) NSString *apiVersion;
@property(readonly, nonatomic) NSString *apiBaseUrl;
- (id)init;

@end

