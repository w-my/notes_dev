//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "JceObjectV2.h"

@class NSString, stMetaComment;

@interface stDeleteFeedCommentReq : JceObjectV2
{
    NSString *jcev2_p_0_r_feed_id;
    stMetaComment *jcev2_p_1_r_comment;
}

+ (id)jceType;
+ (void)initialize;
@property(retain, nonatomic, getter=jce_comment, setter=setJce_comment:) stMetaComment *jcev2_p_1_r_comment; // @synthesize jcev2_p_1_r_comment;
@property(retain, nonatomic, getter=jce_feed_id, setter=setJce_feed_id:) NSString *jcev2_p_0_r_feed_id; // @synthesize jcev2_p_0_r_feed_id;
- (void).cxx_destruct;
- (id)init;

@end

