//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "JceObjectV2.h"

@class stMetaPerson;

@interface stSearchUsersRspBody : JceObjectV2
{
    int jcev2_p_1_o_fans_num;
    stMetaPerson *jcev2_p_0_o_user;
}

+ (id)jceType;
+ (void)initialize;
@property(nonatomic, getter=jce_fans_num, setter=setJce_fans_num:) int jcev2_p_1_o_fans_num; // @synthesize jcev2_p_1_o_fans_num;
@property(retain, nonatomic, getter=jce_user, setter=setJce_user:) stMetaPerson *jcev2_p_0_o_user; // @synthesize jcev2_p_0_o_user;
- (void).cxx_destruct;
- (id)init;

@end

