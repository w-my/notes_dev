//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "JceObjectV2.h"

@class NSArray, stAction;

@interface stAdInfo : JceObjectV2
{
    int jcev2_p_0_o_task_id;
    int jcev2_p_1_o_resource_id;
    int jcev2_p_2_o_pattern_id;
    int jcev2_p_3_o_oper_type;
    unsigned int jcev2_p_6_o_begin_time;
    unsigned int jcev2_p_7_o_end_time;
    NSArray *jcev2_p_4_o_sources__b0x9i_VOstAdSource;
    stAction *jcev2_p_5_o_action;
}

+ (id)jceType;
+ (void)initialize;
@property(nonatomic, getter=jce_end_time, setter=setJce_end_time:) unsigned int jcev2_p_7_o_end_time; // @synthesize jcev2_p_7_o_end_time;
@property(nonatomic, getter=jce_begin_time, setter=setJce_begin_time:) unsigned int jcev2_p_6_o_begin_time; // @synthesize jcev2_p_6_o_begin_time;
@property(retain, nonatomic, getter=jce_action, setter=setJce_action:) stAction *jcev2_p_5_o_action; // @synthesize jcev2_p_5_o_action;
@property(retain, nonatomic, getter=jce_sources, setter=setJce_sources:) NSArray *jcev2_p_4_o_sources__b0x9i_VOstAdSource; // @synthesize jcev2_p_4_o_sources__b0x9i_VOstAdSource;
@property(nonatomic, getter=jce_oper_type, setter=setJce_oper_type:) int jcev2_p_3_o_oper_type; // @synthesize jcev2_p_3_o_oper_type;
@property(nonatomic, getter=jce_pattern_id, setter=setJce_pattern_id:) int jcev2_p_2_o_pattern_id; // @synthesize jcev2_p_2_o_pattern_id;
@property(nonatomic, getter=jce_resource_id, setter=setJce_resource_id:) int jcev2_p_1_o_resource_id; // @synthesize jcev2_p_1_o_resource_id;
@property(nonatomic, getter=jce_task_id, setter=setJce_task_id:) int jcev2_p_0_o_task_id; // @synthesize jcev2_p_0_o_task_id;
- (void).cxx_destruct;
- (id)init;

@end
