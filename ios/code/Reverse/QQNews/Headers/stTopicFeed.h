//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "JceObjectV2.h"

@class NSString;

@interface stTopicFeed : JceObjectV2
{
    int jcev2_p_1_o_location;
    unsigned int jcev2_p_2_o_start_time;
    unsigned int jcev2_p_3_o_end_time;
    int jcev2_p_4_o_title_flag;
    int jcev2_p_6_o_mini_ver;
    NSString *jcev2_p_0_o_topicId;
    NSString *jcev2_p_5_o_pic_url;
}

+ (id)jceType;
+ (void)initialize;
@property(nonatomic, getter=jce_mini_ver, setter=setJce_mini_ver:) int jcev2_p_6_o_mini_ver; // @synthesize jcev2_p_6_o_mini_ver;
@property(retain, nonatomic, getter=jce_pic_url, setter=setJce_pic_url:) NSString *jcev2_p_5_o_pic_url; // @synthesize jcev2_p_5_o_pic_url;
@property(nonatomic, getter=jce_title_flag, setter=setJce_title_flag:) int jcev2_p_4_o_title_flag; // @synthesize jcev2_p_4_o_title_flag;
@property(nonatomic, getter=jce_end_time, setter=setJce_end_time:) unsigned int jcev2_p_3_o_end_time; // @synthesize jcev2_p_3_o_end_time;
@property(nonatomic, getter=jce_start_time, setter=setJce_start_time:) unsigned int jcev2_p_2_o_start_time; // @synthesize jcev2_p_2_o_start_time;
@property(nonatomic, getter=jce_location, setter=setJce_location:) int jcev2_p_1_o_location; // @synthesize jcev2_p_1_o_location;
@property(retain, nonatomic, getter=jce_topicId, setter=setJce_topicId:) NSString *jcev2_p_0_o_topicId; // @synthesize jcev2_p_0_o_topicId;
- (void).cxx_destruct;
- (id)init;

@end
