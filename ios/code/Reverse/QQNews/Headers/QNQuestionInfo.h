//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "QNBaseModelObject.h"

#import "NSCoding.h"
#import "NSCopying.h"

@class NSString;

@interface QNQuestionInfo : QNBaseModelObject <NSCopying, NSCoding>
{
    _Bool _isFollowed;
    long long _followNum;
    long long _answerNum;
    long long _coralScoreZd;
    NSString *_reasonUrl;
}

+ (id)build:(CDUnknownBlockType)arg1;
+ (_Bool)isImmutable;
@property(copy, nonatomic) NSString *reasonUrl; // @synthesize reasonUrl=_reasonUrl;
@property(nonatomic) long long coralScoreZd; // @synthesize coralScoreZd=_coralScoreZd;
@property(nonatomic) long long answerNum; // @synthesize answerNum=_answerNum;
@property(nonatomic) _Bool isFollowed; // @synthesize isFollowed=_isFollowed;
@property(nonatomic) long long followNum; // @synthesize followNum=_followNum;
- (void).cxx_destruct;
- (id)copyInstance;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)init;

@end
