//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "JceObjectV2.h"

@class NSArray, NSDictionary, NSString;

@interface stGetDiscoveryPageDataRsp : JceObjectV2
{
    _Bool jcev2_p_3_o_is_finished;
    NSString *jcev2_p_0_r_attach_info;
    NSArray *jcev2_p_1_r_ops__b0x9i_VOstMetaOpdata;
    NSArray *jcev2_p_2_o_feeds__b0x9i_VOstMetaFeed;
    NSDictionary *jcev2_p_4_o_followinfo__b0x9i_M09ONSStringONSNumber;
    NSArray *jcev2_p_5_o_usersOnChart__b0x9i_VOstMetaPerson;
    NSArray *jcev2_p_6_o_topics__b0x9i_VOstMetaTopic;
}

+ (id)jceType;
+ (void)initialize;
@property(retain, nonatomic, getter=jce_topics, setter=setJce_topics:) NSArray *jcev2_p_6_o_topics__b0x9i_VOstMetaTopic; // @synthesize jcev2_p_6_o_topics__b0x9i_VOstMetaTopic;
@property(retain, nonatomic, getter=jce_usersOnChart, setter=setJce_usersOnChart:) NSArray *jcev2_p_5_o_usersOnChart__b0x9i_VOstMetaPerson; // @synthesize jcev2_p_5_o_usersOnChart__b0x9i_VOstMetaPerson;
@property(retain, nonatomic, getter=jce_followinfo, setter=setJce_followinfo:) NSDictionary *jcev2_p_4_o_followinfo__b0x9i_M09ONSStringONSNumber; // @synthesize jcev2_p_4_o_followinfo__b0x9i_M09ONSStringONSNumber;
@property(nonatomic, getter=jce_is_finished, setter=setJce_is_finished:) _Bool jcev2_p_3_o_is_finished; // @synthesize jcev2_p_3_o_is_finished;
@property(retain, nonatomic, getter=jce_feeds, setter=setJce_feeds:) NSArray *jcev2_p_2_o_feeds__b0x9i_VOstMetaFeed; // @synthesize jcev2_p_2_o_feeds__b0x9i_VOstMetaFeed;
@property(retain, nonatomic, getter=jce_ops, setter=setJce_ops:) NSArray *jcev2_p_1_r_ops__b0x9i_VOstMetaOpdata; // @synthesize jcev2_p_1_r_ops__b0x9i_VOstMetaOpdata;
@property(retain, nonatomic, getter=jce_attach_info, setter=setJce_attach_info:) NSString *jcev2_p_0_r_attach_info; // @synthesize jcev2_p_0_r_attach_info;
- (void).cxx_destruct;
- (id)init;

@end
