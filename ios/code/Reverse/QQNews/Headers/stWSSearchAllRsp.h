//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "JceObjectV2.h"

@class NSString, stFeedSearchResult, stTopicSearchResult, stUserSearchResult;

@interface stWSSearchAllRsp : JceObjectV2
{
    int jcev2_p_1_o_iRet;
    int jcev2_p_6_o_iSearchType;
    int jcev2_p_7_o_iDataType;
    NSString *jcev2_p_0_o_attach_info;
    NSString *jcev2_p_2_o_strMsg;
    stUserSearchResult *jcev2_p_3_o_userSearchResult;
    stTopicSearchResult *jcev2_p_4_o_topicSearchResult;
    stFeedSearchResult *jcev2_p_5_o_feedSearchResult;
}

+ (id)jceType;
+ (void)initialize;
@property(nonatomic, getter=jce_iDataType, setter=setJce_iDataType:) int jcev2_p_7_o_iDataType; // @synthesize jcev2_p_7_o_iDataType;
@property(nonatomic, getter=jce_iSearchType, setter=setJce_iSearchType:) int jcev2_p_6_o_iSearchType; // @synthesize jcev2_p_6_o_iSearchType;
@property(retain, nonatomic, getter=jce_feedSearchResult, setter=setJce_feedSearchResult:) stFeedSearchResult *jcev2_p_5_o_feedSearchResult; // @synthesize jcev2_p_5_o_feedSearchResult;
@property(retain, nonatomic, getter=jce_topicSearchResult, setter=setJce_topicSearchResult:) stTopicSearchResult *jcev2_p_4_o_topicSearchResult; // @synthesize jcev2_p_4_o_topicSearchResult;
@property(retain, nonatomic, getter=jce_userSearchResult, setter=setJce_userSearchResult:) stUserSearchResult *jcev2_p_3_o_userSearchResult; // @synthesize jcev2_p_3_o_userSearchResult;
@property(retain, nonatomic, getter=jce_strMsg, setter=setJce_strMsg:) NSString *jcev2_p_2_o_strMsg; // @synthesize jcev2_p_2_o_strMsg;
@property(nonatomic, getter=jce_iRet, setter=setJce_iRet:) int jcev2_p_1_o_iRet; // @synthesize jcev2_p_1_o_iRet;
@property(retain, nonatomic, getter=jce_attach_info, setter=setJce_attach_info:) NSString *jcev2_p_0_o_attach_info; // @synthesize jcev2_p_0_o_attach_info;
- (void).cxx_destruct;
- (id)init;

@end

