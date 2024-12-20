//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MTAEvent.h"

#import "MTAEventProtocol.h"

@class NSArray, NSDictionary, NSString;

@interface MTACustomEvent : MTAEvent <MTAEventProtocol>
{
    unsigned int _duration;
    NSString *_eventID;
    NSArray *_args;
    NSDictionary *_kvs;
}

@property unsigned int duration; // @synthesize duration=_duration;
@property(copy, nonatomic) NSDictionary *kvs; // @synthesize kvs=_kvs;
@property(copy, nonatomic) NSArray *args; // @synthesize args=_args;
@property(copy, nonatomic) NSString *eventID; // @synthesize eventID=_eventID;
- (void).cxx_destruct;
- (id)init;
- (void)encode:(id)arg1;
- (int)getType;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

