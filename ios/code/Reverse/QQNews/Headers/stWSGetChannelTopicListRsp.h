//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "JceObjectV2.h"

@class NSArray, NSString;

@interface stWSGetChannelTopicListRsp : JceObjectV2
{
    _Bool jcev2_p_1_o_is_finished;
    NSString *jcev2_p_0_o_attach_info;
    NSArray *jcev2_p_2_o_ranks__b0x9i_VOstRankList;
    NSArray *jcev2_p_3_o_topicList__b0x9i_VOstMetaTopic;
}

+ (id)jceType;
+ (void)initialize;
@property(retain, nonatomic, getter=jce_topicList, setter=setJce_topicList:) NSArray *jcev2_p_3_o_topicList__b0x9i_VOstMetaTopic; // @synthesize jcev2_p_3_o_topicList__b0x9i_VOstMetaTopic;
@property(retain, nonatomic, getter=jce_ranks, setter=setJce_ranks:) NSArray *jcev2_p_2_o_ranks__b0x9i_VOstRankList; // @synthesize jcev2_p_2_o_ranks__b0x9i_VOstRankList;
@property(nonatomic, getter=jce_is_finished, setter=setJce_is_finished:) _Bool jcev2_p_1_o_is_finished; // @synthesize jcev2_p_1_o_is_finished;
@property(retain, nonatomic, getter=jce_attach_info, setter=setJce_attach_info:) NSString *jcev2_p_0_o_attach_info; // @synthesize jcev2_p_0_o_attach_info;
- (void).cxx_destruct;
- (id)init;

@end
