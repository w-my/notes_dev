//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "NSCoding.h"
#import "NSCopying.h"

@class NSDictionary, NSURL;

@interface QNNetworkResponse : NSObject <NSCopying, NSCoding>
{
    NSURL *_url;
    long long _statusCode;
    unsigned long long _encoding;
    NSDictionary *_responseHeaders;
    NSObject *_contentObject;
}

@property(retain, nonatomic) NSObject *contentObject; // @synthesize contentObject=_contentObject;
@property(copy, nonatomic) NSDictionary *responseHeaders; // @synthesize responseHeaders=_responseHeaders;
@property(nonatomic) unsigned long long encoding; // @synthesize encoding=_encoding;
@property(nonatomic) long long statusCode; // @synthesize statusCode=_statusCode;
@property(retain, nonatomic) NSURL *url; // @synthesize url=_url;
- (void).cxx_destruct;
- (id)_copyWithAllData;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)initWithURL:(id)arg1 statusCode:(long long)arg2 encoding:(unsigned long long)arg3 headers:(id)arg4 data:(id)arg5;

@end
