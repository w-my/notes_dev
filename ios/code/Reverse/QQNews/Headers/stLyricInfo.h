//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "JceObjectV2.h"

@class NSString;

@interface stLyricInfo : JceObjectV2
{
    long long jcev2_p_0_o_uiSongId;
    NSString *jcev2_p_1_o_strSongMid;
    NSString *jcev2_p_2_o_strFormat;
    NSString *jcev2_p_3_o_strLyric;
}

+ (id)jceType;
+ (void)initialize;
@property(retain, nonatomic, getter=jce_strLyric, setter=setJce_strLyric:) NSString *jcev2_p_3_o_strLyric; // @synthesize jcev2_p_3_o_strLyric;
@property(retain, nonatomic, getter=jce_strFormat, setter=setJce_strFormat:) NSString *jcev2_p_2_o_strFormat; // @synthesize jcev2_p_2_o_strFormat;
@property(retain, nonatomic, getter=jce_strSongMid, setter=setJce_strSongMid:) NSString *jcev2_p_1_o_strSongMid; // @synthesize jcev2_p_1_o_strSongMid;
@property(nonatomic, getter=jce_uiSongId, setter=setJce_uiSongId:) long long jcev2_p_0_o_uiSongId; // @synthesize jcev2_p_0_o_uiSongId;
- (void).cxx_destruct;
- (id)init;

@end

