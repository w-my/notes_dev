//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "JceObjectV2.h"

@class NSArray, NSString;

@interface stWSNetFashionDarenItem : JceObjectV2
{
    int jcev2_p_2_o_total_flower;
    int jcev2_p_3_o_incremental;
    int jcev2_p_4_o_last_receive_time;
    NSString *jcev2_p_0_o_feedid;
    NSString *jcev2_p_1_o_personid;
    NSArray *jcev2_p_5_o_history__b0x9i_VOstWSNetFashionFlowerHistory;
}

+ (id)jceType;
+ (void)initialize;
@property(retain, nonatomic, getter=jce_history, setter=setJce_history:) NSArray *jcev2_p_5_o_history__b0x9i_VOstWSNetFashionFlowerHistory; // @synthesize jcev2_p_5_o_history__b0x9i_VOstWSNetFashionFlowerHistory;
@property(nonatomic, getter=jce_last_receive_time, setter=setJce_last_receive_time:) int jcev2_p_4_o_last_receive_time; // @synthesize jcev2_p_4_o_last_receive_time;
@property(nonatomic, getter=jce_incremental, setter=setJce_incremental:) int jcev2_p_3_o_incremental; // @synthesize jcev2_p_3_o_incremental;
@property(nonatomic, getter=jce_total_flower, setter=setJce_total_flower:) int jcev2_p_2_o_total_flower; // @synthesize jcev2_p_2_o_total_flower;
@property(retain, nonatomic, getter=jce_personid, setter=setJce_personid:) NSString *jcev2_p_1_o_personid; // @synthesize jcev2_p_1_o_personid;
@property(retain, nonatomic, getter=jce_feedid, setter=setJce_feedid:) NSString *jcev2_p_0_o_feedid; // @synthesize jcev2_p_0_o_feedid;
- (void).cxx_destruct;
- (id)init;

@end

