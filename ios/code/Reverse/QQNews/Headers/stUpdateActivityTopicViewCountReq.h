//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "JceObjectV2.h"

@class NSString;

@interface stUpdateActivityTopicViewCountReq : JceObjectV2
{
    unsigned int jcev2_p_1_o_increment;
    NSString *jcev2_p_0_r_topic_id;
}

+ (id)jceType;
+ (void)initialize;
@property(nonatomic, getter=jce_increment, setter=setJce_increment:) unsigned int jcev2_p_1_o_increment; // @synthesize jcev2_p_1_o_increment;
@property(retain, nonatomic, getter=jce_topic_id, setter=setJce_topic_id:) NSString *jcev2_p_0_r_topic_id; // @synthesize jcev2_p_0_r_topic_id;
- (void).cxx_destruct;
- (id)init;

@end
