//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@interface PLPLCrashReporterConfig : NSObject
{
    unsigned long long _signalHandlerType;
    unsigned long long _symbolicationStrategy;
}

+ (id)defaultConfiguration;
@property(readonly, nonatomic) unsigned long long symbolicationStrategy; // @synthesize symbolicationStrategy=_symbolicationStrategy;
@property(readonly, nonatomic) unsigned long long signalHandlerType; // @synthesize signalHandlerType=_signalHandlerType;
- (id)initWithSignalHandlerType:(unsigned long long)arg1 symbolicationStrategy:(unsigned long long)arg2;
- (id)init;

@end
