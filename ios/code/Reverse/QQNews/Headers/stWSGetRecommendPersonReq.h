//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "JceObjectV2.h"

@class NSArray, NSDictionary, NSString;

@interface stWSGetRecommendPersonReq : JceObjectV2
{
    int jcev2_p_1_o_type_page;
    NSString *jcev2_p_0_o_attach_info;
    NSArray *jcev2_p_2_o_type_list__b0x9i_VONSNumber;
    NSDictionary *jcev2_p_3_o_type_count__b0x9i_M09ONSNumberONSNumber;
}

+ (id)jceType;
+ (void)initialize;
@property(retain, nonatomic, getter=jce_type_count, setter=setJce_type_count:) NSDictionary *jcev2_p_3_o_type_count__b0x9i_M09ONSNumberONSNumber; // @synthesize jcev2_p_3_o_type_count__b0x9i_M09ONSNumberONSNumber;
@property(retain, nonatomic, getter=jce_type_list, setter=setJce_type_list:) NSArray *jcev2_p_2_o_type_list__b0x9i_VONSNumber; // @synthesize jcev2_p_2_o_type_list__b0x9i_VONSNumber;
@property(nonatomic, getter=jce_type_page, setter=setJce_type_page:) int jcev2_p_1_o_type_page; // @synthesize jcev2_p_1_o_type_page;
@property(retain, nonatomic, getter=jce_attach_info, setter=setJce_attach_info:) NSString *jcev2_p_0_o_attach_info; // @synthesize jcev2_p_0_o_attach_info;
- (void).cxx_destruct;
- (id)init;

@end
