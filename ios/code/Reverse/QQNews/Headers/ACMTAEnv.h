//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSString, NSUUID;

@interface ACMTAEnv : NSObject
{
    NSString *_deviceid;
    NSString *_app_version;
    NSString *_sdk_version;
    NSUUID *_ifv;
}

@property(retain, nonatomic) NSUUID *ifv; // @synthesize ifv=_ifv;
@property(retain, nonatomic) NSString *sdk_version; // @synthesize sdk_version=_sdk_version;
@property(retain, nonatomic) NSString *app_version; // @synthesize app_version=_app_version;
@property(retain, nonatomic) NSString *deviceid; // @synthesize deviceid=_deviceid;
- (void).cxx_destruct;

@end

