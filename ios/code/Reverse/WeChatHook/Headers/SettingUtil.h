//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@interface SettingUtil : NSObject
{
}

+ (_Bool)isEUCountryISOCodes:(id)arg1;
+ (id)getRegCountryCode;
+ (_Bool)isRegInEUCountry;
+ (_Bool)isRegInChina;
+ (id)getEUCountryISOCodes;
+ (id)getDisplayUsrName;
+ (_Bool)cannotModAlias;
+ (_Bool)isOpenVoicePrint;
+ (_Bool)isCurUsrHasAliasName;
+ (_Bool)isHasWBlogAccount;
+ (_Bool)isMicroBlogOpen;
+ (_Bool)isOpenQQMail;
+ (_Bool)isOpenSX;
+ (_Bool)isOpenGMail;
+ (_Bool)isBindQQ;
+ (_Bool)isOpenQQ;
+ (void)loadCurUserInfo:(id)arg1;
+ (long long)getFontSize;
+ (id)getLocalUsrName:(unsigned int)arg1;
+ (id)getBottleLocalUsrName;
+ (id)getCurUsrDisplayName;
+ (id)getCurUsrNickname;
+ (id)getCurUsrName;
+ (_Bool)isCurUsrName:(id)arg1;
+ (id)getLocalInfo;
+ (id)getUpdateInfo;
+ (id)getMainSettingExt;
+ (id)getMainSetting;
+ (_Bool)isNeverAutoPlaySight;
+ (_Bool)isAutoPlaySight;
+ (_Bool)isSnsAutoDownloadAdCanvasSight;
+ (_Bool)isAutoDownloadAdSight:(id)arg1;
+ (_Bool)isAutoDownloadSightForExp:(id)arg1;
+ (_Bool)isAutoDownloadSight:(id)arg1;
+ (_Bool)isC2CSightInFlowControl:(id)arg1;
+ (_Bool)isSnsAdSightInFlowControl;
+ (_Bool)isC2CAdSightInFlowControl:(id)arg1;
+ (_Bool)isSnsSightInFlowControl;
+ (_Bool)isSnsSightInFlowControlByDatePeriod;
+ (_Bool)isSnsSightInFlowControlByDailyTime;
+ (_Bool)isOnlySetWxId;
+ (_Bool)isNakedWxAccount;
+ (_Bool)isOpenFloatBottle;
+ (id)GetLocalUsrImg;
+ (void)logNotificationSetting:(_Bool)arg1;
+ (id)delayTypeStringWith:(unsigned long long)arg1;
+ (id)delayTypeString;
+ (unsigned long long)transferDelayType;
+ (_Bool)isF2FSynthesizeSpeechOpen;

@end

