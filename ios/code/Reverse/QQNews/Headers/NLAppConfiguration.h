//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSString;

@interface NLAppConfiguration : NSObject
{
    _Bool _bMidasRelease;
    _Bool _bSupportTourist;
    _Bool _bWebDebugMode;
    NSString *_appGroup;
    NSString *_appName;
    NSString *_appId;
    NSString *_appVersion;
    NSString *_externalUA;
    NSString *_clientType;
    NSString *_shareType;
    NSString *_midasAppId;
}

+ (long long)navBarItemStyle;
+ (_Bool)useLeftArrowBackBtn;
+ (void)setBWebDebugMode:(_Bool)arg1;
+ (_Bool)bWebDebugMode;
+ (void)setBSupportTourist:(_Bool)arg1;
+ (_Bool)bSupportTourist;
+ (void)setBMidasRelease:(_Bool)arg1;
+ (_Bool)bMidasRelease;
+ (void)setMidasAppId:(id)arg1;
+ (id)midasAppId;
+ (void)setShareType:(int)arg1;
+ (id)shareType;
+ (void)setClientType:(id)arg1;
+ (id)clientType;
+ (void)setAppVersion:(id)arg1;
+ (id)appVersion;
+ (void)setAppId:(id)arg1;
+ (id)appId;
+ (void)setAppName:(id)arg1;
+ (id)appName;
+ (id)sharedConfiguration;
@property(nonatomic) _Bool bWebDebugMode; // @synthesize bWebDebugMode=_bWebDebugMode;
@property(nonatomic) _Bool bSupportTourist; // @synthesize bSupportTourist=_bSupportTourist;
@property(nonatomic) _Bool bMidasRelease; // @synthesize bMidasRelease=_bMidasRelease;
@property(retain, nonatomic) NSString *midasAppId; // @synthesize midasAppId=_midasAppId;
@property(retain, nonatomic) NSString *shareType; // @synthesize shareType=_shareType;
@property(retain, nonatomic) NSString *clientType; // @synthesize clientType=_clientType;
@property(retain, nonatomic) NSString *externalUA; // @synthesize externalUA=_externalUA;
@property(retain, nonatomic) NSString *appVersion; // @synthesize appVersion=_appVersion;
@property(retain, nonatomic) NSString *appId; // @synthesize appId=_appId;
@property(retain, nonatomic) NSString *appName; // @synthesize appName=_appName;
@property(retain, nonatomic) NSString *appGroup; // @synthesize appGroup=_appGroup;
- (void).cxx_destruct;
- (id)init;

@end
