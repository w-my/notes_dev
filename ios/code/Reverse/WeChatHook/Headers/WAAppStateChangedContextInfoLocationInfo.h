//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMObject.h"

@interface WAAppStateChangedContextInfoLocationInfo : MMObject
{
    _Bool _canKeepAliveByLocating;
    _Bool _isBackgroundLocating;
    _Bool _isLocationSharedResourceBeenRecovered;
}

@property(nonatomic) _Bool isLocationSharedResourceBeenRecovered; // @synthesize isLocationSharedResourceBeenRecovered=_isLocationSharedResourceBeenRecovered;
@property(nonatomic) _Bool isBackgroundLocating; // @synthesize isBackgroundLocating=_isBackgroundLocating;
@property(nonatomic) _Bool canKeepAliveByLocating; // @synthesize canKeepAliveByLocating=_canKeepAliveByLocating;
- (id)description;

@end
