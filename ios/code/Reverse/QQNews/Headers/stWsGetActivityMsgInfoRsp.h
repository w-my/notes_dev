//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "JceObjectV2.h"

@class NSDictionary, NSString, stMetaUgcImage;

@interface stWsGetActivityMsgInfoRsp : JceObjectV2
{
    BOOL jcev2_p_3_o_bOperButtonExist;
    int jcev2_p_0_o_type;
    NSString *jcev2_p_1_o_title;
    NSString *jcev2_p_2_o_wording;
    NSString *jcev2_p_4_o_buttonText;
    NSString *jcev2_p_5_o_buttonJumpUrl;
    NSString *jcev2_p_6_o_wordJumpUrl;
    stMetaUgcImage *jcev2_p_7_o_coverImage;
    stMetaUgcImage *jcev2_p_8_o_backImage;
    NSDictionary *jcev2_p_9_o_extInfo__b0x9i_M09ONSStringONSString;
}

+ (id)jceType;
+ (void)initialize;
@property(retain, nonatomic, getter=jce_extInfo, setter=setJce_extInfo:) NSDictionary *jcev2_p_9_o_extInfo__b0x9i_M09ONSStringONSString; // @synthesize jcev2_p_9_o_extInfo__b0x9i_M09ONSStringONSString;
@property(retain, nonatomic, getter=jce_backImage, setter=setJce_backImage:) stMetaUgcImage *jcev2_p_8_o_backImage; // @synthesize jcev2_p_8_o_backImage;
@property(retain, nonatomic, getter=jce_coverImage, setter=setJce_coverImage:) stMetaUgcImage *jcev2_p_7_o_coverImage; // @synthesize jcev2_p_7_o_coverImage;
@property(retain, nonatomic, getter=jce_wordJumpUrl, setter=setJce_wordJumpUrl:) NSString *jcev2_p_6_o_wordJumpUrl; // @synthesize jcev2_p_6_o_wordJumpUrl;
@property(retain, nonatomic, getter=jce_buttonJumpUrl, setter=setJce_buttonJumpUrl:) NSString *jcev2_p_5_o_buttonJumpUrl; // @synthesize jcev2_p_5_o_buttonJumpUrl;
@property(retain, nonatomic, getter=jce_buttonText, setter=setJce_buttonText:) NSString *jcev2_p_4_o_buttonText; // @synthesize jcev2_p_4_o_buttonText;
@property(nonatomic, getter=jce_bOperButtonExist, setter=setJce_bOperButtonExist:) BOOL jcev2_p_3_o_bOperButtonExist; // @synthesize jcev2_p_3_o_bOperButtonExist;
@property(retain, nonatomic, getter=jce_wording, setter=setJce_wording:) NSString *jcev2_p_2_o_wording; // @synthesize jcev2_p_2_o_wording;
@property(retain, nonatomic, getter=jce_title, setter=setJce_title:) NSString *jcev2_p_1_o_title; // @synthesize jcev2_p_1_o_title;
@property(nonatomic, getter=jce_type, setter=setJce_type:) int jcev2_p_0_o_type; // @synthesize jcev2_p_0_o_type;
- (void).cxx_destruct;
- (id)init;

@end

