//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "JceObjectV2.h"

@class NSString, stPersonUpdateInfo, stWealthInfo;

@interface stMetaPerson : JceObjectV2
{
    int jcev2_p_1_o_type;
    int jcev2_p_3_o_createtime;
    int jcev2_p_6_o_sex;
    int jcev2_p_13_o_rich_flag;
    int jcev2_p_14_o_age;
    int jcev2_p_20_o_chartScore;
    int jcev2_p_21_o_chartRank;
    int jcev2_p_22_o_feedGoldNum;
    unsigned int jcev2_p_23_o_avatar_updatetime;
    int jcev2_p_25_o_sync_content;
    int jcev2_p_27_o_settingmask;
    unsigned int jcev2_p_35_o_lastUpdateFeedNum;
    unsigned int jcev2_p_37_o_nick_updatetime;
    NSString *jcev2_p_0_o_id;
    NSString *jcev2_p_2_o_uid;
    NSString *jcev2_p_4_o_nick;
    NSString *jcev2_p_5_o_avatar;
    NSString *jcev2_p_7_o_feedlist_time_id;
    NSString *jcev2_p_8_o_feedlist_hot_id;
    NSString *jcev2_p_9_o_related_feedlist_id;
    NSString *jcev2_p_10_o_followerlist_id;
    NSString *jcev2_p_11_o_interesterlist_id;
    NSString *jcev2_p_12_o_chatlist_id;
    NSString *jcev2_p_15_o_address;
    stWealthInfo *jcev2_p_16_o_wealth;
    NSString *jcev2_p_17_o_background;
    NSString *jcev2_p_18_o_status;
    long long jcev2_p_19_o_followStatus;
    NSString *jcev2_p_24_o_desc_from_operator;
    NSString *jcev2_p_26_o_feedlist_praise_id;
    NSString *jcev2_p_28_o_originalavatar;
    NSString *jcev2_p_29_o_block_time;
    long long jcev2_p_30_o_grade;
    long long jcev2_p_31_o_medal;
    NSString *jcev2_p_32_o_block_reason;
    long long jcev2_p_33_o_qq;
    NSString *jcev2_p_34_o_recommendReason;
    stPersonUpdateInfo *jcev2_p_36_o_updateinfo;
    NSString *jcev2_p_38_o_lastDownloadAvatar;
    NSString *jcev2_p_39_o_realName;
    NSString *jcev2_p_40_o_pinyin_first;
    NSString *jcev2_p_41_o_certif_desc;
}

