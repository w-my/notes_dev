//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "JceObjectV2.h"

@class NSArray, NSString;

@interface stGetFeedCommentListRsp : JceObjectV2
{
    _Bool jcev2_p_2_r_is_finished;
    int jcev2_p_3_o_total_comment_num;
    NSString *jcev2_p_0_r_attach_info;
    NSArray *jcev2_p_1_r_comments__b0x9i_VOstMetaComment;
    NSString *jcev2_p_4_o_feed_id;
}

+ (id)jceType;
+ (void)initialize;
@property(retain, nonatomic, getter=jce_feed_id, setter=setJce_feed_id:) NSString *jcev2_p_4_o_feed_id; // @synthesize jcev2_p_4_o_feed_id;
@property(nonatomic, getter=jce_total_comment_num, setter=setJce_total_comment_num:) int jcev2_p_3_o_total_comment_num; // @synthesize jcev2_p_3_o_total_comment_num;
@property(nonatomic, getter=jce_is_finished, setter=setJce_is_finished:) _Bool jcev2_p_2_r_is_finished; // @synthesize jcev2_p_2_r_is_finished;
@property(retain, nonatomic, getter=jce_comments, setter=setJce_comments:) NSArray *jcev2_p_1_r_comments__b0x9i_VOstMetaComment; // @synthesize jcev2_p_1_r_comments__b0x9i_VOstMetaComment;
@property(retain, nonatomic, getter=jce_attach_info, setter=setJce_attach_info:) NSString *jcev2_p_0_r_attach_info; // @synthesize jcev2_p_0_r_attach_info;
- (void).cxx_destruct;
- (id)init;

@end
