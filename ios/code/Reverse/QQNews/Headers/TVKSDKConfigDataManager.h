//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSDictionary, NSMutableDictionary, NSString, TVKATSHTTPRequest;

@interface TVKSDKConfigDataManager : NSObject
{
    NSDictionary *_propConfigDict;
    NSMutableDictionary *_configCacheDict;
    NSDictionary *_langDict;
    NSDictionary *_urlsDict;
    NSString *_requestingURL;
    double _lastRequestCongfigTime;
    NSString *_sdkConfigDefaultKey;
    TVKATSHTTPRequest *_httpRequest;
}

+ (id)instance;
@property(retain, nonatomic) TVKATSHTTPRequest *httpRequest; // @synthesize httpRequest=_httpRequest;
@property(retain, nonatomic) NSString *sdkConfigDefaultKey; // @synthesize sdkConfigDefaultKey=_sdkConfigDefaultKey;
@property(nonatomic) double lastRequestCongfigTime; // @synthesize lastRequestCongfigTime=_lastRequestCongfigTime;
@property(copy, nonatomic) NSString *requestingURL; // @synthesize requestingURL=_requestingURL;
@property(retain) NSDictionary *urlsDict; // @synthesize urlsDict=_urlsDict;
@property(retain) NSDictionary *langDict; // @synthesize langDict=_langDict;
@property(retain) NSMutableDictionary *configCacheDict; // @synthesize configCacheDict=_configCacheDict;
@property(retain) NSDictionary *propConfigDict; // @synthesize propConfigDict=_propConfigDict;
- (void).cxx_destruct;
- (void)applicationEnterForegroud;
- (id)getUrlConfString:(id)arg1;
- (id)getLangString:(id)arg1;
- (id)getConfigPropertyArray:(id)arg1;
- (id)getConfigPropertyObject:(id)arg1;
- (id)getConfigPropertyString:(id)arg1;
- (_Bool)getConfigPropertyBool:(id)arg1;
- (double)getConfigPropertyDouble:(id)arg1;
- (float)getConfigPropertyFloat:(id)arg1;
- (int)getConfigPropertyInt:(id)arg1;
- (_Bool)checkObject:(id)arg1 type:(Class)arg2;
- (void)getOnlineConfigRequest;
- (id)sdkConfigURL;
- (void)updateOnlineConfig;
- (void)setConfigWithDict:(id)arg1 saveConfig:(_Bool)arg2;
- (void)syncLangAndUrlList;
- (void)setUpDefaultConfig;
- (id)init;

@end
