//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "JceObjectV2.h"

@interface stChainAuthStatus : JceObjectV2
{
    int jcev2_p_0_o_auth_type;
    int jcev2_p_1_o_auth_status;
    int jcev2_p_2_o_action_ret;
}

+ (id)jceType;
+ (void)initialize;
@property(nonatomic, getter=jce_action_ret, setter=setJce_action_ret:) int jcev2_p_2_o_action_ret; // @synthesize jcev2_p_2_o_action_ret;
@property(nonatomic, getter=jce_auth_status, setter=setJce_auth_status:) int jcev2_p_1_o_auth_status; // @synthesize jcev2_p_1_o_auth_status;
@property(nonatomic, getter=jce_auth_type, setter=setJce_auth_type:) int jcev2_p_0_o_auth_type; // @synthesize jcev2_p_0_o_auth_type;
- (id)init;

@end

