//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNNetworkJSONDictionaryApi.h"

@class NSMutableDictionary;

@interface QNWeatherInfoManager : QNNetworkJSONDictionaryApi
{
    NSMutableDictionary *_weatherDic;
    NSMutableDictionary *_weatherLoader;
    double _timeOutSpan;
}

+ (id)sharedInstance;
@property(nonatomic) double timeOutSpan; // @synthesize timeOutSpan=_timeOutSpan;
@property(retain, nonatomic) NSMutableDictionary *weatherLoader; // @synthesize weatherLoader=_weatherLoader;
@property(retain, nonatomic) NSMutableDictionary *weatherDic; // @synthesize weatherDic=_weatherDic;
- (void).cxx_destruct;
- (id)weatherInfoByLocalChannel:(id)arg1;
- (void)loadWeatherWithLocalChannel:(id)arg1 adcode:(long long)arg2 block:(CDUnknownBlockType)arg3;

@end

