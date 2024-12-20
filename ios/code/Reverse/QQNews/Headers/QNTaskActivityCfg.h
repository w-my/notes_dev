//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNBaseModelObject.h"

#import "NSCoding.h"
#import "NSCopying.h"

@class NSString;

@interface QNTaskActivityCfg : QNBaseModelObject <NSCopying, NSCoding>
{
    NSString *_title;
    NSString *_noticeTitle;
    NSString *_ruleTitle;
    NSString *_ruleUrl;
    NSString *_taskTitle;
    NSString *_leftTitle;
    NSString *_rightTitle;
    NSString *_leftUrl;
    NSString *_rightUrl;
    NSString *_actFinishTitle;
    NSString *_honorDesc;
    NSString *_honorFinishDesc;
    unsigned long long _taskLineType;
    NSString *_taskUrl;
    NSString *_toastTitle;
    NSString *_toastUrl;
}

+ (id)build:(CDUnknownBlockType)arg1;
+ (_Bool)isImmutable;
@property(copy, nonatomic) NSString *toastUrl; // @synthesize toastUrl=_toastUrl;
@property(copy, nonatomic) NSString *toastTitle; // @synthesize toastTitle=_toastTitle;
@property(copy, nonatomic) NSString *taskUrl; // @synthesize taskUrl=_taskUrl;
@property(nonatomic) unsigned long long taskLineType; // @synthesize taskLineType=_taskLineType;
@property(copy, nonatomic) NSString *honorFinishDesc; // @synthesize honorFinishDesc=_honorFinishDesc;
@property(copy, nonatomic) NSString *honorDesc; // @synthesize honorDesc=_honorDesc;
@property(copy, nonatomic) NSString *actFinishTitle; // @synthesize actFinishTitle=_actFinishTitle;
@property(copy, nonatomic) NSString *rightUrl; // @synthesize rightUrl=_rightUrl;
@property(copy, nonatomic) NSString *leftUrl; // @synthesize leftUrl=_leftUrl;
@property(copy, nonatomic) NSString *rightTitle; // @synthesize rightTitle=_rightTitle;
@property(copy, nonatomic) NSString *leftTitle; // @synthesize leftTitle=_leftTitle;
@property(copy, nonatomic) NSString *taskTitle; // @synthesize taskTitle=_taskTitle;
@property(copy, nonatomic) NSString *ruleUrl; // @synthesize ruleUrl=_ruleUrl;
@property(copy, nonatomic) NSString *ruleTitle; // @synthesize ruleTitle=_ruleTitle;
@property(copy, nonatomic) NSString *noticeTitle; // @synthesize noticeTitle=_noticeTitle;
@property(copy, nonatomic) NSString *title; // @synthesize title=_title;
- (void).cxx_destruct;
- (id)copyInstance;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)init;

@end

