//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "JceObjectV2.h"

@class NSString;

@interface stMetaBanner : JceObjectV2
{
    int jcev2_p_0_o_type;
    unsigned int jcev2_p_3_o_start_time;
    unsigned int jcev2_p_4_o_end_time;
    NSString *jcev2_p_1_o_url;
    NSString *jcev2_p_2_o_title;
    NSString *jcev2_p_5_o_cover_url;
    NSString *jcev2_p_6_o_id;
}

+ (id)jceType;
+ (void)initialize;
@property(retain, nonatomic, getter=jce_id, setter=setJce_id:) NSString *jcev2_p_6_o_id; // @synthesize jcev2_p_6_o_id;
@property(retain, nonatomic, getter=jce_cover_url, setter=setJce_cover_url:) NSString *jcev2_p_5_o_cover_url; // @synthesize jcev2_p_5_o_cover_url;
@property(nonatomic, getter=jce_end_time, setter=setJce_end_time:) unsigned int jcev2_p_4_o_end_time; // @synthesize jcev2_p_4_o_end_time;
@property(nonatomic, getter=jce_start_time, setter=setJce_start_time:) unsigned int jcev2_p_3_o_start_time; // @synthesize jcev2_p_3_o_start_time;
@property(retain, nonatomic, getter=jce_title, setter=setJce_title:) NSString *jcev2_p_2_o_title; // @synthesize jcev2_p_2_o_title;
@property(retain, nonatomic, getter=jce_url, setter=setJce_url:) NSString *jcev2_p_1_o_url; // @synthesize jcev2_p_1_o_url;
@property(nonatomic, getter=jce_type, setter=setJce_type:) int jcev2_p_0_o_type; // @synthesize jcev2_p_0_o_type;
- (void).cxx_destruct;
- (id)init;

@end
