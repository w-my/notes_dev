//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSString;

@interface TVKSDKManager : NSObject
{
    _Bool _isRegistered;
    NSString *_guid;
    NSString *_uid;
    long long _playerTypeSetting;
    id <TVKLogDelegate> _logDelegate;
    id <TVKLogReportDelegate> _logReportDelegate;
    NSString *_appkey;
}

+ (id)sharedInstance;
@property(nonatomic) _Bool isRegistered; // @synthesize isRegistered=_isRegistered;
@property(copy, nonatomic) NSString *appkey; // @synthesize appkey=_appkey;
@property(readonly, nonatomic) __weak id <TVKLogReportDelegate> logReportDelegate; // @synthesize logReportDelegate=_logReportDelegate;
@property(nonatomic) __weak id <TVKLogDelegate> logDelegate; // @synthesize logDelegate=_logDelegate;
@property(nonatomic) long long playerTypeSetting; // @synthesize playerTypeSetting=_playerTypeSetting;
@property(copy, nonatomic) NSString *uid; // @synthesize uid=_uid;
@property(copy, nonatomic) NSString *guid; // @synthesize guid=_guid;
- (void).cxx_destruct;
- (void)unLoadP2P;
- (void)resetP2P;
- (void)reportLastLaunchSavedData;
- (void)setLogReportDelegate:(id)arg1;
- (id)getPrivateKeyForCKey;
- (_Bool)registerWithAppKey:(id)arg1;
- (int)authStatus;
@property(readonly, nonatomic) NSString *version;
- (id)init;

@end
