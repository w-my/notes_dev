//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSDictionary, NSString;

@interface TXLivePlayConfig : NSObject
{
    _Bool _bAutoAdjustCacheTime;
    _Bool _enableAEC;
    _Bool _enableMessage;
    _Bool _enableNearestIP;
    float _cacheTime;
    float _maxAutoAdjustCacheTime;
    float _minAutoAdjustCacheTime;
    int _videoBlockThreshold;
    int _connectRetryCount;
    int _connectRetryInterval;
    unsigned int _playerPixelFormatType;
    int _rtmpChannelType;
    int _maxCacheItems;
    NSString *_cacheFolderPath;
    NSDictionary *_headers;
}

@property(retain) NSDictionary *headers; // @synthesize headers=_headers;
@property int maxCacheItems; // @synthesize maxCacheItems=_maxCacheItems;
@property(retain) NSString *cacheFolderPath; // @synthesize cacheFolderPath=_cacheFolderPath;
@property(nonatomic) int rtmpChannelType; // @synthesize rtmpChannelType=_rtmpChannelType;
@property(nonatomic) _Bool enableNearestIP; // @synthesize enableNearestIP=_enableNearestIP;
@property(nonatomic) unsigned int playerPixelFormatType; // @synthesize playerPixelFormatType=_playerPixelFormatType;
@property(nonatomic) _Bool enableMessage; // @synthesize enableMessage=_enableMessage;
@property(nonatomic) _Bool enableAEC; // @synthesize enableAEC=_enableAEC;
@property(nonatomic) int connectRetryInterval; // @synthesize connectRetryInterval=_connectRetryInterval;
@property(nonatomic) int connectRetryCount; // @synthesize connectRetryCount=_connectRetryCount;
@property(nonatomic) int videoBlockThreshold; // @synthesize videoBlockThreshold=_videoBlockThreshold;
@property(nonatomic) float minAutoAdjustCacheTime; // @synthesize minAutoAdjustCacheTime=_minAutoAdjustCacheTime;
@property(nonatomic) float maxAutoAdjustCacheTime; // @synthesize maxAutoAdjustCacheTime=_maxAutoAdjustCacheTime;
@property(nonatomic) _Bool bAutoAdjustCacheTime; // @synthesize bAutoAdjustCacheTime=_bAutoAdjustCacheTime;
@property(nonatomic) float cacheTime; // @synthesize cacheTime=_cacheTime;
- (void).cxx_destruct;
- (id)init;

@end

