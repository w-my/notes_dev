//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSString;

@interface QNJSApiResponseModel : NSObject
{
    long long _errCode;
    NSString *_errStr;
    long long _type;
    NSObject *_responseObj;
}

@property(retain, nonatomic) NSObject *responseObj; // @synthesize responseObj=_responseObj;
@property(nonatomic) long long type; // @synthesize type=_type;
@property(copy, nonatomic) NSString *errStr; // @synthesize errStr=_errStr;
@property(nonatomic) long long errCode; // @synthesize errCode=_errCode;
- (void).cxx_destruct;

@end

