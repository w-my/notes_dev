//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@interface WAMemoryStatusSnapShot : NSObject
{
    long long _totalPhysicalMemorySizeInBytes;
    long long _roundedTotalPhysicalMemorySizeInBytes;
    long long _footPrintMemorySizeInBytes;
    long long _residentMemorySizeInBytes;
    long long _freeMemorySizeInBytes;
    double _footPrintPercent;
    double _freePercent;
}

@property(nonatomic) double freePercent; // @synthesize freePercent=_freePercent;
@property(nonatomic) double footPrintPercent; // @synthesize footPrintPercent=_footPrintPercent;
@property(nonatomic) long long freeMemorySizeInBytes; // @synthesize freeMemorySizeInBytes=_freeMemorySizeInBytes;
@property(nonatomic) long long residentMemorySizeInBytes; // @synthesize residentMemorySizeInBytes=_residentMemorySizeInBytes;
@property(nonatomic) long long footPrintMemorySizeInBytes; // @synthesize footPrintMemorySizeInBytes=_footPrintMemorySizeInBytes;
@property(nonatomic) long long roundedTotalPhysicalMemorySizeInBytes; // @synthesize roundedTotalPhysicalMemorySizeInBytes=_roundedTotalPhysicalMemorySizeInBytes;
@property(nonatomic) long long totalPhysicalMemorySizeInBytes; // @synthesize totalPhysicalMemorySizeInBytes=_totalPhysicalMemorySizeInBytes;

@end

