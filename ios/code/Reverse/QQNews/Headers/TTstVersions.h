//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "JceObjectV2.h"

@class NSDictionary;

@interface TTstVersions : JceObjectV2
{
    int jcev2_p_1_r_bannerVersion;
    int jcev2_p_2_r_opVersion;
    int jcev2_p_3_o_catInfoVersion;
    NSDictionary *jcev2_p_0_r_mainCategoryVersions__b0x9i_M09ONSStringONSNumber;
}

+ (id)jceType;
+ (void)initialize;
@property(nonatomic, getter=jce_catInfoVersion, setter=setJce_catInfoVersion:) int jcev2_p_3_o_catInfoVersion; // @synthesize jcev2_p_3_o_catInfoVersion;
@property(nonatomic, getter=jce_opVersion, setter=setJce_opVersion:) int jcev2_p_2_r_opVersion; // @synthesize jcev2_p_2_r_opVersion;
@property(nonatomic, getter=jce_bannerVersion, setter=setJce_bannerVersion:) int jcev2_p_1_r_bannerVersion; // @synthesize jcev2_p_1_r_bannerVersion;
@property(retain, nonatomic, getter=jce_mainCategoryVersions, setter=setJce_mainCategoryVersions:) NSDictionary *jcev2_p_0_r_mainCategoryVersions__b0x9i_M09ONSStringONSNumber; // @synthesize jcev2_p_0_r_mainCategoryVersions__b0x9i_M09ONSStringONSNumber;
- (void).cxx_destruct;
- (id)init;

@end

