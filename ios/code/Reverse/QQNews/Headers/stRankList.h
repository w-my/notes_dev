//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "JceObjectV2.h"

@class NSArray, NSString;

@interface stRankList : JceObjectV2
{
    int jcev2_p_1_o_type;
    int jcev2_p_4_o_rankTime;
    NSString *jcev2_p_0_o_id;
    NSString *jcev2_p_2_o_name;
    NSArray *jcev2_p_3_o_images__b0x9i_VOstMetaUgcImage;
    NSString *jcev2_p_5_o_jumpUrl;
    NSString *jcev2_p_6_o_desc;
}

+ (id)jceType;
+ (void)initialize;
@property(retain, nonatomic, getter=jce_desc, setter=setJce_desc:) NSString *jcev2_p_6_o_desc; // @synthesize jcev2_p_6_o_desc;
@property(retain, nonatomic, getter=jce_jumpUrl, setter=setJce_jumpUrl:) NSString *jcev2_p_5_o_jumpUrl; // @synthesize jcev2_p_5_o_jumpUrl;
@property(nonatomic, getter=jce_rankTime, setter=setJce_rankTime:) int jcev2_p_4_o_rankTime; // @synthesize jcev2_p_4_o_rankTime;
@property(retain, nonatomic, getter=jce_images, setter=setJce_images:) NSArray *jcev2_p_3_o_images__b0x9i_VOstMetaUgcImage; // @synthesize jcev2_p_3_o_images__b0x9i_VOstMetaUgcImage;
@property(retain, nonatomic, getter=jce_name, setter=setJce_name:) NSString *jcev2_p_2_o_name; // @synthesize jcev2_p_2_o_name;
@property(nonatomic, getter=jce_type, setter=setJce_type:) int jcev2_p_1_o_type; // @synthesize jcev2_p_1_o_type;
@property(retain, nonatomic, getter=jce_id, setter=setJce_id:) NSString *jcev2_p_0_o_id; // @synthesize jcev2_p_0_o_id;
- (void).cxx_destruct;
- (id)init;

@end

