//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QSModel.h"

@class NSString;

@interface QSVIPServiceInfo : QSModel
{
    NSString *_serviceId;
    NSString *_serviceType;
    NSString *_serviceName;
    NSString *_serviceAlias;
    NSString *_serviceDesc;
    NSString *_serviceLogo;
    NSString *_serviceIcon;
    double _serviceEndTime;
    long long _serviceStatus;
}

@property(nonatomic) long long serviceStatus; // @synthesize serviceStatus=_serviceStatus;
@property(nonatomic) double serviceEndTime; // @synthesize serviceEndTime=_serviceEndTime;
@property(copy, nonatomic) NSString *serviceIcon; // @synthesize serviceIcon=_serviceIcon;
@property(copy, nonatomic) NSString *serviceLogo; // @synthesize serviceLogo=_serviceLogo;
@property(copy, nonatomic) NSString *serviceDesc; // @synthesize serviceDesc=_serviceDesc;
@property(copy, nonatomic) NSString *serviceAlias; // @synthesize serviceAlias=_serviceAlias;
@property(copy, nonatomic) NSString *serviceName; // @synthesize serviceName=_serviceName;
@property(copy, nonatomic) NSString *serviceType; // @synthesize serviceType=_serviceType;
@property(copy, nonatomic) NSString *serviceId; // @synthesize serviceId=_serviceId;
- (void).cxx_destruct;

@end
