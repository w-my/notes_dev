//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class CQQUserInfo, NSDictionary, NSString, QNThreadSafeMutableDictionary, WloginUserInfo;

@interface CQQWLogin : NSObject
{
    CQQUserInfo *_weiboUserinfo;
    _Bool _isVip;
    _Bool _isGroupVip;
    _Bool _isInLoginProcess;
    NSString *_qqnick;
    NSString *_mediaID;
    NSString *_encodedUin;
    NSString *_qqHeadUrl;
    long long _sex;
    NSString *_starSign;
    NSString *_loginURL;
    NSDictionary *_externUserInfoCookies;
    CDUnknownBlockType _quickLoginCallback;
    CDUnknownBlockType _quickLoginWebViewCloseCallback;
    WloginUserInfo *_loginUserInfoForSync;
    QNThreadSafeMutableDictionary *_userInfoCookies;
}

+ (id)sharedInstance;
@property(nonatomic) _Bool isInLoginProcess; // @synthesize isInLoginProcess=_isInLoginProcess;
@property(retain, nonatomic) QNThreadSafeMutableDictionary *userInfoCookies; // @synthesize userInfoCookies=_userInfoCookies;
@property(retain, nonatomic) WloginUserInfo *loginUserInfoForSync; // @synthesize loginUserInfoForSync=_loginUserInfoForSync;
@property(copy, nonatomic) CDUnknownBlockType quickLoginWebViewCloseCallback; // @synthesize quickLoginWebViewCloseCallback=_quickLoginWebViewCloseCallback;
@property(copy, nonatomic) CDUnknownBlockType quickLoginCallback; // @synthesize quickLoginCallback=_quickLoginCallback;
@property(copy, nonatomic) NSDictionary *externUserInfoCookies; // @synthesize externUserInfoCookies=_externUserInfoCookies;
@property(copy) NSString *loginURL; // @synthesize loginURL=_loginURL;
@property(copy, nonatomic) NSString *starSign; // @synthesize starSign=_starSign;
@property(nonatomic) long long sex; // @synthesize sex=_sex;
@property(copy) NSString *qqHeadUrl; // @synthesize qqHeadUrl=_qqHeadUrl;
@property(copy) NSString *encodedUin; // @synthesize encodedUin=_encodedUin;
@property(copy) NSString *mediaID; // @synthesize mediaID=_mediaID;
@property(copy) NSString *qqnick; // @synthesize qqnick=_qqnick;
- (void).cxx_destruct;
- (void)p_appDidBecomeActive;
- (_Bool)isLogin;
- (void)loadQQCookiesInfoFromCookies;
- (id)p_hexadecimalStringFromData:(id)arg1;
- (void)savePtLoginInfoToLocal;
- (id)loadPtLoginInfoFromLocal;
- (_Bool)canRefreshTocken;
- (void)updateUserCookie:(id)arg1;
- (void)updateUserInfo:(id)arg1 backgroundMode:(_Bool)arg2;
- (void)removeQQCookie;
- (void)updateMediaInfo:(id)arg1;
- (void)replaceUserInfoWith:(id)arg1;
- (void)updateUserInfoCookies:(id)arg1;
@property(nonatomic) _Bool isGroupVip; // @synthesize isGroupVip=_isGroupVip;
@property(nonatomic) _Bool isVip; // @synthesize isVip=_isVip;
- (long long)loginSexType;
- (id)getIcon;
- (id)getNick;
- (id)getUserName;
- (id)getCookieHeader;
- (void)removePtLoginInfoFromLocalSrcFile:(const char *)arg1 lineNumber:(int)arg2;
- (void)stopLogin;
- (_Bool)resolveQuickLoginResult:(id)arg1;
- (void)showLogin:(id)arg1 type:(id)arg2 showsso:(long long)arg3 from:(id)arg4 complete:(CDUnknownBlockType)arg5;
- (id)p_getLongVersion:(id)arg1;
- (id)init;
- (void)dealloc;
- (id)getA2;
- (id)getSkey;
- (id)p_getUserNameFromCookieArray:(id)arg1;
- (void)p_getUserInfoExFromQQNewsServerWithCookie:(id)arg1;
- (void)loginSuccessSig_v2:(id)arg1 andSig:(id)arg2 andBaseInfo:(id)arg3 tag:(long long)arg4;
- (void)loginFailed_v2:(id)arg1 andRst:(int)arg2 withErrInfo:(id)arg3 tag:(long long)arg4;
- (void)closeWebView:(int)arg1;
- (void)webViewLoadFailed:(id)arg1;
- (void)getInfoFromWebView:(id)arg1;
- (void)qqQuickLoginWithCallback:(CDUnknownBlockType)arg1 webViewCallback:(CDUnknownBlockType)arg2;
- (_Bool)qucickLoginBackAppWithSchemeURL:(id)arg1;

@end
