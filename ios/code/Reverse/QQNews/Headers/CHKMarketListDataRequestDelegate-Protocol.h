//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class CMarketData, NSString;

@protocol CHKMarketListDataRequestDelegate <NSObject>
- (void)hkMarketListDataRequestFail:(NSString *)arg1;
- (void)hkMarketListDataRequestSuccess:(CMarketData *)arg1;
@end
