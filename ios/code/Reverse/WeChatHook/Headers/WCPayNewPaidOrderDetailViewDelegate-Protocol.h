//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"
#import "WCPayPaidOrderShowInfoViewDelegate.h"

@class NSString;

@protocol WCPayNewPaidOrderDetailViewDelegate <WCPayPaidOrderShowInfoViewDelegate, NSObject>
- (void)onNewDetailViewClickMchFav:(_Bool)arg1;
- (void)onNewDetailViewClickLotteryBtn:(id)arg1;
- (void)onNewDetailViewReturnWithoutDrawLottery;
- (void)onNewDetailViewDidFinishLottery;
- (void)onNewDetailViewStartDrawLottery:(unsigned int)arg1;
- (void)onNewDetailViewClickTinyAppActivityWithTinyAppUsername:(NSString *)arg1 tinyAppPath:(NSString *)arg2 tinyAppVersion:(unsigned int)arg3;
- (void)onNewDetailViewClickH5ActivityOpenWithTinyAppUsername:(NSString *)arg1 tinyAppPath:(NSString *)arg2 tinyAppVersion:(unsigned int)arg3;
- (void)onNewDetailViewClickH5Activity:(NSString *)arg1;
- (void)onNewDetailViewClickNativeActicity;
- (void)onNewDetailViewOpenTinyAppWithTinyAppUsername:(NSString *)arg1 tinyAppPath:(NSString *)arg2 tinyAppVersion:(unsigned int)arg3;
- (void)onNewDetailViewDoneBtnClickWithBrandUsername:(NSString *)arg1;
@end

