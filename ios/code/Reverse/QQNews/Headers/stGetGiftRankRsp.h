//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "JceObjectV2.h"

@class NSArray, NSString, stMetaPerson;

@interface stGetGiftRankRsp : JceObjectV2
{
    _Bool jcev2_p_5_o_is_finished;
    int jcev2_p_1_o_wealth;
    int jcev2_p_2_o_rank;
    NSString *jcev2_p_0_r_attach_info;
    stMetaPerson *jcev2_p_3_o_personDetail;
    NSArray *jcev2_p_4_o_personList__b0x9i_VOstMetaPerson;
}

+ (id)jceType;
+ (void)initialize;
@property(nonatomic, getter=jce_is_finished, setter=setJce_is_finished:) _Bool jcev2_p_5_o_is_finished; // @synthesize jcev2_p_5_o_is_finished;
@property(retain, nonatomic, getter=jce_personList, setter=setJce_personList:) NSArray *jcev2_p_4_o_personList__b0x9i_VOstMetaPerson; // @synthesize jcev2_p_4_o_personList__b0x9i_VOstMetaPerson;
@property(retain, nonatomic, getter=jce_personDetail, setter=setJce_personDetail:) stMetaPerson *jcev2_p_3_o_personDetail; // @synthesize jcev2_p_3_o_personDetail;
@property(nonatomic, getter=jce_rank, setter=setJce_rank:) int jcev2_p_2_o_rank; // @synthesize jcev2_p_2_o_rank;
@property(nonatomic, getter=jce_wealth, setter=setJce_wealth:) int jcev2_p_1_o_wealth; // @synthesize jcev2_p_1_o_wealth;
@property(retain, nonatomic, getter=jce_attach_info, setter=setJce_attach_info:) NSString *jcev2_p_0_r_attach_info; // @synthesize jcev2_p_0_r_attach_info;
- (void).cxx_destruct;
- (id)init;

@end

