//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSString;

@interface QQVServerInfo : NSObject
{
    NSString *_serverIP;
    unsigned long long _serverPort;
    NSString *_checkkey;
    NSString *_vid;
}

@property(retain, nonatomic) NSString *vid; // @synthesize vid=_vid;
@property(retain, nonatomic) NSString *checkkey; // @synthesize checkkey=_checkkey;
@property(nonatomic) unsigned long long serverPort; // @synthesize serverPort=_serverPort;
@property(retain, nonatomic) NSString *serverIP; // @synthesize serverIP=_serverIP;
- (void).cxx_destruct;
- (id)toDictionary;

@end

