//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class CTTelephonyNetworkInfo, NSCondition, NSDate, NSMutableArray, NSString;

@interface TVKNetworkChecker : NSObject
{
    CTTelephonyNetworkInfo *_netInfo;
    NSCondition *_mCondition;
    _Bool _speedIsValid;
    _Bool _isCanceled;
    _Bool _forceSimulate3G;
    int _networkState;
    int _preNetworkState;
    int _cellNetType;
    float _checkSpeedPeriod;
    unsigned long long currentWWANBytes;
    NSString *_pingHostName;
    NSMutableArray *_delegatesOfSpeed;
    NSMutableArray *_delegatesOfAvailablitiy;
    NSMutableArray *_delegatesOfReachabilityChanged;
    NSMutableArray *_delegatesOfEnterForeground;
    double _speed;
    double _avgSpeed;
    double _maxSpeed;
    double _lastMesureTime;
    unsigned long long _lastMesureBytes;
    unsigned long long _networkAvailableRetryCounter;
    NSDate *_lastDateOfGetNetworkState;
    NSString *_radioATG;
    unsigned long long _speedMeasureTimes;
    double _totalBps;
    unsigned long long _resetSpeedPeroid;
}

+ (unsigned long long)getCarrierOperators;
+ (int)newNetType;
+ (int)reportNetType;
+ (_Bool)activeWLAN;
+ (_Bool)activeWWAN;
+ (_Bool)networkAvailable;
+ (void)updataOperatorConfigDic;
+ (void)initialize;
+ (id)sharedInstance;
@property(nonatomic) unsigned long long resetSpeedPeroid; // @synthesize resetSpeedPeroid=_resetSpeedPeroid;
@property(nonatomic) float checkSpeedPeriod; // @synthesize checkSpeedPeriod=_checkSpeedPeriod;
@property(nonatomic) double totalBps; // @synthesize totalBps=_totalBps;
@property(nonatomic) unsigned long long speedMeasureTimes; // @synthesize speedMeasureTimes=_speedMeasureTimes;
@property(nonatomic) _Bool forceSimulate3G; // @synthesize forceSimulate3G=_forceSimulate3G;
@property _Bool isCanceled; // @synthesize isCanceled=_isCanceled;
@property(nonatomic) int cellNetType; // @synthesize cellNetType=_cellNetType;
@property(copy, nonatomic) NSString *radioATG; // @synthesize radioATG=_radioATG;
@property(retain) NSDate *lastDateOfGetNetworkState; // @synthesize lastDateOfGetNetworkState=_lastDateOfGetNetworkState;
@property unsigned long long networkAvailableRetryCounter; // @synthesize networkAvailableRetryCounter=_networkAvailableRetryCounter;
@property int preNetworkState; // @synthesize preNetworkState=_preNetworkState;
@property int networkState; // @synthesize networkState=_networkState;
@property unsigned long long lastMesureBytes; // @synthesize lastMesureBytes=_lastMesureBytes;
@property double lastMesureTime; // @synthesize lastMesureTime=_lastMesureTime;
@property double maxSpeed; // @synthesize maxSpeed=_maxSpeed;
@property double avgSpeed; // @synthesize avgSpeed=_avgSpeed;
@property double speed; // @synthesize speed=_speed;
@property _Bool speedIsValid; // @synthesize speedIsValid=_speedIsValid;
@property(retain) NSMutableArray *delegatesOfEnterForeground; // @synthesize delegatesOfEnterForeground=_delegatesOfEnterForeground;
@property(retain) NSMutableArray *delegatesOfReachabilityChanged; // @synthesize delegatesOfReachabilityChanged=_delegatesOfReachabilityChanged;
@property(retain) NSMutableArray *delegatesOfAvailablitiy; // @synthesize delegatesOfAvailablitiy=_delegatesOfAvailablitiy;
@property(retain) NSMutableArray *delegatesOfSpeed; // @synthesize delegatesOfSpeed=_delegatesOfSpeed;
@property(copy) NSString *pingHostName; // @synthesize pingHostName=_pingHostName;
@property unsigned long long currentWWANBytes; // @synthesize currentWWANBytes;
- (void).cxx_destruct;
- (void)appEnterForeground:(id)arg1;
- (void)reachabilityChanged:(id)arg1;
- (void)didUpdate;
- (void)updateOnThread;
- (_Bool)shouldChangeForNetworkRecheck;
- (_Bool)shouldChangeForSpeed;
- (int)getCurrentNetworkState:(_Bool)arg1;
- (void)stopCheckingNetwork:(id)arg1 type:(int)arg2;
- (void)startCheckingNetwork:(id)arg1 type:(int)arg2;
- (void)removeDelegateObject:(id)arg1;
- (void)handleCTRadioAccessTechnologyDidChangeNotification;
- (void)simulate3G:(_Bool)arg1;
- (void)updateRadioATG;
- (void)handleConfigUpdate:(id)arg1;
- (id)init;
- (void)dealloc;

@end

