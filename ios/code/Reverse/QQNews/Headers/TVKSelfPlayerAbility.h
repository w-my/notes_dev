//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSMutableDictionary;

@interface TVKSelfPlayerAbility : NSObject
{
    NSMutableDictionary *_defDict;
}

+ (id)sharedInstance;
- (void).cxx_destruct;
- (int)getWidthFromDefinition:(long long)arg1;
- (_Bool)supportVideoDecodeWithCodec:(long long)arg1 decodeMode:(long long)arg2 definition:(long long)arg3;
- (_Bool)supportVideoDecodeWithCodec:(long long)arg1 decodeMode:(long long)arg2 width:(int)arg3 height:(int)arg4;
- (id)init;

@end
