//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "JceObjectV2.h"

@class NSString;

@interface stWSGetCollectMusicListReq : JceObjectV2
{
    int jcev2_p_1_o_iPage;
    int jcev2_p_2_o_iNum;
    int jcev2_p_3_o_iNeedAll;
    NSString *jcev2_p_0_o_attach_info;
}

+ (id)jceType;
+ (void)initialize;
@property(nonatomic, getter=jce_iNeedAll, setter=setJce_iNeedAll:) int jcev2_p_3_o_iNeedAll; // @synthesize jcev2_p_3_o_iNeedAll;
@property(nonatomic, getter=jce_iNum, setter=setJce_iNum:) int jcev2_p_2_o_iNum; // @synthesize jcev2_p_2_o_iNum;
@property(nonatomic, getter=jce_iPage, setter=setJce_iPage:) int jcev2_p_1_o_iPage; // @synthesize jcev2_p_1_o_iPage;
@property(retain, nonatomic, getter=jce_attach_info, setter=setJce_attach_info:) NSString *jcev2_p_0_o_attach_info; // @synthesize jcev2_p_0_o_attach_info;
- (void).cxx_destruct;
- (id)init;

@end
