//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class GCDWebServer;

@interface QNWebViewLocalServer : NSObject
{
    GCDWebServer *_server;
}

+ (id)sharedInstance;
@property(retain, nonatomic) GCDWebServer *server; // @synthesize server=_server;
- (void).cxx_destruct;
- (id)modificationDateForImageUrl:(id)arg1;
- (void)p_willEnterForeground;
- (id)p_standardRequestSig:(id)arg1;
- (id)p_contentTypeWithPathBase:(id)arg1;
- (id)p_contentTypeWithPath:(id)arg1;
- (id)p_contentTypeWithImageContentType:(long long)arg1;
- (id)p_secretResourceRequest:(id)arg1;
- (id)p_customResourceRequest:(id)arg1;
- (id)p_localWebViewReuseRequest:(id)arg1;
- (id)p_localImageWithRequest:(id)arg1;
- (id)p_localFileWithRequest:(id)arg1;
- (_Bool)p_startWebServerWithPort:(long long)arg1;
- (void)p_startWebServer;
- (void)p_configWebServer;
- (id)redirectURLForNativeSecretResource:(id)arg1 name:(id)arg2 type:(id)arg3;
- (id)redirectURLForNativeCustomResource:(id)arg1;
- (id)redirectURLForCustomResource:(id)arg1;
- (id)originalWebURLForRedirectURL:(id)arg1;
- (id)redirectURLForWebURL:(id)arg1;
- (id)redirectURLForBundleImageName:(id)arg1;
- (id)redirectURLForLocalFileName:(id)arg1;
- (id)redirectURLForWebViewReuse;
- (id)serverURL;
- (void)dealloc;
- (id)init;

@end
