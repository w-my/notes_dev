//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QSModel.h"

@class NSString;

@interface QSHotMatchScheduleFootballEvent : QSModel
{
    NSString *_time;
    NSString *_playerId;
    NSString *_teamId;
    NSString *_type;
    NSString *_playerName;
}

@property(copy, nonatomic) NSString *playerName; // @synthesize playerName=_playerName;
@property(copy, nonatomic) NSString *type; // @synthesize type=_type;
@property(copy, nonatomic) NSString *teamId; // @synthesize teamId=_teamId;
@property(copy, nonatomic) NSString *playerId; // @synthesize playerId=_playerId;
@property(copy, nonatomic) NSString *time; // @synthesize time=_time;
- (void).cxx_destruct;

@end
