//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class MMITransmitKvData, MMVoidITransmitKvDataCallback, NSString;

@protocol MMKWCPayService <NSObject>
- (_Bool)isWCPayRegUser;
- (_Bool)isNeedWalletLock;
- (void)getBannerInfoImpl:(int)arg1 callback:(MMVoidITransmitKvDataCallback *)arg2;
- (void)startUseCaseImpl:(NSString *)arg1 data:(MMITransmitKvData *)arg2 quitCallback:(MMVoidITransmitKvDataCallback *)arg3;
@end

