//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class CTTelephonyNetworkInfo, MQQSecureReachability, MQQWiFiInfo;

@interface MQQNetworkInfo : NSObject
{
    MQQSecureReachability *_reachability;
    CTTelephonyNetworkInfo *_telephonyNetworkInfo;
    long long _cachedNetworkType;
    MQQWiFiInfo *_cachedWiFiInfo;
}

+ (void)checkNetworkIfChanged;
+ (long long)currentNetworkType;
+ (id)sharedInfo;
+ (id)formattedBSSID:(id)arg1;
+ (long long)currentWiFiStatus;
+ (id)currentWiFiInfo;
+ (long long)currentCellularNetworkTechnology;
+ (long long)currentRadioAccessTechnology;
+ (_Bool)supportsCurrentRadioAccessTechnology;
@property(retain, nonatomic) MQQWiFiInfo *cachedWiFiInfo; // @synthesize cachedWiFiInfo=_cachedWiFiInfo;
@property(nonatomic) long long cachedNetworkType; // @synthesize cachedNetworkType=_cachedNetworkType;
- (_Bool)wifiInfo:(id)arg1 isEqualToWiFiInfo:(id)arg2;
- (_Bool)networkType:(long long)arg1 isEqualToNetworkType:(long long)arg2;
- (void)checkNetworkIfChanged;
- (void)networkDidChange:(id)arg1;
- (long long)currentNetworkType;
- (id)reachability;
- (void)dealloc;
- (id)init;
- (id)telephonyNetworkInfo;

@end
