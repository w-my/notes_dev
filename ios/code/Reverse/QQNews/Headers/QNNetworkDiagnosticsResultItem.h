//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSString, QNNetworkDiagnosticsResult;

@interface QNNetworkDiagnosticsResultItem : NSObject
{
    unsigned long long _httpStatusCode;
    double _time;
    NSString *_ip;
    long long _ipType;
    QNNetworkDiagnosticsResult *_result;
}

@property(nonatomic) __weak QNNetworkDiagnosticsResult *result; // @synthesize result=_result;
@property(nonatomic) long long ipType; // @synthesize ipType=_ipType;
@property(copy, nonatomic) NSString *ip; // @synthesize ip=_ip;
@property(nonatomic) double time; // @synthesize time=_time;
@property(nonatomic) unsigned long long httpStatusCode; // @synthesize httpStatusCode=_httpStatusCode;
- (void).cxx_destruct;
- (id)ipTypeDesc;
- (id)speedTestURLString;

@end
