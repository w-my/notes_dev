//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@interface AuthManager : NSObject
{
}

+ (id)getLicenceStr;
+ (_Bool)checkIsLicStrExist;
+ (void)clearLicenceStr;
+ (int)setLicenceStr:(id)arg1;
+ (int)getVersion;
+ (int)currentAuthStatus;
+ (void)clearAuthInfo;
+ (long long)getEndTime;
+ (void)setIsShowFailedReason:(_Bool)arg1;
+ (id)getErrorReason:(int)arg1;
+ (int)setLicencePath:(id)arg1;

@end

