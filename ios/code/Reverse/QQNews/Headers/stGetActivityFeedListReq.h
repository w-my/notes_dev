//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "JceObjectV2.h"

@class NSString;

@interface stGetActivityFeedListReq : JceObjectV2
{
    BOOL jcev2_p_2_o_is_refresh;
    NSString *jcev2_p_0_r_attach_info;
    NSString *jcev2_p_1_r_topic_id;
    long long jcev2_p_3_o_type;
    long long jcev2_p_4_o_uin;
}

+ (id)jceType;
+ (void)initialize;
@property(nonatomic, getter=jce_uin, setter=setJce_uin:) long long jcev2_p_4_o_uin; // @synthesize jcev2_p_4_o_uin;
@property(nonatomic, getter=jce_type, setter=setJce_type:) long long jcev2_p_3_o_type; // @synthesize jcev2_p_3_o_type;
@property(nonatomic, getter=jce_is_refresh, setter=setJce_is_refresh:) BOOL jcev2_p_2_o_is_refresh; // @synthesize jcev2_p_2_o_is_refresh;
@property(retain, nonatomic, getter=jce_topic_id, setter=setJce_topic_id:) NSString *jcev2_p_1_r_topic_id; // @synthesize jcev2_p_1_r_topic_id;
@property(retain, nonatomic, getter=jce_attach_info, setter=setJce_attach_info:) NSString *jcev2_p_0_r_attach_info; // @synthesize jcev2_p_0_r_attach_info;
- (void).cxx_destruct;
- (id)init;

@end
