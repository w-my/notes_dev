//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "JceObjectV2.h"

@class NSDictionary, NSString;

@interface stUpdateVKeyRsp : JceObjectV2
{
    NSString *jcev2_p_0_o_vkey;
    NSString *jcev2_p_1_o_guid;
    NSDictionary *jcev2_p_2_o_video_spec_urls__b0x9i_M09ONSNumberOVideoSpecUrl;
}

+ (id)jceType;
+ (void)initialize;
@property(retain, nonatomic, getter=jce_video_spec_urls, setter=setJce_video_spec_urls:) NSDictionary *jcev2_p_2_o_video_spec_urls__b0x9i_M09ONSNumberOVideoSpecUrl; // @synthesize jcev2_p_2_o_video_spec_urls__b0x9i_M09ONSNumberOVideoSpecUrl;
@property(retain, nonatomic, getter=jce_guid, setter=setJce_guid:) NSString *jcev2_p_1_o_guid; // @synthesize jcev2_p_1_o_guid;
@property(retain, nonatomic, getter=jce_vkey, setter=setJce_vkey:) NSString *jcev2_p_0_o_vkey; // @synthesize jcev2_p_0_o_vkey;
- (void).cxx_destruct;
- (id)init;

@end
