//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "JceObjectV2.h"

@class NSArray, NSDictionary, NSString;

@interface stWSGetTalentDataRsp : JceObjectV2
{
    _Bool jcev2_p_1_o_is_finished;
    unsigned int jcev2_p_2_o_total_num;
    NSString *jcev2_p_0_o_attach_info;
    NSDictionary *jcev2_p_3_o_day_tendency__b0x9i_M09ONSStringONSNumber;
    NSDictionary *jcev2_p_4_o_month_tendency__b0x9i_M09ONSStringONSNumber;
    NSDictionary *jcev2_p_5_o_yesterday_video_data__b0x9i_M09ONSStringONSNumber;
    NSArray *jcev2_p_6_o_video_data__b0x9i_VOstWSVideoData;
}

+ (id)jceType;
+ (void)initialize;
@property(retain, nonatomic, getter=jce_video_data, setter=setJce_video_data:) NSArray *jcev2_p_6_o_video_data__b0x9i_VOstWSVideoData; // @synthesize jcev2_p_6_o_video_data__b0x9i_VOstWSVideoData;
@property(retain, nonatomic, getter=jce_yesterday_video_data, setter=setJce_yesterday_video_data:) NSDictionary *jcev2_p_5_o_yesterday_video_data__b0x9i_M09ONSStringONSNumber; // @synthesize jcev2_p_5_o_yesterday_video_data__b0x9i_M09ONSStringONSNumber;
@property(retain, nonatomic, getter=jce_month_tendency, setter=setJce_month_tendency:) NSDictionary *jcev2_p_4_o_month_tendency__b0x9i_M09ONSStringONSNumber; // @synthesize jcev2_p_4_o_month_tendency__b0x9i_M09ONSStringONSNumber;
@property(retain, nonatomic, getter=jce_day_tendency, setter=setJce_day_tendency:) NSDictionary *jcev2_p_3_o_day_tendency__b0x9i_M09ONSStringONSNumber; // @synthesize jcev2_p_3_o_day_tendency__b0x9i_M09ONSStringONSNumber;
@property(nonatomic, getter=jce_total_num, setter=setJce_total_num:) unsigned int jcev2_p_2_o_total_num; // @synthesize jcev2_p_2_o_total_num;
@property(nonatomic, getter=jce_is_finished, setter=setJce_is_finished:) _Bool jcev2_p_1_o_is_finished; // @synthesize jcev2_p_1_o_is_finished;
@property(retain, nonatomic, getter=jce_attach_info, setter=setJce_attach_info:) NSString *jcev2_p_0_o_attach_info; // @synthesize jcev2_p_0_o_attach_info;
- (void).cxx_destruct;
- (id)init;

@end

