//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "JceObjectV2.h"

@class NSString;

@interface TTstBanner : JceObjectV2
{
    int jcev2_p_3_r_mode;
    long long jcev2_p_0_r_id;
    NSString *jcev2_p_1_r_picUrl;
    long long jcev2_p_2_r_timeFinish;
    NSString *jcev2_p_4_r_url;
    NSString *jcev2_p_5_o_language;
}

+ (id)jceType;
+ (void)initialize;
@property(retain, nonatomic, getter=jce_language, setter=setJce_language:) NSString *jcev2_p_5_o_language; // @synthesize jcev2_p_5_o_language;
@property(retain, nonatomic, getter=jce_url, setter=setJce_url:) NSString *jcev2_p_4_r_url; // @synthesize jcev2_p_4_r_url;
@property(nonatomic, getter=jce_mode, setter=setJce_mode:) int jcev2_p_3_r_mode; // @synthesize jcev2_p_3_r_mode;
@property(nonatomic, getter=jce_timeFinish, setter=setJce_timeFinish:) long long jcev2_p_2_r_timeFinish; // @synthesize jcev2_p_2_r_timeFinish;
@property(retain, nonatomic, getter=jce_picUrl, setter=setJce_picUrl:) NSString *jcev2_p_1_r_picUrl; // @synthesize jcev2_p_1_r_picUrl;
@property(nonatomic, getter=jce_id, setter=setJce_id:) long long jcev2_p_0_r_id; // @synthesize jcev2_p_0_r_id;
- (void).cxx_destruct;
- (id)init;

@end
