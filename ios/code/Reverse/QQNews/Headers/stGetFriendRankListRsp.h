//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "JceObjectV2.h"

@class NSArray, NSString;

@interface stGetFriendRankListRsp : JceObjectV2
{
    NSString *jcev2_p_0_r_attach_info;
    NSArray *jcev2_p_1_r_rank_list__b0x9i_VOstMetaFriendRankItem;
}

+ (id)jceType;
+ (void)initialize;
@property(retain, nonatomic, getter=jce_rank_list, setter=setJce_rank_list:) NSArray *jcev2_p_1_r_rank_list__b0x9i_VOstMetaFriendRankItem; // @synthesize jcev2_p_1_r_rank_list__b0x9i_VOstMetaFriendRankItem;
@property(retain, nonatomic, getter=jce_attach_info, setter=setJce_attach_info:) NSString *jcev2_p_0_r_attach_info; // @synthesize jcev2_p_0_r_attach_info;
- (void).cxx_destruct;
- (id)init;

@end
