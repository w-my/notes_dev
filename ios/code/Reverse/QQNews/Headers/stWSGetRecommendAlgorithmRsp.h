//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "JceObjectV2.h"

@class NSArray, NSString;

@interface stWSGetRecommendAlgorithmRsp : JceObjectV2
{
    int jcev2_p_0_o_ret;
    NSString *jcev2_p_1_o_errmsg;
    NSArray *jcev2_p_2_o_vec_stRecommendAlgorithm__b0x9i_VOstRecommendAlgorithm;
}

+ (id)jceType;
+ (void)initialize;
@property(retain, nonatomic, getter=jce_vec_stRecommendAlgorithm, setter=setJce_vec_stRecommendAlgorithm:) NSArray *jcev2_p_2_o_vec_stRecommendAlgorithm__b0x9i_VOstRecommendAlgorithm; // @synthesize jcev2_p_2_o_vec_stRecommendAlgorithm__b0x9i_VOstRecommendAlgorithm;
@property(retain, nonatomic, getter=jce_errmsg, setter=setJce_errmsg:) NSString *jcev2_p_1_o_errmsg; // @synthesize jcev2_p_1_o_errmsg;
@property(nonatomic, getter=jce_ret, setter=setJce_ret:) int jcev2_p_0_o_ret; // @synthesize jcev2_p_0_o_ret;
- (void).cxx_destruct;
- (id)init;

@end
