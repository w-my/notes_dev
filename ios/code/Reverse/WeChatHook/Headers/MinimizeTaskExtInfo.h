//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "MMObject.h"

#import "PBCoding.h"

@class NSString;

@interface MinimizeTaskExtInfo : MMObject <PBCoding>
{
    int generateType;
    unsigned int generateScene;
    int bizScene;
    NSString *bizId;
    NSString *bizSubId;
    NSString *bizName;
    unsigned long long taskCreateTime;
    NSString *miniSessionId;
    unsigned long long _lastMinimizeTime;
    unsigned long long _lastMaximizeTime;
    NSString *_aggreSessionId;
}

+ (void)initialize;
@property(retain, nonatomic) NSString *aggreSessionId; // @synthesize aggreSessionId=_aggreSessionId;
@property(nonatomic) unsigned long long lastMaximizeTime; // @synthesize lastMaximizeTime=_lastMaximizeTime;
@property(nonatomic) unsigned long long lastMinimizeTime; // @synthesize lastMinimizeTime=_lastMinimizeTime;
@property(retain, nonatomic) NSString *miniSessionId; // @synthesize miniSessionId;
@property(nonatomic) unsigned long long taskCreateTime; // @synthesize taskCreateTime;
@property(retain, nonatomic) NSString *bizName; // @synthesize bizName;
@property(retain, nonatomic) NSString *bizSubId; // @synthesize bizSubId;
@property(retain, nonatomic) NSString *bizId; // @synthesize bizId;
@property(nonatomic) int bizScene; // @synthesize bizScene;
@property(nonatomic) unsigned int generateScene; // @synthesize generateScene;
@property(nonatomic) int generateType; // @synthesize generateType;
- (void).cxx_destruct;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (const map_f8690629 *)getValueTagIndexMap;
- (id)getValueTypeTable;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

