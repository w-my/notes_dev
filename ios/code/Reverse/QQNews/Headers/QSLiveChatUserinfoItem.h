//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QSModel.h"

@class NSString;

@interface QSLiveChatUserinfoItem : QSModel
{
    _Bool _own;
    NSString *_userid;
    NSString *_userIdx;
    NSString *_uidex;
    NSString *_nick;
    NSString *_head;
    NSString *_region;
    long long _gender;
    long long _vipType;
}

@property(nonatomic) long long vipType; // @synthesize vipType=_vipType;
@property(nonatomic) _Bool own; // @synthesize own=_own;
@property(nonatomic) long long gender; // @synthesize gender=_gender;
@property(retain, nonatomic) NSString *region; // @synthesize region=_region;
@property(retain, nonatomic) NSString *head; // @synthesize head=_head;
@property(retain, nonatomic) NSString *nick; // @synthesize nick=_nick;
@property(retain, nonatomic) NSString *uidex; // @synthesize uidex=_uidex;
@property(retain, nonatomic) NSString *userIdx; // @synthesize userIdx=_userIdx;
@property(retain, nonatomic) NSString *userid; // @synthesize userid=_userid;
- (void).cxx_destruct;
- (_Bool)isVip;

@end
