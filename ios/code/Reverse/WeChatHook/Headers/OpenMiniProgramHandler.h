//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMObject.h"

#import "IPreEnterWechatLogicExt.h"

@class NSDictionary, NSString, NSURL;

@interface OpenMiniProgramHandler : MMObject <IPreEnterWechatLogicExt>
{
    NSString *_appId;
    NSString *_bundleId;
    NSURL *_url;
    NSDictionary *_extDic;
}

@property(retain, nonatomic) NSDictionary *extDic; // @synthesize extDic=_extDic;
@property(retain, nonatomic) NSURL *url; // @synthesize url=_url;
@property(retain, nonatomic) NSString *bundleId; // @synthesize bundleId=_bundleId;
@property(retain, nonatomic) NSString *appId; // @synthesize appId=_appId;
- (void).cxx_destruct;
- (void)onPreEnterWechatDone;
- (id)encodeUrl:(id)arg1;
- (id)translateToInternalWebviewUrlString;
- (void)doOpenMiniProgram;
- (void)startHandle:(id)arg1 bundleId:(id)arg2 info:(id)arg3 extDic:(id)arg4;
- (void)dealloc;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
