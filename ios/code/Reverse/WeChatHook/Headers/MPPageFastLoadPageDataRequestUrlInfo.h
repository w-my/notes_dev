//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSString;

@interface MPPageFastLoadPageDataRequestUrlInfo : NSObject
{
    unsigned int _templateType;
    unsigned int _scene;
    unsigned int _enterType;
    unsigned int _lastModifyTime;
    NSString *_url;
    NSString *_identity;
}

+ (id)generateRequestUrlInfoIfSupport:(_Bool)arg1 itemShowType:(unsigned int)arg2 url:(id)arg3 scene:(unsigned int)arg4 enterType:(unsigned int)arg5;
+ (id)generateRequestUrlInfoWithForwardUrl:(id)arg1 scene:(unsigned int)arg2 enterType:(unsigned int)arg3;
@property(nonatomic) unsigned int lastModifyTime; // @synthesize lastModifyTime=_lastModifyTime;
@property(nonatomic) unsigned int enterType; // @synthesize enterType=_enterType;
@property(nonatomic) unsigned int scene; // @synthesize scene=_scene;
@property(nonatomic) unsigned int templateType; // @synthesize templateType=_templateType;
@property(readonly, copy, nonatomic) NSString *identity; // @synthesize identity=_identity;
@property(copy, nonatomic) NSString *url; // @synthesize url=_url;
- (void).cxx_destruct;
- (id)description;

@end

