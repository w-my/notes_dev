//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMObject.h"

@class NSMutableArray, NSString;

@interface WAReportBaseItem : MMObject
{
    _Bool _isEntrance;
    unsigned int _appType;
    unsigned long long _scene;
    NSString *_sceneNote;
    NSString *_sessionId;
    NSString *_appid;
    long long _appVersion;
    unsigned long long _appstate;
    unsigned long long _usedstate;
    NSString *_pagePath;
    NSString *_query;
    NSString *_networkType;
    unsigned long long _preScene;
    NSString *_preSceneNote;
    NSString *_referPagePath;
    NSMutableArray *_paramArr;
}

@property(retain, nonatomic) NSMutableArray *paramArr; // @synthesize paramArr=_paramArr;
@property(nonatomic) unsigned int appType; // @synthesize appType=_appType;
@property(nonatomic) _Bool isEntrance; // @synthesize isEntrance=_isEntrance;
@property(copy, nonatomic) NSString *referPagePath; // @synthesize referPagePath=_referPagePath;
@property(copy, nonatomic) NSString *preSceneNote; // @synthesize preSceneNote=_preSceneNote;
@property(nonatomic) unsigned long long preScene; // @synthesize preScene=_preScene;
@property(copy, nonatomic) NSString *networkType; // @synthesize networkType=_networkType;
@property(copy, nonatomic) NSString *query; // @synthesize query=_query;
@property(copy, nonatomic) NSString *pagePath; // @synthesize pagePath=_pagePath;
@property(nonatomic) unsigned long long usedstate; // @synthesize usedstate=_usedstate;
@property(nonatomic) unsigned long long appstate; // @synthesize appstate=_appstate;
@property(nonatomic) long long appVersion; // @synthesize appVersion=_appVersion;
@property(copy, nonatomic) NSString *appid; // @synthesize appid=_appid;
@property(copy, nonatomic) NSString *sessionId; // @synthesize sessionId=_sessionId;
@property(copy, nonatomic) NSString *sceneNote; // @synthesize sceneNote=_sceneNote;
@property(nonatomic) unsigned long long scene; // @synthesize scene=_scene;
- (void).cxx_destruct;
- (id)getJoinedParamStr;
- (void)appendUInt64:(unsigned long long)arg1;
- (void)appendUInt32:(unsigned int)arg1;
- (void)appendString:(id)arg1;
- (void)startAppendParam;
- (id)reportString;
- (void)makeSafeString;
- (int)reportID;

@end

