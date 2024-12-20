//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIDevice.h"

@interface UIDevice (TVKReachability)
+ (_Bool)isInTaiwan;
+ (_Bool)isInHongkong;
+ (_Bool)isInChina;
+ (_Bool)isInUSA;
+ (_Bool)activeWLAN;
+ (_Bool)activeWWAN;
+ (void)pingReachabilityInternal;
+ (id)getIPAddressByHostName:(id)arg1;
+ (_Bool)networkAvailable;
+ (id)localWiFiIPAddress;
- (_Bool)isString:(const char *)arg1 hasPrefix:(const char *)arg2 preLen:(int)arg3;
- (_Bool)getDataCounters:(unsigned long long *)arg1:(unsigned long long *)arg2:(unsigned long long *)arg3:(unsigned long long *)arg4;
- (unsigned long long)getBytesIn;
- (unsigned long long)getBytesOut;
@end

