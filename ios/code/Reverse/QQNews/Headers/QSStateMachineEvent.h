//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@interface QSStateMachineEvent : NSObject
{
    long long _name;
    unsigned long long _from;
    unsigned long long _to;
}

+ (id)eventWithName:(long long)arg1 fromState:(unsigned long long)arg2 andTargetState:(unsigned long long)arg3;
@property(nonatomic) unsigned long long to; // @synthesize to=_to;
@property(nonatomic) unsigned long long from; // @synthesize from=_from;
@property(nonatomic) long long name; // @synthesize name=_name;

@end
