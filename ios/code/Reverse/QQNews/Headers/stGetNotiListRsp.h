//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "JceObjectV2.h"

@class NSArray, NSDictionary, NSString, stMetaUndealCount, stShareInfo;

@interface stGetNotiListRsp : JceObjectV2
{
    _Bool jcev2_p_1_o_is_finished;
    int jcev2_p_3_o_total;
    NSString *jcev2_p_0_o_attach_info;
    NSArray *jcev2_p_2_o_vecNoti__b0x9i_VOstMetaNoti;
    stMetaUndealCount *jcev2_p_4_o_friLoginCount;
    stShareInfo *jcev2_p_5_o_shareInfo;
    NSDictionary *jcev2_p_6_o_mapCount__b0x9i_M09ONSNumberOstMetaUndealCount;
}

+ (id)jceType;
+ (void)initialize;
@property(retain, nonatomic, getter=jce_mapCount, setter=setJce_mapCount:) NSDictionary *jcev2_p_6_o_mapCount__b0x9i_M09ONSNumberOstMetaUndealCount; // @synthesize jcev2_p_6_o_mapCount__b0x9i_M09ONSNumberOstMetaUndealCount;
@property(retain, nonatomic, getter=jce_shareInfo, setter=setJce_shareInfo:) stShareInfo *jcev2_p_5_o_shareInfo; // @synthesize jcev2_p_5_o_shareInfo;
@property(retain, nonatomic, getter=jce_friLoginCount, setter=setJce_friLoginCount:) stMetaUndealCount *jcev2_p_4_o_friLoginCount; // @synthesize jcev2_p_4_o_friLoginCount;
@property(nonatomic, getter=jce_total, setter=setJce_total:) int jcev2_p_3_o_total; // @synthesize jcev2_p_3_o_total;
@property(retain, nonatomic, getter=jce_vecNoti, setter=setJce_vecNoti:) NSArray *jcev2_p_2_o_vecNoti__b0x9i_VOstMetaNoti; // @synthesize jcev2_p_2_o_vecNoti__b0x9i_VOstMetaNoti;
@property(nonatomic, getter=jce_is_finished, setter=setJce_is_finished:) _Bool jcev2_p_1_o_is_finished; // @synthesize jcev2_p_1_o_is_finished;
@property(retain, nonatomic, getter=jce_attach_info, setter=setJce_attach_info:) NSString *jcev2_p_0_o_attach_info; // @synthesize jcev2_p_0_o_attach_info;
- (void).cxx_destruct;
- (id)init;

@end
