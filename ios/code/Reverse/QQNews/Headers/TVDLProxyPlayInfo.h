//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSString;

@interface TVDLProxyPlayInfo : NSObject
{
    _Bool _playSwitchP2P;
    int _playUrlindex;
    NSString *_playCDNUrl;
    NSString *_playUrlVt;
    NSString *_playCdnClientIp;
    NSString *_playCdnServerIp;
}

@property(nonatomic) _Bool playSwitchP2P; // @synthesize playSwitchP2P=_playSwitchP2P;
@property(nonatomic) int playUrlindex; // @synthesize playUrlindex=_playUrlindex;
@property(copy, nonatomic) NSString *playCdnServerIp; // @synthesize playCdnServerIp=_playCdnServerIp;
@property(copy, nonatomic) NSString *playCdnClientIp; // @synthesize playCdnClientIp=_playCdnClientIp;
@property(copy, nonatomic) NSString *playUrlVt; // @synthesize playUrlVt=_playUrlVt;
@property(copy, nonatomic) NSString *playCDNUrl; // @synthesize playCDNUrl=_playCDNUrl;
- (void).cxx_destruct;

@end

