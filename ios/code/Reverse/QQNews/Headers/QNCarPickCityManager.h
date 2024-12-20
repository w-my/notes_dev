//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class CCarCityList, NSDictionary, NSString;

@interface QNCarPickCityManager : NSObject
{
    CCarCityList *_cityListInfo;
    NSString *_cityListVersion;
    NSDictionary *_cityMap;
}

+ (id)sharedInstance;
@property(retain, nonatomic) NSDictionary *cityMap; // @synthesize cityMap=_cityMap;
@property(copy, nonatomic) NSString *cityListVersion; // @synthesize cityListVersion=_cityListVersion;
@property(retain, nonatomic) CCarCityList *cityListInfo; // @synthesize cityListInfo=_cityListInfo;
- (void).cxx_destruct;
- (void)_writeCarCityListToDisk;
- (_Bool)_parseOriginCityData:(id)arg1;
- (id)_getEffectiveCarCityListX;
- (void)_setCarCurCityItem:(id)arg1 fromNotification:(_Bool)arg2;
- (void)_updateCityMap;
- (id)getCarCityItemByCityID:(id)arg1;
- (void)_handleCityChanged:(id)arg1;
- (void)_handleCityDataUpdate:(id)arg1;
- (void)checkCarCityListUpdate;
- (void)setCarCurCityItem:(id)arg1;
- (id)getCarCurCityItem;
- (id)getCarDiscountCityList;
- (id)getCarCityByLocationData;
- (id)getCarDefaultCity;
- (void)dealloc;
- (id)init;

@end

