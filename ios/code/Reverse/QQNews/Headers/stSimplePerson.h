//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "JceObjectV2.h"

@class NSString;

@interface stSimplePerson : JceObjectV2
{
    NSString *jcev2_p_0_o_id;
    NSString *jcev2_p_1_o_nick;
    NSString *jcev2_p_2_o_avatar;
}

+ (id)jceType;
+ (void)initialize;
@property(retain, nonatomic, getter=jce_avatar, setter=setJce_avatar:) NSString *jcev2_p_2_o_avatar; // @synthesize jcev2_p_2_o_avatar;
@property(retain, nonatomic, getter=jce_nick, setter=setJce_nick:) NSString *jcev2_p_1_o_nick; // @synthesize jcev2_p_1_o_nick;
@property(retain, nonatomic, getter=jce_id, setter=setJce_id:) NSString *jcev2_p_0_o_id; // @synthesize jcev2_p_0_o_id;
- (void).cxx_destruct;
- (id)init;

@end
