//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "JceObjectV2.h"

@class NSDictionary, NSString;

@interface stHippoCommReq : JceObjectV2
{
    int jcev2_p_0_o_testflag;
    NSDictionary *jcev2_p_1_o_mapPushContent__b0x9i_M09ONSNumberOstPushContent;
    NSDictionary *jcev2_p_2_o_mapRevPersonid__b0x9i_M09ONSNumberVONSString;
    NSString *jcev2_p_3_o_postFeedPersonid;
    NSString *jcev2_p_4_o_postFeedid;
    NSString *jcev2_p_5_o_testRevPersonid;
}

+ (id)jceType;
+ (void)initialize;
@property(retain, nonatomic, getter=jce_testRevPersonid, setter=setJce_testRevPersonid:) NSString *jcev2_p_5_o_testRevPersonid; // @synthesize jcev2_p_5_o_testRevPersonid;
@property(retain, nonatomic, getter=jce_postFeedid, setter=setJce_postFeedid:) NSString *jcev2_p_4_o_postFeedid; // @synthesize jcev2_p_4_o_postFeedid;
@property(retain, nonatomic, getter=jce_postFeedPersonid, setter=setJce_postFeedPersonid:) NSString *jcev2_p_3_o_postFeedPersonid; // @synthesize jcev2_p_3_o_postFeedPersonid;
@property(retain, nonatomic, getter=jce_mapRevPersonid, setter=setJce_mapRevPersonid:) NSDictionary *jcev2_p_2_o_mapRevPersonid__b0x9i_M09ONSNumberVONSString; // @synthesize jcev2_p_2_o_mapRevPersonid__b0x9i_M09ONSNumberVONSString;
@property(retain, nonatomic, getter=jce_mapPushContent, setter=setJce_mapPushContent:) NSDictionary *jcev2_p_1_o_mapPushContent__b0x9i_M09ONSNumberOstPushContent; // @synthesize jcev2_p_1_o_mapPushContent__b0x9i_M09ONSNumberOstPushContent;
@property(nonatomic, getter=jce_testflag, setter=setJce_testflag:) int jcev2_p_0_o_testflag; // @synthesize jcev2_p_0_o_testflag;
- (void).cxx_destruct;
- (id)init;

@end
