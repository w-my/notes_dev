//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "JceObjectV2.h"

@class NSArray, NSString, stFlowerAccount, stMetaPerson;

@interface stGetPersonalPageRsp : JceObjectV2
{
    BOOL jcev2_p_8_o_is_finished;
    int jcev2_p_1_r_feed_num;
    int jcev2_p_2_r_related_feed_num;
    int jcev2_p_3_r_follower_num;
    int jcev2_p_4_r_interester_num;
    int jcev2_p_5_r_friend_num;
    int jcev2_p_6_o_relationship;
    stMetaPerson *jcev2_p_0_r_person;
    NSArray *jcev2_p_7_o_feeds__b0x9i_VOstMetaFeed;
    NSString *jcev2_p_9_o_attach_info;
    stFlowerAccount *jcev2_p_10_o_flowerAccount;
}

+ (id)jceType;
+ (void)initialize;
@property(retain, nonatomic, getter=jce_flowerAccount, setter=setJce_flowerAccount:) stFlowerAccount *jcev2_p_10_o_flowerAccount; // @synthesize jcev2_p_10_o_flowerAccount;
@property(retain, nonatomic, getter=jce_attach_info, setter=setJce_attach_info:) NSString *jcev2_p_9_o_attach_info; // @synthesize jcev2_p_9_o_attach_info;
@property(nonatomic, getter=jce_is_finished, setter=setJce_is_finished:) BOOL jcev2_p_8_o_is_finished; // @synthesize jcev2_p_8_o_is_finished;
@property(retain, nonatomic, getter=jce_feeds, setter=setJce_feeds:) NSArray *jcev2_p_7_o_feeds__b0x9i_VOstMetaFeed; // @synthesize jcev2_p_7_o_feeds__b0x9i_VOstMetaFeed;
@property(nonatomic, getter=jce_relationship, setter=setJce_relationship:) int jcev2_p_6_o_relationship; // @synthesize jcev2_p_6_o_relationship;
@property(nonatomic, getter=jce_friend_num, setter=setJce_friend_num:) int jcev2_p_5_r_friend_num; // @synthesize jcev2_p_5_r_friend_num;
@property(nonatomic, getter=jce_interester_num, setter=setJce_interester_num:) int jcev2_p_4_r_interester_num; // @synthesize jcev2_p_4_r_interester_num;
@property(nonatomic, getter=jce_follower_num, setter=setJce_follower_num:) int jcev2_p_3_r_follower_num; // @synthesize jcev2_p_3_r_follower_num;
@property(nonatomic, getter=jce_related_feed_num, setter=setJce_related_feed_num:) int jcev2_p_2_r_related_feed_num; // @synthesize jcev2_p_2_r_related_feed_num;
@property(nonatomic, getter=jce_feed_num, setter=setJce_feed_num:) int jcev2_p_1_r_feed_num; // @synthesize jcev2_p_1_r_feed_num;
@property(retain, nonatomic, getter=jce_person, setter=setJce_person:) stMetaPerson *jcev2_p_0_r_person; // @synthesize jcev2_p_0_r_person;
- (void).cxx_destruct;
- (id)init;

@end

