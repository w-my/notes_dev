//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "NWAVPlayJitterSinkDelegate.h"

@class NSString, NSTimer;

@interface NWSyncAudioVideo : NSObject <NWAVPlayJitterSinkDelegate>
{
    struct NWIAVPlayJitterSink *JitterSink;
    NSTimer *_timer;
}

@property(retain, nonatomic) NSTimer *timer; // @synthesize timer=_timer;
- (void).cxx_destruct;
- (void)SetJitterSink:(void *)arg1;
- (void)DelJitterSink;
- (void)syncAudioVideo:(id)arg1;
- (void)stopSync;
- (void)startSync;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

