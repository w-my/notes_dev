//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "UIView.h"

@class _UILegibilitySettings;

@interface SBLockScreenBatteryChargingView : UIView
{
    _UILegibilitySettings *_legibilitySettings;
}

+ (id)maskImageNameForExternalChargingBattery;
+ (id)maskImageNameForInternalChargingBattery;
+ (id)maskImageNameForChargingBattery;
+ (id)batteryChargingViewWithDoubleBattery;
+ (id)batteryChargingViewWithSingleBattery;
@property(retain, nonatomic) _UILegibilitySettings *legibilitySettings; // @synthesize legibilitySettings=_legibilitySettings;
- (void).cxx_destruct;
- (id)_chargePercentFont;
- (id)_updateChargeString:(id)arg1 oldLabel:(id)arg2;
@property(nonatomic) _Bool batteryVisible;
@property(readonly, nonatomic) double desiredVisibilityDuration;
- (void)setSecondaryChargePercentage:(long long)arg1 isCharging:(_Bool)arg2 deviceName:(id)arg3;
- (void)setPrimaryChargePercentage:(long long)arg1 isCharging:(_Bool)arg2 detailed:(_Bool)arg3;
- (id)initWithFrame:(struct CGRect)arg1;

@end
