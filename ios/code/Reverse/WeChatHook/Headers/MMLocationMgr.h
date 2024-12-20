//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMService.h"

#import "CLLocationManagerDelegate.h"
#import "MMService.h"
#import "PBMessageObserverDelegate.h"
#import "TencentLBSLocationManagerDelegate.h"

@class AESEncryptObject, CLLocationManager, MMLocationCacheItem, MMLocationCacheStorage, MMLocationDB, MMLocationMgrUseInfoHandle, MMWifiSSIDRetriever, NSMutableArray, NSString, RSAEncryptObject;

@interface MMLocationMgr : MMService <PBMessageObserverDelegate, CLLocationManagerDelegate, TencentLBSLocationManagerDelegate, MMService>
{
    MMLocationDB *m_locationDB;
    CLLocationManager *m_locationMgrForAuthorization;
    MMLocationCacheStorage *_locationCacheStorage;
    struct CGPath *_chinaBorder;
    MMLocationMgrUseInfoHandle *_useInfoHandler;
    NSMutableArray *_reversGeolocators;
    RSAEncryptObject *_m_rsaEncryptObject;
    AESEncryptObject *_m_aesEncryptObject;
    MMLocationCacheItem *_m_realtimeLocationCache;
    MMWifiSSIDRetriever *_m_wifiSSIDRetriever;
}

