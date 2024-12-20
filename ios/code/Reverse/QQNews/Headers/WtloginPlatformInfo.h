//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class MemSig, NSData, NSMutableDictionary, NSString, RemortServerList, SafeSingleItemWrapper;

@interface WtloginPlatformInfo : NSObject
{
    NSString *macAddr;
    NSString *ipStr;
    unsigned int clientIp;
    NSString *devType;
    NSString *iosVer;
    NSString *devName;
    NSString *osName;
    NSString *appVer;
    char *if_names[32];
    char *ip_names[32];
    char *hw_addrs[32];
    unsigned long long ip_addrs[32];
    int nextAddr;
    NSString *filePath;
    NSMutableDictionary *wtloginConfigDic;
    NSData *guid;
    unsigned char cIsNew;
    unsigned char cIsDiff;
    unsigned char cIsGetGuid;
    unsigned char cGUIDSrc;
    unsigned char cReadFailFlag;
    unsigned char cDevChgFlag;
    SafeSingleItemWrapper *ksidWrapper;
    MemSig *deviceSig;
    unsigned int dwMyVer;
    unsigned int dwMyPubNo;
    unsigned int dwMyClientType;
    NSString *sigFilePath;
    NSMutableDictionary *sigDictionary;
    RemortServerList *stServerinfo;
    NSString *wtloginIosSdkVer;
    NSString *wtloginBuildTime;
    unsigned int wtloginBigVer;
    int dwDiffTime;
    unsigned int dwClientIP;
    NSString *loginFilePath;
    NSMutableDictionary *userLoginInfo;
    int lang;
    NSData *ecdhShareKey;
    NSData *ecdhCliPubKey;
    NSData *ecdhCliPrivKey;
    unsigned int dwEcdhUpdateEnable;
    unsigned char cSmsVerifyLoginFlag;
    NSString *SmsVerifyLoginPhone;
    NSString *SmsVerifyLoginCoutry;
    unsigned long long ddwSmsVerifyLoginUin;
    NSData *mVerifyLoginPassWordMd5;
    unsigned long long ddwSmsVerifyLoginMUin;
    unsigned long long ddwRandSalt;
    NSMutableDictionary *domainDict;
    unsigned int dwSecGUIDFlag;
    unsigned int dwSecGUIDTag;
    NSData *Salt;
    NSData *DevPwd;
    NSData *SecG;
    NSData *RandSeed;
    NSData *sMacInfo;
    NSData *sVendorID;
    unsigned char cCanWebVerify;
    NSString *extensionShareGroupsId;
    NSData *qrSig;
    unsigned char needWta1;
    NSData *scan_A1Key;
    NSMutableDictionary *dict0x104;
    NSMutableDictionary *dict0x104time;
    unsigned int dwCurAppId;
    NSString *SmsVerifyLoginCountry;
}

