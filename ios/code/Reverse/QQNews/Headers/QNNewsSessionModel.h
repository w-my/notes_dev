//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNBaseModelObject.h"

@class NSString;

@interface QNNewsSessionModel : QNBaseModelObject
{
    NSString *_sessionId;
    unsigned long long _renewType;
    double _startTime;
    double _lastEnterBackgroundTime;
    double _lastEnterForegroundTime;
}

+ (id)modelWithRenewType:(unsigned long long)arg1;
@property(nonatomic) double lastEnterForegroundTime; // @synthesize lastEnterForegroundTime=_lastEnterForegroundTime;
@property(nonatomic) double lastEnterBackgroundTime; // @synthesize lastEnterBackgroundTime=_lastEnterBackgroundTime;
@property(nonatomic) double startTime; // @synthesize startTime=_startTime;
@property(nonatomic) unsigned long long renewType; // @synthesize renewType=_renewType;
@property(copy, nonatomic) NSString *sessionId; // @synthesize sessionId=_sessionId;
- (void).cxx_destruct;
- (id)copyInstance;
- (id)copyWithZone:(struct _NSZone *)arg1;

@end

