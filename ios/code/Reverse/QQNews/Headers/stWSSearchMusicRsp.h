//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "JceObjectV2.h"

@class NSArray, NSString;

@interface stWSSearchMusicRsp : JceObjectV2
{
    int jcev2_p_1_o_iRet;
    int jcev2_p_2_o_iSubRet;
    int jcev2_p_4_o_iCurNum;
    int jcev2_p_5_o_iCurPage;
    int jcev2_p_6_o_iTotalNum;
    int jcev2_p_8_o_iIsFinished;
    NSString *jcev2_p_0_o_attach_info;
    NSString *jcev2_p_3_o_strMsg;
    NSString *jcev2_p_7_o_strKeyword;
    NSArray *jcev2_p_9_o_vecMusic__b0x9i_VOstMusicFullInfo;
    NSArray *jcev2_p_10_o_vecAbout__b0x9i_VONSString;
    NSArray *jcev2_p_11_o_vecTopRcmd__b0x9i_VOstMusicFullInfo;
    NSArray *jcev2_p_12_o_vecMatMusic__b0x9i_VOstMetaMaterial;
}

+ (id)jceType;
+ (void)initialize;
@property(retain, nonatomic, getter=jce_vecMatMusic, setter=setJce_vecMatMusic:) NSArray *jcev2_p_12_o_vecMatMusic__b0x9i_VOstMetaMaterial; // @synthesize jcev2_p_12_o_vecMatMusic__b0x9i_VOstMetaMaterial;
@property(retain, nonatomic, getter=jce_vecTopRcmd, setter=setJce_vecTopRcmd:) NSArray *jcev2_p_11_o_vecTopRcmd__b0x9i_VOstMusicFullInfo; // @synthesize jcev2_p_11_o_vecTopRcmd__b0x9i_VOstMusicFullInfo;
@property(retain, nonatomic, getter=jce_vecAbout, setter=setJce_vecAbout:) NSArray *jcev2_p_10_o_vecAbout__b0x9i_VONSString; // @synthesize jcev2_p_10_o_vecAbout__b0x9i_VONSString;
@property(retain, nonatomic, getter=jce_vecMusic, setter=setJce_vecMusic:) NSArray *jcev2_p_9_o_vecMusic__b0x9i_VOstMusicFullInfo; // @synthesize jcev2_p_9_o_vecMusic__b0x9i_VOstMusicFullInfo;
@property(nonatomic, getter=jce_iIsFinished, setter=setJce_iIsFinished:) int jcev2_p_8_o_iIsFinished; // @synthesize jcev2_p_8_o_iIsFinished;
@property(retain, nonatomic, getter=jce_strKeyword, setter=setJce_strKeyword:) NSString *jcev2_p_7_o_strKeyword; // @synthesize jcev2_p_7_o_strKeyword;
@property(nonatomic, getter=jce_iTotalNum, setter=setJce_iTotalNum:) int jcev2_p_6_o_iTotalNum; // @synthesize jcev2_p_6_o_iTotalNum;
@property(nonatomic, getter=jce_iCurPage, setter=setJce_iCurPage:) int jcev2_p_5_o_iCurPage; // @synthesize jcev2_p_5_o_iCurPage;
@property(nonatomic, getter=jce_iCurNum, setter=setJce_iCurNum:) int jcev2_p_4_o_iCurNum; // @synthesize jcev2_p_4_o_iCurNum;
@property(retain, nonatomic, getter=jce_strMsg, setter=setJce_strMsg:) NSString *jcev2_p_3_o_strMsg; // @synthesize jcev2_p_3_o_strMsg;
@property(nonatomic, getter=jce_iSubRet, setter=setJce_iSubRet:) int jcev2_p_2_o_iSubRet; // @synthesize jcev2_p_2_o_iSubRet;
@property(nonatomic, getter=jce_iRet, setter=setJce_iRet:) int jcev2_p_1_o_iRet; // @synthesize jcev2_p_1_o_iRet;
@property(retain, nonatomic, getter=jce_attach_info, setter=setJce_attach_info:) NSString *jcev2_p_0_o_attach_info; // @synthesize jcev2_p_0_o_attach_info;
- (void).cxx_destruct;
- (id)init;

@end

