//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNBaseModelObject.h"

#import "NSCoding.h"
#import "NSCopying.h"

@class NSArray, NSString, QNTaskActivityCfg;

@interface QNTaskActivityModel : QNBaseModelObject <NSCopying, NSCoding>
{
    _Bool _isNew;
    _Bool _isCompleteToday;
    _Bool _openNotification;
    unsigned long long _isGray;
    unsigned long long _taskType;
    NSString *_taskDesc;
    NSString *_nextTaskDesc;
    unsigned long long _days;
    NSArray *_prizeList;
    NSArray *_taskList;
    QNTaskActivityCfg *_config;
}

+ (id)build:(CDUnknownBlockType)arg1;
+ (_Bool)isImmutable;
@property(nonatomic) _Bool openNotification; // @synthesize openNotification=_openNotification;
@property(nonatomic) _Bool isCompleteToday; // @synthesize isCompleteToday=_isCompleteToday;
@property(retain, nonatomic) QNTaskActivityCfg *config; // @synthesize config=_config;
@property(copy, nonatomic) NSArray *taskList; // @synthesize taskList=_taskList;
@property(copy, nonatomic) NSArray *prizeList; // @synthesize prizeList=_prizeList;
@property(nonatomic) unsigned long long days; // @synthesize days=_days;
@property(copy, nonatomic) NSString *nextTaskDesc; // @synthesize nextTaskDesc=_nextTaskDesc;
@property(copy, nonatomic) NSString *taskDesc; // @synthesize taskDesc=_taskDesc;
@property(nonatomic) unsigned long long taskType; // @synthesize taskType=_taskType;
@property(nonatomic) unsigned long long isGray; // @synthesize isGray=_isGray;
@property(nonatomic) _Bool isNew; // @synthesize isNew=_isNew;
- (void).cxx_destruct;
- (id)copyInstance;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)init;
- (_Bool)p_isValid;
- (_Bool)isValidAndFinishTask;
- (_Bool)isValidAndUnFinishTask;
- (unsigned long long)currentStatus;

@end