+ (id)appBundleIndentify;
+ (id)wtloginCrtCarrierName;
+ (int)wtloginNetState;
+ (id)dataSafeFilePathWithName:(id)arg1;
+ (_Bool)addSkipBackupAttributeToItemAtPath:(id)arg1;
@property unsigned int dwCurAppId; // @synthesize dwCurAppId;
@property(copy) NSString *extensionShareGroupsId; // @synthesize extensionShareGroupsId;
@property(copy) NSData *scan_A1Key; // @synthesize scan_A1Key;
@property unsigned char needWta1; // @synthesize needWta1;
@property(retain) NSData *qrSig; // @synthesize qrSig;
@property unsigned char cCanWebVerify; // @synthesize cCanWebVerify;
@property(copy) NSData *sVendorID; // @synthesize sVendorID;
@property(copy) NSData *sMacInfo; // @synthesize sMacInfo;
@property(copy) NSData *RandSeed; // @synthesize RandSeed;
@property(copy) NSData *SecG; // @synthesize SecG;
@property(copy) NSData *DevPwd; // @synthesize DevPwd;
@property(copy) NSData *Salt; // @synthesize Salt;
@property unsigned int dwSecGUIDTag; // @synthesize dwSecGUIDTag;
@property unsigned int dwSecGUIDFlag; // @synthesize dwSecGUIDFlag;
@property unsigned char cSmsVerifyLoginFlag; // @synthesize cSmsVerifyLoginFlag;
@property unsigned long long ddwRandSalt; // @synthesize ddwRandSalt;
@property unsigned long long ddwSmsVerifyLoginMUin; // @synthesize ddwSmsVerifyLoginMUin;
@property(copy) NSData *mVerifyLoginPassWordMd5; // @synthesize mVerifyLoginPassWordMd5;
@property unsigned long long ddwSmsVerifyLoginUin; // @synthesize ddwSmsVerifyLoginUin;
@property(copy) NSString *SmsVerifyLoginCountry; // @synthesize SmsVerifyLoginCountry;
@property(copy) NSString *SmsVerifyLoginPhone; // @synthesize SmsVerifyLoginPhone;
@property(readonly) NSMutableDictionary *domainDict; // @synthesize domainDict;
@property(readonly) NSData *ecdhCliPrivKey; // @synthesize ecdhCliPrivKey;
@property(readonly) NSData *ecdhCliPubKey; // @synthesize ecdhCliPubKey;
@property(readonly) NSData *ecdhShareKey; // @synthesize ecdhShareKey;
@property unsigned int dwEcdhUpdateEnable; // @synthesize dwEcdhUpdateEnable;
@property int lang; // @synthesize lang;
@property unsigned int dwClientIP; // @synthesize dwClientIP;
@property int dwDiffTime; // @synthesize dwDiffTime;
@property(readonly) NSString *wtloginBuildTime; // @synthesize wtloginBuildTime;
@property(readonly) unsigned int wtloginBigVer; // @synthesize wtloginBigVer;
@property(readonly) NSString *wtloginIosSdkVer; // @synthesize wtloginIosSdkVer;
@property(readonly) RemortServerList *stServerinfo; // @synthesize stServerinfo;
@property(readonly) NSMutableDictionary *sigDictionary; // @synthesize sigDictionary;
@property unsigned int dwMyClientType; // @synthesize dwMyClientType;
@property unsigned int dwMyPubNo; // @synthesize dwMyPubNo;
@property unsigned int dwMyVer; // @synthesize dwMyVer;
@property(retain) MemSig *deviceSig; // @synthesize deviceSig;
@property(readonly) unsigned char cDevChgFlag; // @synthesize cDevChgFlag;
@property(readonly) unsigned char cReadFailFlag; // @synthesize cReadFailFlag;
@property(readonly) unsigned char cGUIDSrc; // @synthesize cGUIDSrc;
@property(readonly) unsigned char cIsGetGuid; // @synthesize cIsGetGuid;
@property(readonly) unsigned char cIsDiff; // @synthesize cIsDiff;
@property(readonly) unsigned char cIsNew; // @synthesize cIsNew;
@property(retain) NSData *guid; // @synthesize guid;
@property(copy) NSString *appVer; // @synthesize appVer;
@property(readonly) NSString *osName; // @synthesize osName;
@property(readonly) unsigned int clientIp; // @synthesize clientIp;
@property(readonly) NSString *macAddr; // @synthesize macAddr;
@property(readonly) NSString *devType; // @synthesize devType;
@property(readonly) NSString *devName; // @synthesize devName;
@property(readonly) NSString *iosVer; // @synthesize iosVer;
@property(readonly) NSString *ipStr; // @synthesize ipStr;
- (void)writeExtensionShareSig;
- (id)PhoneNoConvert:(id)arg1;
- (void)del0x104:(id)arg1;
- (id)get0x104:(id)arg1;
- (void)add0x104:(id)arg1 forAccount:(id)arg2;
- (void)RemovePt4TokenDomainList;
- (void)RemovePskeyDomainList;
- (void)RemoveDomainList;
- (void)addDomain:(id)arg1 withFlag:(unsigned char)arg2;
- (_Bool)canUseEcdhUpdate;
- (void)disableEcdhUpdate;
- (void)enableEcdhUpdate;
- (void)setECDHPrivateKey:(char *)arg1 andPrivKeyLen:(int)arg2;
- (void)setECDHShareKey:(char *)arg1 andPubKey:(char *)arg2 andPubKeyLen:(int)arg3;
- (void)_checkDevice;
- (id)loginUserList;
- (id)lastLoginUserAccount;
- (void)setLastLoginUserAccount:(id)arg1;
- (id)guidForReport;
- (void)writeSigDataTofile;
- (_Bool)removeSig:(id)arg1 withUin:(unsigned int)arg2 andAppId:(unsigned int)arg3;
- (void)printUserInfoList;
- (void)printAllMemsig;
- (id)appDisplayName;
- (id)appMainBundleIndentify;
- (id)appBundleVersion;
- (id)appBundleShortVersionString;
- (unsigned int)lastQuickLoginSubAppId;
- (unsigned int)lastQuickLoginAppId;
- (_Bool)setLastQuickLoginAppInfo:(unsigned int)arg1 subappid:(unsigned int)arg2;
- (id)lastLoginAppVer;
- (id)lastLoginSdkVer;
- (unsigned int)lastLoginTime;
- (_Bool)resetLastLoginInfo;
- (unsigned int)sigVailidateBySigType:(unsigned int)arg1;
- (void)writeSigTimeToFile;
- (_Bool)setSigVailidateTime:(unsigned int)arg1 bySigType:(unsigned int)arg2;
- (void)clearNameToUin:(id)arg1;
- (unsigned int)getNoPwdFlagForUser:(id)arg1;
- (_Bool)setNoPwdFlagToConfig:(unsigned int)arg1 andAccount:(id)arg2;
- (_Bool)isPlatNameAccount:(id)arg1;
- (_Bool)setNameToConfig:(id)arg1 forUin:(unsigned int)arg2;
@property(readonly) NSMutableDictionary *nameDictionary;
- (void)clearPwdSigUser:(unsigned int)arg1;
- (id)generateSecGUID_SecG:(id)arg1 andRandSeed:(id)arg2;
- (id)generateSecGUID_DPwd;
- (id)generateSecGUID_DA1:(unsigned int)arg1 andAppId:(unsigned int)arg2 andSubAppId:(unsigned int)arg3;
- (_Bool)setSaveRandSeedToConfig:(id)arg1 forAccount:(unsigned int)arg2;
- (_Bool)setSaveSecGUIDInfoToConfig:(unsigned int)arg1;
- (void)resetSecGUIDParam;
- (id)noPicSigUser:(unsigned int)arg1;
- (id)getTGTGTSig:(unsigned int)arg1 andAppid:(unsigned int)arg2;
- (id)pwdSigUser:(unsigned int)arg1;
- (_Bool)setSavePwdSigToConfig:(id)arg1 andNoPicSig:(id)arg2 forAccount:(unsigned int)arg3;
- (void)resetKeyChain;
- (id)ksidForUser:(id)arg1;
- (_Bool)setKsidToConfig:(id)arg1 forAccount:(id)arg2;
- (_Bool)setKsidToKeyChain:(id)arg1;
- (id)ksidFromKeyChain;
- (id)tgtgtKeyFromKeyChain;
- (id)getWifiDic;
- (id)getWifiBSSIDInfo;
- (id)crtCarrierName;
- (int)netState;
- (void)setConfigObject:(id)arg1 forKey:(id)arg2 forUin:(unsigned long long)arg3;
- (id)configObjectForKey:(id)arg1;
- (void)dealloc;
- (void)wtloginPlatformDataInit;
- (void)InitDevInfo;
- (id)init;
- (_Bool)tryDecrypt:(id)arg1 byKey:(id)arg2 andOutData:(id)arg3;
- (id)getDeviceVersion;
- (_Bool)closeLowIOSDevLog:(id)arg1;
- (int)writeGuidToPasteBoard:(id)arg1;
- (int)readGuidArrayFromPasteBoard:(id)arg1;
- (void)genGuid;
- (_Bool)writeWtloginConfigFile:(id)arg1 forUin:(unsigned long long)arg2 atomically:(_Bool)arg3;
- (id)macaddress;
- (void)GetHWAddresses;
- (void)GetIPAddresses;
- (void)FreeAddresses;
- (void)InitAddresses;

@end

