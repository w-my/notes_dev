//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "AVAudioPlayer.h"

@class NSString, NSTimer;

@interface MVAudioPlayer : AVAudioPlayer
{
    NSString *_identifer;
    NSTimer *_timerObserver;
    CDStruct_e83c9415 _playRange;
}

+ (id)playerWithFile:(id)arg1;
@property(retain, nonatomic) NSTimer *timerObserver; // @synthesize timerObserver=_timerObserver;
@property(nonatomic) CDStruct_e83c9415 playRange; // @synthesize playRange=_playRange;
@property(retain, nonatomic) NSString *identifer; // @synthesize identifer=_identifer;
- (void).cxx_destruct;
- (void)setRate:(float)arg1;
- (id)initWithContentsOfURL:(id)arg1 error:(id *)arg2;

@end
