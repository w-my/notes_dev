//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSString;

@interface UploadStats : NSObject
{
    long long _inVideoBytes;
    long long _inAudioBytes;
    long long _outVideoBytes;
    long long _outAudioBytes;
    long long _videoCacheLen;
    long long _audioCacheLen;
    long long _videoDropCount;
    long long _audioDropCount;
    long long _startTS;
    long long _dnsTS;
    long long _connTS;
    NSString *_serverIp;
    long long _channelType;
    long long _dnsparseTimeCost;
    long long _connectTimeCost;
    long long _handshakeTimeCost;
    NSString *_connectionID;
    NSString *_connectionStats;
}

@property(retain, nonatomic) NSString *connectionStats; // @synthesize connectionStats=_connectionStats;
@property(retain, nonatomic) NSString *connectionID; // @synthesize connectionID=_connectionID;
@property(nonatomic) long long handshakeTimeCost; // @synthesize handshakeTimeCost=_handshakeTimeCost;
@property(nonatomic) long long connectTimeCost; // @synthesize connectTimeCost=_connectTimeCost;
@property(nonatomic) long long dnsparseTimeCost; // @synthesize dnsparseTimeCost=_dnsparseTimeCost;
@property(nonatomic) long long channelType; // @synthesize channelType=_channelType;
@property(retain, nonatomic) NSString *serverIp; // @synthesize serverIp=_serverIp;
@property(nonatomic) long long connTS; // @synthesize connTS=_connTS;
@property(nonatomic) long long dnsTS; // @synthesize dnsTS=_dnsTS;
@property(nonatomic) long long startTS; // @synthesize startTS=_startTS;
@property(nonatomic) long long audioDropCount; // @synthesize audioDropCount=_audioDropCount;
@property(nonatomic) long long videoDropCount; // @synthesize videoDropCount=_videoDropCount;
@property(nonatomic) long long audioCacheLen; // @synthesize audioCacheLen=_audioCacheLen;
@property(nonatomic) long long videoCacheLen; // @synthesize videoCacheLen=_videoCacheLen;
@property(nonatomic) long long outAudioBytes; // @synthesize outAudioBytes=_outAudioBytes;
@property(nonatomic) long long outVideoBytes; // @synthesize outVideoBytes=_outVideoBytes;
@property(nonatomic) long long inAudioBytes; // @synthesize inAudioBytes=_inAudioBytes;
@property(nonatomic) long long inVideoBytes; // @synthesize inVideoBytes=_inVideoBytes;
- (void).cxx_destruct;

@end