+ (id)jceType;
+ (void)initialize;
@property(retain, nonatomic, getter=jce_certif_desc, setter=setJce_certif_desc:) NSString *jcev2_p_41_o_certif_desc; // @synthesize jcev2_p_41_o_certif_desc;
@property(retain, nonatomic, getter=jce_pinyin_first, setter=setJce_pinyin_first:) NSString *jcev2_p_40_o_pinyin_first; // @synthesize jcev2_p_40_o_pinyin_first;
@property(retain, nonatomic, getter=jce_realName, setter=setJce_realName:) NSString *jcev2_p_39_o_realName; // @synthesize jcev2_p_39_o_realName;
@property(retain, nonatomic, getter=jce_lastDownloadAvatar, setter=setJce_lastDownloadAvatar:) NSString *jcev2_p_38_o_lastDownloadAvatar; // @synthesize jcev2_p_38_o_lastDownloadAvatar;
@property(nonatomic, getter=jce_nick_updatetime, setter=setJce_nick_updatetime:) unsigned int jcev2_p_37_o_nick_updatetime; // @synthesize jcev2_p_37_o_nick_updatetime;
@property(retain, nonatomic, getter=jce_updateinfo, setter=setJce_updateinfo:) stPersonUpdateInfo *jcev2_p_36_o_updateinfo; // @synthesize jcev2_p_36_o_updateinfo;
@property(nonatomic, getter=jce_lastUpdateFeedNum, setter=setJce_lastUpdateFeedNum:) unsigned int jcev2_p_35_o_lastUpdateFeedNum; // @synthesize jcev2_p_35_o_lastUpdateFeedNum;
@property(retain, nonatomic, getter=jce_recommendReason, setter=setJce_recommendReason:) NSString *jcev2_p_34_o_recommendReason; // @synthesize jcev2_p_34_o_recommendReason;
@property(nonatomic, getter=jce_qq, setter=setJce_qq:) long long jcev2_p_33_o_qq; // @synthesize jcev2_p_33_o_qq;
@property(retain, nonatomic, getter=jce_block_reason, setter=setJce_block_reason:) NSString *jcev2_p_32_o_block_reason; // @synthesize jcev2_p_32_o_block_reason;
@property(nonatomic, getter=jce_medal, setter=setJce_medal:) long long jcev2_p_31_o_medal; // @synthesize jcev2_p_31_o_medal;
@property(nonatomic, getter=jce_grade, setter=setJce_grade:) long long jcev2_p_30_o_grade; // @synthesize jcev2_p_30_o_grade;
@property(retain, nonatomic, getter=jce_block_time, setter=setJce_block_time:) NSString *jcev2_p_29_o_block_time; // @synthesize jcev2_p_29_o_block_time;
@property(retain, nonatomic, getter=jce_originalavatar, setter=setJce_originalavatar:) NSString *jcev2_p_28_o_originalavatar; // @synthesize jcev2_p_28_o_originalavatar;
@property(nonatomic, getter=jce_settingmask, setter=setJce_settingmask:) int jcev2_p_27_o_settingmask; // @synthesize jcev2_p_27_o_settingmask;
@property(retain, nonatomic, getter=jce_feedlist_praise_id, setter=setJce_feedlist_praise_id:) NSString *jcev2_p_26_o_feedlist_praise_id; // @synthesize jcev2_p_26_o_feedlist_praise_id;
@property(nonatomic, getter=jce_sync_content, setter=setJce_sync_content:) int jcev2_p_25_o_sync_content; // @synthesize jcev2_p_25_o_sync_content;
@property(retain, nonatomic, getter=jce_desc_from_operator, setter=setJce_desc_from_operator:) NSString *jcev2_p_24_o_desc_from_operator; // @synthesize jcev2_p_24_o_desc_from_operator;
@property(nonatomic, getter=jce_avatar_updatetime, setter=setJce_avatar_updatetime:) unsigned int jcev2_p_23_o_avatar_updatetime; // @synthesize jcev2_p_23_o_avatar_updatetime;
@property(nonatomic, getter=jce_feedGoldNum, setter=setJce_feedGoldNum:) int jcev2_p_22_o_feedGoldNum; // @synthesize jcev2_p_22_o_feedGoldNum;
@property(nonatomic, getter=jce_chartRank, setter=setJce_chartRank:) int jcev2_p_21_o_chartRank; // @synthesize jcev2_p_21_o_chartRank;
@property(nonatomic, getter=jce_chartScore, setter=setJce_chartScore:) int jcev2_p_20_o_chartScore; // @synthesize jcev2_p_20_o_chartScore;
@property(nonatomic, getter=jce_followStatus, setter=setJce_followStatus:) long long jcev2_p_19_o_followStatus; // @synthesize jcev2_p_19_o_followStatus;
@property(retain, nonatomic, getter=jce_status, setter=setJce_status:) NSString *jcev2_p_18_o_status; // @synthesize jcev2_p_18_o_status;
@property(retain, nonatomic, getter=jce_background, setter=setJce_background:) NSString *jcev2_p_17_o_background; // @synthesize jcev2_p_17_o_background;
@property(retain, nonatomic, getter=jce_wealth, setter=setJce_wealth:) stWealthInfo *jcev2_p_16_o_wealth; // @synthesize jcev2_p_16_o_wealth;
@property(retain, nonatomic, getter=jce_address, setter=setJce_address:) NSString *jcev2_p_15_o_address; // @synthesize jcev2_p_15_o_address;
@property(nonatomic, getter=jce_age, setter=setJce_age:) int jcev2_p_14_o_age; // @synthesize jcev2_p_14_o_age;
@property(nonatomic, getter=jce_rich_flag, setter=setJce_rich_flag:) int jcev2_p_13_o_rich_flag; // @synthesize jcev2_p_13_o_rich_flag;
@property(retain, nonatomic, getter=jce_chatlist_id, setter=setJce_chatlist_id:) NSString *jcev2_p_12_o_chatlist_id; // @synthesize jcev2_p_12_o_chatlist_id;
@property(retain, nonatomic, getter=jce_interesterlist_id, setter=setJce_interesterlist_id:) NSString *jcev2_p_11_o_interesterlist_id; // @synthesize jcev2_p_11_o_interesterlist_id;
@property(retain, nonatomic, getter=jce_followerlist_id, setter=setJce_followerlist_id:) NSString *jcev2_p_10_o_followerlist_id; // @synthesize jcev2_p_10_o_followerlist_id;
@property(retain, nonatomic, getter=jce_related_feedlist_id, setter=setJce_related_feedlist_id:) NSString *jcev2_p_9_o_related_feedlist_id; // @synthesize jcev2_p_9_o_related_feedlist_id;
@property(retain, nonatomic, getter=jce_feedlist_hot_id, setter=setJce_feedlist_hot_id:) NSString *jcev2_p_8_o_feedlist_hot_id; // @synthesize jcev2_p_8_o_feedlist_hot_id;
@property(retain, nonatomic, getter=jce_feedlist_time_id, setter=setJce_feedlist_time_id:) NSString *jcev2_p_7_o_feedlist_time_id; // @synthesize jcev2_p_7_o_feedlist_time_id;
@property(nonatomic, getter=jce_sex, setter=setJce_sex:) int jcev2_p_6_o_sex; // @synthesize jcev2_p_6_o_sex;
@property(retain, nonatomic, getter=jce_avatar, setter=setJce_avatar:) NSString *jcev2_p_5_o_avatar; // @synthesize jcev2_p_5_o_avatar;
@property(retain, nonatomic, getter=jce_nick, setter=setJce_nick:) NSString *jcev2_p_4_o_nick; // @synthesize jcev2_p_4_o_nick;
@property(nonatomic, getter=jce_createtime, setter=setJce_createtime:) int jcev2_p_3_o_createtime; // @synthesize jcev2_p_3_o_createtime;
@property(retain, nonatomic, getter=jce_uid, setter=setJce_uid:) NSString *jcev2_p_2_o_uid; // @synthesize jcev2_p_2_o_uid;
@property(nonatomic, getter=jce_type, setter=setJce_type:) int jcev2_p_1_o_type; // @synthesize jcev2_p_1_o_type;
@property(retain, nonatomic, getter=jce_id, setter=setJce_id:) NSString *jcev2_p_0_o_id; // @synthesize jcev2_p_0_o_id;
- (void).cxx_destruct;
- (id)init;

@end
