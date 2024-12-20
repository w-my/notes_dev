//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNGenericEvent.h"

@class QNAudioInfoItem;

@interface QNAudioPlayerProcessChangedEvent : QNGenericEvent
{
    QNAudioInfoItem *_audioInfo;
    double _currentTime;
}

+ (void)subscribeWithObserver:(id)arg1 callback:(CDUnknownBlockType)arg2 callbackThread:(long long)arg3;
+ (void)subscribeWithObserver:(id)arg1 callback:(CDUnknownBlockType)arg2;
@property(nonatomic) double currentTime; // @synthesize currentTime=_currentTime;
@property(retain, nonatomic) QNAudioInfoItem *audioInfo; // @synthesize audioInfo=_audioInfo;
- (void).cxx_destruct;

@end

