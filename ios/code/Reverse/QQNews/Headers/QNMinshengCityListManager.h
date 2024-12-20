//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSDictionary, NSString, QNMinshengCityListItem;

@interface QNMinshengCityListManager : NSObject
{
    NSString *_cityVersion;
    QNMinshengCityListItem *_cityList;
    NSDictionary *_cityMap;
}

+ (id)getDefaultCityAndDistrict;
+ (id)sharedMinshengCityListInstance;
@property(retain, nonatomic) NSDictionary *cityMap; // @synthesize cityMap=_cityMap;
@property(retain, nonatomic) QNMinshengCityListItem *cityList; // @synthesize cityList=_cityList;
- (void).cxx_destruct;
- (void)p_setCurCityAndDistrictItem:(id)arg1 fromNotification:(_Bool)arg2;
- (_Bool)_parseOriginCityData:(id)arg1;
- (void)_updateCityMap;
- (void)_handleCityChanged:(id)arg1;
- (void)_handleCityDataUpdate:(id)arg1;
- (id)getCityItemWithCityID:(id)arg1;
- (id)getMSHCityByLocation;
- (id)getAppCityItem;
- (void)p_setCurCityAndDistrictItem:(id)arg1;
- (id)getMSHCityList;
- (void)writeMSHCityListToDisk;
- (void)checkMinshengCityListUpdate;
- (_Bool)_checkIfMinshengCityItemIsInCityList:(id)arg1;
- (void)dealloc;
- (id)init;

@end