@property(retain, nonatomic) MMWifiSSIDRetriever *m_wifiSSIDRetriever; // @synthesize m_wifiSSIDRetriever=_m_wifiSSIDRetriever;
@property(retain, nonatomic) MMLocationCacheItem *m_realtimeLocationCache; // @synthesize m_realtimeLocationCache=_m_realtimeLocationCache;
@property(retain, nonatomic) AESEncryptObject *m_aesEncryptObject; // @synthesize m_aesEncryptObject=_m_aesEncryptObject;
@property(retain, nonatomic) RSAEncryptObject *m_rsaEncryptObject; // @synthesize m_rsaEncryptObject=_m_rsaEncryptObject;
@property(retain, nonatomic) NSMutableArray *reversGeolocators; // @synthesize reversGeolocators=_reversGeolocators;
@property(retain, nonatomic) MMLocationMgrUseInfoHandle *useInfoHandler; // @synthesize useInfoHandler=_useInfoHandler;
@property(nonatomic) struct CGPath *chinaBorder; // @synthesize chinaBorder=_chinaBorder;
@property(retain, nonatomic) MMLocationCacheStorage *locationCacheStorage; // @synthesize locationCacheStorage=_locationCacheStorage;
- (void).cxx_destruct;
- (unsigned int)getCurrentWiFiInfoUpdateTimeStamp;
- (id)getCurrentWiFiBSSID;
- (void)updateWifiInfo;
- (id)getAESKeyWithRSAEncrypted;
- (id)getEncryptReportWithLocation:(_Bool)arg1 WithSSID:(_Bool)arg2;
- (id)getEncryptReportInfo:(id)arg1;
- (id)getReportWithLocation:(_Bool)arg1 WithSSID:(_Bool)arg2;
- (void)MessageReturn:(id)arg1 Event:(unsigned int)arg2;
- (void)requestWXGeocodeWithParam:(id)arg1;
- (void)connectionDidFinishLoading:(id)arg1;
- (void)connection:(id)arg1 didReceiveData:(id)arg2;
- (void)connection:(id)arg1 didReceiveResponse:(id)arg2;
- (void)requestReverseGeoWithParam:(id)arg1;
- (_Bool)isCoordinateInChina:(struct CLLocationCoordinate2D)arg1;
- (id)countryCodeFromAddressDic:(id)arg1;
- (id)countryFromAddressDic:(id)arg1;
- (id)routeFromAddressDic:(id)arg1;
- (id)subLocalityFromAddressDic:(id)arg1;
- (id)evolvedCityFromAddressDic:(id)arg1;
- (id)cityFromAddressDic:(id)arg1;
- (id)provinceFromAddressDic:(id)arg1;
- (id)roughAddressFromAddressDic:(id)arg1;
- (id)detailAddressFromAddressDic:(id)arg1;
- (id)shortAddressFromAddressDic:(id)arg1;
- (id)findDictionaryByKey:(id)arg1;
- (void)stopUpdateAddressByTag:(unsigned long long)arg1;
- (void)stopGeoAddress:(id)arg1;
- (unsigned long long)updateAddressByLocation:(struct CLLocationCoordinate2D)arg1;
- (id)getAddressByLocation:(struct CLLocationCoordinate2D)arg1;
- (id)keyForLocation:(struct CLLocationCoordinate2D)arg1;
- (void)locationManager:(id)arg1 rangingBeaconsDidFailForRegion:(id)arg2 withError:(id)arg3;
- (void)locationManager:(id)arg1 didRangeBeacons:(id)arg2 inRegion:(id)arg3;
- (void)locationManager:(id)arg1 didUpdateHeading:(id)arg2;
- (void)locationManager:(id)arg1 didFailWithError:(id)arg2;
- (void)locationManager:(id)arg1 didUpdateToLocation:(id)arg2 fromLocation:(id)arg3;
- (void)onUpdateLocationFromLocationManager:(id)arg1;
- (void)tencentLBSLocationManager:(id)arg1 didUpdateHeading:(id)arg2;
- (void)tencentLBSLocationManager:(id)arg1 didUpdateLocation:(id)arg2;
- (void)tencentLBSLocationManager:(id)arg1 didFailWithError:(id)arg2;
- (void)onUpdateLBSLocationFromLocationManager:(id)arg1;
- (_Bool)p_isAccurateLocation:(id)arg1;
- (double)p_locationAccuracy:(id)arg1;
- (id)getRealtimeLocationCache;
- (id)getLastLocationCache;
- (void)updateLocationCache:(id)arg1 isMarsLocation:(_Bool)arg2;
- (void)saveLocationCacheStorage;
- (void)loadLocationCacheStorage;
- (id)getLocationCacheStorage;
- (void)manualStopRangingBeaconsInRegion:(unsigned long long)arg1 withUUIDArray:(id)arg2;
- (void)manualStartRangingBeaconsInRegion:(unsigned long long)arg1 withUUIDArray:(id)arg2;
- (void)manualStopUpdateLocationWithTag:(unsigned long long)arg1;
- (void)manualStartUpdateLocationWithTag:(unsigned long long)arg1;
- (id)getCLLocationManagerByTag:(unsigned long long)arg1;
- (void)manualDeallocLocationWithTag:(unsigned long long)arg1;
- (unsigned long long)manualInitLocation;
- (_Bool)isUpdatingLBSHeading:(unsigned long long)arg1;
- (void)stopUpdateLBSHeading:(unsigned long long)arg1;
- (unsigned long long)startUpdateLBSHeading:(id)arg1 enableIndoor:(_Bool)arg2;
- (_Bool)isUpdatingHeading:(unsigned long long)arg1;
- (void)stopUpdateHeading:(unsigned long long)arg1;
- (unsigned long long)startUpdateHeading;
- (_Bool)isUpdatingGPSLBSLocation:(unsigned long long)arg1;
- (void)stopUpdateGPSLBSLocation:(unsigned long long)arg1;
- (unsigned long long)startUpdateGPSOneLBSLocation:(unsigned long long)arg1 subKey:(id)arg2 enableIndoor:(_Bool)arg3 locationTimeout:(double)arg4;
- (unsigned long long)startUpdateGPSLBSLocation:(_Bool)arg1 backgroundForce:(_Bool)arg2 detailLevel:(unsigned long long)arg3 coordType:(unsigned long long)arg4 subKey:(id)arg5 enableIndoor:(_Bool)arg6;
- (_Bool)isUpdatingGPSLocation:(unsigned long long)arg1;
- (void)stopUpdateGPSLocation:(unsigned long long)arg1;
- (unsigned long long)startUpdateGPSLocation:(_Bool)arg1;
- (void)requestForAuthorization;
- (void)dealloc;
- (id)init;
- (void)onServiceClearData;
- (void)onServiceReloadData;
- (void)onServiceInit;
- (id)getExtraInfoFromAddressDic:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

